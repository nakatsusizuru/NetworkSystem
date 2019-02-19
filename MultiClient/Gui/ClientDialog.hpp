/********************************************************************************
** Form generated from reading UI file 'ClientDialogO14720.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTDIALOGO14720_H
#define CLIENTDIALOGO14720_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
	QHBoxLayout *horizontalLayout;
	QLabel *label;
	QLineEdit *User;
	QLabel *label_2;
	QLineEdit *Pass;
	QPushButton *PushSignIn;
	QPushButton *PushWrite;

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

		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		label = new QLabel(centralwidget);
		label->setObjectName(QStringLiteral("label"));

		horizontalLayout->addWidget(label);

		User = new QLineEdit(centralwidget);
		User->setObjectName(QStringLiteral("User"));

		horizontalLayout->addWidget(User);

		label_2 = new QLabel(centralwidget);
		label_2->setObjectName(QStringLiteral("label_2"));

		horizontalLayout->addWidget(label_2);

		Pass = new QLineEdit(centralwidget);
		Pass->setObjectName(QStringLiteral("Pass"));

		horizontalLayout->addWidget(Pass);

		PushSignIn = new QPushButton(centralwidget);
		PushSignIn->setObjectName(QStringLiteral("PushSignIn"));

		horizontalLayout->addWidget(PushSignIn);

		PushWrite = new QPushButton(centralwidget);
		PushWrite->setObjectName(QStringLiteral("PushWrite"));

		horizontalLayout->addWidget(PushWrite);


		verticalLayout->addLayout(horizontalLayout);

		ClientDialog->setCentralWidget(centralwidget);

		retranslateUi(ClientDialog);

		QMetaObject::connectSlotsByName(ClientDialog);
	} // setupUi

	void retranslateUi(QMainWindow *ClientDialog)
	{
		ClientDialog->setWindowTitle(QString());
		pushButton->setText(QApplication::translate("ClientDialog", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
		label->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\350\264\246\345\217\267", Q_NULLPTR));
		label_2->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\345\257\206\347\240\201", Q_NULLPTR));
		PushSignIn->setText(QApplication::translate("ClientDialog", "\347\231\273\345\275\225\350\264\246\345\217\267", Q_NULLPTR));
		PushWrite->setText(QApplication::translate("ClientDialog", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ClientDialog : public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTDIALOGO14720_H
