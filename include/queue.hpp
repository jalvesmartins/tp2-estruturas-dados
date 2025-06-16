#ifndef BFS_HPP
#define BFS_HPP

#include "./list.hpp"
#include "./graph.hpp"
#include "./node.hpp"

// Renomeia o nó de inteiros.
using Q_Node = Int_Node;

class Queue {
    public:
        // Construtores e destrutores.
        Queue() : head(nullptr), tail(nullptr) {}
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        // Enfileira um item.
        void enqueue(int id) {
            Q_Node* new_node = new Q_Node(id);
            if (isEmpty()) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        };
        
        // Desenfileira um item.
        int dequeue() {
            if (isEmpty()) return -1;

            Q_Node* aux_node = head;
            int removed = aux_node->e_id;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            delete aux_node;
            return removed;
        };

        // Verifica se a fila está vazia.
        int isEmpty() {
            return head == nullptr;
        };

    private:
        Q_Node* head;   // Início da fila.
        Q_Node* tail;   // Fim da fila.
};

#endif