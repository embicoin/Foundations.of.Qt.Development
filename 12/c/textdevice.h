#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QReadWriteLock>

class TextDevice
{
    public:
        TextDevice();

        void increase();

        void write( const QString& );
        
    private:
        int count;
        QReadWriteLock lock;
};
#endif
