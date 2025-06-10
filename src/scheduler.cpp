#include "../include/scheduler.hpp"

void Scheduler::scheduleEvent(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination) {
    Event* new_event = new Event(event_type, post_time, pack, origin, destination);
    scheduler.insert(new_event);
}

Event Scheduler::removeEvent() {
    return this->scheduler.remove();
}

int Scheduler::isEmpty() {
    return scheduler.isEmpty();
}