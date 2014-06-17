#include "ui_editdialog.h"

class EditDialog : public QDialog
{
    public:
        EditDialog(QDialog *parent = 0);

        QString name() const;
        void setName(const QString& name);
        QString number() const;
        void setNumber(const QString& number);
    private:
        Ui::EditDialog ui;
};
