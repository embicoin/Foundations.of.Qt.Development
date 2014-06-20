#include <QApplication>
#include <QTextEdit>
#include "eventwidget.h"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QTextEdit log;
    EventWidget widget;

    QObject::connect( &widget, SIGNAL(gotEvent(const QString &)),
            &log, SLOT(append(const QString &)) );

    log.show();
    widget.show();

    return app.exec();
}
