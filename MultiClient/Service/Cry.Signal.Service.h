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

	class SocketDataInterfaceEx;

	namespace Signal
	{
		class NetworkServiceEngine;

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

		class NetworkServiceEngine : public std::enable_shared_from_this<NetworkServiceEngine>
		{
		public:
			explicit NetworkServiceEngine(const std::string & lpszAddress, const std::string & lpszFlags);
			~NetworkServiceEngine();
		public:
			bool CreateService();
			bool CancelService();
			void SetConnection(Connection cb);
			bool Send(u32 uMsg, const google::protobuf::Message & Data);
			bool Send(const evpp::TCPConnPtr & Conn, u32 uMsg, const google::protobuf::Message & Data);
			void SetupInterface(const u32 uMsg, const std::shared_ptr<Cry::SocketDataInterfaceEx> & f);
			std::shared_ptr<Cry::SocketDataInterfaceEx> Get(const u32 uMsg);
		private:
			void OnMessage(const evpp::TCPConnPtr & Conn, evpp::Buffer * Data);
			void OnConnection(const evpp::TCPConnPtr & Conn);
		private:
			void SendStatus(const evpp::TCPConnPtr & Conn, bool Status);
		private:
			std::string																	m_lpszAddress;
			std::string																	m_lpszFlags;
			Cry::Connection																m_Connection;
		private:
			std::unique_ptr<EventLoopThread>											m_Loop;
			std::unique_ptr<TcpClient>													m_Client;
			std::unordered_map<u32, std::shared_ptr<Cry::SocketDataInterfaceEx>>		m_Data;
		private:
			std::string																	m_lpszBody;
		};
	}
}