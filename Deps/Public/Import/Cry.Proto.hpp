#pragma once
#include <CoreImport.h>
#include <google/protobuf/stubs/common.h>

namespace Cry
{
	namespace Import
	{
		class InitializeProto
		{
		public:
			InitializeProto() = default;
			~InitializeProto()
			{
				// �������ж�̬����Ķ���
				google::protobuf::ShutdownProtobufLibrary();
			}
		};
	};
};


