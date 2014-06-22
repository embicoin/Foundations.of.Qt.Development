#include "clocklabel.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    ClockLabel widget;
    widget.show();

    return app.exec();
}
