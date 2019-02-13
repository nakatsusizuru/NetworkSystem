#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
namespace Cry
{
	namespace Control
	{
		namespace Member
		{
			class MsgSignInResponse;
		}
		class SignIn : public SocketDataInterface
		{
		public:
			explicit SignIn();
			~SignIn() = default;
			
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			bool OnSignin(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & UserName, std::string & PassWord, u32 Code, u32 Version);
			bool CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & UserName, std::string & PassWord);
		};
	}
}