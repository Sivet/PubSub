#pragma once

#include <type_traits>

class Event
{
  public:
    Event(size_t aHash) : typeHash(aHash) {}
    Event() : typeHash(typeid(Event).hash_code()) {}
    ~Event() {}

    template <class T>
    T &GetAs()
    {
        if (typeid(T).hash_code() != typeHash) {
            std::cout << "- Is Not Same Type" << std::endl;
            // throw std::bad_alloc();
        }
        return *reinterpret_cast<T *>(this);
    }

    size_t typeHash;
};

template <class T>
class EventType : public Event
{
  public:
    EventType() : Event(typeid(T).hash_code()) {}
};
