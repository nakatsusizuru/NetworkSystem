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
						if (w32 Result = Session->isConnected(); TRUE == Result)
						{
							if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) AS Result", Poco::Data::Keywords::use(const_cast<std::string&>(ProtoData.username())), Poco::Data::Keywords::use(const_cast<std::string&>(ProtoData.password())), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
							{
								switch (Result)
								{
								case 0U: DebugMsg("��֤ͨ��\n"); break;
								case -1: DebugMsg("�˺�Ϊ��\n"); break;
								case -2: DebugMsg("����Ϊ��\n"); break;
								case -3: DebugMsg("�˺Ŵ���\n"); break;
								case -4: DebugMsg("�������\n"); break;
								default: DebugMsg("ʲô����\n"); break;
								}
								return true;
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