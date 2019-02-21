#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
namespace Poco
{
	namespace Data
	{
		class Session;
	}
}
namespace Cry
{
	class Driver;
	namespace Control
	{
		/// ע���˺�
		class Register : public SocketDataInterface
		{
		public:
			explicit Register();
			virtual ~Register() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, std::string & Email, std::string & Phone, u32 Pin);
		};

		/// ��¼�˺�
		class SignIn : public SocketDataInterface
		{
		public:
			explicit SignIn();
			virtual ~SignIn() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, u32 Code, u32 Version);
			bool CheckOnline(const std::shared_ptr<Cry::Signal::Work> & Work, const std::shared_ptr<Poco::Data::Session> & Session, const w32 Result, std::string & User, std::string & Pass);
		protected:
			u32 GetExpires(const std::shared_ptr<Poco::Data::Session> & Session, u32 uid, u32 Expires = 0);
		};

		/// �޸�����
		class ChangePass : public SocketDataInterface
		{
		public:
			explicit ChangePass();
			virtual ~ChangePass() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, std::string & NewsPass, u32 Pin);
		};

		/// ������
		class ChangeBind : public SocketDataInterface
		{
		public:
			explicit ChangeBind();
			virtual ~ChangeBind() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * cbData, const u32 uSize) override;
		private:
			bool OnMessage(const std::shared_ptr<Cry::Signal::Work> & Work, std::string & User, std::string & Pass, u32 Secret, u32 Expire);
		};
	}
}