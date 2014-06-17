#include <QApplication>
#include <QFileDialog>
#include <QTranslator>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString filename = QFileDialog::getOpenFileName(
            0,
            ("Open Document"),
            QDir::currentPath(),
            ("Document files (*.doc *.rtf);;All files (*.*)") );
    if (!filename.isNull())
    {
    
    }

    return app.exec();
}


