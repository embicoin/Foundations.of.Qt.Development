#include <QApplication>
#include <QMap>
#include <QDebug>


int main(void)
{
    QMap<QString, int> map;
    map["foo"] = 42;
    map["bar"] = 13;
    map["baz"] = 9;
    foreach(QString key, map.keys())
        qDebug() << key << "=" << map[key];

    QMap<QString, int>::ConstIterator ii;
    for ( ii = map.constBegin(); ii != map.constEnd(); ++ii)
        qDebug() << ii.key() << "=" << ii.value();

    int sum = map["foo"] + map["ingenting"];
    qDebug() << sum;
    qDebug() << map["ingenting"];
    qDebug() << map.value("ingenting");

    return 0;
}
