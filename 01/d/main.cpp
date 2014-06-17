#include <QApplication>
#include <QList>
#include <QDebug>


int main(void)
{
    QList<int> list;
    list << 23 << 27 << 52 << 52;

    QListIterator<int> javaIter(list);
    while (javaIter.hasNext())
        qDebug() << javaIter.next();

    QList<int>::const_iterator stlIter;
    for (stlIter = list.begin(); stlIter != list.end(); ++stlIter)
        qDebug() << (*stlIter);

    QList<int>::ConstIterator stlIter2;
    for (stlIter2 = list.begin(); stlIter2 != list.end(); ++stlIter2)
        qDebug() << (*stlIter2);

    foreach(int s, list)
        qDebug() << s;
    return 0;
}

