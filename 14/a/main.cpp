#include "ftpdialog.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    FtpDialog dialog;
    dialog.show();
    return app.exec();
}
