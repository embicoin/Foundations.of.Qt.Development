/********************************************************************************
** Form generated from reading UI file 'ftpdialog.ui'
**
** Created: Tue Sep 16 15:56:21 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTPDIALOG_H
#define UI_FTPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FtpDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QSpacerItem *verticalSpacer;
    QPushButton *cdButton;
    QPushButton *upButton;
    QPushButton *getButton;
    QSpacerItem *verticalSpacer_2;
    QListWidget *dirList;
    QLabel *statusLabel;

    void setupUi(QDialog *FtpDialog)
    {
        if (FtpDialog->objectName().isEmpty())
            FtpDialog->setObjectName(QString::fromUtf8("FtpDialog"));
        FtpDialog->resize(468, 381);
        gridLayout_2 = new QGridLayout(FtpDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(FtpDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        verticalLayout->addWidget(connectButton);

        disconnectButton = new QPushButton(groupBox);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));

        verticalLayout->addWidget(disconnectButton);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        cdButton = new QPushButton(groupBox);
        cdButton->setObjectName(QString::fromUtf8("cdButton"));

        verticalLayout->addWidget(cdButton);

        upButton = new QPushButton(groupBox);
        upButton->setObjectName(QString::fromUtf8("upButton"));

        verticalLayout->addWidget(upButton);

        getButton = new QPushButton(groupBox);
        getButton->setObjectName(QString::fromUtf8("getButton"));

        verticalLayout->addWidget(getButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        dirList = new QListWidget(groupBox);
        dirList->setObjectName(QString::fromUtf8("dirList"));

        gridLayout->addWidget(dirList, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        statusLabel = new QLabel(FtpDialog);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        gridLayout_2->addWidget(statusLabel, 1, 0, 1, 1);


        retranslateUi(FtpDialog);

        QMetaObject::connectSlotsByName(FtpDialog);
    } // setupUi

    void retranslateUi(QDialog *FtpDialog)
    {
        FtpDialog->setWindowTitle(QApplication::translate("FtpDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FtpDialog", "ftp.trolltech.com", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("FtpDialog", "Connect", 0, QApplication::UnicodeUTF8));
        disconnectButton->setText(QApplication::translate("FtpDialog", "Disconnect", 0, QApplication::UnicodeUTF8));
        cdButton->setText(QApplication::translate("FtpDialog", "Change Directory", 0, QApplication::UnicodeUTF8));
        upButton->setText(QApplication::translate("FtpDialog", "Up", 0, QApplication::UnicodeUTF8));
        getButton->setText(QApplication::translate("FtpDialog", "Get File", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("FtpDialog", "Ready", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FtpDialog: public Ui_FtpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTPDIALOG_H
