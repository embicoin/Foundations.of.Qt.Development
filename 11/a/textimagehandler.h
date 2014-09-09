#include <QImageIOHandler>

class TextImageHandler : public QImageIOHandler
{
    public:
        TextImageHandler();
        ~TextImageHandler();

        bool read( QImage *image );
        bool write( const QImage &image );

        bool cnaRead() const;
        static bool canRead( QIODevice *device );
};
