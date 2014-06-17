#include "qpushbutton.h"

ButtonDialog::ButtonDialog(QWidget *parent)
    : QDialog(parent)
{
    clickButton = new QPushButton("Click", this);
    toggleButton = new QPushButton("Toggle", this);
    toggleButton->setCheckable(true);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(clickButton);
    layout->addWidget(toggleButton);

    connect(clickButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(toggleButton, SIGNAL(clicked()), this, SLOT(buttonToggled()));
}

void ButtonDialog::buttonClicked()
{
    QMessageBox::information(this, "Clicked", "The button was clicked");
}

void ButtonDialog::buttonToggled()
{
    QMessageBox::information(this, "Toggled",
            QString("The button is %1")
            .arg(toggleButton->isChecked() ? "pressed" : "released"));
}
