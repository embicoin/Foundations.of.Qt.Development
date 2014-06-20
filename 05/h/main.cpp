#include "intmodel.h"
#include <QApplication>
#include <QListView>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    IntModel model( 25 );

    QListView list;
    list.setModel( &model );
    list.show();

    return app.exec();
}
