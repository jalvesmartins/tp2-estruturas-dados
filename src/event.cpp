#include "../include/event.hpp"
#include <cstring>

int Event::getTime() {
    return this->post_time;
}

int Event::getType() {
    return this->key[12] - '0';
}

int Event::getPackId() {
    return this->pack->getId();
}

int Event::getOriginId() {
    return this->origin->getId();
}

int Event::getDestinationId() {
    return this->destination->getId();
}

char* Event::getKey() {
    return this->key;
}

void Event::resetEvent() {
    strcpy(this->key, "0000000000000");
    this->pack = nullptr;
    this->origin = nullptr;
    this->destination = nullptr;
    return;
}

void Event::printKey() {
    // A variável 'key' é um array de char (C-style string),
    // então podemos passá-la diretamente para o std::cout.
    std::cout << "Event Key: " << this->key;
}

Package* Event::getPack() {
    return this->pack;
}

Warehouse* Event::getDestination() {
    return this->destination;
}

Warehouse* Event::getOrigin() {
    return this->origin;
}

bool operator<(Event& a, Event& b) {
    return strcmp(a.getKey(), b.getKey()) < 0;
}