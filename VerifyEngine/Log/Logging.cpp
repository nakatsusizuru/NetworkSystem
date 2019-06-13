#include <Global>
#include <Log/Logging.h>
#include <QTextEdit>
namespace Cry
{
	extern GuiLog * g_Log = nullptr;

	GuiLog::GuiLog(QTextEdit * TextEdit) : m_TextEdit(TextEdit)
	{
		QObject::connect(this, &GuiLog::Notify_Append, this, &GuiLog::Append);
	}

	GuiLog::~GuiLog()
	{
		m_TextEdit->clear();
	}

	void GuiLog::OutputMessage(const String * Format, ...)
	{
		String Buffer[MAX_PATH];
		va_list ap;
		va_start(ap, Format);
		emit this->Notify_Append(QString::fromLocal8Bit(Buffer, vsnprintf(Buffer, sizeof(Buffer), Format, ap)));
		va_end(ap);
	}

	void GuiLog::Append(const QString & Msg)
	{
		if (m_TextEdit)
		{
			std::lock_guard<std::mutex> Guard(m_Lock);
			{
				m_TextEdit->append(Msg);
			}
		}
	}
}