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

			try
			{
				if (std::shared_ptr<Poco::Data::Session> & Session = m_Session; Session != nullptr)
				{
					if (w32 Result = Session->isConnected(); TRUE == Result)
					{
						std::string name("1231");
						std::string pass("123");
						if (Poco::Data::Statement Statement = (*Session << "Select Common_Signin(?, ?) As Result", Poco::Data::Keywords::use(name), Poco::Data::Keywords::use(pass), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							switch (Result)
							{
							case 0U: DebugMsg("ÑéÖ¤Í¨¹ý\n"); break;
							case -1: DebugMsg("ÕËºÅÎª¿Õ\n"); break;
							case -2: DebugMsg("ÃÜÂëÎª¿Õ\n"); break;
							case -3: DebugMsg("ÕËºÅ´íÎó\n"); break;
							case -4: DebugMsg("ÃÜÂë´íÎó\n"); break;
							default: DebugMsg("Ê²Ã´´íÎó\n"); break;
							}
						}
					}
				}
			}
			catch (const Poco::Exception & ex)
			{
				LOG_ERROR << ex.displayText();
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