/* #include "../include/list.hpp"

template<typename T>
List<T>::~List() {
    while (!is_empty()) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T& data) {
    L_Node* new_node = new L_Node(data);
    if (is_empty()) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

template<typename T>
void List<T>::push_back(T& data) {
    L_Node* new_node = new L_Node(data);
    if (is_empty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

template<typename T>
T List<T>::pop_front() {
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

template<typename T>
T List<T>::pop_back() {
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

template<typename T>
T& List<T>::front() {
    if (is_empty()) {
        throw std::runtime_error("Lista vazia");
    }
    return head->data;
}

template<typename T>
T& List<T>::back() {
    if (is_empty()) {
        throw std::runtime_error("Lista vazia");
    }
    return tail->data;
}

template<typename T>
typename List<T>::L_Node* List<T>::getHead() {
    return this->head;
}

template<typename T>
T& List<T>::getData() {
    if (is_empty()) {
        throw std::runtime_error("Lista vazia");
    }
    return this->data;
}

template<typename T>
bool List<T>::is_empty() const {
    return head == nullptr;
} */