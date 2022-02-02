#pragma once

#include <iostream>

class Broker;

class Publisher
{
  public:
    Publisher()
        : mDataForAA(0), mDataForBB(0), mCntForAA(0), mCntForBB(0), mBrokerPtr(nullptr)
    {
    }
    virtual ~Publisher() {}

    virtual void registerBroker(Broker *pBroker);
    virtual void publishToBroker(std::string topic, int newData);
    virtual void update(void);

  private:
    int mDataForAA;
    int mDataForBB;

    int mCntForAA;
    int mCntForBB;

    Broker *mBrokerPtr;
};