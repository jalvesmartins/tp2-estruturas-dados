#include "../include/item.hpp"

Key Item::getKey() {
    return this->k;
}

Key Item::setKey(Key* new_k) {
    this->k = *new_k;
}

Load Item::getLoad() {
    return this->l;
}

Load Item::setLoad(Load* new_l) {
    this->l = *new_l;
}