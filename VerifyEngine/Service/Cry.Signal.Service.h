#pragma once
#include <evpp/tcp_server.h>
#include <string>
#include <memory>
namespace Cry
{
	class NetworkServiceEngine;
	class DataBase;
	class DataBasePool;

	namespace Import
	{
		class MySQL;
	}

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
		explicit Work(NetworkServiceEngine * Service);
		~Work();
	public:
		void Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * pData);
	private:
		NetworkServiceEngine*										m_Service;
	private:
		/// ������
		std::string													m_lpszBody;
		/// �ͻ���Ϣ
		Cry::CustomerData											m_Customer;
	};

	class NetworkServiceEngine
	{
	public:
		explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags, const u64 & uSize);
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
	private:
		std::unique_ptr<evpp::EventLoopThread>								m_Loop;
		std::unique_ptr<evpp::TCPServer>									m_Service;
		std::shared_ptr<Import::MySQL>										m_MySQL;
		std::shared_ptr<DataBase>											m_DataBase;
		std::shared_ptr<DataBasePool>										m_DataBasePool;
	private:
		std::mutex															m_Mutex;
		std::unordered_map<u64, std::shared_ptr<Work>>						m_Work;
	};
}
