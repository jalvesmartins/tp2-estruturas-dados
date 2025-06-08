#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept> // Required for std::runtime_error

template<typename T>
class List {
public:
    struct L_Node {
        T data;
        L_Node* next;
        L_Node(T& data_ref) : data(data_ref), next(nullptr) {}
    };

    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        while (!is_empty()) {
            pop_front();
        }
    }

    void push_front(T& data) {
        L_Node* new_node = new L_Node(data);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    void push_back(T& data) {
        L_Node* new_node = new L_Node(data);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    T pop_front() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        L_Node* temp_node = head;
        T value = head->data;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }

        delete temp_node;
        return value;
    }

    T pop_back() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        L_Node* temp_node = tail;
        T value = tail->data;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            L_Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            tail = current;
            tail->next = nullptr;
        }

        delete temp_node;
        return value;
    }

    T& front() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    T& back() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        return tail->data;
    }

    L_Node* getHead() {
        return this->head;
    }

    T& getData() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        return this->head->data;
    }

    bool is_empty() const {
        return head == nullptr;
    }

private:
    L_Node* head;
    L_Node* tail;
};

#endif