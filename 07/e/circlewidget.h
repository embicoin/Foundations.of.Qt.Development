#include <QWidget>
#include <QPaintEvent>
#include <QColor>
#include <QTimer>
#include <QMouseEvent>

class CircleWidget : public QWidget
{
    Q_OBJECT  
    public:
        CircleWidget( QWidget *parent = 0 );

        QSize sizeHint() const;

    private slots:
        void timeout();

    protected:
        void paintEvent( QPaintEvent *);

        void mousePressEvent( QMouseEvent *);
        void mouseMoveEvent( QMouseEvent *);
        void mouseReleaseEvent( QMouseEvent *);

    private:
        int x, y, r;
        QColor color;
        int mx, my;
        QTimer timer;
};
