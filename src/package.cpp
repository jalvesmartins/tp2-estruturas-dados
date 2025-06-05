#include "../include/package.hpp"

Key Package::getKey() {
    return this->k;
}

Key Package::setKey(Key* new_k) {
    this->k = *new_k;
}

Load Package::getLoad() {
    return this->l;
}

Load Package::setLoad(Load* new_l) {
    this->l = *new_l;
}