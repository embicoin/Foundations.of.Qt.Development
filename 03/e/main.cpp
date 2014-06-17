#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDialog dlg;

    QLabel *fooLabel = new QLabel("&Foo:");
    QLabel *barLabel = new QLabel("&Bar:");
    QLineEdit *fooEdit = new QLineEdit;
    QLineEdit *barEdit = new QLineEdit;

    fooLabel->setBuddy(fooEdit);
    barLabel->setBuddy(barEdit);

    QGridLayout *layout = new QGridLayout(&dlg);
    layout->addWidget(fooLabel, 0, 0);
    layout->addWidget(fooEdit, 0, 1);
    layout->addWidget(barLabel, 1, 0);
    layout->addWidget(barEdit, 1, 1);

    dlg.show();

    return app.exec();
}
