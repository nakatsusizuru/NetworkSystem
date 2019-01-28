#pragma once
#include <evpp/tcp_server.h>
#include <string>
#include <memory>
namespace Cry
{
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
		std::unique_ptr<evpp::EventLoopThread>						m_Loop;
		std::unique_ptr<evpp::TCPServer>							m_Server;
	};
}
