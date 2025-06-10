#include <iostream>

#include "../include/graph.hpp"
#include "../include/transport.hpp"
#include "../include/scheduler.hpp"
#include <limits>

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

    //Leitura dos armazéns e das conexões entre os armazéns.
    hanoi.readNodes(warehouse_count);
    hanoi.readEdges(warehouse_count);

    //Leitura dos pacotes.
    std:: cin >> pack_count;

    Transport transport(transport_capacity, transport_latency, transport_gap, 
                    removal_cost, warehouse_count, pack_count);

    // REVISAR
    Scheduler admin(pack_count * warehouse_count);
 
    for (int i = 0; i < pack_count; i++) {
        int pack_post_time = 0;
        int pack_id = 0;
        int origin_wh_id = 0;
        int destination_wh_id = 0;
        std::string s_pac, s_org, s_dst;

        std::cin >> pack_post_time >> s_pac >> pack_id >> s_org >> origin_wh_id >> s_dst >> destination_wh_id;

        // 2. VERIFICA SE A LEITURA FALHOU
        if (std::cin.fail()) {
            std::cerr << "ERRO: Erro ao ler a linha do pacote com índice " << i << ". Pulando linha.\n";
            
            // 3. CICLO DE CORREÇÃO
            std::cin.clear(); // Passo 1: Reseta o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Passo 2: Limpa a linha ruim do buffer
            
            continue; // Pula para a próxima iteração do loop
        }

        Package* pack = new Package(pack_post_time, pack_id, origin_wh_id, destination_wh_id);

        transport.calculateRoute(&hanoi, pack);

        admin.scheduleEvent(1, pack->getPostDate(), pack, &(hanoi.findWHouseNode(pack->getOriginWarehouseId())->warehouse), 
                                                          &(hanoi.findWHouseNode(pack->getDestinationWarehouseId())->warehouse));

        
    }

return 0;
}