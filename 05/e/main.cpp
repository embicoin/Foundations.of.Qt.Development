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
    for( int r = 0; r < 5; ++r )
    {
        for (int c = 0; c < 2; c++)
        {
            QStandardItem *item = new QStandardItem( QString("Row %1 : Column %2").arg(r + 1).arg(c + 1) );
            item->setEditable( false );
            model.setItem( r, c, item );
        }
    }

    table->setModel( &model );
    selectionView->setModel( &model );
    selectionView->setSelectionModel( table->selectionModel() );

    QSplitter splitter;
    splitter.addWidget( table );
    splitter.addWidget( selectionView );

    splitter.show();

    return app.exec();
}
