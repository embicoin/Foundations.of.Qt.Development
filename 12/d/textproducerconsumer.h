#ifndef TEXTPRODUCER_H
#define TEXTPRODUCER_H

#include <QString>
#include <QThread>
#include <QSemaphore>

class TextProducer : public QThread
{
    public:
        TextProducer( const QString &text );
        void run();
    private:
        QString m_text;
};

class TextConsumer : public QThread
{
    public:
        TextConsumer();
        void run();
    private:
        QString m_text;
};

#endif
