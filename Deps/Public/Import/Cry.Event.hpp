#pragma once
#include <Winsock2.h>
namespace Cry
{
	namespace Import
	{
		class Event
		{
		public:
			Event()
			{
				WSADATA WSAData;
				WSAStartup(MAKEWORD(2, 2), &WSAData);
			}
			~Event()
			{
				WSACleanup();
			}
		};
	}
}