#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <evpp/tcp_conn.h>
namespace Cry
{
	Work::Work(const NetworkServiceEngine * Service, const evpp::TCPConnPtr & Conn)
	{

	}
	void Work::Receive(const evpp::Buffer * pData)
	{

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
	void NetworkServiceEngine::OnMessage(const evpp::TCPConnPtr & Conn, const evpp::Buffer * Buffer)
	{
		if (std::shared_ptr<Work> Work = this->GetWork(Conn->id()); Work != nullptr)
			Work->Receive(Buffer);
		else
			Conn->Close();
	}
	void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
	{
		if (Conn->IsConnected())
		{
			if (!this->AddWork(Conn->id(), std::make_shared<Work>(this, Conn)))
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
