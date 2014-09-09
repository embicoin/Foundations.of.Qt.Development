#ifndef INCREASETHREAD_H
#define INCREASETHREAD_H

#include "textdevice.h"
#include <QThread>

extern bool stopThreads;

class IncreaseThread : public QThread
{
    public:
        IncreaseThread( TextDevice *device );
        
        void run();

    private:
        TextDevice *m_device;
};

#endif
