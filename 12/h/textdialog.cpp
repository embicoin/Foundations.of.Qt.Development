#include "textdialog.h"

TextDialog::TextDialog() : QDialog()
{
    ui.setupUi( this );

    connect( ui.buttonBox, SIGNAL(clicked(QAbstractButton *)),
             this, SLOT(buttonClicked(QAbstractButton *)) );

    count = 0;
}

void TextDialog::buttonClicked( QAbstractButton *button )
{
    if( ui.buttonBox->buttonRole( button ) == QDialogButtonBox::ResetRole )
        ui.listWidget->clear();
}

void TextDialog::showText( TextAndNumber tan )
{
    QMutexLocker locker( &mutex );

    ui.listWidget->addItem( QString( "Call %1 (%3): %2" ).arg( count++ ).arg( tan.text ).arg( tan.number ));

}
