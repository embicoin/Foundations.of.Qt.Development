#include "imagedialog.h"
#include "imagecollection.h"
#include <QApplication>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    
    ImageDialog dlg;
    dlg.show();

    return app.exec();
}
