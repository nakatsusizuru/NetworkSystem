#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <Service/Cry.Signal.Port.h>
#include <evpp/tcp_conn.h>
namespace Cry
{
	namespace Signal
	{
		OnMessageLeave::OnMessageLeave(evpp::Buffer * pData) : m_pData(pData)
		{

		}
		OnMessageLeave::~OnMessageLeave()
		{
			m_pData->Reset();
		}


		NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags) : m_lpszAddress(lpszAddress), m_lpszFlags(lpszFlags), m_Loop(std::make_unique<EventLoopThread>()), m_Pool(std::make_unique<EventLoopThreadPool>(m_Loop->loop(), 10)), m_Client(std::make_unique<TcpClient>(m_Pool->GetNextLoop(), lpszAddress, lpszFlags)), m_AvailablePort(std::make_unique<AvailablePort>())
		{
			m_Client->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
			m_Client->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
			m_Loop->Start(true);
			m_Pool->Start(true);
		}
		NetworkServiceEngine::~NetworkServiceEngine()
		{
			this->CancelAllService();
			m_Pool->Stop(true);
			m_Loop->Stop(true);
		}
		bool NetworkServiceEngine::CreateService()
		{
			if (m_lpszAddress.empty())
			{
				return false;
			}
			m_Client->Connect();
		}
		bool NetworkServiceEngine::CreateService(const std::string & lpszString, const u32 uPort)
		{
			if (m_lpszAddress.empty())
			{
				return false;
			}
			if (std::unique_ptr<TcpClient> Client = std::make_unique<TcpClient>(m_Pool->GetNextLoop(), m_lpszAddress, std::to_string(uPort)); Client != nullptr)
			{
				Client->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
				Client->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
				Client->Bind(lpszString);
				Client->Connect();

				m_ClientData.emplace(std::cend(m_ClientData), std::move(Client));
				return true;
			}
			return false;
		}
		bool NetworkServiceEngine::CancelService()
		{
			return true;
		}
		void NetworkServiceEngine::CancelAllService()
		{
			for (auto & Args : m_ClientData)
			{
				Args->Disconnect();
			}
		}
		void NetworkServiceEngine::SetConnection(Connection cb)
		{
			m_Connection = cb;
		}
		bool NetworkServiceEngine::Send(u32 uMsg, const google::protobuf::Message & Data)
		{
			return this->Send(m_Client->conn(), uMsg, Data);
		}
		bool NetworkServiceEngine::Send(const evpp::TCPConnPtr & Conn, u32 uMsg, const google::protobuf::Message & Data)
		{
			if (Conn != nullptr && Conn->IsConnected() && uMsg != 0)
			{
				if (u32 uSize = Data.ByteSize() + HeadSize; uSize != HeadSize)
				{
					if (m_lpszBody.capacity() < uSize)
					{
						m_lpszBody.resize(uSize);
					}

					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data())) = htonl(uSize);
					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data()) + sizeof(uint32_t)) = htonl(uMsg);

					if (Data.SerializePartialToArray(const_cast<lPString>(m_lpszBody.data()) + HeadSize, Data.ByteSize()))
					{
						Conn->Send(m_lpszBody.data(), uSize);
						return true;
					}
				}
			}
			return false;
		}
		void NetworkServiceEngine::OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer)
		{

		}
		void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
		{
			switch (Conn->status())
			{
			case evpp::TCPConn::kDisconnecting:
			{
				this->SendStatus(Conn, false);
				break;
			}
			case evpp::TCPConn::kConnected:
			{
				this->SendStatus(Conn, true);
				break;
			}
			}
		}
		void NetworkServiceEngine::SendStatus(const evpp::TCPConnPtr & Conn, bool Status)
		{
			if (m_Connection)
			{
				for (u32 i = 0; i < m_ClientData.size(); ++i)
				{
					if (m_ClientData[i]->conn() == Conn)
					{
						m_Connection(i, Status);
						break;
					}
				}
			}
		}
	}
}