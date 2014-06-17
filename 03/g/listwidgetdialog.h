#include <QDialog>
#include <QWidget>
#include <QListWidget>

class ListWidgetDialog : public QDialog
{
    Q_OBJECT

public:
    ListWidgetDialog();
public slots:
    void moveLeft();
    void moveRight();

private:
    QListWidget *leftList;
    QListWidget *rightList;
};
