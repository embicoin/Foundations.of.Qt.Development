#include "singleitemview.h"
#include <QScrollBar>

SingleItemView::SingleItemView( QWidget *parent )
{
    Q_UNUSED(parent);
}

QModelIndex SingleItemView::indexAt( const QPoint &point ) const
{
    Q_UNUSED(point);
    return QModelIndex();
}

bool SingleItemView::isIndexHidden( const QModelIndex &index ) const
{
    Q_UNUSED(index);
    return true;
}

QRegion SingleItemView::visualRegionForSelection( const QItemSelection &selection ) const
{
    Q_UNUSED(selection);
    return QRegion();
}

void SingleItemView::updateText()
{
    switch( selectionModel()->selection().indexes().count() )
    {
        case 0:
            label->setText( tr("<i>No data.</i>") );
            break;

        case 1:
            label->setText( model()->data( currentIndex() ).toString() );
            break;

        default:
            label->setText( tr("<i>Too many items selected.<br>"
                        "Can only show one item at a item.</i>") );
            break;
    }
}

QRect SingleItemView::visualRect( const QModelIndex &index ) const
{
    if( selectionModel()->selection().indexes().count() != 1 )
        return QRect();

    if( currentIndex() != index )
        return QRect();

    return rect();
}

int SingleItemView::horizontalOffset() const
{
    return horizontalScrollBar()->value();
}

int SingleItemView::verticalOffset() const
{
    return verticalScrollBar()->value();
}

QModelIndex SingleItemView::moveCursor( CursorAction cursorAction,
        Qt::KeyboardModifiers modifiers )
{
    return currentIndex();
}

void SingleItemView::setSelection( const QRect &rect,
        QItemSelectionModel::SelectionFlags flags )
{

}

void SingleItemView::scrollTo( const QModelIndex &index, ScrollHint hint )
{

}

void SingleItemView::dataChanged( const QModelIndex &topLeft,
        const QModelIndex &bottomRight)
{
    updateText();
}

void SingleItemView::selectionChanged( const QItemSelection &selected,
        const QItemSelection &deselected )
{
    updateText();
}
