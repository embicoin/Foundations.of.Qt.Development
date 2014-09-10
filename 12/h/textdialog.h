#include <QDialog>
#include "textandnumber.h"
#include <QMutex>
#include "ui_threadingdemo.h"

class TextDialog : public QDialog
{
    Q_OBJECT
    public:
        TextDialog();

    public slots:
        void showText( TextAndNumber tan );

    private slots:
        void buttonClicked( QAbstractButton * );

    private:
        int count;
        QMutex mutex;

        Ui::TextDialog ui;
};
