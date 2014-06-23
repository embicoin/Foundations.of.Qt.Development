#include "dialog.h"
#include <QMessageBox>

Dialog::Dialog() : QDialog()
{
    ui.setupUi( this );
    connect( ui.clickButton, SIGNAL(clicked()), this, SLOT(buttonClicked()) );
}

void Dialog::buttonClicked()
{
    QMessageBox::information( this, tr("Wohoo"), tr("You clicked the button!"));
}
