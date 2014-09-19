#include "sender.h"
#include <QTimer>
#include <QByteArray>

Sender::Sender()
{
    socket = new QUdpSocket( this );

    image = new QImage( "kitty.png" );
    if( image->isNull() )
        qFatal( "Failed to open test.png" );

    QTimer *timer = new QTimer( this );
    timer->setInterval( 250 );
    timer->start();
    connect( timer, SIGNAL(timeout()), this, SLOT(broadcastLine()) );
}

void Sender::broadcastLine()
{
/*
    datagram format:
    +--------+--------+-------+-------+-------+-------+---------------------------+
    | width  | height |   y   |   r   |   g   |   b   |   r  |   g  |   b  | ...  |
    +--------+--------+-------+-------+-------+-------+---------------------------+
     quint16  quint16  quint16
*/
    QByteArray buffer( 6 + 3*image->width(), 0 );
    QDataStream stream( &buffer, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );

    stream << (quint16)image->width() << (quint16)image->height();

    quint16 y = qrand() % image->height();

    stream << y;

    for( int x=0; x<image->width(); ++x )
    {
        QRgb rgb = image->pixel( x, y );
        stream << (quint8)qRed( rgb ) << (quint8)qGreen( rgb ) << (quint8)qBlue( rgb );
    }

    socket->writeDatagram( buffer, QHostAddress::Broadcast, 9988 );
}
