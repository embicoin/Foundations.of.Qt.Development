#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QApplication>
#include <QDockWidget>

class SdiWindow : public QMainWindow
{
    Q_OBJECT

    public:
        SdiWindow(QWidget *parent = 0);

    private:
        void createActions();
        void createMenus();
        void createToolbars();
        void closeEvent(QCloseEvent *event = 0);
        bool isSafeToClose();
        void createDocks();

        QTextEdit *docWidget;
        QAction *newAction;
        QAction *cutAction;
        QAction *aboutQtAction;
        QAction *closeAction;
        QAction *exitAction;
        QDockWidget *dock;

    private slots:
        void fileNew();

};
