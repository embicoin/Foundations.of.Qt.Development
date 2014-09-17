#ifndef HTTPDIALOG_H
#define HTTPDIALOG_H

#include <QDialog>
#include <QFile>
#include <QHttp>
#include "ui_httpdialog.h"

class HttpDialog : public QDialog
{
    Q_OBJECT   
    public:
        HttpDialog();

    private slots:
        void getClicked();

        void httpStateChanged(int);
        void httpDataSent(int, int);
        void httpDataReceived(int, int);
        void httpHeaderDone(const QHttpResponseHeader&);
        void httpDataDone(const QHttpResponseHeader&);
        void httpStarted(int);
        void httpFinished(int, bool);
        void httpDone(bool);

    private:
        Ui::HttpDialog ui;
        QHttp http;
        QFile *file;

};

#endif
