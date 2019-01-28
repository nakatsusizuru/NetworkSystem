#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <evpp/tcp_conn.h>
namespace Cry
{
	OnMessageLeave::OnMessageLeave(evpp::Buffer * pData) : m_pData(pData)
	{

	}
	OnMessageLeave::~OnMessageLeave()
	{
		m_pData->Reset();
	}

	Work::Work(NetworkServiceEngine * Service) : m_Service(Service)
	{

	}
	void Work::Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * pData)
	{
		OnMessageLeave Leave(pData);
		{
			u32 uMsg = 0, uSize = 0;
			while (pData->length() > 0)
			{
				if (!uMsg)
				{
					if (!m_Service || pData->length() < HeadSize)
					{
						DLOG_TRACE << "Recv DataSize < HeardSize Error:" << Conn->remote_addr();
						return;
					}
					uSize = pData->ReadInt32();
					uSize -= HeadSize;
					uMsg = pData->ReadInt32();
				}
				if (pData->size() < uSize)
				{
					DLOG_TRACE << "Recv DataSize < MessageSize:" << Conn->remote_addr();
					return;
				}
				//if (std::shared_ptr<Action::UnknownInterfaceEx> lpListener = m_Service->GetObjectInterface()->Get(uMsg); lpListener)
				//{
				//	try
				//	{
				//		if (!lpListener->OnSocketData(shared_from_this(), uMsg, pData->data(), uSize))
				//		{
				//			DLOG_TRACE << "·¢ËÍÊý¾ÝÊ§°Ü";
				//			return;
				//		}
				//	}
				//	catch (std::exception & e)
				//	{
				//		return;
				//	}
				//}
				//else
				//{
				//	DLOG_TRACE << "Exec lpListener = nullptr:" << m_Conn->remote_addr();
				//	return;
				//}
				pData->Skip(uSize);
				uMsg = 0;
			}
		}
	}
	NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u32 & uSize) : m_Loop(std::make_unique<evpp::EventLoopThread>()), m_Server(std::make_unique<evpp::TCPServer>(m_Loop->loop(), lpszAddress, lpszFlags, uSize))
	{
		m_Server->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
		m_Server->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
	}
	bool NetworkServiceEngine::CreateService()
	{
		if (m_Server != nullptr)
		{
			if (!m_Server->Init())
			{
				return false;
			}
			if (!m_Server->Start())
			{
				return false;
			}
			return m_Loop->Start();
		}
		return false;
	}
	bool NetworkServiceEngine::CancelService()
	{
		if (m_Server != nullptr)
		{
			m_Server->Stop();
			m_Loop->Stop(true);
			return m_Loop->IsStopped();
		}
		return false;
	}
	void NetworkServiceEngine::OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer)
	{
		if (std::shared_ptr<Work> Work = this->GetWork(Conn->id()); Work != nullptr)
			Work->Receive(Conn, Buffer);
		else
			Conn->Close();
	}
	void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
	{
		if (Conn->IsConnected())
		{
			if (!this->AddWork(Conn->id(), std::make_shared<Work>(this)))
			{
				Conn->Close();
			}
		}
		if (Conn->IsDisconnected())
		{
			if (!this->DelWork(Conn->id()))
			{
				Conn->Close();
			}
		}
	}
	bool NetworkServiceEngine::AddWork(u64 Index, std::shared_ptr<Work> Work)
	{
		std::lock_guard<std::mutex> Guard(m_Mutex);
		{
			if (m_Work.find(Index) == m_Work.cend())
			{
				m_Work.emplace(Index, Work);
				return true;
			}
		}
		return false;
	}
	bool NetworkServiceEngine::DelWork(u64 Index)
	{
		std::lock_guard<std::mutex> Guard(m_Mutex);
		{
			if (auto iter = m_Work.find(Index); iter != m_Work.cend())
			{
				m_Work.erase(iter);
				return true;
			}
		}
		return false;
	}
	std::shared_ptr<Work> NetworkServiceEngine::GetWork(u64 Index)
	{
		std::lock_guard<std::mutex> Guard(m_Mutex);
		{
			if (auto iter = m_Work.find(Index); iter != m_Work.cend())
			{
				return iter->second;
			}
		}
		return nullptr;
	}
}
