#include <Global>
#include <DataBase/Cry.Signal.DataBase.h>
namespace Cry
{
	DataBase::DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u32 uPort, bool ReConnect)
	{
		try
		{
			std::string lpszParameter = "host=" + Host + ";user=" + User + ";password=" + PassWord + ";db=" + DB + ";port=" + std::to_string(uPort) + ";auto-reconnect=" + (ReConnect == true ? "true" : "false") + ";protocol=tcp;";
			m_Session = std::make_shared<Session>(Poco::Data::MySQL::Connector::KEY, lpszParameter, 3U);
		}
		catch (const Poco::Exception & ex)
		{
			LOG_ERROR << ex.displayText();
		}
	}
	DataBase::~DataBase()
	{
		this->Close();
	}
	void DataBase::Close()
	{
		try
		{
			if (m_Session)
			{
				m_Session->close();
			}
		}
		catch (const Poco::Exception & ex)
		{
			LOG_ERROR << ex.displayText();
		}
	}
}