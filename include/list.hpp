#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

class List {
public:
    List();
    ~List();

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
        L_Node(int val) : data(val), next(nullptr) {}
    };

    L_Node* head;
    L_Node* tail;
};

#endif