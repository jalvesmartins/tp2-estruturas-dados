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

Package* Event::getPack() {
    return this->pack;
}

Warehouse* Event::getDestination() {
    return this->destination;
}

Warehouse* Event::getOrigin() {
    return this->origin;
} 

void Event::resetEvent() {
    strcpy(this->key, "0000000000000");
    this->pack = nullptr;
    this->origin = nullptr;
    this->destination = nullptr;
    return;
}

// Compara o valor numérico das chaves.
bool operator<(Event& a, Event& b) {
    return strcmp(a.getKey(), b.getKey()) < 0;
}