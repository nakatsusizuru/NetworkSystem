#include <Global>
#include <DataBase/Cry.Signal.DataBasePool.h>
#include <DataBase/Cry.Signal.DataBase.h>
#include <Log/Logging.h>
namespace Cry
{
	DataPool::DataPool(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u64 uSize, u32 uPort, bool ReConnect) : m_DataBase(std::make_shared<DataBase>(Host, User, PassWord, DB, uPort, ReConnect)), uNext(0)
	{
		for (u64 i = 0; i < uSize; ++i)
		{
			m_DataPool.emplace(i, std::make_shared<DataBase>(Host, User, PassWord, DB, uPort, ReConnect));
		}
		this->CheckSession();
	}

	std::shared_ptr<DataBase> DataPool::GetNextMySQL()
	{
		return this->GetNextMySQL(uNext.fetch_add(1));
	}

	std::shared_ptr<DataBase> DataPool::GetNextMySQL(u64 Index)
	{
		std::lock_guard<std::mutex> Guard(m_Mutex);
		{
			if (false == m_DataPool.empty())
			{
				return m_DataPool[Index % m_DataPool.size()];
			}
		}
		return m_DataBase;
	}
	void DataPool::CheckSession()
	{
		for (u32 i = 0; i < m_DataPool.size(); ++i)
		{
			if (!m_DataPool[i]->GetSession())
			{
				CryMessage("数据库[%d]连接失败", i);
			}
		}
	}
}