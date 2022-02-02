#pragma once

#include <iostream>

class Broker;

class Subscriber
{
  public:
    virtual ~Subscriber() {}

    virtual void subscribeToBroker(Broker *ptr, std::string topic);
    virtual void updateCallback(int newVal);

  private:
    int mData;
    std::string mTopic;
};