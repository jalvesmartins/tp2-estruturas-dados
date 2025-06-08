#include "../include/stack.hpp"
#include "../include/node.hpp"

Stack::~Stack() {
    while (top != nullptr) {
        Pack_Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(Package* new_item) {
    Pack_Node* new_node = new Pack_Node;

    new_node->pack = *new_item;
    new_node->next = this->top;
    top = new_node;

    size++;
}

Package* Stack::pop() {
    if(size == 0)
        throw "A pilha está vazia!";

    Pack_Node* deleted = top;
    Package* removed = &(top->pack);
    top = top->next;
    delete deleted;
    size--;

    return removed;
}

void Stack::clear() {
    while (size > 0) {
        pop();
    }
}

Pack_Node* Stack::getTop() {
    return this->top;
}

int Stack::getSize() {
    return this->size;
}

void Stack::setId(int id) {
    this->id = id;
}

int Stack::getId() {
    return this->id;
}