#include "textthread.h"
#include <QDebug>
#include <QMutex>
#include <QTextStream>

//bool stopThreads = false;
QMutex mutex;
//QTextStream out(stdout);

TextThread::TextThread( const QString &text ) : QThread()
{
    m_text = text;
    //m_device = device;
    m_stop = false;
    m_count = 0;
}

void TextThread::stop()
{
    m_stop = true;
}

void TextThread::run()
{
    while( !m_stop )
    {
        //m_device->write( m_text );
        emit writeText( TextAndNumber( m_count++, m_text ) );
        sleep(1);
    }
}
