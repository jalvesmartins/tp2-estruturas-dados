#include <iostream>

#include "../include/graph.hpp"

int main () {
    int transport_capacity = 0; //Capacidade do transporte.
    int transport_latency = 0; //Latência do transporte.
    int transport_gap = 0;     //Intervalo entre um transporte e o outro.
    int removal_cost = 0;       //Custo de remoção de um pacote;
    int warehouse_count = 0;    //Número total de armazéns.
    int pack_count = 0;

    //Faz a leitura das variáveis globais;
    std::cin >> transport_capacity >> transport_latency
             >> transport_gap >> removal_cost >> warehouse_count;

    //Instancia o grafo de armazéns, chamado hanoi.
    Graph hanoi;
    int warehouse_count = 0;
    
    std::cin >> warehouse_count; // Número de armazéns.

    //Leitura dos armazéns e das conexões entre os armazéns.
    hanoi.readNodes(warehouse_count);
    hanoi.readEdges(warehouse_count);

    //Leitura dos pacotes.
    std:: cin >> pack_count;

    int pack_post_time = 0;
    int pack_id = 0;
    int origin_wh_id = 0;
    int destination_wh_id = 0;
 
    for (int i = 0; i < pack_count; i++) {
        std::cin >> pack_post_time >> pack_id
        >> origin_wh_id >> destination_wh_id;
        
    }
return 0;
}