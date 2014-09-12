#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    // SQLite doesn't need hostname and username and password, no server either. It only needs one file, if db file not exist, it'll create one.
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );

    db.setDatabaseName( "testdatabase.db" );
    // if specify the file name as ':memory:', then the database will exist only in memory instead of writing to file. 
    //db.setDatabaseName( ":memory:" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    QSqlQuery qry;
    if( !qry.exec( "SELECT firstname, lastname FROM names "
                "WHERE lastname = 'Roe' ORDER BY firstname" ) )
        qDebug() << qry.lastError();

    QSqlRecord rec = qry.record();
    int cols = rec.count();

    QString temp;
    for( int c=0; c<cols; c++ )
        temp += rec.fieldName(c) + ((c<cols-1)?"\t":"");
    qDebug() << temp;

    while( qry.next() )
    {
        temp = "";
        for( int c=0; c<cols; c++ )
            temp += qry.value(c).toString() + ((c<cols-1)?"\t":"");
        qDebug() << temp;

    }

    db.close();

    return 0;
}
