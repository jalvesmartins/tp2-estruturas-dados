#include "../include/event.hpp"
#include <cstring>

int Event::getTime() {
    return this->post_time;
}

int Event::getType() {
    return this->key[12];
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

void Event::resetEvent() {
    strcpy(this->key, "0000000000000");
    this->pack = nullptr;
    this->origin = nullptr;
    this->destination = nullptr;
    return;
}