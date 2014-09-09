#include "increasethread.h"

IncreaseThread::IncreaseThread( TextDevice *device ) : QThread()
{
    m_device = device;
}

void IncreaseThread::run()
{
    while( !stopThreads )
    {
        msleep( 1200 );
        m_device->increase();
    }
}
