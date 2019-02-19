#include <Global>
#include <Service/Cry.Signal.Service.h>
#include <DataBase/Cry.Signal.DataBase.h>
#include <DataBase/Cry.Signal.DataBasePool.h>
#include <Action/Cry.Action.DataBase.h>
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

		Work::Work(NetworkServiceEngine * Services, const evpp::TCPConnPtr & Conn, const std::shared_ptr<DataBase> & DB) : m_Services(Services), m_CurrConn(Conn), m_DataBase(DB), m_Listener(std::make_unique<Action::DataBase>()), m_Customer()
		{

		}
		void Work::Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * Data)
		{
			OnMessageLeave Leave(Data);
			{
				if (false == m_Listener->empty())
				{
					return;
				}

				u32 uMsg = 0, uSize = 0;

				while (Data->length() > 0)
				{
					if (!uMsg)
					{
						if (!m_Services || Data->length() < HeadSize)
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

					if (const std::shared_ptr<Cry::SocketDataInterface> & Listener = m_Listener->Get(uMsg); Listener != nullptr)
					{
						if (!Listener->OnSocketData(shared_from_this(), uMsg, Data->data(), uSize))
						{
							DebugMsg("Listener\n");
							this->Close();
						}
					}

					Data->Skip(uSize);
					uMsg = 0;
				}
			}
		}
		bool Work::Send(u32 uMsg, const google::protobuf::Message & Data)
		{
			if (m_CurrConn != nullptr && m_CurrConn->IsConnected() && uMsg != 0)
			{
				if (u32 uSize = Data.ByteSize() + HeadSize; uSize != HeadSize)
				{
					if (m_lpszBody.capacity() < uSize)
					{
						m_lpszBody.resize(uSize);
					}

					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data())) = htonl(uSize);
					*reinterpret_cast<u32 *>(const_cast<lPString>(m_lpszBody.data()) + sizeof(u32)) = htonl(uMsg);

					if (Data.SerializePartialToArray(const_cast<lPString>(m_lpszBody.data()) + HeadSize, Data.ByteSize()))
					{
						m_CurrConn->Send(m_lpszBody.data(), uSize);
						return true;
					}
				}
			}
			return false;
		}
		void Work::Close()
		{
			if (m_CurrConn->IsConnected())
			{
				m_CurrConn->Close();
			}
		}
		bool Work::CheckOnline(w32 wIndex, std::string & UserName, std::string & PassWord)
		{
			if (wIndex < 0)
			{
				return false;
			}
			if(false == this->CheckOnline({ wIndex, UserName, PassWord }))
			{
				m_Customer = std::make_shared<Cry::Signal::CustomerData>(wIndex, UserName, PassWord);
				return false;
			}
			return true;
		}
		bool Work::CheckOnline(const CustomerData & Other) const
		{
			if (m_Services != nullptr)
			{
				if (m_Customer != nullptr)
				{
					return m_Services->CheckOnline(m_Customer);
				}
				return m_Services->CheckOnline(Other);
			}
			return true;
		}
		Work::~Work()
		{
			this->Close();
		}
		NetworkServiceEngine::NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u64 uSize) : m_Loop(std::make_unique<evpp::EventLoopThread>()), m_Services(std::make_unique<evpp::TCPServer>(m_Loop->loop(), lpszAddress, lpszFlags, uSize)), m_MySQL(std::make_shared<Import::MySQL>())
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
			{
				Work->Receive(Conn, Buffer);
			}
			else
			{
				Conn->Close();
			}
		}
		void NetworkServiceEngine::OnConnection(const evpp::TCPConnPtr & Conn)
		{
			if (Conn->IsConnected())
			{
				if (!this->AddWork(Conn->id(), std::make_shared<Work>(this, Conn, m_DataPool->GetNextMySQL(Conn->id()))))
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
					m_WorkData.emplace(Index, Work);
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
			return std::shared_ptr<Work>();
		}

		bool NetworkServiceEngine::CheckOnline(const std::shared_ptr<CustomerData> & Other)
		{
			std::lock_guard<std::mutex> Guard(m_WorkLock);
			{
				for (const auto & [Index, Work] : m_WorkData)
				{
					if (Work != nullptr)
					{
						if (const std::shared_ptr<CustomerData> & Customer = Work->GetCustomerData(); Other != nullptr && Customer != nullptr)
						{
							if (Other == Customer)
							{
								return true;
							}
						}
					}
				}
			}
			return false;
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
							if (Other == *Customer)
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
}
