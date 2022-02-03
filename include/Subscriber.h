#pragma once

#include <iostream>

class Broker;

class Subscriber
{
  public:
    virtual ~Subscriber() {}

    virtual void subscribeToBroker(Broker *ptr, std::string topic);

    // template <class DataValue>
    // void updateCallback(DataValue newData);
    virtual void updateCallback(int newData);

    // protected:
    int mData;
    std::string mTopic;
};