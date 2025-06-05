#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "./stack.hpp"

class Warehouse {
    public:
        Warehouse() : sessions(nullptr) {}
        Warehouse(int session_count) {
            sessions = new Stack[session_count];
        }

        ~Warehouse() {
            delete[] sessions;
        };

        void storePackage(Package* pack);
        Package* getPackage(int session, int id);

        void setId(id id);
        id getId();

    private:
        id w_id;
        Stack* sessions;
};

#endif