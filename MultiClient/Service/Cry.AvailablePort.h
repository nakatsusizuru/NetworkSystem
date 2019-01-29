#pragma once
#include <vector>
#include <string>
namespace Cry
{
	class AvailablePort
	{
	public:
		explicit AvailablePort() = default;
		~AvailablePort() = default;
	public:
		u32 GetAvailableTcpPort();
		std::string GetAvailableAddress(const std::string & Address);
	private:
		std::vector<u32>				m_PortTable;
	};
}