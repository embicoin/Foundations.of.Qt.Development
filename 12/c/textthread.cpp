#include "textthread.h"
#include <QDebug>
#include <QMutex>
#include <QTextStream>

bool stopThreads = false;
QMutex mutex;
QTextStream out(stdout);

TextThread::TextThread( const QString &text, TextDevice *device ) : QThread()
{
    m_text = text;
    m_device = device;
}

void TextThread::run()
{
    while( !stopThreads )
    {
        m_device->write( m_text );
        sleep(1);
    }
}
