#include "../include/heap.hpp"
#include <stdio.h>
#include <stdlib.h>

Heap* NovoHeap(int maxsize) {
    Heap* h = new Heap;
    h->size = 0;
    h->events = new Event[maxsize];
    return h;
}

void deleteHeap(Heap* h) {
    if (h != NULL) {
        delete[] h->events;
        delete h;
    }
}

void insert(Heap* h, Event* new_event) {
    h->events[h->size] = *new_event;
    bottomHeapfy(h, h->size);
    h->size++;
}

Event remove(Heap* h) {
    Event removed = h->events[0];
    h->size--;
    h->events[0] = h->events[h->size];

    h->events[h->size].resetEvent();

    topHeapfy(h, 0);

    return removed;
}

Event* GetAncestral(Heap* h, int index) {
    return &h->events[(index - 1) / 2];
}

Event* GetSucessorEsq(Heap* h, int index) {
    return &h->events[(2 * index) + 1];
}
Event* GetSucessorDir(Heap* h, int index) {
    return &h->events[(2 * index) + 2];
}

//Retorna 1 caso h esteja vazio, 0 caso contrário.
int isEmpty(Heap* h) {
    if (h->size != 0) {
        return 0;
    }
    return 1;
}

//Funções necessárias para implementar o Heapify recursivo
void bottomHeapfy(Heap* h, int index) {
    if (h->events[index] < h->events[(index - 1) / 2]) {
        Event aux_event = h->events[(index - 1) / 2];
        h->events[(index - 1) / 2] = h->events[index];
        h->events[index] = aux_event;

        bottomHeapfy(h, (index - 1) / 2);
    }
    return;
}

void topHeapfy(Heap* h, int index) {
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;
    
    if (left >= h->size) return;

    int min;

    if (right >= h->size) {
        min = left;
    } else {
        min = (h->events[left] < h->events[right]) ? left : right;
    }

    if (h->events[min] < h->events[index]) {
        Event aux_event = h->events[min];
        h->events[min] = h->events[index];
        h->events[index] = aux_event;

        topHeapfy(h, min);
    }
}