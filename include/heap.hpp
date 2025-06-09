#ifndef HEAP_HPP
#define HEAP_HPP

#include "./event.hpp"

typedef struct s_heap{
    int size;
    Event* events;
   } Heap;

   Heap* newHeap(int maxsize);
   void deleteHeap(Heap* h);
   void insert(Heap* h, int x);
   Event remove(Heap* h);
   Event* getParent(Heap* h, int index);
   Event* getLeftChild(Heap* h, int index);
   Event* getRightChild(Heap* h, int index);

   //Retorna 1 caso h esteja vazio, 0 caso contrário.
   int isEmpty(Heap* h);
   
   //Funções necessárias para implementar o Heapify recursivo
   void bottomHeapfy(Heap* h, int index);
   void topHeapfy(Heap* h, int index);

   #endif