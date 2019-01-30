#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <Import/Cry.Event.hpp>
#include <Import/Cry.Glog.hpp>
#include <QtPlugin>
#include <QApplication>
#include <QMetaType>
#include <Gui/ClientDialog.h>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
w32 Exec(w32 argc, lPString argv[])
{
	QApplication a(argc, argv);
	Cry::ClientDialog w;
	qRegisterMetaType<u32>("u32");
	w.show();
	return a.exec();
}

int main(int argc, char* argv[])
{
	Cry::Import::Glog InitGlog;
	{
		Cry::Import::Event InitEvent;
		{
			return Exec(argc, argv);
		}
	}
}