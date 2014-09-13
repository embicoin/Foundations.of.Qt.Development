#include <QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv );

    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "testdatabase.db" );

    if( !db.open() )
    {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
    }

    QSqlQuery qry;
    qry.prepare( "CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, "
            "firstname VARCHAR(30), "
            "lastname VARCHAR(30))" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
        qFatal( "Failed to create the table" );
    }

    qry.prepare( "INSERT INTO names (id, firstname, lastname) "
            "VALUES (:id, :firstname, :lastname)" );
    qry.bindValue( ":id", 1 );
    qry.bindValue( ":firstname", "John" );
    qry.bindValue( ":lastname", "Doe" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
        qFatal( "Failed to insert" );
    }

    qry.prepare( "CREATE TABLE IF NOT EXISTS salaries (id INTEGER UNIQUE PRIMARY KEY, "
            "annual INTEGER)" );
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
        qFatal( "Failed to create table of salaries" );
    }

    qry.prepare( "INSERT INTO salaries (id, annual) "
            "VALUES (:id, :annual)" );
    qry.bindValue( ":id", 1 );
    qry.bindValue( ":annual", 300000 );
    if( !qry.exec() )
    {
        qDebug() << qry.lastError();
        qFatal( "Failed to insert into table of salaries" );
    }

    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    
    model->setTable( "names" );
    // param:
    // 1: the table to be joined with
    // 2: the key used to be corresponded
    // 3: the column we want to get
    model->setRelation( 0, QSqlRelation( "salaries", "id", "annual" ) );
    model->select();

    model->setHeaderData( 0, Qt::Horizontal, QObject::tr("Annual Pay") );
    model->setHeaderData( 1, Qt::Horizontal, QObject::tr("First Name") );
    model->setHeaderData( 2, Qt::Horizontal, QObject::tr("Last Name") );

    QTableView *view = new QTableView();
    //view->setColumnHidden( 0, true );
    view->setModel( model );
    view->show();

    return app.exec();
}
