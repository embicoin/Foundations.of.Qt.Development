#include <QApplication>
#include "bardelegate.h"
#include <QTableView>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication app( argc, argv );
    QTableView table;

    QStandardItemModel model( 10, 2 );
    for( int r = 0; r < 10; ++r )
    {
        QStandardItem *item = new QStandardItem( QString("Row %1").arg(r + 1) );
        item->setEditable( false );
        model.setItem( r, 0, item );
        model.setItem( r, 1, new QStandardItem( QString::number( (r*30) % 100 )) );
    }

    table.setModel( &model );

    BarDelegate delegate;
    // without this line, the 2nd column will show numerics instead of rectangles, so the delegate takes the input data and display it in a graphics way, and this is the delegate's function
    table.setItemDelegateForColumn( 1, &delegate );

    table.show();

    return app.exec();
}
