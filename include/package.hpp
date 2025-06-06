#ifndef PACK_HPP
#define PACK_HPP

#include <string>
#include "./list.hpp"

typedef int id;

class Package {
    public:
        Package() : id(-1), post_date(0), origin_warehouse_id(0),
                    destination_warehouse_id(0), sender(NULL),
                    recipient(NULL), type(NULL), route()  {}

        Package(id id, int post_date, std::string sender, std::string recipient,
                std::string type, int origin_warehouse_id, int destination_warehouse_id) : 

                id(id), post_date(post_date), sender(sender), recipient(recipient),
                type(type), origin_warehouse_id(origin_warehouse_id),
                destination_warehouse_id(destination_warehouse_id)  {}
        
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
        id id;
        int post_date;
        int origin_warehouse_id;
        int destination_warehouse_id;
        List route;
        std::string sender;
        std::string recipient;
        std::string type;
};

#endif