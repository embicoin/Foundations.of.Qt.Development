#include "keyboardfilter.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    KeyboardFilter k;
    k.show();

    return app.exec();
}
