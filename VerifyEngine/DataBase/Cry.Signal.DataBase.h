#pragma once
#include <Action/Cry.Signal.Interface.hpp>
namespace Poco::Data
{
	class Session;
}
namespace Cry
{
	using Session = Poco::Data::Session;
	class MySQL;
	class DataBase
	{
	public:
		DataBase() = default;
		DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DataBase, u32 uPort = 3306, bool ReConnect = true);
		~DataBase() {};
	public:
		virtual bool Initialize();
		virtual void DeInitialize();
	private:
		std::shared_ptr<Session>						m_Session;
	protected:
		std::shared_ptr<MySQL>							m_MySQL;
	};
}