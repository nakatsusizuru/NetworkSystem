#pragma once
#include <google/protobuf/stubs/common.h>
#pragma comment(lib, "libprotobuf.lib")
#pragma comment(lib, "protodata.lib")
namespace Cry
{
	namespace Import
	{
		class Proto
		{
		public:
			Proto() = default;
			~Proto()
			{
				// 回收所有动态分配的对象
				google::protobuf::ShutdownProtobufLibrary();
			}
		};
	};
};


