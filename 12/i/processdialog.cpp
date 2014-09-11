#include "processdialog.h"
#include <stdio.h>
#include <QDebug>
#include <QByteArray>

ProcessDialog::ProcessDialog()
{
    ui.setupUi( this );
    connect( ui.uicButton, SIGNAL(clicked(void)),
             this, SLOT(runUic(void)) );

    process = NULL;
}

ProcessDialog::~ProcessDialog()
{
    if ( process )
        delete process;
}

void ProcessDialog::runUic(void)
{
    ui.uicButton->setEnabled( false );
    ui.textEdit->setText( "" );

    if( process )
        delete process;
    process = new QProcess( this );

    connect( process, SIGNAL(error(QProcess::ProcessError)),
             this, SLOT(handleError(QProcess::ProcessError)) );
    connect( process, SIGNAL(finished(int, QProcess::ExitStatus)),
             this, SLOT(handleFinish(int, QProcess::ExitStatus)) );
    connect( process, SIGNAL(readyReadStandardError()),
             this, SLOT(handleReadStandardError()) );
    connect( process, SIGNAL(readyReadStandardOutput()),
             this, SLOT(handleReadStartardOutput()) );
    connect( process, SIGNAL(started()),
             this, SLOT(handleStarted()) );
    connect( process, SIGNAL(stateChanged(QProcess::ProcessState)),
             this, SLOT(handleStateChange(QProcess::ProcessState)) );

    QStringList arguments;
    arguments << "-tr" << "MYTR" << "processdialog.ui";
    process->start( "uic", arguments );
}

void ProcessDialog::handleFinish( int code, QProcess::ExitStatus status )
{
    QString statusText;

    switch( status )
    {
        case QProcess::NormalExit:
            statusText = "Normal exit";
            break;
        case QProcess::CrashExit:
            statusText = "Crash exit";
            break;
        default:
            break;
    }

    ui.textEdit->append( QString( "<p><b>%1 (%2)</b><p>" )
            .arg( statusText )
            .arg( code ) );
}

void ProcessDialog::handleError( QProcess::ProcessError error )
{
    QString statusText;
    switch( error )
    {
        case QProcess::FailedToStart:
            statusText = "Failed to start";
            break;
        case QProcess::Crashed:
            statusText = "Crashed";
            break;
        case QProcess::Timedout:
            statusText = "Timeout";
            break;
        case QProcess::WriteError:
            statusText = "Write error";
            break;
        case QProcess::ReadError:
            statusText = "Read error";
            break;
        case QProcess::UnknownError:
            statusText = "Unknown error";
            break;
        default:
            statusText = "Unknown error code, check your code";
            break;
    }

    ui.textEdit->append( QString( "<p><b>%1</b><p>" ).arg( statusText ) );
}

void ProcessDialog::handleReadStandardError()
{
    QByteArray ba = process->readAllStandardError();
    QString statusText = QString(ba);
    ui.textEdit->append( QString( "<p><b>%1</b><p>").arg( statusText ) );
}

void ProcessDialog::handleReadStartardOutput()
{
    QByteArray ba = process->readAllStandardOutput();
    QString statusText = QString(ba);
    ui.textEdit->append( QString( "<p><b>%1</b><p>").arg( statusText ) );
}

void ProcessDialog::handleStarted()
{
    QString statusText("Process started");
    ui.textEdit->append( QString( "<p><b>%1</b><p>").arg( statusText ) );
}

void ProcessDialog::handleStateChange( QProcess::ProcessState state )
{
    QString statusText;

    qDebug() << "handleStateChange " << state;
    
    switch ( state )
    {
        case QProcess::NotRunning:
            statusText = "Change to NotRunning now";
            break;
        case QProcess::Starting:
            statusText = "Change to Starting now";
            break;
        case QProcess::Running:
            statusText = "Change to Running now";
            break;
        default:
            statusText = "Change to Unknown state";
    }

    ui.textEdit->append( QString( "<p><b>%1</b><p>").arg( statusText ) );
}
