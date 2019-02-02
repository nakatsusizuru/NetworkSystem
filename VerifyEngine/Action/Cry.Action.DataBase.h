#pragma once
#include <memory>
#include <unordered_map>
namespace Cry
{
	class SocketDataInterface;

	namespace Group
	{
		class Center;
	}

	namespace Action
	{
		class DataBase
		{
		public:
			explicit DataBase();
			virtual ~DataBase();
		public:
			void SetupInterface(const u32 uFlags, const std::shared_ptr<Cry::SocketDataInterface> & Interface);
			std::shared_ptr<Cry::SocketDataInterface> Get(const u32 uFlags);
		private:
			std::unordered_map<u32, std::shared_ptr<Cry::SocketDataInterface>>			m_Data;
		};
	}
}