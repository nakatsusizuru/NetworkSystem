#include <Global>
#include <Action/Cry.Control.Member.h>
#include <Service/Cry.Signal.Service.h>
#include <DataBase/Cry.Signal.DataBase.h>
#include <Poco/Data/MySQL/MySQLException.h>
#include <Log/Logging.h>
#include <Msg.Control.Member.pb.h>
namespace Cry
{
	namespace Control
	{

		Register::Register() {};

		bool Register::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize)
		{
			Cry::Control::Member::MsgRegisterRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(cbData, uSize))
				{
					Work->Close();
					return false;
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), const_cast<std::string &>(ProtoRequest.email()), const_cast<std::string &>(ProtoRequest.phone()), ProtoRequest.pin());
			}
			return false;
		}

		bool Register::OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, std::string & Email, std::string & Phone, u32 Pin)
		{
			if (const std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Write(?, ?, ?, ?, ?) As Result", Poco::Data::Keywords::use(User), Poco::Data::Keywords::use(Pass), Poco::Data::Keywords::use(Email), Poco::Data::Keywords::use(Phone), Poco::Data::Keywords::use(Pin), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgRegisterResponse ProtoResponse;

							switch (Result)
							{
							case -0x00: ProtoResponse.set_msg(Define::CID_WRITE_DEFAULT);			ProtoResponse.set_text("未知的错误"); break;
							case -0x01: ProtoResponse.set_msg(Define::CID_WRITE_USERNAME_EMPTY);	ProtoResponse.set_text("请您输入账号"); break;
							case -0x02: ProtoResponse.set_msg(Define::CID_WRITE_PASSWORD_EMPTY);	ProtoResponse.set_text("请您输入密码"); break;
							case -0x03: ProtoResponse.set_msg(Define::CID_WRITE_EMAIL_EMPTY);		ProtoResponse.set_text("请您输入邮箱"); break;
							case -0x04: ProtoResponse.set_msg(Define::CID_WRITE_PHONE_EMPTY);		ProtoResponse.set_text("请您输入电话"); break;
							case -0x05: ProtoResponse.set_msg(Define::CID_WRITE_PIN_EMPTY);			ProtoResponse.set_text("请您输入PIN码"); break;
							case -0x06: ProtoResponse.set_msg(Define::CID_WRITE_USERNAME_SIZE);		ProtoResponse.set_text("账号不符合要求"); break;
							case -0x07: ProtoResponse.set_msg(Define::CID_WRITE_PASSWORD_SIZE);		ProtoResponse.set_text("密码不符合要求"); break;
							case -0x08: ProtoResponse.set_msg(Define::CID_WRITE_EMAIL_SIZE);		ProtoResponse.set_text("邮箱不符合要求"); break;
							case -0x09: ProtoResponse.set_msg(Define::CID_WRITE_PHONE_SIZE);		ProtoResponse.set_text("电话不符合要求"); break;
							case -0x0A: ProtoResponse.set_msg(Define::CID_WRITE_PIN_SIZE);			ProtoResponse.set_text("PIN码不符合要求"); break;
							case -0x0B: ProtoResponse.set_msg(Define::CID_WRITE_EXIST);				ProtoResponse.set_text("您输入的账号已存在"); break;
							default:
							{
								ProtoResponse.set_msg(Define::CID_WRITE_NOT_ERROR);
								ProtoResponse.set_text("注册成功");
								ProtoResponse.set_uid(Result);
								CryMessage("账号[%s]注册成功 UID[%d]", User.c_str(), Result);
								break;
							}
							}
							return Work->Send(Define::CID_MESSAGE_REGISTER, ProtoResponse);
						}
					}
				}
				catch (const Poco::Data::MySQL::ConnectionException & ce)
				{
					LOG_ERROR << ce.displayText();
				}
				catch (const Poco::Data::MySQL::StatementException & se)
				{
					LOG_ERROR << se.displayText();
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return false;
		}

		SignIn::SignIn() {};

		bool SignIn::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize)
		{
			Cry::Control::Member::MsgSignInRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(cbData, uSize))
				{
					Work->Close();
					return false;
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), 123, ProtoRequest.version());
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
							if (this->CheckOnline(Work, Session, Result, User, Pass))
							{
								return true;
							}

							Cry::Control::Member::MsgSignInResponse ProtoResponse;

							switch (Result)
							{
							case -0x00: ProtoResponse.set_msg(Define::CID_SIGNIN_DEFAULT);				ProtoResponse.set_text("未知的错误"); break;
							case -0x01: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_EMPTY);		ProtoResponse.set_text("请您输入手机/邮箱/账号"); break;
							case -0x02: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_EMPTY);		ProtoResponse.set_text("请您输入密码"); break;
							case -0x03: ProtoResponse.set_msg(Define::CID_SIGNIN_CODE_EMPTY);			ProtoResponse.set_text("请您输入机器码"); break;
							case -0x04: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_SIZE);		ProtoResponse.set_text("您输入的账号不符合要求"); break;
							case -0x05: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_SIZE);		ProtoResponse.set_text("您输入的密码不符合要求"); break;
							case -0x06: ProtoResponse.set_msg(Define::CID_SIGNIN_CODE_SIZE);			ProtoResponse.set_text("您输入的机器码不符合要求"); break;
							case -0x07: ProtoResponse.set_msg(Define::CID_SIGNIN_USERNAME_ERROR);		ProtoResponse.set_text("您输入的账号不存在"); break;
							case -0x08: ProtoResponse.set_msg(Define::CID_SIGNIN_PASSWORD_ERROR);		ProtoResponse.set_text("您输入的密码有误，请重新输入或找回密码"); break;
							case -0x09: ProtoResponse.set_msg(Define::CID_SIGNIN_BANME);				ProtoResponse.set_text("您输入的账号已被封禁"); break;
							case -0x0A: ProtoResponse.set_msg(Define::CID_SIGNIN_CODE);					ProtoResponse.set_text("您输入的账号机器码发生变动"); break;
							default:
							{
								if (u32 Expires = this->GetExpires(Session, Result); Expires >= 0)
								{
									if (Expires <= std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
									{
										ProtoResponse.set_msg(Define::CID_SIGNIN_EXPIRES);
										ProtoResponse.set_text("您的账号已到期，请及时充值。");
										ProtoResponse.set_uid(Result);
										ProtoResponse.set_expires(0);
									}
									else
									{
										if (Work->MakeOnline(Result, User, Pass))
										{
											ProtoResponse.set_msg(Define::CID_SIGNIN_NOT_ERROR);
											ProtoResponse.set_text("登录成功");
											ProtoResponse.set_uid(Result);
											ProtoResponse.set_expires(Expires);
										}
									}
								}
								break;
							}
							}
							return Work->Send(Define::CID_MESSAGE_SIGNIN, ProtoResponse);
						}
					}
				}
				catch (const Poco::Data::MySQL::ConnectionException & ce)
				{
					LOG_ERROR << ce.displayText();
				}
				catch (const Poco::Data::MySQL::StatementException & se)
				{
					LOG_ERROR << se.displayText();
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return false;
		}

		bool SignIn::CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const std::shared_ptr<Poco::Data::Session> & Session, const w32 Result, std::string & User, std::string & Pass)
		{
			if (Work->CheckOnline(Result, User, Pass))
			{
				Cry::Control::Member::MsgSignInResponse ProtoResponse;
				ProtoResponse.set_uid(static_cast<u32>(Result));
				ProtoResponse.set_msg(Define::CID_SIGNIN_ONLINE);
				ProtoResponse.set_expires(this->GetExpires(Session, Result));
				ProtoResponse.set_text("您的账号已经在线");
				return Work->Send(Define::CID_MESSAGE_SIGNIN, ProtoResponse);
			}
			return false;
		}

		u32 SignIn::GetExpires(const std::shared_ptr<Poco::Data::Session> & Session, u32 uid, u32 Expires)
		{
			try
			{
				if (Poco::Data::Statement Statement = (*Session << "Select Common_Expires(?) As Result", Poco::Data::Keywords::use(uid), Poco::Data::Keywords::into(Expires), Poco::Data::Keywords::now); Statement.done() == true)
				{
					return Expires;
				}
			}
			catch (const Poco::Data::MySQL::ConnectionException & ce)
			{
				LOG_ERROR << ce.displayText();
			}
			catch (const Poco::Data::MySQL::StatementException & se)
			{
				LOG_ERROR << se.displayText();
			}
			catch (const Poco::Exception & ex)
			{
				LOG_ERROR << ex.displayText();
			}
			return 0;
		}

		ChangePass::ChangePass() {}

		bool ChangePass::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize)
		{
			Cry::Control::Member::MsgChangePassRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(cbData, uSize))
				{
					Work->Close();
					return false;
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), const_cast<std::string &>(ProtoRequest.newspass()), ProtoRequest.pin());
			}
			return false;
		}
		bool ChangePass::OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, std::string & NewsPass, u32 Pin)
		{
			if (const std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_ChangePass(?, ?, ?, ?) As Result", Poco::Data::Keywords::use(User), Poco::Data::Keywords::use(Pass), Poco::Data::Keywords::use(NewsPass), Poco::Data::Keywords::use(Pin), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgChangePassResponse ProtoResponse;
							switch (Result)
							{
							case -0x00: ProtoResponse.set_msg(Define::CID_CHANGEPASS_DEFAULT);				ProtoResponse.set_text("未知的错误"); break;
							case -0x01: ProtoResponse.set_msg(Define::CID_CHANGEPASS_USERNAME_EMPTY);		ProtoResponse.set_text("请您输入手机/邮箱/账号"); break;
							case -0x02: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PASSWORD_EMPTY);		ProtoResponse.set_text("请您输入密码"); break;
							case -0x03: ProtoResponse.set_msg(Define::CID_CHANGEPASS_NEWSPASS_EMPTY);		ProtoResponse.set_text("请您输入新的密码"); break;
							case -0x04: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PIN_EMPTY);			ProtoResponse.set_text("请您输入PIN密码"); break;
							case -0x05: ProtoResponse.set_msg(Define::CID_CHANGEPASS_USERNAME_SIZE);		ProtoResponse.set_text("您输入的账号不符合要求"); break;
							case -0x06: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PASSWORD_SIZE);		ProtoResponse.set_text("您输入的密码不符合要求"); break;
							case -0x07: ProtoResponse.set_msg(Define::CID_CHANGEPASS_NEWSPASS_SIZE);		ProtoResponse.set_text("您输入的新密码不符合要求"); break;
							case -0x08: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PIN_SIZE);				ProtoResponse.set_text("您输入的PIN密码不符合要求"); break;
							case -0x09: ProtoResponse.set_msg(Define::CID_CHANGEPASS_SAME_ERROR);			ProtoResponse.set_text("新密码与旧密码不能相同"); break;
							case -0x0A: ProtoResponse.set_msg(Define::CID_CHANGEPASS_USERNAME_ERROR);		ProtoResponse.set_text("您输入的账号不存在"); break;
							case -0x0B: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PASSWORD_ERROR);		ProtoResponse.set_text("您输入的原始密码有误"); break;
							case -0x0C: ProtoResponse.set_msg(Define::CID_CHANGEPASS_PIN_ERROR);			ProtoResponse.set_text("您输入的PIN密码有误"); break;
							default:	ProtoResponse.set_msg(Define::CID_CHANGEPASS_NOT_ERROR);			ProtoResponse.set_text("密码修改成功");		ProtoResponse.set_uid(Result); break;
							}
							return Work->Send(Define::CID_MESSAGE_CHANGE, ProtoResponse);
						}
					}
				}
				catch (const Poco::Data::MySQL::ConnectionException & ce)
				{
					LOG_ERROR << ce.displayText();
				}
				catch (const Poco::Data::MySQL::StatementException & se)
				{
					LOG_ERROR << se.displayText();
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return true;
		}

		ChangeBind::ChangeBind() {};

		bool ChangeBind::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize)
		{
			Cry::Control::Member::MsgChangeBindRequest ProtoRequest;
			{
				if (false == ProtoRequest.ParsePartialFromArray(cbData, uSize))
				{
					Work->Close();
					return false;
				}
				return this->OnMessage(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), ProtoRequest.secret(), 3600);
			}
			return false;
		}

		bool ChangeBind::OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, u32 Secret, u32 Expire)
		{

			if (const std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_ChangeBind(?, ?, ?, ?) As Result", Poco::Data::Keywords::use(User), Poco::Data::Keywords::use(Pass), Poco::Data::Keywords::use(Secret), Poco::Data::Keywords::use(Expire), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgChangeBindResponse ProtoResponse;
							switch (Result)
							{
							case -0x00: ProtoResponse.set_msg(Define::CID_CHANGEBIND_DEFAULT);				ProtoResponse.set_text("未知的错误"); break;
							case -0x01: ProtoResponse.set_msg(Define::CID_CHANGEBIND_USERNAME_EMPTY);		ProtoResponse.set_text("请您输入手机/邮箱/账号"); break;
							case -0x02: ProtoResponse.set_msg(Define::CID_CHANGEBIND_PASSWORD_EMPTY);		ProtoResponse.set_text("请您输入密码"); break;
							case -0x03: ProtoResponse.set_msg(Define::CID_CHANGEBIND_SECRET_EMPTY);			ProtoResponse.set_text("请您输入解锁密码"); break;
							case -0x04: ProtoResponse.set_msg(Define::CID_CHANGEBIND_USERNAME_SIZE);		ProtoResponse.set_text("您输入的账号不符合要求"); break;
							case -0x05: ProtoResponse.set_msg(Define::CID_CHANGEBIND_PASSWORD_SIZE);		ProtoResponse.set_text("您输入的密码不符合要求"); break;
							case -0x06: ProtoResponse.set_msg(Define::CID_CHANGEBIND_SECRET_SIZE);			ProtoResponse.set_text("您输入的解锁密码不符合要求"); break;
							case -0x07: ProtoResponse.set_msg(Define::CID_CHANGEBIND_USERNAME_ERROR);		ProtoResponse.set_text("您输入的账号不存在"); break;
							case -0x08: ProtoResponse.set_msg(Define::CID_CHANGEBIND_PASSWORD_ERROR);		ProtoResponse.set_text("您输入的密码有误，请重新输入或找回密码"); break;
							case -0x09: ProtoResponse.set_msg(Define::CID_CHANGEBIND_SECRET_ERROR);			ProtoResponse.set_text("您输入的解锁密码有误"); break;
							case -0x0A: ProtoResponse.set_msg(Define::CID_CHANGEBIND_SECRET_EXPIRE);		ProtoResponse.set_text("您输入的解锁密码已经过期"); break;
							default:	ProtoResponse.set_msg(Define::CID_CHANGEBIND_NOT_ERROR);			ProtoResponse.set_text("解锁成功");		ProtoResponse.set_uid(Result); break;
							}
							return Work->Send(Define::CID_MESSAGE_CHANGE, ProtoResponse);
						}
					}
				}
				catch (const Poco::Data::MySQL::ConnectionException & ce)
				{
					LOG_ERROR << ce.displayText();
				}
				catch (const Poco::Data::MySQL::StatementException & se)
				{
					LOG_ERROR << se.displayText();
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
			}
			return true;
		}
	}
}