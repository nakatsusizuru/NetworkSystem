#pragma once
#include <evpp/logging.h>
#include <Poco/Data/StatementImpl.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/Utility.h>
#include <Poco/Data/MySQL/MySQLException.h>
#pragma comment(lib, "mysqlclient.lib")
namespace Cry
{
	namespace Import
	{
		class MySQL
		{
		public:
			MySQL()
			{
				try
				{
					Poco::Data::MySQL::Connector::registerConnector();
				}
				catch (const Poco::Exception & ex)
				{
					LOG_ERROR << ex.displayText();
				}
				
			}
			~MySQL()
			{
				Poco::Data::MySQL::Connector::unregisterConnector();
			}
		};
	}
}