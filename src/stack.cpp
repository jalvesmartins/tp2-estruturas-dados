#include "../include/stack.hpp"
#include "../include/node.hpp"

Stack::Stack(const Stack& other) 
    : top(nullptr), size(0), id(other.id) { // Inicializa a nova pilha

    if (other.top == nullptr) {
        return; // A outra pilha está vazia, então esta também ficará.
    }

    // A lógica de cópia é mais complexa para uma pilha para manter a ordem.
    // A forma mais fácil é usar uma pilha ou vetor temporário.
    // Vamos usar um vetor temporário de ponteiros:
    
    Package* temp_storage[other.size];
    Pack_Node* current_other = other.top;
    int index = 0;

    // 1. Percorre a pilha original e guarda os ponteiros em ordem inversa
    while (current_other != nullptr) {
        temp_storage[index++] = current_other->pack;
        current_other = current_other->next;
    }

    // 2. Insere os ponteiros na nova pilha. Como eles estão em ordem
    //    inversa no array, a nova pilha terá a ordem correta.
    for (int i = index - 1; i >= 0; i--) {
        this->push(temp_storage[i]); // A sua função push() deve criar um NOVO Pack_Node
    }
}

void Stack::push(Package* new_item) {
    Pack_Node* new_node = new Pack_Node;

    new_node->pack = new_item;
    new_node->next = this->top;
    top = new_node;

    size++;
}

Package* Stack::pop() {
    if(size == 0)
        throw "A pilha está vazia!";

    Pack_Node* deleted = top;
    Package* removed = top->pack;
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

int Stack::isEmpty() {
    return top == nullptr;
}

Stack& Stack::operator=(const Stack& other) {
    // 1. Proteção contra auto-atribuição (ex: p = p)
    if (this == &other) {
        return *this;
    }

    // 2. Limpa completamente os dados antigos desta pilha para evitar lixo
    this->clear();

    // 3. Copia os novos dados (a lógica é a mesma do construtor de cópia)
    this->id = other.id;
    
    if (other.top != nullptr) {
        Package* temp_storage[other.size];
        Pack_Node* current_other = other.top;
        int index = 0;
        while (current_other != nullptr) {
            temp_storage[index++] = current_other->pack;
            current_other = current_other->next;
        }
        for (int i = index - 1; i >= 0; i--) {
            this->push(temp_storage[i]);
        }
    }

    // 4. Retorna a própria pilha modificada
    return *this;
}