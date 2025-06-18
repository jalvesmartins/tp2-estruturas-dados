#ifndef HEAP_HPP
#define HEAP_HPP

#include "./event.hpp"

class Heap {
public:
    // Construtores e destrutor.
    Heap(int maxsize) {
        this->size = 0;
        this->capacity = maxsize; 
        this->events = new Event[maxsize];
    }

    ~Heap() {
        delete[] this->events;
    }

    // Retorna o ancestral do evento na árvore.
    Event* getAncestral(int index);

    // Retorna o sucessor a esqierda na árvore.
    Event* getSucessorEsq(int index);

    // Retorna o sucessor a direira na árvore.
    Event* getSucessorDir(int index);

    // Insere um evento.
    void insert(Event* new_event); 

    // Remove um evento.
    Event remove();

    // Reordena o heap após uma insersção.
    void bottomHeapfy(int index);

    // Reordena o heap após uma remoção.
    void topHeapfy(int index);

    // Verifica se o Heap está vazio.
    int isEmpty();

private:
    int size;   // Tamanho do Heap.
    int capacity;   // Capacidade máxima do heap.
    Event* events;  // Vetor de eventos do heap, que representa a árvore.
};

#endif