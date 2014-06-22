#include "clocklabel.h"
#include <QTimer>
#include <QTime>

ClockLabel::ClockLabel( QWidget *parent )
    : QLabel( parent )
{
    QTimer *timer = new QTimer( this ); 
    timer->setInterval( 1000 );
    connect( timer, SIGNAL(timeout()), this, SLOT(updateTime()) );
    timer->start();
    updateTime();
}

void ClockLabel::updateTime()
{
    setText( QTime::currentTime().toString( "hh:mm:ss" ));
}
