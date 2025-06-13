#include <iostream>

#include "../include/graph.hpp"
#include "../include/transport.hpp"
#include "../include/scheduler.hpp"
#include <limits>

int main () {
    int transport_capacity = 0; //Capacidade do transporte.
    int transport_latency = 0;  //Latência do transporte.
    int transport_gap = 0;      //Intervalo entre um transporte e o outro.
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
                        removal_cost, warehouse_count);

    // REVISAR
    Scheduler admin(pack_count * warehouse_count);

    int first_arrival = transport_gap;
 
    for (int i = 0; i < pack_count; i++) {
        int pack_post_time = 0;
        int origin_wh_id = 0;
        int destination_wh_id = 0;

        // Variáveis para descartar os valores não utilizados do arquivo de entrada
        int dummy_pack_id;
        std::string dummy_label;

        // Leia os dados, mas ignore o ID e os rótulos do arquivo
        std::cin >> pack_post_time >> dummy_label >> dummy_pack_id 
             >> dummy_label >> origin_wh_id 
             >> dummy_label >> destination_wh_id;

        // 2. VERIFICA SE A LEITURA FALHOU
        if (std::cin.fail()) {
            std::cerr << "ERRO: Erro ao ler a linha do pacote com índice " << i << ". Pulando linha.\n";
            
            // 3. CICLO DE CORREÇÃO
            std::cin.clear(); // Passo 1: Reseta o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Passo 2: Limpa a linha ruim do buffer
            
            continue; // Pula para a próxima iteração do loop
        }

        Package* pack = new Package(pack_post_time, i, origin_wh_id, destination_wh_id);

        transport.calculateRoute(&hanoi, pack);

        if (pack->getPostDate() < first_arrival) {
            first_arrival = pack->getPostDate();
        }

        admin.scheduleEvent(1, pack->getPostDate(), pack, &(hanoi.findWHouseNode(pack->getOriginWarehouseId())->warehouse), 
        &(hanoi.findWHouseNode(pack->getRouteFront())->warehouse));

    }

    transport.addTime(first_arrival);
    
    transport.createTransports(&admin, &hanoi);

    while (transport.getDeliveredPacks() < pack_count) {
        transport.executeEvent(&admin, &hanoi);
    }

return 0;
}