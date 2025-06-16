#include "../include/heap.hpp"

void Heap::insert(Event* new_event) {
    if (this->size == this->capacity) {
        return;
    }

    this->events[this->size] = *new_event;
    bottomHeapfy(this->size);
    this->size++;
}

Event Heap::remove() {
    Event removed = this->events[0];
    this->size--;
    this->events[0] = this->events[this->size];
    this->events[this->size].resetEvent();
    topHeapfy(0);
    return removed;
}

Event* Heap::getAncestral(int index) {
    if (index == 0) return nullptr;
    return &this->events[(index - 1) / 2];
}

Event* Heap::getSucessorEsq(int index) {
    int left = (2 * index) + 1;
    if (left >= this->size) return nullptr;
    return &this->events[left];
}

Event* Heap::getSucessorDir(int index) {
    int right = (2 * index) + 2;
    if (right >= this->size) return nullptr;
    return &this->events[right];
}

int Heap::isEmpty() {
    if (this->size != 0) {
        return 0;
    }

    return 1;
}

void Heap::bottomHeapfy(int index) {
    if (index > 0 && events[index] < *getAncestral(index)) {
        Event aux_event = *getAncestral(index);
        events[(index - 1) / 2] = events[index];
        events[index] = aux_event;
        bottomHeapfy((index - 1) / 2);
    }
}

void Heap::topHeapfy(int index) {
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    
    if (left >= this->size) return;

    int min;
    
    if (right >= this->size) {
        min = left;

    } else {
        min = (events[left] < events[right]) ? left : right;
    }

    if (events[min] < events[index]) {
        Event aux_event = events[min];
        events[min] = events[index];
        events[index] = aux_event;
        topHeapfy(min);
    }
}