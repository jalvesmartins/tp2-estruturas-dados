#ifndef NODE_HPP
#define NODE_HPP

#include "./package.hpp"

typedef struct Node {
    Package pack;
    Node* next;
    
    Node() : pack(), next(nullptr) {}
} Node;

#endif