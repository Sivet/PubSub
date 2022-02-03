#include "Subscriber.h"
#include "Broker.h"

void Subscriber::subscribeToBroker(Broker *ptr, std::string topic)
{
    mTopic = topic;
    ptr->addSubscriber(this, topic);
}

// template <class DataValue>
void Subscriber::updateCallback(int newData)
{
    mData = newData;
    // std::cout << "Base Subscriber recieved data" << std::endl;
    std::cout << "new data for topic " << mTopic << " is " << mData << "\n";
}