#include <Global>
#include <Service/Cry.Signal.Port.h>
#include <algorithm>
#include <WinSock2.h>
#include <iphlpapi.h>
#pragma comment(lib, "iphlpapi.lib")
namespace Cry
{
	u32 AvailablePort::GetAvailableTcpPort()
	{
		if (ulong uSize = 0; GetTcpTable(NULL, &uSize, TRUE) == ERROR_INSUFFICIENT_BUFFER)
		{
			std::unique_ptr<char> buffer(new char[uSize]);
			{
				PMIB_TCPTABLE TcpTable = reinterpret_cast<PMIB_TCPTABLE>(buffer.get());
				if (GetTcpTable(TcpTable, &uSize, FALSE) == NO_ERROR)
				{
					for (u32 i = 0; i < TcpTable->dwNumEntries; ++i)
					{
						m_Port.emplace(std::cend(m_Port), ntohs(TcpTable->table[i].dwLocalPort));
					}
					//std::sort(std::begin(m_Port), std::end(m_Port));
					for (u32 uPort = 1025; uPort != 65535; ++uPort)
					{
						if (!std::binary_search(std::cbegin(m_Port), std::cend(m_Port), uPort) && !std::binary_search(std::cbegin(m_Active), std::cend(m_Active), uPort))
						{
							return *m_Active.emplace(std::cend(m_Active), uPort);
						}
					}
				}
			}
		}
		return 0U;
	}
	std::string AvailablePort::GetAvailableAddress(const std::string & lpszString, const u32 uPort)
	{
		return lpszString + ":" + std::to_string(uPort);
	}
}
