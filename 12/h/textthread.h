#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>
//#include "textdevice.h"
#include "textandnumber.h"

class TextThread : public QThread
{
    Q_OBJECT

    public:
        //TextThread( const QString &text, TextDevice *device );
        TextThread( const QString &text );

        void run();
        void stop();

    signals:
        void writeText( TextAndNumber tan );

    private:
        QString m_text;
        bool m_stop;
        int m_count;
        //TextDevice *m_device;
};

#endif
