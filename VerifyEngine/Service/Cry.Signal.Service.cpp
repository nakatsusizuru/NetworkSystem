#include <Global>
#include <Service/Cry.Signal.Service.h>
namespace Cry
{
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

	}
	void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
	{

	}
}
