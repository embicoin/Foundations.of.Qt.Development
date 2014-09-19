#include "sender.h"
#include <QApplication>
#include <QMessageBox>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    Sender sender;
    QMessageBox::information( 0, "Info", "Broadcasting image" );

    return 0;
}
