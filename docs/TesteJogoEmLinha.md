@page teste_jogo_em_linha Teste Jogo Em Linha

Execução de exemplo com base no problema do Jogo Em Linha, uma generalização do Jogo do Galo.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraAdversa, e execute.
No Linux na pasta `.../TProcura/Adversa/Teste$` execute `make` seguido de `./bin/Release/TProcuraAdversa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#jel-a1)
- [Ação 2 - Heurística](#jel-a2)
- [Ação 3 - Torneio Profundidade](#jel-a3)
- [Ação 4 - Torneio Iterativo](#jel-a4)
- [Ação 5 - Torneio Ruido](#jel-a5)
- [Ação 6 - Torneio Poda](#jel-a6)


```entrada
Teste TProcuraAdversa
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
 P1(Algoritmo): MiniMax alfa/beta | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 4 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0 | P12(Ordenar): 2 | P13(PodaHeuristica): 0 | P14(PodaCega): 0
3 em Linha (3x3)
   A B C
 1 . . . 1
 2 . . . 2
 3 . . . 3
   A B C
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
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

Vamos começar por verificar se a heurística implementada, 
tem atenção a aspetos mínimos, como bloquear ameaças de vitória a uma jogada.

Para tal vamos fazer um jogo com profundidade 1, para que a heurística seja o fator predominante.

Introduza: 
- **1; 2; 3; 7; 2; *ENTER*; 6.** executa um lance, fica com 3 ameaças a 3 jogadas
- **6.** responde anulando uma das ameaças, e faz 2 ameaças a 3 jogadas
- **6.** uma das ameaças passa a 2 jogadas
- **6; 6; 6; ....** termine o jogo, verificando que todas as ameaças são resondidas

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

Este teste é importante para despistar algum erro na heurística. 

Podemos fazer o mesmo para um tabuleiro maior. Introduza: **1; 10; 6.**
O lance inicial vai para o meio do tabuleiro, onde há mais ameaças em simultâneo, ou seja, vai para a jogada que maximiza o valor da heurística.
Execute também um jogo, verificando que as ameaças vão sendo respondidas: **6; 6; ...** 

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

Nos testes empíricos vamos utilizar a linha de comando, por ser mais simples a identificação do teste a realizar.

Pretendemos verificar num torneio, que a profundidade maior resulta em força de jogo superior. Assim, 
como temos muitos jogos, vamos fazer apenas duas profundidades, nível 1 e 2, mas com várias opções.

Pretendemos também comparar: 
- MiniMax alfa/beta vs MiniMax
- Com / sem ordenação

Vamos utilizar todas as instâncias, já que a heurística é igual.

```entrada
PS ...\Teste> TProcuraAdversa 1:10 -R resultadoEmLinha -P P1=1,2 x P12=0,1 x P7=2,3
...
Opção: 2
...
Ficheiro resultadoEmLinha.csv gravado.
```

Podemos com os resultados fazer um relatório dinâmico em que soma todos os resultados e separa por cada 
indicador em estudo:

| Rótulos de Linha | Ordenar 0 | Ordenar 1 | Total Geral |
|:---:|:---:|:---:|:---:|
| Nível 2 | -36 | -36 | -72 |
| 1:MiniMax | -18 | -18 | -36 |
| 2:MiniMax alfa/beta | -18 | -18 | -36 |
| Nível 3 | 40 | 32 | 72 |
| 1:MiniMax | 20 | 16 | 36 |
| 2:MiniMax alfa/beta | 20 | 16 | 36 |
| Total Geral | 4 | -4 | 0 |

A grande diferença foi a profundidade, em que o valor 3 (corresponde ao nível 2), foi claramente superior ao valor 2 (correspondente ao nível 1).
Significa que a heurística faz sentido, já que adicionando mais profundidade aumenta a força de jogo.
A diferença entre cortes alfa/beta e sem cortes, não é observável aqui. O nível de profundidade é curto, pelo que é normal.
A ordenação aparenta até a dar um impacto ligeiramente negativo.

A tabela de torneio é a seguinte:

| Rótulos de Linha | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 2 | 2 | 2 | -2 | -2 | -3 | -3 | -4 |
| 1 | 2 | 2 | 2 | -2 | -2 | -3 | -3 | -4 |
| 2 | 2 | 2 | 2 | -2 | -2 | -3 | -3 | -4 |
| 3 | 2 | 2 | 2 | -2 | -2 | -3 | -3 | -4 |
| 4 | 2 | 2 | 2 | 2 | 2 | 0 | 0 | 10 |
| 5 | 2 | 2 | 2 | 2 | 2 | 0 | 0 | 10 |
| 6 | 2 | 2 | 2 | 2 | -2 | -2 | 0 | 4 |
| 7 | 2 | 2 | 2 | 2 | -2 | -2 | 0 | 4 |
| Total Geral | 14 | 14 | 14 | 14 | -10 | -10 | -12 | -12 | 12 |

As configurações de cada jogador:

| Jogador | P1(Algoritmo) | P2(Debug) | P3(Seed) | P4(Tempo) | P5(Iterações) | P6(Ver) | P7(Limite) | P8(Repetidos) | P9(pesoAStar) | P10(ruido) | P11(baralhar) | P12(Ordenar) | P13(PodaHeuristica) | P14(PodaCega) |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 2 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 1 | 2:MiniMax alfa/beta | 0:nada | 1 | 10 | 0 | 4 | 2 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 2 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 2 | 1:ignorar | 100 | 0 | 0 | 1 | 0 | 0 |
| 3 | 2:MiniMax alfa/beta | 0:nada | 1 | 10 | 0 | 4 | 2 | 1:ignorar | 100 | 0 | 0 | 1 | 0 | 0 |
| 4 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 5 | 2:MiniMax alfa/beta | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 0 | 0 | 0 |
| 6 | 1:MiniMax | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 1 | 0 | 0 |
| 7 | 2:MiniMax alfa/beta | 0:nada | 1 | 10 | 0 | 4 | 3 | 1:ignorar | 100 | 0 | 0 | 1 | 0 | 0 |

Podemos ver uma tabela de resultados de cada jogador, com os parâmetros que variam:

| P1(Algoritmo) | P7(Limite) | P12(Ordenar) | Rótulos de Linha | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1:MiniMax | 2 | 0 | 0 | -4 | -14 | -18 |
| 2:MiniMax alfa/beta | 2 | 0 | 1 | -4 | -14 | -18 |
| 1:MiniMax | 2 | 1 | 2 | -4 | -14 | -18 |
| 2:MiniMax alfa/beta | 2 | 1 | 3 | -4 | -14 | -18 |
| 1:MiniMax | 3 | 0 | 4 | 10 | 10 | 20 |
| 2:MiniMax alfa/beta | 3 | 0 | 5 | 10 | 10 | 20 |
| 1:MiniMax | 3 | 1 | 6 | 4 | 12 | 16 |
| 2:MiniMax alfa/beta | 3 | 1 | 7 | 4 | 12 | 16 |
| Total Geral | | | 12 | -12 | 0 |


O jogador 4 e 5, com o nível máximo no teste e sem ordenar, aparenta ser superior. 
Como a profundidade é fixa, é natural que os cortes alfa/beta e ordenação não alterem o resultado de forma significativa.
Reduzem o tempo, mas não alteram o resultado.

\anchor jel-a4
## Ação 4 - Torneio Iterativo

Na ação anterior, após confirmação que quanto maior a profundidade melhor, podemos comparar
procuras com a mesma profundidade, mas diferentes opções. 

Sabemos que o corte alfa/beta é benéfico neste jogos,
bem como a ordenação dos sucessores, porque reduz o tempo, mantendo a árvore de procura com a mesma qualidade.

Em termos práticos, o tempo é um fator restritivo, e ideal para poder comparar algoritmos.
Tendo tempo igual, pretende-se saber qual o mais forte. Os métodos da ação 3 não têm paragem por tempo,
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
caso o mesmo estado apareça várias vezes por ordens distintas de movimentos.

Vamos utilizar 1 segundo por lance. O valor de omissão de P7 é 0, mas vamos colocar P7=0 para realçar que estamos na procura iterativa.
Utilizamos apenas a instãncia 3 para que o torneio não leve muito tempo, já que cada lance levará 1 segundo.

```entrada
PS ...\Teste> TProcuraAdversa 3 -R resultadoIterativo -P P4=1 P7=0 P1=1,2 x P12=0:2
...
Opção: 2
...
Ficheiro resultadoIterativo.csv gravado.
```

| P1(Algoritmo) | P12(Ordenar) | Rótulos de Linha | 0 | 1 | 2 | 3 | 4 | 5 | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1:MiniMax | 0 |   |0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 2:MiniMax alfa/beta | 0 | 1 |  | 1 | 1 | 0 | 1 | 0 | 3 |
| 1:MiniMax | 1 | 2 | 0 | 0 |  | 0 | 0 | 1 | 1 |
| 2:MiniMax alfa/beta | 1 | 3 | 0 | 0 | 0 | | 0 | 1 | 1 |
| 1:MiniMax | 2 | 4 | 0 | 0 | 0 | 0 | | 0 | 0 |
| 2:MiniMax alfa/beta | 2 | 5 | 0 | 0 | 0 | 0 | 0 | | 0 |
| Total Geral | | 1 | 0 | 1 | 0 | 1 | 2 | 5 |

Estes resultados apontam para vantagem do MiniMax com cortes alfa/beta, sem ordenação.

Os resultados por jogador:

| P1(Algoritmo) | P12(Ordenar) | Rótulos de Linha | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 1:MiniMax | 0 | 0 | 0 | -1 | -1 |
| 2:MiniMax alfa/beta | 0 | 1 | 3 | 0 | 3 |
| 1:MiniMax | 1 | 2 | 1 | -1 | 0 |
| 2:MiniMax alfa/beta | 1 | 3 | 1 | 0 | 1 |
| 1:MiniMax | 2 | 4 | 0 | -1 | -1 |
| 2:MiniMax alfa/beta | 2 | 5 | 0 | -2 | -2 |
| Total Geral | 5 | -5 | 0 |

Esta tabela confirma a tabela anterior, e permite observar que nesta instância as brancas ganham com maior facilidade.

Vamos agora utilizar uma instância maior, mas com a gravidade, a instância 5, em que os sucessores são mais limitados.

```entrada
PS ...\Teste> TProcuraAdversa 5 -R resultadoIterativo5 -P P4=1 P7=0 P1=1,2 x P12=0:2
...
Opção: 2
...
Ficheiro resultadoIterativo5.csv gravado.
```

Resultados por jogador:

| P1(Algoritmo) | P12(Ordenar) | Rótulos de Linha | Brancas | Pretas | Total Geral |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 1:MiniMax | 0 | 0 | -1 | 3 | 2 |
| 2:MiniMax alfa/beta | 0 | 1 | -3 | 1 | -2 |
| 1:MiniMax | 1 | 2 | -1 | -1 | -2 |
| 2:MiniMax alfa/beta | 1 | 3 | -3 | 3 | 0 |
| 1:MiniMax | 2 | 4 | -1 | 5 | 4 |
| 2:MiniMax alfa/beta | 2 | 5 | -3 | 1 | -2 |
| Total Geral | | -12 | 12 | 0 |

Podemos observar que o MiniMax com ordenação 2 é o algoritmo mais forte neste jogo.
O jogo aparenta não permitir empates, e as pretas têm mais facilidade em ganhar.

O MiniMax ao utilizar a ordenação 2, memoriza mais estados e pode assim ter maior vantagem que o ganho pelos cortes do alfa/beta.
Ao utilizar o alfa/beta, a informação memorizada tem de ter informação se esteve um corte alfa ou beta ativo, para utilizar devidamente o valor registado, como um upper bound ou lower bound.
Assim, o ganho da memorização perde-se.

Estes resultados poderiam ser mais evidentes com mais tempo por jogada, o que permitiria maiores profundidades e maiores ganhos em algumas configurações.
Por outro lado, para maior precisão, tem de se utilizar aleatoriedade e ruído, que é o que iremos fazer na próxima ação.

\anchor jel-a5
## Ação 5 - Torneio Ruido

Um jogo isolado pode não significar muito. Vamos ver entre duas configurações, se uma é de facto melhor que a outra,
utilizando vários jogos, com diferentes sementes aleatórias.

Pretendemos saber entre o MiniMax com e sem cortes alfa/beta, qual é o melhor, se ordenarmos com 2 (guarda estados analisados), 
e utilizarmos a procura iterativa.

No entanto, se executarmos um teste a variar apenas a semente, 
como a semente aleatória apenas tem efeito se forem gerados números aleatórios,
iriamos apenas gerar jogadores iguais.

Assim, vamos primeiramente estudar o uso do ruído na heurística, com o efeito de variar a jogada.

O ruído é especificado no parâmetro 10, e o seu valor pode ser positivo ou negativo. 
Se for negativo pode oscilar positiva ou negativamente, se positivo será sempre um ruído positivo.
Vamos variar entre valores negativos, já que pretendemos que o ruído seja simétrico. 
Esperamos que ruído baixo, não altere a força de jogo, mas ruído alto degrade consideravelmente a força de jogo.

```entrada
PS ...\Teste> TProcuraAdversa 5 -R resultadoRuido -P P4=1 P7=0 P12=0 P1=1 P10=0,-1,-2,-5,-10 
...
Opção: 2
...
Ficheiro resultadoRuido.csv gravado.
```

... (estudar o efeito do ruído)



\anchor jel-a6
## Ação 6 - Torneio Poda

... (estudar o efeito da poda)

