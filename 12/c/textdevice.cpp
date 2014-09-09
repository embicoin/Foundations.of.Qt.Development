#include "textdevice.h"
#include <QDebug>

TextDevice::TextDevice()
{
    count = 0;
}

void TextDevice::increase()
{
    QWriteLocker locker( &lock );
    count++;
}

void TextDevice::write( const QString & text )
{
    QReadLocker locker( &lock );
    qDebug() << QString( "Call %1: %2" ).arg( count++ ).arg( text );
}
