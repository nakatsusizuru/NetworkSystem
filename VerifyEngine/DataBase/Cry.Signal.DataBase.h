#pragma once
#include <Action/Cry.Signal.Interface.hpp>
namespace Cry
{
	class DataBase : public DataBaseInterface
	{
	public:
		explicit DataBase();
		~DataBase() = default;
	public:
		virtual bool Initialize() override;
		virtual void DeInitialize() override;
	private:
		 
	};
}