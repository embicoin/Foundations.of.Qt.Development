#include "clientdialog.h"
#include <QBuffer>
#include <QImageReader>
#include <QMessageBox>

ClientDialog::ClientDialog() : QDialog() 
{
    ui.setupUi( this );

    connect( ui.getButton, SIGNAL(clicked()), this, SLOT(getClicked()) );

    connect( &socket, SIGNAL(error(QAbstractSocket::SocketError)),
             this, SLOT(tcpError(QAbstractSocket::SocketError)) );
    connect( &socket, SIGNAL(readyRead()),
             this, SLOT(tcpReady()) );
}

void ClientDialog::getClicked()
{
    ui.getButton->setEnabled( false );
    
    ui.imageLabel->setPixmap( QPixmap() );
    ui.imageLabel->setText( tr("<i>Getting image...</i>") );

    dataSize = 0;

    socket.abort();

    qDebug() << ui.serverEdit->text();
    socket.connectToHost( ui.serverEdit->text(), 9876 );
    //socket.connectToHost( "localhost", 80 );
}

void ClientDialog::tcpReady()
{
    if( dataSize == 0 )
    {
        QDataStream stream( &socket );
        stream.setVersion( QDataStream::Qt_4_0 );
        if( socket.bytesAvailable() < sizeof(quint32) ) 
            return;

        stream >> dataSize;
    }

    if( dataSize > socket.bytesAvailable() )
    {
        qDebug() << "dataSize greater than max bytes";
        return;
    }

    QByteArray array = socket.read( dataSize );
    QBuffer buffer( &array );
    buffer.open( QIODevice::ReadOnly);

    QImageReader reader( &buffer, "PNG" );
    QImage image = reader.read();

    if( !image.isNull() )
    {
        ui.imageLabel->setPixmap( QPixmap::fromImage( image ) );
        //ui.imageLabel->clear();
    }
    else
    {
        ui.imageLabel->setText( tr("<i>Invalid image received!</i>") );
    }
    ui.getButton->setEnabled( true );
}

void ClientDialog::tcpError( QAbstractSocket::SocketError error )
{
    if( error == QAbstractSocket::RemoteHostClosedError )
        return;

    QMessageBox::warning( this, tr("Error"),
                          tr("TCP error: %1").arg( socket.errorString() ) );
    ui.imageLabel->setText( tr("<i>No Image</i>") );
    ui.getButton->setEnabled( true );
}
