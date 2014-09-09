#include "textdevice.h"
#include <QApplication>
#include "textthread.h"
#include <QMessageBox>
#include "increasethread.h"

extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextDevice device;
    IncreaseThread inc( &device );
    TextThread foo( "Foo", &device );
    TextThread bar( "Bar", &device );

    foo.start();
    bar.start();
    inc.start();

    QMessageBox::information( 0, "Threading", "Close me to stop!" );

    stopThreads = true;

    foo.wait();
    bar.wait();
    inc.wait();

    return 0;
}
