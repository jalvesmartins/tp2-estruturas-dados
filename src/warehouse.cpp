#include "../include/warehouse.hpp"
#include "../include/list.hpp"
#include "../include/node.hpp"


void Warehouse::storePackage(int session, Package* pack) {
    typename List<Stack>::L_Node* aux_node = sessions.getHead();
    while (aux_node->data.getId() != session) {
        aux_node = aux_node->next;
    }
    aux_node->data.push(pack);
    return;
}

Package* Warehouse::getPackage(int session, int id) {
    Stack aux_stack;
    typename List<Stack>::L_Node* aux_node = sessions.getHead();

    // 1. Find the correct session
    while (aux_node != nullptr && aux_node->data.getId() != session) {
        aux_node = aux_node->next;
    }

    // Exit early if the session wasn't found
    if (aux_node == nullptr) {
        return nullptr;
    }

    // Get a REFERENCE to the original stack
    Stack& stack = aux_node->data;

    // 2. Search for the package, moving other packages to aux_stack
    // This loop is correct: it checks size before accessing the element.
    while (stack.getSize() != 0 && stack.getTop()->pack.getId() != id) {
        Package* removed = stack.pop();
        aux_stack.push(removed);
    }

    // 3. Determine the result of the search
    Package* found_pack = nullptr; // Assume not found by default

    // If the stack isn't empty, the loop must have stopped because we found it.
    if (stack.getSize() != 0) {
        // Pop the found package and store it in our result variable.
        found_pack = stack.pop();
    }

    // 4. Unconditionally restore the stack
    // This single block of code now handles restoration for both the "found"
    // and "not found" cases, making the code cleaner (Don't Repeat Yourself).
    while (aux_stack.getSize() != 0) {
        Package* removed2 = aux_stack.pop();
        stack.push(removed2);
    }

    // 5. Return the final result
    // This will be the package pointer if it was found, or nullptr if it wasn't.
    return found_pack;
}

void Warehouse::setId(::id id) {
    this->w_id = id;
}

id Warehouse::getId() {
    return this->w_id;
}

void Warehouse::addSession(int edge_id) {
    Stack* new_session = new Stack;
    new_session->setId(edge_id);
    sessions.push_back(*new_session);
}