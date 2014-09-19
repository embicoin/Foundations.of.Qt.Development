#include "listener.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    Listener listener;
    listener.show();

    return app.exec();
}
