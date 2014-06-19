#include "mulmodel.h"
#include <QApplication>
#include <QTableView>

int main( int argc, char **argv )
{
    QApplication app(argc, argv);

    MulModel model( 12, 12 );

    QTableView table;
    table.setModel( &model );

    table.show();

    return app.exec();
}
