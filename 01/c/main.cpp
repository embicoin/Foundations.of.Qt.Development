#include <QList>
#include <QApplication>
#include <QDebug>


int main(void)
{
    QList<QString> list;
    list << "foo" << "bar" << "baz";

    foreach(QString s, list)
        qDebug() << s;
    return 0;
}

