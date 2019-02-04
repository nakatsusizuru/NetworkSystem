#include <Global>
#include <Action/Cry.Action.DataBase.h>
#include <Action/Cry.Control.Member.h>
namespace Cry
{
	class SocketDataInterface;

	namespace Action
	{
		DataBase::DataBase()
		{
			this->SetupInterface(1, std::make_shared<Cry::Control::SignIn>());
			this->SetupInterface(2, std::make_shared<Cry::Control::SignIn>());
		}
		DataBase::~DataBase()
		{

		}
		void DataBase::SetupInterface(const u32 uFlags, const std::shared_ptr<Cry::SocketDataInterface> & Interface)
		{
			m_Data.emplace(uFlags, Interface);
		}
		std::shared_ptr<Cry::SocketDataInterface> DataBase::Get(const u32 uFlags)
		{
			if (auto iter = m_Data.find(uFlags); iter != std::end(m_Data))
			{
				return iter->second;
			}
			return std::shared_ptr<Cry::SocketDataInterface>();
		}
		bool DataBase::Empty() const
		{
			return m_Data.empty() != true && m_Data.size() != 0;
		}
	}
}