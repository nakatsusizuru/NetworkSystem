#include <Global>
#include <DataBase/Cry.Signal.DataBase.h>
namespace Cry
{
	DataBase::DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u32 uPort, bool ReConnect)
	{
		try
		{
			if (m_Session == nullptr)
			{
				std::string lpszParameter = "host=" + Host + ";user=" + User + ";password=" + PassWord + ";db=" + DB + ";port=" + std::to_string(uPort) + ";auto-reconnect=" + (ReConnect == true ? "true" : "false") + ";compress=true;secure-auth=true;protocol=tcp;character-set=gbk;";
				m_Session.reset(new Session(Poco::Data::MySQL::Connector::KEY, lpszParameter));
			}
			
			//if (w32 Result = m_Session->isConnected(); TRUE == Result)
			//{
			//	std::string name = "123111";
			//	std::string pass = "456";
			//	if (Poco::Data::Statement Statement = (*m_Session << "Select Common_Write(?, ?) As Result", Poco::Data::Keywords::use(name), Poco::Data::Keywords::use(pass), Poco::Data::Keywords::into(Result), Poco::Data::Keywords::now); Statement.done() == true)
			//	{
			//		DebugMsg("·µ»Ø:%d\n", Result);
			//	}
			//}
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