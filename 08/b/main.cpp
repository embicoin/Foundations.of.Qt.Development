#include <QFile>
#include <QDebug>

int main( void )
{
    QFile file( "testfile.txt" );

    if( !file.exists() )
    {
        qDebug() << "The file of " << file.fileName() << "does not exist";
        return -1;
    }

    if( !file.open(QIODevice::WriteOnly) )
    {
        qDebug() << "Cannot write the file";
        return -1;
    }

    qDebug() << "Success";

    file.close();

    return 0;
}
