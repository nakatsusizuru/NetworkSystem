#pragma once
#include <Import/Cry.Event.hpp>
#include <Import/Cry.Glog.hpp>
class WinPort : public Cry::Import::Glog, public Cry::Import::Event
{
public:
	static w32 Exec(w32 argc, lPString argv[]);
};