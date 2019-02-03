#include <Global>
#include <Action/Cry.Group.Control.h>
#include <Service/Cry.Signal.Service.h>
#include <Action/Cry.Signal.Proto.hpp>
#include <DataBase/Cry.Signal.DataBase.h>
#include <member.pb.h>
namespace Cry
{
	namespace Group
	{
		Center::Center() {};

		bool Center::OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Signal::Register ProtoData;
			{
				if (!ProtoData.ParsePartialFromArray(Data, uSize))
				{
					Work->Close();
				}
				try
				{
					if (std::shared_ptr<Poco::Data::Session> & Session = Work->GetDataBase()->GetSession(); Session != nullptr)
					{
						if (bool Result = Session->isConnected(); true == Result)
						{
							/// EXECUTE CALL
							if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) AS Result", Poco::Data::Keywords::use(const_cast<std::string&>(ProtoData.username())), Poco::Data::Keywords::use(const_cast<std::string&>(ProtoData.password())), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
							{
								DebugMsg("²éÕÒ½á¹û£º%d\n", Result);
								return Result;
							}
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