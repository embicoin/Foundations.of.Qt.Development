#ifndef TEXTANDNUMBER_H
#define TEXTANDNUMBER_H
#include <QString>
#include <QVariant>

class TextAndNumber
{
    public:
        TextAndNumber();
        TextAndNumber( int, QString );

        int number;
        QString text;
};

Q_DECLARE_METATYPE( TextAndNumber );

#endif
