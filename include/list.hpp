#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
template<typename T>
class List {
public:
    struct L_Node {
        T data;
        L_Node* next;
        L_Node(T& data) : data(data), next(nullptr) {}
    };

    List() : head(nullptr), tail(nullptr) {};
    ~List();

    void push_front(T& data);
    void push_back(T& data);

    T pop_front();
    T pop_back();

    L_Node* getHead();

    T& getData();
    T& front();
    T& back();
    bool is_empty() const;

private:
    L_Node* head;
    L_Node* tail;
};

#endif