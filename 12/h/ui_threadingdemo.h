/********************************************************************************
** Form generated from reading UI file 'threadingdemo.ui'
**
** Created: Wed Sep 10 10:37:25 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADINGDEMO_H
#define UI_THREADINGDEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TextDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TextDialog)
    {
        if (TextDialog->objectName().isEmpty())
            TextDialog->setObjectName(QString::fromUtf8("TextDialog"));
        TextDialog->resize(359, 265);
        gridLayout = new QGridLayout(TextDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget = new QListWidget(TextDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(TextDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Reset);

        verticalLayout_2->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(TextDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), TextDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(TextDialog);
    } // setupUi

    void retranslateUi(QDialog *TextDialog)
    {
        TextDialog->setWindowTitle(QApplication::translate("TextDialog", "Threading demonstration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TextDialog: public Ui_TextDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADINGDEMO_H
