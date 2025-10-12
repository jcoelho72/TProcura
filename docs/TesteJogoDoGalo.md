@page teste_jogo_do_galo Teste Jogo do Galo

Execução de exemplo com base no problema do Jogo do Galo.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraAdversa, e execute.
No Linux na pasta `.../TProcura/Adversa/Teste$` execute `make` seguido de `./bin/Release/TProcuraAdversa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#jdg-a1)
- [Ação 2 - Explorar sucessores](#jdg-a2)
- [Ação 3 - MiniMax](#jdg-a3)
- [Ação 4 - MiniMax com cortes Alfa/Beta](#jdg-a4)
- [Ação 5 - Explorar todo o espaço de estados](#jdg-a5)
- [Ação 6 - Testes Empíricos](#jdg-a6)


```entrada
Teste TProcuraAdversa
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
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
```

Este é o estado vazio do tabuleiro do Jogo do Galo. Temos um tabuleiro de 3x3, 
e cada jogador ocupa uma casa livre na sua 
vez de jogar. O objetivo é colocar 3 marcas seguidas.

Este problema é um jogo, pelo que requer a procura adversa. 
Há no entanto muitos parametros comuns com as procuras construtivas
de agente único. Temos aqui como parametro base, a ordenação, que tem o valor 2. 
Este parametro permite que estados repetidos que já tenham sido analisados num nível igual ou superior ao requerido, 
possam ser reutilizados em vez de chamar novamente a procura. 
Esta é a opção equivalente a ignorar estados repetidos, que não deve ser ativada no âmbito das procuras adversas, já que
um movimento num dado estado tem de ser considerado, mesmo que tenha ocorrido em outro local.
Podemos é não recalcular tudo novamente para o estado repetido, guardando o resultado e nível de 
profundidade realizadas, para reutilizar assim que o estado seja analisado novamente.

Temos também a poda heurística, e poda cega, de modo a eliminar sucessores pelo seu 
valor heurístico, ou simplesmente de forma aleatória (cega). 
Estes parametros podem ser necessários em jogos cuja ramificação
seja muito elevada, não fazendo tanto sentido para situações de procura não adversa.

Em tudo o resto estamos em situação idêntica, embora os algoritmos sejam distintos. 
Temos por omissão o algoritmo MiniMax alfa/beta.

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
g:0 1|9|4
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 a2 b2 c2 a3 b3 c3
Sucessor [1-9, ação(ões), exe]:a2
Executadas 1 ações com sucesso.
g:0 3|26|9
  A B C
1 . . . 1
2 x . . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 b2 c2 a3 b3 c3
Sucessor [1-8, ação(ões), exe]:b2
Executadas 1 ações com sucesso.
g:0 5|41|13
  A B C
1 . . . 1
2 x o . 2
3 . . . 3
  A B C
Ações: a1 b1 c1 c2 a3 b3 c3
Sucessor [1-7, ação(ões), exe]:
```

A cada momento são mostradas as ações possíveis, correspondendo às casas livres para jogar.
Cada jogador deixa a sua marca à vez. Vamos verificar se o jogo deteta vitória.
Introduza: **a3 c1 a1.**


```entrada
Sucessor [1-7, ação(ões), exe]:a3 c1 a1
Executadas 3 ações com sucesso.
g:0 h:-1000 8|59|14
  A B C
1 x . o 1
2 x o . 2
3 x . . 3
  A B C
Ações:
Sem sucessores.
Jogo do Galo
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . o 1
2 x o . 2
3 x . . 3
  A B C
____________________________________________________________________
```

O jogo terminou com sucesso, vitória X, pelo que não há mais sucessores.

O jogo tem 3 simetrias, vamos agora ver como fica esta exploração com a remoção de estados repetidos.
Introduza: **3; 8; 3; *ENTER*; 1; 2.**

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

Introduza: **2; *ENTER*.**

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

Temos agora a1, mas não c1 (obtido por simetria vertical). Do mesmmo modo temos a2, mas não c2, e a3 mas não c3.
Já b2 e b3 não têm estados simétricos. 

Assim, reduzimos consideravelmente a ramificação inicial, bem como os estados existentes no geral.

No entanto, tal como referido na ação 1, não podemos ignorar repetidos, 
já que podemos estar a eliminar alternativas importantes
num estado, apenas porque ocorrem em outro. 
Mas com este teste podemos ver a importância das simetrias.

O parâmetro de estados repetidos deve ficar nas procuras adversas em igonrar, e o de ordenação em 2.

Note que se quisermos jogar contra o computador, 
podemos utilizar a ação "exe" para que o computador jogue com o algoritmo atual.


\anchor jdg-a3
## Ação 3 - MiniMax

Vamos começar por ver o MiniMax neste formato, ignorando estados repetidos, 
com informação de debug completa, vendo todos os estados, e nível de profundidade 2,
e com P12(Ordenar)=0.
Introduza: **1; 3; 1; 1; 2; 4; 6; 1; 7; 2; 8; 1; 12; 0; *ENTER*; 6.**

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
 P1=1 P2=4 P3=1 P4=10 P5=0 P6=1 P7=2 P8=1 P9=100 P10=0
 P11=0 P12=0 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 2 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 0 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 45 | I3(Iterações): 9 | I4(Expansões): 1 | I5(Gerações): 9 |
I6(Lower Bound): 0
____________________________________________________________________
```

Podemos ver a árvore de procura, que há 9 estados gerados, embora apenas 3 sejam distintos
a menos das 3 simetrias. 

A heurística neste problema é a deteção de estado final, pelo que vemos 0 como valor de cada ramo final.

Vamos agora colocar P14(Ordenar): 2, e repetir a procura. Introduza: **1; 3; 12; 2; *ENTER*; 6.**

```entrada
 HT: reutilização 1,67 vezes g:0
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
 P1=1 P2=4 P3=1 P4=10 P5=0 P6=1 P7=2 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 2 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 37 | I3(Iterações): 3 | I4(Expansões): 1 | I5(Gerações): 9 |
I6(Lower Bound): 0
____________________________________________________________________
```

A procura foi realizada, existindo agora apenas 3 avaliações, já que apenas 3 estados novos foram gerados. 
Outros estados foram gerados, mas são iguais a menos de operações de simetria.

Na árvore de procura esses estados não desaparecem, mas a árvore é podada.
Se o estado já foi analisado nesse nível (ou com mais profundidade), reutiliza-se o valor em vez de expandir o estado.

Vamos continuar, mas reduzindo o nível de debug para passos, e aumentando o nível da procura para 3. 
Introduza: **3; 2; 2; 7; 3; *ENTER*; 6.**  

```entrada
 HT: reutilização 1,50 vezes --+--#= g:2 2|15|5 0
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
 P1=1 P2=2 P3=1 P4=10 P5=0 P6=1 P7=3 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): passos | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 3 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . o 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 38 | I3(Iterações): 32 | I4(Expansões): 6 | I5(Gerações): 43 |
I6(Lower Bound): 0
____________________________________________________________________
```

Continuamos com avaliações todas com heurística nula, pelo que para o algoritmo é indiferente qualquer opção.
Vamos agora executar mais algumas jogadas, e ver a execução final com debug a 4. 

Introduza: **6; 6; 3; 2; 4; *ENTER*; 6.**

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
 P1=1 P2=4 P3=1 P4=10 P5=0 P6=1 P7=3 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 3 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x x o 1
2 . . x 2
3 . . o 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 109 | I3(Iterações): 19 | I4(Expansões): 6 | I5(Gerações): 25 |
I6(Lower Bound): 0
____________________________________________________________________
```

Podemos ver que a árvore de procura já interseta posições em que há vitória de O, sendo o valor de +infinito. 
O infinito é de omissão 1000. O X é o primeiro a jogar, e em SolucaoVazia() é indicado que o 
primeiro a jogar procura minimizar o jogo.
O valor dos estados em que O ganha é 998 e não 1000. 
Ao valor do infinito é subtraído o número de jogadas desde a jogada atual.
Esta ação tem o efeito de uma derrota de X que seja mais uma jogada, tenha valer 997. 
Como O pretende maximizar, prefere sempre as vitórias mais curtas, tal como o X, 
e ambos preferem as derrotas mais longas.

Notar ainda para a frase inicial: "HT: reutilização 0,35 vezes". 
Ao ser limpa a hashtable com o registo dos estados na procura anterior,
é verificado quantas vezes em média, um estado guardado foi reutilizado, 
poupando assim uma execução do algoritmo para esse estado.


\anchor jdg-a4
## Ação 4 - MiniMax com cortes Alfa/Beta

Vamos agora ver como se comporta a procura da ação anterior, se ativarmos os cortes alfa/beta.
Introduza: **1; 3; 1; 2; 2; 4; 6; 1; 7; 3; *ENTER*; 6.**

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
 P1=2 P2=4 P3=1 P4=10 P5=0 P6=1 P7=3 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 3 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 101 | I3(Iterações): 11 | I4(Expansões): 7 | I5(Gerações): 57 |
I6(Lower Bound): 0
____________________________________________________________________
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

Como resultado dos cortes, temos menos avaliações, mas podemos ter menos memorizações e que por sua vez pode aumentar
as avaliações. Se a ramificação é alta, valerá sempre a pena o alfa/beta, se a ramificação é baixa, pode ser compensador
não ter o alfa/beta de modo a que fiquem memorizados estado com o valor exato.

Vamos avaçar para o momento em que há estados finais visiveis.
Introduza: **6; 6; 6; 6; 6; 6; 6.**

```entrada
 HT: reutilização 0,36 vezes g:0
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
 P1=2 P2=4 P3=1 P4=10 P5=0 P6=1 P7=3 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 3 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x x o 1
2 . . x 2
3 x o o 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 47 | I3(Iterações): 9 | I4(Expansões): 4 | I5(Gerações): 9 |
I6(Lower Bound): 0
____________________________________________________________________
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
Após reiniciar, introduza: **1; 3; 1; 1; 7; 20; 12; 0; *ENTER*; 6.**

```entrada
 P1=1 P2=0 P3=1 P4=10 P5=0 P6=4 P7=20 P8=1 P9=100 P10=0
 P11=0 P12=0 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 20 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 0 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 134 | I3(Iterações): 113416 | I4(Expansões): 155758 | I5(Gerações): 318517 |
I6(Lower Bound): 0
____________________________________________________________________
```
Podemos ver que há 318517 estados gerados, um valor reduzido para os tempos atuais.
O resultado do jogo é um empate.

Vamos agora ver o efeito da ordenação. 
Após arrancar, introduza:  **1; 3; 1; 1; 7; 20; 12; 2; *ENTER*; 6.**

```entrada
 P1=1 P2=0 P3=1 P4=10 P5=0 P6=4 P7=20 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 20 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 15 | I3(Iterações): 826 | I4(Expansões): 624 | I5(Gerações): 2299 |
I6(Lower Bound): 0
____________________________________________________________________
```

O número de estados gerados é consideravelmente inferior, ficando em apenas 2299 estados.

Vamos agora procurar ver o impacto dos cortes alfa/beta, na versão sem ordenação.
Após arrancar, introduza:  **1; 3; 1; 2; 7; 20; 12; 0; *ENTER*; 6.**

```entrada
 P1=2 P2=0 P3=1 P4=10 P5=0 P6=4 P7=20 P8=1 P9=100 P10=0
 P11=0 P12=0 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 20 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 0 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 19 | I3(Iterações): 7848 | I4(Expansões): 11750 | I5(Gerações): 27362 |
I6(Lower Bound): 0
____________________________________________________________________
```
O número de estados gerados é de 27362, em vez de 318517 para o MiniMax sem cortes alfa/beta.
Podemos observar um grande ganho. Vamos agora ver qual o resultado do alfa/beta com ordenação.
Após arrancar, introduza:  **1; 3; 1; 2; 7; 20; 12; 2; *ENTER*; 6.**

```entrada
 P1=2 P2=0 P3=1 P4=10 P5=0 P6=4 P7=20 P8=1 P9=100 P10=0
 P11=0 P12=2 P13=0 P14=0
Jogo do Galo
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 20 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 x . . 1
2 . . . 2
3 . . . 3
  A B C
I1(Custo): 0 | I2(Tempo(ms)): 32 | I3(Iterações): 806 | I4(Expansões): 1212 | I5(Gerações): 3633 |
I6(Lower Bound): 0
____________________________________________________________________
```

Os estados gerados ficam em 3633, contra 2299 sem cortes alfa/beta. 
Não reduz, mas em termos de avaliações temos 806, enquanto sem cortes alfa/beta temos 826.

O número de estados gerados é até superior, relativamente sem cortes alfa/beta,
porque a reutilização das procuras é superior ao algoritmo sem cortes alfa/beta, 
em que todos os resultados são exatos. 
Conforme já referido, nos cortes alfa/beta alguns resultados são influenciados com o 
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

Temos também de ter o cuidado de desligar a utilização das hashtables, 
para observer sem perturbações o ganho da profundidade.

Introduza: 
- **1; 7; P1=1 P12=0 P7=20,7,5,3; -1; *ENTER*.**

Apagamos a configuração 1 dado que tinha o valor de omissão P7=0.

```entrada
...
Comando: P1=1 P12=0 P7=20,7,5,3

Parâmetros comuns:
 P1=1 P2=0 P3=1 P4=10 P5=0 P6=4 P8=1 P9=100 P10=0 P11=0
 P12=0 P13=0 P14=0
- Configurações geradas (total: 5) -
 P7=0 [1] --- atual
 P7=3 [2]
 P7=5 [3]
 P7=7 [4]
 P7=20 [5]
...
Comando: -1

Parâmetros comuns:
 P1=1 P2=0 P3=1 P4=10 P5=0 P6=4 P8=1 P9=100 P10=0 P11=0
 P12=0 P13=0 P14=0
- Configurações geradas (total: 4) -
 P7=3 [1] --- atual
 P7=5 [2]
 P7=7 [3]
 P7=20 [4]
 ...
```

Temos 4 configurações. Como a procura é adversa, é necessário duas configurações, ou seja, jogos entre configurações para avaliar.
Assim, em vez da tabela com desempenho individual, há jogos entre todas as configurações, e reportado apenas a tabela de torneio final.

Podemos ainda ver as soluções, que aqui equivale a observar os jogos. 
Como são 4 configurações, haverá grande quantidade de jogos, de todos contra todos e de ambas as cores. 
Por outro lado os jogos são muito rápidos. Assim, não vamos querer ver os jogos.
Se existissem vários tabuleiros iniciais, ou vários tamanhos, ou seja, instâncias de jogo, podiamos indicar as instâncias a serem utilizadas. 

Introduza: **8; 1; *ENTER*; 0.**

```entrada
Match 1 vs 2:
 Instância 1:  Empate
Match 1 vs 3:
 Instância 1:  Empate
Match 1 vs 4:
 Instância 1:  Empate
Match 2 vs 1:
 Instância 1:  Vitória Branca
Match 2 vs 3:
 Instância 1:  Empate
Match 2 vs 4:
 Instância 1:  Empate
Match 3 vs 1:
 Instância 1:  Vitória Branca
Match 3 vs 2:
 Instância 1:  Vitória Branca
Match 3 vs 4:
 Instância 1:  Empate
Match 4 vs 1:
 Instância 1:  Vitória Branca
Match 4 vs 2:
 Instância 1:  Vitória Branca
Match 4 vs 3:
 Instância 1:  Empate
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    |  0 |  0 |  0 | -3
 |----|----|----|----|
 2  1 |    |  0 |  0 | -1
 |----|----|----|----|
 3  1 |  1 |    |  0 |  2
 |----|----|----|----|
 4  1 |  1 |  0 |    |  2
 |----|----|----|----|
Tempos: 0,000s 0,006s 0,060s 0,344s
Parâmetros comuns:
 P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0 | P11(baralhar): 0
 P12(Ordenar): 0 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
- Configurações geradas (total: 4) -
 P7(Limite): 3 [1]
 P7(Limite): 5 [2]
 P7(Limite): 7 [3]
 P7(Limite): 20 [4]

Jogo do Galo
 P1(Algoritmo): MiniMax | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 0 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
  A B C
1 . . . 1
2 . . . 2
3 . . . 3
  A B C
____________________________________________________________________
```

Podemos ver os resultados dos jogos, seguido do torneio, em que as duas primeiras configurações com nível 20 e 7 
são igualmente boas.
Assim, é suficiente procura em profundidade 7 para obter a estratégia vencedora. 
As restantes configurações, à medida que se reduz o nível de profundidade, a qualidade baixa, como seria de esperar.

Notar na informação da linha com os tempos: "Tempos: 0,028s 0,001s 0,001s 0,005s"
Estes tempos são o tempo total de jogo de cada configuração, para todos os jogos. 
Profundidades maiores o tempo é superior.

Vamos ver o resultado deste mesmo torneio em ficheiro CSV. Introduza: **8; 1; resultadoGalo; 0.**

O ficheiro fica com duas tabelas, a primeira com o resultado dos jogos, duas linhas por cada jogo:

| Jogador | Adversário | Cor | Resultado |
|:---:|:---:|:---:|:---:|
| 0 | 1 | Brancas | 0 |
| 1 | 0 | Pretas | 0 |
| 0 | 2 | Brancas | 0 |
| 2 | 0 | Pretas | 0 |
| 0 | 3 | Brancas | 0 |
| 3 | 0 | Pretas | 0 |
| 1 | 0 | Brancas | 1 |
| 0 | 1 | Pretas | -1 |
| 1 | 2 | Brancas | 0 |
| 2 | 1 | Pretas | 0 |
| 1 | 3 | Brancas | 0 |
| 3 | 1 | Pretas | 0 |
| 2 | 0 | Brancas | 1 |
| 0 | 2 | Pretas | -1 |
| 2 | 1 | Brancas | 1 |
| 1 | 2 | Pretas | -1 |
| 2 | 3 | Brancas | 0 |
| 3 | 2 | Pretas | 0 |
| 3 | 0 | Brancas | 1 |
| 0 | 3 | Pretas | -1 |
| 3 | 1 | Brancas | 1 |
| 1 | 3 | Pretas | -1 |
| 3 | 2 | Brancas | 0 |
| 2 | 3 | Pretas | 0 |

Com esta tabela, pode-se fazer o relatório dinâmico com os resultados do torneio, colocando:
- linhas: Jogador
- colunas: Adversário
- valores: Resultado
- Filtro: Cor=Brancas

| Rótulos de Linha | 0 | 1 | 2 | 3 | Total Geral |
|:---:|:---:|:---:|:---:|:---:|
|   | 0 | 0 | 0 | 0 | 0 |
| 1 |   | 1 | 0 | 0 | 1 |
| 2 | 1 |   | 1 | 0 | 2 |
| 3 | 1 | 1 |   | 0 | 2 |
| Total Geral | 3 | 2 | 0 | 0 | 5 |

O filtro é necessário para que cada jogo conte uma só vez. Cada jogo está em duas linhas.
Existindo várias instâncias, haverá sempre duas linhas por cada confronto A vs B, com o somatório do resultado em todas as instâncias.

Podemos fazer outras tabelas, como o resultado dos jogos por cor:

| Rótulos de Linha (Jogador) | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|
| 0 | 0 | -3 | -3 |
| 1 | 1 | -2 | -1 |
| 2 | 2 | 0 | 2 |
| 3 | 2 | 0 | 2 |
| Total Geral | 5 | -5 | 0 |

Podemos ver que os jogadores mais fortes ganharam quando estavam de brancas, e o inverso também, os jogadores
mais fracos só perderam quando estavam de pretas. 
Em termos de jogadores, o jogador 2 e 3 têm os mesmos pontos, pelo que podem ser considerados de força idêntica.

Podemos confirmar que os jogos entre jogadores mais fortes ficaram empatados, ao filtrar a tabela anterior por jogador/adversário 2 ou 3:

| Rótulos de Linha | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|
| 2 | 0 | 0 | 0 |
| 3 | 0 | 0 | 0 |
| Total Geral | 0 | 0 | 0 |

Sem o filtro para o Adversário ser 2 ou 3, iriamos obter a pontuação dos jogadores mais fortes, em conjunto com 
os mais fracos, o que poderia medir a eficiência de um jogador a lidar com mais fracos. 
Para saber se um jogador é mais forte que outro, apenas os confrontos entre ambos devem ser utilizados, o chamado match.

A segunda tabela no ficheiro CSV tem as configurações de cada jogador.

| Jogador | P1(Algoritmo) | P2(Debug) | P3(Seed) | P4(Tempo) | P5(Iterações) | P6(Ver) | P7(Limite) | P8(Repetidos) | P9(pesoAStar) | P10(ruido) | P11(baralhar) | P12(Ordenar) | P13(PodaHeuristica) | P14(PodaCega) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 1 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 5 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 2 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 7 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 3 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 20 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |

Assim, mantemos a informação completa no ficheiro de resultados, mesmo em torneios, para que se detecte algum erro na configuração, 
e se possa saber exatamente como os resultados foram obtgidos.

Como seria de esperar, este ficheiro de resultados poderia ser obtido também em linha de comandos:

```entrada
PS ...\Teste> TProcuraAdversa 1 -R resultadoGalo -P P1=1 P12=0 P7=20,7,5,3
...
Opção: 1
...
Ficheiro resultadoGalo.csv gravado.
```

A linha de comandos continua a ser o modo preferencial quando a implementação está finalizada e se pretende testes empíricos.

Este é no entanto um jogo muito pequeno para explorar, pelo que a sua generalização para os Jogos Em Linha, 
permitirá explorar melhor as particularidades das procuras adversas.


