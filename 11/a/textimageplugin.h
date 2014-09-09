#include <QImageIOPlugin>
//#include <QImageIOHandler>
#include <QStringList>

class TextImagePlugin : public QImageIOPlugin
{
    public:
        TextImagePlugin();
        ~TextImagePlugin();

        QStringList keys() const;
        Capabilities capabilities( QIODevice *device, const QByteArray &format ) const;
        QImageIOHandler *create( QIODevice *device,
                const QByteArray &format = QByteArray() ) const;
};
