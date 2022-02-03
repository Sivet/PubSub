#pragma once

#include <iostream>
#include <map>
#include <vector>

class Subscriber;
class Publisher;

// template <typename TopicType>
class Broker
{
  public:
    virtual ~Broker() {}

    void addSubscriber(Subscriber *ptr, std::string topic);
    void registerToPublisher(Publisher *ptr);
    // template <typename NewData>
    // void onPublish(std::string topic, NewData newData);
    void onPublish(std::string topic, int newData);

    // protected:
    std::map<std::string, std::vector<Subscriber *>> mSubscriberMap;
};