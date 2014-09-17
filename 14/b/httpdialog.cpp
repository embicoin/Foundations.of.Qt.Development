#include "httpdialog.h"
#include <QUrl>
#include <QMessageBox>
#include <QFileDialog>

HttpDialog::HttpDialog() : QDialog()
{
    file = 0;

    ui.setupUi( this );

    connect( ui.getButton, SIGNAL(clicked()), this, SLOT(getClicked()) );

    connect( &http, SIGNAL(stateChanged(int)),
             this, SLOT(httpStateChanged(int)) );
    connect( &http, SIGNAL(dataSendProgress(int, int)),
             this, SLOT(httpDataSent(int, int)) );
    connect( &http, SIGNAL(dataReadProgress(int, int)),
             this, SLOT(httpDataReceived(int, int)) );
    connect( &http, SIGNAL(responseHeaderReceived(const QHttpResponseHeader&)),
             this, SLOT(httpHeaderDone(const QHttpResponseHeader&)) );
    connect( &http, SIGNAL(readyRead(const QHttpResponseHeader&)),
             this, SLOT(httpDataDone(const QHttpResponseHeader&)) );
    connect( &http, SIGNAL(requestStarted(int)),
             this, SLOT(httpStarted(int)) );
    connect( &http, SIGNAL(requestFinished(int, bool)),
             this, SLOT(httpFinished(int, bool)) );
    connect( &http, SIGNAL(done(bool)),
             this, SLOT(httpDone(bool)) );
}

void HttpDialog::getClicked()
{
    QUrl url( ui.requestEdit->text(), QUrl::TolerantMode );

    if( !url.isValid() )
    {
        ui.hostLabel->clear();
        ui.pathLabel->clear();
        ui.portLabel->clear();
        ui.userLabel->clear();
        ui.passwordLabel->clear();
        QMessageBox::warning( this, tr("Invalid URL"),
                tr("The URL '%1' is invalid.").arg( ui.requestEdit->text() ) );
        return;
    }

    ui.hostLabel->setText( url.host() );
    ui.pathLabel->setText( url.path() );
    ui.portLabel->setText( QString::number(url.port()==-1 ? 80 : url.port()) );
    ui.userLabel->setText( url.userName() );
    ui.passwordLabel->setText( url.password() );

    http.setHost( url.host(), url.port()==-1 ? 80 : url.port() );
    if( !url.userName().isEmpty() )
        http.setUser( url.userName(), url.password() );

    QString fileName = QFileDialog::getSaveFileName( this );
    if( fileName.isEmpty() )
        return;

    file = new QFile( fileName, this );
    if( !file->open( QIODevice::WriteOnly | QIODevice::Truncate ) )
    {
        QMessageBox::warning( this, tr("Could not write"),
                tr("Could not open the file %f for writing.").arg( fileName ) );
        delete file;
        file = 0;
        return;
    }

    http.get( url.path(), file );
    ui.getButton->setEnabled( false );
}

void HttpDialog::httpStateChanged( int state )
{
    QString s = "State changed, (";
    switch( state )
    {
        case QHttp::Unconnected:
            ui.statusList->addItem( s + QString("unconnected)") );
            break;
        case QHttp::HostLookup:
            ui.statusList->addItem( s + QString("host lookup)"));
            break;
        case QHttp::Connecting:
            ui.statusList->addItem( s + QString("connecting)"));
            break;
        case QHttp::Sending:
            ui.statusList->addItem( s + QString("sending)"));
            break;
        case QHttp::Reading:
            ui.statusList->addItem( s + QString("reading)"));
            break;
        case QHttp::Connected:
            ui.statusList->addItem( s + QString("connected)"));
            break;
        case QHttp::Closing:
            ui.statusList->addItem( s + QString("closing)"));
            break;
        default:
            break;
    }
}

void HttpDialog::httpDataSent( int done, int total )
{}

void HttpDialog::httpDataReceived( int done, int total )
{}

void HttpDialog::httpHeaderDone( const QHttpResponseHeader& qhrd )
{}

void HttpDialog::httpDataDone( const QHttpResponseHeader& qhrd )
{}

void HttpDialog::httpStarted(int)
{}

void HttpDialog::httpFinished(int, bool)
{}

void HttpDialog::httpDone( bool error )
{
    ui.statusList->addItem( QString("done( %1 )").arg( error ? "True" : "False" ) );

    if( error )
    {
        QMessageBox::warning( this, tr("Http: done"), http.errorString() );

        if( file )
        {
            file->close();
            file->remove();

            delete file;
            file = 0;
        }
    }

    if ( file )
    {
        file->close();

        delete file;
        file = 0;
    }
}
