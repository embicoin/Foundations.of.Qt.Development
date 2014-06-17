#include <QApplication>
#include <QGridLayout>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGroupBox box("Printting Options");

    QRadioButton *portrait = new QRadioButton("Portrait");
    QRadioButton *landscape = new QRadioButton("Landscape");
    QRadioButton *color = new QRadioButton("Color");
    QRadioButton *bw = new QRadioButton("B&W");

    QButtonGroup *orientation = new QButtonGroup(&box);
    QButtonGroup *colorBw = new QButtonGroup(&box);

    orientation->addButton(portrait);
    orientation->addButton(landscape);
    colorBw->addButton(color);
    colorBw->addButton(bw);

    QGridLayout *grid = new QGridLayout(&box);
    grid->addWidget(portrait, 0, 0);
    grid->addWidget(landscape, 0, 1);
    grid->addWidget(color, 1, 0);
    grid->addWidget(bw, 1, 1);

    box.show();

    return app.exec();
}

