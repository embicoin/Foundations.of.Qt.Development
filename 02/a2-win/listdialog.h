#include <QDialog>
#include "ui_listdialog.h"

class ListDialog : public QDialog
{
    Q_OBJECT
    public:
        ListDialog(QWidget *parent = 0);
    private slots:
        void addItem();
        void deleteItem();
        void editItem();
        void clearAll();

    private:
        Ui::ListDialog ui;
};
