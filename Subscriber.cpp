#include "Subscriber.h"
#include "Broker.h"

void Subscriber::subscribeToBroker(Broker *ptr, std::string topic)
{
    mTopic = topic;
    ptr->addSubscriber(this, topic);
}

void Subscriber::updateCallback(int newData)
{
    std::cout << "new data for topic " << mTopic << " is " << mData << "\n";
    mData = newData;
}