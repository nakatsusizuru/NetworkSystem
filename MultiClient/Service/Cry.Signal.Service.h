#pragma once
#include <evpp/tcp_client.h>
#include <evpp/event_loop_thread_pool.h>
#include <vector>
namespace Cry
{
	class NetworkServiceEngine;
	class Work
	{
	public:
		explicit Work(NetworkServiceEngine * Service);
		~Work() = default;
	public:
		void Receive(const evpp::TCPConnPtr & Conn, evpp::Buffer * pData);
	private:
		NetworkServiceEngine*										m_Service;
	private:
		/// »º³åÇø
		std::string													m_lpszBody;
	};

	class NetworkServiceEngine
	{
	public:
		explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags);
		~NetworkServiceEngine();
	public:
		bool CreateService();
		bool CancelService();
	private:
		void OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer);
		void OnConnection(const evpp::TCPConnPtr & Conn);
	private:
		std::unique_ptr<evpp::EventLoopThread>								m_Loop;
		std::unique_ptr<evpp::EventLoopThreadPool>							m_Pool;
		std::unique_ptr<evpp::TCPClient>									m_Service;
		std::vector<std::unique_ptr<evpp::TCPClient>>						m_ClientData;
	};
}