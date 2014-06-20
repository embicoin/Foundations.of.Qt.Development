#include <QWidget>
#include <QEvent>
#include <QKeyEvent>

class KeyboardFilter : public QWidget 
{
    public:
        KeyboardFilter( QWidget *parent = 0 );

    protected:
        bool eventFilter( QObject *dist, QEvent *event );
        void keyPressEvent( QKeyEvent *event );
};
