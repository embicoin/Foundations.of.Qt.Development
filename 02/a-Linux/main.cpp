#include <QApplication>
#include "listdialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ListDialog dlg;

    dlg.show();

    return app.exec();
}


