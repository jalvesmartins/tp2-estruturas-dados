#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "./stack.hpp"

class Warehouse {
    public:
        Warehouse() : sessions(nullptr) {}
        Warehouse(int id) : w_id(id) {}

        ~Warehouse() {
            delete[] sessions;
        };

        void storePackage(Package* pack);
        Package* getPackage(int session, int id);

        void setId(id id);
        id getId();

        void initializeSessions(int session_count);

    private:
        id w_id;
        Stack* sessions;
};

#endif