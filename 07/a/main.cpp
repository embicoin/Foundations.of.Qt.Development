#include <QApplication>
#include <QTextDocument>
#include <QPainter>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QLabel>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QTextDocument doc;
    doc.setHtml( "<p>A QTextDocument can be used to present formatted text "
            "in a nice way.</p>"
            "<p align=center>It can be <b>formatted</b> "
            "<font size=+2>in</font> <i>different</i> ways.</p>"
            "<p>The text can be really long and contain many "
            "paragraphs. It is properly wrapped and such...</p>" );

    QPixmap pixmap( 520, 520 );
    pixmap.fill( Qt::white );

    QPainter painter( &pixmap );

    QPen pen( Qt::black );
    painter.setPen( pen );

    QBrush brush( Qt::white );
    painter.setBrush( brush );

    QRect rect( 0, 0, 400, 200 );
    rect.translate( 0, 50 );

    rect.setHeight( 160 );
    doc.setTextWidth( rect.width() );
    painter.save();

    // translate the painter to the top left point of the rectangle
    painter.translate( rect.topLeft() );

    // Draws the content of the document with painter p, clipped to rect.
    doc.drawContents( &painter, rect.translated( -rect.topLeft() ) );
    painter.restore();

    QWidget window;
    QLabel label( &window );
    label.setPixmap( pixmap );
    window.resize( 520, 520 );

    window.show();

    return app.exec();
}
