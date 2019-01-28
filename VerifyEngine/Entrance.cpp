#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <QtPlugin>
#include <QApplication>
#include <Gui/ControlDialog.h>
w32 WinPort::Exec(w32 argc, lPString argv[])
{
	Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
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