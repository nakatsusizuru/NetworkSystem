#include <Global>
#include <DataBase/Cry.Signal.DataBase.h>
#include <DataBase/Cry.Signal.MySQL.hpp>
#include <evpp/logging.h>
namespace Cry
{
	DataBase::DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DataBase, u32 uPort, bool ReConnect) : m_MySQL(std::make_shared<MySQL>())
	{
		try
		{
			std::string lpszParameter = "host=" + Host + ";user=" + User + ";password=" + PassWord + ";db=" + DataBase + ";port=" + std::to_string(uPort) + ";auto-reconnect=" + (ReConnect == true ? "true" : " false") + ";protocol=tcp;";
			m_Session = std::make_shared<Session>(Poco::Data::MySQL::Connector::KEY, lpszParameter);
		}
		catch (const Poco::Exception & ex)
		{
			LOG_ERROR << ex.displayText();
			m_Session->close();
		}
		// F:\My Source Program\MySQL\vio\viosocket.c
	}
	bool DataBase::Initialize()
	{
		return true;
	}
	void DataBase::DeInitialize()
	{

	}
}