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

void Package::setRoute(List<int>& route) {
    this->route = route;
}

void Package::addTime(int time) {
    this->pack_time += time;
}

int Package::getTime() {
    return this->pack_time;
}

int Package::isRouteEmpty() {
    return route.getHead() == nullptr;
}