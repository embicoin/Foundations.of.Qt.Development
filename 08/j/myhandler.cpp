#include "myhandler.h"
#include <QDebug>

bool MyHandler::endElement( const QString &namespaceURI, const QString &localName, const QString &qName )
{
    qDebug() << "End of element" << qName;
    return true;
}

bool MyHandler::startElement( const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts )
{
    qDebug() << "Start of element" << qName;
    for( int i = 0; i < atts.length(); i++ )
        qDebug() << " " << atts.qName(i) << "=" << atts.value(i);

    return true;
}
