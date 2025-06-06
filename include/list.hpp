#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List {
public:
    List() : head(nullptr), tail(nullptr) {};
    ~List() {
        while(!this->is_empty()) {
            this->pop_front();
        }
    };

    void push_front(int data);
    void push_back(int data);

    int pop_front();
    int pop_back();

    int front() const;
    int back() const;

    bool is_empty() const;

private:
    struct L_Node {
        int data;
        L_Node* next;
        L_Node(int data) : data(data), next(nullptr) {}
    };

    L_Node* head;
    L_Node* tail;
};

#endif