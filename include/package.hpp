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
        Package() : pack_id(-1), status(NAO_FOI_POSTADO), post_date(0), origin_warehouse_id(0),
                    destination_warehouse_id(0), route(), sender(NULL),
                    recipient(NULL), type(NULL)  {}

        Package(id id , int post_date, std::string sender, std::string recipient,
                std::string type, int origin_warehouse_id, int destination_warehouse_id) : 

                pack_id(id),  status(NAO_FOI_POSTADO), post_date(post_date), origin_warehouse_id(origin_warehouse_id),
                destination_warehouse_id(destination_warehouse_id), route(), sender(sender), recipient(recipient),
                type(type) {}
        
        ~Package() = default;

        id getId();
        void setId(id new_id);

        int getPostDate();
        void setPostDate(int new_pd);

        int getOriginWarehouseId();
        void setOriginWarehouseId(int new_ow_id);

        int getDestinationWarehouseId();
        void setDestinationWarehouseId(int new_dw_id);

        std::string getSender();
        void setSender(std::string new_sender);

        std::string getRecipient();
        void setRecipient(std::string new_recipient);

        std::string getType();
        void setType(std::string new_type);

    private:
        id pack_id;
        packageStatus status;
        int post_date;
        int origin_warehouse_id;
        int destination_warehouse_id;
        List<int> route;
        std::string sender;
        std::string recipient;
        std::string type;

        int exp_stay_time;
        int stored_time;
        int transit_time;
        int most_recent_change;
};

#endif