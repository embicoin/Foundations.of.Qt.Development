#include "mybutton.h"
#include <QPainter>
#include <QStyleOptionButton>

MyButton::MyButton( QWidget *parent )
    : QAbstractButton( parent )
{
}

QSize MyButton::sizeHint() const
{
    return QSize( fontMetrics().width( text() ) + 10, fontMetrics().height() + 10 );
}

void MyButton::paintEvent( QPaintEvent *)
{
    QPainter painter( this );
    QStyleOptionButton option;
    option.init( this );
    if( isDown() )
        option.state |= QStyle::State_Sunken;
    else if( isChecked() )
        option.state |= QStyle::State_On;

    style()->drawControl( QStyle::CE_PushButtonBevel, &option, &painter, this );

    painter.setFont( font() );

    if( !isEnabled() )
        painter.setPen( Qt::darkGray );

    else if( isDown() ) 
        painter.setPen( Qt::yellow ); // pressed
    else 
        painter.setPen( Qt::blue ); // being pressed

    painter.drawText( rect(), Qt::AlignCenter, text() );
}
