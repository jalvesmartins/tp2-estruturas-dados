#include "../include/warehouse.hpp"
#include "../include/list.hpp"
#include "../include/node.hpp"

void Warehouse::storePackage(int session, Package* pack) {
    // Pega o início da lista de seções.
    typename List<Stack>::L_Node* aux_node = sessions.getHead();

    // Encontra a seção alvo.
    while (aux_node != nullptr && aux_node->data.getId() != session) {
        aux_node = aux_node->next;
    }

    // Empilha o pacote.
    if (aux_node != nullptr) {
        aux_node->data.push(pack);
    }
    
    return;
}

void Warehouse::addSession(int edge_id) {
    Stack new_session;
    new_session.setId(edge_id);
    sessions.pushBack(new_session);
}

List<Stack>& Warehouse::getSessions() {
    return this->sessions;
}

id Warehouse::getId() {
    return this->w_id;
}

void Warehouse::setId(::id id) {
    this->w_id = id;
}