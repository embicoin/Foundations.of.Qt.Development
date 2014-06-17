#include <QApplication>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTreeView *tree = new QTreeView;
    QListView *list = new QListView;
    QTableView *table = new QTableView;

    QSplitter splitter;
    splitter.addWidget(tree);
    splitter.addWidget(list);
    splitter.addWidget(table);

    QStandardItemModel model(5, 2);
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 2; c++) {
            QStandardItem *item =
                new QStandardItem(QString("Row:%1, Column:%2").arg(r).arg(c));

            if (c == 0) {
                for (int i = 0; i < 3; i++) {
                    QStandardItem *child = new QStandardItem(QString("Item %1").arg(i));

                    child->setEditable(false);
                    item->appendRow(child);
                }
            }

            model.setItem(r, c, item);
        }
    }

    model.setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model.setHorizontalHeaderItem(1, new QStandardItem("Phone Number"));

    tree->setModel(&model);
    list->setModel(&model);
    table->setModel(&model);

    // only one row can be selected at one time
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    // this means that if you select something in one view, the same view will be selected in the other two as well
    //
    list->setSelectionModel(tree->selectionModel());
    table->setSelectionModel(tree->selectionModel());

    splitter.show();

    return app.exec();   
}
