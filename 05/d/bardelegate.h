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
        QWidget *createEditor( QWidget *parent,
                const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;
        void setEditorData( QWidget *editor,
                const QModelIndex &index ) const;
        void setModelData( QWidget *editor,
                QAbstractItemModel *model,
                const QModelIndex &index ) const;
        void updateEditorGeometry( QWidget *editor,
                const QStyleOptionViewItem &option,
                const QModelIndex &index) const;
};

