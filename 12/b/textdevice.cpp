#include "textdevice.h"
#include <QDebug>

TextDevice::TextDevice()
{
    count = 0;
}

void TextDevice::write( const QString & text )
{
    // the mutex is locked when QMutexLocker object is constructed, and unlocked when it is destructed
    QMutexLocker locker( &mutex );
    qDebug() << QString( "Call %1: %2" ).arg( count++ ).arg( text );
}
