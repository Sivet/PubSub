#include <chrono>
#include <iostream>
#include <thread>

#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

class Email : public Publisher
{
  public:
    Email() : Publisher()
    {
        mData = 2;
    }
    ~Email() {}

    void update(void) override
    {
        publishToBroker("Email", mData);
        mData++;
    }
};

class SmS : public Publisher
{
  public:
    SmS() : Publisher()
    {
        mData = 5;
    }
    ~SmS() {}

    void update(void) override
    {
        publishToBroker("SmS", mData);
        mData++;
    }
};
class BadPub : public Publisher
{
  public:
    BadPub() : Publisher()
    {
        mData = 5;
    }
    ~BadPub() {}

    void update(void) override
    {
        publishToBroker("BadPub", mData);
        mData++;
    }
};

int main()
{
    Broker broker;
    Publisher pubBase;
    Email emailPub;
    SmS smsPub;
    BadPub smsBadPub;

    broker.registerToPublisher(&pubBase);
    broker.registerToPublisher(&emailPub);
    broker.registerToPublisher(&smsPub);
    broker.registerToPublisher(&smsBadPub);

    Subscriber sub1;
    Subscriber sub2;
    Subscriber sub3;
    Subscriber sub4;

    sub1.subscribeToBroker(&broker, "Base");
    sub2.subscribeToBroker(&broker, "Email");
    sub3.subscribeToBroker(&broker, "SmS");
    sub4.subscribeToBroker(&broker, "SmS");

    std::cout << "Number of elements with key Base " << broker.mSubscriberMap.count("Base") << std::endl;
    std::cout << "Number of elements with key Email " << broker.mSubscriberMap.count("Email") << std::endl;
    std::cout << "Number of elements with key SmS " << broker.mSubscriberMap.count("SmS") << std::endl;
    std::cout << "Number of elements with key BadPub " << broker.mSubscriberMap.count("BadPub") << std::endl;

    while (true) {
        pubBase.update();
        emailPub.update();
        smsPub.update();
        smsBadPub.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}