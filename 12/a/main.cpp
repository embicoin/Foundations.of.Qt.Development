#include <QApplication>
#include <QMessageBox>
#include "textthread.h"

extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextThread foo( "Foo" ), bar( "Bar" );

    bar.start();
    foo.start();

    QMessageBox::information( 0, "Threading", "Close me to stop!");

    stopThreads = true;

    foo.wait();
    bar.wait();

    return 0;
}
