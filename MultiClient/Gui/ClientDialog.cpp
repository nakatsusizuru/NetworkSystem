#include <Global>
#include <Gui/ClientDialog.h>
#include <Gui/ClientDialog.hpp>
#include <Service/Cry.Signal.Service.h>
#include <Service/Cry.Signal.Port.h>
#include <QStandardItemModel>
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
		/// 连接跨线程信号
		connect(this, &ClientDialog::MultiDelegateConnection, this, &ClientDialog::OnConnection);
		/// 假委托执行函数
		m_Service->SetConnection(std::bind(&ClientDialog::MultiDelegateConnection, this, std::placeholders::_1, std::placeholders::_2));
	}
	void ClientDialog::OnConnection(const u32 Index, bool Status)
	{
		m_QStandardItemModel->setData(m_QStandardItemModel->index(Index, 2), Status ? CryString("连接成功") : CryString("断开连接"));
	}
	void ClientDialog::OnPushButton(bool Status)
	{
		for (u32 i = 0; i < 100; ++i)
		{
			if (u32 uPort = m_AvailablePort->GetAvailableTcpPort(); uPort != 0)
			{
				if (std::string lpszAddress = m_AvailablePort->GetAvailableAddress("127.0.0.1", uPort); false != m_Service->CreateService(lpszAddress, uPort))
				{
					u32 Row = m_QStandardItemModel->rowCount();
					m_QStandardItemModel->setItem(Row, 0, new QStandardItem(QString("%1").arg(Row)));
					m_QStandardItemModel->setItem(Row, 1, new QStandardItem(QString(lpszAddress.c_str())));
					m_QStandardItemModel->setItem(Row, 2, new QStandardItem(CryString("等待连接")));
					m_QStandardItemModel->item(Row, 0)->setTextAlignment(Qt::AlignCenter);
					m_QStandardItemModel->item(Row, 1)->setTextAlignment(Qt::AlignCenter);
					m_QStandardItemModel->item(Row, 2)->setTextAlignment(Qt::AlignCenter);
				}
			}
		}
	}
}