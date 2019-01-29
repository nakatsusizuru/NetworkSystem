#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <Service/Cry.AvailablePort.h>
#include <evpp/tcp_conn.h>
namespace Cry
{
	Work::Work(NetworkServiceEngine * Service)
	{

	}
	void Work::Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * pData)
	{

	}

	NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags) : m_Loop(std::make_unique<evpp::EventLoopThread>()), m_Pool(std::make_unique<evpp::EventLoopThreadPool>(m_Loop->loop(), 100))
	{
		m_Pool->Start(true);
		m_Loop->Start(true);
	}
	NetworkServiceEngine::~NetworkServiceEngine()
	{
		m_Pool->Stop(true);
		m_Loop->Stop(true);
	}
	bool NetworkServiceEngine::CreateService()
	{

		std::unique_ptr<evpp::TCPClient> Client = std::make_unique<evpp::TCPClient>(m_Pool->GetNextLoop(), "127.0.0.1:9999", std::to_string(m_ClientData.size()) + "#Client");
		
		Client->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
		Client->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
		Client->Bind(std::make_unique<AvailablePort>()->GetAvailableAddress("127.0.0.1"));
		Client->Connect();
		DebugMsg("%s\n", Client->local_addr().c_str());
		m_ClientData.push_back(std::move(Client));
		return true;
	}
	bool NetworkServiceEngine::CancelService()
	{
		return true;
	}
	void NetworkServiceEngine::OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer)
	{

	}
	void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
	{
		DebugMsg("%s\n", Conn->local_addr().c_str());
	}
}