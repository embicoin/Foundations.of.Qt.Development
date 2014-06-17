#include "editdialog.h"

EditDialog::EditDialog(QDialog *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

QString EditDialog::name() const
{
    return ui.nameEdit->text();
}

void EditDialog::setName(const QString& name)
{
    ui.nameEdit->setText(name);
}

QString EditDialog::number() const
{
    return ui.numberEdit->text();
}

void EditDialog::setNumber(const QString& number)
{
    ui.nameEdit->setText(number);
}
