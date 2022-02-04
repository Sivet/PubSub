#pragma once

#include <iostream>

#include "Broker.h"

class Publisher
{
  public:
    Publisher()
        : mBrokerPtr(nullptr)
    {
    }
    virtual ~Publisher() {}

    virtual void registerBroker(Broker *pBroker);
    virtual void publishToBroker(Topic topic, Event &newEvent);

    // protected:
    Broker *mBrokerPtr;
};