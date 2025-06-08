#ifndef STACK_HPP
#define STACK_HPP

#include "./package.hpp"

class Node;

class Stack {
    public:
        Stack() : top(nullptr), size(0), id(0) {}
        ~Stack();

        void push(Package* new_item);
        Package* pop();
        void clear();

        void setId(int id);
        int getId();

        Node* getTop();
        int getSize();

    private:
        Node* top;
        int size;
        int id;
}; 

#endif