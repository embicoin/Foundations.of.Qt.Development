#include <QDataStream>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QList>
#include <QFile>

struct ColorText
{
    QString text;
    QColor color;
};

QDataStream& operator<<( QDataStream& stream, const ColorText& data )
{
    stream << data.text;
    stream << data.color;
    return stream;
}

QDataStream& operator>>( QDataStream& stream, ColorText& data )
{
    stream >> data.text;
    stream >> data.color;
    return stream;
}

int main( void )
{
    QList<ColorText> list;

    QFile file("test.dat");
    if( !file.open( QIODevice::ReadOnly ) )
    {
        qDebug() << "Cannot open the file";
    }

    QDataStream stream( &file );
    stream >> list;
    foreach( ColorText data, list )
        qDebug() << data.text << " "
        << data.color.red() << " "
        << data.color.green() << " "
        << data.color.blue() << " ";

    return 0;
}
