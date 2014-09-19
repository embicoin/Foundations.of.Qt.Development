#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QImage>

class Sender : public QObject
{
    Q_OBJECT
    public:
        Sender();
    private slots:
        void broadcastLine();
    private:
        QUdpSocket *socket;
        QImage *image;
};

#endif
