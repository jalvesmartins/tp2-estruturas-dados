#include "../include/package.hpp"

::id Package::getId() {
    return this->pack_id;
}

int Package::getPostDate() {
    return this->post_date;
}

int Package::getOriginWarehouseId() {
    return this->origin_warehouse_id;
}

int Package::getDestinationWarehouseId() {
    return this->destination_warehouse_id;
}

std::string Package::getSender() {
    return this->sender;
}

std::string Package::getRecipient() {
    return this->recipient;
}

std::string Package::getType() {
    return this->type;
}

void Package::setId(::id new_id) {
    this->pack_id = new_id;
}

void Package::setPostDate(int new_pd) {
    this->post_date = new_pd;
}

void Package::setOriginWarehouseId(int new_ow_id) {
    this->origin_warehouse_id = new_ow_id;
}

void Package::setDestinationWarehouseId(int new_dw_id) {
    this->destination_warehouse_id = new_dw_id;
}

void Package::setSender(std::string new_sender) {
    this->sender = new_sender;
}

void Package::setRecipient(std::string new_recipient) {
    this->recipient = new_recipient;
}

void Package::setType(std::string new_type) {
    this->type = new_type;
}