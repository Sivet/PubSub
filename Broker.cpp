#include <utility>

#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

void Broker::addSubscriber(Subscriber *ptr, std::string topic)
{
    mSubscriberMap.insert(std::pair<std::string, Subscriber *>(topic, ptr));
}

void Broker::registerToPublisher(Publisher *ptr)
{
    ptr->registerBroker(this);
}

void Broker::onPublish(std::string topic, int newData)
{
    // foreach sub in multimap for a given key, do->update
    for (auto iter = mSubscriberMap.begin(); iter != mSubscriberMap.end(); iter++) {
        if (iter->first == topic) {
            iter->second->updateCallback(newData);
        }
    }
}