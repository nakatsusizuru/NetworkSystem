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
				// �������ж�̬����Ķ���
				google::protobuf::ShutdownProtobufLibrary();
			}
		};
	};
};


