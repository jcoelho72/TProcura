@page teste_puzzle8 Teste Puzzle 8

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |


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
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
 .  4  2
 6  3  5
 7  1  8
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Aparece uma instância do Puzzle 8. Poderiamos procurar resolver manualmente. 
No entanto esta instância está distante da solução, pelo que vamos ver outra instância.
Introduza: **1;4.**

```entrada
Opção: 1

Nova instância (atual 40) [1-1000]: 4

Puzzle 8
...
 3  1  2
 4  5  8
 6  7  .
_______________________________________________________________________________```

Estavamos na instância 40, e existem instâncias de 1 a 1000. 
Como as instâncias são construídas com base em movimentos aleatórios em quantidade igual ao ID da instância,
ao escolher um ID de 4 garantimos que estamos a uma distância de 4 ou menos da solução.


\anchor puzzle8-a2
## Ação 2 - Resolver manualmente

Vamos então resolver a instância manualmente. Introduza: **2; baixo dir dir baixo; *ENTER*.**

```entrada
Opção: 2
g:0 h:4 1|2|3
 3  1  2
 4  5  8
 6  7  .
Ações: baixo dir
Sucessor [1-2, ação(ões), exe]:baixo dir dir baixo
Executadas 4 ações com sucesso.
g:0 6|16|6
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
_______________________________________________________________________________
```
A instância está resolvida. Vamos agora ver o caminho gravado. Introduza **3.**

```entrada
Opção: 3

Parte 1, ações: baixo dir dir baixo
(3) 1  2
(4)(5)(8)
 6  7  .
Puzzle 8
...
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
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
Introduza: **1; 4; 4; 2; 4; *ENTER*; 5**

```entrada
g:0
 3  1  2
 4  5  8
 6  7  .
Ações: baixo dir
g:1 1|2
 3  1  2
 4  5  .
 6  7  8
Ações: baixo dir
g:1 2|4
 3  1  2
 4  5  8
 6  .  7
Ações: baixo dir
g:2 3|6
 3  1  .
 4  5  2
 6  7  8
Ações: dir
g:2 4|7
 3  1  2
 4  .  5
 6  7  8
Ações: baixo cima dir
g:2 5|10
 3  1  2
 4  .  8
 6  5  7
Ações: baixo dir esq
g:2 6|13
 3  1  2
 4  5  8
 .  6  7
Ações: baixo
g:3 7|14
 3  .  1
 4  5  2
 6  7  8
Ações: cima dir
g:3 8|16
 3  .  2
 4  1  5
 6  7  8
Ações: dir esq
g:3 9|18
 3  1  2
 4  7  5
 6  .  8
Ações: dir esq
g:3 10|20
 3  1  2
 .  4  5
 6  7  8  Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:4)
P1:1 P2:4 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:2
P11:100 P12:0 P13:0
Resultado: 4 (0,027s)
Puzzle 8
P1(Algoritmo): Largura Primeiro | P2(Debug): completo | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 11 | gerações 22 | avaliações 0
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Foi encontrada uma solução de distância 4. Podemos ver a ordem das expansões, houve estados expandidos 
que em nada contribuiam para a solução, mas serviram para garantir que não havia outra solução mais curta.

Esta instância éra fácil, mas e a instância inicial?
Vamos ver, mas reduzindo o debug para 2. Introduza: **1; 40; 4; 2; 2; *ENTER*; 5

```entrada
g:0
g:1 1|2
g:1 2|4
g:2 3|6
...
g:9 388|668
g:9 389|670
g:9 390|672 Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:1 P2:2 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:2
P11:100 P12:0 P13:0
Resultado: 10 (0,162s)
Puzzle 8
P1(Algoritmo): Largura Primeiro | P2(Debug): passos | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 391 | gerações 674 | avaliações 0
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Foi encontrado um resultado com 10 movimentos, mas foram realizadas 391 expansões, resultando em 674 gerações.
Vamos confirmar a solução. Introduza **3.**

```entrada
Parte 1, ações: esq cima cima dir
 . (4) 2
 6 (3) 5
(7)(1) 8
Parte 2, ações: baixo baixo esq
(4)(3) 2
(6) 1  5
 .  7  8
Parte 3, ações: cima dir baixo
(3) .  2
(4)(1) 5
 6  7  8
Puzzle 8
...
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```

Nesta instância, foram precisas 3 partes para mostrar a solução com 10 ações. 

Embora o estado inicial tenha sido obtido por 40 movimentos aleatórios desde o estado objetivo,
alguns dos movimentos acabaram por se inverter resultando numa instância à distãncia 10 do objetivo.


\anchor puzzle8-a4
## Ação 4 - Procura em Profundidade

Vamos ver a procura em profundidade na instância 40, que sabemos ter uma solução de 10. 
Vamos alterar o algoritmo, colocar a profundidade a 4, debug a completo e visualização a 1, 
para ser ver todos os estados. 
Introduza: **1; 40; 4; 1; 3; 9; 4; 2; 4; 3; 1; *ENTER*; 5.**

```entrada
g:0
 .  4  2
 6  3  5
 7  1  8
  +g:1 1|2 cima
  | 6  4  2
  | .  3  5
  | 7  1  8
  |  +g:2 2|4 cima
  |  | 6  4  2
  |  | 7  3  5
  |  | .  1  8
  |  |  +g:3 3|5 esq
  |  |    6  4  2
  |  |    7  3  5
  |  |    1  .  8
  |  |
  |  +g:2 3|5 esq
  |    6  4  2
  |    3  .  5
  |    7  1  8
  |     +g:3 4|8 baixo
  |     | 6  .  2
  |     | 3  4  5
  |     | 7  1  8
  |     |
  |     +g:3 4|8 cima
  |     | 6  4  2
  |     | 3  1  5
  |     | 7  .  8
  |     |
  |     +g:3 4|8 esq
  |       6  4  2
  |       3  5  .
  |       7  1  8
  |
  +g:1 4|8 esq
    4  .  2
    6  3  5
    7  1  8
     +g:2 5|10 cima
     | 4  3  2
     | 6  .  5
     | 7  1  8
     |  +g:3 6|13 cima
     |  | 4  3  2
     |  | 6  1  5
     |  | 7  .  8
     |  |
     |  +g:3 6|13 dir
     |  | 4  3  2
     |  | .  6  5
     |  | 7  1  8
     |  |
     |  +g:3 6|13 esq
     |    4  3  2
     |    6  5  .
     |    7  1  8
     |
     +g:2 6|13 esq
       4  2  .
       6  3  5
       7  1  8
        +g:3 7|14 cima
          4  2  5
          6  3  .
          7  1  8

P1:3 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:4 P10:2
P11:100 P12:0 P13:0
Resultado: -1 (0,043s)
Puzzle 8
P1(Algoritmo): Profundidade Primeiro | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 4 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 7 | gerações 14 | avaliações 0
 .  4  2
 6  3  5
 7  1  8
_______________________________________________________________________________
```
Foram vistos todos os estados, e não se encontrou uma solução. Vamos agora colocar 
o limite a 0, de modo a executar a iterativa, e debug no nível 2.
Introduza: **1; 40; 4; 9; 0; 2; 2; *ENTER*; 5.

```entrada
Iteração 1:
= g:0
Iteração 2:
--+= g:1 1|2
  += g:1 1|2
Iteração 3:
--+--+= g:2 3|6
  |  += g:2 3|6
  +--+= g:2 4|8
     += g:2 4|8
Iteração 4:
--+--+--+= g:3 7|13
  |  +--+= g:3 8|16
  |     += g:3 8|16
  |     += g:3 8|16
  +--+--+= g:3 10|21
     |  += g:3 10|21
     |  += g:3 10|21
     +--+= g:3 11|22
Iteração 5:
--+--+--+--+= g:4 15|29
  |  |     += g:4 15|29
...
           += g:4 26|52
Iteração 6:
--+--+--+--+--+= g:5 31|62
  |  |     |  += g:5 31|62
...
              += g:5 57|102
Iteração 7:
--+--+--+--+--+--+= g:6 63|114
  |  |     |  |  += g:6 63|114
...
                 += g:6 108|192
Iteração 8:
--+--+--+--+--+--+--+= g:7 115|205
  |  |     |  |  +--+= g:7 116|206
...
                 +--+= g:7 199|350
Iteração 9:
--+--+--+--+--+--+--+--+= g:8 207|365
  |  |     |  |  |     += g:8 207|365
...
                       += g:8 358|644
Iteração 10:
--+--+--+--+--+--+--+--+--+= g:9 367|660
  |  |     |  |  |     +--+= g:9 368|663
...
                       +--+= g:9 653|1126
Iteração 11:
--+--+--+--+--+--+--+--+--+--+= g:10 663|1144
  |  |     |  |  |     |     += g:10 663|1144
...
     |  |  |     |     |  |  += g:10 904|1574
     |  |  |     |     |  +--+ Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:3 P2:2 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:2
P11:100 P12:0 P13:0
Resultado: 10 (1,037s)
Puzzle 8
P1(Algoritmo): Profundidade Primeiro | P2(Debug): passos | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 905 | gerações 1576 | avaliações 0
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```

A procura em profundidade iterativa encontrou também a solução ótima, com 10 movimentos, na 11ª iteração.
Foram realizadas 905 expansões e 1576 gerações, um valor superior à procura em largura.

Notar no entanto no parâmetro P10(Repetidos): ascendentes. Significa que não foram gerados estadso, 
que num dado ramo, já tinham ocorrido anteriormente. Esta é a opção de omissão para este problema, 
já que foi redefinido CPuzzle8::ResetParametros().

Vamos repetir esta execução, com debug no nível 1, e ignorando repetidos. 
Introduza: **1; 40; 4; 2; 1; 10; 1; *ENTER*; 5.**

```entrada
#
#
#






#####
###############
################ Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:3 P2:1 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
Resultado: 10 (0,018s)
Puzzle 8
P1(Algoritmo): Profundidade Primeiro | P2(Debug): atividade | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 14852 | gerações 42350 | avaliações 0
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Podemos ver que o número de expansões e gerações é consideravelmente superior.

A verificação dos estados repetidos, é portanto um parametro bastante importante neste problema, em que
o mesmo estado pode surgir várias vezes. Vamos então testar em eliminar todos os estados repetidos.
Introduza: **1; 40; 4; 10; 3; *ENTER*; 5.**

```entrada
#
#
#








 Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:3 P2:1 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 10 (0,050s)
Puzzle 8
P1(Algoritmo): Profundidade Primeiro | P2(Debug): atividade | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 864 | gerações 1469 | avaliações 0
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
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

Vamos começar por ver (notar que P3(Ver): 1). Introduza: **1; 40; 2; esq esq; *ENTER*.**

```entrada
g:0 h:6 1|2|3
 .  4  2
 6  3  5
 7  1  8
  +#1 g:1 h:7 1|2|3 cima
  | 6  4  2
  | .  3  5
  | 7  1  8
  +#2 g:1 h:7 1|2|3 esq
    4  .  2
    6  3  5
    7  1  8
Sucessor [1-2, ação(ões), exe]:esq esq
Executadas 2 ações com sucesso.
g:0 h:8 4|9|6
 4  2  .
 6  3  5
 7  1  8
  +#1 g:1 h:9 4|9|6 cima
  | 4  2  5
  | 6  3  .
  | 7  1  8
  +#2 g:1 h:7 4|9|6 dir
    4  .  2
    6  3  5
    7  1  8
Sucessor [1-2, ação(ões), exe]:

Puzzle 8
...
 4  2  .
 6  3  5
 7  1  8
_______________________________________________________________________________
```

Na informação de um estado, vemos não apenas o valor de g (o custo), mas também o valor de h.
O valor de h é a heuristica, que idealmente é uma estimativa conservadora da distância até ao objetivo.

No estado inicial a heurística é 6, porque:
- o número 1 está à distância 2
- o número 3, 4, 6, e 7 à distância 1

Vamos ver como esta heurística guia os diferentes algoritmos informados.

\anchor puzzle8-a6
## Ação 6 - Melhor Primeiro

Vamos executar o primeiro algoritmo informado, o melhor primeiro, que segue sempre pelo ramo 
com menor heurística, ou seja, mais perto do objetivo, daí o nome de melhor primeiro.

Este é um algoritmo em profundidade pelo que vamos deixar a configuração de remoção de estados
repetidos gerados, de modo a observar o desempenho deste algoritmo nas melhores condições.

Neste e em outras execuções das procuras informadas, vamos limitar o número de avaliações a 1000000, 
de modo a ter um critério de paragem independente do tempo.

Introduza: **1; 40; 4; 1; 4; 2; 3; 8; 1000000; 10; 3; *ENTER*; 5.

```entrada
--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+& g:30 h:4 31|56|56
  |  |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     | 6  4  2
  |  |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     | 3  1  5
  |  |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     | .  7  8
  |  |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     |     |  |  |     
  +--+--+--+--+--+--+--+--+--+--+--+--+--+--+ Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:44)
P1:4 P2:3 P3:1 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 44 (0,028s)
Puzzle 8
P1(Algoritmo): Melhor Primeiro | P2(Debug): detalhe | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 45 | gerações 83 | avaliações 83
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Conseguimos uma solução de 44 ações, utilizando 45 expansões. 
O resultado em termos de esforço computacional é muito reduzido, pelo que a informação 
dada pela heurística foi útil. No entanto, a qualidade da solução baixa, já que fica com
44 de custo, quando sabemos existir uma solução de custo 10. 

\anchor puzzle8-a7
## Ação 7 - AStar

Vamos agora ver o comportamento do AStar, que garante a solução ótima. 

Introduza: **1; 40; 4; 1; 2; 4; 3; 4; 5; *ENTER*; 5.**

```entrada
g:0 h:8
 .  4  2
 6  3  5
 7  1  8
Ações: cima esq
g:1 h:7 1|2|2
 4  .  2
 6  3  5
 7  1  8
Ações: cima esq
g:1 h:7 2|4|4
 6  4  2
 .  3  5
 7  1  8
Ações: cima esq
g:2 h:6 3|6|6
 6  4  2
 3  .  5
 7  1  8
Ações: baixo cima esq
g:3 h:5 4|9|9
 6  4  2
 3  1  5
 7  .  8
Ações: dir esq
g:4 h:4 5|11|11
 6  4  2
 3  1  5
 .  7  8
Ações: baixo
g:3 h:5 6|12|12
 6  .  2
 3  4  5
 7  1  8
Ações: dir esq
g:2 h:8 7|14|14
 4  3  2
 6  .  5
 7  1  8
Ações: cima dir esq
g:3 h:7 8|17|17
 4  3  2
 6  1  5
 7  .  8
Ações: dir esq
g:4 h:6 9|19|19
 4  3  2
 6  1  5
 .  7  8
Ações: baixo
g:5 h:5 10|20|20
 4  3  2
 .  1  5
 6  7  8
Ações: baixo esq
g:6 h:4 11|22|22
 .  3  2
 4  1  5
 6  7  8
Ações: esq
g:7 h:3 12|23|23
 3  .  2
 4  1  5
 6  7  8
Ações: cima esq
g:8 h:2 13|25|25
 3  1  2
 4  .  5
 6  7  8
Ações: cima dir esq
g:9 h:1 14|28|28
 3  1  2
 .  4  5
 6  7  8
Ações: baixo cima
g:10 15|30|30
 .  1  2
 3  4  5
 6  7  8  Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:5 P2:4 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 10 (0,041s)
Puzzle 8
P1(Algoritmo): A* | P2(Debug): completo | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 15 | gerações 30 | avaliações 30
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Foram utilizadas 15 expansões para obter a solução ótima de 10 movimentos. 
Esta é portanto uma instância simples para este algoritmo.

\anchor puzzle8-a8
## Ação 8 - IDAStar

O AStar pode ter problemas de memória em instâncias complexas, existindo o IDAStar que permite a mesma ordem
de expansão, mas sem o problema de memória, em troca de algum tempo de CPU extra, gasto ao expandir multiplas
vezes os mesmos estados. Vamas ver como se comporta nesta instância.

Introduza: **1; 40; 4; 1; 6; *ENTER*; 5.**

```entrada
g:0 h:8
 .  4  2
 6  3  5
 7  1  8

Iteração 6: (expansões 0, gerações 0, avaliações 1)
g:0 h:8 |1
 .  4  2
 6  3  5
 7  1  8
  +
  +
Iteração 8: (expansões 1, gerações 2, avaliações 3)
g:0 h:8 1|2|3
 .  4  2
 6  3  5
 7  1  8
  +g:1 h:7 2|4|5 cima
  |  +g:2 h:6 3|6|7 esq
  |  |  +g:3 h:5 4|9|10 baixo
  |  |  |  +
  |  |  |  +
  |  |  +g:3 h:5 5|11|12 cima
  |  |  |  +g:4 h:4 6|13|14 dir
  |  |  |  |  +
  |  |  |  +
  |  |  +
  |  +
  +g:1 h:7 7|14|15 esq
     +
     +
Iteração 10: (expansões 8, gerações 16, avaliações 17)
g:0 h:8 8|16|17
 .  4  2
 6  3  5
 7  1  8
  +g:1 h:7 9|18|19 cima
  |  +g:2 h:6 10|20|21 esq
  |  |  +g:3 h:5 11|23|24 baixo
  |  |  |  +g:4 h:6 12|25|26 dir
  |  |  |  |  +
  |  |  |  +g:4 h:6 13|26|27 esq
  |  |  |     +
  |  |  +g:3 h:5 14|27|28 cima
  |  |  |  +g:4 h:4 15|29|30 dir
  |  |  |  |  +g:5 h:5 16|30|31 baixo
  |  |  |  |     +g:6 h:4 17|32|33 baixo
  |  |  |  |     |  +
  |  |  |  |     +
  |  |  |  +g:4 h:6 18|33|34 esq
  |  |  |     +
  |  |  +g:3 h:7 19|34|35 esq
  |  |     +
  |  |     +
  |  +g:2 h:8 20|36|37 cima
  |     +
  +g:1 h:7 21|37|38 esq
     +g:2 h:8 22|39|40 cima
     |  +g:3 h:7 23|42|43 cima
     |  |  +g:4 h:6 24|44|45 dir
     |  |  |  +g:5 h:5 25|45|46 baixo
     |  |  |     +g:6 h:4 26|47|48 baixo
     |  |  |     |  +g:7 h:3 27|48|49 esq
     |  |  |     |     +g:8 h:2 28|50|51 cima
     |  |  |     |     |  +g:9 h:1 29|53|54 dir
     |  |  |     |     |  |  +g:10 30|55|56 baixo
     |  |  |     |     |  |  | Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:6 P2:4 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 10 (0,059s)
Puzzle 8
P1(Algoritmo): IDA* | P2(Debug): completo | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 30 | gerações 55 | avaliações 56
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Podemos ver que em termos de iterações, ao contrário da procura em profundidade iterativa,
tem menos iterações. O limite da iteração seguinte é determinado pelo menor valor dos estados
cortados, avançando mais que uma unidade de cada vez.
Acabou por ter apenas 30 expansões, enquanto que o AStar utilizou 15 expansões. 

Pode-se considerar que é o dobro, mas é um pequeno preço a pagar por não ter problemas de memória.


\anchor puzzle8-a9
## Ação 9 - Branch-and-Bound

Vamos agora ver como se comporta o Branch-and-Bound, o último algoritmo informado. 
Este algoritmo pode ser visto como o Melhor Primeiro que continua a procura após a primeira solução.
No entanto restringe o espaço de procura apenas aos estados que melhoram a solução atual.

É um algoritmo em profundidade, pelo que não tem problemas de memória originados na procura em largura.
Vamos baixar o nível de debug para 1.

Introduza: **1; 40; 4; 1; 2; 1; 7; *ENTER*; 5.**

```entrada
# Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:44) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:42) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:40) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:38) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:26) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:24) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:18) Solução encontrada!
 .  1  2
 3  4  5
 6  7  8 (g:10)
P1:7 P2:1 P3:4 P4:1 P5:10 P6:0 P7:0 P8:1000000 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 10 (0,019s)
Puzzle 8
P1(Algoritmo): Branch and Bound | P2(Debug): atividade | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 1000000
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 846 | gerações 1406 | avaliações 1406
 .  1  2
 3  4  5
 6  7  8
_______________________________________________________________________________
```
Vemos que primeiramente encontra a solução de 44 movimentos, e depois vai encontrando sucessivamente 
soluções melhores até que termina com a solução de 10. Gasta nesta instância um número 
consideravelmente superior de expansões e gerações, quando comparado com o AStar.

Podemos agora ver outras instâncias, e estar a executar cada um dos algoritmos para ver qual é o melhor.
No entanto seria um trabalho fastidioso.

Não o fazer, ficariamos com a informação da performance dos algoritmos numa só instância, 
não necessariamente representativa de todas as instâncias.

É para melhor medir o desempenho de algoritmos e configurações, que existem os testes empíricos,
permitindo assim comparar algoritmos e/ou configurações num leque alargado de instâncias.

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

| [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
