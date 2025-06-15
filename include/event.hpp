#ifndef EVENT_HPP
#define EVENT_HPP

#include <cstring>
#include "./package.hpp"
#include "./warehouse.hpp"

class Event {
    public:
        Event() : key("0000000000000"), post_time(0), pack(nullptr), origin(nullptr), destination(nullptr) {} 
        Event(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination) : 
            post_time(post_time),
            pack(pack),
            origin(origin),
            destination(destination)     
        {
            snprintf(key, 7, "%06d", post_time);

            switch (event_type) {
                case 1:
                    // VERIFICAÇÃO DE SEGURANÇA: Só acesse 'pack' se ele não for nulo.
                    if (this->pack != nullptr) {
                        snprintf(key + 6, 7, "%06d", this->pack->getId());
                    } else {
                        // Se o pack for nulo, preenchemos com zeros para manter a chave válida.
                        snprintf(key + 6, 7, "%06d", 0);
                    }
                    key[12] = '1';
                    key[13] = '\0';
                    break; // O 'break' que você já havia adicionado corretamente.
                    
                case 2:
                    // VERIFICAÇÃO DE SEGURANÇA: Só acesse os ponteiros se ambos forem válidos.
                    if (this->origin != nullptr && this->destination != nullptr) {
                        snprintf(key + 6, 4, "%03d", this->origin->getId());
                        snprintf(key + 9, 4, "%03d", this->destination->getId());
                    } else {
                        // Se algum for nulo, preenchemos com zeros.
                        snprintf(key + 6, 7, "%06d", 0);
                    }
                    key[12] = '2';
                    key[13] = '\0';
                    break; // << ADICIONADO o 'break' que faltava aqui.

                default:
                    // Agora o default só executa se o tipo não for nem 1 nem 2.
                    // É uma boa ideia ter um estado padrão para a chave em caso de erro.
                    snprintf(key + 6, 7, "%06d", 0);
                    key[12] = '0';
                    key[13] = '\0';
                    break;
            }
        }

        Event(const Event& other) = default;

        ~Event() = default;

        int getTime();
        int getOriginId();
        int getDestinationId();
        int getPackId();
        int getType();
        void resetEvent();

        Warehouse* getOrigin();
        Warehouse* getDestination();

        void printKey();
        Package* getPack();

        char* getKey();

        Event& operator=(Event& other) = default;

    private:
        char key[14];
        int post_time;
        Package* pack;
        Warehouse* origin;
        Warehouse* destination;
};

bool operator<(Event& a, Event& b);

#endif