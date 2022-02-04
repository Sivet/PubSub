#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Event.h"

enum class Topic {
    Base,
    Email,
    SmS,
    BadTopic
};

class Subscriber;
class Publisher;

class Broker
{
  public:
    virtual ~Broker() {}

    void addSubscriber(Subscriber *ptr, Topic topic);
    void registerToPublisher(Publisher *ptr);
    void onPublish(Topic topic, Event &newEvent);

    // protected:
    std::map<Topic, std::vector<Subscriber *>> mSubscriberMap;
};