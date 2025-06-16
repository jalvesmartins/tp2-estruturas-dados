#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "./heap.hpp"
#include "./graph.hpp"

class Scheduler {
    public:
        // Construtores e destrutor.
        Scheduler(int maxsize) : scheduler(maxsize) {};
        ~Scheduler() = default;

        // Adiciona um evento no heap.
        void scheduleEvent(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination) {
            Event new_event = Event(event_type, post_time, pack, origin, destination);
            scheduler.insert(&new_event);
        }

        // Remove um evento, sendo ele o de menor tempo.
        Event removeEvent() {
            return this->scheduler.remove();
        }

        // Verifica se o heap esta vazio.
        int isEmpty() {
            return scheduler.isEmpty();
        };

    private:
        Heap scheduler; // Heap em si.
};

#endif