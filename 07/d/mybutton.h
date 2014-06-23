#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QAbstractButton>
#include <QWidget>
#include <QPaintEvent>

class MyButton : public QAbstractButton
{
    Q_OBJECT  
    public:
        MyButton( QWidget *parent = 0 );

        QSize sizeHint() const;

    protected:
        void paintEvent( QPaintEvent *);
};

#endif
