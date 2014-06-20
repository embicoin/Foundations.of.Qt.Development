#include <QWidget>
#include <QString>
#include <QPainter>

class EventWidget : public QWidget
{
    Q_OBJECT
    public:
        EventWidget( QWidget *parent = 0 );
    signals:
        void gotEvent( const QString & );
    protected:
        void closeEvent( QCloseEvent *event );
        void contextMenuEvent( QContextMenuEvent *event );
        void enterEvent( QEvent *event );
        void focusInEvent( QFocusEvent *event );
        void focusOutEvent( QFocusEvent *event );
        void hideEvent( QHideEvent *event );
        void keyPressEvent( QKeyEvent *event );
        void keyReleaseEvent( QKeyEvent *event );
        //void leaveEvent( QEvent *event );
        //void mouseDoubleClickEvent( QMouseEvent *event );
        //void mouseMoveEvent( QMouseEvent *event );
        //void mousePressEvent( QMouseEvent *event );
        //void mouseReleaseEvent( QMouseEvent *event );
        //void paintEvent( QPaintEvent *event );
        //void resizeEvent( QResizeEvent *event );
        //void showEvent( QShowEvent *event );
        //void wheelEvent( QWheelEvent *event );
};
