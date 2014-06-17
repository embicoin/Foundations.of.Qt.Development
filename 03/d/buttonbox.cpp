#include "buttonbox.h"

buttonBox::buttonBox(QWidget *parent)
    : QWidget(parent)
{
    QDialogButtonBox *box = new QDialogButtonBox(Qt::Horizontal);

    button = new QPushButton("Ok");

    // the following two are both ok
    //connect(button, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(box, SIGNAL(accepted()), this, SLOT(okClicked()));

    box->addButton(button, QDialogButtonBox::AcceptRole);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(box);
}

void buttonBox::okClicked()
{
    QMessageBox::information(this, "status", "ok clicked");
    qDebug() << "okClicked";
}
