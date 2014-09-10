#include "textdevice.h"
#include <QApplication>
#include "textthread.h"
#include <QMessageBox>

//extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextDevice device;
    TextThread foo( "Foo" );
    TextThread bar( "Bar" );

    QObject::connect( &foo, SIGNAL(writeText(const QString &)),
                      &device, SLOT(write(const QString &)) );
    QObject::connect( &bar, SIGNAL(writeText(const QString &)),
                      &device, SLOT(write(const QString &)) );

    foo.start();
    bar.start();
    device.start();

    QMessageBox::information( 0, "Threading", "Close me to stop!" );

    foo.stop();
    bar.stop();
    device.stop();
    //stopThreads = true;

    foo.wait();
    bar.wait();
    device.wait();

    return 0;
}
