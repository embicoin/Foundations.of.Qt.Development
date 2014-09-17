/********************************************************************************
** Form generated from reading UI file 'httpdialog.ui'
**
** Created: Wed Sep 17 12:01:00 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPDIALOG_H
#define UI_HTTPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HttpDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *requestEdit;
    QPushButton *getButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *hostLabel;
    QLabel *pathLabel;
    QLabel *portLabel;
    QLabel *userLabel;
    QLabel *passwordLabel;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QListWidget *statusList;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *HttpDialog)
    {
        if (HttpDialog->objectName().isEmpty())
            HttpDialog->setObjectName(QString::fromUtf8("HttpDialog"));
        HttpDialog->resize(421, 390);
        gridLayout_4 = new QGridLayout(HttpDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(HttpDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        requestEdit = new QLineEdit(groupBox);
        requestEdit->setObjectName(QString::fromUtf8("requestEdit"));

        horizontalLayout->addWidget(requestEdit);

        getButton = new QPushButton(groupBox);
        getButton->setObjectName(QString::fromUtf8("getButton"));

        horizontalLayout->addWidget(getButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(HttpDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hostLabel = new QLabel(groupBox_2);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

        verticalLayout->addWidget(hostLabel);

        pathLabel = new QLabel(groupBox_2);
        pathLabel->setObjectName(QString::fromUtf8("pathLabel"));

        verticalLayout->addWidget(pathLabel);

        portLabel = new QLabel(groupBox_2);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        verticalLayout->addWidget(portLabel);

        userLabel = new QLabel(groupBox_2);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        verticalLayout->addWidget(userLabel);

        passwordLabel = new QLabel(groupBox_2);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        verticalLayout->addWidget(passwordLabel);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(105, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(HttpDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        statusList = new QListWidget(groupBox_3);
        statusList->setObjectName(QString::fromUtf8("statusList"));

        gridLayout_3->addWidget(statusList, 0, 0, 2, 1);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);


        retranslateUi(HttpDialog);

        QMetaObject::connectSlotsByName(HttpDialog);
    } // setupUi

    void retranslateUi(QDialog *HttpDialog)
    {
        HttpDialog->setWindowTitle(QApplication::translate("HttpDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("HttpDialog", "Request", 0, QApplication::UnicodeUTF8));
        getButton->setText(QApplication::translate("HttpDialog", "Get", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("HttpDialog", "Url Components", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HttpDialog", "Host:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HttpDialog", "Path:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HttpDialog", "Port:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HttpDialog", "User:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HttpDialog", "Password:", 0, QApplication::UnicodeUTF8));
        hostLabel->setText(QApplication::translate("HttpDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        pathLabel->setText(QApplication::translate("HttpDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("HttpDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QApplication::translate("HttpDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("HttpDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("HttpDialog", "Http Status", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("HttpDialog", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HttpDialog: public Ui_HttpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPDIALOG_H
