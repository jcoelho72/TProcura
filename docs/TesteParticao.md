@page teste_particao Teste Particao

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |

Execução de exemplo com base no problema da Partição. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#particao-a1)
- [Ação 2 - Resolver manualmente](#particao-a2)
- [Ação 6 - Testes Empíricos](#particao-a3)


```entrada
Teste TProcurasConstrutivas
Problema:
  1 - Aspirador
  2 - Puzzle 8
  3 - 8 Damas
  4 - Partição
  5 - Artificial
Opção: 4
```

![Partição - separe os números em duas partes iguais](docs/images/particao.png)

Vamos escolher o problema da partição. Introduza: **4.**

```entrada
Partição
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
Colocar #8: 0 = 0
---   8  10  14  17  ---
---  18  25  28  28  ---
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Este problem aconsiste em dividir os números em duas partes que somem exatamente o mesmo valor.

\anchor particao-a1
## Ação 1 - Ver instâncias

Vamos ver as instâncias que temos. Introduza: **1; 10.**

```entrada
Nova instância (atual 10) [2-1000]:
```
Existem instâncias de 2 a 1000, correspondendo o ID à quantidade de números. 
As instâncias são geradas aleatoriamente, podendo existir instâncias impossíveis.

Deixemos a instância 10 para resolução manual.

\anchor particao-a2
## Ação 2 - Resolver manualmente

Vamos procurar resolver manualmente a intância. Introduza: **2; esq dir esq dir; dir esq; dir; esq.**

```entrada
Colocar #8: 0 = 0
---   8  10  14  17  ---
---  18  25  28  28  ---
Ações: esq dir
Sucessor [1-2, ação(ões), exe]:esq dir esq dir
Executadas 4 ações com sucesso.
g:0 6|12|6
Colocar #4: 53 = 46
---   8  10  14  17  ---
     28  25          <<<
>>>  28  18
Ações: esq dir
Sucessor [1-2, ação(ões), exe]:dir esq
Executadas 2 ações com sucesso.
g:0 9|18|9
Colocar #2: 67 = 63
---   8  10          ---
     28  25  14      <<<
>>>  28  18  17
Ações: esq dir
Sucessor [1-2, ação(ões), exe]:dir
Executadas 1 ações com sucesso.
g:0 11|22|12
Colocar #1: 67 = 73
---   8              ---
     28  25  14      <<<
>>>  28  18  17  10
Ações: esq dir
Sucessor [1-2, ação(ões), exe]:esq
Executadas 1 ações com sucesso.
g:0 13|24|13
Colocar #0: 75 = 73
     28  25  14   8  <<<
>>>  28  18  17  10
Ações:
Sem sucessores.
Partição
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 13 | gerações 24 | avaliações 13
Colocar #0: 75 = 73
     28  25  14   8  <<<
>>>  28  18  17  10
_______________________________________________________________________________
```
Foi uma boa tentativa, mas no final um lado soma 75 o outro 73. 

Tal como as 8 damas, o número de ações de uma solução completa é fixo. É igual à quantidade de número a colocar.
Sabemos que não faz sentido a procura em largura nestes problemas.
Também pelos mesmos motivos que nas 8 damas, não se consegue uma heurística pelo que não faz sentido 
as procuras informadas.


Naturalmente que se poderia efetuar mais cortes dos que estão a ser feitos nesta implementação.
Vamos apenas comparar a remoção de repetidos gerados, relativamente a ignorar repetidos.

No caso da partição, após um número estar num lado, apenas a soma interessa. 
Como se coloca os números por ordem, um estado fica igual a todos os que têm o montante igual das peças colocadas.
Esquerda e direita é naturalmente irrelevante. 

Como o estado codificado fica pequeno, a expectativa para ganho por repetidos aumenta.

\anchor particao-a3
## Ação 3 - Testes Empíricos

Temos para teste a procura em profundidade ilimitada, e pretendemos comparar ignorar estados repetidos, ou remover todos os repetidos gerados.
Introduza: **4; 1; 3; 6; 1000000; 10; 1; 9; -1; *ENTER*; 6; *ENTER*; 4; 10; 3; *ENTER*; 6; *ENTER*. **

```entrada
Parametros comuns a 2 configurações:
P1:3 P2:0 P3:4 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:-1 P11:100
P12:0 P13:0
--- Configuração 1
P10:1
--- Configuração 2 --- atual
P10:3
```
Estamos prontos para ver primeiramente algumas instâncias mais pequenas. 
Introduza: **7; 0; 19; 10.**

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
 10 |  1 |        8 |         13 |        16 |          0 |   0,000s |
 11 |  1 |       11 |         55 |        60 |          0 |   0,000s |
 12 |  1 | sem sol. |        603 |       602 |          0 |   0,001s |
 13 |  1 | sem sol. |       1539 |      1538 |          0 |   0,001s |
 14 |  1 |       13 |         37 |        42 |          0 |   0,000s |
 15 |  1 | sem sol. |       8131 |      8130 |          0 |   0,003s |
 16 |  1 |       16 |         35 |        42 |          0 |   0,000s |
 17 |  1 |       17 |         76 |        84 |          0 |   0,000s |
 18 |  1 |       16 |         42 |        48 |          0 |   0,000s |
 19 |  1 |       19 |         31 |        38 |          0 |   0,000s |
 10 |  2 |        8 |         13 |        15 |          0 |   0,000s |
 11 |  2 |       11 |         44 |        48 |          0 |   0,001s |
 12 |  2 | sem sol. |        124 |       123 |          0 |   0,000s |
 13 |  2 | sem sol. |        158 |       157 |          0 |   0,000s |
 14 |  2 |       13 |         37 |        41 |          0 |   0,000s |
 15 |  2 | sem sol. |        290 |       289 |          0 |   0,000s |
 16 |  2 |       16 |         32 |        38 |          0 |   0,000s |
 17 |  2 |       17 |         64 |        71 |          0 |   0,000s |
 18 |  2 |       16 |         42 |        47 |          0 |   0,000s |
 19 |  2 |       19 |         31 |        37 |          0 |   0,000s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      100 |      10562 |     10600 |          0 |   0,005s |  10
Total  2 |      100 |        835 |       866 |          0 |   0,001s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|
 1    |  0 |  0
 |----|----|
 2  0 |    |  0
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

Muito rápido, não é possível observar diferenças a nível de tempo. 
Pode-se no entanto ver que os estados gerados e expandidos, 
são uma ordem de grandeza superior, se se ignorar estados gerados duplicadso.

Introduza: **7; 0; 29; 20.**

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
 20 |  1 |       20 |        184 |       192 |          0 |   0,000s |
 21 |  1 |       20 |         33 |        40 |          0 |   0,000s |
 22 |  1 |       21 |         34 |        42 |          0 |   0,000s |
 23 |  1 | sem sol. |     384627 |    384626 |          0 |   0,232s |
 24 |  1 | não res. |     999992 |   1000002 |          0 |   0,564s |
 25 |  1 | não res. |     999991 |   1000002 |          0 |   0,538s |
 26 |  1 | não res. |     999991 |   1000002 |          0 |   0,595s |
 27 |  1 |       27 |         45 |        54 |          0 |   0,000s |
 28 |  1 |       27 |         86 |        96 |          0 |   0,000s |
 29 |  1 |       29 |         50 |        58 |          0 |   0,000s |
 20 |  2 |       20 |        148 |       155 |          0 |   0,000s |
 21 |  2 |       20 |         33 |        39 |          0 |   0,000s |
 22 |  2 |       21 |         34 |        41 |          0 |   0,000s |
 23 |  2 | sem sol. |       1008 |      1007 |          0 |   0,001s |
 24 |  2 | sem sol. |       1389 |      1388 |          0 |   0,002s |
 25 |  2 | sem sol. |       1874 |      1873 |          0 |   0,002s |
 26 |  2 | sem sol. |       1473 |      1472 |          0 |   0,001s |
 27 |  2 |       27 |         45 |        53 |          0 |   0,000s |
 28 |  2 |       27 |         81 |        90 |          0 |   0,000s |
 29 |  2 |       29 |         50 |        57 |          0 |   0,000s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      144 |    3385033 |   3385114 |          0 |   1,929s |   7
Total  2 |      144 |       6135 |      6175 |          0 |   0,006s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|
 1    | -4 | -4
 |----|----|
 2  4 |    |  4
 |----|----|
 ```

Conseguimos observar clara vantagem já nestas instâncias de 20 elementos. 
Nas instâncias impossíveis o espaço de estados aumenta de forma considerável, caso se ignore repetidos.
Na instância 23 (as restantes atingiram o critério de paragem), foram necessários 384 mil estados,
enquanto que removendo duplicados apenas 1007, o que dá duas ordens de grandeza.

Claramente a remoção de repetidos é crítica, dado que muitos estados ficam iguais após ações distintas.
 
Vamos fazer agora um teste para saber até que instância podem os métodos construtivos resolver instâncias
partição. Introduza: **6; -1; 7; 0; 159; 150**
 
 ```entrada
  ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
150 |  1 |      150 |        404 |       448 |          0 |   0,001s |
151 |  1 |      151 |        257 |       301 |          0 |   0,000s |
152 |  1 | sem sol. |     460826 |    460825 |          0 |   1,068s |
153 |  1 | sem sol. |     489670 |    489669 |          0 |   1,155s |
154 |  1 | sem sol. |     470043 |    470042 |          0 |   1,225s |
155 |  1 |      155 |        423 |       467 |          0 |   0,001s |
156 |  1 | sem sol. |     469527 |    469526 |          0 |   1,114s |
157 |  1 |      157 |        454 |       501 |          0 |   0,001s |
158 |  1 | sem sol. |     553655 |    553654 |          0 |   1,355s |
159 |  1 |      159 |        457 |       506 |          0 |   0,001s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      772 |    2445716 |   2445939 |          0 |   5,921s |  10
 ```
 Com 150 números o algoritmo já leva à volta de 1 segundo, e as gerações estão a metade do limite, que é um milhão.

 As instâncias que têm resolução, continuam a ser resolvidas muito rapidamente.


| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
