#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

void Broker::addSubscriber(Subscriber *ptr, std::string topic)
{
    if (topic == "AA") {
        mSubscriberForAA.push_back(ptr);
    } else if (topic == "BB") {
        mSubscriberForBB.push_back(ptr);
    }
}

void Broker::registerToPublisher(Publisher *ptr)
{
    ptr->registerBroker(this);
}

void Broker::onPublish(std::string topic, int newData)
{
    if (topic == "AA") {
        for (auto sub : mSubscriberForAA) {
            sub->updateCallback(newData);
        }
    } else if (topic == "BB") {
        for (auto sub : mSubscriberForBB) {
            sub->updateCallback(newData);
        }
    }
}