#include <Gui/ControlDialog.h>
#include <Gui/ControlDialog.hpp>
namespace Cry
{
	ControlDialog::ControlDialog(QWidget* Widget) : QMainWindow(Widget), Interface( new Ui::ControlDialog )
	{
		Interface->setupUi(this);
	}
	ControlDialog::~ControlDialog()
	{
		delete Interface;
	}
}