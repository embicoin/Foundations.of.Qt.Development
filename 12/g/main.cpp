#include "textdevice.h"
#include <QApplication>
#include "textthread.h"
#include <QMessageBox>

//extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    qRegisterMetaType<TextAndNumber>("TextAndNumber");

    TextDevice device;
    TextThread foo( "Foo" );
    TextThread bar( "Bar" );

    QObject::connect( &foo, SIGNAL(writeText(TextAndNumber)),
                      &device, SLOT(write(TextAndNumber)) );
    QObject::connect( &bar, SIGNAL(writeText(TextAndNumber)),
                      &device, SLOT(write(TextAndNumber)) );

    foo.start();
    bar.start();
    device.start();

    QMessageBox::information( 0, "Threading", "Close me to stop!" );

    foo.stop();
    bar.stop();
    device.stop();

    foo.wait();
    bar.wait();
    device.wait();

    return 0;
}
