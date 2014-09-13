#ifndef IMAGECOLLECTION_H
#define IMAGECOLLECTION_H

#include <QImage>
#include <QList>
#include <QStringList>

class ImageCollection
{
    public:
        ImageCollection();

        QImage getImage( int id );
        QList<int> getIds( QStringList tags );
        QStringList getTags();

        void addTag( int id, QString tag );
        void addImage( QImage, QStringList tags );

    private:
        void populateDatabase();
};

#endif
