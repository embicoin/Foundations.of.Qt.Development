#include <QFile>
#include <QTextStream>
#include <QDebug>

int main( void )
{
    QFile file( "main.cpp" );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        qDebug() << "Cannot open the file";

    QTextStream s( &file );

    while ( !s.atEnd() )
    {
        QString text;
        text = s.readLine();
        qDebug() << text;
    }

    return 0;
}
