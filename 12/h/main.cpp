//#include "textdevice.h"
#include <QApplication>
#include "textthread.h"
#include <QMessageBox>
#include "textdialog.h"
#include <QDebug>

//extern bool stopThreads;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    qRegisterMetaType<TextAndNumber>("TextAndNumber");

    TextDialog dialog;

    TextThread foo( "Foo" );
    TextThread bar( "Bar" );

    QObject::connect( &foo, SIGNAL(writeText(TextAndNumber)),
                      &dialog, SLOT(showText(TextAndNumber)) );
    QObject::connect( &bar, SIGNAL(writeText(TextAndNumber)),
                      &dialog, SLOT(showText(TextAndNumber)) );

    foo.start();
    bar.start();
    qDebug() << "showing";

    // QDialog::exec() maintains its own event loop and returns when the dialog box is closed. QDialog::show() shows the window and returns immediately.
    dialog.exec();
    //dialog.show();

    foo.stop();
    bar.stop();

    foo.wait();
    bar.wait();

    qDebug() << "end showing";

    // As we called dialog.exec(), when we click the close button, the dialog
    // will quit. If there's another app.exec(), then no way to quit app,
    // because there is no dialog now. If we call dialog.show() instead,
    // we can call app.exec() here.
    //return app.exec();
    return 0;
}
