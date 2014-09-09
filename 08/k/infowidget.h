#include <QLabel>
#include <QWidget>

class InfoWidget : public QLabel
{
    Q_OBJECT
    public:
        InfoWidget(QWidget *parent = 0);
    public slots:
        void documentChanged(int position, int charsRemoved, int charsAdded);
};
