#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include "textandnumber.h"

class TextDevice : public QThread
{
    Q_OBJECT
    public:
        TextDevice();
        
        void run();
        void stop();

    public slots:
        void write( TextAndNumber tan );
        
    private:
        int m_count;
        QMutex m_mutex;
};
#endif
