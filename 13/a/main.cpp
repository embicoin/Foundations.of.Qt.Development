#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QSqlError>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL");

    db.setHostName( "localhost" );
    db.setDatabaseName( "qtbook" );

    db.setUserName( "user" );
    db.setPassword( "password" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    db.close();

    return app.exec();
}
