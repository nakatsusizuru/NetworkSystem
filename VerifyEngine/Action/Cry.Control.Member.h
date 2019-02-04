#pragma once
#include <Action/Cry.Signal.Interface.hpp>
namespace Cry
{
	namespace Control
	{
		class SignIn : public SocketDataInterface
		{
		public:
			explicit SignIn();
			~SignIn() = default;
		public:
			bool OnSignin(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & username, std::string & password);
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			
		};
	}
}