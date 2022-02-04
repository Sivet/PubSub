#include "Publisher.h"

void Publisher::registerBroker(Broker *pBroker)
{
    mBrokerPtr = pBroker;
}

void Publisher::publishToBroker(Topic topic, Event &newEvent)
{
    mBrokerPtr->onPublish(topic, newEvent);
}