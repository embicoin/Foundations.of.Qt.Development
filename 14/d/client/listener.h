#ifndef LISTENER_H
#define LISTENER_H

#include <QLabel>
#include <QUdpSocket>
#include <QImage>

class Listener : public QLabel
{
    Q_OBJECT

    public:
        Listener( QWidget *parent = 0 );
    private slots:
        void dataPending();
    private:
        QUdpSocket *socket;
        QImage *image;
};

#endif
