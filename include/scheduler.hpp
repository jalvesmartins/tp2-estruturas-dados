#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "./heap.hpp"
#include "./graph.hpp"

class Scheduler {
    public:
        Scheduler(int maxsize) : scheduler(maxsize) {};
        ~Scheduler() = default;

        void scheduleEvent(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination);
        Event* removeEvent();

    private:
        Heap scheduler;
};

#endif