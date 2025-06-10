#ifndef STACK_HPP
#define STACK_HPP

#include "./package.hpp"

class Package;

struct Pack_Node;

class Stack {
    public:
        Stack() : top(nullptr), size(0), id(0) {}
        ~Stack();

        void push(Package* new_item);
        Package* pop();
        void clear();
        void setId(int id);
        int getId();
        Pack_Node* getTop();
        int getSize();
        int isEmpty();

    private:
        Pack_Node* top;
        int size;
        int id;
}; 

#endif