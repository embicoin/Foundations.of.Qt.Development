#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QListView list;
    QStringListModel model;
    QStringList strings;

    strings << "Huey" << "Dewey" << "Louie";

    model.setStringList(strings);
    list.setModel(&model);

    list.show();

    return app.exec();   
}
