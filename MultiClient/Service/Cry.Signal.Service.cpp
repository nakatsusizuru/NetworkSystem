#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <Service/Cry.Signal.Port.h>
#include <Interface/Cry.Signal.Interface.hpp>
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

		NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags) : m_lpszAddress(lpszAddress), m_lpszFlags(lpszFlags), m_Loop(std::make_unique<EventLoopThread>()), m_Client(std::make_unique<TcpClient>(m_Loop->loop(), lpszAddress, lpszFlags))
		{
			m_Client->SetConnectionCallback(std::bind(&NetworkServiceEngine::OnConnection, this, std::placeholders::_1));
			m_Client->SetMessageCallback(std::bind(&NetworkServiceEngine::OnMessage, this, std::placeholders::_1, std::placeholders::_2));
			m_Loop->Start(true);
		}
		NetworkServiceEngine::~NetworkServiceEngine()
		{
			this->CancelService();
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

		bool NetworkServiceEngine::CancelService()
		{
			m_Client->Disconnect();
			return true;
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
				if (u32 uSize = Data.ByteSize() + HeadSize; uSize >= HeadSize)
				{
					if (m_lpszBody.capacity() < uSize)
					{
						m_lpszBody.resize(uSize);
					}

					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data())) = htonl(uSize);
					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data()) + sizeof(u32)) = htonl(uMsg);

					if (Data.SerializePartialToArray(const_cast<lPString>(m_lpszBody.data()) + HeadSize, Data.ByteSize()))
					{
						Conn->Send(m_lpszBody.data(), uSize);
						return true;
					}
				}
			}
			return false;
		}

		void NetworkServiceEngine::SetupInterface(const u32 uMsg, const std::shared_ptr<Cry::SocketDataInterfaceEx> & f)
		{
			if (m_Data.find(uMsg) == std::end(m_Data))
			{
				m_Data.emplace(uMsg, f);
			}
		}

		std::shared_ptr<Cry::SocketDataInterfaceEx> NetworkServiceEngine::Get(const u32 uMsg)
		{
			if (auto iter = m_Data.find(uMsg); iter != std::end(m_Data))
			{
				return iter->second;
			}
			return std::shared_ptr<Cry::SocketDataInterfaceEx>();
		}

		void NetworkServiceEngine::OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Data)
		{
			OnMessageLeave Leave(Data);
			{
				u32 uMsg = 0, uSize = 0;
				while (Data->length() > 0)
				{
					if (!uMsg)
					{
						if (Data->length() < HeadSize)
						{
							return;
						}
						uSize = Data->ReadInt32();
						uSize -= HeadSize;
						uMsg = Data->ReadInt32();
					}

					if (Data->size() < uSize)
					{
						return;
					}

					if (const std::shared_ptr<Cry::SocketDataInterfaceEx> & Listener = this->Get(uMsg); Listener != nullptr)
					{
						if (!Listener->OnSocketData(shared_from_this(), uMsg, Data->data(), uSize))
						{
							DebugMsg("Listener\n");
							//this->Close();
						}
					}

					Data->Skip(uSize);
					uMsg = 0;
				}
			}
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

		}
	}
}