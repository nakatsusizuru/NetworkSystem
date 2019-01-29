#pragma once
/********************************************************************************
** Form generated from reading UI file 'ClientDialogi14768.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTDIALOGI14768_H
#define CLIENTDIALOGI14768_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
	QWidget *centralwidget;
	QVBoxLayout *verticalLayout;
	QTableView *tableView;
	QPushButton *pushButton;

	void setupUi(QMainWindow *ClientDialog)
	{
		if (ClientDialog->objectName().isEmpty())
			ClientDialog->setObjectName(QStringLiteral("ClientDialog"));
		ClientDialog->resize(640, 480);
		ClientDialog->setMinimumSize(QSize(640, 480));
		centralwidget = new QWidget(ClientDialog);
		centralwidget->setObjectName(QStringLiteral("centralwidget"));
		verticalLayout = new QVBoxLayout(centralwidget);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		tableView = new QTableView(centralwidget);
		tableView->setObjectName(QStringLiteral("tableView"));

		verticalLayout->addWidget(tableView);

		pushButton = new QPushButton(centralwidget);
		pushButton->setObjectName(QStringLiteral("pushButton"));

		verticalLayout->addWidget(pushButton);

		ClientDialog->setCentralWidget(centralwidget);

		retranslateUi(ClientDialog);

		QMetaObject::connectSlotsByName(ClientDialog);
	} // setupUi

	void retranslateUi(QMainWindow *ClientDialog)
	{
		ClientDialog->setWindowTitle(QString());
		pushButton->setText(QApplication::translate("ClientDialog", "PushButton", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ClientDialog : public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTDIALOGI14768_H
