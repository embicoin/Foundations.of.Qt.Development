#include "textdevice.h"
#include <QApplication>
#include "textthread.h"
#include <QMessageBox>

extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextDevice device;
    TextThread foo( "Foo", &device);
    TextThread bar( "Bar", &device);

    foo.start();
    bar.start();

    QMessageBox::information( 0, "Threading", "Close me to stop!");

    stopThreads = true;

    foo.wait();
    bar.wait();

    return 0;
}
