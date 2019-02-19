#pragma once
#include <Global>
#include <memory>
#include <functional>
namespace Cry
{
	namespace Signal
	{
		class Work;
		class NetworkServiceEngine;
	}

	//typedef std::function<void(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const PVOID Data, const u32 uSize)> SocketDataInterface;

	class SocketDataInterface
	{
	public:
		explicit SocketDataInterface() = default;
		virtual ~SocketDataInterface() = default;
	public:
		virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) = 0;
	protected:
		SocketDataInterface(const SocketDataInterface &) = default;
		SocketDataInterface &operator=(const SocketDataInterface &) = default;
	};

	class SocketDataInterfaceEx
	{
	public:
		explicit SocketDataInterfaceEx() = default;
		virtual ~SocketDataInterfaceEx() = default;
	public:
		virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize) = 0;
	protected:
		SocketDataInterfaceEx(const SocketDataInterfaceEx &) = default;
		SocketDataInterfaceEx &operator=(const SocketDataInterfaceEx &) = default;
	};
}