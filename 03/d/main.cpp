#include "buttonbox.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    buttonBox window;
    window.show();

    return app.exec();
}
