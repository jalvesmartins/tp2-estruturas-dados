#ifndef NODE_HPP
#define NODE_HPP

#include "./package.hpp"
#include "./warehouse.hpp"

typedef struct Node {
    Package pack;
    Node* next;
    
    Node() : pack(), next(nullptr) {}
} Node;

typedef struct Edge_Node {
    id e_id;
    Edge_Node* next;

    Edge_Node(int e_id) : e_id(e_id), next(nullptr) {}
} Edge_Node;

typedef struct WHouse_Node {
    id n_id;
    Warehouse warehouse;
    WHouse_Node* next;
    Edge_Node* edges;
    
    WHouse_Node(id n_id) : n_id(n_id), warehouse(n_id), next(nullptr), edges(nullptr) {}

} WHouse_Node;

#endif