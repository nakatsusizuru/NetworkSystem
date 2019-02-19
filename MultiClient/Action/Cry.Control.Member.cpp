#include <Global>
#include <Action/Cry.Control.Member.h>
#include <Service/Cry.Signal.Service.h>
#include <Msg.Control.Member.pb.h>
namespace Cry
{
	namespace Control
	{
		SignIn::SignIn(OnSignIn cb) : m_OnSignIn(cb) { }

		bool SignIn::OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgSignInResponse ProtoResponse;
			{
				if (false == ProtoResponse.ParsePartialFromArray(Data, uSize))
				{
					
				}
				return m_OnSignIn(ProtoResponse.msg(), ProtoResponse.text());
			}
			return false;
		}
	}
}