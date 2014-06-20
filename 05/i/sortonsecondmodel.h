#include <QSortFilterProxyModel>
#include <QObject>

class SortOnSecondModel : public QSortFilterProxyModel
{
    public:
        SortOnSecondModel( QObject *parent = 0 );

    protected:
        bool lessThan( const QModelIndex &left, const QModelIndex &right ) const;
};
