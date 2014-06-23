#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        Dialog();

    private slots:
        void buttonClicked();

    private:
        Ui::Dialog ui;
};

#endif
