#include "keyboardfilter.h"
#include <QDebug>

KeyboardFilter::KeyboardFilter( QWidget *parent ) 
    : QWidget( parent )
{
}

bool KeyboardFilter::eventFilter( QObject *dist, QEvent *event )
{
    if( event->type() == QEvent::KeyPress )
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>( event );
        static QString digits = QString( "1234567890" );
        //if ( digits.indexOf( keyEvent->text() ) != -1 )
        if ( keyEvent->key() == Qt::Key_0 )
            return true;
    }

    return QWidget::eventFilter( dist, event );
}

/*
void KeyboardFilter::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
        case Qt::Key_Escape: 
            qDebug() << "Esc pressed";
            break;
        case Qt::Key_0:
            qDebug() << "0 pressed";
        default:
            break;
    }
}
*/
