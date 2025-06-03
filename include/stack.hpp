#ifndef STACK_HPP
#define STACK_HPP

#include "./node.hpp"
#include "./item.hpp"

class Stack {
    public:
        Stack() : top(nullptr), size(0) {}
        ~Stack();

        void push(Item* new_item);
        Item pop();
        void clear();
        Item* findAndRemove(Stack* aux_stack, Key key);

    private:
        Node* top;
        int size;
}; 

#endif