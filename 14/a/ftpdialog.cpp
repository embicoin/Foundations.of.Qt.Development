#include "ftpdialog.h"
#include <QMessageBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QString>
#include <QDebug>

FtpDialog::FtpDialog() : QDialog()
{
    file = 0;

    ui.setupUi( this );

    connect( ui.connectButton, SIGNAL(clicked()),
             this, SLOT(connectClicked()) );
    connect( ui.disconnectButton, SIGNAL(clicked()),
             this, SLOT(disconnectClicked()) );
    connect( ui.cdButton, SIGNAL(clicked()),
             this, SLOT(cdClicked()) );
    connect( ui.upButton, SIGNAL(clicked()),
             this, SLOT(upClicked()) );
    connect( ui.getButton, SIGNAL(clicked()),
             this, SLOT(getClicked()) );

    connect( ui.dirList, SIGNAL(itemSelectionChanged()),
             this, SLOT(selectionChanged()) );

    connect( &ftp, SIGNAL(commandFinished(int, bool)),
             this, SLOT(ftpFinished(int, bool)) );
    connect( &ftp, SIGNAL(listInfo(QUrlInfo)),
             this, SLOT(ftpListInfo(QUrlInfo)) );
    connect( &ftp, SIGNAL(dataTransferProgress(qint64, qint64)),
             this, SLOT(ftpProgress(qint64, qint64)) );

    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    ui.getButton->setEnabled( false );
}

void FtpDialog::connectClicked()
{
    ui.connectButton->setEnabled( false );

    //ftp.connectToHost( "ftp.trolltech.com" );
    ftp.connectToHost( "ftp.informatik.hu-berlin.de" );
    
    ui.statusLabel->setText( tr("Connecting to host...") );
}

void FtpDialog::ftpFinished( int request, bool error )
{
    // Handle errors depending on the command causing it
    if( error )
    {
        // if request == ftp.currentCommand()?
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:
                QMessageBox::warning( this, tr("Error"), tr("Failed to connect to host.") );
                break;
            case QFtp::Login:
                QMessageBox::warning( this, tr("Error"), tr("Failed to login.") );
                ui.connectButton->setEnabled( true );
                break;
            case QFtp::List:
                QMessageBox::warning( this, tr("Error"),
                        tr("Failed to get file list.\nClosing connection.") );
                ftp.close();
                break;
            case QFtp::Cd:
                QMessageBox::warning( this, tr("Error"),
                        tr("Failed to change dir.") );
                getFileList();
                break;
            case QFtp::Get:
                QMessageBox::warning( this, tr("Error"), tr("Failed to get file?") );
                file->close();
                file->remove();

                delete file;
                file = 0;

                ui.disconnectButton->setEnabled( true );
                ui.upButton->setEnabled( true );
                selectionChanged();

                break;
            default:
                break;
        }

        ui.statusLabel->setText( tr("Ready.") );
    }
    // React to the cuurent command and issue
    // more commands or update the user inerface
    else
    {
        switch( ftp.currentCommand() )
        {
            case QFtp::ConnectToHost:
                ftp.login();
                break;
            case QFtp::Login:
                getFileList();
                break;
            case QFtp::Close: // close the connection
                ui.connectButton->setEnabled( true );
                getFileList();
                break;
            case QFtp::List:
                ui.disconnectButton->setEnabled( true );
                ui.upButton->setEnabled( true );
                ui.statusLabel->setText( tr("Ready") );
                break;
            case QFtp::Cd:
                getFileList();
                break;
            case QFtp::Get:
                file->close();

                delete file;
                file = 0;

                ui.disconnectButton->setEnabled( true );
                ui.upButton->setEnabled( true );
                selectionChanged();

                ui.statusLabel->setText( tr("Ready") );

                break;
            default:
                break;
        }
    }
}

void FtpDialog::getFileList()
{
    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    ui.getButton->setEnabled( false );

    ui.dirList->clear();
    files.clear();

    if( ftp.state() == QFtp::LoggedIn )
        ftp.list();
}

// during the execution of ftp.list(), ftpListInfo will be
// called for each file or folder
void FtpDialog::ftpListInfo( const QUrlInfo &info )
{
    ui.dirList->addItem( info.name() );
    if( info.isFile() )
        files << info.name();
}

void FtpDialog::disconnectClicked()
{
    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    ui.getButton->setEnabled( false );

    ftp.close();
}

void FtpDialog::selectionChanged()
{
    if( !ui.dirList->selectedItems().isEmpty() )
    {
        if( files.indexOf( ui.dirList->selectedItems()[0]->text() ) == -1 )
        {
            ui.cdButton->setEnabled( ui.disconnectButton->isEnabled() );
            ui.getButton->setEnabled( false );
        }
        else
        {
            ui.cdButton->setEnabled( false );
            ui.getButton->setEnabled( ui.disconnectButton->isEnabled() );
        }
    }
    else
    {
        ui.cdButton->setEnabled( false );
        ui.getButton->setEnabled( false );
    }
}

void FtpDialog::cdClicked()
{
    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    // Only when the selected item is a file, is the get button
    // enabled
    // ui.getButton->setEnabled( false );
    //
    // As only one item can be selected once,
    // the selectedItems[0] is the one selected
    ftp.cd( ui.dirList->selectedItems()[0]->text() );
    ui.statusLabel->setText( tr("Changing directory...") );
}

void FtpDialog::upClicked()
{
    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    ui.getButton->setEnabled( false );

    ftp.cd("..");
    ui.statusLabel->setText( tr("Changing directory... ") );
}

void FtpDialog::getClicked()
{
    QString fileName =
        QFileDialog::getSaveFileName( this, tr("Get File"),
                                      ui.dirList->selectedItems()[0]->text() );

    if( fileName.isEmpty() )
        return;

    file = new QFile( fileName, this );
    if( !file->open( QIODevice::WriteOnly | QIODevice::Truncate ) )
    {
        QMessageBox::warning( this, tr("Error"),
                tr("Failed to open file %1 for writing.").arg( fileName ) );

       delete file; 
       file = 0;

       return;
    }

    ui.disconnectButton->setEnabled( false );
    ui.cdButton->setEnabled( false );
    ui.upButton->setEnabled( false );
    ui.getButton->setEnabled( false );

    ftp.get( ui.dirList->selectedItems()[0]->text(), file );
    ui.statusLabel->setText( tr("Downloading file.") );
}

void FtpDialog::ftpProgress( qint64 done, qint64 total )
{
    if( total == 0)
        return;

    ui.statusLabel->setText(
            tr("Downloading file..(%1)")
            .arg( QString::number( done*100.0/total, 'f', 1 ) ) );
}
