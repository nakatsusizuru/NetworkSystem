#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
namespace Cry
{
	namespace Control
	{
		class SignIn : public SocketDataInterface
		{
		public:
			explicit SignIn();
			~SignIn() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, u32 Code, u32 Version);
			bool CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & User, std::string & Pass);
		};

		class Register : public SocketDataInterface
		{
		public:
			explicit Register();
			~Register() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass);
		};
	}
}