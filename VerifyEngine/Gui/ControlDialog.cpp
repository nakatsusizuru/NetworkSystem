#include <Global>
#include <Gui/ControlDialog.h>
#include <Gui/ControlDialog.hpp>
#include <Service/Cry.Signal.Service.h>
#include <QElapsedTimer>
namespace Cry
{
	ControlDialog::ControlDialog(QWidget* Widget) : QMainWindow(Widget), Interface(new Ui::ControlDialog)
	{
		Interface->setupUi(this);
		connect(Interface->action_star, &QAction::triggered, this, &ControlDialog::star);
		connect(Interface->action_stop, &QAction::triggered, this, &ControlDialog::stop);
	}
	ControlDialog::~ControlDialog()
	{
		this->CancelService();
		delete Interface;
	}
	void ControlDialog::star()
	{
		this->CreateService();
	}
	void ControlDialog::stop()
	{
		this->CancelService();
	}
	bool ControlDialog::CreateService()
	{
		if (m_Service == nullptr)
		{
			if (m_Service = std::make_unique<NetworkServiceEngine>("0.0.0.0:9999", "123", 3); m_Service != nullptr)
			{
				return m_Service->CreateService();
			}
		}

		return false;
	}
	bool ControlDialog::CancelService()
	{
		if (m_Service != nullptr)
		{
			if (m_Service->CancelService())
			{
				m_Service.reset();
				return true;
			}
		}
		return false;
	}
}