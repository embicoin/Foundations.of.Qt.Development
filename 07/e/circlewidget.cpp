#include "circlewidget.h"
#include <QPainter>

CircleWidget::CircleWidget( QWidget *parent )
    : QWidget( parent )
{
    r = 0;

    timer.setInterval( 50 );
    
    connect( &timer, SIGNAL(timeout()), this, SLOT(timeout()) );
}

QSize CircleWidget::sizeHint() const
{
    return QSize( 200, 100 );
}

void CircleWidget::mousePressEvent( QMouseEvent *e )
{
    mx = e->x();
    my = e->y();

    timer.start();
}

void CircleWidget::mouseMoveEvent( QMouseEvent *e )
{
    mx = e->x();
    my = e->y();
}

void CircleWidget::mouseReleaseEvent( QMouseEvent *e )
{
    timer.stop();
}

void CircleWidget::timeout()
{
    if( r == 0 )
    {
        x = mx;
        y = my;

        color = QColor( qrand()%256, qrand()%256, qrand()%256 );
    }

    int dx = mx - x;
    int dy = my - y;

    if( dx*dx + dy*dy <= r*r )
        r++;
    else
        r--;

    update();
}

void CircleWidget::paintEvent( QPaintEvent * )
{
    if( r > 0 )
    {
        QPainter painter( this );

        painter.setRenderHint( QPainter::Antialiasing );

        painter.setPen( color );
        painter.setBrush( color );
        painter.drawEllipse( x-r, y-r, 2*r, 2*r );
    }
}
