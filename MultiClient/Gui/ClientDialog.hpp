/********************************************************************************
** Form generated from reading UI file 'ClientDialogC10356.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTDIALOGC10356_H
#define CLIENTDIALOGC10356_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
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
	QHBoxLayout *horizontalLayout;
	QPushButton *pushButton;
	QPushButton *PushSignIn;

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

		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		pushButton = new QPushButton(centralwidget);
		pushButton->setObjectName(QStringLiteral("pushButton"));

		horizontalLayout->addWidget(pushButton);

		PushSignIn = new QPushButton(centralwidget);
		PushSignIn->setObjectName(QStringLiteral("PushSignIn"));

		horizontalLayout->addWidget(PushSignIn);


		verticalLayout->addLayout(horizontalLayout);

		ClientDialog->setCentralWidget(centralwidget);

		retranslateUi(ClientDialog);

		QMetaObject::connectSlotsByName(ClientDialog);
	} // setupUi

	void retranslateUi(QMainWindow *ClientDialog)
	{
		ClientDialog->setWindowTitle(QString());
		pushButton->setText(QApplication::translate("ClientDialog", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
		PushSignIn->setText(QApplication::translate("ClientDialog", "\347\231\273\345\275\225\350\264\246\345\217\267", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ClientDialog : public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTDIALOGC10356_H
