#pragma once
#include <Global>
#include <memory>
#include <functional>
namespace Cry
{
	namespace Signal
	{
		class Work;
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

	class DataBaseInterface
	{
	public:
		explicit DataBaseInterface() = default;
		virtual ~DataBaseInterface() = default;
	public:
		virtual bool Initialize() = 0;
		virtual void DeInitialize() = 0;
	protected:
		DataBaseInterface(const DataBaseInterface &) = default;
		DataBaseInterface &operator=(const DataBaseInterface &) = default;
	};
}