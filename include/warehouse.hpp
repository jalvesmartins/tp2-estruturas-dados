#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "./stack.hpp"

class Warehouse {
    public:
        Warehouse() : w_id(-1), sessions() {}
        Warehouse(int id) : w_id(id), sessions() {}
        ~Warehouse() {
            while (!getSessions().is_empty()) {
                getSessions().pop_front();
            }
        }

        void setId(id id);
        id getId();

        void storePackage(int session_id, Package* pack);
        //Package* getPackage(int session_id, int id);

        void addSession(int edge_id);
        void removeSession(int edge_id);

        List<Stack>& getSessions();

    private:
        id w_id;
        List<Stack> sessions;
};

#endif