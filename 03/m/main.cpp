#include <QApplication>
#include "validationdailog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ValidationDialog dialog;
    dialog.show();

    return app.exec();
}
