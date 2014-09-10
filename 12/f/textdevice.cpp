#include "textdevice.h"
#include <QDebug>

TextDevice::TextDevice()
{
    m_count = 0;
}

void TextDevice::run()
{
    exec();
}

void TextDevice::stop()
{
    quit();
}

void TextDevice::write( const QString & text )
{
    // the mutex is locked when QMutexLocker object is constructed, and unlocked when it is destructed
    QMutexLocker locker( &m_mutex );
    qDebug() << QString( "Call %1: %2" ).arg( m_count++ ).arg( text );
}
