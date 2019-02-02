#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <atomic>
namespace Cry
{
	class DataBase;
	class DataPool
	{
	public:
		DataPool() = default;
		DataPool(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u64 uSize = 0, u32 uPort = 3306, bool ReConnect = true);
		~DataPool() {};
	public:
		std::shared_ptr<DataBase> GetNextMySQL();
		std::shared_ptr<DataBase> GetNextMySQL(u64 Index);
	private:
		std::shared_ptr<DataBase>										m_DataBase;	/// Ĭ������
		std::unordered_map<u64, std::shared_ptr<DataBase>>				m_DataPool; /// ��������
		std::atomic<u64>												uNext;		/// ���ô���
	};
}