#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <Import/Cry.Glog.hpp>
#include <Import/Cry.Proto.hpp>
#include <Import/Cry.Event.hpp>
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
		Cry::Import::Proto InitProto; 
		{
			Cry::Import::Event InitEvent;
			{
				return WinPort::Exec(argc, argv);
			}
		}
	}
}