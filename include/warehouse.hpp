#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "./stack.hpp"

class Warehouse {
    public:
        Warehouse() : w_id(-1), sessions(nullptr) {}
        Warehouse(int id) : w_id(id), sessions(nullptr) {}

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