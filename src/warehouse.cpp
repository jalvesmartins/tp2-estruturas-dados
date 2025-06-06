#include "../include/warehouse.hpp"

void Warehouse::storePackage(int session, Package* pack) {
    sessions[session].push(pack);
}

Package* Warehouse::getPackage(int session, int id) {
    Stack aux_stack;
    Node* aux_node = sessions[session].getTop();

    while (aux_node->pack.getId() != id) {
        Package* removed = sessions[session].pop();

        aux_stack.push(removed);

        aux_node = sessions[session].getTop();
    }

    Package* pack = sessions[session].pop();

    while(aux_stack.getSize() != 0) {
        Package* removed2 = aux_stack.pop();
        this->sessions[session].push(removed2);
    }

    return pack;
}

void Warehouse::setId(::id id) {
    this->w_id = id;
}

id Warehouse::getId() {
    return this->w_id;
}

void Warehouse::initializeSessions(int session_count) {
    this->sessions = new Stack[session_count];
}