#include <QDataStream>
#include <QDebug>
#include <QString>
#include <QColor>
#include <QFile>

struct ColorText
{
    QString text;
    QColor color;
};

QDataStream& operator<<( QDataStream& stream, const ColorText& data)
{
    stream << data.text << data.color;
    return stream;
}

QDataStream& operator>>( QDataStream& stream, ColorText& data)
{
    stream >> data.text;
    stream >> data.color;
    return stream;
}

int main( void )
{
    QList<ColorText> list;
    ColorText colortext;
    colortext.text = "Red";
    colortext.color = Qt::red;

    list << colortext;

    QFile file("test.dat");
    if( !file.open( QIODevice::WriteOnly ) )
    {
        qDebug() << "Cannot open the file";
        return -1;
    }

    QDataStream datastream( &file );
    datastream.setVersion( QDataStream::Qt_4_2 );
    datastream << list;

    file.close();

    return 0;
}
