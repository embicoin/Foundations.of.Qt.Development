#include <QApplication>
#include "listdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ListDialog window;
    window.show();

    return app.exec();
}
