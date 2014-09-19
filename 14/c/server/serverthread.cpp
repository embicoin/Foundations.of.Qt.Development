#include "serverthread.h"
#include <QTime>
#include <QDir>
#include <QFileInfoList>
#include <QDebug>
#include <QImage>
#include <QTcpSocket>
#include <QBuffer>
#include <QImageWriter>

QImage ServerThread::randomImage()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //QDir dir("images");
    QDir dir = QDir::current();
    //dir.setFilter( QDir::Files );
    QStringList filters;
    filters << "*.png";
    dir.setNameFilters(filters);
    QFileInfoList entries = dir.entryInfoList();

    if( entries.size() == 0 )
    {
        qDebug() << "No images to show!";
        return QImage();
    }

    return QImage( entries.at( qrand() % entries.size() ).absoluteFilePath() );
}

ServerThread::ServerThread( int descriptor, QObject *parent ) : QThread( parent )
{
    m_descriptor = descriptor;
}

void ServerThread::run()
{
    QTcpSocket socket;

    if( !socket.setSocketDescriptor( m_descriptor ) )
    {
        qDebug() << "Socket error!";
        return;
    }

    QBuffer buffer;
    QImageWriter writer( &buffer, "PNG" );
    writer.write( randomImage() );
    //writer.write( QImage("/home/debian/my_codes/foundations_of_qt_development/14/c/server/megaphone.png") );

    QByteArray data;
    QDataStream stream( &data, QIODevice::WriteOnly );
    stream.setVersion( QDataStream::Qt_4_0 );
    stream << (quint32)buffer.data().size();
    data.append( buffer.data() );

    socket.write( data );

    socket.disconnectFromHost();
    socket.waitForDisconnected();
}
