#include <QApplication>
#include <QSet>
#include <QDebug>

int main(void)
{
    QSet<QString> set;

    set << "Ada" << "C++" << "Ruby";

    for (QSet<QString>::ConstIterator ii = set.begin(); ii != set.end(); ++ii)
        qDebug() << *ii;

    if (set.contains("FORTRAN"))
        qDebug() << "FORTRAN is in the set.";
    else
        qDebug() << "FORTRAN is out.";

    return 0;
}

