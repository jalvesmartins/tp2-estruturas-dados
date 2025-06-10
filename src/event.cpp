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

// Retorna 'true' se 'a' tiver MAIOR prioridade que 'b'.
bool operator<(Event& a, Event& b) {
    // 1. Critério primário: TEMPO
    // Se os tempos são diferentes, o de menor tempo tem maior prioridade.
    if (a.getTime() != b.getTime()) {
        return a.getTime() < b.getTime();
    }

    // 2. Critério de desempate: TIPO DE EVENTO
    // Se os tempos são iguais, o de menor tipo tem maior prioridade.
    if (a.getType() != b.getType()) {
        return a.getType() < b.getType();
    }

    // 3. Critério final: DADOS ESPECÍFICOS DO EVENTO
    // Se tempo e tipo são iguais, a comparação final depende do tipo.
    if (a.getType() == 1) {
        // Ambos são eventos de Pacote. Desempata pelo ID do pacote.
        return a.getPackId() < b.getPackId();
    } else { // a.getType() == 2
        // Ambos são eventos de Transporte.
        // Desempata primeiro pela origem, depois pelo destino.
        if (a.getOriginId() != b.getOriginId()) {
            return a.getOriginId() < b.getOriginId();
        }
        // Se as origens são iguais, desempata pelo destino.
        return a.getDestinationId() < b.getDestinationId();
    }
}