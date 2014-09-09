#include "textproducerconsumer.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextProducer produder( "Lorem ipsum dolor sit amet, "
            "consectetuer adipiscing elit. "
            "Praesent tortor.");
    TextConsumer consumer;

    produder.start();
    consumer.start();

    produder.wait();
    consumer.wait();

    return 0;
}
