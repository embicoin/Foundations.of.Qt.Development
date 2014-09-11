#include "processdialog.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    ProcessDialog dialog;
    dialog.exec();

    return 0;
}
