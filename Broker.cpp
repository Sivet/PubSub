#include <utility>

#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

void Broker::addSubscriber(Subscriber *ptr, std::string topic)
{
    // mSubscriberMap.insert(std::pair<std::string, Subscriber *>(topic, ptr));
    if (auto iter{mSubscriberMap.find(topic)}; iter == mSubscriberMap.end()) {
        // Topic not found
        mSubscriberMap.insert(std::pair<std::string, std::vector<Subscriber *>>(topic, std::vector<Subscriber *>{ptr}));
    } else {
        // Topic found
        iter->second.push_back(ptr);
    }
}

void Broker::registerToPublisher(Publisher *ptr)
{
    ptr->registerBroker(this);
}

// template <typename NewData>
void Broker::onPublish(std::string topic, int newData)
{
    // foreach sub in multimap for a given key, do->update
    for (auto sub : mSubscriberMap[topic]) {
        sub->updateCallback(newData);
    }
}