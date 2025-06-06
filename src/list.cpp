#include "../include/list.hpp"

void List::push_front(int data) {
    L_Node* new_node = new L_Node(data);

    if(this->is_empty()) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        new_node->next = this->head;
        this->head = new_node;
    }
    return;
}

void List::push_back(int data) {
    L_Node* new_node = new L_Node(data);

    if(this->is_empty()) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
    return;
}

int List::pop_front() {
    if(this->is_empty()) {
        throw std::runtime_error("Lista vazia!");
    }

    int value = this->head->data;
    L_Node* temp_node = this->head;

    if(this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        this->head = this->head->next;
    }

    delete temp_node;
    return value;
}

int List::pop_back() {
    if(this->is_empty()) {
        throw std::runtime_error("Lista vazia!");
    }

    int value = this->tail->data;
    L_Node* temp_node = this->tail;

    if(this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    } else {
        L_Node* aux_node = this->head;
        while(aux_node->next != this->tail) {
            aux_node = aux_node->next;
        }
        this->tail = aux_node;
        this->tail->next = nullptr;
    }

    delete temp_node;
    return value;
}

int List::front() const {
    if(this->is_empty()) {
        throw std::runtime_error("Cannot call front() on an empty list.");
    }
    return this->head->data;
}

int List::back() const {
    if(this->is_empty()) {
        throw std::runtime_error("Cannot call back() on an empty list.");
    }
    return this->tail->data;
}

bool List::is_empty() const {
    return this->head == nullptr;
}