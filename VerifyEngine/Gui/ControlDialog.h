#pragma once
#include <QMainWindow>
namespace Ui
{
	class ControlDialog;
}
namespace Cry
{
	class ControlDialog : public QMainWindow
	{
		Q_OBJECT;
	public:
		explicit ControlDialog(QWidget* Widget = 0);
		~ControlDialog();
	private:
		Ui::ControlDialog*							Interface;
	};
}