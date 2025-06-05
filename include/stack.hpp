#ifndef STACK_HPP
#define STACK_HPP

#include "./node.hpp"
#include "./package.hpp"

class Stack {
    public:
        Stack() : top(nullptr), size(0) {}
        ~Stack();

        void push(Package* new_item);
        Package* pop();
        void clear();
        Node* getTop();
        int getSize();

    private:
        Node* top;
        int size;
}; 

#endif