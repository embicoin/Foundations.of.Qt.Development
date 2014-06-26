#include <QFile>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QDebug>
#include "myhandler.h"

int main( void )
{
    QFile file( "data.xml" );    
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "Failed to open file for reading.";
        return -1;
    }

    QXmlInputSource source( &file );

    MyHandler handler;
    QXmlSimpleReader reader;
    reader.setContentHandler( &handler );
    reader.parse( source );

    file.close();
    return 0;
}
