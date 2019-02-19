#pragma once
#include <evpp/tcp_server.h>
#include <google/protobuf/message.h>
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
			CustomerData(w32 Index, const std::string & _Ty1, const std::string & _Ty2) : uIndex(Index), User(_Ty1), Pass(_Ty2) {};
			bool operator == (const CustomerData & Other) const noexcept
			{
				if (Other.uIndex == this->uIndex)
				{
					return true;
				}
				return Other.User == this->User && Other.Pass == this->Pass;
			}
			bool operator != (const CustomerData & Other) const noexcept
			{
				return !(*this == Other);
			}
		private:
			w32							uIndex;
		private:
			std::string					User;
			std::string					Pass;
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
			bool Send(u32 uMsg, const google::protobuf::Message & Data);
			void Close();
			bool CheckOnline(w32 wIndex, const std::string & UserName, const std::string & PassWord);
			bool CheckOnline(const CustomerData & Other) const;
			bool MakeOnline(w32 wIndex, const std::string & UserName, const std::string & PassWord);
		public:
			const std::shared_ptr<CustomerData> & GetCustomerData() const { return m_Customer; }
			const std::shared_ptr<DataBase> & GetDataBase() const { return m_DataBase; }
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
			bool CheckOnline(const std::shared_ptr<CustomerData> & Other);
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
