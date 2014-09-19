#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QAbstractSocket>
#include "ui_clientdialog.h"
#include <QTcpSocket>

class ClientDialog : public QDialog
{
    Q_OBJECT   
    public:
        ClientDialog();
    private slots:
        void getClicked();
        void tcpReady();
        void tcpError( QAbstractSocket::SocketError error );
    private:
        Ui::ClientDialog ui;

        QTcpSocket socket;
        int dataSize;
};

#endif
