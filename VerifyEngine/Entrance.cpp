#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <Import/Cry.Event.hpp>
#include <Import/Cry.Glog.hpp>
#include <QtPlugin>
#include <QApplication>
#include <Gui/ControlDialog.h>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
w32 WinPort::Exec(w32 argc, lPString argv[])
{
	QApplication a(argc, argv);
	Cry::ControlDialog w;
	w.show();
	return a.exec();
}
int main(int argc, char* argv[])
{
	Cry::Import::Glog InitGlog;
	{
		Cry::Import::Event InitEvent;
		{
			return WinPort::Exec(argc, argv);
		}
	}
}