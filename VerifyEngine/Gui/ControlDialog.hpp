#pragma once
/********************************************************************************
** Form generated from reading UI file 'ControlDialogjp2112.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CONTROLDIALOGJP2112_H
#define CONTROLDIALOGJP2112_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlDialog
{
public:
	QAction *action_star;
	QAction *action_stop;
	QWidget *centralwidget;
	QVBoxLayout *verticalLayout;
	QTextEdit *LogExport;
	QMenuBar *menubar;
	QMenu *menu_control;
	QStatusBar *statusbar;

	void setupUi(QMainWindow *ControlDialog)
	{
		if (ControlDialog->objectName().isEmpty())
			ControlDialog->setObjectName(QStringLiteral("ControlDialog"));
		ControlDialog->resize(400, 300);
		ControlDialog->setMinimumSize(QSize(400, 300));
		action_star = new QAction(ControlDialog);
		action_star->setObjectName(QStringLiteral("action_star"));
		action_stop = new QAction(ControlDialog);
		action_stop->setObjectName(QStringLiteral("action_stop"));
		centralwidget = new QWidget(ControlDialog);
		centralwidget->setObjectName(QStringLiteral("centralwidget"));
		verticalLayout = new QVBoxLayout(centralwidget);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		verticalLayout->setContentsMargins(2, 2, 2, 0);
		LogExport = new QTextEdit(centralwidget);
		LogExport->setObjectName(QStringLiteral("LogExport"));

		verticalLayout->addWidget(LogExport);

		ControlDialog->setCentralWidget(centralwidget);
		menubar = new QMenuBar(ControlDialog);
		menubar->setObjectName(QStringLiteral("menubar"));
		menubar->setGeometry(QRect(0, 0, 400, 23));
		menu_control = new QMenu(menubar);
		menu_control->setObjectName(QStringLiteral("menu_control"));
		ControlDialog->setMenuBar(menubar);
		statusbar = new QStatusBar(ControlDialog);
		statusbar->setObjectName(QStringLiteral("statusbar"));
		ControlDialog->setStatusBar(statusbar);

		menubar->addAction(menu_control->menuAction());
		menu_control->addAction(action_star);
		menu_control->addAction(action_stop);

		retranslateUi(ControlDialog);

		QMetaObject::connectSlotsByName(ControlDialog);
	} // setupUi

	void retranslateUi(QMainWindow *ControlDialog)
	{
		ControlDialog->setWindowTitle(QApplication::translate("ControlDialog", "Console", Q_NULLPTR));
		action_star->setText(QApplication::translate("ControlDialog", "\345\220\257\345\212\250\346\234\215\345\212\241(&S)", Q_NULLPTR));
		action_stop->setText(QApplication::translate("ControlDialog", "\345\201\234\346\255\242\346\234\215\345\212\241(&T)", Q_NULLPTR));
		menu_control->setTitle(QApplication::translate("ControlDialog", "\346\216\247\345\210\266(&C)", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ControlDialog : public Ui_ControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONTROLDIALOGJP2112_H
