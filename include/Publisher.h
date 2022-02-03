#pragma once

#include <iostream>

class Broker;

class Publisher
{
  public:
    Publisher()
        : mData(0), mBrokerPtr(nullptr)
    {
    }
    virtual ~Publisher() {}

    virtual void registerBroker(Broker *pBroker);
    virtual void publishToBroker(std::string topic, int newData);
    virtual void update(void);

    // protected:
    int mData;
    Broker *mBrokerPtr;
};