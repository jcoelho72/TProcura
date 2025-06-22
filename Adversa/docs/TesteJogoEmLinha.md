@page teste_jogo_em_linha Teste Jogo Em Linha

Execução de exemplo com base no problema do Jogo Em Linha, uma generalização do Jogo do Galo. 
Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 1 - Ver instâncias](#jel-a1)
- [Ação 2 - Heurística](#jel-a2)
- [Ação 3 - Torneio Profundidade](#jel-a3)
- [Ação 4 - Torneio Iterativo](#jel-a4)
- [Ação 5 - Torneio Ruido](#jel-a5)
- [Ação 6 - Torneio Poda](#jel-a6)


```entrada
Teste TProcurasAdversas
Problema:
  1 - Jogo do Galo
  2 - Jogo Em Linha
Opção: 2
```

Este jogo tem várias instâncias, com as dimensões e tamanho da linha para ganhar. Existe ainda 
a variante em que as peças caem pela ação da gravidade.


\anchor jel-a1
## Ação 1 - Ver instâncias

Vamos entrar no Jogo Em Linha, introduza: **2.**

```entrada
Jogo Em Linha
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0 | P14(Ordenar): 2 | P15(PodaHeuristica): 0 | P16(PodaCega): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
3 em Linha (3x3)
   A B C
 1 . . . 1
 2 . . . 2
 3 . . . 3
   A B C
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

O primeiro jogo é o Jogo do Galo, em que se tem de fazer 3 em linha, num tabuleiro de 3x3. 
Vamos ver outras instâncias. 

Introduza: 
- **1; 2.** jogo 4 em Linha (4x4)
- **1; 3.** jogo 4 em Linha (6x4)
- **1; 4.** jogo 4 em Linha (7x6) gravidade
- **1; 5.** jogo 4 em Linha (14x6) gravidade
- **1; 6.** jogo 5 em Linha (8x8)
- **1; 7.** jogo 5 em Linha (12x8)
- **1; 8.** jogo 5 em Linha (9x9)
- **1; 9.** jogo 6 em Linha (11x9)
- **1; 10.** jogo 6 em Linha (12x12)


```entrada
4 em Linha (4x4)
   A B C D
 1 . . . . 1
 2 . . . . 2
 3 . . . . 3
 4 . . . . 4
   A B C D
_______________________________________________________________________________
4 em Linha (6x4)
   A B C D E F
 1 . . . . . . 1
 2 . . . . . . 2
 3 . . . . . . 3
 4 . . . . . . 4
   A B C D E F
_______________________________________________________________________________
4 em Linha (7x6) gravidade
   A B C D E F G
 1 . . . . . . . 1
 2 . . . . . . . 2
 3 . . . . . . . 3
 4 . . . . . . . 4
 5 . . . . . . . 5
 6 . . . . . . . 6
   A B C D E F G
_______________________________________________________________________________
4 em Linha (14x6) gravidade
   A B C D E F G H I J K L M N
 1 . . . . . . . . . . . . . . 1
 2 . . . . . . . . . . . . . . 2
 3 . . . . . . . . . . . . . . 3
 4 . . . . . . . . . . . . . . 4
 5 . . . . . . . . . . . . . . 5
 6 . . . . . . . . . . . . . . 6
   A B C D E F G H I J K L M N
_______________________________________________________________________________
5 em Linha (8x8)
   A B C D E F G H
 1 . . . . . . . . 1
 2 . . . . . . . . 2
 3 . . . . . . . . 3
 4 . . . . . . . . 4
 5 . . . . . . . . 5
 6 . . . . . . . . 6
 7 . . . . . . . . 7
 8 . . . . . . . . 8
   A B C D E F G H
_______________________________________________________________________________
5 em Linha (12x8)
   A B C D E F G H I J K L
 1 . . . . . . . . . . . . 1
 2 . . . . . . . . . . . . 2
 3 . . . . . . . . . . . . 3
 4 . . . . . . . . . . . . 4
 5 . . . . . . . . . . . . 5
 6 . . . . . . . . . . . . 6
 7 . . . . . . . . . . . . 7
 8 . . . . . . . . . . . . 8
   A B C D E F G H I J K L
_______________________________________________________________________________
5 em Linha (9x9)
   A B C D E F G H I
 1 . . . . . . . . . 1
 2 . . . . . . . . . 2
 3 . . . . . . . . . 3
 4 . . . . . . . . . 4
 5 . . . . . . . . . 5
 6 . . . . . . . . . 6
 7 . . . . . . . . . 7
 8 . . . . . . . . . 8
 9 . . . . . . . . . 9
   A B C D E F G H I
_______________________________________________________________________________
6 em Linha (11x9)
   A B C D E F G H I J K
 1 . . . . . . . . . . . 1
 2 . . . . . . . . . . . 2
 3 . . . . . . . . . . . 3
 4 . . . . . . . . . . . 4
 5 . . . . . . . . . . . 5
 6 . . . . . . . . . . . 6
 7 . . . . . . . . . . . 7
 8 . . . . . . . . . . . 8
 9 . . . . . . . . . . . 9
   A B C D E F G H I J K
_______________________________________________________________________________
6 em Linha (12x12)
   A B C D E F G H I J K L
 1 . . . . . . . . . . . . 1
 2 . . . . . . . . . . . . 2
 3 . . . . . . . . . . . . 3
 4 . . . . . . . . . . . . 4
 5 . . . . . . . . . . . . 5
 6 . . . . . . . . . . . . 6
 7 . . . . . . . . . . . . 7
 8 . . . . . . . . . . . . 8
 9 . . . . . . . . . . . . 9
10 . . . . . . . . . . . . 10
11 . . . . . . . . . . . . 11
12 . . . . . . . . . . . . 12
   A B C D E F G H I J K L
_______________________________________________________________________________

```

Temos diferentes tabuleiros, resultando em ramificações distintas. 
A variante da gravidade, reduz consideravelmente a ramificação.


\anchor jel-a2
## Ação 2 - Heurística

Vamos começar por verificar se a heurística implementada, tem atenção a aspetos mínimos, como bloquear ameaças de vitória a uma jogada.

Para tal vamos fazer um jogo com profundidade 1, para que a heurística seja o fator predominante.

Introduza: 
- **1; 2; 4; 9; 2; *ENTER*; 5.** executa um lance, fica com 3 ameaças a 3 jogadas
- **5.** responde anulando uma das ameaças, e faz 2 ameaças a 3 jogadas
- **5.** uma das ameaças passa a 2 jogadas
- **5; 5; 5; ....** termine o jogo, verificando que todas as ameaças são resondidas

```entrada
4 em Linha (4x4)
   A B C D
 1 . . . . 1
 2 . . . . 2
 3 . . . . 3
 4 x . . . 4
   A B C D
4 em Linha (4x4)
   A B C D
 1 o . . . 1
 2 . . . . 2
 3 . . . . 3
 4 x . . . 4
   A B C D
4 em Linha (4x4)
   A B C D
 1 o . . . 1
 2 . . . . 2
 3 . x . . 3
 4 x . . . 4
   A B C D
```

Podemos fazer o mesmo para um tabuleiro maior. Introduza: **1; 10; 5.**
Execute também um jogo, verificando que as ameaças vão sendo respondidas: **5; 5; ...** 

Se conseguir chegar ao final, verifica que há empate:

```entrada
6 em Linha (12x12)
   A B C D E F G H I J K L
 1 o o o o x o o o o x x o 1
 2 o x x x o o o x x o x x 2
 3 x x x o x x x x o o o o 3
 4 o o o x o o o o x x o x 4
 5 x o x x o x x x o o x x 5
 6 x x o o x o o o x x o o 6
 7 x o x o o x x x o o o o 7
 8 o x o x x x o o o x x o 8
 9 o x o o x x x o x o x x 9
10 x x x x o o x x x x o o 10
11 x o o x o o x o o o x x 11
12 x o x o x o x x x x o o 12
   A B C D E F G H I J K L
```

Não temos portanto motivo para não considerar a heurística válida. 
Deixamos de forma a variante da gravidade, já que esta heurística foi feita com base na variante regular.

\anchor jel-a3
## Ação 3 - Torneio Profundidade

Pretendemos agora verificar que em torneio, profundidade maior resulta em força de jogo superior. Assim, 
como temos muitos jogos, vamos fazer apenas duas profundidades, nível 1 e 2, mas com várias opções.

Vamos primeiramente construir as configurações em teste. Introduza:
- **4; 1; 2; 9; 2; 14; 0; *ENTER*; 6; *ENTER*. -- MiniMax alfa/beta, sem ordenação, nível 2 
- **4; 9; 3; *ENTER*; 6; *ENTER*. -- MiniMax alfa/beta, sem ordenação, nivel 3
- **4; 9; 2; 14; 1; *ENTER*; 6; *ENTER*. -- MiniMax alfa/beta, com ordenação, nível 2 
- **4; 9; 3; *ENTER*; 6; *ENTER*. -- MiniMax alfa/beta, com ordenação, nivel 3
- **4; 1; 1; 9; 2; 14; 0; *ENTER*; 6; *ENTER*. -- MiniMax, sem ordenação, nível 2 
- **4; 9; 3; *ENTER*; 6; *ENTER*. -- MiniMax, sem ordenação, nível 2 

O resultado das configurações deverá ser este:

```entrada
Parametros comuns a 6 configurações:
P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P10:1 P11:100 P12:0
P13:0 P15:0 P16:0
--- Configuração 1
P1:2 P9:2 P14:0
--- Configuração 2
P1:2 P9:3 P14:0
--- Configuração 3
P1:2 P9:2 P14:1
--- Configuração 4
P1:2 P9:3 P14:1
--- Configuração 5
P1:1 P9:2 P14:0
--- Configuração 6 --- atual
P1:1 P9:3 P14:0
```

Vamos executar o torneio, para todas as instâncias. Introduza: **7; 0; 10; 1.**

```entrada
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|
 1    | -2 |  2 | -3 |  2 | -2 |-13
 |----|----|----|----|----|----|
 2  2 |    |  2 |  0 |  2 |  2 | 14
 |----|----|----|----|----|----|
 3  2 | -2 |    | -3 |  2 | -2 |-13
 |----|----|----|----|----|----|
 4  2 | -2 |  2 |    |  2 | -2 | 11
 |----|----|----|----|----|----|
 5  2 | -2 |  2 | -3 |    | -2 |-13
 |----|----|----|----|----|----|
 6  2 |  2 |  2 |  0 |  2 |    | 14
 |----|----|----|----|----|----|
Tempos: 0,733s 15,511s 0,706s 8,993s 0,730s 57,606s
Parametros comuns a 6 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 10
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0 | P10(Repetidos): ignorar
P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0 | P15(PodaHeuristica): 0
P16(PodaCega): 0
--- Configuração 1
P1(Algoritmo): MiniMax alfa/beta | P9(Limite): 2 | P14(Ordenar): 0
--- Configuração 2
P1(Algoritmo): MiniMax alfa/beta | P9(Limite): 3 | P14(Ordenar): 0
--- Configuração 3
P1(Algoritmo): MiniMax alfa/beta | P9(Limite): 2 | P14(Ordenar): 1
--- Configuração 4
P1(Algoritmo): MiniMax alfa/beta | P9(Limite): 3 | P14(Ordenar): 1
--- Configuração 5
P1(Algoritmo): MiniMax | P9(Limite): 2 | P14(Ordenar): 0
--- Configuração 6
P1(Algoritmo): MiniMax | P9(Limite): 3 | P14(Ordenar): 0
```
As configurações de profundidade 3 ganharam as de profundidade 2, sendo clara a vitória, significa que 
a heurística faz sentido, e utilizada em mais profundidade adiciona informação. 

Entre elas deveriam ser iguais, mas houve uma diferença na configuração 4.

Em termos de tempos, podemos ver o MiniMax sem cortes com mais tempo total, 57 segundos, 
seguido do MiniMax com cortes alfa/beta mas sem ordenação, com 15 segundos, e com o melhor tempo
o MiniMax com cortes alfa/beta e com ordenação, levando 9 segundos.

A ordenação leva a jogadas e resultados distintos, mas terá sido um acaso o facto de ter perdido
alguns pontos. Um volume de jogos permitiria concluir que não há diferença.

A utilização de cortes alfa/beta, bem como a ordenação de estados é portanto crítica, motivo pelo qual
se justifica o método iterativo.

\anchor jel-a4
## Ação 4 - Torneio Iterativo

Na ação anterior, após confirmação que quanto maior a profundidade melhor, podemos comparar
procuras com a mesma profundidade, mas diferentes opções. Sabemos que o corte alfa/beta é benéfico neste jogos,
bem como a ordenação dos sucessores, porque reduz o tempo, mantendo a árvore de procura com a mesma qualidade.

Em termos práticos, o tempo é um fator restritivo, e ideal para poder comparar algoritmos.
Tendo tempo igual, pretende-se saber qual o mais forte. Os métodos da ação 3 não permitem a paragem por tempo,
tem de se definir a profundidade máxima.

O método iterativo faz procuras com a profundidade iterativamente a ser aumentada.
Esta estratégia tem a vantagem de ter sempre um movemento pronto a jogar quando o tempo acaba.
Por outro lado, utiliza o tempo existente, se der para explorar mais um nível, esse é explorado.

Vamos nesta ação, com o torneio iterativo, comparar métodos em que se dá a todos o mesmo tempo para jogar.

Temos mais uma opção na ordennação, que é o valor 2 (omissão). Este valor, para além de ordenar os sucessores,
guarda em memória cada estado, e resultado de análises anteriores. Quando o estado ocorre novamnete, se estiver 
em memória, o seu valor é utilizado em vez de ser executada a heurítica ou uma procura e determinada profundidade.
Para tal é guardada alguma informação sobre o estado de modo a sabermos se podemos utilizar o valor assim que exista
possibilidade de reutilização. Esta opção tem naturalmente mais impacto na procura iterativa, em que os estados
iniciais são re-expandidos, mas pode ter influencia mesmo sem ser na procura iterativa, 
caso o mesmo estado apareça por ordens distintas de movimentos.

Vamos utilizar 1 segundo por lance.

Introduza: 
- **4; 1; 2; 9; 0; 5; 1; 14; 0; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, sem ordenação, 1s
- **4; 14; 1; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, ordenação 1, 1s
- **4; 14; 2; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, ordenação 2, 1s
- **4; 1; 1; 14; 0; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax, sem ordenação, 1s
- **4; 14; 2; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax, ordenação 2, 1s

O resultado deverá ser o seguinte:

```entrada
Parametros comuns a 5 configurações:
P2:0 P3:4 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:1 P11:100
P12:0 P13:0 P15:0 P16:0
--- Configuração 1
P1:2 P14:0
--- Configuração 2
P1:2 P14:1
--- Configuração 3
P1:2 P14:2
--- Configuração 4
P1:1 P14:0
--- Configuração 5 --- atual
P1:1 P14:2
```
Vamos agora executar o torneio, mas apenas numa instância pequena, de modo a que os jogos sejam mais rápidos.
Este teste ao utilizar 1 segundo por lance, significa que um jogo com 60 lances, leve 1 minuto.
Introduza: **7; 0; 3; 3.**

```entrada
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|
 1    |  0 |  0 |  1 |  1 |  1
 |----|----|----|----|----|
 2  0 |    |  1 |  0 |  0 |  1
 |----|----|----|----|----|
 3  1 |  0 |    |  0 |  0 |  0
 |----|----|----|----|----|
 4  0 |  0 |  0 |    |  0 | -1
 |----|----|----|----|----|
 5  0 |  0 |  0 |  0 |    | -1
 |----|----|----|----|----|
Tempos: 55,079s 45,969s 46,600s 63,583s 52,842s
Parametros comuns a 5 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 1
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0 | P9(Limite): 0
P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
P15(PodaHeuristica): 0 | P16(PodaCega): 0
--- Configuração 1
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 0
--- Configuração 2
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 1
--- Configuração 3
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 2
--- Configuração 4
P1(Algoritmo): MiniMax | P14(Ordenar): 0
--- Configuração 5
P1(Algoritmo): MiniMax | P14(Ordenar): 2
```
Houve um ligeiro resutlado positivo para as duas primeiras configurações. 
Não se pode concluir que neste jogo, um método seja muito melhor que outro.

Vamos agora utilizar uma instância maior, mas com a gravidade, em que os sucessores são mais limitados.
Introduza: **7; 0; 5; 5.**

```entrada
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|
 1    |  1 |  1 |  1 | -1 |  4
 |----|----|----|----|----|
 2 -1 |    | -1 |  1 |  1 |  2
 |----|----|----|----|----|
 3  1 | -1 |    |  1 |  1 |  2
 |----|----|----|----|----|
 4 -1 | -1 | -1 |    |  1 | -4
 |----|----|----|----|----|
 5 -1 | -1 |  1 | -1 |    | -4
 |----|----|----|----|----|
Tempos: 159,921s 154,533s 119,257s 156,182s 155,026s
Parametros comuns a 5 configurações:
P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1 | P5(Tempo): 1
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0 | P9(Limite): 0
P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 0
P15(PodaHeuristica): 0 | P16(PodaCega): 0
--- Configuração 1
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 0
--- Configuração 2
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 1
--- Configuração 3
P1(Algoritmo): MiniMax alfa/beta | P14(Ordenar): 2
--- Configuração 4
P1(Algoritmo): MiniMax | P14(Ordenar): 0
--- Configuração 5
P1(Algoritmo): MiniMax | P14(Ordenar): 2
```

Este jogo aparentemente não admite empates, sendo clara a vantagem dos cortes alfa/beta sobre o MiniMax puro.
Já a componente de ordenação, não é visivel melhoria, sendo até melhor a versão sem ordenação, mas tal pode 
ser devido a uma questão de sorte na ordenação dos lances.

Já tinhamos dito que seria sorte numa situação anterior, agora novamente sorte.

É tempo de tirar a limpo esta situação. Vamos fazer um último torneio com as duas melhores configurações,
neste problema, mas com a ordem de sucessores baralhada de início.
Vamos fazer vários jogos, com sementes distintas, e assim confirmar se não ordenar é uma vantagem neste jogo.

Introduza:
- **4; 1; 2; 9; 0; 5; 1; 14; 2; 13; 1; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, ordenação 2, 1s
- **4; 14; 0; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, sem ordenação, 1s
- **4; 14; 2; 4; 2; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, ordenação 2, 1s, seed 2
- **4; 14; 0; *ENTER*; 6; *ENTER*.** -- Iterativo, MiniMax alfa/beta, sem ordenação, 1s, seed 2

O resultado deverá ser:

```entrada
Parametros comuns a 4 configurações:
P1:2 P2:0 P3:4 P5:1 P6:0 P7:0 P8:0 P9:0 P10:1 P11:100
P12:0 P13:1 P15:0 P16:0
--- Configuração 1
P4:1 P14:2
--- Configuração 2
P4:1 P14:0
--- Configuração 3
P4:2 P14:2
--- Configuração 4 --- atual
P4:2 P14:0
```

Vamos agora executar novamente, utilizando a instância 4, ligeiramente mais reduzida que a 5, mas com características idênticas.
Introduza: **7; 0; 4; 4.**

```entrada
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    | -1 |  1 | -1 | -1
 |----|----|----|----|
 2 -1 |    | -1 |  1 |  0
 |----|----|----|----|
 3  0 |  1 |    | -1 |  1
 |----|----|----|----|
 4  1 | -1 | -1 |    |  0
 |----|----|----|----|
Tempos: 72,835s 77,357s 67,841s 77,481s
Parametros comuns a 4 configurações:
P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Ver): 4 | P5(Tempo): 1
P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0 | P9(Limite): 0
P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0 | P13(baralhar): 1
P15(PodaHeuristica): 0 | P16(PodaCega): 0
--- Configuração 1
P4(Seed): 1 | P14(Ordenar): 2
--- Configuração 2
P4(Seed): 1 | P14(Ordenar): 0
--- Configuração 3
P4(Seed): 2 | P14(Ordenar): 2
--- Configuração 4
P4(Seed): 2 | P14(Ordenar): 0
```

Pelos resultados deste torneio, podemos ver que ordenar é melhor com um valor de seed, e é o pior com outro valor de seed. 
Portanto, não há uma diferença demasiado forte.

Pudemos observar um empate, pelo que, pelo menos esta dimensão de tabuleiros, aceita empates na prática. 
Por outro lado, há vitórias de brancas e pretas, pelo que o jogo está equilibrado.


\anchor jel-a5
## Ação 5 - Torneio Ruido

... (estudar o efeito do ruído)

\anchor jel-a6
## Ação 6 - Torneio Poda

... (estudar o efeito da poda)

