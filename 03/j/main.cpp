#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    bool ok;
    QString text = QInputDialog::getText(
            0,
            "String",
            "Enter a city name:",
            QLineEdit::Normal,
            "Alingas",
            &ok );

    if (ok && !text.isEmpty())
    {
    
    }

    return app.exec();
}
