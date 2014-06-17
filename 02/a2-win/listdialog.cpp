#include "listdialog.h"
#include "editdialog.h"

ListDialog::ListDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteItem()));
    connect(ui.editButton, SIGNAL(clicked()), this, SLOT(editItem()));
    connect(ui.clearButton, SIGNAL(clicked()), this, SLOT(clearAll()));
}

void ListDialog::addItem()
{
    EditDialog dlg(this);    

    if (dlg.exec() == QDialog::Accepted)
    {
        QString name = dlg.ui.nameEdit->text().replace("--", "").trimmed();
        QString number = dlg.ui.numberEdit->text().replace("--", "").trimmed();

        ui.list->addItem(name + " -- " + number);
    }
}

void ListDialog::deleteItem()
{
    if (ui.list->currentItem() != 0)
    {
        // no change when call removeItemWidget
        //ui.list->removeItemWidget(ui.list->currentItem());
        delete ui.list->currentItem();
    }
}

void ListDialog::editItem()
{
    if (ui.list->currentItem() != 0)
    {
        EditDialog dlg(this);

        QStringList item = ui.list->currentItem()->text().split("--");
        QString name = item[0].trimmed();
        QString number = item[1].trimmed();

        dlg.ui.nameEdit->setText(name);
        dlg.ui.numberEdit->setText(number);

        if (dlg.exec() == QDialog::Accepted)
        {
            name = dlg.name();
            number = dlg.number();
            ui.list->currentItem()->setText(name + " -- " + number);
        }   
    }
}

void ListDialog::clearAll()
{
    ui.list->clear();
}
