#pragma once
#include <QMainWindow>
#include <memory>
namespace Ui
{
	class ControlDialog;
}
namespace Cry
{
	class NetworkServiceEngine;
	class ControlDialog : public QMainWindow
	{
		Q_OBJECT;
	public:
		explicit ControlDialog(QWidget* Widget = 0);
		~ControlDialog();
	public:
		bool CreateService();
		bool CancelService();
	private:
		void star();
		void stop();
	private:
		Ui::ControlDialog*							Interface;
		std::shared_ptr<NetworkServiceEngine>		m_Service;
	};
}