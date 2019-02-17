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
			if (!ProtoRequest.ParsePartialFromArray(Data, uSize))
			{
				Work->Close();
			}
			return this->OnSignin(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password()), 0, ProtoRequest.version());
		}

		bool SignIn::OnSignin(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & UserName, std::string & PassWord, u32 Code, u32 Version)
		{
			if (std::shared_ptr<Poco::Data::Session> Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?, ?) As Result", Poco::Data::Keywords::use(UserName), Poco::Data::Keywords::use(PassWord), Poco::Data::Keywords::use(Code), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							if (false == this->CheckOnline(Work, Result, UserName, PassWord))
							{
								Cry::Control::Member::MsgSignInResponse ProtoResponse;
								switch (Result)
								{
								case -1: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_EMPTY); ProtoResponse.set_text("���������ֻ�/����/�û���"); break;
								case -2: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_EMPTY); ProtoResponse.set_text("������������"); break;
								case -3: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_ERROR); ProtoResponse.set_text("��������˺Ų�����"); break;
								case -4: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_ERROR); ProtoResponse.set_text("���������������������������һ�����"); break;
								case -5: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_BANME); ProtoResponse.set_text("�����˺��ѱ����"); break;
								case -6: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_CODE); ProtoResponse.set_text("�����뷢���䶯�������°�"); break;
								default:
								{
									if (Poco::Data::Statement Statement = (*Session << "Select Common_Expires(?) As Result", Poco::Data::Keywords::use(Result), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
									{
										if (Result <= std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))
										{
											ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_EXPIRES);
											ProtoResponse.set_text("�����˺��ѵ��ڣ��뼰ʱ��ֵ��");
										}
										else
										{
											ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_NOT_ERROR);
											ProtoResponse.set_expires(Result);
										}
									}
									break;
								}
								}
								return Work->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, static_cast<const google::protobuf::Message &>(ProtoResponse));
							}
							return true;
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

		bool SignIn::CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const w32 Result, std::string & UserName, std::string & PassWord)
		{
			if (Work->CheckOnline(Result, UserName, PassWord))
			{
				Cry::Control::Member::MsgSignInResponse ProtoResponse;
				ProtoResponse.set_uid(static_cast<u32>(Result));
				ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_ONLINE);
				ProtoResponse.set_text("�����˺��Ѿ�����");
				return Work->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, static_cast<const google::protobuf::Message &>(ProtoResponse));
			}
			return false;
		}

		Register::Register() {};

		bool Register::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize)
		{
			return true;
		}
	}
}