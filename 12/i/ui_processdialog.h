/********************************************************************************
** Form generated from reading UI file 'processdialog.ui'
**
** Created: Thu Sep 11 10:11:03 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSDIALOG_H
#define UI_PROCESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProcessDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *uicButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *ProcessDialog)
    {
        if (ProcessDialog->objectName().isEmpty())
            ProcessDialog->setObjectName(QString::fromUtf8("ProcessDialog"));
        ProcessDialog->resize(266, 230);
        gridLayout = new QGridLayout(ProcessDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        uicButton = new QPushButton(ProcessDialog);
        uicButton->setObjectName(QString::fromUtf8("uicButton"));

        verticalLayout->addWidget(uicButton);

        textEdit = new QTextEdit(ProcessDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(ProcessDialog);

        QMetaObject::connectSlotsByName(ProcessDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessDialog)
    {
        ProcessDialog->setWindowTitle(QApplication::translate("ProcessDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        uicButton->setText(QApplication::translate("ProcessDialog", "Run uic", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProcessDialog: public Ui_ProcessDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSDIALOG_H
