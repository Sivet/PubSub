#pragma once

#include <iostream>

#include "Broker.h"

class Subscriber
{
  public:
    virtual ~Subscriber() {}

    virtual void subscribeToBroker(Broker *ptr, Topic topic);
    virtual void updateCallback(Event &newEvent);

    // protected:
    Topic mTopic;
};