#include <QApplication>
#include <QList>
#include <QStringList>
#include <QDebug>


int main(void)
{
    QStringList list;
    list << "foo" << "bar" << "baz";

    QString all = list.join(",");

    qDebug() << all;

    list.replaceInStrings("a", "oo");

    qDebug() << list;

    list << all.split(",");

    qDebug() << list;
    return 0;
}
