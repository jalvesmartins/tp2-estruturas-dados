#ifndef BFS_HPP
#define BFS_HPP

#include "./list.hpp"
#include "./graph.hpp"

struct Q_Node {
    int id;
    Q_Node* next;

    Q_Node(int id) : id(id), next(nullptr) {}
};

class Queue {
    public:
        Queue() : head(nullptr), tail(nullptr) {}
        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        void enqueue(int id) {
            Q_Node* new_node = new Q_Node(id);
            if (isEmpty()) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        };
        
        int dequeue() {
            if (isEmpty()) return -1;

            Q_Node* aux_node = head;
            int removed = aux_node->id;
            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            }

            delete aux_node;
            return removed;
        };

        int isEmpty() {
            return head == nullptr;
        };

    private:
        Q_Node* head;
        Q_Node* tail;
};

#endif