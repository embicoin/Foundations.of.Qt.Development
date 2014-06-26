#include <QFile>
#include <QDomDocument>
#include <QDebug>

int main( void )
{
    QFile file( "data.xml" );
    if( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "Cannot open file for reading.";
        return -1;
    }

    QDomDocument document;
    if ( !document.setContent( &file ) )
    {
        qDebug() << "Failed to parse the file into a DOM tree.";
        file.close();
        return -1;
    }

    file.close();

    QDomElement documentElement = document.documentElement();

    QDomNode node = documentElement.firstChild();

    while( !node.isNull() )
    {
        if( node.isElement() )
        {
            QDomElement element = node.toElement();
            qDebug() << element.tagName();
            qDebug() << element.attribute("name");
        }
        
        if( node.isText() )
        {
            QDomText text = node.toText();
            qDebug() << text.data();
        }

        node = node.nextSibling();
    }

    return 0;
}
