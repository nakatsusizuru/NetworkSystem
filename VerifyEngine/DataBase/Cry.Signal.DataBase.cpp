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
			if (w32 Result = m_Session->isConnected(); TRUE == Result)
			{
				std::string name = "123111";
				std::string pass = "456";
				if (Poco::Data::Statement Statement = (*m_Session << "Select Common_Write(?, ?) As Result", Poco::Data::Keywords::use(name), Poco::Data::Keywords::use(pass), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
				{
					DebugMsg("·µ»Ø:%d\n", Result);
				}
			}
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
			if (m_Session != nullptr)
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