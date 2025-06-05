#include "../include/graph.hpp"
#include <iostream>

int Graph::node_count = 0;
int Graph::double_edge_count = 0;

WHouse_Node* Graph::getGraph() {
    return this->head;
}

void Graph::insertNode(int n_id) {
    WHouse_Node* new_node = new WHouse_Node(n_id);
    this->node_count++;

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
};

//Por enquanto, adiciona apenas 1 aresta. Adaptar dependendo da entrada.
void Graph::insertEdge(int n_id, int e_id) {
    WHouse_Node* aux_node = head;

    while(aux_node != nullptr && aux_node->n_id != n_id) {
        aux_node = aux_node->next;
    }

    if (aux_node == nullptr) {
        std::cout << "ERRO" << std::endl;
        return;
    }

    Edge_Node* new_edge = new Edge_Node(e_id);
    Edge_Node* aux_edge = aux_node->edges;

    if(aux_edge == nullptr) {
        aux_node->edges = new_edge;

    } else {
        new_edge->next = aux_edge;
        aux_node->edges = new_edge;
    }
    
    this->double_edge_count++;
    
    return;
};