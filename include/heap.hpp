#ifndef HEAP_HPP
#define HEAP_HPP

#include "./event.hpp"

class Heap {
public:
    Heap(int maxsize) {
        this->size = 0;
        this->capacity = maxsize; 
        this->events = new Event[maxsize];
    }

    ~Heap() {
        delete[] this->events;
    }

    void insert(Event* new_event);
    Event remove();
    Event* getAncestral(int index);
    Event* getSucessorEsq(int index);
    Event* getSucessorDir(int index);
    int isEmpty();

private:
    int size;
    int capacity;
    Event* events;

    void bottomHeapfy(int index);
    void topHeapfy(int index);
};

#endif