#ifndef TEXTDEVICE_H
#define TEXTDEVICE_H

#include <QMutex>

class TextDevice
{
    public:
        TextDevice();

        void write( const QString& );
        
    private:
        int count;
        QMutex mutex;
};
#endif
