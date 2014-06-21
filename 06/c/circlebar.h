#include <QWidget>

class CircleBar : public QWidget
{
    Q_OBJECT
    public:
        CircleBar( int value = 0, QWidget *parent = 0 );

        int value() const;

        int heightForWidth( int ) const;
        QSize sizeHint() const;
    public slots:
        void setValue( int );

    signals:
        void valueChanged( int );

    protected:
        void paintEvent( QPaintEvent* );
//        void wheelEvent( QWheelEvent* );

    private:
        int m_value;

};
