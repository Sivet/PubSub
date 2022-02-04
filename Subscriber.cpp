#include "Subscriber.h"

void Subscriber::subscribeToBroker(Broker *ptr, Topic topic)
{
    mTopic = topic;
    ptr->addSubscriber(this, topic);
}

void Subscriber::updateCallback(Event &newEvent)
{
    std::cout << "Base Sub got callback" << std::endl;
}