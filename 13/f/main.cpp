#include <QApplication>
#include <QSqlQueryModel>
#include <QTableView>
//#include <QSqlQueryModel>
#include <QSqlTableModel>
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

    QSqlTableModel *model = new QSqlTableModel();

    model->setTable( "names" );
    model->setFilter( "lastname = 'Doe'" );
    model->select();

    // if removeColumn is enabled, the table won't be editable, this
    // is a bug under this old version
    //model->removeColumn( 0 );

    QTableView *view = new QTableView();
    //view->setColumnHidden( 0, true );
    view->setModel( model );
    view->show();

    /*
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery( "SELECT firstname, lastname FROM names" );

    QTableView *view = new QTableView();
    view->setModel( model );
    view->show();
    */

    return app.exec();
}
