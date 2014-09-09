#include "textproducerconsumer.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    TextProducer produder1( "Lorem ipsum dolor sit amet, "
            "consectetuer adipiscing elit. "
            "Praesent tortor.");
    TextProducer produder2( "LOREM IPSUM DOLOR SIT AMET, "
            "CONSECTETUER ADIPISCING ELIT. "
            "PRAESENT TORTOR.");
    TextConsumer consumer;

    produder1.start();
    produder2.start();
    consumer.start();

    produder1.wait();
    produder2.wait();
    consumer.wait();

    return 0;
}
