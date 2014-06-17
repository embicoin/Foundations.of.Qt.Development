#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QDialog dlg;
    QWidget widget;

    QGridLayout layout(&widget);
    //layout.addWidget(new QPushButton("foo"), 0, 0, 1, 2);
    //layout.addWidget(new QPushButton("bar"), 1, 0);
    //layout.addWidget(new QPushButton("baz"), 1, 1);
    layout.addWidget(new QPushButton("foo"), 0, 0, 2, 1);
    layout.addWidget(new QPushButton("bar"), 0, 1);
    layout.addWidget(new QPushButton("baz"), 1, 1);


    widget.show();

    return app.exec();
}
