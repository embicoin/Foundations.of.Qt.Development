#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>
#include <QProcess>
#include "ui_processdialog.h"

class ProcessDialog : public QDialog
{
    Q_OBJECT

    public:
        ProcessDialog();
        ~ProcessDialog();

    private slots:
        void runUic(void);

        void handleError( QProcess::ProcessError );
        void handleFinish( int, QProcess::ExitStatus );
        void handleReadStandardError();
        void handleReadStartardOutput();
        void handleStarted();
        void handleStateChange( QProcess::ProcessState );

    private:
        QProcess *process;

        Ui::ProcessDialog ui;
};

#endif
