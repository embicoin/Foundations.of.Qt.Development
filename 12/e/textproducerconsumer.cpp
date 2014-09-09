#include "textproducerconsumer.h"
#include <QDebug>
#include <QMutex>

const int bufferSize = 20;
// noThreads must be equal to the number of producers
const int noThreads = 2;

QChar buffer[ bufferSize ];
QSemaphore freeSpace( bufferSize );
QSemaphore availableData( 0 );

QSemaphore atEnd(noThreads);

TextProducer::TextProducer( const QString &text )
{
    m_text = text;
}

void TextProducer::run()
{
    static int index = 0;
    static QMutex indexMutex;

    for( int i=0; i<m_text.length(); ++i )
    {
        freeSpace.acquire();
        indexMutex.lock();
        buffer[ index++ % bufferSize ] = m_text[i];
        indexMutex.unlock();

        if( i == m_text.length()-1 )
            //atEnd = true;
            atEnd.acquire();

        availableData.release();
    }
}

TextConsumer::TextConsumer()
{
    //m_text = text;
}

void TextConsumer::run()
{
    int i = 0;
    // QSemaphore::availableData():
    // returns the number of available semaphores
    while( atEnd.available() || availableData.available() )
    {
        availableData.acquire();
        qDebug() << buffer[ i ];
        i = (i+1) % bufferSize;
        freeSpace.release();
    }
}
