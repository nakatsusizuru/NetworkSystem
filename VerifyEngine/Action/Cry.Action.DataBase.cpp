#include <Global>
#include <Action/Cry.Action.DataBase.h>
#include <Action/Cry.Control.Member.h>
#include <Msg.Control.Define.pb.h>
namespace Cry
{
	namespace Action
	{
		DataBase::DataBase()
		{
			this->SetupInterface(Cry::Control::Define::CID_MESSAGE_SIGNIN, std::make_shared<Cry::Control::SignIn>());
		}
		DataBase::~DataBase()
		{

		}
		void DataBase::SetupInterface(const u32 uFlags, const std::shared_ptr<Cry::SocketDataInterface> & Interface)
		{
			if (m_Data.find(uFlags) == std::end(m_Data))
			{
				m_Data.emplace(uFlags, Interface);
			}
		}
		std::shared_ptr<Cry::SocketDataInterface> DataBase::Get(const u32 uFlags)
		{
			if (auto iter = m_Data.find(uFlags); iter != std::end(m_Data))
			{
				return iter->second;
			}
			return std::shared_ptr<Cry::SocketDataInterface>();
		}
		bool DataBase::empty() const
		{
			return m_Data.empty() != true && m_Data.size() != 0;
		}
	}
}