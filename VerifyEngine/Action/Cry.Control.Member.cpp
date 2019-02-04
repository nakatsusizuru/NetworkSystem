#include <Global>
#include <Action/Cry.Control.Member.h>
#include <Service/Cry.Signal.Service.h>
#include <Action/Cry.Signal.Proto.hpp>
#include <DataBase/Cry.Signal.DataBase.h>
#include <Msg.Control.Member.pb.h>
namespace Cry
{
	namespace Control
	{
		SignIn::SignIn() {};
		bool SignIn::OnSignin(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & username, std::string & password)
		{
			if (std::shared_ptr<Poco::Data::Session> Session = Work->GetDataBase()->GetSession(); Session != nullptr)
			{
				try
				{
					if (w64 Result = Session->isConnected(); TRUE == Result)
					{
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) As Result", Poco::Data::Keywords::use(username), Poco::Data::Keywords::use(password), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							Cry::Control::Member::MsgSignInResponse ProtoResponse;
							{
								switch (Result)
								{
								case -1: ProtoResponse.set_msg(Define::SignIn::CID_SIGNIN_USERNAME_EMPTY); break;
								case -2: ProtoResponse.set_msg(Define::SignIn::CID_SIGNIN_PASSWORD_EMPTY); break;
								case -3: ProtoResponse.set_msg(Define::SignIn::CID_SIGNIN_USERNAME_ERROR); break;
								case -4: ProtoResponse.set_msg(Define::SignIn::CID_SIGNIN_PASSWORD_ERROR); break;
								default:
								{
									if (Result > 0)
									{
										Work->SetCustomer(Result, username, password);
										ProtoResponse.set_msg(Define::SignIn::CID_SIGNIN_NOT_ERROR);
									}
									else
									{
										Work->Close();
									}
									break;
								}
								}
								
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