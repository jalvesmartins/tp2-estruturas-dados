#ifndef NODE_HPP
#define NODE_HPP

#include "./package.hpp"
#include "./warehouse.hpp"

typedef struct Node {
    Package pack;
    Node* next;
    
    Node() : pack(), next(nullptr) {}
} Node;

typedef struct W_Node {
    id n_id;
    Warehouse warehouse;
    W_Node* next;
    W_Node* edges;
    
    W_Node(id n_id) : n_id(n_id), warehouse(n_id), next(nullptr), edges(nullptr) {}

} W_Node;

#endif