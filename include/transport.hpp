#include "./package.hpp"
#include "./event.hpp"
#include "./graph.hpp"
#include "./queue.hpp"

class Transport {
    public:
        Transport(int transport_capacity ,int transport_latency, int transport_gap,
            int removal_cost, int warehouse_count, int pack_count) :

            transport_capacity(transport_capacity) , transport_latency(transport_latency), transport_gap(transport_gap),
            removal_cost(removal_cost), warehouse_count(warehouse_count), pack_count(pack_count) {}

        ~Transport() = default;

        void calculateRoute(Graph* graph, Package* pack);

    private:
        int transport_capacity; //Capacidade do transporte.
        int transport_latency;  //Latência do transporte.
        int transport_gap;      //Intervalo entre um transporte e o outro.
        int removal_cost;       //Custo de remoção de um pacote;
        int warehouse_count;    //Número total de armazéns.
        int pack_count;
};