#pragma once
#include <Port>
#include <mutex>
#include <QObject>
#include <QString>
class QTextEdit;
namespace Cry
{
	class GuiLog : public QObject
	{
		Q_OBJECT;
	public:
		explicit GuiLog(QTextEdit * TextEdit);
		~GuiLog();
	signals:
		void Notify_Append(const QString & Msg);
	public:
		void OutputMessage(const String * Format, ...);
		void Append(const QString & Msg);
	private:
		QTextEdit*															m_TextEdit;
	private:
		std::mutex															m_Lock;
	};

	extern GuiLog * g_Log;

	#define CryMessage(...)														\
	if (g_Log)																	\
	{																			\
		g_Log->OutputMessage(##__VA_ARGS__);									\
	}
}
