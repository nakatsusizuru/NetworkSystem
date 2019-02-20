#include <Global>
#include <Gui/ClientDialog.h>
#include <Gui/ClientDialog.hpp>
#include <Service/Cry.Signal.Service.h>
#include <Service/Cry.Signal.Port.h>
#include <Action/Cry.Control.Member.h>
#include <QStandardItemModel>
#include <Msg.Control.Member.pb.h>
#include <Msg.Control.Define.pb.h>
namespace Cry
{
	ClientDialog::ClientDialog(QWidget* Widget) : QMainWindow(Widget), Interface(new Ui::ClientDialog), m_Service(std::make_shared<Signal::NetworkServiceEngine>("127.0.0.1:9999", "Client")), m_AvailablePort(std::make_unique<AvailablePort>())
	{
		Interface->setupUi(this);
		this->InitializeUi(this);
	}
	ClientDialog::~ClientDialog()
	{

	}
	void ClientDialog::InitializeUi(QWidget* Widget)
	{
		m_QStandardItemModel = new QStandardItemModel();
		m_QStandardItemModel->setColumnCount(5);
		m_QStandardItemModel->setHeaderData(0, Qt::Horizontal, CryString("客户序号"));
		m_QStandardItemModel->setHeaderData(1, Qt::Horizontal, CryString("客户地址"));
		m_QStandardItemModel->setHeaderData(2, Qt::Horizontal, CryString("连接状态"));
		m_QStandardItemModel->setHeaderData(3, Qt::Horizontal, CryString("心跳状态"));
		m_QStandardItemModel->setHeaderData(4, Qt::Horizontal, CryString("连接开关"));
		
		Interface->tableView->setModel(m_QStandardItemModel);

		/// 只选一行
		Interface->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		/// 必选一行
		Interface->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

		Interface->tableView->setColumnWidth(0, 64);
		Interface->tableView->setColumnWidth(1, 240);
		Interface->tableView->setColumnWidth(2, 64);
		Interface->tableView->setColumnWidth(3, 64);
		Interface->tableView->setColumnWidth(4, 64);
		/// 表头居中
		Interface->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
		/// 拉深显示
		Interface->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Custom);

		Interface->tableView->verticalHeader()->setHidden(true);

		Interface->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

		connect(Interface->pushButton, &QPushButton::clicked, this, &ClientDialog::OnPushButton);
		/// 登录
		connect(Interface->PushSignIn, &QPushButton::clicked, this, &ClientDialog::PushSignIn);
		/// 注册
		connect(Interface->PushWrite, &QPushButton::clicked, this, &ClientDialog::PushWrite);
		/// 修改
		connect(Interface->PushChange, &QPushButton::clicked, this, &ClientDialog::PushChange);
		/// 连接跨线程信号
		connect(this, &ClientDialog::MultiDelegateConnection, this, &ClientDialog::OnConnection);
		/// 假委托执行函数
		m_Service->SetConnection(std::bind(&ClientDialog::MultiDelegateConnection, this, std::placeholders::_1, std::placeholders::_2));

		m_Service->CreateService();

		connect(this, &ClientDialog::DelegateRegisterMsg, this, &ClientDialog::OnRegisterMsg, Qt::BlockingQueuedConnection);
		connect(this, &ClientDialog::DelegateSignInMsg, this, &ClientDialog::OnSignInMsg, Qt::BlockingQueuedConnection);
		connect(this, &ClientDialog::DelegateChangeMsg, this, &ClientDialog::OnChangeMsg, Qt::BlockingQueuedConnection);
		


		m_Service->SetupInterface(Cry::Control::Define::CID_MESSAGE_REGISTER, std::make_shared<Cry::Control::Register>(std::bind(&ClientDialog::DelegateRegisterMsg, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
		m_Service->SetupInterface(Cry::Control::Define::CID_MESSAGE_SIGNIN, std::make_shared<Cry::Control::SignIn>(std::bind(&ClientDialog::DelegateSignInMsg, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
		m_Service->SetupInterface(Cry::Control::Define::CID_MESSAGE_CHANGE, std::make_shared<Cry::Control::Change>(std::bind(&ClientDialog::DelegateChangeMsg, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
		
	}

	void ClientDialog::OnConnection(const u32 Index, bool Status)
	{
		m_QStandardItemModel->setData(m_QStandardItemModel->index(Index, 2), Status ? CryString("连接成功") : CryString("断开连接"));
	}

	bool ClientDialog::OnSignInMsg(const u32 uMsg, const std::string & Text, const u32 uid, const u32 expires)
	{
		DebugMsg("消息：%d 提示：%s uid:%d 到期时间：%d\n", uMsg, Text.c_str(), uid, expires);
		return true;
	}

	bool ClientDialog::OnRegisterMsg(const u32 uMsg, const std::string & Text, const u32 uid)
	{
		DebugMsg("消息：%d 提示：%s uid:%d\n", uMsg, Text.c_str(), uid);
		return true;
	}

	bool ClientDialog::OnChangeMsg(const u32 uMsg, const std::string & Text, const u32 uid)
	{
		DebugMsg("消息：%d 提示：%s uid:%d\n", uMsg, Text.c_str(), uid);
		return true;
	}

	void ClientDialog::OnPushButton(bool Status)
	{
		//for (u32 i = 0; i < 100; ++i)
		//{
		//	if (u32 uPort = m_AvailablePort->GetAvailableTcpPort(); uPort != 0)
		//	{
		//		if (std::string lpszAddress = m_AvailablePort->GetAvailableAddress("127.0.0.1", uPort); false != m_Service->CreateService(lpszAddress, uPort))
		//		{
		//			u32 Row = m_QStandardItemModel->rowCount();
		//			m_QStandardItemModel->setItem(Row, 0, new QStandardItem(QString("%1").arg(Row)));
		//			m_QStandardItemModel->setItem(Row, 1, new QStandardItem(QString(lpszAddress.c_str())));
		//			m_QStandardItemModel->setItem(Row, 2, new QStandardItem(CryString("等待连接")));
		//			m_QStandardItemModel->item(Row, 0)->setTextAlignment(Qt::AlignCenter);
		//			m_QStandardItemModel->item(Row, 1)->setTextAlignment(Qt::AlignCenter);
		//			m_QStandardItemModel->item(Row, 2)->setTextAlignment(Qt::AlignCenter);
		//		}
		//	}
		//}
	}

	void ClientDialog::PushSignIn(bool Status)
	{
		Cry::Control::Member::MsgSignInRequest ProtoRequest;
		ProtoRequest.set_username(Interface->User->text().toLocal8Bit());
		ProtoRequest.set_password(Interface->Pass->text().toLocal8Bit());
		ProtoRequest.set_version(VERSION_CHECK(1, 0, 0));
		m_Service->Send(Cry::Control::Define::CID_MESSAGE_SIGNIN, ProtoRequest);
	}
	void ClientDialog::PushWrite(bool Status)
	{
		Cry::Control::Member::MsgRegisterRequest ProtoRequest;
		ProtoRequest.set_username(Interface->User->text().toLocal8Bit());
		ProtoRequest.set_password(Interface->Pass->text().toLocal8Bit());
		ProtoRequest.set_email("540163@qq.com");
		ProtoRequest.set_phone("18304489877");
		ProtoRequest.set_pin(521815);
		m_Service->Send(Cry::Control::Define::CID_MESSAGE_REGISTER, ProtoRequest);
	}
	void ClientDialog::PushChange(bool Status)
	{
		Cry::Control::Member::MsgChangeRequest ProtoRequest;
		ProtoRequest.set_username(Interface->Change_User->text().toLocal8Bit());
		ProtoRequest.set_password(Interface->Change_oPass->text().toLocal8Bit());
		ProtoRequest.set_pin(Interface->Change_pPass->text().toUInt());
		ProtoRequest.set_newspass(Interface->Change_nPass->text().toLocal8Bit());
		m_Service->Send(Cry::Control::Define::CID_MESSAGE_CHANGE, ProtoRequest);
	}
}