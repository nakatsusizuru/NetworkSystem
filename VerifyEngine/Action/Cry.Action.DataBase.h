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
			void SetupInterface(const u32 uMsg, const std::shared_ptr<Cry::SocketDataInterface> & f);
			std::shared_ptr<Cry::SocketDataInterface> Get(const u32 uMsg);
			bool empty() const;
		private:
			std::unordered_map<u32, std::shared_ptr<Cry::SocketDataInterface>>			m_Data;
		};
	}
}