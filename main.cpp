#include <iostream>

#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

int main()
{
    Broker broker;
    Publisher pub;
    broker.registerToPublisher(&pub);

    Subscriber sub1;
    Subscriber sub2;
    Subscriber sub3;
    Subscriber sub4;

    sub1.subscribeToBroker(&broker, "AA");
    sub2.subscribeToBroker(&broker, "AA");
    sub3.subscribeToBroker(&broker, "BB");
    sub4.subscribeToBroker(&broker, "BB");

    while (true) {
        pub.update();
    }
    return 0;
}