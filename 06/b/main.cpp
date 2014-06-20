#include "keyboardfilter.h"
#include <QApplication>
#include <QLineEdit>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QLineEdit lineEdit;
    KeyboardFilter filter;

    lineEdit.installEventFilter( &filter );
    lineEdit.show();

    return app.exec();
}
