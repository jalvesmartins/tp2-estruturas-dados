#include "../include/transport.hpp"

int Transport::getDeliveredPacks() {
    return this->packs_delivered;
}

int Transport::getTime() {
    return this->time;
}

void Transport::calculateRoute(Graph* graph, Package* pack) {
    //Implementação do BFS abaixo. Utiliza a queue.
    Queue queue;
    List<int> route;

    int origin_id = pack->getOriginWarehouseId();
    int destination_id = pack->getDestinationWarehouseId();
    int size = this->warehouse_count;

    // Cria os vetores de visitados e vetor dos pais dos nós.
    int* parents = new int[size + 1];
    bool* visited = new bool[size + 1];

    for (int i = 0; i <= size; ++i) {
        parents[i] = -1; // -1 significa que não tem pai
        visited[i] = false;
    }

    // Começa com o armazém inicial, nesse caso, o armazém de chegada.
    queue.enqueue(origin_id);
    visited[origin_id] = true;

    while (!queue.isEmpty()) {
        id whouse_id = queue.dequeue();

        if (whouse_id == destination_id) break; // Encontrou o destino, pode parar a busca

        WHouse_Node* present_node = graph->findWHouseNode(whouse_id);  // Reutiliza a função de busca de nó
        if (present_node == nullptr) {
            // Se o nó não existe no grafo, imprima um aviso e continue
            std::cerr << "ERRO: Armazém com ID " << whouse_id << " não existe." << std::endl;
            continue;
        }

        Edge_Node* edge = present_node->edges;

        // Enfileira os nós vizinhos e registra o pai do nó visitado.
        while (edge != nullptr) {
            id edge_id = edge->e_id;

            if (!visited[edge_id]) {
                visited[edge_id] = true;
                parents[edge_id] = whouse_id;
                queue.enqueue(edge_id);
            }

            edge = edge->next;
        }
    }

    // Retorna nulo caso não haja caminho
    if (parents[destination_id] == -1) {
        delete[] parents;
        delete[] visited;
        return;
    }
        for (int i = destination_id; i != -1 && i != pack->getOriginWarehouseId(); i = parents[i]) {
        // Após encontrar o nó target, caminha o grafo pra trás e adiciona os nós no caminho na lista de rota.
        route.pushFront(i);
    }

    // Deleta os vetores alocados
    delete[] parents;
    delete[] visited;

    pack->setRoute(route); // Atrinui a rota calculada ao pacote.
    return;
}

void Transport::addTime(int time) {
    this->time += time;
}

void Transport::executeEvent(Scheduler* admin, Graph* graph) {
    // Remove evento do heap.
    Event executed_event = admin->removeEvent();

    // Switch case no tipo de evento.
    switch (executed_event.getType()) {

        // Evento de armazenamento.
        case 1: {
            Package* pack = executed_event.getPack();

            // Se o armazém que ele será armazenado é o de entrega, anuncia a lógica de entrega e deleta o pacote.
            if (executed_event.getOriginId() == pack->getDestinationWarehouseId()) {

                //Imprime estatísticas.
                printf("%07d pacote %03d entregue em %03d\n", 
                executed_event.getTime(), pack->getId(), executed_event.getOriginId());

                delete pack;
                
                this->packs_delivered++;    // Aumenta o contador de pacotes entregues.

            // Caso contrário, armazena o pacote normalmente.
            } else {
                Warehouse* warehouse = executed_event.getOrigin();
                int session = executed_event.getDestinationId();

                // Armazena o pacote.
                warehouse->storePackage(session, pack);

                //Imprime estatísticas.
                printf("%07d pacote %03d armazenado em %03d na secao %03d\n",
                executed_event.getTime(), pack->getId(), warehouse->getId(), session);
            }

            break;
        }

        // Evento de transporte.
        case 2: {
            
            // Chama o transporte entre os armazéns do evento.
            transportPackages(admin, graph, executed_event.getTime(), transport_capacity, executed_event.getOrigin(), executed_event.getDestination());

            // Escalona o próximo transporte entre esses dois armazéns. 
            admin->scheduleEvent(2, executed_event.getTime() + transport_gap, nullptr, executed_event.getOrigin(), executed_event.getDestination());

            break;
        }

        default: { break; }
    }
}

void Transport::createTransports(Scheduler* admin, Graph* graph) {
    WHouse_Node* aux_warehouse = graph->getGraph();
    Edge_Node* aux_edge = nullptr;

    // Escalona os transportes para todas as arestas.
    for (int i = 0; i < warehouse_count; i++) {
        aux_edge = aux_warehouse->edges;
        while (aux_edge != nullptr) {
            admin->scheduleEvent(2, this->time, nullptr, &aux_warehouse->warehouse, &graph->findWHouseNode(aux_edge->e_id)->warehouse);
            aux_edge = aux_edge->next; 
        }

        aux_warehouse = aux_warehouse->next;
    }

}

void Transport::transportPackages(Scheduler* admin, Graph* graph, int time, int transport_capacity, Warehouse* origin, Warehouse* destination) {
    int session_time = time;    // Tempo interno desse transporte.

    // Cria a pilha e nó auxiliar.
    Stack aux_stack;
    typename List<Stack>::L_Node* aux_node = origin->getSessions().getHead();

    // Encontra a sessão correta.
    while (aux_node != nullptr && aux_node->data.getId() != destination->getId()) {
        aux_node = aux_node->next;
    }

    // Retorna se a sessão não existe.
    if (aux_node == nullptr) {
        return;
    }

    // Guarda o endereço da stack original.
    Stack& stack = aux_node->data;

    // Desempilha todos os pacotes.
    while (stack.getSize() > 0) {
        Package* removed = stack.pop(); // Remove pacote.
        session_time += removal_cost;   // Atualiza tempo do pacote.
        removed->setTime(session_time);

        // Imprime estatísticas
        printf("%07d pacote %03d removido de %03d na secao %03d\n", 
        removed->getTime(), removed->getId(), origin->getId(), destination->getId());
        
        // Empilha o pacote na pilha auxiliar.
        aux_stack.push(removed);
    }

    // Para os pacotes target, criamos os eventos de entrega no próximo armazém
    for (int i = 0; i < transport_capacity; i++) {
        if (aux_stack.isEmpty()) {
            break; // Sai do loop se não houver mais pacotes para transportar
        }

        Package* target_pack = aux_stack.pop();

        printf("%07d pacote %03d em transito de %03d para %03d\n", 
        session_time, target_pack->getId(), origin->getId(), destination->getId());

        // Atualiza a rota dos pacotes.
        target_pack->popRoute();
        
        // Se a rota está vazia, o próximo destino é o de chegada. Essa verificação
        // evita uma ação de pop em uma lista vazia.
        if (target_pack->isRouteEmpty()) {

            session_time += transport_latency;
        
            // Marca o evento.
            admin->scheduleEvent(1, session_time, target_pack, destination, nullptr);

            // Volta o tempo para o atual.
            session_time -= transport_latency;

            continue;
        }

        // Pega o próximo destino do pacote.
        int next_session = target_pack->getRouteFront();

        // Atualiza o tempo para o tempo de chegada no próximo armazém.
        session_time += transport_latency;
        
        // Escalona o evento.
        admin->scheduleEvent(1, session_time, target_pack, destination, &graph->findWHouseNode(next_session)->warehouse);

        // Volta o tempo para o atual.
        session_time -= transport_latency;
    }

    // Esvazia a pilha auxiliar e imprime o rearmazenamento.
    while (aux_stack.getSize() != 0) {
        Package* removed2 = aux_stack.pop();
        stack.push(removed2);

        printf("%07d pacote %03d rearmazenado em %03d na secao %03d\n", 
        session_time, removed2->getId(), origin->getId(), destination->getId());
    }

    return;
}