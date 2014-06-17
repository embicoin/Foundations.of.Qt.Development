#include <QApplication>
#include <QHash>
#include <QDebug>

class Person
{
    public:
        Person(const QString& name, const QString& number);

        const QString& name() const;
        const QString& number() const;

    private:
        QString m_name;
        QString m_number;
};

Person::Person(const QString& name, const QString& number)
{
    m_name = name;
    m_number = number;
}

const QString& Person::name() const
{
    return m_name;
}

const QString& Person::number() const
{
    return m_number;
}

bool operator==(const Person &a, const Person &b)
{
    return ((a.name() == b.name()) && (a.number() == b.number()));
}

uint qHash(const Person &key)
{
    return qHash(key.name()) ^ qHash(key.number());
}

int main(void)
{
    QHash<Person, int> hash;

    hash[Person("Anders", "8447070")] = 10;
    hash[Person("Micke", "7728433")] = 20;

    qDebug() << hash.value(Person("Anders", "8447070"));
    qDebug() << hash.value(Person("Anders", "8447071"));
    qDebug() << hash.value(Person("Micke", "7728433"));
    qDebug() << hash.value(Person("Michael", "7728433"));

    return 0;

}
