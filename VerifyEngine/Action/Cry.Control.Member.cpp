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
					if (w64 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) As Result", Poco::Data::Keywords::use(UserName), Poco::Data::Keywords::use(PassWord), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgSignInResponse ProtoResponse;
							{
								switch (Result)
								{
								case -1: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_EMPTY); break;
								case -2: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_EMPTY); break;
								case -3: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_USERNAME_ERROR); break;
								case -4: ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_PASSWORD_ERROR); break;
								}
								Work->SetCustomer(Result, UserName, PassWord);
								ProtoResponse.set_msg(Cry::Control::Define::CID_SIGNIN_NOT_ERROR);
								ProtoResponse.set_uid(static_cast<u64>(Result));
								ProtoResponse.set_expires(0);
								Work->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, static_cast<const google::protobuf::Message &>(ProtoResponse));
							}
							return true;
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
			{
				if (!ProtoRequest.ParsePartialFromArray(Data, uSize))
				{
					Work->Close();
				}

				if (!this->OnSignin(Work, const_cast<std::string &>(ProtoRequest.username()), const_cast<std::string &>(ProtoRequest.password())))
				{
					Work->Close();
				}
			}
			return false;
		}
	}
}