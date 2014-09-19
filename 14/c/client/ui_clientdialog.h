/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created: Thu Sep 18 14:33:35 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *serverEdit;
    QPushButton *getButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *imageLabel;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QString::fromUtf8("ClientDialog"));
        ClientDialog->resize(481, 451);
        gridLayout_3 = new QGridLayout(ClientDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(ClientDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        serverEdit = new QLineEdit(groupBox);
        serverEdit->setObjectName(QString::fromUtf8("serverEdit"));

        horizontalLayout->addWidget(serverEdit);

        getButton = new QPushButton(groupBox);
        getButton->setObjectName(QString::fromUtf8("getButton"));

        horizontalLayout->addWidget(getButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ClientDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        imageLabel = new QLabel(groupBox_2);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(imageLabel, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);


        retranslateUi(ClientDialog);

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ClientDialog", "Server Settings", 0, QApplication::UnicodeUTF8));
        getButton->setText(QApplication::translate("ClientDialog", "Get", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ClientDialog", "Image", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QApplication::translate("ClientDialog", "No Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
