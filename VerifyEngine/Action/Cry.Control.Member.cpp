#include <Global>
#include <Action/Cry.Control.Member.h>
#include <Service/Cry.Signal.Service.h>
#include <DataBase/Cry.Signal.DataBase.h>
#include <Msg.Control.Member.pb.h>
namespace Cry
{
	namespace Control
	{
		SignIn::SignIn() {};
		bool SignIn::OnSignin(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & UserName, std::string & PassWord)
		{
			if (std::shared_ptr<Poco::Data::Session> Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) As Result", Poco::Data::Keywords::use(UserName), Poco::Data::Keywords::use(PassWord), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							return this->SendResponse(Work, Result, UserName, PassWord);
						}
					}
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
				return true;
			}
			return false;
		}
		bool SignIn::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgSignInRequest ProtoRequest;
			if (!ProtoRequest.ParsePartialFromArray(Data, uSize))
			{
				Work->Close();
			}
			return this->OnSignin(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()));
		}

		bool SignIn::CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & UserName, std::string & PassWord)
		{
			if (Work->CheckOnline(Result, UserName, PassWord))
			{
				Cry::Control::Member::MsgSignInResponse ProtoResponse;
				ProtoResponse.set_uid(static_cast<u64>(Result));
				ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_NOT_ONLINE);
				ProtoResponse.set_text("您的账号已经在线");
				return Work->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, static_cast<const google::protobuf::Message &>(ProtoResponse));
			}
			return false;
		}

		bool SignIn::SendResponse(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & UserName, std::string & PassWord)
		{
			if (false == this->CheckOnline(Work, Result, UserName, PassWord))
			{
				Cry::Control::Member::MsgSignInResponse ProtoResponse;
				switch (Result)
				{
				case -1: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_EMPTY); ProtoResponse.set_text("请您输入手机/邮箱/用户名"); break;
				case -2: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_EMPTY); ProtoResponse.set_text("请您输入密码"); break;
				case -3: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_ERROR); ProtoResponse.set_text("您输入的账号不存在"); break;
				case -4: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_ERROR); ProtoResponse.set_text("您输入的密码有误，请重新输入或找回密码"); break;
				default: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_NOT_ERROR);	ProtoResponse.set_expires(0); break;
				}
				return Work->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, static_cast<const google::protobuf::Message &>(ProtoResponse));
			}
			return false;
		}
	}
}