#include "qpushbutton.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ButtonDialog window;
    window.show();

    return app.exec();
}
