#include <Global>
#include <Gui/ClientDialog.h>
#include <Gui/ClientDialog.hpp>
#include <Service/Cry.Signal.Service.h>
#include <QStandardItemModel>
namespace Cry
{
	ClientDialog::ClientDialog(QWidget* Widget) : QMainWindow(Widget), Interface(new Ui::ClientDialog), m_Service(std::make_shared<NetworkServiceEngine>("127.0.0.1:9999", "Client"))
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
		m_QStandardItemModel->setHeaderData(0, Qt::Horizontal, CryString("�ͻ����"));
		m_QStandardItemModel->setHeaderData(1, Qt::Horizontal, CryString("�ͻ���ַ"));
		m_QStandardItemModel->setHeaderData(2, Qt::Horizontal, CryString("����״̬"));
		m_QStandardItemModel->setHeaderData(3, Qt::Horizontal, CryString("����״̬"));
		m_QStandardItemModel->setHeaderData(4, Qt::Horizontal, CryString("���ӿ���"));
		
		Interface->tableView->setModel(m_QStandardItemModel);

		/// ֻѡһ��
		Interface->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		/// ��ѡһ��
		Interface->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

		Interface->tableView->setColumnWidth(0, 64);
		Interface->tableView->setColumnWidth(1, 240);
		Interface->tableView->setColumnWidth(2, 64);
		Interface->tableView->setColumnWidth(3, 64);
		Interface->tableView->setColumnWidth(4, 64);
		/// ��ͷ����
		Interface->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
		/// ������ʾ
		Interface->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Custom);
		Interface->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Custom);

		connect(Interface->pushButton, &QPushButton::clicked, this, &ClientDialog::OnPushButton);

	}
	void ClientDialog::OnPushButton(bool Status)
	{
		m_Service->CreateService();
	}
}