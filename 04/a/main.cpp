#include "sdiwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // NOTE: if allocate window on stack, and click rightup 'X' to exit
    // it displays many errors
    //
    //SdiWindow window;
    //window.show();
    
    SdiWindow *window = new SdiWindow;
    window->show();


    return app.exec();
}
