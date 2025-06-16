#ifndef PACK_HPP
#define PACK_HPP

#include <string>
#include "./list.hpp"

// Define o tipo do id como inteiro.
typedef int id;

// Enumera os status possíveis para o pacote.
enum packageStatus {
    NULO,
    NAO_FOI_POSTADO,
    CHEGADA_ESCALONADAA_EM_UM_ARMAZEM,
    CHEGOU_MAS_NAO_FOI_ARMAZENADO,
    ARMAZENADO_EM_UM_ARMAZEM,
    ALOCADO_PARA_TRANSPORTE,
    ENTREGUE
};

class Package {
    public:
        Package() : pack_id(-1), status(NULO), post_date(0), origin_warehouse_id(-1),
                    destination_warehouse_id(-1), route(), pack_time(0) {}

        Package(int post_date, id id, int origin_warehouse_id, int destination_warehouse_id) : 

                pack_id(id), status(NULO), post_date(post_date), origin_warehouse_id(origin_warehouse_id),
                destination_warehouse_id(destination_warehouse_id), route(), pack_time(post_date) {}
        
        ~Package() = default;

        // Getters dos atributos.
        id getId();
        int getPostDate();
        int getOriginWarehouseId();
        int getDestinationWarehouseId();
        int getRouteFront();
        int getTime();

        // Setters dos atributos.
        void setTime(int time);
        void setRoute(List<int>& route);

        // Tira o primeiro elemento da lista de rotas.
        void popRoute();

        // Verifica se a lista de rotas está vazia.
        int isRouteEmpty();

    private:
        id pack_id; // id do pacote.
        packageStatus status; // Status do pacote.
        int post_date;  // Tempo de postagem do pacote.
        int origin_warehouse_id;    // id do armazém de origem.
        int destination_warehouse_id;   // id do armazém de destino.
        List<int> route;    // Lista que contém a rota.
        int pack_time;  // "Horário" do pacote, usado para a simulação de eventos discretos.
};

#endif