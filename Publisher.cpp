#include "Publisher.h"
#include "Broker.h"

void Publisher::registerBroker(Broker *pBroker)
{
    mBrokerPtr = pBroker;
}

void Publisher::publishToBroker(std::string topic, int newData)
{
    mBrokerPtr->onPublish(topic, newData);
}

void Publisher::update(void)
{
    publishToBroker("Base", mData);
}