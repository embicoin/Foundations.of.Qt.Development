#include "textimageplugin.h"

Q_EXPORT_PLUGIN2( textimageplugin, TextImagePlugin )

QImageIOPlugin::Capabilities TextImagePlugin::capabilities( QIODevice *device,
        const QByteArray &format ) const
{
    if( format == "ti" )
        return (QImageIOPlugin::CanRead | QImageIOPlugin::CanWrite);

    if( !format.isEmpty() )
        return 0;

    if( !device->isOpen() )
        return 0;

    QImageIOPlugin::Capabilities result;

    if ( device->isReadable() && TextImageHandler::canRead( device ) )
        result |= QImageIOPlugin::CanRead;

    if( device->isWritable() )
        result |= QImageIOPlugin::CanWrite;

    return result;
}

QStringList TextImagePlugin::keys() const
{
    return QStringList() << "ti";
}

QImageIOHandler *TextImagePlugin::create( QIODevice *device,
        const QByteArray &format ) const
{
    QImageIOHandler *result = new TextImageHandler();

    result->setDevice( device );
    result->setFormat( format );

    return result;
}
