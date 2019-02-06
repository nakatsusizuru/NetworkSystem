#pragma once
#include <evpp/tcp_client.h>
#include <evpp/event_loop_thread_pool.h>
#include <google/protobuf/message.h>
#include <vector>
namespace Cry
{
	using EventLoopThread = evpp::EventLoopThread;
	using EventLoopThreadPool = evpp::EventLoopThreadPool;
	using TcpClient = evpp::TCPClient;
	typedef std::function<void(const u32 Index, bool Status)> Connection;
	class AvailablePort;

	namespace Signal
	{
		class NetworkServiceEngine
		{
		public:
			explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags);
			~NetworkServiceEngine();
		public:
			bool CreateService(const std::string & lpszString, const u32 uPort);
			bool CancelService();
			void CancelAllService();
			void SetConnection(Connection cb);
			bool Send(u32 uMsg, const google::protobuf::Message & Data);
		private:
			void OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Buffer);
			void OnConnection(const evpp::TCPConnPtr & Conn);
		private:
			void SendStatus(const evpp::TCPConnPtr & Conn, bool Status);
		private:
			std::string															m_lpszAddress;
			std::string															m_lpszFlags;
			Cry::Connection														m_Connection;
		private:
			std::unique_ptr<EventLoopThread>									m_Loop;
			std::unique_ptr<EventLoopThreadPool>								m_Pool;
			std::unique_ptr<AvailablePort>										m_AvailablePort;
			std::vector<std::unique_ptr<TcpClient>>								m_ClientData;
		private:
			std::string															m_lpszBody;
		};
	}
}