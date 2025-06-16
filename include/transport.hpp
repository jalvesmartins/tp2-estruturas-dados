#include "./package.hpp"
#include "./event.hpp"
#include "./graph.hpp"
#include "./queue.hpp"
#include "./scheduler.hpp"

class Transport {
    public:
        // Construtores e destrutor.
        Transport(int transport_capacity ,int transport_latency, int transport_gap,
            int removal_cost, int warehouse_count) :

            time(transport_gap), transport_capacity(transport_capacity) , transport_latency(transport_latency), transport_gap(transport_gap),
            removal_cost(removal_cost), warehouse_count(warehouse_count), packs_delivered(0) {}

        ~Transport() = default;
        
        // Getters dos atrubutos
        int getDeliveredPacks();
        int getTime();

        // Calcula a rota de um pacote, implementando o algoritmo BFS.
        void calculateRoute(Graph* graph, Package* pack);

        // Executa um evento. Trata ambos os tipos de evento, usando um switch case.
        void executeEvent(Scheduler* admin, Graph* graph);

        // Cria e escalona os primeiros eventos de transportes entre todas as arestas.
        void createTransports(Scheduler* admin, Graph* graph);
        
        // Executa o transporte entre duas arestas. Desempilha e reempilha os pacotes,
        // escalona as chegadas e registra as estatísticas.
        void transportPackages(Scheduler* admin, Graph* graph, int transport_capacity, int time, Warehouse* origin, Warehouse* destination);
        
        // Adiciona tempo ao horário do transportador.
        void addTime(int time);

    private:
        int time;               // Horário
        int transport_capacity; // Capacidade do transporte.
        int transport_latency;  // Latência do transporte.
        int transport_gap;      // Intervalo entre um transporte e o outro.
        int removal_cost;       // Custo de remoção de um pacote;
        int warehouse_count;    // Número total de armazéns.
        int packs_delivered;    // Número de pacotes entregues.
};