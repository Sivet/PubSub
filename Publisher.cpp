#include "Publisher.h"
#include "Broker.h"

void Publisher::registerBroker(Broker *pBroker)
{
    mBrokerPtr = pBroker;
}

void Publisher::publishToBroker(std::string topic, int newData)
{
    mBrokerPtr->onPublish(topic, newData);
}

void Publisher::update(void)
{
    if ((++mCntForAA) == 100000) {

        mCntForAA = 0;
        mDataForAA += 10;

        publishToBroker("AA", mDataForAA);
    }

    if ((++mCntForBB) == 200000) {

        mCntForBB = 0;
        mDataForBB += 20;

        publishToBroker("BB", mDataForBB);
    }
}