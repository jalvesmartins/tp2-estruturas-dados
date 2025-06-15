#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "./node.hpp"
#include "warehouse.hpp"

class Graph {
    public:
        Graph() : head(nullptr), tail(nullptr) {};

        ~Graph() {
            WHouse_Node* aux_node = head;
            while (aux_node != nullptr) {
                WHouse_Node* next_node = aux_node->next;
        
                Edge_Node* aux_edge_node = aux_node->edges;
                while (aux_edge_node != nullptr) {
                    Edge_Node* next_edge = aux_edge_node->next;
                    delete aux_edge_node;
                    aux_edge_node = next_edge;
                }
        
                delete aux_node;
        
                aux_node = next_node;
            }
        };

        WHouse_Node* getGraph();

        void readNodes(int node_count);
        void readEdges(int node_count, std::ifstream& inputFile);

        void insertNode();
        void insertEdge(int node, int edge);

        WHouse_Node* findWHouseNode(int w_id);

    private:
        static int node_count;
        WHouse_Node* head;
        WHouse_Node* tail;
};

#endif