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

		bool SignIn::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgSignInRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(Data, uSize))
				{
					Work->Close();
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), 0, ProtoRequest.version());
			}
			return false;
		}

		bool SignIn::OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, u32 Code, u32 Version)
		{
			if (const std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?, ?) As Result", Poco::Data::Keywords::use(User), Poco::Data::Keywords::use(Pass), Poco::Data::Keywords::use(Code), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							if (this->CheckOnline(Work, Result, User, Pass))
							{
								return true;
							}
							Cry::Control::Member::MsgSignInResponse ProtoResponse;
							switch (Result)
							{
							case -1: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_EMPTY); ProtoResponse.set_text("请您输入手机/邮箱/用户名"); break;
							case -2: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_EMPTY); ProtoResponse.set_text("请您输入密码"); break;
							case -3: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_SIZE); ProtoResponse.set_text("您输入的用户名过长"); break;
							case -4: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_SIZE); ProtoResponse.set_text("您输入的密码过长"); break;
							case -5: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_ERROR); ProtoResponse.set_text("您输入的用户名不存在"); break;
							case -6: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_ERROR); ProtoResponse.set_text("您输入的密码有误，请重新输入或找回密码"); break;
							case -7: ProtoResponse.set_msg(Define::CID_SIGNIN_BANME); ProtoResponse.set_text("您的账号已被封禁"); break;
							case -8: ProtoResponse.set_msg(Define::CID_SIGNIN_CODE); ProtoResponse.set_text("机器码发生变动，请重新绑定"); break;
							default:
							{
								if (Poco::Data::Statement Statement = (*Session << "Select Common_Expires(?) As Result", Poco::Data::Keywords::use(Result), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
								{
									if (Result <= std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
									{
										ProtoResponse.set_msg(Define::CID_SIGNIN_EXPIRES);
										ProtoResponse.set_text("您的账号已到期，请及时充值。");
									}
									else
									{
										ProtoResponse.set_msg(Define::CID_SIGNIN_NOT_ERROR);
										ProtoResponse.set_expires(Result);
									}
								}
								break;
							}
							}
							return Work->Send(Define::CID_MESSAGE_SIGNIN, ProtoResponse);
						}
					}
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return false;
		}

		bool SignIn::CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & User, std::string & Pass)
		{
			if (Work->CheckOnline(Result, User, Pass))
			{
				Cry::Control::Member::MsgSignInResponse ProtoResponse;
				ProtoResponse.set_uid(static_cast<u32>(Result));
				ProtoResponse.set_msg(Define::CID_SIGNIN_ONLINE);
				ProtoResponse.set_text("您的账号已经在线");
				return Work->Send(Define::CID_MESSAGE_SIGNIN, ProtoResponse);
			}
			return false;
		}

		Register::Register() {};

		bool Register::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgRegisterRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(Data, uSize))
				{
					Work->Close();
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()));
			}
			return false;
		}

		bool Register::OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass)
		{
			if (const std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Write(?, ?) As Result", Poco::Data::Keywords::use(User), Poco::Data::Keywords::use(Pass), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgRegisterResponse ProtoResponse;

							switch (Result)
							{
							case -1: ProtoResponse.set_msg(Define::CID_WRITE_USERNAME_EMPTY); ProtoResponse.set_text("请您输入手机/邮箱/用户名"); break;
							case -2: ProtoResponse.set_msg(Define::CID_WRITE_PASSWORD_EMPTY); ProtoResponse.set_text("请您输入密码"); break;
							case -3: ProtoResponse.set_msg(Define::CID_WRITE_USERNAME_SIZE); ProtoResponse.set_text("您输入的用户名过长"); break;
							case -4: ProtoResponse.set_msg(Define::CID_WRITE_PASSWORD_SIZE); ProtoResponse.set_text("您输入的密码过长"); break;
							case -5: ProtoResponse.set_msg(Define::CID_WRITE_EXIST); ProtoResponse.set_text("您输入的用户名已存在"); break;
							default:
							{
								ProtoResponse.set_msg(Define::CID_WRITE_NOT_ERROR);
								ProtoResponse.set_uid(Result);
								break;
							}
							}
							return Work->Send(Define::CID_MESSAGE_REGISTER, ProtoResponse);
						}
					}
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return false;
		}
	}
}