#pragma once
#include <evpp/tcp_server.h>
#include <string>
#include <memory>
namespace Cry
{
	class NetworkServiceEngine;

	struct CustomerData
	{
	public:
		CustomerData() = default;
		CustomerData(const std::string & lpszUsername, const std::string & lpszPassword) : Username(lpszUsername), Password(lpszPassword) {};
		bool operator == (const CustomerData & Other) const
		{
			return Other.Username == Username && Other.Password == Password;
		}
		bool operator != (const CustomerData & Other) const
		{
			return !(*this == Other);
		}
	private:
		std::string			Username;
		std::string			Password;
		u32					Expires;
	};

	class Work
	{
	public:
		explicit Work(const NetworkServiceEngine * Service, const evpp::TCPConnPtr & Conn);
		~Work() = default;
	public:
		void Receive(const evpp::Buffer * pData);
	private:
		/// 缓冲区
		std::string													m_lpszBody;
		/// 客户信息
		Cry::CustomerData											m_Customer;
	};

	class NetworkServiceEngine
	{
	public:
		explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u32 & uSize);
		~NetworkServiceEngine() = default;
	public:
		bool CreateService();
		bool CancelService();
	private:
		void OnMessage(const evpp::TCPConnPtr & Conn, const evpp::Buffer * Buffer);
		void OnConnection(const evpp::TCPConnPtr & Conn);
	private:
		bool AddWork(u64 Index, std::shared_ptr<Work> Work);
		bool DelWork(u64 Index);
		std::shared_ptr<Work> GetWork(u64 Index);
	private:
		std::unique_ptr<evpp::EventLoopThread>								m_Loop;
		std::unique_ptr<evpp::TCPServer>									m_Server;
	private:
		std::mutex															m_Mutex;
		std::unordered_map<u64, std::shared_ptr<Work>>						m_Work;
	};
}
