#include "circlewidget.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    CircleWidget window;
    window.show();

    return app.exec();
}
