#pragma once
#include <Action/Cry.Signal.Interface.hpp>
namespace Cry
{
	namespace Group
	{
		class Center : public SocketDataInterface
		{
		public:
			explicit Center();
			~Center() = default;
		private:
			virtual bool OnSocketData(const std::shared_ptr<Cry::Signal::Work> & Work, const u32 uMsg, const void * Data, const u32 uSize) override;
		private:
			
		};
	}
}