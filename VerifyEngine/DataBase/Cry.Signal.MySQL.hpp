#pragma once
#include <Poco/Data/StatementImpl.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/Utility.h>
#include <Poco/Data/MySQL/MySQLException.h>
#pragma comment(lib, "mysqlclient.lib")
namespace Cry
{
	class MySQL
	{
	public:
		inline explicit MySQL()
		{
			Poco::Data::MySQL::Connector::registerConnector();
		}
		inline ~MySQL()
		{
			Poco::Data::MySQL::Connector::unregisterConnector();
		}
	};
}