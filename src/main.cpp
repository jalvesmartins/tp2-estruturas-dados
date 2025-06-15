#include <iostream>
#include <fstream>

#include "../include/graph.hpp"
#include "../include/transport.hpp"
#include "../include/scheduler.hpp"

int main (int argc, char* argv[]) {

    // Verificação de segurança.
    if (argc < 2) {
        std::cerr << "ERRO: Nome do arquivo deve ser passado na execução" << std::endl;
        return 1;
    }

    // Cria um stream de entrada a partir do arquivo
    std::ifstream inputFile(argv[1]);

    // Verifica se o arquivo foi aberto com sucesso
    if (!inputFile.is_open()) {
        std::cerr << "ERRO: Não foi possível abrir o arquivo." << std::endl;
        return 1;
    }

    int transport_capacity = 0; //Capacidade do transporte.
    int transport_latency = 0;  //Latência do transporte.
    int transport_gap = 0;      //Intervalo entre um transporte e o outro.
    int removal_cost = 0;       //Custo de remoção de um pacote;
    int warehouse_count = 0;    //Número total de armazéns.
    int pack_count = 0;

    //Faz a leitura das variáveis globais;
    inputFile >> transport_capacity >> transport_latency
             >> transport_gap >> removal_cost >> warehouse_count;

    //Instancia o grafo de armazéns, chamado hanoi.
    Graph hanoi;

    //Leitura dos armazéns e das conexões entre os armazéns.
    hanoi.readNodes(warehouse_count);
    hanoi.readEdges(warehouse_count, inputFile);

    inputFile >> pack_count;

    // Cria o transporte.
    Transport transport(transport_capacity, transport_latency, transport_gap, 
                        removal_cost, warehouse_count);

    // Instancia o escalonador para o tamanho máximo de eventos.
    Scheduler admin(pack_count * warehouse_count);

    // Atribui o valor do primeiro transporte para achar a primeira chegada.
    int first_arrival = transport_gap;
 
    for (int i = 0; i < pack_count; i++) {
        int pack_post_time = 0; // Tempo de chegada do pacote.
        int origin_wh_id = 0;   // id do armazém de origem.
        int destination_wh_id = 0; // id do armazém de chegada.

        // Variáveis para descartar os valores não utilizados do arquivo de entrada
        int dummy_pack_id;
        std::string dummy_label;

        // Leia os dados, mas ignore o ID e os rótulos do arquivo
        inputFile >> pack_post_time >> dummy_label >> dummy_pack_id 
             >> dummy_label >> origin_wh_id 
             >> dummy_label >> destination_wh_id;

        Package* pack = new Package(pack_post_time, i, origin_wh_id, destination_wh_id);

        transport.calculateRoute(&hanoi, pack);

        // Se o tempo de chegada é menor que o first arrival, se torna o first arrival.
        if (pack->getPostDate() < first_arrival) {
            first_arrival = pack->getPostDate();
        }

        // Escalona o evento de chegada do pacote.
        admin.scheduleEvent(1, pack->getPostDate(), pack, &(hanoi.findWHouseNode(pack->getOriginWarehouseId())->warehouse), 
        &(hanoi.findWHouseNode(pack->getRouteFront())->warehouse));

    }

    // Adiciona o tempo da primeira chegada ao transporte.
    transport.addTime(first_arrival);
    
    // Escalona os transportes entre todas as arestas.
    transport.createTransports(&admin, &hanoi);

    // Enquanto houverem pacotes em trânsito, executa os eventos.
    while (transport.getDeliveredPacks() < pack_count) {
        transport.executeEvent(&admin, &hanoi);
    }

return 0;
}