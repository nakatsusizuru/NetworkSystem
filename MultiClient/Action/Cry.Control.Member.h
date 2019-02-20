#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
namespace Cry
{
	namespace Control
	{

		typedef std::function<bool(const u32 uMsg, const std::string & Text, const u32 uid)> OnRegister;

		class Register : public SocketDataInterfaceEx
		{
		public:
			explicit Register(OnRegister cb);
			virtual ~Register() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			OnRegister									m_OnSocketData;
		};

		typedef std::function<bool(const u32 uMsg, const std::string & Text, const u32 uid, const u32 expires)> OnSignIn;

		class SignIn : public SocketDataInterfaceEx
		{
		public:
			explicit SignIn(OnSignIn cb);
			virtual ~SignIn() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			OnSignIn									m_OnSocketData;
		};

		typedef std::function<bool(const u32 uMsg, const std::string & Text, const u32 uid)> OnChange;

		/// ÐÞ¸ÄÃÜÂë
		class Change : public SocketDataInterfaceEx
		{
		public:
			explicit Change(OnChange cb);
			virtual ~Change() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::NetworkServiceEngine> & Service, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			OnChange									m_OnSocketData;
		};
	}
}