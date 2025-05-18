@page teste_8damas Teste 8 Damas

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |


Execução de exemplo com base no problema das 8 Damas. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#8damas-a1)
- [Ação 2 - Resolver manualmente](#8damas-a2)
- [Ação 3 - Procura em Largura](#8damas-a3)
- [Ação 4 - Procura em Profundidade](#8damas-a4)
- [Ação 5 - Heurística](#8damas-a5)
- [Ação 6 - Testes Empíricos](#8damas-a6)


```entrada
Teste TProcurasConstrutivas
Problema:
  1 - Aspirador
  2 - Puzzle 8
  3 - 8 Damas
  4 - Partição
  5 - Artificial
Opção: 3
```

![8 Damas - colocar 8 damas no tabuleiro sem que se ataquem mutuamente](docs/images/8damas.png)

Vamos entrar no problema das 8 damas. Introduza: **3.**

```entrada
8 Damas
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Este estado vazio é um tabuleiro de 8x8. 
O objetivo é colocar damas no tabuleiro de xadrez, sem que as damas se ataquem mutuamente.


\anchor 8damas-a1
## Ação 1 - Ver instâncias

Vamos ver que instâncias temos. Introduza: **1; 4.**


```entrada
Nova instância (atual 8) [4-40]: 4

8 Damas
...
::  ::
  ::  ::
::  ::
  ::  ::
_______________________________________________________________________________
```

O tabuleiro foi generalizado a largura N. Podemos escolher entre 4 e 40 colunas.



\anchor 8damas-a2
## Ação 2 - Resolver manualmente

Há várias formas de se colocar damas no tabuleiro. 
Está implementada a colocação de uma dama, na linha superior que não esteja atacada.

Poder-se-ia permitir a colocação de uma dama em qualquer posição. 
No entanto, como em cada linha tem de estar uma dama, optamos por colocar sempre na primeira linha vazia.
Caso tivessem feito diferentes opções, seria adicionado um parametro, e os sucessores seria distinto.

Vamos resolver esta instância manualmente, para explorar o espaço de estados.
Introduza: **2; d1; d4; d3.**


```entrada
g:0 1|4|5
::  ::
  ::  ::
::  ::
  ::  ::
Ações: d1 d2 d3 d4
Sucessor [1-4, ação(ões), exe]:d1
Executadas 1 ações com sucesso.
g:0 3|10|8
##  ::
  ::  ::
::  ::
  ::  ::
Ações: d3 d4
Sucessor [1-2, ação(ões), exe]:d4
Executadas 1 ações com sucesso.
g:0 5|13|10
##  ::
  ::  ##
::  ::
  ::  ::
Ações: d2
Sucessor [1-1, ação(ões), exe]:d2
Executadas 1 ações com sucesso.
g:0 7|14|11
##  ::
  ::  ##
::##::
  ::  ::
Ações:
Sem sucessores.
8 Damas
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 7 | gerações 14 | avaliações 11
##  ::
  ::  ##
::##::
  ::  ::
_______________________________________________________________________________
```
Esta resolução correu mal, e chegamos a um beco sem saida. 
Não há nenhuma coluna onde possa ser colocada a quarta dama, sem que esteja atacada.

A escolha na primeira ação por d2 (ou d3), é crítica para obter a solução.

Neste problema a solução em sempre o mesmo número de ações, igual a N.


\anchor 8damas-a3
## Ação 3 - Procura em Largura

Vamos fazer uma procura em largura, no tabuleiro de 4x4, debug completo. 
Vamos deixar desde já fixado o limite no número de gerações a 1000000. 
Introduza: **1; 4; 2; 4; 6; 1000000; *ENTER*; 5.**

```entrada
g:0
::  ::
  ::  ::
::  ::
  ::  ::
Ações: d1 d2 d3 d4
g:1 1|4
##  ::
  ::  ::
::  ::
  ::  ::
Ações: d3 d4
g:1 2|6
::##::
  ::  ::
::  ::
  ::  ::
Ações: d4
g:1 3|7
::  ##
  ::  ::
::  ::
  ::  ::
Ações: d1
g:1 4|8
::  ::##
  ::  ::
::  ::
  ::  ::
Ações: d1 d2
g:2 5|10
##  ::
  ::##::
::  ::
  ::  ::
Ações:
g:2 6|10
##  ::
  ::  ##
::  ::
  ::  ::
Ações: d2
g:2 7|11
::##::
  ::  ##
::  ::
  ::  ::
Ações: d1
g:2 8|12
::  ##
##::  ::
::  ::
  ::  ::
Ações: d4
g:2 9|13
::  ::##
##::  ::
::  ::
  ::  ::
Ações: d3
g:2 10|14
::  ::##
  ##  ::
::  ::
  ::  ::
Ações:
g:3 11|14
##  ::
  ::  ##
::##::
  ::  ::
Ações:
g:3 12|14
::##::
  ::  ##
##  ::
  ::  :: Solução encontrada!
::##::
  ::  ##
##  ::
  ::##::(g:4)
P1:1 P2:4 P3:4 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
Resultado: 4 (0,038s)
8 Damas
P1(Algoritmo): Largura Primeiro | P2(Debug): completo | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 13 | gerações 15 | avaliações 0
::##::
  ::  ##
##  ::
  ::##::
_______________________________________________________________________________
```
A solução foi encontrada. No entanto, o algoritmo explora todos os estados do nível 3 antes de ver
o primeiro do nível 4. Neste problema, como a solução está no nível 4, acaba por não ser muito
interessante esta procura. Não só este algoritmo gasta muito tempo nos níveis inferiores, a explorar 
completamente, como a procura em profundidade ilimitada não tem problema, já que não existem ciclos infinitos.


\anchor 8damas-a4
## Ação 4 - Procura em Profundidade

Vamos executar a mesma instância com a procura em profundidade ilimitada.
Introduza: **1; 4; 4; 1; 3; 9; -1; *ENTER*; 5.**

```entrada
g:0
::  ::
  ::  ::
::  ::
  ::  ::
  +g:1 1|4 d1
  |  +g:2 2|6 d3
  |  |
  |  +g:2 3|6 d4
  |     +g:3 4|7 d2
  |
  +g:1 5|7 d2
  |  +g:2 6|8 d4
  |     +g:3 7|9 d1
  |        +g:4 8|10 d3
  |          Solução encontrada!
::##::
  ::  ##
##  ::
  ::##::(g:4)
P1:3 P2:4 P3:4 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:-1 P10:1
P11:100 P12:0 P13:0
Resultado: 4 (0,014s)
8 Damas
P1(Algoritmo): Profundidade Primeiro | P2(Debug): completo | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): -1 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 8 | gerações 10 | avaliações 0
::##::
  ::  ##
##  ::
  ::##::
_______________________________________________________________________________
```

Podemos observar que o algoritmo em profundidade fez o mesmo erro que nós fizemos, ao escolher d1.
No entanto, após ver que não é possível, testa a opção de d2 e encontra a solução.

Neste caso fez 8 expansões, contra 13 da procura em largura. 
Mas evidentemente que não será esta pequena instância que irá suportar as nossas conclusões. 
Temos um teste empírico na ação 6, com mais instâncias.

\anchor 8damas-a5
## Ação 5 - Heurística

Na abordagem construtiva, atendendo a que este problema tem o número de ações fixas, se as ações
tivessem custo variável, faria sentido uma heurística para estimar o custo. Sendo o custo fixo, 
apenas sabemos que se existir solução, a distância é conhecida e igual para todos os estados 
num determinado nível. Assim, não faz sentido construir uma heurítsica, nem ter procuras informadas
com a abordagem construtiva.

Poder-se-ia ter no entanto opções que melhorariam a abordagem construiva. 
Uma das possibilidades é considerar ou não os estados repetidos. 
Neste problema temos 3 eixos de simetria. Significa que a mesma posição pode ao ser refletida em cada eixo,
transformar-se numa das outras, num total de 8 posições simétricas. 
Ao anular as simetrias por normalização do estado, e remoção de repetidos, o espaço de estados reduz-se.
As simetrias estão implementadas, pelo que vamos testar na próxima ação.

Outra possibilidade não implementada neste código, é a verificação se há linhas/colunas vazias, que 
estejam totalmente atacadas. Ao colocar duas ou três damas, estas podem cobrir a totalidade das casas
da última linha. Esta implementação causa também mais peso, mas invalida estados antecipadamente. 

\anchor 8damas-a6
## Ação 6 - Testes Empíricos

Vamos começar por comparar a procura em largura, com a procura em profundidade ilimitada, 
e respetivas versões com eliminação de estados repetidos.
Introduza: **4; 1; 1; 2; 0; 6; 1000000; 9; 0; 10; 1; *ENTER*; 6; *ENTER*.**

```entrada
Parametros comuns a 1 configurações:
P1:1 P2:0 P3:4 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
--- Configuração 1 --- atual
```
Colocação das restantes configurações: 
- **4; 10; 3; *ENTER*; 6; *ENTER*.**
- **4; 10; 1; 1; 3; 9; -1; *ENTER*; 6; *ENTER*.**
- **4; 10; 3; *ENTER*; 6; *ENTER*.**

```entrada
Parametros comuns a 4 configurações:
P2:0 P3:4 P4:1 P5:10 P6:1000000 P7:0 P8:0 P11:100 P12:0 P13:0
--- Configuração 1
P1:1 P9:0 P10:1
--- Configuração 2
P1:1 P9:0 P10:3
--- Configuração 3
P1:3 P9:-1 P10:1
--- Configuração 4 --- atual
P1:3 P9:-1 P10:3
```
Vamos agora executar o teste para as primeiras 10 instâncias: **7; 0; 13; 4.**

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
  4 |  1 |        4 |         13 |        15 |          0 |   0,000s |
  5 |  1 |        5 |         33 |        44 |          0 |   0,000s |
  6 |  1 |        6 |        114 |       149 |          0 |   0,000s |
  7 |  1 |        7 |        419 |       512 |          0 |   0,000s |
  8 |  1 |        8 |       1665 |      1965 |          0 |   0,001s |
  9 |  1 |        9 |       6977 |      8042 |          0 |   0,004s |
 10 |  1 |       10 |      30779 |     34815 |          0 |   0,020s |
 11 |  1 |       11 |     149131 |    164246 |          0 |   0,115s |
 12 |  1 |       12 |     773731 |    841989 |          0 |   0,631s |
 13 |  1 | não res. |     393490 |   1000002 |          0 |   0,478s |
  4 |  2 |        4 |          8 |         8 |          0 |   0,000s |
  5 |  2 |        5 |         18 |        23 |          0 |   0,000s |
  6 |  2 |        6 |         60 |        75 |          0 |   0,000s |
  7 |  2 |        7 |        211 |       257 |          0 |   0,000s |
  8 |  2 |        8 |        839 |       983 |          0 |   0,002s |
  9 |  2 |        9 |       3490 |      4022 |          0 |   0,007s |
 10 |  2 |       10 |      15392 |     17408 |          0 |   0,033s |
 11 |  2 |       11 |      74567 |     82124 |          0 |   0,180s |
 12 |  2 |       12 |     386869 |    420995 |          0 |   1,082s |
 13 |  2 | não res. |     517151 |   1000001 |          0 |   2,481s |
  4 |  3 |        4 |          8 |        10 |          0 |   0,000s |
  5 |  3 |        5 |          5 |        11 |          0 |   0,000s |
  6 |  3 |        6 |         31 |        39 |          0 |   0,000s |
  7 |  3 |        7 |          9 |        22 |          0 |   0,000s |
  8 |  3 |        8 |        113 |       124 |          0 |   0,001s |
  9 |  3 |        9 |         41 |        60 |          0 |   0,000s |
 10 |  3 |       10 |        102 |       124 |          0 |   0,001s |
 11 |  3 |       11 |         52 |        83 |          0 |   0,000s |
 12 |  3 |       12 |        261 |       295 |          0 |   0,001s |
 13 |  3 |       13 |        111 |       154 |          0 |   0,000s |
  4 |  4 |        4 |          8 |         8 |          0 |   0,000s |
  5 |  4 |        5 |          5 |         9 |          0 |   0,000s |
  6 |  4 |        6 |         31 |        36 |          0 |   0,000s |
  7 |  4 |        7 |          9 |        19 |          0 |   0,000s |
  8 |  4 |        8 |        113 |       120 |          0 |   0,000s |
  9 |  4 |        9 |         41 |        56 |          0 |   0,000s |
 10 |  4 |       10 |        102 |       119 |          0 |   0,000s |
 11 |  4 |       11 |         52 |        78 |          0 |   0,000s |
 12 |  4 |       12 |        261 |       289 |          0 |   0,000s |
 13 |  4 |       13 |        111 |       148 |          0 |   0,001s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |       72 |    1356352 |   2051779 |          0 |   1,249s |   9
Total  2 |       72 |     998605 |   1525896 |          0 |   3,785s |   9
Total  3 |       85 |        733 |       922 |          0 |   0,003s |  10
Total  4 |       85 |        733 |       882 |          0 |   0,001s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    |  1 | -3 | -3 | -5
 |----|----|----|----|
 2 -1 |    | -3 | -3 | -7
 |----|----|----|----|
 3  3 |  3 |    |  0 |  6
 |----|----|----|----|
 4  3 |  3 |  0 |    |  6
 |----|----|----|----|
Parametros comuns a 4 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 10
P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0 | P11(pesoAStar): 100
P12(ruido): 0 | P13(baralhar): 0
--- Configuração 1
P1(Algoritmo): Largura Primeiro | P9(Limite): 0 | P10(Repetidos): ignorar
--- Configuração 2
P1(Algoritmo): Largura Primeiro | P9(Limite): 0 | P10(Repetidos): gerados
--- Configuração 3
P1(Algoritmo): Profundidade Primeiro | P9(Limite): -1 | P10(Repetidos): ignorar
--- Configuração 4
P1(Algoritmo): Profundidade Primeiro | P9(Limite): -1 | P10(Repetidos): gerados
```

Podemos ver a clara superioridade da procura em profundidade ilimitada.
A procura em largura nem resolve a instância 13 dentro dos critérios de paragem.

Não é possível com estas instâncias, observar diferença entre repetidos ignorando ou 
gerados, mas gastando tempo com a normalização. Há apenas uma ligeira diferença
nos estados gerados.

Para observar diferença, vamos retirar as duas primeiras configurações do teste, para
poder executar instâncias maiores.

Introduza: **6; -1; 6; -1; 7; 0; 23; 14.

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
 14 |  1 |       14 |       1899 |      1944 |          0 |   0,002s |
 15 |  1 |       15 |       1359 |      1414 |          0 |   0,001s |
 16 |  1 |       16 |      10052 |     10112 |          0 |   0,009s |
 17 |  1 |       17 |       5374 |      5449 |          0 |   0,005s |
 18 |  1 |       18 |      41299 |     41377 |          0 |   0,051s |
 19 |  1 |       19 |       2545 |      2642 |          0 |   0,008s |
 20 |  1 |       20 |     199635 |    199733 |          0 |   0,264s |
 21 |  1 |       21 |       8562 |      8676 |          0 |   0,011s |
 22 |  1 | não res. |     999877 |   1000001 |          0 |   1,426s |
 23 |  1 |       23 |      25428 |     25566 |          0 |   0,038s |
 14 |  2 |       14 |       1899 |      1937 |          0 |   0,005s |
 15 |  2 |       15 |       1359 |      1407 |          0 |   0,003s |
 16 |  2 |       16 |       2850 |      2896 |          0 |   0,010s |
 17 |  2 |       17 |       5206 |      5258 |          0 |   0,019s |
 18 |  2 |       18 |      28605 |     28659 |          0 |   0,127s |
 19 |  2 |       19 |       4656 |      4733 |          0 |   0,021s |
 20 |  2 |       20 |     112596 |    112672 |          0 |   0,539s |
 21 |  2 |       21 |      20208 |     20295 |          0 |   0,091s |
 22 |  2 |       22 |     425154 |    425243 |          0 |   2,397s |
 23 |  2 |       23 |     250250 |    250347 |          0 |   1,455s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      163 |    1296030 |   1296914 |          0 |   1,815s |   9
Total  2 |      185 |     852783 |    853447 |          0 |   4,667s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|
 1    |  1 |  1
 |----|----|
 2 -1 |    | -1
 |----|----|
Parametros comuns a 2 configurações:
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): -1 | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
--- Configuração 1
P10(Repetidos): ignorar
--- Configuração 2
P10(Repetidos): gerados
```
Embora uma das instâncias não tenha sido resolvida devido ao limite das gerações,
a configuração em que ignora os repetidos, revela-se mais rápida em termos de tempo,
embora com cerca de mais 50% de estados gerados e expandidos.

Dos resultados pode-se também conjeturar que as instâncias pares são mais complexas que as ímpares.


| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
