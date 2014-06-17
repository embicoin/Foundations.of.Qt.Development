#include "validationdailog.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRegExp>
#include <QValidator>

ValidationDialog::ValidationDialog()
{
    QGridLayout *layout = new QGridLayout(this);

    QLineEdit *reEdit = new QLineEdit("+46(0)31-445566");

    QRegExp rx("^\\+(\\d{1,2})\\(([089])\\)(\\d{2,5})\\-(\\d+)$");
    QValidator *rxv = new QRegExpValidator(rx, this);
    reEdit->setValidator(rxv);

    QPushButton *button = new QPushButton("Close");

    layout->addWidget(new QLabel("Phone:"), 0, 0);
    layout->addWidget(reEdit, 0, 1);
    layout->addWidget(button, 1, 0, 1, 2);

    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
}
