#include "circlebar.h"
#include <QSize>
#include <QPaintEvent>
#include <QPainter>

CircleBar::CircleBar( int value, QWidget *parent)
    : QWidget( parent )
{
    m_value = value;

    QSizePolicy policy( QSizePolicy::Preferred, QSizePolicy::Preferred );
    policy.setHeightForWidth( true );
    setSizePolicy( policy );
}

int CircleBar::heightForWidth( int width ) const
{
    return width;
}

QSize CircleBar::sizeHint() const
{
    return QSize( 100, 100 );
}

int CircleBar::value() const
{
    return m_value;
}

void CircleBar::setValue( int value )
{
    if( value < 0 )
        value = 0;

    if( value > 100 )
        value = 100;

    if( m_value == value )
        return;

    m_value = value;

    // emit repaint signal to call paintEvent
    update();

    emit valueChanged( m_value );
}

void CircleBar::paintEvent( QPaintEvent *event )
{
    int radius = width() / 2;
    double factor = m_value / 100.0;

    QPainter p( this );
    p.setPen( Qt::black );
    p.drawEllipse( 0, 0, width() - 1, width() - 1 );
    p.setBrush( Qt::black );
    p.drawEllipse( (int)(radius * (1.0 - factor)),
            (int)(radius * (1.0 - factor)),
            //(int)((width() - 1) * factor) + 1,
            //(int)((width() - 1) * factor) + 1 );
            (int)((width()) * factor),
            (int)((width()) * factor));
}
