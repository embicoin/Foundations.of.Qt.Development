#include "eventwidget.h"

EventWidget::EventWidget( QWidget *parent )
    : QWidget( parent )
{
    
}

void EventWidget::closeEvent( QCloseEvent *event )
{
    emit gotEvent( tr("closeEvent") );
}

void EventWidget::contextMenuEvent( QContextMenuEvent *event )
{
    emit gotEvent( tr("contextMenuEvent") );
}

void EventWidget::enterEvent( QEvent *event )
{
    emit gotEvent( tr("enterEvent") );
}

void EventWidget::focusInEvent( QFocusEvent *event )
{
    emit gotEvent( tr("focusInEvent") );
}

void EventWidget::focusOutEvent( QFocusEvent *event )
{
    emit gotEvent( tr("focusOutEvent") );
}

void EventWidget::hideEvent( QHideEvent *event )
{
    emit gotEvent( tr("hideEvent") );
}

void EventWidget::keyPressEvent( QKeyEvent *event )
{
    emit gotEvent( tr("keyPressEvent") );
}

void EventWidget::keyReleaseEvent( QKeyEvent *event )
{
    emit gotEvent( tr("keyReleaseEvent") );
}

//void EventWidget::leaveEvent( QEvent *event )
//void EventWidget::mouseDoubleClickEvent( QMouseEvent *event )
//void EventWidget::mouseMoveEvent( QMouseEvent *event )
//void EventWidget::mousePressEvent( QMouseEvent *event )
//void EventWidget::mouseReleaseEvent( QMouseEvent *event )
//void EventWidget::paintEvent( QPaiintEvent *event )
//void EventWidget::resizeEvent( QResizeEvent *event )
//void EventWidget::showEvent( QShowEvent *event )
//void EventWidget::wheelEvent( QWheelEvent *event )
