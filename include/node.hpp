#ifndef NODE_HPP
#define NODE_HPP

#include "./item.hpp"

typedef struct Node {
    Item item;
    Node* next;
    
    Node() : item(), next(nullptr) {}
} Node;

#endif