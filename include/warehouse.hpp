#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "./stack.hpp"

class Warehouse {
    public:
        // Construtores e destrutor.
        Warehouse() : w_id(-1), sessions() {}
        Warehouse(int id) : w_id(id), sessions() {}
        ~Warehouse() {
            while (!getSessions().isEmpty()) {
                getSessions().popFront();
            }
        }

        // Getters
        id getId();
        List<Stack>& getSessions();

        // Setter do id.
        void setId(id id);

        // Armazena o pacote em uma seção passada por parâmetro.
        void storePackage(int session_id, Package* pack);

        // Adiciona uma seção ao armazém.
        void addSession(int edge_id);

    private:
        id w_id;    // id do armazém.
        List<Stack> sessions;   // Lista de pilhas de pacotes, chamadas de seções.
};

#endif