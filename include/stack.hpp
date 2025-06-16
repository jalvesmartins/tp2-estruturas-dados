#ifndef STACK_HPP
#define STACK_HPP

#include "./package.hpp"

// Declaração das classes, para evitar erros de include.
class Package;
struct Pack_Node;

class Stack {
    public:
        // Construtores e destrutor.
        Stack() : top(nullptr), size(0), id(0) {} 
        Stack(const Stack& other);
        ~Stack() { 
            clear();
        }
        
        Stack& operator=(const Stack& other); // Operador de Atribuição

        // Getters dos atributos.
        int getId();
        Pack_Node* getTop();
        int getSize();

        // Setter do id.
        void setId(int id);

        // Empilha um item.
        void push(Package* new_item);

        // Desempilha um item.
        Package* pop();

        // Desempilha todos os itens.
        void clear();

        // Verifica se a pilha está vazia.
        int isEmpty();

    private:
        Pack_Node* top; // Nó do topo da pilha.
        int size;       // Tamanho da pilha.
        int id;         // id da pulha.
}; 

#endif