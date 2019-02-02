#include <Global>
#include <Action/Cry.Group.Control.h>
#include <Service/Cry.Signal.Service.h>
#include <Action/Cry.Signal.Proto.hpp>
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
				DebugMsg("用户账号：%s 用户密码：%s\n", ProtoData.username().c_str(), ProtoData.password().c_str());
			}
			return true;
		}
	}
}