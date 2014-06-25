#include <QDir>
#include <QFileInfo>
#include <QDebug>

int main( void )
{
    foreach( QFileInfo drive, QDir::drives() )
    {
        qDebug() << "Drives: "<< drive.absolutePath();
        QDir dir = drive.dir();
        dir.setFilter( QDir::Dirs );
        foreach( QFileInfo rootDir, dir.entryInfoList() )
            qDebug() << rootDir.fileName();
    }
    return 0;
}
