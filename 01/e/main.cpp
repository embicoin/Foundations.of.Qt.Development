#include <QApplication>
#include <QList>
#include <QDebug>


int main(void)
{
    QList<int> list;
    list << 23 << 27 << 52 << 52;

    QMutableListIterator<int> javaIter(list);
    while (javaIter.hasNext())
    {
        int value = javaIter.next() + 1;
        javaIter.setValue(value);
        qDebug() << value;
    }

    QList<int>::Iterator stlIter;
    for (stlIter = list.begin(); stlIter != list.end(); ++stlIter)
    {
        (*stlIter) = (*stlIter) * 2;
        qDebug() << (*stlIter);
    }

    for (int i = 0; i < 4; i++)
    {
        qDebug() << list.at(i);
    }

    return 0;
}
