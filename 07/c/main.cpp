#include <QApplication>
#include <QTextDocument>
#include <QPainter>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QLabel>
#include <QPainterPath>
#include <QFont>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    QPixmap pixmap( 520, 520 );
    pixmap.fill( Qt::white );

    QPainter painter( &pixmap );
    painter.translate( 100, 100 );
    //painter.scale( 1.5, 2.0 );
    painter.rotate( 30 );

    QPen pen( Qt::white );
    painter.setPen( pen );

    QBrush brush( Qt::gray );
    painter.setBrush( brush );

    QPainterPath path;
    path.addEllipse( 80, 80, 80, 80 );
    path.moveTo( 120, 120 );
    path.lineTo( 120, 40 );
    path.arcTo( 40, 40, 160, 160, 90, 90 );
    path.lineTo( 120, 120 );

    QFont font = QApplication::font();    
    font.setPixelSize( 40 );

    path.addText( 20, 180, font, "Path" );

    painter.save();

    painter.drawPath( path );

    painter.restore();

    QWidget window;
    QLabel label( &window );
    label.setPixmap( pixmap );
    window.resize( 520, 520 );

    window.show();

    return app.exec();
}
