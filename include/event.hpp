#ifndef EVENT_HPP
#define EVENT_HPP

#include <cstring>
#include "./package.hpp"
#include "./warehouse.hpp"

class Event {
    public:
        // Construtores e destrutor.
        Event() : key("0000000000000"), post_time(0), pack(nullptr), origin(nullptr), destination(nullptr) {} 

        Event(int event_type, int post_time, Package* pack, Warehouse* origin, Warehouse* destination) : 
            post_time(post_time),
            pack(pack),
            origin(origin),
            destination(destination)     
        {
            // Ambos os tipos de evento tem o tempo como prinmeiro atributo, portanto esta fora do switch case.
            snprintf(key, 7, "%06d", post_time);

            // Dependendo do tipo de evento, o construtor modifica a construção da chave do evento.
            switch (event_type) {
                case 1: // Evento de armazenamento.
                    // Só acessa o pacote se ele não for nulo.
                    if (this->pack != nullptr) {
                        snprintf(key + 6, 7, "%06d", this->pack->getId());

                    } else {
                        // Se o pacote for nulo, preenchemos com zeros para manter a chave válida.
                        snprintf(key + 6, 7, "%06d", 0);
                    }

                    key[12] = '1';
                    key[13] = '\0';
                    break;
                    
                case 2: // Evento de transporte.
                    // Só acesse os ponteiros se ambos forem válidos.
                    if (this->origin != nullptr && this->destination != nullptr) {
                        snprintf(key + 6, 4, "%03d", this->origin->getId());
                        snprintf(key + 9, 4, "%03d", this->destination->getId());
                    } else {
                        // Se algum for nulo, preenchemos com zeros.
                        snprintf(key + 6, 7, "%06d", 0);
                    }
                    key[12] = '2';
                    key[13] = '\0';
                    break;

                default:
                    // Segurança, caso o tipo seja incorreto.
                    snprintf(key + 6, 7, "%06d", 0);
                    key[12] = '0';
                    key[13] = '\0';
                    break;
            }
        }

        Event(const Event& other) = default;

        ~Event() = default;

        // Getters dos atributos.
        int getTime();
        int getType();
        char* getKey();
        int getOriginId();
        int getDestinationId();
        Warehouse* getOrigin();
        Warehouse* getDestination();
        int getPackId();
        Package* getPack();

        // Reseta o evento.
        void resetEvent();

    private:
        char key[14];   // Chave.
        int post_time;  // Tempo do evento.
        Package* pack;  // Pacote do evento.
        Warehouse* origin;  // Armazém de origem do evento.
        Warehouse* destination; // Armazém de destino do evento.
};

// Sobrecarga do operador de comparação (Compara o valor numérico das chaves).
bool operator<(Event& a, Event& b);

#endif