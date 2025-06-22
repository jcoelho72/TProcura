@page teste_jogo_do_galo Teste Jogo do Galo

Execução de exemplo com base no problema do Jogo do Galo. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#jdg-a1)
- [Ação 2 - Explorar sucessores](#jdg-a2)
- [Ação 3 - MiniMax](#jdg-a3)
- [Ação 4 - MiniMax com cortes Alfa/Beta](#jdg-a4)
- [Ação 5 - Explorar todo o espaço de estados](#jdg-a5)
- [Ação 6 - Testes Empíricos](#jdg-a6)


```entrada
Teste TProcurasAdversas
Problema:
  1 - Jogo do Galo
  2 - Jogo Em Linha
Opção: 1
```

![Jogo do Galo - cada jogador joga numa casa na sua vez, ganha quem faz 3 em linha](docs/images/jdg.png)


\anchor jdg-a1
## Ação 1 - Ver instâncias

Vamos entrar no Jogo do Galo, introduza: **1.**

```entrada
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Este é o estado vazio do tabuleiro do Jogo do Galo. Temos um tabuleiro de 3x3, 
e cada jogador ocupa uma casa livre na sua 
vez de jogar. O objetivo é colocar 3 marcas seguidas.

Este problema é um jogo, pelo que requer a procura adversa. 
Há no entanto muitos parametros comuns com as procuras construtivas
de agente único. Temos aqui como parametro base, a ordenação, que tem o valor 2. 
Este parametro permite que estados repetidos que já tenham sido analisados num nível igual ou superior ao requerido, 
possam ser reutilizados em vez de chamar novamente a procura. 
Esta é a opção equivalente a ignorar estados repetidos, que não deve ser ativada já que
um movimento num dado estado tem de ser considerado, mesmo que tenha ocorrido em outro local.
Podemos é não recalcular tudo novamente para o estado repetido, guardando o resultado e nível de 
profundidade realizadas, para reutilizar assim que o estado seja analisado novamente.

Temos também a poda heurística, e poda cega, de modo a eliminar sucessores pelo seu 
valor heurístico, ou simplesmente de forma aleatória (cega). Estes parametros podem ser necessários em jogos cuja ramificação
seja muito elevada, não fazendo tanto sentido para situações de procura não adversa.

Em tudo o resto estamos em situação idêntica, embora os algoritmos sejam distintos, tendo por omissão o algoritmo MiniMax alfa/beta.

Introduza: **1.** para inicialiar novo jogo.


```entrada
Jogo do Galo
...
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

Podemos ver que há apenas uma instância, com o tabuleiro inicial. 
Podemos ver a borda do tabuleiro com indicação da coluna em letras, 
e linhas em números. Cada casa fica identificada de forma unívoca.


\anchor jdg-a2
## Ação 2 - Explorar sucessores

Vamos entrar na exploração manual. Introduza: **2; a2; b2.**

```entrada
g:0 1|9|10
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 a2 b2 c2 a3 b3 c3
Sucessor [1-9, ação(ões), exe]:a2
Executadas 1 ações com sucesso.
g:0 2|17|19
  A B C
1 . . . 1
2 x . . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 b2 c2 a3 b3 c3
Sucessor [1-8, ação(ões), exe]:b2
Executadas 1 ações com sucesso.
g:0 3|24|27
  A B C
1 . . . 1
2 x o . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 c2 a3 b3 c3
Sucessor [1-7, ação(ões), exe]:
```

A cada momento são mostradas as ações possíveis, correspondendo às casas livres para jogar.
Cada jogador deixa a sua marca à vez. Vamos verifica se o jogo deteta vitória.
Introduza: **a3 c1 a1.**


```entrada
Sucessor [1-7, ação(ões), exe]:a3 c1 a1
Executadas 3 ações com sucesso.
g:0 h:-1000 3|24|28
  A B C
1 x . o 1
2 x o . 2
3 x . . 3
  A B C
Ações:
Sem sucessores.
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 3 | gerações 24 | avaliações 28
  A B C
1 x . o 1
2 x o . 2
3 x . . 3
  A B C
_______________________________________________________________________________
```

O jogo terminou com sucesso, vitória X, pelo que não há mais sucessores.

O jogo tem 3 simetrias, vamos agora ver como fica esta exploração com a remoção de estados repetidos.
Introduza: **4; 10; 3; *ENTER*; 1; 2.**

```entrada
g:0 1|3|4
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
Ações: a1 b1 b2
Sucessor [1-3, ação(ões), exe]:
```

Em vez das 9 possíveis ações, restam 3 ações, a1, b1 e b2. 
Todas as outras ações conduzem a estados que podem ser convertidos nestes, com uma ou mais de 3 simetrias:
horizontal, vertical, diagonal. Assim, não é necessário explorá-los. 

Introduza: **1; *ENTER*.**

```entrada
g:0 1|3|4
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
Ações: a1 b1 b2
Sucessor [1-3, ação(ões), exe]:2
g:0 2|8|9
  A B C
1 . x . 1
2 . . . 2
3 . . . 3
  A B C
Ações: a1 a2 b2 a3 b3
Sucessor [1-5, ação(ões), exe]:
```
Este
Temos agora a1, mas não c1 (obtido por simetria vertical). Do mesmmo modo temos a2, mas não c2, e a3 mas não c3.
Já b2 e b3 não têm estados simétricos. 

Assim, reduzimos consideravelmente a ramificação inicial, bem como os estados existentes no geral.

No entanto, tal como referido na ação 1, não podemos ignorar repetidos, já que podemos estar a eliminar alternativas importantes
num estado, apenas porque ocorrem em outro. Mas com esta experiência podemos ver a importância das simetrias.

O parâmetro de estados repetidos deve ficar nas procuras adversas em igonrar, e o de ordenação em 2.

Note que se quisermos jogar contra o computador, podemos utilizar a ação "exe" para que o computador jogue com o algoritmo atual.


\anchor jdg-a3
## Ação 3 - MiniMax

Vamos começar por ver o MiniMax neste formato, ignorando estados repetidos, 
com informação de debug completa, vendo todos os estados, e nível de profundidade 2,
e com P14(Ordenar)=0.
Introduza: **1; 4; 1; 1; 2; 4; 3; 1; 9; 2; 10; 1; 14; 0; *ENTER*; 5.**

```entrada
g:0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
  #g:1 1|9 a1
  /  A B C
  /1 x . . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  / 0
  /(0)
  #g:1 1|9|1 b1
  /  A B C
  /1 . x . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  / 0
  #g:1 1|9|2 c1
  /  A B C
  /1 . . x 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  / 0
  #g:1 1|9|3 a2
  /  A B C
  /1 . . . 1
  /2 x . . 2
  /3 . . . 3
  /  A B C
  / 0
  #g:1 1|9|4 b2
  /  A B C
  /1 . . . 1
  /2 . x . 2
  /3 . . . 3
  /  A B C
  / 0
  #g:1 1|9|5 c2
  /  A B C
  /1 . . . 1
  /2 . . x 2
  /3 . . . 3
  /  A B C
  / 0
  #g:1 1|9|6 a3
  /  A B C
  /1 . . . 1
  /2 . . . 2
  /3 x . . 3
  /  A B C
  / 0
  #g:1 1|9|7 b3
  /  A B C
  /1 . . . 1
  /2 . . . 2
  /3 . x . 3
  /  A B C
  / 0
  #g:1 1|9|8 c3
     A B C
   1 . . . 1
   2 . . . 2
   3 . . x 3
     A B C
    0
P1:1 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:2 P10:1
P11:100 P12:0 P13:0 P14:0 P15:0 P16:0
Resultado: 0 (0,170s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 2 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 0 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 1 | gerações 9 | avaliações 9
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

Podemos ver a árvore de procura, que há 9 estados gerados, embora apenas 3 sejam distintos
a menos das 3 simetrias. 

A heurística neste problema é a deteção de estado final, pelo que vemos 0 como valor de cada ramo final.

Vamos agora colocar P14(Ordenar): 2, e repetir a procura. Introduza: **1; 4; 14; 2; *ENTER*; 5.**

Vamos agora ver os estados completos, e não apenas as ações, e repetir nova procura.
Introduza: **4; 3; 1; *ENTER*; 5.**

```entrada
g:0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
  #g:1 1|9 a1
  /  A B C
  /1 x . . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  / 0
  /(0)
  #g:1 1|9|1 b1
  /  A B C
  /1 . x . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  / 0
  #
  #
  #g:1 1|9|2 b2
  /  A B C
  /1 . . . 1
  /2 . x . 2
  /3 . . . 3
  /  A B C
  / 0
  #
  #
  #
  #
P1:1 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:2 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,081s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 2 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 1 | gerações 9 | avaliações 3
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

A procura foi realizada, existindo agora apenas 3 avaliações, já que apenas 3 estados novos foram gerados. 
Outros estados foram gerados, mas são iguais a menos de operações de simetria.

Na árvore de procura esses estados não desaparecem, mas a árvore é podada.
Se o estado já foi analisado nesse nível (ou com mais profundidade), reutiliza-se o valor em vez de expandir o estado.

Vamos continuar, mas reduzindo o nível de debug para passos, e aumentando o nível para 3. 
Introduza: **4; 2; 2; 9; 3; *ENTER*; 5.**  

```entrada
--+--#= g:2 2|15|5 0
  |  /(0)
  |  #= g:2 2|15|6 0
  |  #
  |  #= g:2 2|15|7 0
  |  #= g:2 2|15|8 0
  |  #
  |  #
  |(0)
  +--#= g:2 3|22|9 0
  |  /(0)
  |  #= g:2 3|22|10 0
  |  #= g:2 3|22|11 0
  |  #= g:2 3|22|12 0
  |  #= g:2 3|22|13 0
  |  #= g:2 3|22|14 0
  |  #= g:2 3|22|15 0
  +--#= g:2 4|29|16 0
  |  /(0)
  |  #= g:2 4|29|17 0
  |  #= g:2 4|29|18 0
  |  #= g:2 4|29|19 0
  |  #
  |  #= g:2 4|29|20 0
  |  #= g:2 4|29|21 0
  +--#= g:2 5|36|22 0
  |  /(0)
  |  #
  |  #= g:2 5|36|23 0
  |  #= g:2 5|36|24 0
  |  #= g:2 5|36|25 0
  |  #= g:2 5|36|26 0
  |  #= g:2 5|36|27 0
  +--#= g:2 6|43|28 0
  |  /(0)
  |  #= g:2 6|43|29 0
  |  #
  |  #= g:2 6|43|30 0
  |  #
  |  #
  |  #= g:2 6|43|31 0
  +
  +
  +
P1:1 P2:2 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:3 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,159s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): passos | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 6 | gerações 43 | avaliações 32
  A B C
1 x . . 1
2 . . . 2
3 . . o 3
  A B C
_______________________________________________________________________________
```

Continuamos com avaliações todas com heurística nula, pelo que para o algoritmo é indiferente qualquer opção.
Vamos agora executar mais algumas jogadas, e ver a execução final com debug a 4. 

Introduza: **5; 5; 4; 2; 4; *ENTER*; 5.**

```entrada
 HT: reutilização 0,35 vezes g:0
  A B C
1 x x o 1
2 . . . 2
3 . . o 3
  A B C
  #g:1 1|5|5 a2
  /  A B C
  /1 x x o 1
  /2 x . . 2
  /3 . . o 3
  /  A B C
  /  +g:2 2|9|5 b2
  /  |  A B C
  /  |1 x x o 1
  /  |2 x o . 2
  /  |3 . . o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 2|9|6 c2
  /  |  A B C
  /  |1 x x o 1
  /  |2 x . o 2
  /  |3 . . o 3
  /  |  A B C
  /  | 998
  /  |(998)
  /(998)
  #g:1 2|9|7 a3
  /  A B C
  /1 x x o 1
  /2 . . . 2
  /3 x . o 3
  /  A B C
  /  +g:2 3|13|7 a2
  /  |  A B C
  /  |1 x x o 1
  /  |2 o . . 2
  /  |3 x . o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 3|13|8 b2
  /  |  A B C
  /  |1 x x o 1
  /  |2 . o . 2
  /  |3 x . o 3
  /  |  A B C
  /  | 0
  /  +g:2 3|13|9 c2
  /  |  A B C
  /  |1 x x o 1
  /  |2 . . o 2
  /  |3 x . o 3
  /  |  A B C
  /  | 998
  /  |(998)
  #g:1 3|13|10 c2
  /  A B C
  /1 x x o 1
  /2 . . x 2
  /3 . . o 3
  /  A B C
  /  +g:2 4|17|10 a2
  /  |  A B C
  /  |1 x x o 1
  /  |2 o . x 2
  /  |3 . . o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 4|17|11 b2
  /  |  A B C
  /  |1 x x o 1
  /  |2 . o x 2
  /  |3 . . o 3
  /  |  A B C
  /  | 0
  /  +g:2 4|17|12 a3
  /  |  A B C
  /  |1 x x o 1
  /  |2 . . x 2
  /  |3 o . o 3
  /  |  A B C
  /  | 0
  /  +g:2 4|17|13 b3
  /     A B C
  /   1 x x o 1
  /   2 . . x 2
  /   3 . o o 3
  /     A B C
  /    0
  /(0)
  #g:1 4|17|14 b2
  /  A B C
  /1 x x o 1
  /2 . x . 2
  /3 . . o 3
  /  A B C
  /  +g:2 5|21|14 a2
  /  |  A B C
  /  |1 x x o 1
  /  |2 o x . 2
  /  |3 . . o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 5|21|15 c2
  /  |  A B C
  /  |1 x x o 1
  /  |2 . x o 2
  /  |3 . . o 3
  /  |  A B C
  /  | 998
  /  |(998)
  #g:1 5|21|16 b3
     A B C
   1 x x o 1
   2 . . . 2
   3 . x o 3
     A B C
     +g:2 6|25|16 a2
     |  A B C
     |1 x x o 1
     |2 o . . 2
     |3 . x o 3
     |  A B C
     | 0
     |(0)
     +g:2 6|25|17 b2
     |  A B C
     |1 x x o 1
     |2 . o . 2
     |3 . x o 3
     |  A B C
     | 0
     +g:2 6|25|18 c2
     |  A B C
     |1 x x o 1
     |2 . . o 2
     |3 . x o 3
     |  A B C
     | 998
     |(998)
P1:1 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:3 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,162s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 6 | gerações 25 | avaliações 19
  A B C
1 x x o 1
2 . . x 2
3 . . o 3
  A B C
_______________________________________________________________________________
```
Podemos ver que a árvore de procura já interseta posições em que há vitória de O, sendo o valor de +infinito. 
O infinito é de omissão 1000. O X é o primeiro a jogar, e em SolucaoVazia() é indicado que o primeiro a jogar procura minimizar o jogo.
O valor dos estados em que O ganha é 998 e não 1000. Ao valor do infinito é subtraído o número de jogadas desde a jogada atual.
Esta ação tem o efeito de uma derrota de X que seja mais uma jogada, tenha valer 997. Como O pretende maximizar, pelo que prefere
sempre as vitórias mais curtas, tal como o X, e ambos preferem as derrotas mais longas.

Notar ainda para a frase inicial: "HT: reutilização 0,35 vezes". Ao ser limpa a hashtable com o registo dos estados na procura anterior,
é verificado quantas vezes um estado guardado foi reutilizado, poupando assim uma execução do algoritmo para esse estado.


\anchor jdg-a4
## Ação 4 - MiniMax com cortes Alfa/Beta

Vamos agora ver como se comporta a procura da ação anterior, se ativarmos os cortes alfa/beta.
Introduza: **1; 4; 1; 2; 2; 4; 3; 1; 9; 3; *ENTER*; 5;

```entrada
 HT: reutilização 0,25 vezes g:0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
  #g:1 1|9|3 a1
  /  A B C
  /1 x . . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  /  +g:2 2|17|3 b1
  /  |  A B C
  /  |1 x o . 1
  /  |2 . . . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 2|17|4 c1
  /  |  A B C
  /  |1 x . o 1
  /  |2 . . . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  +
  /  +g:2 2|17|5 b2
  /  |  A B C
  /  |1 x . . 1
  /  |2 . o . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  +g:2 2|17|6 c2
  /  |  A B C
  /  |1 x . . 1
  /  |2 . . o 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  +
  /  +
  /  +g:2 2|17|7 c3
  /     A B C
  /   1 x . . 1
  /   2 . . . 2
  /   3 . . o 3
  /     A B C
  /    0
  /(0)
  #
  #g:1 2|17|8 c2
  /  A B C
  /1 . . . 1
  /2 . . x 2
  /3 . . . 3
  /  A B C
  /  +g:2 3|25|8 a1
  /  |  A B C
  /  |1 o . . 1
  /  |2 . . x 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  > beta(0)
  #g:1 3|25|9 b3
  /  A B C
  /1 . . . 1
  /2 . . . 2
  /3 . x . 3
  /  A B C
  /  +g:2 4|33|9 a1
  /  |  A B C
  /  |1 o . . 1
  /  |2 . . . 2
  /  |3 . x . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  > beta(0)
  #g:1 4|33|9 b2
  /  A B C
  /1 . . . 1
  /2 . x . 2
  /3 . . . 3
  /  A B C
  /  +g:2 5|41|9 a1
  /  |  A B C
  /  |1 o . . 1
  /  |2 . x . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  > beta(0)
  #
  #g:1 5|41|10 b1
  /  A B C
  /1 . x . 1
  /2 . . . 2
  /3 . . . 3
  /  A B C
  /  +g:2 6|49|10 a1
  /  |  A B C
  /  |1 o x . 1
  /  |2 . . . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  > beta(0)
  #g:1 6|49|11 a2
  /  A B C
  /1 . . . 1
  /2 x . . 2
  /3 . . . 3
  /  A B C
  /  +g:2 7|57|11 a1
  /  |  A B C
  /  |1 o . . 1
  /  |2 x . . 2
  /  |3 . . . 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  > beta(0)
  #
P1:2 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:3 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,083s)
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 7 | gerações 57 | avaliações 11
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

Temos na procura vários cortes beta. Vamos ver com atenção:
- o primeiro ramo com X em a1 foi explorado por completo
- no final desse ramo aparece "/(0)". Significa que beta (que minimiza) tem uma alternativa explorada que garante pelo menos 0.
- no ramo com X em c2, vamos dar a um estado de valor 0. Assim, para c2, temos o adversário que pode obter 0, mas para isso X vai para o ramo anterior e obtém 0, pelo que este ramo pode ser cortado
- notar que foi analizado o estado em que X joga b3 (e b1 e a2), que é simétrico de c2. Teve de ser já que o resultado do estado com X em c2 não é exato,
  e neste caso não pode ser utilizado. Dependente se o resultado é obtido após corte alfa ou beta, será um lowerbound ou upperbound 
  do valor real, sendo utilizado em conformidade.
- notar que o estado com X em a1, foi explorado completamente, tendo sido memorizado, e por esse motivo os estados com X em a3, c1 e c3, não são explorados, já que são reutilizados.
- no ramo com X em b2 ocorre exatamente o mesmo, após se explorar um ramo, sabe-se que o adversário pode obter 0, pelo que não mais interessa.

Como resultado dos corte, temos menos avaliações, mas podemos ter menos memorizações ou que por sua vez pode aumentar
as avaliações. Se a ramificação é alta, valerá sempre a pena o alfa/beta, se a ramificação é baixa, pode ser compensador
não ter o alfa/beta de modo a que fiquem memorizados estado com o valor exato.

Vamos avaçar para o momento em que há estados finais visiveis.
Introduza: **5; 5; 5; 5; 5; 5.**

```entrada
g:0
  A B C
1 x x o 1
2 . . x 2
3 . o o 3
  A B C
  #g:1 1|3|3 a2
  /  A B C
  /1 x x o 1
  /2 x . x 2
  /3 . o o 3
  /  A B C
  /  +g:2 2|5|3 b2
  /  |  A B C
  /  |1 x x o 1
  /  |2 x o x 2
  /  |3 . o o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 2|5|4 a3
  /     A B C
  /   1 x x o 1
  /   2 x . x 2
  /   3 o o o 3
  /     A B C
  /    998
  /   (998)
  /(998)
  #g:1 2|5|5 b2
  /  A B C
  /1 x x o 1
  /2 . x x 2
  /3 . o o 3
  /  A B C
  /  +g:2 3|7|5 a2
  /  |  A B C
  /  |1 x x o 1
  /  |2 o x x 2
  /  |3 . o o 3
  /  |  A B C
  /  | 0
  /  |(0)
  /  +g:2 3|7|6 a3
  /     A B C
  /   1 x x o 1
  /   2 . x x 2
  /   3 o o o 3
  /     A B C
  /    998
  /   (998)
  #g:1 3|7|7 a3
     A B C
   1 x x o 1
   2 . . x 2
   3 x o o 3
     A B C
     +g:2 4|9|7 a2
     |  A B C
     |1 x x o 1
     |2 o . x 2
     |3 x o o 3
     |  A B C
     | 0
     |(0)
     +g:2 4|9|8 b2
        A B C
      1 x x o 1
      2 . o x 2
      3 x o o 3
        A B C
       0
   (0)
P1:2 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:3 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,049s)
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 4 | gerações 9 | avaliações 9
  A B C
1 x x o 1
2 . . x 2
3 x o o 3
  A B C
_______________________________________________________________________________
```
Neste caso não tivemos um corte alfa/beta, dado que o melhor ramo foi expandido no final.

Assim, na procura iterativa é importante ordenar os estados por ordem de valor, de modo a que os melhoes estados sejam analisados primeiro
e possam potenciar o número de cortes. 

Naturalmente que estes cortes tornam-se mais significativos em árvores de procura maiores.

\anchor jdg-a5
## Ação 5 - Explorar todo o espaço de estados

Vamos agora procurar explorar todo o espaço de estados, o que é possível apenas porque este jogo tem dimensões reduzidas.
Para que a hashtable não poupe demasiados estados, vamos nesta ação arrancar com o programa em cada teste.

Vamos começar com o MiniMax, sem a ordenação. Vamos colocar o limite a 20, para não interferir
Após reiniciar, introduza: **1; 4; 1; 1; 9; 20; 14; 0; *ENTER*; 5.**

```entrada
P1:1 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:20 P10:1
P11:100 P12:0 P13:0 P14:0 P15:0 P16:0
Resultado: 0 (0,111s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 20 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 0 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 155758 | gerações 318517 | avaliações 113416
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```
Podemos ver que há 318517 estados gerados, um valor reduzido para os tempos atuais.
O resultado do jogo é um empate.

Vamos agora ver o efeito da ordenação. 
Após arrancar, introduza:  **1; 4; 9; 20; 14; 2; *ENTER*; 5.**

```entrada
P1:1 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:20 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,009s)
Jogo do Galo
P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 20 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 624 | gerações 2299 | avaliações 826
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

O número de estados gerados é consideravelmente inferior, ficando em apenas 2299 estados.

Vamos agora procurar ver o impacto dos cortes alfa/beta, na versão sem ordenação.
Após arrancar, introduza:  **1; 4; 1; 2; 9; 20; 14; 0; *ENTER*; 5.**

```entrada
P1:2 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:20 P10:1
P11:100 P12:0 P13:0 P14:0 P15:0 P16:0
Resultado: 0 (0,015s)
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 20 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 0 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 11750 | gerações 27362 | avaliações 7848
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```
O número de estados gerados é de 27362, em vez de 318517 para o MiniMax sem cortes alfa/beta.
Podemos observar um grande ganho. Vamos agora ver qual o resultado do alfa/beta com ordenação.
Após arrancar, introduza:  **1; 4; 1; 2; 9; 20; 14; 2; *ENTER*; 5.**

```entrada
P1:2 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:20 P10:1
P11:100 P12:0 P13:0 P14:2 P15:0 P16:0
Resultado: 0 (0,016s)
Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 20 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 1212 | gerações 3633 | avaliações 806
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```

Os estados gerados ficam em 3633, contra 2299 sem cortes alfa/beta. 
Não reduz, mas em termos de avaliações temos 806, enquanto sem cortes alfa/beta temos 826.

O número de estados gerados é até superior, relativamente sem cortes alfa/beta,
porque a reutilização das procuras é superior ao algoritmo sem cortes alfa/beta, 
em que todos os resultados são exatos. Conforme já referido, nos cortes alfa/beta alguns resultados são influenciados com o 
alfa/beta existente, sendo um lowerbound ou upperbound do real valor, e podem ser utilizados apenas se o alfa/beta
atual for compatível. Assim, a utilzação de cortes alfa/beta é mais rápido no imediato,
mas guarda-se menos informação para procuras futuras, e reutilização.

Naturalmente que esta árvore de procura é pequena, pelo que estes resultados têm também de ser interpretados com cuidado.

O problema sendo pequeno, não faz sentido fazer uma heurística.

\anchor jdg-a6
## Ação 6 - Testes Empíricos

Embora a estratégia de jogo seja fácil de obter, vamos simular um torneio para demonstrar a possibilidade de
comparar parametros distintos.

O único parametro que faz diferença, atendendo a que os tempos de execução são muito rápidos, é a profundidade da procura.
Vamos colocar em competição várias configurações a diferentes profundidades, e pretendemos conseguir observar
maior desempenho nas procuras de maior profundidade.

Temos também de ter o cuidado de desligar a utilização das hashtables, para observer sem perturbações o ganho da profundidade.

Introduza: 
- **4; 1; 2; 9; 20; 14; 0; *ENTER*; 6; *EMNTER*.**
- **4; 9; 7; *ENTER*; 6; *EMNTER*.**
- **4; 9; 5; *ENTER*; 6; *EMNTER*.**
- **4; 9; 3; *ENTER*; 6; *EMNTER*.**

```entrada
Parametros comuns a 4 configurações:
P1:2 P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P10:1 P11:100
P12:0 P13:0 P14:0 P15:0 P16:0
--- Configuração 1
P9:20
--- Configuração 2
P9:7
--- Configuração 3
P9:5
--- Configuração 4 --- atual
P9:3
```

Temos 4 configurações. Como a procura é adversa, é necessário duas configurações, ou seja, jogos entre configurações para avaliar.
Assim, em vez da tabela com desempenho individual, há jogos entre todas as configurações, e reportado apenas a tabela de torneio final.

Podemos ainda ver as soluções, que aqui equivale a observar os jogos. 
Como são 4 configurações, haverá grande quantidade de jogos, de todos contra todos e de ambas as cores. 
Por outro lado os jogos são muito rápidos. Assim, não vamos querer ver os jogos.
Se existissem vários tabuleiros iniciais, ou vários tamanhos, ou seja, instâncias de jogo, podiamos indicar as instâncias a serem utilizadas. 

Introduza: **7; 0; 1; 1**

```entrada
Match 1 vs 2:
 Instância 1:  Empate
Match 1 vs 3:
 Instância 1:  Vitória Branca
Match 1 vs 4:
 Instância 1:  Vitória Branca
Match 2 vs 1:
 Instância 1:  Empate
Match 2 vs 3:
 Instância 1:  Vitória Branca
Match 2 vs 4:
 Instância 1:  Vitória Branca
Match 3 vs 1:
 Instância 1:  Empate
Match 3 vs 2:
 Instância 1:  Empate
Match 3 vs 4:
 Instância 1:  Vitória Branca
Match 4 vs 1:
 Instância 1:  Empate
Match 4 vs 2:
 Instância 1:  Empate
Match 4 vs 3:
 Instância 1:  Empate
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    |  0 |  1 |  1 |  2
 |----|----|----|----|
 2  0 |    |  1 |  1 |  2
 |----|----|----|----|
 3  0 |  0 |    |  1 | -1
 |----|----|----|----|
 4  0 |  0 |  0 |    | -3
 |----|----|----|----|
Tempos: 0,033s 0,009s 0,004s 0,000s
Parametros comuns a 4 configurações:
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
P14(Ordenar): 0 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
--- Configuração 1
P9(Limite): 20
--- Configuração 2
P9(Limite): 7
--- Configuração 3
P9(Limite): 5
--- Configuração 4
P9(Limite): 3

Jogo do Galo
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 0 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 1 | gerações 1 | avaliações 1
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
_______________________________________________________________________________
```
Podemos ver os resultados dos jogos, seguido do torneio, em que as duas primeiras configurações são igualmente boas.
Assim, é suficiente procura em profundidade 7 para obter a estratégia vencedora. 
As restantes configurações, à medida que se reduz o nível de profundidade, a qualidade baixa, como seria de esperar.

Notar na informação da linha com os tempos: "Tempos: 0,033s 0,009s 0,004s 0,000s"
Estes tempos são o tempo total de jogo de cada configuração, para todos os jogos. 
Profundidades maiores o tempo é superior.

Este é no entanto um jogo muito pequeno para explorar, pelo que a sua generalização para os Jogos Em Linha, 
permitirá explorar melhor as particularidades das procuras adversas.


