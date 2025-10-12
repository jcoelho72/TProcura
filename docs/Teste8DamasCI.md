@page teste_8damas_ci Teste 8 Damas - Codificação Inteira

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


Execução de exemplo com base no problema das 8 damas, com a codificação inteira.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute.
No Linux na pasta `.../TProcura/Melhorativa/Teste$` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#8damas-ci1)
- [Ação 2 - Resolver manualmente](#8damas-ci2)
- [Ação 3 - Algoritmos Evolutivos](#8damas-ci3)
- [Ação 4 - Testes Empíricos](#8damas-ci6)


```entrada
Teste TProcuraMelhorativa
Problema:
  1 - 8 Damas
  2 - 8 Damas Inteira
  3 - 8 Damas Permutacao
  4 - Partição
  5 - Partição Binária
  6 - Artificial
Opção: 2
```


\anchor 8damas-ci1
## Ação 1 - Ver instâncias

Vamos entrar no problema 8 Damas Inteira, introduza: **2.**

```entrada
8 Damas Inteira
 P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
 P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20 | P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50
 P9(SELECAO): Roleta | P10(PRESSAO): 150 | P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100
 P16(ELITISMO): 1 | P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
 P21(TIPO_CRUZAR): 2-pontos | P22(TIPO_MUTAR): 0 | P23(TIPO_VIZINHO): incDecValor | P24(LIMITE_VIZINHOS): 0
 P25(TIPO_DISTANCIA): Hamming
::  ::  ::  ##
  ::##::  ::  ::
::  ::  ::  ::##
##::  ::  ::  ::
::  ::  ##  ::
  ::  ::  ::##::
::  ::  ##  ::
  ::  ::  ::  ##

____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
```
Temos uma instância das 8 Damas como no exemplo da TProcuraConstrutiva. 
Em vez de um tabuleiro vazio, em que iamos construindo a solução adicionando damas, 
existem damas já colocadas mas que se atacam mutuamente.
Esta é uma solução completa aleatória, que pretendemos melhorar. 
Tem ainda violações, que são damas a atacarem-se, que neste contexto transfoormam-se em custos,
que pretendemos remover. 

Temos um número de parametros mais extenso, embora os 5 primeiros parametros sejam os mesmos que no exemplo do teste TVector.
O último parametro é o P25, muito embora não estejam 25 parametros. 
O P11 por exemplo não é mostrado. Alguns parametros só são ativos devido a valores de outros parametros.
Como temos o P1(ALGORITMO) em Algoritmos Evolutivos, este algoritmo tem muitos parametros, e por esse motivo
são mostrados bastantes. Iremos abordar cada um no momento próprio.

Vamos trocar para uma instância menor antes de avançarmos, para simplificar a nossa exploração.

Introduza: **1;4.**

```entrada
Opção: 1

ID atual: 8  Intervalo: [4-40]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto): 4

8 Damas Inteira
 P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
...
 P25(TIPO_DISTANCIA): Hamming
::  ##
  ::##::
::  ::##
##::  ::

____________________________________________________________________
```

Estavamos na instância 8 e agora estamos na instância 4. Temos um tabuleiro de 4x4 para colcoar 4 damas.
Podiamos ter escolhido até tabuleiros de 40x40.


\anchor 8damas-ci2
## Ação 2 - Resolver manualmente

Vamos então resolver a instância manualmente. Introduza: **2.**

```entrada
Opção: 2

 Melhor solução (g:2)
##  ::
  ::##::
##  ::
  ::  ##

5ms  Época 0, população 4 (g: 2 a 4)
População:
   1: 0 2 0 3  (g: 2)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 3 3 1 0  (g: 4)
Diversidade:
    |   1|   2|   3|   4|
----|----|----|----|----|
   1|    |   4|   4|   4|
   2|   4|    |   3|   1|
   3|   4|   3|    |   3|
   4|   4|   1|   3|    |
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos):
```
Entramos num modo de expoloração manual, com as operações dos algoritmos melhorativos.
No entanto a população foi fixada a 4, para podermos melhor gerir a exploração manual.
Durante a geração da população de 4 elementos, foi encontrada uma solução de custo 2, mostrada.
Arranca a época 0, tal como os genéticos, mas neste caso cada época é o resultado de aplicar um operador.

Podemos ver a população de 4 elementos, com custos de 2 a 4.
É mostrado a codificação inteira, e não as soluções a que correspondem. 
Assim pretenedemos focar no que os algoritmos vêm, e não no que pretendemos.
Temos um mapa de diversidade, com as distâncias entre os 4 elemnentos. 
A medida de distência de omissão Hamming, significando que conta simplesmente os valores distintos.
Podemos alterar através do parametro P25(TIPO_DISTANCIA). 
Há vários tipos de distâncias disponíveis dependendo da codificação.
Há dois elmentos à distância de 1 unidade, o 2 e 4. De facto, estes diferem apenas no valor do segundo inteiro.

Temos 3 operações para testar, a mutação, cruzamento e vizinhança.
Vamos começar pela mutação, para mutar o indivíduo 4. Introduza: **1; 4.**

```entrada
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos): 1
Individuo [1-4]: 4

Atual:  3 3 1 0  mutar vizinho incDecValor (3,1)
Mutado: 3 3 1 1
::  ::##
  ::  ##
::##::
  ##  ::

35" 556ms  Época 1, população 4 (g: 2 a 4)
População:
   1: 0 2 0 3  (g: 2)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 3 3 1 1  (g: 4)
Diversidade:
    |   1|   2|   3|   4|
----|----|----|----|----|
   1|    |   4|   4|   4|
   2|   4|    |   3|   2|
   3|   4|   3|    |   4|
   4|   4|   2|   4|    |
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos):
```

A mutação acabou por trocar apenas um valor, o que se pode confirmar nas linhas Atual e Mutado, com as codificaçõe seguidas e alinhadas.
Ficou uma solução igualmente má. 
Podemos alterar a mutação no parametro P22(TIPO_MUTAR). 
Existem também vários operadores de mutação disponíveis dependente do tipo de codificação.

Vamos agora passar para o cruzamento, e cruzar o individuo 1 com o 3, os dois melhores na população, e substituir o individuo 4. 
Introduza: **2; 1; 3; 4.**

```entrada
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos): 2
Pai [1-4]: 1
Mãe [1-4]: 3
Filho [1-4]: 4

Pai:   0 2 0 3
Mãe:   1 0 3 0  cruzamento 1-ponto(s): 3
Filho: 0 2 0 0
##  ::
  ::##::
##  ::
##::  ::

1' 35" 811ms  Época 2, população 4 (g: 2 a 4)
População:
   1: 0 2 0 3  (g: 2)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 0 2 0 0  (g: 4)
Diversidade:
    |   1|   2|   3|   4|
----|----|----|----|----|
   1|    |   4|   4|   1|
   2|   4|    |   3|   3|
   3|   4|   3|    |   3|
   4|   1|   3|   3|    |
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos):
```
O filho ficou quase igual à mãe, com os três primeiros elmentos da mãe, e o último do pai. 
Existem vários tipos de operadores de cruzamento, controlados pelo parametro P21(TIPO_CRUZAR).
Diferentes operadores estão disponíveis em diferentes codificações, podendo cada operador ter também parâmetros próprios.

Falta-nos explorar o operador de vizinhança, pelo que vamos aplicar ao melhor individuo 1, e escolher o melhor vizinho. 
Introduza: **3; 1; 1.**

```entrada
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos): 3
Individuo [1-4]: 1

Atual: 0 2 0 3  vizinhança incDecValor (limite 0)
Vizinhos:
   1: 1 2 0 3  (g: 1)
   2: 0 3 0 3  (g: 3)
   3: 0 1 0 3  (g: 5)
   4: 0 2 1 3  (g: 2)
   5: 0 2 0 2  (g: 2)
Vizinho [1-5]: 1

1' 1" 853ms  Melhor solução (g:1)
::##::
  ::##::
##  ::
  ::  ##

1' 1" 857ms  Época 3, população 4 (g: 1 a 4)
População:
   1: 1 2 0 3  (g: 1)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 0 2 0 0  (g: 4)
Diversidade:
    |   1|   2|   3|   4|
----|----|----|----|----|
   1|    |   4|   3|   2|
   2|   4|    |   3|   3|
   3|   3|   3|    |   3|
   4|   2|   3|   3|    |
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos):
```

O vizinho tem agora o custo 1, pelo que estamos mais perto. 
Foi feita a substituição da melhor solução, que tem agora custo 1.
Notar que o tipo de vizinhança é descrito, neste caso apenas incrementamos ou decrementamos cada valor em uma unidade.
Devido a esta opção, a vizinhança tem um número controlado de indivíduos.

Vamos insistir e ver os vizinhos deste novo elemento, e novamente escolher o melhor destes.
Introduza: **3; 1; 3.**

```entrada
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos): 3
Individuo [1-4]: 1

Atual: 1 2 0 3  vizinhança incDecValor (limite 0)
Vizinhos:
   1: 2 2 0 3  (g: 2)
   2: 0 2 0 3  (g: 2)
   3: 1 3 0 3  (g: 1)
   4: 1 1 0 3  (g: 3)
   5: 1 2 1 3  (g: 3)
   6: 1 2 0 2  (g: 2)
Vizinho [1-6]: 3

::##::
  ::  ##
##  ::
  ::  ##
1 3 0 3
5' 33" 823ms  Época 3, população 4 (g: 1 a 4)
População:
   1: 1 3 0 3  (g: 1)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 0 2 0 0  (g: 4)
Diversidade:
    |   1|   2|   3|   4|
----|----|----|----|----|
   1|    |   4|   3|   3|
   2|   4|    |   3|   3|
   3|   3|   3|    |   3|
   4|   3|   3|   3|    |
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos):
```

Neste caso o vizinho tem o mesmo custo, mas é outro vizinho, pelo que vale a pena ainda uma última vez, ver quais os seus vizinhos.
Introduza: **3; 1; 5.**

```entrada
Operação (1 - Mutar, 2 - Cruzar, 3 - Vizinhos): 3
Individuo [1-4]: 1

Atual: 1 3 0 3  vizinhança incDecValor (limite 0)
Vizinhos:
   1: 2 3 0 3  (g: 3)
   2: 0 3 0 3  (g: 3)
   3: 1 2 0 3  (g: 1)
   4: 1 3 1 3  (g: 2)
   5: 1 3 0 2  (g: 0)
Vizinho [1-5]: 5

2' 54" 221ms  Melhor solução (g:0)
::##::
  ::  ##
##  ::
  ::##::

8 Damas Inteira
 P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
 P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20 | P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50
 P9(SELECAO): Roleta | P10(PRESSAO): 150 | P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100
 P16(ELITISMO): 1 | P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
 P21(TIPO_CRUZAR): 1-ponto | P22(TIPO_MUTAR): 0 | P23(TIPO_VIZINHO): incDecValor | P24(LIMITE_VIZINHOS): 0
 P25(TIPO_DISTANCIA): Hamming
::##::
  ::  ##
##  ::
  ::##::

____________________________________________________________________
```
Temos finalmente a solução de custo 0, o que pretendiamos. Uma solução com as 4 damas, sem se atacarem.
Ao selecionar o vizinho com a solução ótima, a exploração é interrompida, tal como qualquer algoritmo, 
sendo a solução obitida é retornada. 



\anchor 8damas-ci3
## Ação 3 - Algoritmos Evolutivos

Vamos agora ver como o algoritmo evolutivo poderia obter esta solução de forma automática, com a parametrização de omissão.
Introduza: **1; 4; 6.**

```entrada
Opção: 6

 P1=3 P2=0 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50
 P9=1 P10=150 P13=1 P14=100 P16=1 P17=1 P18=3 P19=0
 P21=1 P22=0 P23=1 P24=0 P25=1
8 Damas Inteira
...
::  ##
##::  ::
::  ::##
  ##  ::

I1(Resultado): 0 | I2(Tempo(ms)): 8 | I3(Iterações): 241 | I4(Épocas): 10 | I5(Gerações): 250
____________________________________________________________________
```

Podemos ver que o primeiro indicador, I1(Resultado) é igual a 0. Este é o custo da solução.
Podemos observar a solução e ver que as damas não se atacam, aliás, é exatamente a mesma solução obtida manualmente.

O segundo indicador I2(Tempo(ms)) é 0, o que significa que foi consumido menos de 1 milisegundo.

Temos o número de iterações a 241, que corresponde às avaliações efetuadas, e 10 épocas, o que corresponde ao número de ciclos do algoritmo evolutivo.
Finalmente, temos o número de estados gerados a 250.

Há informação visivel nos indicadores, mas não vemos nada em termos de funcionamento do algoritmo. 
O que aconteceu nestas 10 épocas?
Vendo a parametrização podemos ver que há população de 20, e toda a informação de operadores e opções.
Mas estaremos satisfeitos com esta informação? Não, precisamos de ver o que se passou, para saber o que correu bem e menos bem.

Como podemos repetir todas as execuções, podemos ver a mesma execução com diferentes níveis de detalhe.
Vamos aproveitar esta execução que tem tamanho reduzido, para ir subindo o nível de debug.
Introduza: **1; 4; 3; 2; 1; *ENTER*; 6.**


```entrada
Opção: 6
.
 Melhor solução (g:2)
##  ::
  ::##::
##  ::
  ::  ##

3ms  Melhor solução (g:1)
##  ::
  ::##::
::  ::##
  ##  ::

6ms  Melhor solução (g:0)
::  ##
##::  ::
::  ::##
  ##  ::

 P1=3 P2=1 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50
 P9=1 P10=150 P13=1 P14=100 P16=1 P17=1 P18=3 P19=0
 P21=1 P22=0 P23=1 P24=0 P25=1
8 Damas Inteira
...
::  ##
##::  ::
::  ::##
  ##  ::

I1(Resultado): 0 | I2(Tempo(ms)): 15 | I3(Iterações): 241 | I4(Épocas): 10 | I5(Gerações): 250
____________________________________________________________________
```
Nesta repetição, vemos um ponto de quando em quando, para saber que há atividade. 
No final são introduzidos 128 pontos, se o número de iterações for atingido.
Como gastamos muito poucas iterações, e o limite é muito alto, estes pontos nem são visiveis.

Mas vemos algo importante. Sempre que uma melhor solução global é encontrada, é registado o tempo e a solução é mostrada ao utilizador.
Podemos ver que primeiro foi encontrada uma solução de custo 2, de seguida outra de custo 1 e finalmente a de custo 0.

Sabemos mais alguma coisa do que se passou, mas não muito.

Vamos ver agora o nível de debug PASSOS.
Introduza: **1; 4; 3; 2; 2; *ENTER*; 6.**

```entrada
Opção: 6

 Melhor solução (g:2)
##  ::
  ::##::
##  ::
  ::  ##

3ms  Época 0, população 20 (g: 2 a 5)
4ms  Melhor solução (g:1)
##  ::
  ::##::
::  ::##
  ##  ::

6ms  Época 1, população 20 (g: 1 a 5)
7ms  Época 2, população 20 (g: 1 a 5)
8ms  Época 3, população 20 (g: 1 a 5)
9ms  Época 4, população 20 (g: 1 a 5)
10ms  Época 5, população 20 (g: 1 a 5)
11ms  Época 6, população 20 (g: 1 a 4)
12ms  Época 7, população 20 (g: 1 a 5)
13ms  Época 8, população 20 (g: 1 a 5)
14ms  Época 9, população 20 (g: 1 a 4)
15ms  Melhor solução (g:0)
::  ##
##::  ::
::  ::##
  ##  ::

 P1=3 P2=2 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50
 P9=1 P10=150 P13=1 P14=100 P16=1 P17=1 P18=3 P19=0
 P21=1 P22=0 P23=1 P24=0 P25=1
8 Damas Inteira
...
::  ##
##::  ::
::  ::##
  ##  ::

I1(Resultado): 0 | I2(Tempo(ms)): 21 | I3(Iterações): 241 | I4(Épocas): 10 | I5(Gerações): 250
____________________________________________________________________
```

Temos agora a informação das diferentes épocas. 
Em cada época é registado o instante em que esta ocorre, neste caso apenas alguns milisegundos,
o número da época, a população e o menor e maior custo na população.

Aqui é possível observar que nesta procura, a melhor solução na população nunca piorou de uma época para a outra.
Dependente da parametrização, nem sempre esta situação é garantida. A utilização de P16(ELITISMO)=1 garante
que pelo menos um elemento da população antiga, irá manter-se caso na nova população não exista nenhum elemento com valor melhor ou igual.

Aumentamos o conhecimento, mas ainda estamos um pouco às escuras. 
Fora o parametro do elitismo, nada mais pode ser observado ou verificada a sua utilidade.

É tempo para aumentar o nível de debug para DETALHE.
Introduza: **1; 4; 3; 2; 3; *ENTER*; 6.**

```entrada
Opção: 6

 Melhor solução (g:2)
##  ::
  ::##::
##  ::
  ::  ##

3ms  Época 0, população 20 (g: 2 a 5) [d: 1 a 4 (média 2, melhor/pior 3)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   4|   3|   4|   4|   2|   3|   2|   4|   2|
  10|   2|   4|   2|   5|   3|   2|   5|   3|   5|   4|
12ms  Melhor solução (g:1)
##  ::
  ::##::
::  ::##
  ##  ::

15ms  Época 1, população 20 (g: 1 a 5) [d: 1 a 4 (média 2, melhor/pior 4)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   1|   4|   4|   4|   3|   2|   5|   4|   3|   2|
  10|   4|   4|   2|   3|   2|   2|   3|   4|   4|   3|
24ms  Época 2, população 20 (g: 1 a 5) [d: 1 a 4 (média 3, melhor/pior 3)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   4|   3|   5|   2|   3|   4|   3|   3|   4|
  10|   4|   3|   2|   2|   4|   1|   3|   2|   4|   2|
34ms  Época 3, população 20 (g: 1 a 5) [d: 1 a 4 (média 2, melhor/pior 3)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   4|   3|   5|   3|   4|   2|   1|   4|   4|   3|
  10|   3|   1|   3|   3|   3|   3|   2|   4|   2|   4|
42ms  Época 4, população 20 (g: 1 a 5) [d: 0 a 4 (média 2, melhor/pior 2)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   4|   2|   1|   2|   3|   1|   4|   4|   3|   3|
  10|   4|   3|   3|   3|   1|   5|   3|   3|   2|   4|
51ms  Época 5, população 20 (g: 1 a 5) [d: 1 a 4 (média 2, melhor/pior 3)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   1|   4|   1|   3|   3|   4|   2|   4|   4|   1|
  10|   4|   2|   4|   3|   3|   3|   5|   2|   3|   4|
59ms  Época 6, população 20 (g: 1 a 4) [d: 1 a 4 (média 2, melhor/pior 4)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   3|   4|   3|   2|   4|   2|   1|   4|   1|   2|
  10|   4|   3|   1|   3|   4|   3|   2|   3|   1|   3|
67ms  Época 7, população 20 (g: 1 a 5) [d: 0 a 4 (média 2, melhor/pior 4)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   3|   3|   4|   4|   2|   3|   3|   2|   1|   5|
  10|   4|   3|   4|   1|   2|   1|   1|   3|   5|   4|
76ms  Época 8, população 20 (g: 1 a 5) [d: 1 a 4 (média 2, melhor/pior 4)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   5|   2|   4|   4|   4|   3|   4|   1|   5|   1|
  10|   1|   4|   3|   3|   3|   1|   3|   4|   3|   4|
86ms  Época 9, população 20 (g: 1 a 4) [d: 0 a 4 (média 2, melhor/pior 2)]
 Ind|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   3|   2|   3|   2|   2|   1|   1|   2|   2|
  10|   4|   3|   2|   3|   4|   2|   2|   3|   2|   3|
95ms  Melhor solução (g:0)
::  ##
##::  ::
::  ::##
  ##  ::

 P1=3 P2=3 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50
 P9=1 P10=150 P13=1 P14=100 P16=1 P17=1 P18=3 P19=0
 P21=1 P22=0 P23=1 P24=0 P25=1
8 Damas Inteira
...
::  ##
##::  ::
::  ::##
  ##  ::

I1(Resultado): 0 | I2(Tempo(ms)): 103 | I3(Iterações): 241 | I4(Épocas): 10 | I5(Gerações): 250
____________________________________________________________________
```

Temos agora uma tabela para cada época e informação extendida sobre as distâncias.
Na época 0 sabemos que as distâncias entre indivíduos vai de 2 a 4, a média das distâncias é 2,
e a distância entre o melhor e o pior indivíduo é 3.

A cada linha da época segue-se agora uma tabela "Ind".
Esta tabela tem para cada um dos 20 indivíduos na população o seu custo.
Tem 10 colunas e tantas linhas quantas necessárias, uma por cada dezena de indivíduos. 
O indivíduo 14 está na linha com índice 10 e coluna com índice 4, que na época 0 tinha custo 5.

Assim, podemos ter uma ideia mais detalhada dos custos dos indivíduos, e uma ideia da diversidade.
Se a diversidade da população for muito baixa, podemos observar a média de distâncias com valor baixo.
Se apenas alguns elementos tiverem um bom valor, e a maior parte tiver um valor mau, podemos também observar.

Idealmente pretendemos uma diversidade alta e alto valor nos indivíduos, portanto baixo custo.
Por vezes o que ocorre num problema mal afinado, é que todas as soluções fiquem com o mesmo valor, e a diversidade seja muito baixa.
Nesse caso o algoritmo fica estagnado, sendo essa a situação mais crítica a evitar.

Embora possamos observar a situação mais indesejáve que pode ocorrer num algoritmo evolutivo, a estagnação,
nada sabemos sobre os indivíduos concretos, e o que se passa de uma população para a outra.

Há várias fases para passar de uma época para a outra, e muitos operadores são aplicados. 
Mas isso é interno aos algoritmos evolutivos, nada é visivel neste nível de debug.

É portanto tempo para passarmos para o último nível de debug, COMPLETO.
Introduza:  **1; 4; 3; 2; 4; *ENTER*; 6.**

```entrada
Opção: 6

 Melhor solução (g:2)
##  ::
  ::##::
##  ::
  ::  ##

5ms  Época 0, população 20 (g: 2 a 5)
População:
   1: 0 2 0 3  (g: 2)
   2: 3 1 1 0  (g: 4)
   3: 1 0 3 0  (g: 3)
   4: 3 3 1 0  (g: 4)
   5: 3 1 2 3  (g: 4)
   6: 3 0 2 3  (g: 2)
   7: 3 0 3 0  (g: 3)
   8: 2 0 2 3  (g: 2)
   9: 0 0 0 3  (g: 4)
  10: 3 0 0 2  (g: 2)
  11: 0 3 1 1  (g: 2)
  12: 1 2 3 0  (g: 4)
  13: 2 3 3 0  (g: 2)
  14: 0 0 1 0  (g: 5)
  15: 0 3 0 0  (g: 3)
  16: 3 0 0 3  (g: 2)
  17: 1 2 1 2  (g: 5)
  18: 3 0 1 1  (g: 3)
  19: 1 2 1 0  (g: 5)
  20: 0 0 2 2  (g: 4)
Diversidade:
    |   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|  11|  12|  13|  14|  15|  16|  17|  18|  19|  20|
----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
   1|    |   4|   4|   4|   3|   3|   4|   3|   1|   3|   3|   3|   4|   3|   2|   2|   3|   4|   3|   3|
   2|   4|    |   3|   1|   2|   3|   2|   4|   4|   3|   3|   3|   3|   2|   3|   3|   3|   2|   2|   4|
   3|   4|   3|    |   3|   4|   3|   1|   3|   3|   3|   4|   1|   2|   2|   3|   3|   3|   3|   2|   3|
   4|   4|   1|   3|    |   3|   3|   2|   4|   4|   3|   2|   3|   2|   2|   2|   3|   3|   2|   2|   4|
   5|   3|   2|   4|   3|    |   1|   3|   2|   3|   3|   4|   4|   4|   4|   4|   2|   4|   3|   4|   3|
   6|   3|   3|   3|   3|   1|    |   2|   1|   2|   2|   4|   4|   4|   3|   4|   1|   4|   2|   4|   2|
   7|   4|   2|   1|   2|   3|   2|    |   3|   3|   2|   4|   2|   2|   2|   3|   2|   4|   2|   3|   3|
   8|   3|   4|   3|   4|   2|   1|   3|    |   2|   3|   4|   4|   3|   3|   4|   2|   4|   3|   4|   2|
   9|   1|   4|   3|   4|   3|   2|   3|   2|    |   2|   3|   4|   4|   2|   2|   1|   4|   3|   4|   2|
  10|   3|   3|   3|   3|   3|   2|   2|   3|   2|    |   4|   4|   4|   3|   3|   1|   3|   2|   4|   2|
  11|   3|   3|   4|   2|   4|   4|   4|   4|   3|   4|    |   4|   3|   2|   2|   4|   3|   2|   3|   3|
  12|   3|   3|   1|   3|   4|   4|   2|   4|   4|   4|   4|    |   2|   3|   3|   4|   2|   4|   1|   4|
  13|   4|   3|   2|   2|   4|   4|   2|   3|   4|   4|   3|   2|    |   3|   2|   4|   4|   4|   3|   4|
  14|   3|   2|   2|   2|   4|   3|   2|   3|   2|   3|   2|   3|   3|    |   2|   3|   3|   2|   2|   2|
  15|   2|   3|   3|   2|   4|   4|   3|   4|   2|   3|   2|   3|   2|   2|    |   3|   4|   4|   3|   3|
  16|   2|   3|   3|   3|   2|   1|   2|   2|   1|   1|   4|   4|   4|   3|   3|    |   4|   2|   4|   3|
  17|   3|   3|   3|   3|   4|   4|   4|   4|   4|   3|   3|   2|   4|   3|   4|   4|    |   3|   1|   3|
  18|   4|   2|   3|   2|   3|   2|   2|   3|   3|   2|   2|   4|   4|   2|   4|   2|   3|    |   3|   3|
  19|   3|   2|   2|   2|   4|   4|   3|   4|   4|   4|   3|   1|   3|   2|   3|   4|   1|   3|    |   4|
  20|   3|   4|   3|   4|   3|   2|   3|   2|   2|   2|   3|   4|   4|   2|   3|   3|   3|   3|   4|    |
FASE Selecionar 20 pais - Roleta, pressão 150.
100%|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|  75|  38|  49|  41|  43|  59|  51|  64|  33|  62|
  10|  72|  46|  70|  25|  54|  67|  28|  57|  30|  36|
Número de seleções
#Pai|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   1|   1|   0|   1|   1|   1|   2|   0|   2|
  10|   1|   1|   1|   1|   1|   1|   1|   1|   1|   0|
FASE Reproduzir 20 pais
Pais emparelhados:
 IDs|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|  10|  14|   6|   8|  16|   8|   5|   1|  15|  13|
  10|  11|  17|  10|  19|  18|   3|   2|   7|  12|   1|
119ms  Melhor solução (g:1)
##  ::
  ::##::
::  ::##
  ##  ::

Custo (g):
Pais|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   4|   3|   4|   3|   3|   5|   2|   5|   2|
  10|   2|   3|   2|   4|   2|   2|   2|   2|   5|   2|
Filhos (g) - 10 cruzamentos, 14 mutações
Desc|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   1|   4|   4|   4|   4|   3|   2|   5|   2|   4|
  10|   3|   2|   4|   4|   2|   3|   2|   2|   3|   4|
FASE Selecionar sobreviventes - Elite 1 (se < 1) - Idade - Imigrantes 1
FASE Diversidade - limpeza (1 removidos)
141ms  Época 1, população 20 (g: 1 a 5)
...
1" 198ms  Época 9, população 20 (g: 1 a 4)
População:
   1: 0 3 3 1  (g: 2)
   2: 0 2 3 0  (g: 3)
   3: 2 0 2 1  (g: 2)
   4: 3 1 0 3  (g: 3)
   5: 0 3 1 3  (g: 2)
   6: 0 2 0 3  (g: 2)
   7: 0 2 3 1  (g: 1)
   8: 1 3 0 3  (g: 1)
   9: 0 3 3 2  (g: 2)
  10: 2 2 3 1  (g: 2)
  11: 1 3 3 1  (g: 4)
  12: 1 2 0 1  (g: 3)
  13: 3 0 0 3  (g: 2)
  14: 1 0 3 1  (g: 3)
  15: 2 2 2 0  (g: 4)
  16: 0 1 3 1  (g: 2)
  17: 2 2 0 3  (g: 2)
  18: 0 3 2 2  (g: 3)
  19: 3 2 0 3  (g: 2)
  20: 1 2 0 1  (g: 3)
Diversidade:
    |   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|  11|  12|  13|  14|  15|  16|  17|  18|  19|  20|
----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
   1|    |   2|   3|   4|   2|   3|   1|   3|   1|   2|   1|   3|   4|   2|   4|   1|   4|   2|   4|   3|
   2|   2|    |   4|   4|   3|   2|   1|   4|   2|   2|   3|   3|   4|   3|   2|   2|   3|   3|   3|   3|
   3|   3|   4|    |   4|   4|   4|   3|   4|   4|   2|   3|   3|   3|   2|   2|   3|   3|   3|   4|   3|
   4|   4|   4|   4|    |   3|   2|   4|   2|   4|   4|   4|   3|   1|   4|   4|   3|   2|   4|   1|   3|
   5|   2|   3|   4|   3|    |   2|   3|   2|   2|   4|   3|   4|   3|   4|   4|   3|   3|   2|   3|   4|
   6|   3|   2|   4|   2|   2|    |   2|   2|   3|   3|   4|   2|   2|   4|   3|   3|   1|   3|   1|   2|
   7|   1|   1|   3|   4|   3|   2|    |   4|   2|   1|   2|   2|   4|   2|   3|   1|   3|   3|   3|   2|
   8|   3|   4|   4|   2|   2|   2|   4|    |   3|   4|   2|   2|   2|   3|   4|   4|   2|   3|   2|   2|
   9|   1|   2|   4|   4|   2|   3|   2|   3|    |   3|   2|   4|   4|   3|   4|   2|   4|   1|   4|   4|
  10|   2|   2|   2|   4|   4|   3|   1|   4|   3|    |   2|   2|   4|   2|   2|   2|   2|   4|   3|   2|
  11|   1|   3|   3|   4|   3|   4|   2|   2|   2|   2|    |   2|   4|   1|   4|   2|   4|   3|   4|   2|
  12|   3|   3|   3|   3|   4|   2|   2|   2|   4|   2|   2|    |   3|   2|   3|   3|   2|   4|   2|   0|
  13|   4|   4|   3|   1|   3|   2|   4|   2|   4|   4|   4|   3|    |   3|   4|   4|   2|   4|   1|   3|
  14|   2|   3|   2|   4|   4|   4|   2|   3|   3|   2|   1|   2|   3|    |   4|   2|   4|   4|   4|   2|
  15|   4|   2|   2|   4|   4|   3|   3|   4|   4|   2|   4|   3|   4|   4|    |   4|   2|   3|   3|   3|
  16|   1|   2|   3|   3|   3|   3|   1|   4|   2|   2|   2|   3|   4|   2|   4|    |   4|   3|   4|   3|
  17|   4|   3|   3|   2|   3|   1|   3|   2|   4|   2|   4|   2|   2|   4|   2|   4|    |   4|   1|   2|
  18|   2|   3|   3|   4|   2|   3|   3|   3|   1|   4|   3|   4|   4|   4|   3|   3|   4|    |   4|   4|
  19|   4|   3|   4|   1|   3|   1|   3|   2|   4|   3|   4|   2|   1|   4|   3|   4|   1|   4|    |   2|
  20|   3|   3|   3|   3|   4|   2|   2|   2|   4|   2|   2|   0|   3|   2|   3|   3|   2|   4|   2|    |
FASE Selecionar 20 pais - Roleta, pressão 150.
100%|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|  57|  41|  49|  36|  51|  46|  72|  75|  67|  54|
  10|  28|  33|  64|  30|  25|  59|  62|  43|  70|  38|
Número de seleções
#Pai|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   1|   1|   1|   0|   1|   1|   2|   1|   2|   1|
  10|   0|   1|   1|   1|   0|   1|   2|   0|   2|   1|
FASE Reproduzir 20 pais
Pais emparelhados:
 IDs|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|  10|   1|  19|   3|   8|  17|  14|  12|   7|  16|
  10|  17|   7|   9|   9|  20|   6|   5|   2|  19|  13|
1" 310ms  Melhor solução (g:0)
::  ##
##::  ::
::  ::##
  ##  ::

Custo (g):
Pais|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   2|   3|   2|   2|   3|   2|   2|   1|   2|
  10|   2|   1|   3|   3|   2|   1|   2|   2|   2|   2|
Filhos (g) - 10 cruzamentos, 12 mutações
Desc|   1|   2|   3|   4|   5|   6|   7|   8|   9|  10|
----|----|----|----|----|----|----|----|----|----|----|
   0|   2|   2|   2|   3|   2|   2|   3|   2|   1|   2|
  10|   2|   4|   0|   4|   4|   1|   5|   1|   1|   3|
FASE Selecionar sobreviventes - Elite 1 (se < 0) - Idade - Imigrantes 1
FASE Diversidade - limpeza (0 removidos)
 P1=3 P2=4 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50
 P9=1 P10=150 P13=1 P14=100 P16=1 P17=1 P18=3 P19=0
 P21=1 P22=0 P23=1 P24=0 P25=1
8 Damas Inteira
...
::  ##
##::  ::
::  ::##
  ##  ::

I1(Resultado): 0 | I2(Tempo(ms)): 1341 | I3(Iterações): 241 | I4(Épocas): 10 | I5(Gerações): 250
____________________________________________________________________
```

A informação é agora bastante extensa, pelo que colocamos apenas a primeira e última época. 
Em cada época tem toda a população, mostrando a codificação de cada elemento e o seu custo.
Temos após a população um mapa de distâncias entre indivíduos, para poder ter uma idia mais completa da diversidade da população.
Este mapa é realizado apenas para populações de 20 ou menos indivíduos, sendo feito um mapa mais curto para populações maiores.

Mostra-se informação de todas as fases. A primeira fase é a seleção dos pais. 
Há informação na época 0 de que irão ser selecionados 20 pais pelo método Roleta, com pressão 150.
Este valor corresponde a 1,5, sendo que o valor 1 todos os membros têm a mesma probabilidade, e com 2
os melhores têm muito mais possibildiades de ser escolhidos.
A permilagem de cada indivíduo é colocada na tabela 100%.

Podemos ver a diferença entre o 1 e o 2, tendo o indivíduo 1 custo 2 e o indivíduo 2 custo 4.
A probabilidade de ser selecionado o indivíduo 1 é de 7,5% enquanto que o indivíduo 2 tem probabilidade de 3,8%.

Como resultado destas probabilidades, a tabela seguinte, #Pai, tem o número de vezes que cada indivíduo foi escolhido para pai.
O primeiro indivíduo foi escolhido 2 vezes. Podemos ver alguns indivíduos que nem foram escolhidos, como o 4.

Terminada a fase de seleção dos pais, arranca a fase de reprodução. 
Nesta fase temos os pais emparelhados. Na tabela IDs podemos ver os indivíduos da população original por uma ordem de reprodução.
Podemos confirmar que o indivíduo 1 está duas vezes, na posição 8 e 20. Irá reproduzir com o indivíduo 5 e 12.

Os filhos são gerados com base nestes pares, o primeiro com o segundo, o terceiro com o quarto e assim  sucessivamente. 
Há sempre dois filhos por cada casal de pais. Durante a geração dos filhos, foi encontrado uma solução melhor que o registo global.

As duas tabelas seguintes têm os custos dos pais e dos filhos, onde se pode ver o GAP geracional. 
Podemos ver por exemplo, o casal 1 e 2, tinham custo 2 e 4 e os seus filhos ficaram com custos 1 e 4.

A fase de sobrevivência, atendendo a que o método é a idade, não há muito a mostrar, dado que a geração nova substitui a geração antiga.
Há no entanto indicação sobre elite e imigrantes.

Ocorreu nesta época a fase de limpeza, tendo sido eliminado um elemento que estava duplicado, atendendo às configurações de omissão.

Podemos ver na época 9 que os pais da melhor solução, tinham ambos custo 3, e essa solução teve um "irmão" com custo 4.
Podemos ainda ver na tabela de IDs que esses dois pais eram na verdade a solução 9, que tinha sido selecionada 2 vezes na seleção de pais.
Por um acaso ficaram seguidos, resultando portanto em filhos iguais à solução 9, tendo sido aplicado uma mutação que melhorou num caso e piorou no outro.

Esta é uma análise bastante completa, tendo muita informação. 
Pode ser utilizada em instâncias pequenas para compreender os algoritmos e diferentes opções, 
e também para um dado problema procurar entender porque algumas parametrizações resultam melhor que outras.
Aumentando o entendimento no problema, é possível que apareçam oportunidades de melhoria que se possam explorar.

Para identificar as melhores parametrizações, temos de ter testes empíricos, tal como nos restantes exemplos, e esse é o tema da próxima secção.

\anchor 8damas-ci4
## Ação 4 - Testes Empíricos

O modo interativo é importante para compreender e aprender, mas para se poder tirar conclusões temos de ter 
um número considerável de execuções. 

Vamos agora procurar saber qual a melhor parametrização dos algoritmos evolutivos para as 8 damas.

Começamos por executar a parametrização de omissão nas primeiras instâncias.
Como o algoritmo é aleatório, é crítico fazer mais que uma execução. 
No entanto neste exemplo, sem processamento paralelo, vamos fazer apeans 1 execução.
Iremos repetir o teste mais tarde com mais execuções, num cluster, e assim poder observar uma melhoria na qualidade dos resultados.
Colocamos o nível de debug a PASSO, para ter alguma informação durante execução.

Notar que nos testes empíricos, o nível de debug destina-se à informação sobre o progresso da execução global,
mas o algoritmo é executado sempre sem qualquer debug, de modo a obtermos a melhor performance.

Linha de comando: TProcuraMelhorativa.exe 4:40 -R damasCIt1 -P P2=2 

```entrada
PS ...\Teste> .\x64\Release\TProcuraMelhorativa.exe 4:40 -R damasCIt1 -P P2=2
...
Opção: 2

Teste com 37 tarefas, 37 instâncias, 1 configurações, utilizando 1 processo(s).
1' 7" 430ms  Tarefa 25.
2' 7" 437ms  Tarefa 31.
Ficheiro damasCIt1.csv gravado.
Tempo real: 3' 7" 447ms
CPU total: 3' 7" 449ms
Taxa de utilização: 100,0%
```

Houve reporte a cada minuto, e a execução demorou 3 minutos.
Os tempos de execução não foram afetados por ter o nível de debug a 2, apenas é influenciada a informação sobre o progresso das execuções.

Podemos agora ver a tabela de resultados:

| Instância | I1(Resultado) | I2(Tempo(ms)) | I3(Iterações) | I4(Épocas) |
|:---:|---:|---:|---:|---:|
| 4 | 0 | 0 | 241 | 10 |
| 5 | 0 | 0 | 210 | 9 |
| 6 | 0 | 0 | 105 | 4 |
| 7 | 0 | 3 | 2040 | 95 |
| 8 | 0 | 3 | 2063 | 96 |
| 9 | 0 | 17 | 9500 | 446 |
| 10 | 0 | 8 | 3066 | 144 |
| 11 | 0 | 91 | 40402 | 1898 |
| 12 | 0 | 84 | 34942 | 1641 |
| 13 | 0 | 533 | 201347 | 9467 |
| 14 | 0 | 455 | 146253 | 6879 |
| 15 | 0 | 603 | 184587 | 8681 |
| 16 | 0 | 61 | 15886 | 748 |
| 17 | 0 | 2757 | 689898 | 32461 |
| 18 | 0 | 1833 | 403174 | 18973 |
| 19 | 0 | 3164 | 695640 | 32722 |
| 20 | 0 | 3460 | 676772 | 31860 |
| 21 | 1 | 5612 | 1000002 | 47056 |
| 22 | 1 | 6039 | 1000013 | 47060 |
| 23 | 0 | 3141 | 458090 | 21565 |
| 24 | 1 | 6915 | 1000002 | 47070 |
| 25 | 0 | 2643 | 347321 | 16343 |
| 26 | 1 | 10001 | 998103 | 46990 |
| 27 | 1 | 10001 | 910933 | 42896 |
| 28 | 2 | 10001 | 954472 | 44966 |
| 29 | 1 | 10001 | 867581 | 40859 |
| 30 | 1 | 10001 | 768950 | 36213 |
| 31 | 1 | 10001 | 713185 | 33584 |
| 32 | 2 | 10001 | 616686 | 29051 |
| 33 | 1 | 10001 | 501125 | 23596 |
| 34 | 2 | 10001 | 504596 | 23775 |
| 35 | 2 | 10001 | 431877 | 20350 |
| 36 | 3 | 10001 | 422171 | 19896 |
| 37 | 3 | 10001 | 445109 | 20975 |
| 38 | 3 | 10001 | 408987 | 19275 |
| 39 | 3 | 10001 | 378330 | 17825 |
| 40 | 3 | 10001 | 379320 | 17878 |

A parametrização de omissão consegue resolver até à instância 20, mas após essa instância, falha tanto por tempo como por número de iterações.

Não interressa ter instâncias demasiado simples ou demasiado complicadas nos testes. 
Como estes testes não vão ser num cluster, convém ter um conjunto de teste reduzido.
Pretendemos melhorar o algoritmo no ponto de transição. 
Assim, vamos escolher para conjunto de teste, as instâncias 17 a 26.

O primeiro parametro a averiguar, é o tamanho da população.

Linha de comando: TProcuraMelhorativa.exe 17:26 -R damasCIt2 -P P2=2 P6=10,20,30,50,100,200

Notar que repetimos a população 20, da qual já tinhamos resultados. 
Poderiamos aproveitar, mas não só é mais simples repetir, como repetindo garante-se condições de igualdade entre execuções.

```entrada
Teste com 60 tarefas, 10 instâncias, 6 configurações, utilizando 1 processo(s).
1' 1" 759ms  Tarefa 14.
2' 4" 110ms  Tarefa 30.
3' 11" 96ms  Tarefa 47.
4' 12" 568ms  Tarefa 57.
Ficheiro damasCIt2.csv gravado.
Tempo real: 4' 39" 25ms
CPU total: 4' 39" 27ms
Taxa de utilização: 100,0%
```

Podemos agregar o somatório do resultado e a média do tempo.

| Rótulos de Linha | Soma de I1(Resultado) | Média de I2(Tempo(ms)) |
|:---:|---:|---:|
| 10 | 13 | 5026 |
| 20 | 4 | 4339 |
| 30 | 2 | 3044 |
| 50 | 2 | 3331 |
| 100 | 8 | 5830 |
| 200 | 9 | 6329 |

Tanto pelos resultados como pelo tempo, a população de 30 a 50 aparenta ser melhor,
embora sem grande precisão dado que há apenas uma execução por cada configuração.

.... (continuar para outros parametros)



| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
