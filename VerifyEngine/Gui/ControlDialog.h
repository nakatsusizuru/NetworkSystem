#pragma once
#include <QMainWindow>
#include <memory>
#include <thread>
namespace Ui
{
	class ControlDialog;
}
namespace Cry
{
	namespace Signal
	{
		class NetworkServiceEngine;
	}

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
		Ui::ControlDialog*										m_Interface;
		std::shared_ptr<std::thread>							m_Thread;
		std::unique_ptr<Cry::Signal::NetworkServiceEngine>		m_Service;
	};
}