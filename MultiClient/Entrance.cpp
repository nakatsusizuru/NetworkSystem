#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <Import/Cry.Event.hpp>
#include <Import/Cry.Glog.hpp>
#include <QtPlugin>
#include <QApplication>

int main(int argc, char* argv[])
{
	Cry::Import::Glog InitGlog;
	{
		Cry::Import::Event InitEvent;
		{
			return 0;
		}
	}
}