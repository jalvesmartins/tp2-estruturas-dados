#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "./node.hpp"
#include "warehouse.hpp"

// Renomeia o nó de inteiros.
using Edge_Node = Int_Node;

class Graph {
    public:
        // Construtor e destrutor.
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

        // Retorna o primeiro nó do grafo.
        WHouse_Node* getGraph();

        // Faz a leitura dos nós.
        void readNodes(int node_count);

        // Faz a leitura das arestas.
        void readEdges(int node_count, std::ifstream& inputFile);

        // Insere o nó.
        void insertNode();

        // Insere a aresta.
        void insertEdge(int node, int edge);

        // Encontra um nó específico.
        WHouse_Node* findWHouseNode(int w_id);

    private:
        static int node_count;  // Contador de nós.
        WHouse_Node* head;      // Primeiro nó.
        WHouse_Node* tail;      // Último nó.
};

#endif