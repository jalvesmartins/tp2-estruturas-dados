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

    // Constructor
    List() : head(nullptr), tail(nullptr) {}

    // Destructor - no 'List<T>::' needed
    ~List() {
        while (!is_empty()) {
            pop_front();
        }
    }

    // push_front - no 'List<T>::' needed
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

    // push_back - no 'List<T>::' needed
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

    // pop_front - no 'List<T>::' needed
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

    // pop_back - no 'List<T>::' needed
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

    // front - no 'List<T>::' needed
    T& front() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    // back - no 'List<T>::' needed
    T& back() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        return tail->data;
    }

    // getHead - no 'List<T>::' needed
    L_Node* getHead() {
        return this->head;
    }

    // getData - no 'List<T>::' needed AND corrected the bug
    T& getData() {
        if (is_empty()) {
            throw std::runtime_error("List is empty");
        }
        // BUG FIX: The List class has no 'data' member.
        // Assuming you want the data from the first node.
        return this->head->data;
    }

    // is_empty - no 'List<T>::' needed
    bool is_empty() const {
        return head == nullptr;
    }

private:
    L_Node* head;
    L_Node* tail;
};

#endif