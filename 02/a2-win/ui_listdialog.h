/********************************************************************************
** Form generated from reading UI file 'listdialog.ui'
**
** Created: Mon May 26 19:45:23 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTDIALOG_H
#define UI_LISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *list;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editButton;
    QSpacerItem *verticalSpacer;
    QPushButton *clearButton;

    void setupUi(QDialog *ListDialog)
    {
        if (ListDialog->objectName().isEmpty())
            ListDialog->setObjectName(QString::fromUtf8("ListDialog"));
        ListDialog->resize(400, 300);
        gridLayout = new QGridLayout(ListDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        list = new QListWidget(ListDialog);
        list->setObjectName(QString::fromUtf8("list"));

        gridLayout->addWidget(list, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addButton = new QPushButton(ListDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        deleteButton = new QPushButton(ListDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        editButton = new QPushButton(ListDialog);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout->addWidget(editButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        clearButton = new QPushButton(ListDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        verticalLayout->addWidget(clearButton);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(ListDialog);

        QMetaObject::connectSlotsByName(ListDialog);
    } // setupUi

    void retranslateUi(QDialog *ListDialog)
    {
        ListDialog->setWindowTitle(QApplication::translate("ListDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("ListDialog", "Add", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("ListDialog", "Delete", 0, QApplication::UnicodeUTF8));
        editButton->setText(QApplication::translate("ListDialog", "Edit", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("ListDialog", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ListDialog: public Ui_ListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTDIALOG_H
