# Armazéns de Hanói: Um Sistema de Escalonamento de Transporte de Pacotes

[cite_start]Este projeto foi desenvolvido por **João Henrique Alves Martins** ([jalvesmartins16@ufmg.br](mailto:jalvesmartins16@ufmg.br)) como parte do Trabalho Prático 2 para a disciplina de Estruturas de Dados na Universidade Federal de Minas Gerais (UFMG). 

## 1. Visão Geral do Projeto

[cite_start]O "Armazéns de Hanói" é uma simulação de eventos discretos que implementa um sistema de escalonamento para o transporte de pacotes.  [cite_start]O objetivo principal é otimizar a ordem de transporte, priorizando pacotes que estão armazenados por mais tempo, de forma a evitar atrasos excessivos. 

[cite_start]A lógica do sistema é inspirada no clássico problema das **Torres de Hanói**, onde os armazéns utilizam uma estrutura de pilhas (stacks) para guardar os pacotes.  [cite_start]Isso impõe uma restrição de que, para mover um pacote armazenado há mais tempo (no fundo da pilha), todos os pacotes que chegaram depois dele precisam ser removidos primeiro. 

[cite_start]A topologia dos armazéns é representada por um grafo, e as rotas mais curtas para cada pacote são calculadas utilizando o algoritmo de Busca em Largura (BFS). 

## 2. Estruturas de Dados Implementadas

[cite_start]O projeto foi modularizado em diversas classes e Tipos Abstratos de Dados (TADs) para garantir organização e encapsulamento.  As principais estruturas são:

* [cite_start]**`Package`**: Classe que representa os pacotes, armazenando suas informações e a rota a ser seguida. 
* [cite_start]**`Stack`**: TAD central da implementação, simula as pilhas de armazenamento nos armazéns, seguindo a lógica LIFO (Last-In, First-Out), fundamental para a mecânica inspirada em Hanói. 
* [cite_start]**`List`**: Uma lista encadeada genérica (usando templates) que facilita a inserção e remoção de elementos no início, operação frequente no sistema. 
* [cite_start]**`Queue`**: Fila convencional utilizada para a implementação do algoritmo BFS durante o cálculo de rotas no grafo. 
* [cite_start]**`Warehouse`**: Representa um armazém, que contém um ID e uma lista de seções ("sessions"), onde cada seção é uma pilha (`Stack`) de pacotes destinada a um armazém adjacente. 
* [cite_start]**`Graph`**: Modela a topologia da rede de armazéns.  [cite_start]Embora a entrada seja uma matriz de adjacência, a implementação interna utiliza uma lista de adjacências para facilitar a manipulação dos transportes. 
* [cite_start]**`Event`**: Classe que representa os eventos da simulação (armazenamento ou transporte), que são a base para o funcionamento do escalonador. 
* [cite_start]**`Heap`**: Um *min-heap* de eventos, que constitui a base do escalonador.  [cite_start]Ele ordena os eventos de forma crescente por uma chave, garantindo que o próximo evento a ser executado seja sempre o de "menor" valor (mais próximo no tempo). 
* [cite_start]**`Scheduler`**: Uma camada de encapsulamento que utiliza o `Heap` para gerenciar a adição e remoção de eventos. 
* [cite_start]**`Transport`**: A classe orquestradora do sistema, responsável por gerenciar o tempo, calcular rotas (via BFS), executar os eventos e escalonar novos eventos, além de registrar todas as estatísticas. 

## 3. Fluxo de Execução do Programa

1.  [cite_start]**Inicialização**: O programa lê os parâmetros iniciais, como a capacidade de transporte, intervalos, e a topologia da rede de armazéns (fornecida como uma matriz de adjacência).  [cite_start]Em seguida, instancia o Grafo, o Escalonador e o Transportador. 
2.  [cite_start]**Leitura dos Pacotes**: O sistema lê os dados de cada pacote (ID, origem, destino, tempo de chegada). 
3.  [cite_start]**Cálculo de Rota**: Para cada pacote, a rota mais curta é calculada com a função `calculateRoute()` (usando BFS) e armazenada dentro do próprio objeto do pacote. 
4.  [cite_start]**Escalonamento Inicial**: A chegada de cada pacote ao seu primeiro armazém é escalonada como um evento.  [cite_start]Em seguida, a função `createTransports()` é chamada para escalonar o primeiro evento de transporte para cada aresta do grafo. 
5.  [cite_start]**Loop de Simulação**: O sistema entra em um loop que continua enquanto o número de pacotes entregues for menor que o total. 
    * [cite_start]A cada iteração, a função `executeEvent()` retira o próximo evento do escalonador. 
    * [cite_start]**Evento de Armazenamento (Tipo 1)**: Se o pacote chegou ao destino final, uma mensagem é impressa e o contador de pacotes entregues é incrementado.  [cite_start]Caso contrário, o pacote é armazenado na seção correta do armazém atual usando a função `storePackage()`. 
    * [cite_start]**Evento de Transporte (Tipo 2)**: A função `transportPackages()` é chamada.  [cite_start]Os pacotes que estão armazenados há mais tempo são desempilhados e a sua chegada no próximo armazém é escalonada.  [cite_start]Os pacotes restantes são reempilhados.  [cite_start]Por fim, o próximo transporte para essa mesma rota é escalonado, com o tempo incrementado de acordo com o intervalo definido. 
6.  [cite_start]**Fim da Simulação**: O loop termina quando todos os pacotes são entregues, e as estatísticas finais são impressas. 

## 4. Tecnologias Utilizadas

* [cite_start]**Linguagem**: C++ 
* [cite_start]**Compilador**: G++ (GNU Compiler Collection) 
* [cite_start]**Sistema Operacional (Desenvolvimento)**: Linux (Ubuntu) 

## 5. Como Compilar e Executar

Para compilar e executar o projeto, siga as instruções abaixo.

1.  Extraia o conteúdo do arquivo `.zip`.
2.  Adicione um arquivo de texto com os dados de entrada ao diretório extraído.
3.  [cite_start]No terminal, navegue até o diretório e execute o seguinte comando, substituindo `nome-arquivo-entrada.txt` pelo nome do seu arquivo: 

```bash
make run FILE=nome-arquivo-entrada.txt
```
[cite_start]Este comando irá compilar todos os arquivos-fonte, realizar a ligação e executar o programa, utilizando o arquivo de entrada especificado. 

## 6. Análise e Robustez

* [cite_start]**Análise de Complexidade**: Uma análise detalhada da complexidade de tempo e espaço para cada estrutura de dados e função principal foi realizada.  [cite_start]A análise experimental confirmou que a variável de maior impacto no tempo de execução é a **capacidade de transporte**, pois uma capacidade pequena aumenta drasticamente o número de eventos de inserção e remoção no `Heap`. 
* [cite_start]**Estratégias de Robustez**: O sistema foi desenvolvido com práticas de programação defensiva para garantir a estabilidade. 
    * [cite_start]Verificação da existência e sucesso na abertura de arquivos de entrada. 
    * [cite_start]Validação de acesso a posições válidas em listas, pilhas e no heap para evitar acessos indevidos. 
    * [cite_start]Uso de `default` em `switch-cases` para tratar casos inesperados. 
    * [cite_start]Liberação de toda a memória alocada dinamicamente, verificada com o uso da ferramenta `valgrind`.
