#include "textproducerconsumer.h"
#include <QDebug>

const int bufferSize = 20;

QChar buffer[ bufferSize ];
QSemaphore freeSpace( bufferSize );
QSemaphore availableData( 0 );

bool atEnd = false;

TextProducer::TextProducer( const QString &text )
{
    m_text = text;
}

void TextProducer::run()
{
    for( int i=0; i<m_text.length(); ++i )
    {
        freeSpace.acquire();
        buffer[ i % bufferSize ] = m_text[i];

        if( i == m_text.length()-1 )
            atEnd = true;

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
    while( !atEnd || availableData.available() )
    {
        availableData.acquire();
        qDebug() << buffer[ i ];
        i = (i+1) % bufferSize;
        freeSpace.release();
    }
}
