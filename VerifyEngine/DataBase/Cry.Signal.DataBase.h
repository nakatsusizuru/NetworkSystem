#pragma once
#include <Action/Cry.Signal.Interface.hpp>
namespace Poco::Data
{
	class Session;
}
namespace Cry
{
	using Session = Poco::Data::Session;
	class MySQL;
	class DataBase : public DataBaseInterface
	{
	public:
		explicit DataBase();
		explicit DataBase(const std::string & Host, const std::string & User, const std::string & PassWord, u32 uPort, const std::string & DataBase, bool ReConnect);
		~DataBase() = default;
	public:
		virtual bool Initialize() override;
		virtual void DeInitialize() override;
	private:
		std::shared_ptr<Session>						m_Session;
	protected:
		std::unique_ptr<MySQL>							m_MySQL;
	};
}