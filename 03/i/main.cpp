#include <QApplication>
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString dirname = QFileDialog::getExistingDirectory(
            0,
            ("Selecting a Directory"),
            QDir::currentPath() );

    return app.exec();
}
