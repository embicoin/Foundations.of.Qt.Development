#include "listwidgetdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ListWidgetDialog window;
    window.show();

    return app.exec();
}
