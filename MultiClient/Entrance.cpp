#include <Global>
#include <Entrance.h>
#include <Cry.Import.h>
#include <Import/Cry.Event.hpp>
#include <Import/Cry.Glog.hpp>
#include <QtPlugin>
#include <QApplication>
#include <Gui/ClientDialog.h>
w32 Exec(w32 argc, lPString argv[])
{
	constexpr Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
	QApplication a(argc, argv);
	Cry::ClientDialog w;
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