#include <Global>
#include <DataBase/Cry.Signal.DataBase.h>
#include <DataBase/Cry.Signal.MySQL.hpp>
namespace Cry
{
	DataBase::DataBase() : m_MySQL(std::make_unique<MySQL>())
	{

	}
	DataBase::DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, u32 uPort, const std::string & DataBase, bool ReConnect)
	{
		std::string lpszParameter = "host=" + Host + ";user=" + User + ";password=" + PassWord + ";port=" + std::to_string(uPort) + ";db=" + DataBase + ";auto-reconnect=" + (ReConnect == true ? "true" : " false") + ";protocol=tcp;";
		m_Session = std::make_shared<Session>(Poco::Data::MySQL::Connector::KEY, lpszParameter);
	}
	bool DataBase::Initialize()
	{
		return true;
	}
	void DataBase::DeInitialize()
	{

	}
}