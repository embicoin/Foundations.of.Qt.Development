#include <QObject>
#include <QAbstractItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>


class BarDelegate : public QAbstractItemDelegate
{
    public:
        BarDelegate( QObject *parent = 0);

        void paint( QPainter *painter,
                const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;
        QSize sizeHint( const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;
};
