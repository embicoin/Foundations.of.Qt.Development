#include <QApplication>
#include <QDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDialog dlg;
    QGroupBox *groupBox = new QGroupBox("GroupBox");
    QLabel *label = new QLabel("Super.........................");
    QLineEdit *lineEdit = new QLineEdit;
    QDialogButtonBox *buttons =
        new QDialogButtonBox(QDialogButtonBox::Ok |
                QDialogButtonBox::Cancel);

    QHBoxLayout *hLayout = new QHBoxLayout(groupBox);
    hLayout->addWidget(label);
    hLayout->addWidget(lineEdit);

    QVBoxLayout *vLayout = new QVBoxLayout(&dlg);
    vLayout->addWidget(groupBox);
    vLayout->addStretch();
    vLayout->addWidget(buttons);

    QSizePolicy policy = label->sizePolicy();
    policy.setHorizontalStretch(3);
    label->setSizePolicy(policy);
    policy = lineEdit->sizePolicy();
    policy.setHorizontalStretch(1);
    lineEdit->setSizePolicy(policy);

    dlg.show();

    return app.exec();
}
