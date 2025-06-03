#include "../include/stack.hpp"

void Stack::push(Item* new_item) {
    Node* new_node = new Node;

    new_node->item = *new_item;
    new_node->next = this->top;
    top = new_node;

    size++;
}

Item Stack::pop() {
    if(size == 0)
        throw "A pilha está vazia!";

    Node* deleted = top;
    Item removed = top->item;
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

Item* Stack::findAndRemove(Stack* stack, Key key) {
    Node* aux_node = top;

    while (aux_node->item.getKey() != key) {
        stack->push(&(top->item));
        pop();
    }

    Item found_item = pop();

    while(stack->size > 0) {
        this->push(&(stack->top->item));
        stack->pop();
    }

    return &found_item;
}
