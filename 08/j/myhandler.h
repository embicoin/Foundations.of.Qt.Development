#include <QXmlAttributes>
#include <QString>

class MyHandler : public QXmlDefaultHandler
{
    public:
        //bool startDocument();
        //bool endDocument();
        
        bool startElement( const QString &namespaceURI,
                const QString &localName,
                const QString &qName,
                const QXmlAttributes &atts );

        bool endElement( const QString &namespaceURI,
                const QString &localName,
                const QString &qName );

        //bool characters( const QString &ch );
};
