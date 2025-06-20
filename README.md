# tp2-estruturas-dados

Este projeto implementa um sistema de escalonamento logístico para os "Armazéns Hanoi", inspirado no problema das Torres de Hanói. [cite_start]O sistema foi desenvolvido como parte da disciplina de Estruturas de Dados da Universidade Federal de Minas Gerais (UFMG). 

## Descrição do Problema

O sistema logístico automatiza o envio e armazenamento de pacotes entre armazéns. Os pacotes chegam a um armazém de origem, têm sua rota calculada e são transportados até um armazém de destino. Os armazéns são organizados em seções, onde cada seção é uma pilha que opera no princípio LIFO (Last-In First-Out), simulando as Torres de Hanói. Isso significa que, para remover um pacote que não está no topo, todos os pacotes acima dele precisam ser removidos primeiro.

O sistema considera parâmetros como tempo de transporte entre armazéns, tempo de remoção de pacote, intervalo entre transportes e capacidade de transporte. O objetivo é escalonar eventos de transporte para que os pacotes cheguem ao seu destino final, visando eliminar aqueles que permanecem armazenados por um tempo excessivo. [cite_start]A simulação é discreta, focando apenas nos momentos em que eventos ocorrem. 

## Estruturas de Dados Implementadas

[cite_start]O código-fonte é modularizado e utiliza as seguintes estruturas de dados e classes personalizadas: 

* **Stack (Pilha)**: Ponto central da implementação, simula as Torres de Hanói, forçando o desempilhamento de todos os pacotes para mover o último. [cite_start]É uma pilha de nós de pacotes e foi implementada usando ponteiros para lidar com o número variado de pacotes, incluindo um ID para facilitar a identificação nas seções. 
* **List (Lista Encadeada)**: Uma lista encadeada convencional, implementada com templates para armazenar diferentes tipos de dados. [cite_start]Facilita a inserção e remoção no início e fim da lista, operações frequentemente utilizadas no sistema. 
* **Queue (Fila)**: Uma fila convencional utilizada para a implementação do algoritmo BFS (Breadth-First Search) no grafo de armazéns, que calcula as rotas dos pacotes. [cite_start]Comporta apenas IDs de armazéns (inteiros) e é baseada em nós encadeados devido à variabilidade do tamanho do grafo e das conexões. 
* **Package (Pacote)**: Representa os pacotes com informações básicas e sua rota, que é armazenada em uma lista de inteiros. [cite_start]Inclui um atributo `status` para futuras implementações mais robustas, embora sua lógica não tenha sido implementada neste trabalho. 
* **Warehouse (Armazém)**: Uma classe que representa os armazéns, contendo um ID e uma lista de pilhas de pacotes chamada "sessions". [cite_start]Cada ligação entre dois armazéns resulta em uma nova pilha nesta lista, correspondente ao armazém conectado. 
* **Graph (Grafo)**: Representa a topologia completa dos armazéns como um grafo. Cada armazém é um nó com um ID, o próprio armazém, uma lista encadeada de arestas e um ponteiro para o próximo nó. As conexões são as arestas do grafo. [cite_start]Embora a leitura seja via matriz de adjacência, a implementação usa lista de adjacência e nós de armazéns para facilitar o transporte e manuseio do grafo. 
* **Events (Eventos)**: Uma classe que representa os eventos na simulação discreta, alimentando o escalonador. Os eventos podem ser de dois tipos (transporte e armazenamento) e armazenam atributos cruciais como o pacote e os armazéns envolvidos. [cite_start]A chave do evento, que inclui o tempo e informações sobre o transporte, determina a ordem de execução. 
* **Heap (MinHeap)**: Implementa um minheap de eventos, garantindo que os eventos removidos sejam sempre os "menores" (ordenados pela chave do evento, que prioriza o tempo). [cite_start]É a base do escalonador e foi implementada com um vetor estático. 
* [cite_start]**Scheduler (Escalonador)**: O escalonador de eventos, que encapsula o Heap e fornece funções para adicionar e remover eventos. 
* **Transport (Transporte)**: A peça final do sistema, responsável por todo o mecanismo de transporte. Lida com a manipulação do tempo, cálculo de rotas (BFS), execução e escalonamento de eventos. [cite_start]Também armazena estatísticas de transporte e cria todos os eventos. 

## Fluxo do Programa

[cite_start]O programa opera da seguinte forma: 

1.  [cite_start]**Leitura de Entrada**: Recebe variáveis globais de transporte (intervalo, capacidade, duração, custo de remoção) e a topologia do grafo (matriz de adjacência). 
2.  [cite_start]**Instanciação**: Instancia o grafo, criando armazéns e seções (`readNodes()` e `readEdges()`), além de instanciar o objeto `Transport` e `Scheduler`. 
3.  **Leitura de Pacotes e Cálculo de Rotas**: Lê os dados de cada pacote (tempo de chegada, ID, origem, destino), cria o pacote e calcula sua rota usando BFS (`calculateRoute()`). [cite_start]A rota é armazenada em uma lista dentro do pacote. 
4.  [cite_start]**Escalonamento Inicial**: A chegada de cada pacote no primeiro armazém de sua rota é escalonada usando `scheduleEvent()`. 
5.  [cite_start]**Criação de Transportes Iniciais**: A função `createTransports()` é chamada para escalonar os primeiros eventos de transporte entre todas as arestas do grafo. 
6.  **Loop de Simulação**: Inicia-se um loop que continua enquanto o número de pacotes entregues for menor que o número total de pacotes. [cite_start]Dentro do loop, a função `executeEvent()` é chamada. 
7.  **Execução de Eventos (`executeEvent()`)**:
    * [cite_start]Retira o próximo evento do `Scheduler`. 
    * **Evento de Armazenamento (Tipo 1)**: Verifica se o pacote chegou ao destino final. Se sim, imprime a entrega, deleta o pacote e incrementa o contador de pacotes entregues. [cite_start]Caso contrário, armazena o pacote no armazém e seção correspondentes ao próximo destino. 
    * **Evento de Transporte (Tipo 2)**: Chama a função `transportPackages()`. [cite_start]Após o transporte, escalona o próximo evento de transporte para a mesma aresta, incrementando o tempo. 
8.  [cite_start]**Término da Simulação**: Quando todos os pacotes são entregues, o loop se encerra e o programa termina, imprimindo todas as estatísticas. 

## Análise de Complexidade

[cite_start]A complexidade do sistema foi analisada em termos de tempo e espaço para as funções mais importantes: 

* **Pilha (Stack)**:
    * [cite_start]`push()`: $O(1)$ tempo e $O(1)$ espaço. 
    * [cite_start]`pop()`: $O(1)$ tempo e $O(1)$ espaço. 
* **Lista (List)**:
    * [cite_start]`pushFront()` e `pushBack()`: $O(1)$ tempo e $O(1)$ espaço. 
    * [cite_start]`popFront()` e `popBack()`: $O(1)$ tempo e $O(1)$ espaço. 
    * [cite_start]`front()` e `back()`: $O(1)$ tempo e $O(1)$ espaço. 
* **Fila (Queue)**:
    * [cite_start]`enqueue()`: $O(1)$ tempo e $O(1)$ espaço. 
    * [cite_start]`dequeue()`: $O(1)$ tempo e $O(1)$ espaço. 
* **Grafo (Graph)**:
    * [cite_start]`readNodes()` e `insertNode()`: $O(n)$ tempo e $O(n)$ espaço, onde 'n' é o número de nós. 
    * [cite_start]`readEdges()` e `insertEdge()`: $O(n^2)$ tempo e $O(n^2)$ espaço no pior caso (grafo completo). 
    * [cite_start]`findWHouseNode()`: $O(n)$ tempo e $O(1)$ espaço. 
* **Heap (MinHeap) / Scheduler**:
    * [cite_start]`Heap()` (construtor): $O(1)$ tempo e $O(n \cdot k)$ ou $O(n^2)$ espaço (pacotes x armazéns). 
    * [cite_start]`insert()` (com `bottomHeapfy()`): $O(\log n)$ tempo e $O(1)$ espaço. 
    * [cite_start]`remove()` (com `topHeapfy()`): $O(\log n)$ tempo e $O(1)$ espaço. 
    * [cite_start]`isEmpty()` e `getters()`: $O(1)$ tempo e $O(1)$ espaço. 
* **Package (Pacote)**:
    * [cite_start]Todas as funções (getters/setters): $O(1)$ tempo e $O(1)$ espaço, exceto `setRoute()`. 
    * [cite_start]`setRoute()`: $O(n)$ tempo e $O(n)$ espaço (copia uma lista de 'n' inteiros). 
* **Warehouse (Armazém)**:
    * [cite_start]`storePackage()`: $O(n)$ tempo e $O(1)$ espaço. 
    * [cite_start]`addSession()`: $O(1)$ tempo e $O(1)$ espaço. 
* **Transport (Transporte)**:
    * [cite_start]`calculateRoute()` (BFS): $O(n+a)$ tempo e $O(n)$ espaço, onde 'n' é o número de vértices e 'a' é o número de arestas. 
    * [cite_start]`createTransports()`: $O(n^2 \log n)$ tempo no pior caso (grafo completo) e $O(1)$ espaço. 
    * [cite_start]`transportPackages()`: Aproximadamente $O(n \log n)$ tempo e $O(n)$ espaço. 
    * [cite_start]`executeEvent()`: No pior caso, $O(n \log n)$ tempo e $O(n)$ espaço. 
* [cite_start]**Event (Evento)**: Todas as funções (getters/setters) são $O(1)$ tempo e espaço. 

A complexidade de tempo geral do sistema é aproximadamente $O(n^2 + (p \cdot n + a) + (n^2 \cdot \log n) + w \cdot (p + k + \log n))$, onde 'n' é o número de armazéns (vértices), 'a' é o número de arestas, 'p' é o número de pacotes, 'k' é o número de pacotes transportados, e 'w' é o número de execuções. [cite_start]A complexidade de espaço no pior caso é $O(2 \cdot n^2 + p)$. 

## Estratégias de Robustez

O sistema incorpora mecanismos de programação defensiva para garantir robustez e lidar com falhas e entradas inválidas. [cite_start]As principais estratégias incluem: 

* [cite_start]Verificação da existência e sucesso de abertura do arquivo de entrada. 
* [cite_start]Verificação de tamanhos e posições válidas para listas, pilhas e heap para evitar acessos inadequados. 
* [cite_start]Uso de `default` cases em `switch-case` para proteção contra tipos atípicos de eventos. 
* [cite_start]Liberação da memória de todos os vetores alocados dinamicamente, verificada com Valgrind. 

[cite_start]Em caso de falha, essas verificações retornam `1` (indicando falha na execução do programa) ou `nullptr`. 

## Análise Experimental

A análise experimental foi realizada utilizando a biblioteca `chrono` do C++ para medir o tempo de execução. [cite_start]As entradas foram geradas com scripts Python e os resultados armazenados em arquivos `.csv`, plotados com `matplotlib`. 

* **Número de Pacotes vs. Tempo de Execução**: Com topologia e capacidade de transporte constantes, o tempo de execução cresce linearmente com o aumento do número de pacotes. [cite_start]Isso demonstra a eficiência do sistema em lidar com grandes volumes de pacotes, pois os elementos da complexidade que envolvem a variável 'p' (pacotes) não são os de maior ordem de complexidade quando o número de armazéns é constante. 
* **Número de Armazéns vs. Tempo de Execução**: Mantendo o número de pacotes e a capacidade de transporte constantes, o tempo de execução também cresce linearmente com o aumento do número de armazéns. [cite_start]Isso reforça a eficiência do sistema em ambientes com muitos armazéns.  [cite_start]É importante notar que a esparsidade da matriz de adjacência não foi explorada; um aumento nas arestas poderia levar a um comportamento não-linear devido ao pior caso de $O(n^2 \log n)$ para escalonar eventos de transporte em grafos completos. 
* **Capacidade de Transporte vs. Tempo de Execução**: A análise revela que a capacidade de transporte impacta significativamente o número de inserções e remoções no heap (escalonador). Capacidades menores exigem que o sistema escalone e execute muito mais eventos, o que eleva o tempo de execução. [cite_start]Para 10.000 pacotes e 4 armazéns, variando a capacidade de 1 a 100, os resultados são consistentes com a complexidade esperada de $O(n \log n)$ para a função `executeEvent()`. 

[cite_start]Esses resultados experimentais confirmam a teoria da análise de complexidade, indicando que o escalonador de transportes é mais afetado pelo número de eventos a serem realizados do que pela quantidade de pacotes ou armazéns na topologia. 

## Conclusões

O trabalho demonstrou a implementação e análise de um sistema de escalonamento de eventos de transporte, otimizando a realização de tais eventos com base nos conhecimentos de Estruturas de Dados. As análises experimentais destacam a importância de sistemas que otimizem a ordenação e execução de eventos, mostrando como diferentes configurações de armazéns ou transporte geram resultados distintos. [cite_start]A eficácia do sistema foi comprovada, indicando que, com capacidade de transporte suficiente, ele pode lidar com transportes de forma linear, mesmo com muitos pacotes ou armazéns. 

[cite_start]A realização do projeto evidenciou o impacto direto das decisões de implementação e do uso de diferentes estruturas de dados no funcionamento do produto final, especialmente ao lidar com múltiplas estruturas interconectadas.  [cite_start]O desafio de integrar essas estruturas foi a parte mais interessante e enriquecedora, proporcionando um conhecimento mais amplo sobre TADs e preparando para desafios de computação mais complexos.  [cite_start]O projeto também reforçou a importância de boas práticas de programação e o uso de controle de versão (GitHub) para depuração e construção. 

## Compilação e Execução

Para compilar e executar o programa, siga as instruções abaixo:

1.  Extraia o conteúdo do arquivo `.zip` fornecido.
2.  Adicione o arquivo `.txt` com os dados de entrada na raiz do diretório extraído.
3.  Navegue até o diretório raiz do projeto no terminal.
4.  Execute o seguinte comando:
    ```bash
    make run FILE=nome-arquivo-entrada.txt
    ```
    [cite_start]Este comando compilará e vinculará todos os arquivos, além de executar o programa utilizando o arquivo de entrada especificado. 

## Estrutura do Projeto

O projeto segue a seguinte estrutura de diretórios:

TP
├── src/           # Arquivos de código-fonte (.cpp)
├── bin/           # Executáveis (vazio inicialmente)
├── obj/           # Arquivos objeto (.o) (vazio inicialmente)
├── include/       # Cabeçalhos (.hpp)
└── Makefile       # Arquivo de construção do projeto

O executável gerado será `tp2.out` e estará localizado na pasta `bin/`.

## Requisitos e Restrições

* Linguagem de implementação: C++11.
* Não é permitido o uso de estruturas pré-implementadas por bibliotecas padrão ou de terceiros (ex: `std::queue`, `std::stack`, `std::vector`, `std::list`).
* Não é permitido o uso de smart pointers.
* É permitido o uso do tipo `std::string`.
* Não é permitido usar `std::string` para simular estruturas de dados.
* É permitido usar bibliotecas para tratar exceções e gerenciar memória.