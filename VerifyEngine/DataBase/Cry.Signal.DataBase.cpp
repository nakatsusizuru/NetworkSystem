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
					if (bool Result = Session->isConnected(); true == Result)
					{
						std::string name("123");
						std::string pass("123");
						if (Poco::Data::Statement Statement = (*Session << "SELECT Common_Signin(?, ?) AS Result", Poco::Data::Keywords::use(name), Poco::Data::Keywords::use(pass), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
						{
							DebugMsg("²éÕÒ½á¹û£º%d\n", Result);
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