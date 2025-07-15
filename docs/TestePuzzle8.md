@page teste_puzzle8 Teste Puzzle 8

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |


Execução de exemplo com base no problema do Puzzle 8. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#puzzle8-a1)
- [Ação 2 - Resolver manualmente](#puzzle8-a2)
- [Ação 3 - Procura em Largura](#puzzle8-a3)
- [Ação 4 - Procura em Profundidade](#puzzle8-a4)
- [Ação 5 - Heurística](#puzzle8-a5)
- [Ação 6 - Melhor Primeiro](#puzzle8-a6)
- [Ação 7 - AStar](#puzzle8-a7)
- [Ação 8 - IDAStar](#puzzle8-a8)
- [Ação 9 - Branch-and-Bound](#puzzle8-a9)
- [Ação 10 - Configurações](#puzzle8-a10)
- [Ação 11 - Testes Empíricos](#puzzle8-a11)


```entrada
Teste TProcurasConstrutivas
Problema:
  1 - Aspirador
  2 - Puzzle 8
  3 - 8 Damas
  4 - Partição
  5 - Artificial
Opção: 2
```

![Puzzle 8 - movimentar uma das peças para o espaço vazio](docs/images/puzzle8.png)


\anchor puzzle8-a1
## Ação 1 - Ver instâncias

Vamos entrar no problema Puzzle 8, introduza: **2.**

```entrada
Puzzle 8
 P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 3  1  2
 4  7  5
 6  8  .
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
```
Aparece uma instância do Puzzle 8. Poderiamos procurar resolver manualmente. 
No entanto esta instância está distante da solução, pelo que vamos ver outra instância.
Introduza: **1;4.**

```entrada
Opção: 1

ID atual: 40  Intervalo: [1-1000]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto): 4

Puzzle 8
 P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 3  1  2
 6  4  5
 7  8  .
____________________________________________________________________
```

Estavamos na instância 40, e existem instâncias de 1 a 1000. 
Como as instâncias são construídas com base em movimentos aleatórios em quantidade igual ao ID da instância,
ao escolher um ID de 4 garantimos que estamos a uma distância de 4 ou menos da solução.


\anchor puzzle8-a2
## Ação 2 - Resolver manualmente

Vamos então resolver a instância manualmente. Introduza: **2; dir dir baixo baixo; *ENTER*.**

```entrada
Opção: 2
g:0 h:4 1|2|3
 3  1  2
 6  4  5
 7  8  .
Ações: baixo dir
Sucessor [1-2, ação(ões), exe]:dir dir baixo baixo
Executadas 4 ações com sucesso.
g:0 6|14|6
 .  1  2
 3  4  5
 6  7  8
Ações: cima esq
Sucessor [1-2, ação(ões), exe]:

Puzzle 8
...
 .  1  2
 3  4  5
 6  7  8
____________________________________________________________________
```
A instância está resolvida. Vamos agora ver o caminho gravado. Introduza **4.**

```entrada
Opção: 4

Parte 1, ações: dir dir baixo baixo
(3) 1  2
(6) 4  5
(7)(8) .
Puzzle 8
...
 .  1  2
 3  4  5
 6  7  8
____________________________________________________________________
```
Vemos agora a solução num formato compacto. 
Num só tabuleiro, vemos as peças que mudam.
Ou se se quiser, vemos o percurso do espaço. 
Existe uma só parte, com as ações que demos manualmente. 
Caso o caminho intersecte, existiriam mais partes.

Esta forma de ver soluções é específica do Puzzle 8 porque foi redefinido o método MostrarSolucao().
Assim temos uma forma compacta mais cómuda de ver soluções.

\anchor puzzle8-a3
## Ação 3 - Procura em Largura

Começamos pela procura em largura nesta instãncia, colocando debug a 4.
Introduza: **1; 4; 3; 2; 4; *ENTER*; 6**

```entrada
Opção: 6

g:0
 3  1  2
 6  4  5
 7  8  .
Ações: baixo dir
g:1 1|2
 3  1  2
 6  4  .
 7  8  5
Ações: baixo dir
g:1 2|4
 3  1  2
 6  4  5
 7  .  8
Ações: baixo dir
g:2 3|6
 3  1  .
 6  4  2
 7  8  5
Ações: dir
g:2 4|7
 3  1  2
 6  .  4
 7  8  5
Ações: baixo cima dir
g:2 5|10
 3  1  2
 6  .  5
 7  4  8
Ações: baixo dir esq
g:2 6|13
 3  1  2
 6  4  5
 .  7  8
Ações: baixo
g:3 7|14
 3  .  1
 6  4  2
 7  8  5
Ações: cima dir
g:3 8|16
 3  .  2
 6  1  4
 7  8  5
Ações: dir esq
g:3 9|18
 3  1  2
 6  8  4
 7  .  5
Ações: dir esq
g:3 10|20
 3  1  2
 .  6  4
 7  8  5
Ações: baixo cima
g:3 11|22
 3  .  2
 6  1  5
 7  4  8
Ações: dir esq
g:3 12|24
 3  1  2
 .  6  5
 7  4  8
Ações: baixo cima
g:3 13|26
 3  1  2
 6  5  .
 7  4  8
Ações: baixo cima
g:3 14|28
 3  1  2
 .  4  5
 6  7  8  Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:4)
 P1=1 P2=4 P3=1 P4=10 P5=0 P6=4 P7=0 P8=2 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Largura Primeiro | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 4 | I2(Tempo(ms)): 45 | I3(Iterações): 0 | I4(Expansões): 15 | I5(Gerações): 30 |
I6(Lower Bound): 0
____________________________________________________________________
```
Foi encontrada uma solução de distância 4. Podemos ver a ordem das expansões, houve estados expandidos 
que em nada contribuiam para a solução, mas serviram para garantir que não havia outra solução mais curta.

Esta instância era fácil, mas e a instância inicial?
Vamos ver, mas reduzindo o debug para 2, e a semente para 2. Introduza: **1; 40; 3; 2; 2; 3; 2; *ENTER*; 6.**

```entrada
Opção: 6

g:0
g:1 1|4
g:1 2|6
g:1 3|8
g:1 4|10
g:2 5|12
g:2 6|13
g:2 7|14
g:2 8|15
g:2 9|16
g:2 10|17
...
g:11 1281|2123
g:11 1282|2125
g:11 1283|2127
g:11 1284|2129 Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=1 P2=2 P3=2 P4=10 P5=0 P6=4 P7=0 P8=2 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Largura Primeiro | P2(Debug): passos | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 621 | I3(Iterações): 0 | I4(Expansões): 1285 | I5(Gerações): 2131 |
I6(Lower Bound): 0
____________________________________________________________________
```
Foi encontrado um resultado com 12 movimentos, mas foram realizadas 1285 expansões, resultando em 2131 gerações.

Vamos confirmar a solução. Introduza **4.**

```entrada
Opção: 4

Parte 1, ações: baixo esq cima cima
 4 (7)(3)
 1  . (2)
 6  8 (5)
Parte 2, ações: dir baixo baixo dir
(4)(3) 2
 1 (7) 5
 6 (8) .
Parte 3, ações: cima esq
 .  4  2
(1)(3) 5
 6  7  8
Parte 4, ações: baixo dir
(1)(4) 2
 3  .  5
 6  7  8
Puzzle 8
...
 .  1  2
 3  4  5
 6  7  8
...
____________________________________________________________________
```

Nesta instância, foram precisas 4 partes para mostrar a solução com 12 ações. 

Embora o estado inicial tenha sido obtido por 40 movimentos aleatórios desde o estado objetivo,
alguns dos movimentos acabaram por se inverter resultando numa instância à distãncia 12 do objetivo.

Utilizamos P3(Seed)=2, naturalmente que outra semente aleatória poderia gerar um puzzle de 0 a 40 movimentos da solução.


\anchor puzzle8-a4
## Ação 4 - Procura em Profundidade

Vamos ver a procura em profundidade na instância 40, que sabemos ter uma solução de 12. 
Vamos alterar o algoritmo, colocar a profundidade a 4, debug a completo e visualização a 1, 
para ser ver todos os estados. 
Introduza: **1; 40; 3; 1; 3; 7; 4; 2; 4; 6; 1; *ENTER*; 6.**

```entrada
g:0
 4  7  3
 1  .  2
 6  8  5
  +g:1 1|4 baixo
  | 4  .  3
  | 1  7  2
  | 6  8  5
  |  +g:2 2|6 dir
  |  | .  4  3
  |  | 1  7  2
  |  | 6  8  5
  |  |  +g:3 3|7 cima
  |  |    1  4  3
  |  |    .  7  2
  |  |    6  8  5
  |  |
  |  +g:2 3|7 esq
  |    4  3  .
  |    1  7  2
  |    6  8  5
  |     +g:3 4|8 cima
  |       4  3  2
  |       1  7  .
  |       6  8  5
  |
  +g:1 4|8 cima
  | 4  7  3
  | 1  8  2
  | 6  .  5
  |  +g:2 5|10 dir
  |  | 4  7  3
  |  | 1  8  2
  |  | .  6  5
  |  |  +g:3 6|11 baixo
  |  |    4  7  3
  |  |    .  8  2
  |  |    1  6  5
  |  |
  |  +g:2 6|11 esq
  |    4  7  3
  |    1  8  2
  |    6  5  .
  |     +g:3 7|12 baixo
  |       4  7  3
  |       1  8  .
  |       6  5  2
  |
  +g:1 7|12 dir
  | 4  7  3
  | .  1  2
  | 6  8  5
  |  +g:2 8|14 baixo
  |  | .  7  3
  |  | 4  1  2
  |  | 6  8  5
  |  |  +g:3 9|15 esq
  |  |    7  .  3
  |  |    4  1  2
  |  |    6  8  5
  |  |
  |  +g:2 9|15 cima
  |    4  7  3
  |    6  1  2
  |    .  8  5
  |     +g:3 10|16 esq
  |       4  7  3
  |       6  1  2
  |       8  .  5
  |
  +g:1 10|16 esq
    4  7  3
    1  2  .
    6  8  5
     +g:2 11|18 baixo
     | 4  7  .
     | 1  2  3
     | 6  8  5
     |  +g:3 12|19 dir
     |    4  .  7
     |    1  2  3
     |    6  8  5
     |
     +g:2 12|19 cima
       4  7  3
       1  2  5
       6  8  .
        +g:3 13|20 dir
          4  7  3
          1  2  5
          6  .  8

 P1=3 P2=4 P3=2 P4=10 P5=0 P6=1 P7=4 P8=2 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): completo | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 4 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 4  7  3
 1  .  2
 6  8  5
I1(Custo): -1 | I2(Tempo(ms)): 70 | I3(Iterações): 0 | I4(Expansões): 13 | I5(Gerações): 20 |
I6(Lower Bound): 0
____________________________________________________________________
```
Foram vistos todos os estados, e não se encontrou uma solução. Vamos agora colocar 
o limite a 0, de modo a executar a iterativa, e debug no nível 2.
Introduza: **1; 40; 3; 7; 0; 2; 2; *ENTER*; 6.**

```entrada
Iteração 1:
= g:0
Iteração 2:
--+= g:1 1|4
  += g:1 1|4
  += g:1 1|4
  += g:1 1|4
Iteração 3:
--+--+= g:2 3|10
  |  += g:2 3|10
  +--+= g:2 4|12
  |  += g:2 4|12
  +--+= g:2 5|14
  |  += g:2 5|14
  +--+= g:2 6|16
     += g:2 6|16
Iteração 4:
--+--+--+= g:3 9|23
  |  +--+= g:3 10|24
  +--+--+= g:3 12|27
  |  +--+= g:3 13|28
  +--+--+= g:3 15|31
  |  +--+= g:3 16|32
  +--+--+= g:3 18|35
     +--+= g:3 19|36
Iteração 5:
--+--+--+--+= g:4 23|45
  |  |     += g:4 23|45
  |  +--+--+= g:4 25|48
  |        += g:4 25|48
  +--+--+--+= g:4 28|53
  |  |     += g:4 28|53
  |  +--+--+= g:4 30|56
  |        += g:4 30|56
  +--+--+--+= g:4 33|61
  |  |     += g:4 33|61
  |  +--+--+= g:4 35|64
  |        += g:4 35|64
  +--+--+--+= g:4 38|69
     |     += g:4 38|69
     +--+--+= g:4 40|72
           += g:4 40|72
...
Iteração 13:
--+--+--+--+--+--+--+--+--+--+--+--+= g:12 2711|4651
  |  |     |     |  |  |     |     += g:12 2711|4651
  |  |     |     |  |  |     +--+--+= g:12 2713|4656
...
  |  |                          +--+= g:12 2943|5062
  |  |                             += g:12 2943|5062
  |  +--+--+--+--+--+--+--+--+--+--+= g:12 2953|5079
  |        |     |  |  |     |     += g:12 2953|5079
  |        |     |  |  |     +--+--+ Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=3 P2=2 P3=2 P4=10 P5=0 P6=1 P7=0 P8=2 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): passos | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): ascendentes | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 3920 | I3(Iterações): 0 | I4(Expansões): 2955 | I5(Gerações): 5084 |
I6(Lower Bound): 0
____________________________________________________________________
```

A procura em profundidade iterativa encontrou também a solução ótima, com 12 movimentos, na 13ª iteração.
Foram realizadas 2955 expansões e 5084 gerações, um valor superior à procura em largura.

Notar no entanto no parâmetro P8(Repetidos): ascendentes. Significa que não foram gerados estadso, 
que num dado ramo, já tinham ocorrido anteriormente. Esta é a opção de omissão para este problema, 
já que foi redefinido CPuzzle8::ResetParametros().

Vamos repetir esta execução, com debug no nível 1, e ignorando repetidos. 
Introduza: **1; 40; 3; 2; 1; 8; 1; *ENTER*; 6.**

```entrada
Opção: 6
#
#
#





#####
##########
#######################
####################################################################
##########...###########################
##########...########################### Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=3 P2=1 P3=2 P4=10 P5=0 P6=1 P7=0 P8=1 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): atividade | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 114 | I3(Iterações): 0 | I4(Expansões): 156105 | I5(Gerações): 440523 |
I6(Lower Bound): 0
____________________________________________________________________
```
Podemos ver que o número de expansões e gerações é consideravelmente superior.

A verificação dos estados repetidos, é portanto um parametro bastante importante neste problema, em que
o mesmo estado pode surgir várias vezes. Vamos então testar em eliminar todos os estados repetidos.
Introduza: **1; 40; 3; 8; 3; *ENTER*; 6.**

```entrada
#
#
#








#
#
 Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=3 P2=1 P3=2 P4=10 P5=0 P6=1 P7=0 P8=3 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): atividade | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): gerados | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 77 | I3(Iterações): 0 | I4(Expansões): 2647 | I5(Gerações): 4400 |
I6(Lower Bound): 0
____________________________________________________________________
```

Podemos ver que o número de exapansões e gerações é ligeiramente inferior à configuração inicial, de remover repetidos ascendentes.
No entanto, o tempo CPU é consideravelmente inferior. Isto deve-se a que a remoção de estados repetidos gerados,
utiliza uma hashtable, em vez de verificar cada ascendente um a um. Esta verificação de ascendentes é 
normalmente menos eficiente, e remove menos estados que a verificação de estados gerados.

Pergunta: o que acontecia se executar-mos a procura em profundidade ilimitada, ao deixar limite com -1, 
e sem verificar estados repetidos?
<details>
  <summary>Resposta</summary>
A procura não retorna, crasha devido a entrar num ciclo infinito.
</details>

\anchor puzzle8-a5
## Ação 5 - Heurística

Neste problema foi implementada a heurística com a distância na horizontal e vertical, de cada peça até à sua posição final.
Esta heurística relaxa a situação de apenas ser possível mover para o local onde está o espaço, e 
retorna o valor que seria o correto caso cada peça pudesse mover-se por cima das outras.
É implementada no problema ao redefinir CPuzzle8::Heuristica().

Vamos começar por ver (notar que P6(Ver): 1). Introduza: **1; 40; 2; dir baixo; *ENTER*.**

```entrada
g:0 h:12 1|4|5
 4  7  3
 1  .  2
 6  8  5
  +#1 g:1 h:11 1|4|5 baixo
  | 4  .  3
  | 1  7  2
  | 6  8  5
  +#2 g:1 h:13 1|4|5 cima
  | 4  7  3
  | 1  8  2
  | 6  .  5
  +#3 g:1 h:11 1|4|5 dir
  | 4  7  3
  | .  1  2
  | 6  8  5
  +#4 g:1 h:13 1|4|5 esq
    4  7  3
    1  2  .
    6  8  5
Sucessor [1-4, ação(ões), exe]:dir baixo
Executadas 2 ações com sucesso.
g:0 h:10 4|13|8
 .  7  3
 4  1  2
 6  8  5
  +#1 g:1 h:11 4|13|8 cima
  | 4  7  3
  | .  1  2
  | 6  8  5
  +#2 g:1 h:11 4|13|8 esq
    7  .  3
    4  1  2
    6  8  5
Sucessor [1-2, ação(ões), exe]:

Puzzle 8
...
 .  7  3
 4  1  2
 6  8  5
____________________________________________________________________
```

Na informação de um estado, vemos não apenas o valor de g (o custo), mas também o valor de h.
O valor de h é a heuristica, que idealmente é uma estimativa conservadora da distância até ao objetivo.

No estado inicial a heurística é 12, porque:
- os números 2, 5, 8 estão a distância 1
- os números 1, 4, 7 estã à distância 2
- o número 3 está à distância 3

O total será 3 + 6 + 3 = 12.

Vamos ver como esta heurística guia os diferentes algoritmos informados.

\anchor puzzle8-a6
## Ação 6 - Melhor Primeiro

Vamos executar o primeiro algoritmo informado, o melhor primeiro, que segue sempre pelo ramo 
com menor heurística, ou seja, mais perto do objetivo, daí o nome de melhor primeiro.

Este é um algoritmo em profundidade pelo que vamos deixar a configuração de remoção de estados
repetidos gerados, de modo a observar o desempenho deste algoritmo nas melhores condições.

Neste e em outras execuções das procuras informadas, vamos limitar o número de avaliações (iterações) a 1000000, 
de modo a ter um critério de paragem independente do tempo.

Introduza: **1; 40; 3; 1; 4; 2; 3; 5; 1000000; 8; 3; *ENTER*; 6.**

```entrada
Opção: 6
--+--+--+--+--+--...+--+--+--+--+--+--+--+--+--+--+--+--+--+ Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:70)
 P1=4 P2=3 P3=2 P4=10 P5=1000000 P6=1 P7=0 P8=3 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Melhor Primeiro | P2(Debug): detalhe | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 1000000
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): gerados | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 70 | I2(Tempo(ms)): 36 | I3(Iterações): 128 | I4(Expansões): 70 | I5(Gerações): 128 |
I6(Lower Bound): 0
____________________________________________________________________
```
Conseguimos uma solução de 70 ações, utilizando 70 expansões. 
O resultado em termos de esforço computacional é muito reduzido, pelo que a informação 
dada pela heurística foi útil. No entanto, a qualidade da solução baixa, já que fica com
70 de custo, quando sabemos existir uma solução de custo 12. 

\anchor puzzle8-a7
## Ação 7 - AStar

Vamos agora ver o comportamento do AStar, que garante a solução ótima. 

Introduza: **1; 40; 3; 1; 5; 2; 4; 6; 4; *ENTER*; 6.**

```entrada
Opção: 6

g:0 h:10
 4  7  3
 1  .  2
 6  8  5
Ações: baixo cima dir esq
g:1 h:11 1|4|4
 4  .  3
 1  7  2
 6  8  5
Ações: dir esq
g:2 h:10 2|6|6
 4  3  .
 1  7  2
 6  8  5
Ações: cima
g:3 h:9 3|7|7
 4  3  2
 1  7  .
 6  8  5
Ações: cima dir
g:4 h:8 4|9|9
 4  3  2
 1  7  5
 6  8  .
Ações: dir
g:5 h:7 5|10|10
 4  3  2
 1  7  5
 6  .  8
Ações: baixo dir
g:6 h:6 6|12|12
 4  3  2
 1  .  5
 6  7  8
Ações: baixo dir esq
g:7 h:5 7|15|15
 4  3  2
 .  1  5
 6  7  8
Ações: baixo cima
g:8 h:4 8|17|17
 .  3  2
 4  1  5
 6  7  8
Ações: esq
g:9 h:3 9|18|18
 3  .  2
 4  1  5
 6  7  8
Ações: cima esq
g:10 h:2 10|20|20
 3  1  2
 4  .  5
 6  7  8
Ações: cima dir esq
g:11 h:1 11|23|23
 3  1  2
 .  4  5
 6  7  8
Ações: baixo cima
g:12 12|25|25
 .  1  2
 3  4  5
 6  7  8  Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=5 P2=4 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): A* | P2(Debug): completo | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 1000000
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): gerados | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 40 | I3(Iterações): 25 | I4(Expansões): 12 | I5(Gerações): 25 |
I6(Lower Bound): 0
____________________________________________________________________
```
Foram utilizadas 12 expansões para obter a solução ótima de 12 movimentos. 
Esta é portanto uma instância simples para este algoritmo.

\anchor puzzle8-a8
## Ação 8 - IDAStar

O AStar pode ter problemas de memória em instâncias complexas, existindo o IDAStar que permite a mesma ordem
de expansão, mas sem o problema de memória, em troca de algum tempo de CPU extra, gasto ao expandir multiplas
vezes os mesmos estados. Vamas ver como se comporta nesta instância.

Introduza: **1; 40; 3; 1; 6; *ENTER*; 6.**

```entrada
g:0 h:10
 4  7  3
 1  .  2
 6  8  5

Iteração 12: (expansões 0, gerações 0, avaliações 1)
g:0 h:10 |1
 4  7  3
 1  .  2
 6  8  5
  +g:1 h:11 1|4|5 baixo
  |  +g:2 h:10 2|6|7 dir
  |  |  +g:3 h:9 3|7|8 cima
  |  |     +
  |  |     +
  |  +g:2 h:10 4|9|10 esq
  |     +g:3 h:9 5|10|11 cima
  |        +g:4 h:8 6|12|13 cima
  |        |  +g:5 h:7 7|13|14 dir
  |        |     +g:6 h:6 8|15|16 baixo
  |        |     |  +g:7 h:5 9|18|19 baixo
  |        |     |  |  +g:8 h:4 10|20|21 dir
  |        |     |  |  |  +g:9 h:3 11|21|22 cima
  |        |     |  |  |     +g:10 h:2 12|23|24 esq
  |        |     |  |  |     |  +g:11 h:1 13|26|27 baixo
  |        |     |  |  |     |  |  +g:12 14|28|29 dir
  |        |     |  |  |     |  |  | Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=6 P2=4 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): IDA* | P2(Debug): completo | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 1000000
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): gerados | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 35 | I3(Iterações): 29 | I4(Expansões): 14 | I5(Gerações): 28 |
I6(Lower Bound): 14
____________________________________________________________________
```
Podemos ver que em termos de iterações, ao contrário da procura em profundidade iterativa,
tem menos iterações. 

O limite da iteração seguinte é determinado pelo menor valor dos estados
cortados, avançando mais que uma unidade de cada vez.
Acabou por ter apenas 29 expansões, enquanto que o AStar utilizou 12 expansões. 

Pode-se considerar que é mais do dobro, mas é um pequeno preço a pagar por não ter problemas de memória.


\anchor puzzle8-a9
## Ação 9 - Branch-and-Bound

Vamos agora ver como se comporta o Branch-and-Bound, o último algoritmo informado. 
Este algoritmo pode ser visto como o Melhor Primeiro que continua a procura após a primeira solução.
No entanto restringe o espaço de procura apenas aos estados que melhoram a solução atual.

É um algoritmo em profundidade, pelo que não tem problemas de memória originados na procura em largura.
Vamos baixar o nível de debug para 1.

Introduza: **1; 40; 3; 1; 7; 2; 1; *ENTER*; 6.**

```entrada
# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:70) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:68) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:64) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:60) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:52) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:50)# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:48) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:46)# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:42) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:32) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:30) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:28)# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:24)# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:12)
 P1=7 P2=1 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0
 P11=0
Puzzle 8
 P1(Algoritmo): Branch and Bound | P2(Debug): atividade | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 1000000
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): gerados | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 .  1  2
 3  4  5
 6  7  8
I1(Custo): 12 | I2(Tempo(ms)): 36 | I3(Iterações): 6666 | I4(Expansões): 4110 | I5(Gerações): 6666 |
I6(Lower Bound): 14
____________________________________________________________________
```
Vemos que primeiramente encontra a solução de 70 movimentos, e depois vai encontrando sucessivamente 
soluções melhores até que termina com a solução de 12. Gasta nesta instância um número 
consideravelmente superior de expansões e gerações, quando comparado com o AStar.

Podemos agora ver outras instâncias, e estar a executar cada um dos algoritmos para ver qual é o melhor.
No entanto seria um trabalho fastidioso.

Não o fazer, ficariamos com a informação da performance dos algoritmos numa só instância, 
não necessariamente representativa de todas as instâncias.

É para melhor medir o desempenho de algoritmos e configurações, que existem os testes empíricos,
permitindo assim comparar algoritmos e/ou configurações num leque alargado de instâncias.

..................................................................
..................................................................
.... (executar logo o teste empírico em linha de comando?)........
..................................................................
..................................................................


\anchor puzzle8-a10
## Ação 10 - Configurações

Podemos adicionar configurações para o teste. 
Para o fazer basta alterar os parametros, e entrar no menu 6.
Vamos começar por colocar a procura em largura, com todos os parametros nos valores de teste.

Vamos querer para teste que: debug=0, avaliações=1000000, tempo=10s; repetidos=gerados.

Introduza: **4; 1; 1; 2; 0; 5; 10; 8; 1000000; 10; 3; *ENTER*; 6; *ENTER*.**

```entrada
Parametros comuns a 1 configurações:
P1:1 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3
P11:100 P12:0 P13:0
--- Configuração 1 --- atual

Selecionar configuração (negativo apaga):
```
Ao entrar na opção 6 pela primeira vez, introduzimos a primeira parameterização de teste. Temos a configuração 1.
Vamos agora alterar o que pretendemos variar. 
Neste caso vamos variar o algoritmo, tudo o resto mantém-se igual.

Introduza: **4; 1; 3; *ENTER*; 6; *ENTER*.**

```entrada
Parametros comuns a 2 configurações:
P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3 P11:100
P12:0 P13:0
--- Configuração 1
P1:1
--- Configuração 2 --- atual
P1:3
Selecionar configuração (negativo apaga):
```

Podemos ver agora que há 2 configurações. 
Os parâmetros que tomam o mesmo valor estão na primeira secção, seguindo-se os paramêtros que diferem entre configurações.
Poderiamos ao indicar uma configuração, em vez de sair, alterar a parametrização atual para uma das configurações guardadas.
Poderiamos também apagar uma configuração com -ID, sendo ID a identificação da configuração.

Vamos agora introduzir o resto dos algoritmos:
- **4; 1; 4; *ENTER*; 6; *ENTER*
- **4; 1; 5; *ENTER*; 6; *ENTER*
- **4; 1; 6; *ENTER*; 6; *ENTER*
- **4; 1; 7; *ENTER*; 6; *ENTER*

```entrada
Parametros comuns a 6 configurações:
P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3 P11:100
P12:0 P13:0
--- Configuração 1
P1:1
--- Configuração 2
P1:3
--- Configuração 3
P1:4
--- Configuração 4
P1:5
--- Configuração 5
P1:6
--- Configuração 6 --- atual
P1:7
```
Temos 6 configurações preparadas para serem testadas. 
Estamos em condições de fazer um teste empírico, em que todos os algoritmos estão nas mesmas
condições de execução, excepto a troca de algoritmo.

\anchor puzzle8-a11
## Ação 11 - Testes Empíricos

Com as configurações efetuadas na Ação 10, vamos agora fazer um teste empírico. Falta definir as instâncias.
A instância atual e seu estado não têm impacto para este teste.

É preciso apenas saber se se pretende ver as soluções, instância inicial e final. 
Não vamos querer ver as soluções, apenas visualizar os resultados. 
Naturalmente que num problema novo, é de toda a conveniência observar as soluções e verificá-las, para remover eventuais bugs.

Introduza: **7; 0; 49; 40.**

```entrada
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
Instância 40: DONE.
Instância 41: DONE.
Instância 42: DONE.
Instância 43: DONE.
Instância 44: DONE.
Instância 45: DONE.
Instância 46: DONE.
Instância 47: DONE.
Instância 48: DONE.
Instância 49: DONE.
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
Instância 40: DONE.
Instância 41: DONE.
Instância 42: DONE.
Instância 43: DONE.
Instância 44: DONE.
Instância 45: DONE.
Instância 46: DONE.
Instância 47: DONE.
Instância 48: DONE.
Instância 49: DONE.
...
P1(Algoritmo): Branch and Bound | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
Instância 40: DONE.
Instância 41: DONE.
Instância 42: DONE.
Instância 43: DONE.
Instância 44: DONE.
Instância 45: DONE.
Instância 46: DONE.
Instância 47: DONE.
Instância 48: DONE.
Instância 49: DONE.
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
 40 |  1 |       10 |        348 |       570 |          0 |   0,001s |
 41 |  1 |       11 |        495 |       774 |          0 |   0,001s |
 42 |  1 |       12 |       1175 |      1921 |          0 |   0,002s |
 43 |  1 |       13 |       1425 |      2266 |          0 |   0,001s |
 44 |  1 |       14 |       2506 |      4084 |          0 |   0,003s |
 45 |  1 |       15 |       3981 |      6311 |          0 |   0,004s |
 46 |  1 |       16 |       4892 |      7512 |          0 |   0,005s |
 47 |  1 |       15 |       3981 |      6311 |          0 |   0,003s |
 48 |  1 |       14 |       2397 |      3699 |          0 |   0,002s |
 49 |  1 |       15 |       3380 |      5191 |          0 |   0,004s |
 40 |  2 |       10 |        864 |      1469 |          0 |   0,035s |
 41 |  2 |       11 |       1253 |      2088 |          0 |   0,040s |
 42 |  2 |       12 |       3292 |      5507 |          0 |   0,043s |
 43 |  2 |       13 |       3965 |      6563 |          0 |   0,047s |
 44 |  2 |       14 |       7265 |     12070 |          0 |   0,062s |
 45 |  2 |       15 |      11884 |     19494 |          0 |   0,061s |
 46 |  2 |       16 |      14393 |     23397 |          0 |   0,097s |
 47 |  2 |       15 |      11884 |     19494 |          0 |   0,058s |
 48 |  2 |       14 |       6720 |     11007 |          0 |   0,050s |
 49 |  2 |       15 |       9617 |     15683 |          0 |   0,056s |
 40 |  3 |       44 |         45 |        83 |         83 |   0,000s |
 41 |  3 |       11 |         11 |        22 |         22 |   0,000s |
 42 |  3 |       42 |         43 |        80 |         80 |   0,000s |
 43 |  3 |       23 |         23 |        44 |         44 |   0,000s |
 44 |  3 |       22 |         22 |        42 |         42 |   0,000s |
 45 |  3 |       21 |         21 |        41 |         41 |   0,000s |
 46 |  3 |       44 |         44 |        82 |         82 |   0,000s |
 47 |  3 |       21 |         21 |        41 |         41 |   0,000s |
 48 |  3 |       14 |         14 |        28 |         28 |   0,000s |
 49 |  3 |       15 |         15 |        30 |         30 |   0,000s |
 40 |  4 |       10 |         15 |        30 |         30 |   0,000s |
 41 |  4 |       11 |         24 |        42 |         42 |   0,000s |
 42 |  4 |       12 |         33 |        60 |         60 |   0,000s |
 43 |  4 |       13 |         48 |        84 |         84 |   0,000s |
 44 |  4 |       14 |         96 |       161 |        161 |   0,000s |
 45 |  4 |       15 |        107 |       180 |        180 |   0,000s |
 46 |  4 |       16 |        139 |       232 |        232 |   0,001s |
 47 |  4 |       15 |        107 |       180 |        180 |   0,000s |
 48 |  4 |       14 |         84 |       141 |        141 |   0,000s |
 49 |  4 |       15 |        136 |       228 |        228 |   0,001s |
 40 |  5 |       10 |         30 |        55 |         56 |   0,009s |
 41 |  5 |       11 |         31 |        57 |         58 |   0,008s |
 42 |  5 |       12 |         90 |       162 |        163 |   0,012s |
 43 |  5 |       13 |        127 |       223 |        224 |   0,015s |
 44 |  5 |       14 |        197 |       341 |        342 |   0,018s |
 45 |  5 |       15 |        277 |       477 |        478 |   0,025s |
 46 |  5 |       16 |        275 |       469 |        470 |   0,024s |
 47 |  5 |       15 |        277 |       477 |        478 |   0,019s |
 48 |  5 |       14 |        130 |       228 |        229 |   0,016s |
 49 |  5 |       15 |        148 |       258 |        259 |   0,015s |
 40 |  6 |       10 |        846 |      1406 |       1406 |   0,001s |
 41 |  6 |       11 |         22 |        39 |         39 |   0,000s |
 42 |  6 |       12 |        827 |      1373 |       1373 |   0,001s |
 43 |  6 |       13 |        320 |       537 |        537 |   0,000s |
 44 |  6 |       14 |        304 |       511 |        511 |   0,000s |
 45 |  6 |       15 |        317 |       530 |        530 |   0,000s |
 46 |  6 |       16 |        813 |      1354 |       1354 |   0,001s |
 47 |  6 |       15 |        317 |       530 |        530 |   0,001s |
 48 |  6 |       14 |         71 |       121 |        121 |   0,000s |
 49 |  6 |       15 |         82 |       140 |        140 |   0,000s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      135 |      24580 |     38639 |          0 |   0,026s |  10
Total  2 |      135 |      71137 |    116772 |          0 |   0,549s |  10
Total  3 |      257 |        259 |       493 |        493 |   0,000s |  10
Total  4 |      135 |        789 |      1338 |       1338 |   0,002s |  10
Total  5 |      135 |       1582 |      2747 |       2757 |   0,161s |  10
Total  6 |      135 |       3919 |      6541 |       6541 |   0,004s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|
 1    |  0 |  7 |  0 |  0 |  0 |  7
 |----|----|----|----|----|----|
 2  0 |    |  7 |  0 |  0 |  0 |  7
 |----|----|----|----|----|----|
 3 -7 | -7 |    | -7 | -7 | -7 |-35
 |----|----|----|----|----|----|
 4  0 |  0 |  7 |    |  0 |  0 |  7
 |----|----|----|----|----|----|
 5  0 |  0 |  7 |  0 |    |  0 |  7
 |----|----|----|----|----|----|
 6  0 |  0 |  7 |  0 |  0 |    |  7
 |----|----|----|----|----|----|
Parametros comuns a 6 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 10
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000 | P9(Limite): 0
P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
--- Configuração 1
P1(Algoritmo): Largura Primeiro
--- Configuração 2
P1(Algoritmo): Profundidade Primeiro
--- Configuração 3
P1(Algoritmo): Melhor Primeiro
--- Configuração 4
P1(Algoritmo): A*
--- Configuração 5
P1(Algoritmo): IDA*
--- Configuração 6
P1(Algoritmo): Branch and Bound

Puzzle 8
...
_______________________________________________________________________________
```
Primeiramente enquando o algoritmo executa, temos o algoritmo e a instância a ser processada.
Se tivessemos solicitado soluções, em vez de DONE, iriamnos ver a solução.
Como escolhemos critérios de paragem curtos, as instâncias são simples, o teste terminou rápido.

Temos os resultados por cada instância e configuração. 
Temos também os somatórios de cada indicador, ou seja, custo (qualidade), expansões, gerações, avaliações e tempo.
Na última coluna temos também o número de instâncias resolvidas, mas neste caso foram todas as 10 resolvidas por todos os algoritmos.

Como os algoritmos executaram no mesmo computador, o criterio tempo poderia ser utilizado, para os algoritmos
que obtiveram as soluções de melhor qualidade, ou seja, de custo total 135. Segundo este critério, a configuração 4,
o AStar, seria o melhor.

No final temos um torneio entre configurações, em que cada configuração ganha 1 ponto por cada instância que tem 
melhor que as restantes. 

Para uma instância ser considerada melhor, a qualidade tem de ser melhor. Se a qualidade for igual, 
O tempo tem de ser melhor em pelo menos 0.1 segundos. Nestas condições, o torneio é perdido pelo Melhor Primeiro,
que embora o algoritmo mais rápido em termos de tempo, apresenta soluções de pior qualidade. Os restantes lugares
ficam iguais, já que as diferenças temporais não ultrapassam a granularidade definida de 0.1 segundos.

Vamos repetir o teste com as instâncias de 990 a 999. Introduza: **7; 0; 999; 990.**

```entrada
 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
...
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |      249 |    1308470 |   1517905 |          0 |   1,454s |  10
Total  2 |      249 |    8537541 |  11746172 |          0 |   8,651s |  10
Total  3 |     4421 |       4472 |      7864 |       7864 |   0,007s |  10
Total  4 |      249 |      19620 |     30554 |      30554 |   0,030s |  10
Total  5 |      249 |      29563 |     47788 |      47798 |   0,280s |  10
Total  6 |      249 |     821149 |   1301677 |    1301677 |   1,097s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|
 1    | 10 | 10 |-10 | -9 | -5 | -4
 |----|----|----|----|----|----|
 2-10 |    | 10 |-10 |-10 |-10 |-30
 |----|----|----|----|----|----|
 3-10 |-10 |    |-10 |-10 |-10 |-50
 |----|----|----|----|----|----|
 4 10 | 10 | 10 |    |  0 |  5 | 35
 |----|----|----|----|----|----|
 5  9 | 10 | 10 |  0 |    |  5 | 34
 |----|----|----|----|----|----|
 6  5 | 10 | 10 | -5 | -5 |    | 15
 |----|----|----|----|----|----|
Parametros comuns a 6 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 10
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000 | P9(Limite): 0
P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
--- Configuração 1
P1(Algoritmo): Largura Primeiro
--- Configuração 2
P1(Algoritmo): Profundidade Primeiro
--- Configuração 3
P1(Algoritmo): Melhor Primeiro
--- Configuração 4
P1(Algoritmo): A*
--- Configuração 5
P1(Algoritmo): IDA*
--- Configuração 6
P1(Algoritmo): Branch and Bound

Puzzle 8
...
_______________________________________________________________________________
```

Podemos observar aqui uma vantagem para o AStar e IDAStar, comparativamente com o Branch-and-Bound.
O Melhor Primeiro e os algoritmos cegos, estão claramente a trás.
Note-se no entanto que o limite no número de avaliações não afeta os algoritmos cegos, pelo que um limite no 
numero de gerações poderia permitir observar vantagem do Melhor Primeiro sobre os algoritmos cegos.

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
