/********************************************************************************
** Form generated from reading UI file 'ClientDialoga19848.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CLIENTDIALOGA19848_H
#define CLIENTDIALOGA19848_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
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
	QVBoxLayout *verticalLayout_3;
	QTableView *tableView;
	QPushButton *pushButton;
	QGroupBox *groupBox;
	QVBoxLayout *verticalLayout;
	QHBoxLayout *horizontalLayout;
	QLabel *label;
	QLineEdit *User;
	QLabel *label_2;
	QLineEdit *Pass;
	QPushButton *PushSignIn;
	QPushButton *PushWrite;
	QGroupBox *groupBox_2;
	QVBoxLayout *verticalLayout_2;
	QHBoxLayout *horizontalLayout_2;
	QLabel *label_3;
	QLineEdit *Change_User;
	QLabel *label_4;
	QLineEdit *Change_oPass;
	QHBoxLayout *horizontalLayout_3;
	QLabel *label_5;
	QLineEdit *Change_pPass;
	QLabel *label_6;
	QLineEdit *Change_nPass;
	QPushButton *PushChange;

	void setupUi(QMainWindow *ClientDialog)
	{
		if (ClientDialog->objectName().isEmpty())
			ClientDialog->setObjectName(QStringLiteral("ClientDialog"));
		ClientDialog->resize(640, 480);
		ClientDialog->setMinimumSize(QSize(640, 480));
		centralwidget = new QWidget(ClientDialog);
		centralwidget->setObjectName(QStringLiteral("centralwidget"));
		verticalLayout_3 = new QVBoxLayout(centralwidget);
		verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
		tableView = new QTableView(centralwidget);
		tableView->setObjectName(QStringLiteral("tableView"));

		verticalLayout_3->addWidget(tableView);

		pushButton = new QPushButton(centralwidget);
		pushButton->setObjectName(QStringLiteral("pushButton"));

		verticalLayout_3->addWidget(pushButton);

		groupBox = new QGroupBox(centralwidget);
		groupBox->setObjectName(QStringLiteral("groupBox"));
		verticalLayout = new QVBoxLayout(groupBox);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
		label = new QLabel(groupBox);
		label->setObjectName(QStringLiteral("label"));

		horizontalLayout->addWidget(label);

		User = new QLineEdit(groupBox);
		User->setObjectName(QStringLiteral("User"));

		horizontalLayout->addWidget(User);

		label_2 = new QLabel(groupBox);
		label_2->setObjectName(QStringLiteral("label_2"));

		horizontalLayout->addWidget(label_2);

		Pass = new QLineEdit(groupBox);
		Pass->setObjectName(QStringLiteral("Pass"));

		horizontalLayout->addWidget(Pass);

		PushSignIn = new QPushButton(groupBox);
		PushSignIn->setObjectName(QStringLiteral("PushSignIn"));

		horizontalLayout->addWidget(PushSignIn);

		PushWrite = new QPushButton(groupBox);
		PushWrite->setObjectName(QStringLiteral("PushWrite"));

		horizontalLayout->addWidget(PushWrite);


		verticalLayout->addLayout(horizontalLayout);


		verticalLayout_3->addWidget(groupBox);

		groupBox_2 = new QGroupBox(centralwidget);
		groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
		verticalLayout_2 = new QVBoxLayout(groupBox_2);
		verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
		label_3 = new QLabel(groupBox_2);
		label_3->setObjectName(QStringLiteral("label_3"));

		horizontalLayout_2->addWidget(label_3);

		Change_User = new QLineEdit(groupBox_2);
		Change_User->setObjectName(QStringLiteral("Change_User"));

		horizontalLayout_2->addWidget(Change_User);

		label_4 = new QLabel(groupBox_2);
		label_4->setObjectName(QStringLiteral("label_4"));

		horizontalLayout_2->addWidget(label_4);

		Change_oPass = new QLineEdit(groupBox_2);
		Change_oPass->setObjectName(QStringLiteral("Change_oPass"));

		horizontalLayout_2->addWidget(Change_oPass);


		verticalLayout_2->addLayout(horizontalLayout_2);

		horizontalLayout_3 = new QHBoxLayout();
		horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
		label_5 = new QLabel(groupBox_2);
		label_5->setObjectName(QStringLiteral("label_5"));

		horizontalLayout_3->addWidget(label_5);

		Change_pPass = new QLineEdit(groupBox_2);
		Change_pPass->setObjectName(QStringLiteral("Change_pPass"));

		horizontalLayout_3->addWidget(Change_pPass);

		label_6 = new QLabel(groupBox_2);
		label_6->setObjectName(QStringLiteral("label_6"));

		horizontalLayout_3->addWidget(label_6);

		Change_nPass = new QLineEdit(groupBox_2);
		Change_nPass->setObjectName(QStringLiteral("Change_nPass"));

		horizontalLayout_3->addWidget(Change_nPass);


		verticalLayout_2->addLayout(horizontalLayout_3);

		PushChange = new QPushButton(groupBox_2);
		PushChange->setObjectName(QStringLiteral("PushChange"));

		verticalLayout_2->addWidget(PushChange);


		verticalLayout_3->addWidget(groupBox_2);

		ClientDialog->setCentralWidget(centralwidget);

		retranslateUi(ClientDialog);

		QMetaObject::connectSlotsByName(ClientDialog);
	} // setupUi

	void retranslateUi(QMainWindow *ClientDialog)
	{
		ClientDialog->setWindowTitle(QString());
		pushButton->setText(QApplication::translate("ClientDialog", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
		groupBox->setTitle(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
		label->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\350\264\246\345\217\267", Q_NULLPTR));
		label_2->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\345\257\206\347\240\201", Q_NULLPTR));
		PushSignIn->setText(QApplication::translate("ClientDialog", "\347\231\273\345\275\225\350\264\246\345\217\267", Q_NULLPTR));
		PushWrite->setText(QApplication::translate("ClientDialog", "\346\263\250\345\206\214\350\264\246\345\217\267", Q_NULLPTR));
		groupBox_2->setTitle(QApplication::translate("ClientDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
		label_3->setText(QApplication::translate("ClientDialog", "\347\224\250\346\210\267\350\264\246\345\217\267", Q_NULLPTR));
		label_4->setText(QApplication::translate("ClientDialog", "\345\216\237\345\247\213\345\257\206\347\240\201", Q_NULLPTR));
		label_5->setText(QApplication::translate("ClientDialog", "PIN \345\257\206\347\240\201", Q_NULLPTR));
		label_6->setText(QApplication::translate("ClientDialog", "\346\226\260\347\232\204\345\257\206\347\240\201", Q_NULLPTR));
		PushChange->setText(QApplication::translate("ClientDialog", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ClientDialog : public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CLIENTDIALOGA19848_H
