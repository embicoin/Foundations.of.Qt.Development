#include <QDialogButtonBox>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QDebug>

class buttonBox : public QWidget
{
    Q_OBJECT
    public:
        buttonBox(QWidget *parent = 0);

    private:
        QDialogButtonBox *box;
        QPushButton *button;

        private slots:
            void okClicked();
};
