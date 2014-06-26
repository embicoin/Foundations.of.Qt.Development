#include <QFile>
#include <QDomDocument>
#include <QDebug>

void traverse( const QDomNode& n );

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

    QDomNodeList elements = documentElement.elementsByTagName( "Author" );
    if( elements.isEmpty() )
    {
        QDomElement a = document.createElement( "Author" );
        documentElement.insertBefore( a, QDomNode() );

    }
    //else if( elements.size() == 1 )
    else
    {
        QDomElement a = elements.at(0).toElement();

        QDomElement r = document.createElement( "revision" );
        r.setAttribute( "count",
                QString::number(
                    a.elementsByTagName( "revision" ).size() + 1 ) );

        a.appendChild( r );
    }

    QDomNode node = documentElement.firstChild();
    traverse( node );

    return 0;
}

void traverse( const QDomNode &n )
{
    if( n.isNull() )
        return;

    traverse( n.firstChild() );

    QDomNode n2 = n;

    while( !n2.isNull() )
    {
        if( n2.isElement() )
        {
            QDomElement element = n2.toElement();
            qDebug() << "tag name: " << element.tagName();
            qDebug() << "name: " << element.attribute("name");
            qDebug() << "count: " << element.attribute("count");
        }

        if( n2.isText() )
        {
            QDomText text = n2.toText();
            qDebug() << "text: " << text.data();
        }

        n2 = n2.nextSibling();
    }
}
