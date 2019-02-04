#pragma once
#include <evpp/tcp_server.h>
#include <string>
#include <memory>
namespace Cry
{
	class DataBase;
	class DataPool;
	namespace Import
	{
		class MySQL;
	}
	namespace Action
	{
		class DataBase;
	}
	namespace Signal
	{
		class NetworkServiceEngine;

		struct CustomerData
		{
		public:
			CustomerData() = default;
			CustomerData(w64 Index, const std::string & Username, const std::string & Password) : m_Index(Index), m_Username(Username), m_Password(Password), m_Expires(0) {};
			bool operator == (const CustomerData & Other) const noexcept
			{
				if (Other.m_Index == m_Index)
				{
					return true;
				}
				return Other.m_Username == m_Username && Other.m_Password == m_Password;
			}
			bool operator != (const CustomerData & Other) const noexcept
			{
				return !(*this == Other);
			}
		private:
			w64					m_Index;
			std::string			m_Username;
			std::string			m_Password;
			u32					m_Expires;
		};

		class OnMessageLeave
		{
		public:
			OnMessageLeave() = default;
			explicit OnMessageLeave(evpp::Buffer * pData);
			~OnMessageLeave();
		private:
			evpp::Buffer*														m_pData;
		private:
			OnMessageLeave(const OnMessageLeave &) = default;
			OnMessageLeave &operator=(const OnMessageLeave &) = default;
		};

		class Work : public std::enable_shared_from_this<Work>
		{
		public:
			explicit Work(NetworkServiceEngine * Services, const evpp::TCPConnPtr & Conn, const std::shared_ptr<DataBase> & DB);
			~Work();
		public:
			void Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * Data);
			void Close();
			void SetCustomer(w64 wIndex, std::string & UserName, std::string & PassWord);
			bool CheckOnline(const CustomerData & Other) const;
		public:
			std::shared_ptr<CustomerData> & GetCustomerData() { return m_Customer; }
			std::shared_ptr<DataBase> & GetDataBase() { return m_DataBase; }
		private:
			NetworkServiceEngine*												m_Services;
			evpp::TCPConnPtr													m_CurrConn;
			std::shared_ptr<DataBase>											m_DataBase;
			std::unique_ptr<Action::DataBase>									m_Listener;
		private:
			/// 缓冲区
			std::string															m_lpszBody;
			/// 客户信息
			std::shared_ptr<CustomerData>										m_Customer;
		};

		class NetworkServiceEngine
		{
		public:
			explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u64 uSize);
			~NetworkServiceEngine() = default;
		public:
			bool CreateService();
			bool CancelService();
		private:
			void OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer);
			void OnConnection(const evpp::TCPConnPtr & Conn);
		private:
			bool AddWork(u64 Index, const std::shared_ptr<Work> & Work);
			bool DelWork(u64 Index);
			std::shared_ptr<Work> GetWork(u64 Index);
		public:
			bool CheckOnline(const CustomerData & Other);
		private:
			std::unique_ptr<evpp::EventLoopThread>								m_Loop;
			std::unique_ptr<evpp::TCPServer>									m_Services;
			std::shared_ptr<Import::MySQL>										m_MySQL;
			std::shared_ptr<DataPool>											m_DataPool;
		private:
			std::unordered_map<u64, std::shared_ptr<Work>>						m_WorkData;
		private:
			std::mutex															m_WorkLock;
		};
	}
}
