#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <atomic>
namespace Cry
{
	class DataBase;
	class DataBasePool
	{
	public:
		DataBasePool() = default;
		DataBasePool(const std::string & Host, const std::string & User, const std::string & PassWord, const std::string & DB, u64 uSize = 0, u32 uPort = 3306, bool ReConnect = true);
		~DataBasePool() {};
	public:
		std::shared_ptr<DataBase> GetNextMySQL();
		u64 Count() const;
	private:
		std::shared_ptr<DataBase>										m_DataBase;	/// Ĭ������
		std::unordered_map<u64, std::shared_ptr<DataBase>>				m_DataPool; /// ��������
		std::atomic<u64>												uNext;		/// ���ô���
	};
}