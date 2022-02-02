#pragma once

#include <iostream>
#include <map>
#include <vector>

class Subscriber;
class Publisher;

class Broker
{
  public:
    virtual ~Broker() {}

    virtual void addSubscriber(Subscriber *ptr, std::string topic);
    virtual void registerToPublisher(Publisher *ptr);
    virtual void onPublish(std::string topic, int newData);

    std::multimap<std::string, Subscriber *> mSubscriberMap;
};