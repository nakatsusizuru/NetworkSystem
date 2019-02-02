#include <Global>
#include <DataBase/Cry.Signal.DataBase.h>
namespace Cry
{
	DataBase::DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u32 uPort, bool ReConnect)
	{
		try
		{
			std::string lpszParameter = "host=" + Host + ";user=" + User + ";password=" + PassWord + ";db=" + DB + ";port=" + std::to_string(uPort) + ";auto-reconnect=" + (ReConnect == true ? "true" : " false") + ";protocol=tcp;";
			m_Session = std::make_shared<Session>(Poco::Data::MySQL::Connector::KEY, lpszParameter);
		}
		catch (const Poco::Exception & ex)
		{
			LOG_ERROR << ex.displayText();
			m_Session->close();
		}
	}
	DataBase::~DataBase()
	{
		m_Session->close();
	}
	bool DataBase::Initialize()
	{
		return true;
	}
	void DataBase::DeInitialize()
	{

	}
}