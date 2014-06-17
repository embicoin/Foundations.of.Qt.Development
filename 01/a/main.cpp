#include <QApplication>
#include <QTextStream>
#include "signal_slot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QObject parent;
    MyClass *a, *b, *c;

    a = new MyClass("foo", &parent);
    b = new MyClass("bar", &parent);
    c = new MyClass("baz", &parent);

    QObject::connect(
            a, SIGNAL(textChanged(const QString&)),
            b, SLOT(setText(const QString&)));
    QObject::connect(
            b, SIGNAL(textChanged(const QString&)),
            c, SLOT(setText(const QString&)));
    QObject::connect(
            c, SIGNAL(textChanged(const QString&)),
            b, SLOT(setText(const QString&)));

    //a->setText("text");
    //b->setText("text");

    QTextStream out(stdout);
    out << "a: " << a->text() << endl;
    out << "b: " << b->text() << endl;
    out << "c: " << c->text() << endl;

    //return app.exec();
    return 0;
}
