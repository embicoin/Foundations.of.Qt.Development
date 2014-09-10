#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>
#include "textdevice.h"

class TextThread : public QThread
{
    Q_OBJECT

    public:
        //TextThread( const QString &text, TextDevice *device );
        TextThread( const QString &text );

        void run();
        void stop();

    signals:
        void writeText( const QString& );

    private:
        QString m_text;
        bool m_stop;
        //TextDevice *m_device;
};

#endif
