#ifndef NODE_HPP
#define NODE_HPP

#include "./package.hpp"
#include "./warehouse.hpp"

// Nó de pacotes.
typedef struct Pack_Node {
    Package* pack;
    Pack_Node* next;
    
    Pack_Node() : pack(), next(nullptr) {}
} Pack_Node;

// Nó de inteiros.
typedef struct Int_Node {
    id e_id;
    Int_Node* next;

    Int_Node(int e_id) : e_id(e_id), next(nullptr) {}
} Int_Node;

// Nó de armazéns.
typedef struct WHouse_Node {
    id n_id;
    Warehouse warehouse;
    WHouse_Node* next;
    Int_Node* edges;
    
    WHouse_Node(id n_id) : n_id(n_id), warehouse(n_id), next(nullptr), edges(nullptr) {}
} WHouse_Node;

#endif 