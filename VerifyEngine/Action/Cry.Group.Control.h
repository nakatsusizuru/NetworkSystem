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
			virtual void OnSocketData(const std::shared_ptr<Cry::Work> & Work, const u32 uMsg, const PVOID Data, const u32 uSize) override;
		private:
			
		};
	}
}