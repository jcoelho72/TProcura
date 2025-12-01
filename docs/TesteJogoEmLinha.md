@page teste_jogo_em_linha Teste Jogo Em Linha

Execução de exemplo com base no problema do Jogo Em Linha, uma generalização do Jogo do Galo.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraAdversa, e execute.
No Linux na pasta `.../TProcura/Adversa/Teste$` execute `make` seguido de `./bin/Release/TProcuraAdversa`

## Sumário

- [Ação 1 - Ver instâncias](#jel-a1)
- [Ação 2 - Heurística](#jel-a2)
- [Ação 3 - MiniMax com cortes Alfa/Beta](#jel-a3)
- [Ação 4 - Torneio Profundidade](#jel-a4)
- [Ação 5 - Torneio Iterativo](#jel-a5)
- [Ação 6 - Torneio Heurística](#jel-a6)
- [Ação 7 - Torneio Ruido](#jel-a7)
- [Ação 8 - Torneio Poda](#jel-a8)
- [Ação 9 - Torneio Niveis](#jel-a9)


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

Vamos entrar no Jogo Em Linha, insira: **2.**

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

Insira: 
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
que tem em atenção aspetos mínimos, como bloquear ameaças de vitória a uma jogada.

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
## Ação 3 - MiniMax com cortes Alfa/Beta

Vamos fazer um jogo com o MiniMax com cortes alfa/beta no 4 em linha, de modo a
observar o MiniMax com cortes Alfa/Beta num jogo com heurística.

Insira: **2; 1; 2; 3; 2; 3; 7; 3; *ENTER*; 6.**

\htmlonly
<pre>
═╤═ ►  Execução iniciada ═══
 ├□═╤═ 💰 g:0  ═══ α=-10000 β=10000 ═══
 │  ├■═╤═ 🔖 1 💰 g:1 🎯 h:-149 ⚖  1|16|16 ═══ α=-10000 β=10000 ═══ ⚡ a4
 │  │  ├□═╤═ 🔖 17 💰 g:2 ⚖  2|31|16 ═══ α=-10000 β=10000 ═══ ⚡ a3
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 o . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□ -49 → α
 │  │  ├□═╤═ 🔖 18 💰 g:2 ⚖  2|31|17 ═══ α=-49 β=10000 ═══ ⚡ a2
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 o . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 19 💰 g:2 ⚖  2|31|18 ═══ α=-49 β=10000 ═══ ⚡ a1
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 o . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 → α
 │  │  ├□═╤═ 🔖 20 💰 g:2 ⚖  2|31|19 ═══ α=0 β=10000 ═══ ⚡ b4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x o . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 21 💰 g:2 ⚖  2|31|20 ═══ α=0 β=10000 ═══ ⚡ b3
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . o . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□═╤═ 🔖 22 💰 g:2 ⚖  2|31|21 ═══ α=0 β=10000 ═══ ⚡ b2
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . o . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□═╤═ 🔖 23 💰 g:2 ⚖  2|31|22 ═══ α=0 β=10000 ═══ ⚡ b1
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . o . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 24 💰 g:2 ⚖  2|31|23 ═══ α=0 β=10000 ═══ ⚡ c4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . o . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 25 💰 g:2 ⚖  2|31|24 ═══ α=0 β=10000 ═══ ⚡ c3
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . o . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□═╤═ 🔖 26 💰 g:2 ⚖  2|31|25 ═══ α=0 β=10000 ═══ ⚡ c2
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . o . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□═╤═ 🔖 27 💰 g:2 ⚖  2|31|26 ═══ α=0 β=10000 ═══ ⚡ c1
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . o . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 28 💰 g:2 ⚖  2|31|27 ═══ α=0 β=10000 ═══ ⚡ d4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . o 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□═╤═ 🔖 29 💰 g:2 ⚖  2|31|28 ═══ α=0 β=10000 ═══ ⚡ d3
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . o 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  ├□═╤═ 🔖 30 💰 g:2 ⚖  2|31|29 ═══ α=0 β=10000 ═══ ⚡ d2
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . o 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 x . . . 4 
 │  │  │    A B C D ─── 🍃 -49
 │  │  └□═╤═ 🔖 31 💰 g:2 ⚖  2|31|30 ═══ α=0 β=10000 ═══ ⚡ d1
 │  │    4 em Linha (4x4)
 │  │       A B C D
 │  │     1 . . . o 1 
 │  │     2 . . . . 2 
 │  │     3 . . . . 3 
 │  │     4 x . . . 4 
 │  │       A B C D ─── 🍃 0
 │  ├■ 0 → β
 │  ├■═╤═ 🔖 10 💰 g:1 🎯 h:-149 ⚖  2|31|31 ═══ α=-10000 β=0 ═══ ⚡ c3
 │  │  ├□═╤═ 🔖 32 💰 g:2 ⚖  3|46|31 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . x . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 33 🔖 34 🔖 35 … 🔖 44 🔖 45 🔖 46 } #14
 │  ├■═╤═ 🔖 11 💰 g:1 🎯 h:-149 ⚖  3|46|32 ═══ α=-10000 β=0 ═══ ⚡ c2
 │  │  ├□═╤═ 🔖 47 💰 g:2 ⚖  4|61|32 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . x . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 48 🔖 49 🔖 50 … 🔖 59 🔖 60 🔖 61 } #14
 │  ├■═╤═ 🔖 13 💰 g:1 🎯 h:-149 ⚖  4|61|33 ═══ α=-10000 β=0 ═══ ⚡ d4
 │  │  ├□═╤═ 🔖 62 💰 g:2 ⚖  5|76|33 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . x 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 63 🔖 64 🔖 65 … 🔖 74 🔖 75 🔖 76 } #14
 │  ├■═╤═ 🔖 7 💰 g:1 🎯 h:-149 ⚖  5|76|34 ═══ α=-10000 β=0 ═══ ⚡ b2
 │  │  ├□═╤═ 🔖 77 💰 g:2 ⚖  6|91|34 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . x . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 78 🔖 79 🔖 80 … 🔖 89 🔖 90 🔖 91 } #14
 │  ├■═╤═ 🔖 16 💰 g:1 🎯 h:-149 ⚖  6|91|35 ═══ α=-10000 β=0 ═══ ⚡ d1
 │  │  ├□═╤═ 🔖 92 💰 g:2 ⚖  7|106|35 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . x 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 93 🔖 94 🔖 95 … 🔖 104 🔖 105 🔖 106 } #14
 │  ├■═╤═ 🔖 6 💰 g:1 🎯 h:-149 ⚖  7|106|36 ═══ α=-10000 β=0 ═══ ⚡ b3
 │  │  ├□═╤═ 🔖 107 💰 g:2 ⚖  8|121|36 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . x . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 108 🔖 109 🔖 110 … 🔖 119 🔖 120 🔖 121 } #14
 │  ├■═╤═ 🔖 4 💰 g:1 🎯 h:-149 ⚖  8|121|37 ═══ α=-10000 β=0 ═══ ⚡ a1
 │  │  ├□═╤═ 🔖 122 💰 g:2 ⚖  9|136|37 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 x . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 0
 │  │  ├□ 0 ─── 🪓 β(0) { 🔖 123 🔖 124 🔖 125 … 🔖 134 🔖 135 🔖 136 } #14
 │  ├■═╤═ 🔖 2 💰 g:1 🎯 h:-99 ⚖  9|136|38 ═══ α=-10000 β=0 ═══ ⚡ a3
 │  │  ├□═╤═ 🔖 137 💰 g:2 ⚖  10|151|38 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 x . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 138 🔖 139 🔖 140 … 🔖 149 🔖 150 🔖 151 } #14
 │  ├■═╤═ 🔖 14 💰 g:1 🎯 h:-99 ⚖  10|151|39 ═══ α=-10000 β=0 ═══ ⚡ d3
 │  │  ├□═╤═ 🔖 152 💰 g:2 ⚖  11|166|39 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . x 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 153 🔖 154 🔖 155 … 🔖 164 🔖 165 🔖 166 } #14
 │  ├■═╤═ 🔖 5 💰 g:1 🎯 h:-99 ⚖  11|166|40 ═══ α=-10000 β=0 ═══ ⚡ b4
 │  │  ├□═╤═ 🔖 167 💰 g:2 ⚖  12|181|40 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o x . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 168 🔖 169 🔖 170 … 🔖 179 🔖 180 🔖 181 } #14
 │  ├■═╤═ 🔖 3 💰 g:1 🎯 h:-99 ⚖  12|181|41 ═══ α=-10000 β=0 ═══ ⚡ a2
 │  │  ├□═╤═ 🔖 182 💰 g:2 ⚖  13|196|41 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 x . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 183 🔖 184 🔖 185 … 🔖 194 🔖 195 🔖 196 } #14
 │  ├■═╤═ 🔖 9 💰 g:1 🎯 h:-99 ⚖  13|196|42 ═══ α=-10000 β=0 ═══ ⚡ c4
 │  │  ├□═╤═ 🔖 197 💰 g:2 ⚖  14|211|42 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . x . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 198 🔖 199 🔖 200 … 🔖 209 🔖 210 🔖 211 } #14
 │  ├■═╤═ 🔖 15 💰 g:1 🎯 h:-99 ⚖  14|211|43 ═══ α=-10000 β=0 ═══ ⚡ d2
 │  │  ├□═╤═ 🔖 212 💰 g:2 ⚖  15|226|43 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . . . 1 
 │  │  │  2 . . . x 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 213 🔖 214 🔖 215 … 🔖 224 🔖 225 🔖 226 } #14
 │  ├■═╤═ 🔖 12 💰 g:1 🎯 h:-99 ⚖  15|226|44 ═══ α=-10000 β=0 ═══ ⚡ c1
 │  │  ├□═╤═ 🔖 227 💰 g:2 ⚖  16|241|44 ═══ α=-10000 β=0 ═══ ⚡ a4
 │  │  │ 4 em Linha (4x4)
 │  │  │    A B C D
 │  │  │  1 . . x . 1 
 │  │  │  2 . . . . 2 
 │  │  │  3 . . . . 3 
 │  │  │  4 o . . . 4 
 │  │  │    A B C D ─── 🍃 49
 │  │  ├□ 49 ─── 🪓 β(0) { 🔖 228 🔖 229 🔖 230 … 🔖 239 🔖 240 🔖 241 } #14
 │  └■═╤═ 🔖 8 💰 g:1 🎯 h:-99 ⚖  16|241|45 ═══ α=-10000 β=0 ═══ ⚡ b1
 │     ├□═╤═ 🔖 242 💰 g:2 ⚖  17|256|45 ═══ α=-10000 β=0 ═══ ⚡ a4
 │     │ 4 em Linha (4x4)
 │     │    A B C D
 │     │  1 . x . . 1 
 │     │  2 . . . . 2 
 │     │  3 . . . . 3 
 │     │  4 o . . . 4 
 │     │    A B C D ─── 🍃 49
 │     ├□ 49 ─── 🪓 β(0) { 🔖 243 🔖 244 🔖 245 … 🔖 254 🔖 255 🔖 256 } #14 HT: reutilização 0.35 vezes 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>3 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>2 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0 <span style="color:gray">P15=</span>200
 ├─ ⚙   ─ <span style="color:gray">P16=</span>100
═╧═ 🏁  Execução terminada ⏱   6ms  ═══
Jogo Em Linha
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> MiniMax alfa/beta | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 3
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0 | <span style="color:gray">P12(ORDENAR_SUCESSORES):</span> 2
│ <span style="color:gray">P13(PODA_HEURISTICA):</span> 0 | <span style="color:gray">P14(PODA_CEGA):</span> 0 | <span style="color:gray">P15(HEUR_BASE):</span> 200 | <span style="color:gray">P16(HEUR_MAX_PONTOS):</span> 100
└──────────────────────────────────────────────────────────────────────
 │ 4 em Linha (4x4)
 │    A B C D
 │  1 . . . . 1 
 │  2 . . . . 2 
 │  3 . . . . 3 
 │  4 x . . . 4 
 │    A B C D
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 6 | <span style="color:gray">I3(Iterações):</span> 46 | <span style="color:gray">I4(IND_EXPANSOES):</span> 17 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 256 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Realçamos os seguintes pontos:
- alfa que inicialmente é -10000 é atualizado para para -49 no estado 17 (`├□ -49 → α`),
- logo no estado 19 ocorre nova atualização para 0 (`├□ 0 → α`)
- o estado 20 é igual ao estado 17 (eixo diagonal), no entanto não é removido devido a não existir simetrias implementadas.
- o segundo ramo com c3, estado 10, expande para o estado 32 com custo 0, é imediatamente cortado (`├□ 0 ─── 🪓 β(0) { 🔖 33 🔖 34 🔖 35 … 🔖 44 🔖 45 🔖 46 } #14`).
- o mesmo ocorre nos restantes lances, poupando a análise de inúmeros estados

O motivo para não se implementar simetrias, é que em tabuleiros grandes acabam por ocorrer apenas no início do jogo.
Todo o resto do tempo a normalizar o estado, é tempo que é desperdiçado sem que exista real vantagem.
No entanto se o mesmo estado ocorrer exatamente no mesmo formato, a hashtable está ligada e o estado é reutilizado.

A qualidade da heurística é aqui crítico.

Temos dois parâmetros que influenciam a heurística:
- HEUR_BASE - Valor base para diferença entre ameaças de K e K-1 (100 não há diferença, 200 corresponde ao doubro e é o valor de omissão)
- HEUR_MAX_PONTOS - Pontos de amaeaças máximos, para colocar a função sigmoide a saturar por essa altura (ficando perto do +/-infinito)

Esta heurística é genérica, e pode ser utilizada em problemas que se possam calcular ameaças a K jogadas,
como é o caso dos jogos em que se pretende fazer K marcas em linha.
No entanto os valores de omissão podem não ser os melhores, pelo que serão alvo de teste.


\anchor jel-a4
## Ação 4 - Torneio Profundidade

Nos testes empíricos vamos utilizar a linha de comando, por ser mais simples a identificação do teste a realizar.

Pretendemos verificar em torneio, que a profundidade maior resulta em força de jogo superior.
Por outro lado pretendemos confirmar que os cortes alfa/beta e a ordenação dos sucessores,
não alteram de forma significativa a força de jogo,
mas reduzem o tempo de execução (P1=1,2 x P12=0,1).

Vamos variar apenas quatro profundidades, nível 1 a 3, deixando a procura iterativa para o torneio seguinte (P7=2:4).
A profundidade com nível fixo, se o tempo acabar irá retornar um resultado que pode não ser o melhor possível.
A utilização da procura em profundidade iterativa, permite que quando o tempo acaba, seja utilizada a
última árvore completamente explorada, e assim a jogada não será baseada numa árvore incompleta.
Para procurar ver o ganho de profundidade sem perturbação do limite de tempo, vamos colocar neste teste um tempo por jogada de 60 segundos (P4=60).
Vamos utilizar todas as instâncias, já que a heurística é igual.

- **Tipo de Teste / Objetivo**: Performance (Profundidade, alfa/beta, ordenação)
- **Definição**: Instâncias: 1:10; Configurações: P1=1,2 x P12=0,1 x P7=2:4
- **Esforço**: (um só jogo, não há aleatoriedade)
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioProfundidade -M 0 -G 1 -P P2=2 P4=60 P1=1,2 x P12=0,1 x P7=2:4

Nota: Vamos neste torneio gravar os jogos (-G 1), para mostrar essa possibilidade, mas como não iremos analisar os jogos,
não iremos manter esta configuração nos torneios seguintes.

\htmlonly
<details>
  <summary>Ver script: evolutivos1.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=torneioProfundidade
#SBATCH --output=Resultados/torneioProfundidade.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: TorneioProfundidade
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioProfundidade -M 1 -G 1 -P P2=2 P4=60 P1=1,2 x P12=0,1 x P7=2:4
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>
═╤═ Instâncias ═══ { 📄 1 📄 2 📄 3 📄 4 📄 5 📄 6 📄 7 📄 8 📄 9 📄 10 } 
 ├─ 🛠️  ─ <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>60 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0 <span style="color:gray">P15=</span>200 <span style="color:gray">P16=</span>100<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P7=</span>2 <span style="color:gray">P12=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P7=</span>2 <span style="color:gray">P12=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P7=</span>2 <span style="color:gray">P12=</span>1
 │ ...
 ├─ ⚙  [10] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P7=</span>4 <span style="color:gray">P12=</span>0
 ├─ ⚙  [11] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P7=</span>4 <span style="color:gray">P12=</span>1
 ├─ ⚙  [12] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P7=</span>4 <span style="color:gray">P12=</span>1
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:1320   📄 Instâncias: 10   🛠️ Configurações: 12   🖥️ Processos: 48.
 ├─ ⏱ 1' 1" 704ms     📋 201   📄 6     🛠️ 10    🛠️ 4     🖥️ 29    ⚖  
 ├─ ⏱ 2' 4" 994ms     📋 215   📄 8     🛠️ 10    🛠️ 4     🖥️ 30    ⚖  
 ├─ ⏱ 3' 10" 498ms    📋 242   📄 8     🛠️ 10    🛠️ 0     🖥️ 45    ⚖  
 ├─ ⏱ 4' 13" 454ms    📋 294   📄 8     🛠️ 9     🛠️ 4     🖥️ 24    ⚖  
 ├─ ⏱ 5' 15" 392ms    📋 362   📄 7     🛠️ 9     🛠️ 10    🖥️ 39    ⚖  
 ├─ ⏱ 6' 29" 324ms    📋 375   📄 6     🛠️ 8     🛠️ 6     🖥️ 31    ⚖  
 ├─ ⏱ 7' 35" 427ms    📋 405   📄 10    🛠️ 9     🛠️ 1     🖥️ 40    ⚖  
 ├─ ⏱ 8' 45" 254ms    📋 431   📄 8     🛠️ 8     🛠️ 3     🖥️ 13    ⚖  
 ├─ ⏱ 9' 49" 841ms    📋 464   📄 8     🛠️ 7     🛠️ 9     🖥️ 24    ⚖  
 ├─ ⏱ 10' 50" 191ms   📋 565   📄 7     🛠️ 8     🛠️ 4     🖥️ 7     ⚖  
 ├─ ⏱ 11' 51" 493ms   📋 594   📄 7     🛠️ 6     🛠️ 7     🖥️ 30    ⚖  
 ├─ ⏱ 12' 59" 993ms   📋 683   📄 6     🛠️ 5     🛠️ 10    🖥️ 3     ⚖  
 ├─ ⏱ 14' 132ms       📋 773   📄 10    🛠️ 5     🛠️ 0     🖥️ 7     ⚖  
 ├─ ⏱ 15' 6" 472ms    📋 803   📄 9     🛠️ 4     🛠️ 9     🖥️ 25    ⚖  
 ├─ ⏱ 16' 6" 642ms    📋 845   📄 6     🛠️ 4     🛠️ 3     🖥️ 30    ⚖  
 ├─ ⏱ 17' 10" 734ms   📋 911   📄 9     🛠️ 3     🛠️ 9     🖥️ 40    ⚖  
 ├─ ⏱ 18' 12" 131ms   📋 992   📄 9     🛠️ 2     🛠️ 11    🖥️ 7     ⚖  
 ├─ ⏱ 19' 33" 27ms    📋 1012  📄 9     🛠️ 2     🛠️ 9     🖥️ 22    ⚖  
 ├─ ⏱ 20' 38" 269ms   📋 1025  📄 6     🛠️ 2     🛠️ 8     🖥️ 1     ⚖  
 ├─ ⏱ 21' 44" 254ms   📋 1115  📄 9     🛠️ 2     🛠️ 10    🖥️ 7     ⚖  
 ├─ ⏱ 22' 46" 778ms   📋 1132  📄 7     🛠️ 1     🛠️ 9     🖥️ 42    ⚖  
 ├─ ⏱ 23' 55" 191ms   📋 1151  📄 10    🛠️ 1     🛠️ 6     🖥️ 24    ⚖  
 ├─ ⏱ 24' 56" 915ms   📋 1232  📄 6     🛠️ 0     🛠️ 10    🖥️ 7     ⚖  
 ├─ ⏱ 25' 58" 606ms   📋 1320  📄 10    🛠️ 0     🛠️ 6     🖥️ 41    ⚖  
 ├─ ⏱ 27' 44" 826ms   📋 1320  📄 7     🛠️ 0     🛠️ 10    🖥️ 25    ⚖  
 ├─ ⏱ 29' 24" 327ms   📋 1320  📄 10    🛠️ 10    🛠️ 9     🖥️ 21    ⚖  
 ├─ ⏱ 30' 34" 472ms   📋 1320  📄 10    🛠️ 8     🛠️ 11    🖥️ 17    ⚖  
 ├─ ⏱ 31' 45" 230ms   📋 1320  📄 10    🛠️ 8     🛠️ 5     🖥️ 31    ⚖  
 ├─ ⏱ 32' 50" 813ms   📋 1320  📄 10    🛠️ 8     🛠️ 1     🖥️ 29    ⚖  
 ├─ ⏱ 34' 646ms       📋 1320  📄 10    🛠️ 7     🛠️ 10    🖥️ 6     ⚖  
 ├─ ⏱ 35' 13" 216ms   📋 1320  📄 10    🛠️ 8     🛠️ 9     🖥️ 2     ⚖  
 ├─ ⏱ 37' 16" 785ms   📋 1320  📄 10    🛠️ 5     🛠️ 10    🖥️ 37    ⚖  
 ├─ ⏱ 39' 2" 43ms     📋 1320  📄 10    🛠️ 4     🛠️ 10    🖥️ 19    ⚖  
 ├─ ⏱ 40' 49" 649ms   📋 1320  📄 10    🛠️ 3     🛠️ 10    🖥️ 30    ⚖  
 ├─ ⏱ 42' 40" 370ms   📋 1320  📄 10    🛠️ 2     🛠️ 10    🖥️ 28    ⚖  
 ├─ ⏱ 45' 35" 733ms   📋 1320  📄 10    🛠️ 1     🛠️ 10    🖥️ 3     ⚖  
 ├─ ⏱ 48' 57" 490ms   📋 1320  📄 10    🛠️ 0     🛠️ 10    🖥️ 47    ⚖  
 ├─ ⏱ 54' 51" 376ms   📋 1320  📄 10    🛠️ 8     🛠️ 10    🖥️ 45    ⚖  
 ├─ 📑  Ficheiro Resultados/TorneioProfundidade.csv gravado.
 │  ⏱  Tempo real: 54' 51" 381ms 
 │  ⏱  CPU total: 1d 18h 58' 14" 920ms 
 │  ⏱  Espera do gestor: 54' 51" 338ms 
 │  ⏱  Espera trabalhadores: 16h 16' 26" 181ms 
 │  📊  Utilização:
 │  - Total: 60.8%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 62.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 54' 51" 381ms ) ═══
</pre>
\endhtmlonly
</details>

Nesta execução podemos ver que a taxa de utilização foi de 60%.
Este facto deve-se a que houve jogos que levaram muito mais tempo que outros.
A última tarefa (jogo) foi colocada no minuto 25, tendo os processadores que ficaram livres após esse instante ficado sem trabalho até ao final.

Para medir a performance de cada configuração e lado (branco/preto), vamos analisar o desempenho e eficácia:
- Desempenho: Tempo médio por jogada em segundos
- Eficácia: Média de pontos (vitória 1 ponto, empate 0.5 pontos, derrota 0 pontos)

Desta forma mantemos a ligação de desempenho à performance temporal, e eficácia à taxa de sucesso, sendo de certa forma uma probabilidade de vitória.

Vamos ver neste primeiro relatório a performance do jogador branco: 

|  | P1(ALGORITMO) | P12(ORDENAR_SUCESSORES) | P7(LIMITE)<br>2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| DesempenhoBranco | 1:MiniMax | ID | 0,001 | 0,04 | 3,852 |
| | | Heurística | 0,001 | 0,04 | 3,732 |
| | 2:MiniMax alfa/beta | ID | 0,001 | 0,01 | 0,607 |
| | | Heurística | 0,001 | 0,006 | 0,093 |
| EficáciaBranco | 1:MiniMax | ID | 0,45 | 0,53 | 0,6 |
| | | Heurística | 0,45 | 0,55 | 0,63 |
| | 2:MiniMax alfa/beta | ID | 0,45 | 0,53 | 0,6 |
| | | Heurística | 0,45 | 0,55 | 0,63 |
| Total TempoBrancoJog  | | | 0,001 | 0,024 | 2,068 |
| Total DesempenhoBranco | | | 0,45 | 0,54 | 0,62 |

Podemos neste ponto concluir que:
- A profundidade tem um impacto muito grande no desempenho, aumentando exponencialmente, para mais de 2 segundos por jogada no nível 4. Naturalmente que estes resultados são médias de 10 instâncias, sendo as instâncias maiores as responsáveis por estes tempos.
- Maior profundidade resulta em melhor eficácia, confirmando a hipótese inicial, embora não sejam ganhos elevados.
- As diferenças de eficácia entre alfa/beta e sem cortes, não são observáveis, nem com a ordenação.
- Em termos de desempenho registamos um grande ganho para os cortes alfa/beta, e a ordenação dos sucessores por heurística, que se torna mais evidente com o aumento da profundidade.

Vamos agora ver a mesma tabela para o jogador a preto:

|  | P1(ALGORITMO) | P12(ORDENAR_SUCESSORES) | P7(LIMITE)<br> 2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| DesempenhoPreto | 1:MiniMax | ID | 0 | 0,039 | 3,35 |
| | | Heurística | 0 | 0,043 | 3,546 |
| | 2:MiniMax alfa/beta | ID | 0 | 0,01 | 0,486 |
| | | Heurística | 0 | 0,006 | 0,092 |
| EficáciaPreto | 1:MiniMax | ID | 0,38 | 0,5 | 0,49 |
| | | Heurística | 0,38 | 0,52 | 0,52 |
| | 2:MiniMax alfa/beta | ID | 0,38 | 0,5 | 0,49 |
| | | Heurística | 0,38 | 0,52 | 0,52 |
| Total TempoPretoJog | | | 0 | 0,024 | 1,87 |
| Total DesempenhoPreto | | | 0,38 | 0,51 | 0,51 |

As conclusões são semelhantes, tendo que se registar que a eficácia do jogador a preto é ligeiramente inferior ao do jogador a branco.

Podemose ver também do lado das instâncias, o número de vitórias, empates e derrotas:

| Instância | Vitória Preta | Empate | Vitória Branca |
|:---:|:---:|:---:|:---:|
| 1 | | 132 | |
| 2 | | 132 | |
| 3 | 4 | 126 | 2 |
| 4 | 42 | 12 | 78 |
| 5 | 48 | 8 | 76 |
| 6 | 16 | 116 | |
| 7 | 2 | 100 | 30 |
| 8 | | 116 | 16 |
| 9 | | 132 | |
| 10 | | 132 | |
| Total Geral | 112 | 1006 | 202 |

Algumas instâncias têm apenas empates, outras têm poucos empates, existindo ainda instâncias só com empates e vitórias brancas / pretas.

As instâncias correspondem a jogos diferentes, tanto no tamanho como no aspeto da gravidade que limita o número de movimentos possíveis.

Pretendemos optimizar cada instância, mas de momento temos conclusões gerais:
- Os cortes alfa/beta, bem como a ordenação dos sucessores, são benéficos em termos de desempenho, sem impacto na eficácia.
- A profundidade aumenta a força de jogo, mas o tempo aumenta exponencialmente.

Tempos elevados por jogada não são viáveis nem para testes empíricos, nem para jogar contra jogadores humanos.


\anchor jel-a5
## Ação 5 - Torneio Iterativo

Na ação anterior, tem um torneio que compara configurações, utilizando tempos distintos.
Assim a comparação não é justa, embora tenha permitido observar vantagens nos cortes alfa/beta e ordenação dos sucessores. 

Vamos agora utilizar a profundidade iterativa, e dando exatamente o mesmo tempo por jogada, procurar ver se a eficácia
dos coertes alfa/beta e ordenação dos sucessores se mantém. 

Com o método iterativo a profundidade vai iterativamente sendo aumentada.
Esta estratégia tem a vantagem de ter sempre um movemento pronto a jogar quando o tempo acaba.
Por outro lado, utiliza o tempo existente, se der para explorar mais um nível, esse é explorado.

Temos mais uma opção na ordennação, que é o valor 2 (omissão). Este valor, para além de ordenar os sucessores,
guarda em memória cada estado, e resultado de análises anteriores. Quando o estado ocorre novamnete, se estiver 
em memória, o seu valor é utilizado em vez de ser executada a heurítica ou uma procura e determinada profundidade.
Para tal é guardada alguma informação sobre o estado de modo a sabermos se podemos utilizar o valor assim que exista
possibilidade de reutilização. Esta opção tem naturalmente mais impacto na procura iterativa, em que os estados
iniciais são re-expandidos, mas pode ter influencia mesmo sem ser na procura iterativa, 
caso o mesmo estado apareça várias vezes por ordens distintas de movimentos.

Vamos limitar o tempo a 1 segundo (P4=1).

- **Tipo de Teste / Objetivo**: Eficácia (alfa/beta, ordenação)
- **Definição**: Instâncias: 1:10; Configurações: P7=0 P1=1,2 x P12=0:2 
- **Esforço**: (um só jogo, não há aleatoriedade)
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioIterativo -M 1 -P P2=2 P4=1 P7=0 P1=1,2 x P12=0:2 

\htmlonly
<details>
  <summary>Ver script: evolutivos1.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=torneioIterativo
#SBATCH --output=Resultados/torneioIterativo.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioIterativo
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioIterativo -M 1 -P P2=2 P4=1 P7=0 P1=1,2 x P12=0:2 
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>
</pre>
\endhtmlonly
</details>













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

\anchor jel-a6
## Ação 6 - Torneio Heurística


\anchor jel-a7
## Ação 7 - Torneio Ruido

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



\anchor jel-a8
## Ação 8 - Torneio Poda

... (estudar o efeito da poda)



\anchor jel-a9
## Ação 9 - Torneio Níveis

Estando identificadas as variáveis críticas de desempenho estamos em condições de identificar configurações com diferentes níveis de força de jogo.

Pretendemos que a diferença de força de jogo entre níveis consecutivos, seja significativa e constante,
idealmente com 3 pontos em 4 jogos, ou seja, 75%.

Desta forma podemos ter diferentes níveis de jogo para diferentes dificuldades que o jogador humano pretender enfrentar,
podendo optar por um adversário artificial adequado à sua força de jogo atual. 

Um torneio entre os diferentes níveis deve portanto confirmar esta hipótese 75% de vitórias contra o nível imediatamente inferior.

O número de níveis tem de ir desde o jogador aleatório até à configuração mais forte encontrada nas ações anteriores.


