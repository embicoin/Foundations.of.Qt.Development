#include <QApplication>
#include "httpdialog.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    
    HttpDialog dialog;
    dialog.show();

    return app.exec();
}
