#include "clientdialog.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    
    ClientDialog dialog;
    dialog.show();
    return app.exec();
}
