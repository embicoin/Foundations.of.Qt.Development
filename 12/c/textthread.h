#ifndef TEXTTHREAD_H
#define TEXTTHREAD_H

#include <QThread>
#include <QString>
#include "textdevice.h"

class TextThread : public QThread
{
    public:
        TextThread( const QString &text, TextDevice *device );

        void run();

    private:
        QString m_text;
        TextDevice *m_device;
};

#endif
