#ifndef EVENT_HPP
#define EVENT_HPP

#include "./package.hpp"
#include "./warehouse.hpp"

enum eventType {
    STORING_EVENT,
    TRANSPORT_EVENT
};

class Event {
    public:
        Event(eventType type, int post_time, Package* pack, Warehouse* destination) : 
        type(type), post_time(post_time), pack(pack), destination(destination) {}

        ~Event() = default;

        bool operator<(const Event& other) const {
            return this->post_time < other.post_time;
        }

        bool operator>(const Event& other) const {
            return this->post_time > other.post_time;
        }

    private:
        eventType type;
        int post_time;
        Package* pack;
        Warehouse* destination;
};

#endif