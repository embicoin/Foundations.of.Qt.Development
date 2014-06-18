#include "singleitemview.h"
#include <QApplication>
#include <QTableView>
#include <QSplitter>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView *table = new QTableView;
    SingleItemView *selectionView = new SingleItemView;

    QStandardItemModel model( 10, 2 );
    for( int r = 0; r < 10; ++r )
    {
        QStandardItem *item = new QStandardItem( QString("Row %1").arg(r + 1) );
        item->setEditable( false );
        model.setItem( r, 0, item );
        model.setItem( r, 1, new QStandardItem( QString::number( ( r*30 ) % 100 )) );
    }

    QSplitter splitter;
    splitter.addWidget( table );
    splitter.addWidget( selectionView );

    table->setModel( &model );
    selectionView->setModel( &model );

    selectionView->setSelectionModel( table->selectionModel() );

    splitter.show();

    return app.exec();
}
