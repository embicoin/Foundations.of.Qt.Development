#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    bool ok;
    QStringList items;
    items << "Foo" << "Bar" << "Baz";
    QString item = QInputDialog::getItem(
            0,
            "Item",
            "Pick an item:",
            items,
            0,
            false,
            &ok);

    if (ok && !item.isEmpty())
    {
    
    }

    return app.exec();
}
