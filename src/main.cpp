#include <iostream>

#include "../include/graph.hpp"

int main () {

    //Instancia o grafo de armazéns, chamado hanoi.
    Graph hanoi;
    int warehouse_count = 0;
    
    std::cin >> warehouse_count; // Número de armazéns.

    //Leitura dos armazéns e das conexões entre os armazéns.
    hanoi.readNodes(warehouse_count);
    hanoi.readEdges(warehouse_count);


return 0;
}