#include <Global>
#include <DataBase/Cry.Signal.DataBasePool.h>
#include <DataBase/Cry.Signal.DataBase.h>
namespace Cry
{
	DataPool::DataPool(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u64 uSize, u32 uPort, bool ReConnect) : m_DataBase(std::make_shared<DataBase>(Host, User, PassWord, DB, uPort, ReConnect)), uNext(0)
	{
		for (u64 i = 0; i < uSize; ++i)
		{
			m_DataPool.emplace(i, std::make_shared<DataBase>(Host, User, PassWord, DB, uPort, ReConnect));
		}
	}

	std::shared_ptr<DataBase> DataPool::GetNextMySQL()
	{
		return this->GetNextMySQL(uNext.fetch_add(1));
	}

	std::shared_ptr<DataBase> DataPool::GetNextMySQL(u64 Index)
	{
		if (false == m_DataPool.empty())
		{
			return m_DataPool[Index % m_DataPool.size()];
		}
		return m_DataBase;
	}
}