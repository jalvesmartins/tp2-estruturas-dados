#include "../include/transport.hpp"

void Transport::calculateRoute(Graph* graph, Package* pack) {
    Queue queue;
    List<int> route;

    int origin_id = pack->getOriginWarehouseId();
    int destination_id = pack->getDestinationWarehouseId();
    int size = this->warehouse_count;


    int* parents = new int[size + 1];
    bool* visited = new bool[size + 1];
    for (int i = 0; i <= size; ++i) {
        parents[i] = -1; // -1 significa que não tem pai
        visited[i] = false;
    }

    queue.enqueue(origin_id);
    visited[origin_id] = true;

    while (!queue.isEmpty()) {
        id whouse_id = queue.dequeue();

        if (whouse_id == destination_id) break; // Encontrou o destino, pode parar a busca

        WHouse_Node* present_node = graph->findWHouseNode(whouse_id);  // Reutiliza a função de busca de nó
        if (present_node == nullptr) {
            // Se o nó não existe no grafo, imprima um aviso e continue
            std::cerr << "AVISO: Armazém com ID " << whouse_id << " não encontrado no grafo." << std::endl;
            continue;
        }

        Edge_Node* edge = present_node->edges;
        while (edge != nullptr) {
            id edge_id = edge->e_id;
            if (!visited[edge_id]) {
                visited[edge_id] = true;
                parents[edge_id] = whouse_id; // Registra de onde viemos
                queue.enqueue(edge_id);
            }
            edge = edge->next;
        }
    }

    if (parents[destination_id] == -1) {
        delete[] parents;
        delete[] visited;
        return; // Retorna nulo para indicar que não há caminho
    }
        for (int i = destination_id; i != -1; i = parents[i]) {
        // Adiciona o novo nó no INÍCIO da lista, o que já inverte a ordem para nós
        route.push_front(i);
    }

    // Deleta os vetores alocados
    delete[] parents;
    delete[] visited;

    pack->setRoute(route); // Atrinui a rota calculada ao pacote.
    return;
}

void Transport::addTime(Package* pack, int time) {
    pack->addTime(time);
}

void Transport::executeEvent(Scheduler* admin, Graph* graph) {
    Event executed_event = admin->removeEvent();

    switch (executed_event.getType()) {
        case 1: {
            WHouse_Node* warehouse = graph->findWHouseNode(executed_event.getOriginId());
            int session = executed_event.getDestinationId();
            Package* pack = executed_event.getPack();
            warehouse->warehouse.storePackage(session, pack);
            printf("%07d pacote %03d armazenado em %03d na secao %03d\n", 
            pack->getTime(), pack->getId(), warehouse->n_id, session);

            break;
        }
        case 2: {
            break;

        }

        default: {
            break;
        }
    }
    
    int wh_id = executed_event.getOriginId();
    WHouse_Node* wh_node = graph->findWHouseNode(wh_id);
    
}