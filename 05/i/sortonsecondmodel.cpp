#include "sortonsecondmodel.h"
#include <QString>

SortOnSecondModel::SortOnSecondModel( QObject *parent )
    : QSortFilterProxyModel( parent )
{
}

bool SortOnSecondModel::lessThan( const QModelIndex &left,
        const QModelIndex &right ) const
{
    QString leftString = sourceModel()->data( left ).toString();
    QString rightString = sourceModel()->data( right ).toString();

    if( !leftString.isEmpty() )
        leftString = leftString.mid( 1 );

    if( !rightString.isEmpty() )
        rightString = rightString.mid( 1 );

    return leftString < rightString;
}
