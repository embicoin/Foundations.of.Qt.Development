#include "textthread.h"
#include <QDebug>
#include <QMutex>
#include <QTextStream>

bool stopThreads = false;
QMutex mutex;
QTextStream out(stdout);

TextThread::TextThread( const QString &text ) : QThread()
{
    m_text = text;
}

void TextThread::run()
{
    while( !stopThreads )
    {
        mutex.lock();
        
        if( stopThreads ) {
            mutex.unlock();
            return;
        }
        qDebug() << m_text;
        //out << m_text << endl;
        sleep( 1 );
        mutex.unlock();
    }
}
