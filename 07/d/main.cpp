//#include "mybutton.h"
#include "dialog.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    Dialog window;
    window.show();

    return app.exec();
}

