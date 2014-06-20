#include <QApplication>
#include <QStringListModel>
#include <QStringList>
#include <QTableView>
#include "sortonsecondmodel.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QStringListModel model;
    QStringList list;
    list << "Totte" << "Alfons" << "Laban" << "Bamse" << "Skalman";
    model.setStringList( list );

    SortOnSecondModel sorter;
    sorter.setSourceModel( &model );
    sorter.setDynamicSortFilter( true );

    QTableView table;
    table.setModel( &sorter );
    table.setSortingEnabled( true );
    table.show();

    return app.exec();
}
