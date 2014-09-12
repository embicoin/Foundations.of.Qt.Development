#include <QSqlDatabase>
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDir>
#include <QtSql>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    //db.setDatabaseName( QDir::homePath() + QDir::separator() + "testdatabase.db" );
    db.setDatabaseName( "testdatabase.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    // SQLite doesn't need hostname and username and password, no server either. It only needs one file, if db file not exist, it'll create one.
    QSqlQuery qry;

    // QSqlQuery::prepare is used to deal with the input from users
    qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, "
            "firstname VARCHAR(30), "
            "lastname VARCHAR(30))" );
    if( !qry.exec() )
    {
        qDebug() << "Failed to create the table" << qry.lastError();
    }

    qry.prepare("INSERT INTO names (id, firstname, lastname) "
            "VALUES (:id, :firstname, :lastname)" );
    qry.bindValue( ":id", 9 );
    qry.bindValue( ":firstname", "Ralph" );
    qry.bindValue( ":lastname", "Roe" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
    }

    if( !qry.exec("SELECT firstname, lastname FROM names "
                "WHERE lastname = 'Roe' ORDER BY firstname" ) )
    {
        qDebug() << qry.lastError();
    }

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
