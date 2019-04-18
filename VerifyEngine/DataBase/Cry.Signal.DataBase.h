#pragma once
#include <Interface/Cry.Signal.Interface.hpp>
#include <DataBase/Cry.Signal.MySQL.hpp>
namespace Poco::Data
{
	class Session;
}
namespace Cry
{
	class DataBase
	{
	public:
		using Session = Poco::Data::Session;
	public:
		explicit DataBase() = default;
		explicit DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & Db, u32 uPort = 3306, bool ReConnect = true);
		virtual ~DataBase();
	public:
		const std::shared_ptr<Session> & GetSession() const { return m_Session; }
	private:
		void Close();
	private:
		std::shared_ptr<Session>						m_Session;
	};
}