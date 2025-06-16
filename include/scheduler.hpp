#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "./heap.hpp"
#include "./graph.hpp"

class Scheduler {
    public:
        Scheduler(int maxsize) : scheduler(maxsize) {};
        ~Scheduler() = default;

        void scheduleEvent(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination) {
            Event new_event = Event(event_type, post_time, pack, origin, destination);
            scheduler.insert(&new_event);
        }

        Event removeEvent() {
            return this->scheduler.remove();
        }

        int isEmpty() {
            return scheduler.isEmpty();
        };

    private:
        Heap scheduler;
};

#endif