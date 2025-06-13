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

    List(const List<T>& other) {
        // Primeiro, inicializamos a nova lista (a 'this') como vazia.
        // Isso é crucial para garantir que ela comece em um estado limpo.
        head = nullptr;
        tail = nullptr;
        size = 0;

        // Criamos um ponteiro temporário para percorrer a lista 'other'
        // (a lista original da qual estamos copiando).
        L_Node* current_other = other.head;

        // Percorremos a lista 'other' do início ao fim.
        while (current_other != nullptr) {
            // Para cada nó na lista original, pegamos seu dado e o adicionamos
            // ao final da *nossa* nova lista.
            // A função 'push_back' já cuida de criar um *novo* nó e alocar
            // memória para ele, garantindo uma cópia profunda (deep copy).
            this->push_back(current_other->data);

            // Avançamos para o próximo nó na lista original.
            current_other = current_other->next;
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

        this->size++;
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

        this->size++;
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
        this->size--;
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
        this->size--;
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

    List<T>& operator=(const List<T>& other) {
        // Proteção contra auto-atribuição (ex: minhaLista = minhaLista)
        if (this == &other) {
            return *this;
        }

        // Limpa a lista atual para não vazar memória
        while (!is_empty()) {
            pop_front();
        }

        // Copia os elementos da outra lista (mesma lógica do construtor de cópia)
        L_Node* current_other = other.head;
        while (current_other != nullptr) {
            this->push_back(current_other->data);
            current_other = current_other->next;
        }

        return *this;
    }

private:
    L_Node* head;
    L_Node* tail;
    int size;
};

#endif