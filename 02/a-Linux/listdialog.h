#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include "ui_listdialog.h"
#include "ui_editdialog.h"

class ListDialog : public QDialog 
{
    Q_OBJECT
    public:
        ListDialog();
    private slots:
        void addItem();
        void editItem();
        void deleteItem();

    private:
        Ui::ListDialog ui;

};

class EditDialog : public QDialog
{
    public:
        EditDialog(QWidget *parent = 0);
        const QString name() const;
        void setName(const QString&);

        const QString number() const;
        void setNumber(const QString&);
        
    private:
        Ui::EditDialog ui;
};

#endif
