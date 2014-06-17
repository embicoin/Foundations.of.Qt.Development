#include "sdiwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QMessageBox>
#include <QCloseEvent>
#include "infowidget.h"

SdiWindow::SdiWindow(QWidget *parent)    
    : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(QString(tr("%1[*] - %2")).arg(tr("unnamed")).arg(tr("SDI")));
    docWidget = new QTextEdit(this);
    setCentralWidget(docWidget);

    connect(docWidget->document(), SIGNAL(modificationChanged(bool)), this, SLOT(setWindowModified(bool)));

    createActions();
    createDocks();
    createMenus();
    createToolbars();
    statusBar()->showMessage(tr("Done"));
}

void SdiWindow::createActions()
{
    newAction = new QAction(QIcon(tr(":/images/new.png")), tr("&New"), this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Create a new document"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(fileNew()));

    cutAction = new QAction(QIcon(tr(":/images/cut.png")), tr("Cu&t"), this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("Cut"));
    cutAction->setEnabled(false);
    connect(docWidget, SIGNAL(copyAvailable(bool)),
            cutAction, SLOT(setEnabled(bool)));
    connect(cutAction, SIGNAL(triggered()), docWidget, SLOT(cut()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("About the Qt toolkit"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    closeAction = new QAction(QIcon(tr(":/images/close.png")), tr("&Close"), this);
    closeAction->setShortcut(tr("Ctrl+O"));
    closeAction->setStatusTip(tr("Close"));
    // TODO change the slot
    connect(closeAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    exitAction = new QAction(QIcon(tr(":/images/exit.png")), tr("&Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit"));
    connect(closeAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void SdiWindow::createMenus()
{
    QMenu *menu;    

    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(closeAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = menuBar()->addMenu(tr("&Edit"));
    menu->addAction(cutAction);
    //menu->addAction(copyAction);
    // menu->addAction(pasteAction);

    menu = menuBar()->addMenu(tr("&View"));
    menu->addAction(dock->toggleViewAction());
}

void SdiWindow::createToolbars()
{
    QToolBar *toolbar;
    toolbar = addToolBar(tr("File"));
    toolbar->addAction(newAction);
}

void SdiWindow::fileNew()
{
    (new SdiWindow())->show();
}

void SdiWindow::closeEvent(QCloseEvent *event)
{
    if (isSafeToClose())
        event->accept();
    else
        event->ignore();
}

bool SdiWindow::isSafeToClose()
{
    if (isWindowModified())
    {
        switch (QMessageBox::warning(this, tr("SDI"),
                    tr("The document has unsaved changes.\nDo you want to save it before it is closed?"),
                    QMessageBox::Discard | QMessageBox::Cancel))
        {
            case QMessageBox::Cancel:
                return false;
            default:
                return true;
        }
    }

    return true;
}

void SdiWindow::createDocks()
{
    dock = new QDockWidget(tr("Information"), this);
    InfoWidget *info = new InfoWidget(dock);
    dock->setWidget(info);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    connect(docWidget->document(), SIGNAL(contentsChange(int,int,int)),
            info, SLOT(documentChanged(int, int, int)));


}
