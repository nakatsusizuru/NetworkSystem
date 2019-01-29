#include <Global>
#include <Service/Cry.AvailablePort.h>
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
						m_PortTable.push_back(ntohs(TcpTable->table[i].dwLocalPort));
					}
					//std::sort(std::begin(m_PortTable), std::end(m_PortTable));
					for (u32 uPort = 1000; uPort != 65535; ++uPort)
					{
						if (!std::binary_search(std::cbegin(m_PortTable), std::cend(m_PortTable), uPort))
						{
							return uPort;
						}
					}
				}
			}
		}
		return 0U;
	}
	std::string AvailablePort::GetAvailableAddress(const std::string & Address)
	{
		return Address + ":" + std::to_string(this->GetAvailableTcpPort());
	}
}
