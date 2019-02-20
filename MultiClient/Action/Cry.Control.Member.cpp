#include <Global>
#include <Action/Cry.Control.Member.h>
#include <Service/Cry.Signal.Service.h>
#include <Msg.Control.Member.pb.h>
namespace Cry
{
	namespace Control
	{
		Register::Register(OnRegister cb) : m_OnSocketData(cb) { }

		bool Register::OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgRegisterResponse ProtoResponse;
			{
				if (false == ProtoResponse.ParsePartialFromArray(Data, uSize))
				{
					return false;
				}
				return m_OnSocketData(ProtoResponse.msg(), ProtoResponse.text(), ProtoResponse.uid());
			}
			return false;
		}

		SignIn::SignIn(OnSignIn cb) : m_OnSocketData(cb) { }

		bool SignIn::OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgSignInResponse ProtoResponse;
			{
				if (false == ProtoResponse.ParsePartialFromArray(Data, uSize))
				{
					return false;
				}
				return m_OnSocketData(ProtoResponse.msg(), ProtoResponse.text(), ProtoResponse.uid(), ProtoResponse.expires());
			}
			return false;
		}

		Change::Change(OnChange cb) : m_OnSocketData (cb) {};

		bool Change::OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize)
		{
			Cry::Control::Member::MsgChangeResponse ProtoResponse;
			{
				if (false == ProtoResponse.ParsePartialFromArray(Data, uSize))
				{
					return false;
				}
				return m_OnSocketData(ProtoResponse.msg(), ProtoResponse.text(), ProtoResponse.uid());
			}
			return false;
		}
	}
}