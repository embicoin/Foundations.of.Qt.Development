#include "listener.h"

Listener::Listener( QWidget *parent ) : QLabel( parent )
{
    setText( "Waiting for data." );

    image = 0;

    socket = new QUdpSocket( this );
    socket->bind( 9988 );

    connect( socket, SIGNAL(readyRead()), this, SLOT(dataPending()) );
}

void Listener::dataPending()
{
    while( socket->hasPendingDatagrams() )
    {
        QByteArray buffer( socket->pendingDatagramSize(), 0 );
        socket->readDatagram( buffer.data(), buffer.size() );

        QDataStream stream( buffer );
        stream.setVersion( QDataStream::Qt_4_0 );

        quint16 width, height, y;
        stream >> width >> height >> y;

        if( !image )
            image = new QImage( width, height, QImage::Format_RGB32 );
        else if( image->width() != width || image->width() != height )
        {
            delete image;
            image = new QImage( width, height, QImage::Format_RGB32 );
        }

        for( int x=0; x<width; ++x )
        {
            quint8 red, green, blue;
            stream >> red >> green >> blue;
            image->setPixel( x, y, qRgb( red, green, blue ) );
        }
    }

    setText( "" );
    setPixmap( QPixmap::fromImage( *image ) );
    resize( image->size() );
}
