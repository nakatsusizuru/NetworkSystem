#include <Global>
#include <Gui/ControlDialog.h>
#include <Gui/ControlDialog.hpp>
#include <Service/Cry.Signal.Service.h>
#include <Log/Logging.h>
#include <QElapsedTimer>
namespace Cry
{
	ControlDialog::ControlDialog(QWidget* Widget) : QMainWindow(Widget), m_Interface(new Ui::ControlDialog)
	{
		m_Interface->setupUi(this);
		g_Log = new GuiLog(m_Interface->LogExport);
		QObject::connect(m_Interface->action_star, &QAction::triggered, this, &ControlDialog::star);
		QObject::connect(m_Interface->action_stop, &QAction::triggered, this, &ControlDialog::stop);
	}
	ControlDialog::~ControlDialog()
	{
		this->CancelService();
		delete m_Interface;
		delete g_Log;
	}
	void ControlDialog::star()
	{
		if (this->CreateService())
		{
			CryMessage("服务器启动成功");
		}
	}
	void ControlDialog::stop()
	{
		this->CancelService();
	}
	bool ControlDialog::CreateService()
	{
		if (!m_Service)
		{
			if (m_Service = std::make_unique<Cry::Signal::NetworkServiceEngine>("0.0.0.0:9999", "123", 3); m_Service)
			{
				return m_Service->CreateService();
			}
		}
		return false;
	}
	bool ControlDialog::CancelService()
	{
		if (m_Service)
		{
			if (m_Service->CancelService())
			{
				m_Service.reset();
				CryMessage("服务器停止成功");
				return true;
			}
		}
		return false;
	}
}