#include "textimagehandler.h"
#include <QTextStream>
#include <QImage>

bool TextImageHandler::write( const QImage &image )
{
    QTextStream stream( device() );

    stream << "TEXT\n";
    stream << image.width() << "x" << image.height() << "\n";
    for( int y=0; y<image.height(); ++y)
    {
        for( int x=0; x<image.width(); ++x)
        {
            QRgb rgb = image.pixel( x, y );
            int r = rgb & 0xff;
            int g = (rgb >> 8) & 0xff;
            int b = (rgb >> 16) & 0xff;

            stream << map[ 7 - (((r + g + b)/3)>>5) & 0x7 ];
        }
        stream << "\n";
    }

    if( stream.status() != QTextStream::Ok )
        return false;

    return true;
}

bool TextImageHandler::read( QImage *image )
{
    QTextStream stream( device() );
    QString line;

    line = stream.readLine();
    if( line != "TEXT" || stream.status() != QTextStream::Ok )
        return false;

    line = stream.readLine();
    QRegExp re( "(\\d+)x(\\d+)" );
    int width, height;
    if( re.exactMatch( line ) )
    {
        bool ok;

        width = re.cap(1).toInt( &ok );
        if( !ok )
            return false;

        height = re.cap(2).toInt( &ok );
        if( !ok )
            return false;
    }
    else
        return false;

    QImage result( width, height, QImage::Format_ARGB32 );

    for( int y=0; y<height; ++y )
    {
        line = stream.readLine();
        if( line.length() != width )
            return false;

        for( int x=0; x<width; ++x)
        {
            switch( QString(map).indexOf(line[x]) )
            {
                case 0:
                    result.setPixel( x, y, 0xffffffff );
                    break;
                case 1:
                    result.setPixel( x, y, 0xffdfdfdf );
                    break;
                case 2:
                    result.setPixel( x, y, 0xffbfbfbf );
                    break;
                case 3:
                    result.setPixel( x, y, 0xff9f9f9f );
                    break;
                case 4:
                    result.setPixel( x, y, 0xff7f7f7f );
                    break;
                case 5:
                    result.setPixel( x, y, 0xff5f5f5f );
                    break;
                case 6:
                    result.setPixel( x, y, 0xff3f3f3f );
                    break;
                case 7:
                    result.setPixel( x, y, 0xff000000 );
                    break;
                default:
                    return false;
            }
        }
    }

    if( stream.status() != QTextStream::Ok )
        return false;

    *image = result;

    return true;
}

bool TextImageHandler::canRead( QIODevice *device )
{
    if( device->peek(4) == "TEXT")
        return true;

    return false;
}

bool TextImageHandler::canRead() const
{
    return TextImageHandler::canRead( device() );
}
