#include "../include/graph.hpp"
#include <iostream>

int Graph::node_count = 0;

void Graph::readNodes(int node_count) {
    for (int i = 0; i < node_count; i++) {
        insertNode();
    }
}

void Graph::readEdges(int node_count) {
    int warehouse = 0, edge_exists = 0;
    for (int warehouse = 0; warehouse < node_count; warehouse++) {
        for (int columns = 0; columns < node_count; columns++) {
            std::cin >> edge_exists;
            if (edge_exists == 1) {
                insertEdge(warehouse, columns);
            }
        }
    }
}

WHouse_Node* Graph::getGraph() {
    return this->head;
}

void Graph::insertNode() {
    WHouse_Node* new_node = new WHouse_Node(node_count);
    std::cout << "WHOUSE " << node_count << "CREATED" << std::endl;
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

    aux_node->warehouse.addSession(e_id);
    
    return;
};