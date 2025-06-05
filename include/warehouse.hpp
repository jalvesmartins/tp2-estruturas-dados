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

    private:
        Stack* sessions;
};

#endif