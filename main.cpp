#include <chrono>
#include <iostream>
#include <thread>

#include "Broker.h"
#include "Publisher.h"
#include "Subscriber.h"

class EmailEvent : public EventType<EmailEvent>
{
  public:
    EmailEvent(std::string data)
        : emailData(data) {}
    ~EmailEvent() {}
    std::string emailData;
};
class SmSEvent : public EventType<SmSEvent>
{
  public:
    SmSEvent(int data)
        : smsData(data) {}
    ~SmSEvent() {}
    int smsData;
};

class Email : public Publisher
{
  public:
    Email() : Publisher() {}
    ~Email() {}
};
class SmS : public Publisher
{
  public:
    SmS() : Publisher() {}
    ~SmS() {}
};

class EmailSub : public Subscriber
{
  public:
    EmailSub() : emailEvent(""){};
    ~EmailSub(){};

    void updateCallback(Event &newEvent) override
    {
        emailEvent.emailData += newEvent.GetAs<EmailEvent>().emailData;
        std::cout << "Email Sub new data " << emailEvent.emailData << std::endl;
    }

    EmailEvent emailEvent;
};
class SmSSub : public Subscriber
{
  public:
    SmSSub() : smsEvent(0){};
    ~SmSSub(){};

    void updateCallback(Event &newEvent) override
    {
        smsEvent.smsData += newEvent.GetAs<SmSEvent>().smsData;
        std::cout << "SmS Sub new data " << smsEvent.smsData << std::endl;
    }

    SmSEvent smsEvent;
};

int main()
{
    Broker broker;

    Publisher pubBase;
    Email emailPub;
    Email email2Pub;
    SmS smsPub;
    // BadPub badPub;

    broker.registerToPublisher(&pubBase);
    broker.registerToPublisher(&emailPub);
    broker.registerToPublisher(&email2Pub);
    broker.registerToPublisher(&smsPub);

    Subscriber baseSub;
    EmailSub eSub;
    SmSSub sSub2;
    SmSSub sSub;

    baseSub.subscribeToBroker(&broker, Topic::Base);
    eSub.subscribeToBroker(&broker, Topic::Email);
    sSub2.subscribeToBroker(&broker, Topic::Email);
    sSub.subscribeToBroker(&broker, Topic::SmS);

    Event be;
    EmailEvent ev("a");
    SmSEvent sv(0);
    while (true) {
        pubBase.publishToBroker(Topic::Base, be);
        emailPub.publishToBroker(Topic::Email, ev);
        email2Pub.publishToBroker(Topic::Email, ev);
        smsPub.publishToBroker(Topic::SmS, sv);
        std::cout << "---" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}