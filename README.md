# Armazéns de Hanói: Um Sistema de Escalonamento de Transporte de Pacotes

[cite_start]Este projeto foi desenvolvido por **João Henrique Alves Martins** ([jalvesmartins16@ufmg.br](mailto:jalvesmartins16@ufmg.br)) como parte do Trabalho Prático 2 para a disciplina de Estruturas de Dados na Universidade Federal de Minas Gerais (UFMG). 

## 1. Visão Geral do Projeto

[cite_start]O "Armazéns de Hanói" é uma simulação de eventos discretos que implementa um sistema de escalonamento para o transporte de pacotes.  [cite_start]O objetivo principal é otimizar a ordem de transporte, priorizando pacotes que estão armazenados por mais tempo, de forma a evitar atrasos excessivos. 

[cite_start]A lógica do sistema é inspirada no clássico problema das **Torres de Hanói**, onde os armazéns utilizam uma estrutura de pilhas (stacks) para guardar os pacotes.  [cite_start]Isso impõe uma restrição de que, para mover um pacote armazenado há mais tempo (no fundo da pilha), todos os pacotes que chegaram depois dele precisam ser removidos primeiro. 

[cite_start]A topologia dos armazéns é representada por um grafo, e as rotas mais curtas para cada pacote são calculadas utilizando o algoritmo de Busca em Largura (BFS). 

## 2. Estruturas de Dados Implementadas

[cite_start]O projeto foi modularizado em diversas classes e Tipos Abstratos de Dados (TADs) para garantir organização e encapsulamento.  As principais estruturas são:

* [cite_start]**`Package`**: Representa os pacotes, armazenando suas informações básicas e a rota a ser seguida. 
* [cite_start]**`Stack`**: Simula as pilhas de armazenamento dentro dos armazéns, seguindo a lógica LIFO (Last-In, First-Out), fundamental para a mecânica inspirada em Hanói. 
* [cite_start]**`List`**: Uma lista encadeada genérica (usando templates) para armazenar diferentes tipos de dados de forma eficiente. 
* [cite_start]**`Queue`**: Fila convencional utilizada para a implementação do algoritmo BFS para o cálculo de rotas. 
* [cite_start]**`Warehouse`**: Representa um armazém, que contém um ID e uma lista de seções, onde cada seção é uma pilha (`Stack`) de pacotes destinada a um armazém adjacente. 
* [cite_start]**`Graph`**: Modela a topologia da rede de armazéns usando uma lista de adjacências, onde cada nó representa um armazém. 
* [cite_start]**`Event`**: Define os eventos da simulação (armazenamento ou transporte), que são a base para o funcionamento do escalonador. 
* [cite_start]**`Heap`**: Um *min-heap* que funciona como a estrutura central do escalonador, ordenando os eventos por uma chave que considera o tempo e o tipo do evento. 
* [cite_start]**`Scheduler`**: Uma camada de abstração que encapsula o `Heap` para gerenciar a fila de eventos. 
* **`Transport`**: A classe orquestradora do sistema. [cite_start]É responsável por gerenciar o tempo, calcular rotas, executar e escalonar novos eventos, e coletar estatísticas. 

## 3. Fluxo de Execução do Programa

1.  [cite_start]**Inicialização**: O programa lê os parâmetros iniciais, como a capacidade de transporte, intervalos, e a topologia da rede de armazéns (fornecida como uma matriz de adjacência).  [cite_start]Em seguida, instancia o Grafo, o Escalonador e o Transportador. 
2.  [cite_start]**Leitura dos Pacotes**: O sistema lê os dados de cada pacote (ID, origem, destino, tempo de chegada). 
3.  [cite_start]**Cálculo de Rota**: Para cada pacote, a rota mais curta é calculada usando o algoritmo **BFS** sobre o grafo de armazéns. 
4.  [cite_start]**Escalonamento Inicial**: A chegada de cada pacote em seu armazém de origem é escalonada como um evento inicial.  [cite_start]Além disso, o primeiro evento de transporte para cada rota (aresta do grafo) é criado e agendado. 
5.  [cite_start]**Loop de Simulação**: O programa entra em um loop que continua enquanto houver pacotes não entregues. 
    * [cite_start]A cada iteração, o evento com a menor chave (o mais próximo no tempo) é removido do escalonador (`Heap`). 
    * [cite_start]**Se o evento for de Armazenamento**: O sistema verifica se o pacote chegou ao seu destino final.  [cite_start]Se sim, o pacote é registrado como entregue.  [cite_start]Caso contrário, ele é armazenado na pilha (seção) correspondente ao próximo passo de sua rota. 
    * **Se o evento for de Transporte**: Os pacotes elegíveis são movidos de um armazém para outro. [cite_start]Os pacotes armazenados há mais tempo são priorizados.  [cite_start]A chegada desses pacotes ao armazém de destino é então escalonada como um novo evento.  [cite_start]Um novo evento de transporte para a mesma rota é agendado para o futuro, com base no intervalo de transporte definido. 
6.  [cite_start]**Fim da Simulação**: O loop termina quando todos os pacotes forem entregues.  [cite_start]As estatísticas finais são impressas no terminal. 

## 4. Tecnologias Utilizadas

* [cite_start]**Linguagem**: C++ (compilado com G++) 
* [cite_start]**Sistema Operacional para Desenvolvimento**: Linux (Ubuntu) 
* [cite_start]**Versionamento**: Git e GitHub 

## 5. Como Compilar e Executar

Para compilar e executar o projeto, siga os passos abaixo:

1.  [cite_start]Extraia o conteúdo do arquivo `.zip`. 
2.  [cite_start]Adicione o arquivo de entrada (`.txt`) ao diretório extraído. 
3.  Abra um terminal nesse diretório e execute o seguinte comando, substituindo `nome-arquivo-entrada.txt` pelo nome do seu arquivo de entrada:

```bash
make run FILE=nome-arquivo-entrada.txt
```
[cite_start]Este comando irá compilar todos os arquivos-fonte, realizar a ligação e executar o programa, passando o arquivo de entrada especificado como parâmetro. 

## 6. Análise e Robustez

* [cite_start]**Análise de Complexidade**: Uma análise detalhada da complexidade de tempo e espaço para cada estrutura de dados e função principal foi realizada.  [cite_start]A análise experimental mostrou que o desempenho do sistema é mais sensível à **capacidade de transporte** (que impacta o número de eventos gerados) do que ao número de pacotes ou armazéns. 
* [cite_start]**Estratégias de Robustez**: O programa implementa práticas de programação defensiva, como a verificação da existência de arquivos, validação de acesso a estruturas de dados e liberação adequada da memória alocada dinamicamente (verificada com `valgrind`).
