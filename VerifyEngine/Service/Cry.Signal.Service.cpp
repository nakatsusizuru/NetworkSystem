#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <DataBase/Cry.Signal.DataBase.h>
#include <DataBase/Cry.Signal.DataBasePool.h>
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

	Work::Work(NetworkServiceEngine * Services, const evpp::TCPConnPtr & Conn, const std::shared_ptr<DataBase> & DB) : m_Services(Services), m_CurrConn(Conn), m_DataBase(DB), m_Customer()
	{
		DebugMsg("数据地址：%p\n", DB);
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
					if (!m_Services || pData->length() < HeadSize)
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
				//			DLOG_TRACE << "发送数据失败";
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
	void Work::Close()
	{
		if (m_CurrConn->IsConnected())
		{
			m_CurrConn->Close();
		}
	}
	void Work::SetCustomer(const std::shared_ptr<CustomerData> & Customer)
	{
		m_Customer = Customer;
	}
	bool Work::CheckOnline(const CustomerData & Other) const
	{
		if (m_Services != nullptr)
		{
			return m_Services->CheckOnline(Other);
		}
		return true;
	}
	Work::~Work()
	{
		this->Close();
	}
	NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u64 & uSize) : m_Loop(std::make_unique<evpp::EventLoopThread>()), m_Services(std::make_unique<evpp::TCPServer>(m_Loop->loop(), lpszAddress, lpszFlags, uSize)), m_MySQL(std::make_shared<Import::MySQL>())
	{
		m_Services->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
		m_Services->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
		m_DataPool = std::make_shared<DataPool>("192.168.1.111", "root", "ccnihao123", "Verify", uSize);
	}
	bool NetworkServiceEngine::CreateService()
	{
		if (m_Services != nullptr)
		{
			if (!m_Services->Init())
			{
				return false;
			}
			if (!m_Services->Start())
			{
				return false;
			}
			return m_Loop->Start();
		}
		return false;
	}
	bool NetworkServiceEngine::CancelService()
	{
		if (m_Services != nullptr)
		{
			m_Services->Stop();
			m_Loop->Stop(true);
			return true;
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
			if (!this->AddWork(Conn->id(), std::make_unique<Work>(this, Conn, m_DataPool->GetNextMySQL(Conn->id()))))
			{
				Conn->Close();
			}
		}
		if (Conn->IsDisconnecting() || Conn->IsDisconnected())
		{
			if (!this->DelWork(Conn->id()))
			{
				Conn->Close();
			}
		}
	}
	bool NetworkServiceEngine::AddWork(u64 Index, const std::shared_ptr<Work> & Work)
	{
		std::lock_guard<std::mutex> Guard(m_WorkLock);
		{
			if (m_WorkData.find(Index) == m_WorkData.cend())
			{
				m_WorkData.insert({ Index, std::move(Work) });
				return true;
			}
		}
		return false;
	}
	bool NetworkServiceEngine::DelWork(u64 Index)
	{
		std::lock_guard<std::mutex> Guard(m_WorkLock);
		{
			if (auto iter = m_WorkData.find(Index); iter != m_WorkData.cend())
			{
				m_WorkData.erase(iter);
				return true;
			}
		}
		return false;
	}
	std::shared_ptr<Work> NetworkServiceEngine::GetWork(u64 Index)
	{
		std::lock_guard<std::mutex> Guard(m_WorkLock);
		{
			if (auto iter = m_WorkData.find(Index); iter != m_WorkData.cend())
			{
				return iter->second;
			}
		}
		return nullptr;
	}

	bool NetworkServiceEngine::CheckOnline(const CustomerData & Other)
	{
		std::lock_guard<std::mutex> Guard(m_WorkLock);
		{
			for (const auto & [Index, Work] : m_WorkData)
			{
				if (Work != nullptr)
				{
					if (const std::shared_ptr<CustomerData> & Customer = Work->GetCustomerData(); Customer != nullptr)
					{
						if (Other == std::move(*Customer))
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
}
