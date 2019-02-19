#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
namespace Poco
{
	namespace Data
	{
		class Session;
	}
}
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
			bool CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const std::shared_ptr<Poco::Data::Session> & Session, const w32 Result, std::string & User, std::string & Pass);
		protected:
			u32 GetExpires(const std::shared_ptr<Poco::Data::Session> & Session, u32 uid, u32 Expires = 0);
		};

		class Register : public SocketDataInterface
		{
		public:
			explicit Register();
			~Register() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, std::string & Email, std::string & Phone, u32 Pin);
		};
	}
}