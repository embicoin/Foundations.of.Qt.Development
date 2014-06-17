#include "listdialog.h"

ListDialog::ListDialog() : QDialog()
{
    ui.setupUi(this);

    connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui.editButton, SIGNAL(clicked()), this, SLOT(editItem()));
    connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
}

void ListDialog::addItem()
{
    EditDialog dlg(this);

    if (dlg.exec() == QDialog::Accepted)
        ui.list->addItem(dlg.name() + " -- " + dlg.number());
}

void ListDialog::deleteItem()
{
    delete ui.list->currentItem();
}

void ListDialog::editItem()
{
    if (!ui.list->currentItem())
        return;

    QStringList parts = ui.list->currentItem()->text().split("--");

    EditDialog dlg(this);
    dlg.setName(parts[0].trimmed());
    dlg.setNumber(parts[1].trimmed());

    if (dlg.exec() == QDialog::Accepted)
        ui.list->currentItem()->setText(dlg.name() + " -- " + dlg.number());
}

EditDialog::EditDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

const QString EditDialog::name() const
{
    return ui.nameEdit->text().replace("--","").trimmed();
}

void EditDialog::setName(const QString &name)
{
    ui.nameEdit->setText(name);
}

const QString EditDialog::number() const
{
    return ui.numberEdit->text().replace("--","").trimmed();
}

void EditDialog::setNumber(const QString &number)
{
    ui.numberEdit->setText(number);
}
