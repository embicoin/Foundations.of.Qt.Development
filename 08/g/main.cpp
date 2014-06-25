//
// pro file: QT += xml
//
#include <QDomDocument>
#include <QDebug>
#include <QDomText>
#include <QTextStream>
#include <QFile>

int main( void )
{
    QDomDocument document;
    QDomElement d = document.createElement( "Document" );
    d.setAttribute( "name", "document" );

    QDomElement a = document.createElement( "Author" );
    a.setAttribute( "name", "author");
    QDomText text = document.createTextNode( "Some text" );

    document.appendChild(d);
    d.appendChild(a);
    d.appendChild(text);


    QFile file( "data.xml" );
    if( !file.open( QIODevice::WriteOnly ) )
    {
        qDebug() << "Cannot open the file";
    }

    QTextStream stream( &file );

    stream << document.toString();

    file.close();

    return 0;
}
