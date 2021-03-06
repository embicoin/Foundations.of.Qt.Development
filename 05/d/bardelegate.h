#include <QObject>
#include <QAbstractItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>


class BarDelegate : public QAbstractItemDelegate
{
    public:
        BarDelegate( QObject *parent = 0);

        // paint one item
        void paint( QPainter *painter,
                const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;

        QSize sizeHint( const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;

        QWidget *createEditor( QWidget *parent,
                const QStyleOptionViewItem &option,
                const QModelIndex &index ) const;

        // set the editor value based on the model
        void setEditorData( QWidget *editor,
                const QModelIndex &index ) const;

        // set the model value based on the editor
        void setModelData( QWidget *editor,
                QAbstractItemModel *model,
                const QModelIndex &index ) const;

        void updateEditorGeometry( QWidget *editor,
                const QStyleOptionViewItem &option,
                const QModelIndex &index) const;
};

