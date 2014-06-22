#include <QLabel>

class ClockLabel : public QLabel
{
    Q_OBJECT
    public:
        ClockLabel( QWidget *parent = 0 );

    private slots:
        void updateTime();
};
