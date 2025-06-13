#include "./package.hpp"
#include "./event.hpp"
#include "./graph.hpp"
#include "./queue.hpp"
#include "./scheduler.hpp"

class Transport {
    public:
        Transport(int transport_capacity ,int transport_latency, int transport_gap,
            int removal_cost, int warehouse_count) :

            time(transport_gap), transport_capacity(transport_capacity) , transport_latency(transport_latency), transport_gap(transport_gap),
            removal_cost(removal_cost), warehouse_count(warehouse_count), packs_delivered(0) {}

        ~Transport() = default;

        void calculateRoute(Graph* graph, Package* pack);
        void executeEvent(Scheduler* admin, Graph* graph);
        void createTransports(Scheduler* admin, Graph* graph);
        void createNextEvent(Scheduler* admin, Graph* graph, Package* pack);
        void transportPackages(Scheduler* admin, Graph* graph, int transport_capacity, int time, Warehouse* origin, Warehouse* destination);
        int getDeliveredPacks();
        int getTime();

        void addTime(int time);
        void addTimePack(Package* pack, int time);
        

    private:
        int time;               //Horário
        int transport_capacity; //Capacidade do transporte.
        int transport_latency;  //Latência do transporte.
        int transport_gap;      //Intervalo entre um transporte e o outro.
        int removal_cost;       //Custo de remoção de um pacote;
        int warehouse_count;    //Número total de armazéns.
        int packs_delivered;
};