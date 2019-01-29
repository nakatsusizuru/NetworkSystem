#pragma once
#include <QMainWindow>
#include <memory>
namespace Ui
{
	class ClientDialog;
}
class QStandardItemModel;
namespace Cry
{
	class NetworkServiceEngine;
	class ClientDialog: public QMainWindow
	{
		Q_OBJECT;
	public:
		explicit ClientDialog(QWidget* Widget = 0);
		~ClientDialog();
	private:
		void InitializeUi(QWidget* Widget);
		void OnPushButton(bool Status);
	private:
		Ui::ClientDialog*							Interface;
		QStandardItemModel*							m_QStandardItemModel;
	private:
		std::shared_ptr<NetworkServiceEngine>		m_Service;
	};
}