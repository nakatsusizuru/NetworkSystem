#pragma once
#include <QMainWindow>
#include <memory>
#include <Port>
namespace Ui
{
	class ClientDialog;
}
class QStandardItemModel;
namespace Cry
{
	class AvailablePort;
	namespace Signal
	{
		class NetworkServiceEngine;
	}
	class ClientDialog: public QMainWindow
	{
		Q_OBJECT;
	public:
		explicit ClientDialog(QWidget* Widget = 0);
		~ClientDialog();
	private:
		void InitializeUi(QWidget* Widget);
		void OnPushButton(bool Status);
		void PushSignIn(bool Status);
		void PushWrite(bool Status);
		void PushChange(bool Status);
	private:
		void OnConnection(const u32 Index, bool Status);
		bool OnSignInMsg(const u32 uMsg, const std::string & Text, const u32 uid, const u32 expires);
		bool OnRegisterMsg(const u32 uMsg, const std::string & Text, const u32 uid);
		bool OnChangeMsg(const u32 uMsg, const std::string & Text, const u32 uid);
	signals:
		void MultiDelegateConnection(const u32 Index, bool Status);
		bool DelegateSignInMsg(const u32 uMsg, const std::string & Text, const u32 uid, const u32 expires);
		bool DelegateRegisterMsg(const u32 uMsg, const std::string & Text, const u32 uid);
		bool DelegateChangeMsg(const u32 uMsg, const std::string & Text, const u32 uid);
	private:
		Ui::ClientDialog*													Interface;
		QStandardItemModel*													m_QStandardItemModel;
	private:
		std::shared_ptr<Signal::NetworkServiceEngine>						m_Service;
		std::unique_ptr<AvailablePort>										m_AvailablePort;
	};
}