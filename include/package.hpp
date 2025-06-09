#ifndef PACK_HPP
#define PACK_HPP

#include <string>
#include "./list.hpp"

typedef int id;

enum packageStatus {
    NAO_FOI_POSTADO,
    CHEGADA_ESCALONADAA_EM_UM_ARMAZEM,
    CHEGOU_MAS_NAO_FOI_ARMAZENADO,
    ARMAZENADO_EM_UM_ARMAZEM,
    ALOCADO_PARA_TRANSPORTE,
    ENTREGUE
};

//ADD LOGICA INICIALIZAÇÂO ROTAS
class Package {
    public:
        Package() : pack_id(-1), status(NAO_FOI_POSTADO), post_date(0), origin_warehouse_id(-1),
                    destination_warehouse_id(-1), route() {}

        Package(int post_date, id id, int origin_warehouse_id, int destination_warehouse_id) : 

                post_date(post_date), pack_id(id),  status(NAO_FOI_POSTADO), origin_warehouse_id(origin_warehouse_id),
                destination_warehouse_id(destination_warehouse_id), route(), pack_time(post_date) {}
        
        ~Package() = default;

        id getId();
        int getPostDate();
        int getOriginWarehouseId();
        int getDestinationWarehouseId();

    private:
        id pack_id;
        packageStatus status;
        int post_date;
        int origin_warehouse_id;
        int destination_warehouse_id;
        List<int> route;

        int pack_time;
};

#endif