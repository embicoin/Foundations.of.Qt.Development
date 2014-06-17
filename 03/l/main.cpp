#include <QRegExp>
#include <QDebug>

int main(void)
{
    QRegExp re("^\\+(\\d{1,2})\\(([089])\\)(\\d{2,5})\\-(\\d+)$");
    qDebug() << re.indexIn("+46(0)31-445566");
    qDebug() << re.indexIn("Tel: +46(0)31-445566"); // -1
    qDebug() << re.indexIn("(0)31-445566");

    qDebug() << re.indexIn("+46(0)31-445566");
    qDebug() << re.cap(0);
    qDebug() << re.cap(1);
    qDebug() << re.cap(2);
    qDebug() << re.cap(3);
    qDebug() << re.cap(4);

    return 0;
}
