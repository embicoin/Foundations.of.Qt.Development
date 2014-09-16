#ifndef FTPDIALOG_H
#define FTPDIALOG_H

#include <QDialog>
#include <QUrlInfo>
#include <QFtp>
#include <QFile>
#include "ui_ftpdialog.h"

class FtpDialog : public QDialog
{
    Q_OBJECT    

    public:
        FtpDialog();
        
    private slots:
        void connectClicked();
        void disconnectClicked();
        void cdClicked();
        void upClicked();
        void getClicked();

        void selectionChanged();

        void ftpFinished( int, bool );
        void ftpListInfo( const QUrlInfo& );
        void ftpProgress( qint64, qint64 );

    private:
        void getFileList();

        Ui::FtpDialog ui;

        QFtp ftp;
        QFile *file;

        QStringList files;
};

#endif
