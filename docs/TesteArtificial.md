@page teste_artificial Teste Artificial

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |


Execução de exemplo com base no problema artificial. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#artificia-a1)
- [Ação 2 - Resolver manualmente](#artificia-a2)
- [Ação 3 - Testes Empíricos](#artificia-a3)


```entrada
Teste TProcurasConstrutivas
Problema:
  1 - Aspirador
  2 - Puzzle 8
  3 - 8 Damas
  4 - Partição
  5 - Artificial
Opção: 5
```

Temos ainda a opção do problema artificial. Introduza: **5.**

```entrada
Artificial
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
--<([1])>--
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Estas instâncias artificiais não têm um problema concreto. 
Cada estado é abstrato e é representado por um inteiro. 
O primeiro estado é o estado 1. 
No entanto, cada instância tem diferentes características:
- Ramificação - existe valor mínimo e máximo, pelo que pode-se controlar se é elevada ou baixa, fixa ou variável.
- Nível do objetivo - pode-se definir o nível mínimo em que o objetivo pode estar, e assim indicar que é 8. Nesse caso apenas estados no nível 8 ou superior, é que podem ser objetivo.
- Nível máximo - a profundidade máxima em que há estados. Após este nível os sucessores ficam vazios.
- Objetivo - permite controlar a raridade do objetivo. Define-se um número K, se ID é objetivo então tem de ser multiplo de K. No caso de K=10, significa que todos os estados que tiverem ID a terminar com 0, são objetivo.
- Custo máximo - permite controlar entre custos das ações fixos, ou variáveis
- Repetição de estados - define-se um número K, ficando todos os IDs resto da divisão por K. Assim, controla-se a probabilidade de um estado ser repetido, K menor há mais repetidos.
- Repetição de estados mas por nível - idêntico ao anterior, mas os estados apenas são repetidos de entre os que estão no mesmo nível.

Estas caracteristicas definem o espaço de estados, e permite avaliar os algoritmos de forma independente
dos problemas, ou testar em situações extermas, mesmo antes de ter um problema concreto que tenha essas características.

\anchor artificia-a1
## Ação 1 - Ver instâncias

Introduza: **1; 1.**

```entrada
Nova instância (atual 1) [1-10]:1
```

As instâncias têm características definidas na função CProblemaArtificial::CarregaInstancia().
Procurou-se ter instâncias de diferentes tipos.

No entanto, infelizmente a heurística não é simulada, pelo que não dá para analisar algoritmos informados.

\anchor artificia-a2
## Ação 2 - Resolver manualmente

Introduza: **2; 1; *ENTER*.**

```entrada
g:0 h:4 1|2|3
--<([1])>--
  +#1 g:1 h:3 1|2|3 a2715811231
  |--<([2715811231])>--
  +#2 g:1 h:3 1|2|3 a3810139872
   --<([3810139872])>--
Sucessor [1-2, ação(ões), exe]:1
g:0 h:3 2|4|6
--<([2715811231])>--
  +#1 g:1 h:2 2|4|6 a83408230
  |--<([83408230])>--
  +#2 g:1 h:2 2|4|6 a3304292189
   --<([3304292189])>--
Sucessor [1-2, ação(ões), exe]:

Artificial
...
--<([2715811231])>--
_______________________________________________________________________________
```
As ações são os próprios estados. Sem informação é complicado explorar o espaço de estados.
Nesta instância o objetivo termina com 0, pelo que explorando um bocado já daria para encontrar 
uma solução, mas seria sempre uma procura à sorte.


\anchor artificia-a3
## Ação 3 - Testes Empíricos

Temos aqui o custo uniforme, atendendo que há instâncias com custos distintos por ação.
Vamos portanto comparar resultados da procura em largura, custo uniforme e procura em profundidade iterativa,
atendendo a que desconhecemos a profundidade máxima das instâncias. 
Vamos colocar dos algoritmos informados o Branch-and-Bound e o A*, dado que embora não exista heurística, 
existe a distância até ao nível do objetivo, e poderá dar alguma vantagem.

Introduza: **4; 1; 1; 2; 0; 6; 1000000; 10; 1; *ENTER*; 6; *ENTER*.**


```entrada
Parametros comuns a 1 configurações:
P1:1 P2:0 P3:1 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
--- Configuração 1 --- atual
```

Vamos colocar o custo uniforme, e procura em profundiadade iterativa:
- **4; 1; 2; *ENTER*; 6; *ENTER*.* 
- **4; 1; 3; *ENTER*; 6; *ENTER*.* 
- **4; 1; 7; *ENTER*; 6; *ENTER*.* 
- **4; 1; 5; *ENTER*; 6; *ENTER*.* 

```entrada
Parametros comuns a 5 configurações:
P2:0 P3:1 P4:1 P5:10 P6:1000000 P7:0 P8:0 P9:0 P10:1 P11:100
P12:0 P13:0
--- Configuração 1
P1:1
--- Configuração 2
P1:2
--- Configuração 3
P1:3
--- Configuração 4
P1:7
--- Configuração 5 --- atual
P1:5
```

Vamos agora resolver todas as 10 instâncias: **7; 0; 10; 1.**

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
  1 |  1 |        5 |         16 |        32 |          0 |   0,000s |
  2 |  1 |        2 |          2 |         8 |          0 |   0,000s |
  3 |  1 |        5 |        260 |      1560 |          0 |   0,000s |
  4 |  1 |       16 |          7 |        11 |          0 |   0,000s |
  5 |  1 |       25 |     331561 |    663719 |          0 |   0,117s |
  6 |  1 |       11 |         14 |        27 |          0 |   0,000s |
  7 |  1 | não res. |     496637 |   1000003 |          0 |   0,200s |
  8 |  1 | não res. |      69015 |   1000006 |          0 |   0,114s |
  9 |  1 |        2 |          6 |        91 |          0 |   0,000s |
 10 |  1 | não res. |      16854 |   1000033 |          0 |   0,108s |
  1 |  2 |        5 |         31 |        62 |          0 |   0,000s |
  2 |  2 |        2 |          6 |        24 |          0 |   0,000s |
  3 |  2 |        5 |       1581 |      9486 |          0 |   0,002s |
  4 |  2 |       16 |          6 |        12 |          0 |   0,000s |
  5 |  2 |       22 |      59854 |    119675 |          0 |   0,039s |
  6 |  2 |       11 |         20 |        39 |          0 |   0,000s |
  7 |  2 |       22 |      84480 |    169257 |          0 |   0,051s |
  8 |  2 | não res. |      69022 |   1000012 |          0 |   0,187s |
  9 |  2 |        2 |        106 |      1537 |          0 |   0,001s |
 10 |  2 | não res. |      16784 |   1000056 |          0 |   0,251s |
  1 |  3 |        5 |         31 |        62 |          0 |   0,000s |
  2 |  3 |        2 |          3 |        12 |          0 |   0,000s |
  3 |  3 |        5 |        315 |      1890 |          0 |   0,000s |
  4 |  3 |       16 |         13 |        21 |          0 |   0,000s |
  5 |  3 | não res. |     499391 |   1000002 |          0 |   0,144s |
  6 |  3 |       11 |         41 |        62 |          0 |   0,000s |
  7 |  3 | não res. |     497963 |   1000001 |          0 |   0,146s |
  8 |  3 | não res. |      69047 |   1000012 |          0 |   0,086s |
  9 |  3 |        2 |          7 |       104 |          0 |   0,000s |
 10 |  3 | não res. |      16863 |   1000033 |          0 |   0,085s |
  1 |  4 |        5 |         31 |        62 |         62 |   0,000s |
  2 |  4 |        2 |         32 |       120 |        120 |   0,000s |
  3 |  4 |        5 |         10 |        60 |         60 |   0,000s |
  4 |  4 |       16 |          6 |        12 |         12 |   0,000s |
  5 |  4 |       22 |       1284 |      2249 |       2249 |   0,001s |
  6 |  4 |       11 |        985 |      1929 |       1929 |   0,001s |
  7 |  4 |       22 |       2831 |      4221 |       4221 |   0,001s |
  8 |  4 |       10 |        292 |      4281 |       4281 |   0,001s |
  9 |  4 |        2 |       2417 |     33084 |      33084 |   0,005s |
 10 |  4 |       40 |       1201 |     72680 |      72680 |   0,009s |
  1 |  5 |        5 |         32 |        62 |         62 |   0,000s |
  2 |  5 |        2 |          6 |        24 |         24 |   0,000s |
  3 |  5 |        5 |         26 |       156 |        156 |   0,000s |
  4 |  5 |       16 |          5 |         9 |          9 |   0,000s |
  5 |  5 |       22 |       2902 |      5036 |       5036 |   0,002s |
  6 |  5 |       11 |         20 |        39 |         39 |   0,000s |
  7 |  5 |       22 |       1075 |      1860 |       1860 |   0,000s |
  8 |  5 |       10 |         92 |      1294 |       1294 |   0,000s |
  9 |  5 |        2 |        106 |      1537 |       1537 |   0,001s |
 10 |  5 |       40 |        149 |      8302 |       8302 |   0,002s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |       66 |     914372 |   3665490 |          0 |   0,539s |   7
Total  2 |       85 |     231890 |   2300160 |          0 |   0,531s |   8
Total  3 |       41 |    1083674 |   4002199 |          0 |   0,461s |   6
Total  4 |      135 |       9089 |    118698 |     118698 |   0,018s |  10
Total  5 |      135 |       4413 |     18319 |      18319 |   0,005s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|
 1    | -2 |  1 | -4 | -4 | -9
 |----|----|----|----|----|
 2  2 |    |  2 | -2 | -2 |  0
 |----|----|----|----|----|
 3 -1 | -2 |    | -4 | -4 |-11
 |----|----|----|----|----|
 4  4 |  2 |  4 |    |  0 | 10
 |----|----|----|----|----|
 5  4 |  2 |  4 |  0 |    | 10
 |----|----|----|----|----|
Parametros comuns a 5 configurações:
P2(Debug): nada | P3(Ver): 1 | P4(Seed): 1 | P5(Tempo): 10
P6(Gerações): 1000000 | P7(Expansões): 0 | P8(Avaliações): 0 | P9(Limite): 0
P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
--- Configuração 1
P1(Algoritmo): Largura Primeiro
--- Configuração 2
P1(Algoritmo): Custo Uniforme
--- Configuração 3
P1(Algoritmo): Profundidade Primeiro
--- Configuração 4
P1(Algoritmo): Branch and Bound
--- Configuração 5
P1(Algoritmo): A*
```
Podemos observar aqui que as procuras informadas são bastante robustas, mesmo com a heurística mínima
indicando a informação até ao nível em que pode estar o estado objetivo. 

Estas 10 instâncias não são portanto complexas para estes algoritmos, 
que podem lidar com objetivos mais raros, profundos, e com ramificação mais elevada, que as utilizadas aqui.

A remoção de duplicados não foi ativada, mas algumas instâncias tinham repetidos, e essa situação melhora
naturalmente o desempanho dos algoritmos.

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
