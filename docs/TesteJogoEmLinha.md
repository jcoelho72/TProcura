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
- [Ação 7 - Torneio Poda](#jel-a7)
- [Ação 8 - Torneio Ruido](#jel-a8)
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
- HEUR_MAX_PONTOS - Pontos de ameaças máximos, para colocar a função sigmoide a saturar por essa altura (ficando perto do +/-infinito)

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
  <summary>Ver script: torneioProfundidade.sh</summary>
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

Vamos limitar o tempo a 1 segundo (P4=1). Vamos estudar também a influênica de baralhar os sucessores com P11=0,1.
Notar que esta ação pode ser feita em conjunto com a ordenação, ou seja, primeiro baralha-se e depois ordena-se,
ficando os estados com o mesmo valor por ordem aleatória. Caso não atrapalhe, a baralhação dos sucessores é importante
para permitir realizar vários jogos distintos entre duas configurações iguais, e assim ter um resultado mais preciso.

- **Tipo de Teste / Objetivo**: Eficácia (alfa/beta, ordenação, baralhação)
- **Definição**: Instâncias: 1:10; Configurações: P7=0 P1=1,2 x P12=0:2 x P11=0,1
- **Esforço**: (um só jogo, não há aleatoriedade)
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioIterativo -M 1 -P P2=2 P4=1 P7=0 P1=1,2 x P12=0:2 x P11=0,1

<details>
  <summary>Ver script: torneioIterativo.sh</summary>
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
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioIterativo -M 1 -P P2=2 P4=1 P7=0 P1=1,2 x P12=0:2 x P11=0,1
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>
═╤═ Instâncias ═══ { 📄 1 📄 2 📄 3 📄 4 📄 5 📄 6 📄 7 📄 8 📄 9 📄 10 } 
 ├─ 🛠️  ─ <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>1 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>1 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0 <span style="color:gray">P15=</span>200 <span style="color:gray">P16=</span>100<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P11=</span>0 <span style="color:gray">P12=</span>1
 │ ...
 ├─ ⚙  [10] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P11=</span>1 <span style="color:gray">P12=</span>1
 ├─ ⚙  [11] ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P11=</span>1 <span style="color:gray">P12=</span>2
 ├─ ⚙  [12] ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P11=</span>1 <span style="color:gray">P12=</span>2
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:1320   📄 Instâncias: 10   🛠️ Configurações: 12   🖥️ Processos: 48.
 ├─ ⏱ 1' 848ms        📋 101   📄 6     🛠️ 11    🛠️ 5     🖥️ 39    ⚖  
 ├─ ⏱ 2' 934ms        📋 149   📄 3     🛠️ 10    🛠️ 8     🖥️ 30    ⚖  
 ├─ ⏱ 3' 1" 593ms     📋 207   📄 6     🛠️ 10    🛠️ 6     🖥️ 6     ⚖  
 ├─ ⏱ 4' 2" 56ms      📋 266   📄 9     🛠️ 10    🛠️ 3     🖥️ 3     ⚖  
 ├─ ⏱ 5' 2" 907ms     📋 319   📄 4     🛠️ 9     🛠️ 3     🖥️ 32    ⚖  
 ├─ ⏱ 6' 3" 259ms     📋 374   📄 7     🛠️ 9     🛠️ 3     🖥️ 18    ⚖  
 ├─ ⏱ 7' 5" 715ms     📋 429   📄 4     🛠️ 8     🛠️ 3     🖥️ 23    ⚖  
 ├─ ⏱ 8' 5" 787ms     📋 486   📄 7     🛠️ 8     🛠️ 3     🖥️ 9     ⚖  
 ├─ ⏱ 9' 7" 282ms     📋 553   📄 6     🛠️ 7     🛠️ 5     🖥️ 3     ⚖  
 ├─ ⏱ 10' 7" 362ms    📋 605   📄 10    🛠️ 7     🛠️ 8     🖥️ 46    ⚖  
 ├─ ⏱ 11' 7" 593ms    📋 662   📄 1     🛠️ 6     🛠️ 0     🖥️ 18    ⚖  
 ├─ ⏱ 12' 8" 229ms    📋 714   📄 5     🛠️ 5     🛠️ 10    🖥️ 1     ⚖  
 ├─ ⏱ 13' 10" 414ms   📋 772   📄 4     🛠️ 5     🛠️ 2     🖥️ 25    ⚖  
 ├─ ⏱ 14' 11" 501ms   📋 827   📄 8     🛠️ 5     🛠️ 0     🖥️ 45    ⚖  
 ├─ ⏱ 15' 11" 638ms   📋 882   📄 9     🛠️ 4     🛠️ 8     🖥️ 32    ⚖  
 ├─ ⏱ 16' 12" 32ms    📋 936   📄 5     🛠️ 3     🛠️ 11    🖥️ 37    ⚖  
 ├─ ⏱ 17' 12" 726ms   📋 995   📄 9     🛠️ 3     🛠️ 8     🖥️ 36    ⚖  
 ├─ ⏱ 18' 13" 108ms   📋 1051  📄 5     🛠️ 2     🛠️ 10    🖥️ 1     ⚖  
 ├─ ⏱ 19' 14" 429ms   📋 1103  📄 3     🛠️ 2     🛠️ 1     🖥️ 15    ⚖  
 ├─ ⏱ 20' 14" 501ms   📋 1158  📄 5     🛠️ 1     🛠️ 8     🖥️ 36    ⚖  
 ├─ ⏱ 21' 14" 568ms   📋 1215  📄 9     🛠️ 1     🛠️ 8     🖥️ 5     ⚖  
 ├─ ⏱ 22' 15" 594ms   📋 1275  📄 9     🛠️ 1     🛠️ 2     🖥️ 13    ⚖  
 ├─ ⏱ 23' 16" 347ms   📋 1320  📄 8     🛠️ 0     🛠️ 6     🖥️ 47    ⚖  
 ├─ ⏱ 24' 18" 274ms   📋 1320  📄 10    🛠️ 0     🛠️ 6     🖥️ 11    ⚖  
 ├─ 📑  Ficheiro Resultados/TorneioIterativo.csv gravado.
 │  ⏱  Tempo real: 25' 16" 76ms 
 │  ⏱  CPU total: 19h 47' 35" 578ms 
 │  ⏱  Espera do gestor: 25' 16" 23ms 
 │  ⏱  Espera trabalhadores: 1h 8' 44" 222ms 
 │  📊  Utilização:
 │  - Total: 92.2%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 94.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 25' 16" 76ms ) ═══
</pre>
\endhtmlonly
</details>


Podemos ver agora a eficácia do jogador das brancas:

| P11(BARALHAR_SUCESSORES) | P12(ORDENAR_SUCESSORES) | 1:MiniMax | 2:MiniMax alfa/beta |
|:---:|:---:|:---:|:---:|
| ID | ID | 0,48 | 0,49 |
| | Heurística | 0,45 | 0,55 |
| | Memória | 0,46 | 0,53 |
| Baralhar | ID | 0,46 | 0,47 |
| | Heurística | 0,52 | 0,58 |
| | Memória | 0,51 | 0,55 |
| Total Geral || 0,48 | 0,53 |


E do jogador das pretas:

| P11(BARALHAR_SUCESSORES) | P12(ORDENAR_SUCESSORES) | 1:MiniMax | 2:MiniMax alfa/beta |
|:---:|:---:|:---:|:---:|
| ID | ID | 0,44 | 0,42 |
| | Heurística | 0,43 | 0,53 |
| | Memória | 0,49 | 0,57 |
| Baralhar | ID | 0,48 | 0,48 |
| | Heurística | 0,47 | 0,58 |
| | Memória | 0,5 | 0,55 |
| Total Geral || 0,47 | 0,52 |


Em ambos os casos o MiniMax com cortes alfa/beta é mais eficaz, e a ordenação dos sucessores por heurística também traz vantagens.
A utilização de memória traz vantagens, mas menores que a ordenação por heurística.
Esta situação pode ser devida ao facto de utilizarmos apenas 1 segundo por jogada, e a vantagem de recuperar uma posição já vista é menos vincada.
A baralhação dos sucessores traz ligeira vantagem quando combinada com a ordenação por heurística,
e principalmente não piora, pelo que passamos a utilizar para poder fazer vários jogos entre duas configurações. 

Na tabela de resultados por instância, podemos ver o seguinte:

| Instância | Vitória Preta | Empate | Vitória Branca |
|:---:|:---:|:---:|:---:|
| 1 | | 132 | |
| 2 | | 132 | |
| 3 | | 122 | 10 |
| 4 | 65 | 9 | 58 |
| 5 | 69 | 1 | 62 |
| 6 | |  132 | |
| 7 | 9 | 109 | 14 |
| 8 | 11 | 98 | 23 |
| 9 | | 132 | |
| 10 | | 132 | |
| Total Geral | 154 | 999 | 167 |

Vê-se aqui claramente as instâncias 4 e 5 como mais decisivas, quase sem empates e bastante equilíbrio entre vitórias brancas e pretas.
Nestas instâncias existe uma menor ramificação, devido à gravidade, o que permite maior profundidade e maior eficácia dos algoritmos.
Por outro lado, as restantes instâncias podem não estar equilibradas e ser fácil defender contra qualquer tentativa de vitória. 

Naturalmente que mais tempo por jogada os resultados podem ser diferentes.


\anchor jel-a6
## Ação 6 - Torneio Heurística

Vamos agora estudar o impacto da heurística na eficácia do jogador.

Temos os seguintes parâmetros:
- HEUR_BASE - Valor base para diferença entre ameaças de K e K-1, em que 100 corresponde a 1 (não há diferença).
	- Valores testados: P15=100,150,200,300,400,800 
- HEUR_MAX_PONTOS - Pontos de ameaças máximos, para colocar a função sigmoide a saturar por essa altura.
	- Valores testados: P16=10,20,50,100,200,500

- **Tipo de Teste / Objetivo**: Eficácia (HEUR_BASE, HEUR_MAX_PONTOS)
- **Definição**: Instâncias: 1:10; Configurações: P7=0 P1=2 P12=1 P11=1 P15=100,150,200,300,400,800 x P16=10,20,50,100,200,500
- **Esforço**: (um só jogo)
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioHeuristica -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=100,150,200,300,400,800 x P16=10,20,50,100,200,500

<details>
  <summary>Ver script: torneioHeuristica.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=torneioHeuristica
#SBATCH --output=Resultados/torneioHeuristica.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioHeuristica
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioHeuristica -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=100,150,200,300,400,800 x P16=10,20,50,100,200,500
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>
═╤═ Instâncias ═══ { 📄 1 📄 2 📄 3 📄 4 📄 5 📄 6 📄 7 📄 8 📄 9 📄 10 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>2 <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>1 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>1 <span style="color:gray">P12=</span>1 <span style="color:gray">P13=</span>0 <span style="color:gray">P14=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P15=</span>100 <span style="color:gray">P16=</span>10
 ├─ ⚙  [2] ─ <span style="color:gray">P15=</span>150 <span style="color:gray">P16=</span>10
 ├─ ⚙  [3] ─ <span style="color:gray">P15=</span>200 <span style="color:gray">P16=</span>10
 │ ...
 ├─ ⚙  [34] ─ <span style="color:gray">P15=</span>300 <span style="color:gray">P16=</span>500
 ├─ ⚙  [35] ─ <span style="color:gray">P15=</span>400 <span style="color:gray">P16=</span>500
 ├─ ⚙  [36] ─ <span style="color:gray">P15=</span>800 <span style="color:gray">P16=</span>500
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:12600   📄 Instâncias: 10   🛠️ Configurações: 36   🖥️ Processos: 48.
 ├─ ⏱ 1' 313ms        📋 113   📄 6     🛠️ 35    🛠️ 29    🖥️ 19    ⚖  
 ├─ ⏱ 2' 323ms        📋 186   📄 3     🛠️ 35    🛠️ 18    🖥️ 4     ⚖  
 ├─ ⏱ 3' 973ms        📋 266   📄 9     🛠️ 35    🛠️ 19    🖥️ 36    ⚖  
 ├─ ⏱ 4' 1" 777ms     📋 342   📄 8     🛠️ 35    🛠️ 9     🖥️ 29    ⚖  
 ├─ ⏱ 5' 2" 351ms     📋 415   📄 7     🛠️ 34    🛠️ 30    🖥️ 40    ⚖  
 ├─ ⏱ 6' 3" 566ms     📋 489   📄 6     🛠️ 34    🛠️ 27    🖥️ 37    ⚖  
 ├─ ⏱ 7' 3" 654ms     📋 558   📄 5     🛠️ 34    🛠️ 17    🖥️ 34    ⚖  
 ├─ ⏱ 8' 4" 668ms     📋 633   📄 9     🛠️ 34    🛠️ 17    🖥️ 18    ⚖  
 ├─ ⏱ 9' 4" 981ms     📋 713   📄 8     🛠️ 34    🛠️ 0     🖥️ 38    ⚖  
 ├─ ⏱ 10' 5" 150ms    📋 778   📄 3     🛠️ 33    🛠️ 28    🖥️ 22    ⚖  
 ├─ ⏱ 11' 6" 135ms    📋 841   📄 10    🛠️ 33    🛠️ 23    🖥️ 24    ⚖  
 ├─ ⏱ 12' 8" 111ms    📋 908   📄 5     🛠️ 33    🛠️ 17    🖥️ 30    ⚖  
 ├─ ⏱ 13' 8" 162ms    📋 976   📄 8     🛠️ 33    🛠️ 11    🖥️ 44    ⚖  
 ├─ ⏱ 14' 8" 297ms    📋 1046  📄 3     🛠️ 33    🛠️ 2     🖥️ 1     ⚖  
 ├─ ⏱ 15' 10" 579ms   📋 1106  📄 9     🛠️ 33    🛠️ 3     🖥️ 45    ⚖  
 ├─ ⏱ 16' 11" 725ms   📋 1167  📄 9     🛠️ 32    🛠️ 31    🖥️ 41    ⚖  
 ├─ ⏱ 17' 11" 749ms   📋 1227  📄 6     🛠️ 32    🛠️ 22    🖥️ 33    ⚖  
 ├─ ⏱ 18' 12" 621ms   📋 1292  📄 6     🛠️ 32    🛠️ 16    🖥️ 14    ⚖  
 ├─ ⏱ 19' 12" 645ms   📋 1360  📄 1     🛠️ 32    🛠️ 4     🖥️ 15    ⚖  
 ├─ ⏱ 20' 13" 103ms   📋 1423  📄 5     🛠️ 31    🛠️ 35    🖥️ 35    ⚖  
 ├─ ⏱ 21' 14" 323ms   📋 1478  📄 8     🛠️ 31    🛠️ 34    🖥️ 47    ⚖  
 ├─ ⏱ 22' 14" 878ms   📋 1536  📄 10    🛠️ 31    🛠️ 34    🖥️ 43    ⚖  
 ├─ ⏱ 23' 15" 389ms   📋 1591  📄 8     🛠️ 31    🛠️ 22    🖥️ 29    ⚖  
 ├─ ⏱ 24' 15" 667ms   📋 1646  📄 9     🛠️ 31    🛠️ 18    🖥️ 38    ⚖  
 ├─ ⏱ 25' 17" 517ms   📋 1704  📄 9     🛠️ 31    🛠️ 12    🖥️ 23    ⚖  
 ├─ ⏱ 26' 19" 105ms   📋 1766  📄 6     🛠️ 31    🛠️ 3     🖥️ 44    ⚖  
 ├─ ⏱ 27' 19" 837ms   📋 1835  📄 7     🛠️ 31    🛠️ 0     🖥️ 40    ⚖  
 ├─ ⏱ 28' 21" 559ms   📋 1903  📄 2     🛠️ 30    🛠️ 20    🖥️ 20    ⚖  
 ├─ ⏱ 29' 21" 677ms   📋 1962  📄 7     🛠️ 30    🛠️ 22    🖥️ 9     ⚖  
 ├─ ⏱ 30' 21" 981ms   📋 2028  📄 8     🛠️ 30    🛠️ 9     🖥️ 12    ⚖  
 ├─ ⏱ 31' 22" 926ms   📋 2096  📄 2     🛠️ 30    🛠️ 1     🖥️ 21    ⚖  
 ├─ ⏱ 32' 23" 10ms    📋 2159  📄 4     🛠️ 29    🛠️ 32    🖥️ 16    ⚖  
 ├─ ⏱ 33' 23" 387ms   📋 2235  📄 9     🛠️ 29    🛠️ 25    🖥️ 7     ⚖  
 ├─ ⏱ 34' 25" 16ms    📋 2311  📄 7     🛠️ 29    🛠️ 17    🖥️ 21    ⚖  
 ├─ ⏱ 35' 25" 127ms   📋 2386  📄 2     🛠️ 29    🛠️ 7     🖥️ 19    ⚖  
 ├─ ⏱ 36' 25" 532ms   📋 2463  📄 8     🛠️ 29    🛠️ 1     🖥️ 26    ⚖  
 ├─ ⏱ 37' 26" 403ms   📋 2535  📄 2     🛠️ 28    🛠️ 27    🖥️ 34    ⚖  
 ├─ ⏱ 38' 27" 848ms   📋 2601  📄 2     🛠️ 28    🛠️ 20    🖥️ 35    ⚖  
 ├─ ⏱ 39' 28" 778ms   📋 2676  📄 2     🛠️ 28    🛠️ 13    🖥️ 32    ⚖  
 ├─ ⏱ 40' 29" 852ms   📋 2756  📄 10    🛠️ 28    🛠️ 20    🖥️ 1     ⚖  
 ├─ ⏱ 41' 31" 670ms   📋 2835  📄 7     🛠️ 27    🛠️ 35    🖥️ 23    ⚖  
 ├─ ⏱ 42' 32" 210ms   📋 2895  📄 8     🛠️ 27    🛠️ 33    🖥️ 31    ⚖  
 ├─ ⏱ 43' 33" 117ms   📋 2959  📄 3     🛠️ 27    🛠️ 20    🖥️ 20    ⚖  
 ├─ ⏱ 44' 34" 31ms    📋 3026  📄 3     🛠️ 27    🛠️ 13    🖥️ 45    ⚖  
 ├─ ⏱ 45' 34" 113ms   📋 3094  📄 6     🛠️ 27    🛠️ 11    🖥️ 2     ⚖  
 ├─ ⏱ 46' 34" 338ms   📋 3164  📄 2     🛠️ 26    🛠️ 35    🖥️ 11    ⚖  
 ├─ ⏱ 47' 35" 185ms   📋 3222  📄 4     🛠️ 26    🛠️ 31    🖥️ 42    ⚖  
 ├─ ⏱ 48' 36" 649ms   📋 3282  📄 9     🛠️ 26    🛠️ 31    🖥️ 43    ⚖  
 ├─ ⏱ 49' 36" 981ms   📋 3348  📄 4     🛠️ 26    🛠️ 18    🖥️ 6     ⚖  
 ├─ ⏱ 50' 37" 384ms   📋 3411  📄 5     🛠️ 26    🛠️ 13    🖥️ 36    ⚖  
 ├─ ⏱ 51' 38" 731ms   📋 3479  📄 10    🛠️ 26    🛠️ 16    🖥️ 22    ⚖  
 ├─ ⏱ 52' 39" 176ms   📋 3537  📄 6     🛠️ 26    🛠️ 1     🖥️ 23    ⚖  
 ├─ ⏱ 53' 40" 33ms    📋 3594  📄 9     🛠️ 25    🛠️ 34    🖥️ 1     ⚖  
 ├─ ⏱ 54' 40" 65ms    📋 3649  📄 8     🛠️ 25    🛠️ 27    🖥️ 12    ⚖  
 ├─ ⏱ 55' 40" 512ms   📋 3702  📄 4     🛠️ 25    🛠️ 17    🖥️ 31    ⚖  
 ├─ ⏱ 56' 41" 547ms   📋 3763  📄 5     🛠️ 25    🛠️ 10    🖥️ 1     ⚖  
 ├─ ⏱ 57' 42" 406ms   📋 3823  📄 8     🛠️ 25    🛠️ 9     🖥️ 27    ⚖  
 ├─ ⏱ 58' 43" 398ms   📋 3882  📄 3     🛠️ 24    🛠️ 34    🖥️ 9     ⚖  
 ├─ ⏱ 59' 44" 125ms   📋 3948  📄 4     🛠️ 24    🛠️ 28    🖥️ 3     ⚖  
 ├─ ⏱ 1h 45" 204ms    📋 4017  📄 4     🛠️ 24    🛠️ 21    🖥️ 11    ⚖  
 ├─ ⏱ 1h 1' 46" 193ms  📋 4078  📄 4     🛠️ 24    🛠️ 14    🖥️ 43    ⚖  
 ├─ ⏱ 1h 2' 46" 568ms  📋 4147  📄 6     🛠️ 24    🛠️ 11    🖥️ 25    ⚖  
 ├─ ⏱ 1h 3' 47" 702ms  📋 4212  📄 3     🛠️ 24    🛠️ 0     🖥️ 13    ⚖  
 ├─ ⏱ 1h 4' 48" 504ms  📋 4283  📄 10    🛠️ 24    🛠️ 6     🖥️ 20    ⚖  
 ├─ ⏱ 1h 5' 49" 437ms  📋 4353  📄 2     🛠️ 23    🛠️ 20    🖥️ 47    ⚖  
 ├─ ⏱ 1h 6' 49" 613ms  📋 4426  📄 4     🛠️ 23    🛠️ 15    🖥️ 23    ⚖  
 ├─ ⏱ 1h 7' 50" 176ms  📋 4501  📄 9     🛠️ 23    🛠️ 15    🖥️ 9     ⚖  
 ├─ ⏱ 1h 8' 51" 855ms  📋 4578  📄 4     🛠️ 22    🛠️ 35    🖥️ 23    ⚖  
 ├─ ⏱ 1h 9' 53" 631ms  📋 4648  📄 3     🛠️ 22    🛠️ 27    🖥️ 29    ⚖  
 ├─ ⏱ 1h 10' 54" 403ms  📋 4718  📄 5     🛠️ 22    🛠️ 24    🖥️ 47    ⚖  
 ├─ ⏱ 1h 11' 56" 48ms  📋 4795  📄 2     🛠️ 22    🛠️ 11    🖥️ 36    ⚖  
 ├─ ⏱ 1h 12' 56" 92ms  📋 4877  📄 6     🛠️ 22    🛠️ 9     🖥️ 24    ⚖  
 ├─ ⏱ 1h 13' 56" 266ms  📋 4945  📄 5     🛠️ 21    🛠️ 35    🖥️ 40    ⚖  
 ├─ ⏱ 1h 15' 204ms    📋 5009  📄 3     🛠️ 21    🛠️ 26    🖥️ 2     ⚖  
 ├─ ⏱ 1h 16' 1" 268ms  📋 5078  📄 8     🛠️ 21    🛠️ 20    🖥️ 29    ⚖  
 ├─ ⏱ 1h 17' 1" 426ms  📋 5144  📄 3     🛠️ 21    🛠️ 12    🖥️ 4     ⚖  
 ├─ ⏱ 1h 18' 1" 673ms  📋 5207  📄 7     🛠️ 21    🛠️ 13    🖥️ 47    ⚖  
 ├─ ⏱ 1h 19' 2" 457ms  📋 5276  📄 5     🛠️ 20    🛠️ 35    🖥️ 4     ⚖  
 ├─ ⏱ 1h 20' 2" 602ms  📋 5332  📄 4     🛠️ 20    🛠️ 30    🖥️ 26    ⚖  
 ├─ ⏱ 1h 21' 2" 734ms  📋 5395  📄 2     🛠️ 20    🛠️ 22    🖥️ 4     ⚖  
 ├─ ⏱ 1h 22' 2" 776ms  📋 5459  📄 8     🛠️ 20    🛠️ 22    🖥️ 6     ⚖  
 ├─ ⏱ 1h 23' 2" 874ms  📋 5524  📄 6     🛠️ 20    🛠️ 13    🖥️ 18    ⚖  
 ├─ ⏱ 1h 24' 4" 191ms  📋 5589  📄 5     🛠️ 20    🛠️ 6     🖥️ 41    ⚖  
 ├─ ⏱ 1h 25' 7" 293ms  📋 5646  📄 8     🛠️ 20    🛠️ 1     🖥️ 19    ⚖  
 ├─ ⏱ 1h 26' 7" 434ms  📋 5706  📄 6     🛠️ 19    🛠️ 30    🖥️ 2     ⚖  
 ├─ ⏱ 1h 27' 10" 752ms  📋 5762  📄 6     🛠️ 19    🛠️ 24    🖥️ 34    ⚖  
 ├─ ⏱ 1h 28' 12" 446ms  📋 5818  📄 8     🛠️ 19    🛠️ 20    🖥️ 25    ⚖  
 ├─ ⏱ 1h 29' 16" 282ms  📋 5879  📄 3     🛠️ 19    🛠️ 8     🖥️ 35    ⚖  
 ├─ ⏱ 1h 30' 16" 349ms  📋 5942  📄 6     🛠️ 19    🛠️ 6     🖥️ 20    ⚖  
 ├─ ⏱ 1h 31' 16" 579ms  📋 6002  📄 7     🛠️ 19    🛠️ 3     🖥️ 39    ⚖  
 ├─ ⏱ 1h 32' 17" 150ms  📋 6069  📄 9     🛠️ 18    🛠️ 33    🖥️ 46    ⚖  
 ├─ ⏱ 1h 33' 18" 42ms  📋 6134  📄 3     🛠️ 18    🛠️ 19    🖥️ 14    ⚖  
 ├─ ⏱ 1h 34' 18" 185ms  📋 6199  📄 8     🛠️ 18    🛠️ 17    🖥️ 28    ⚖  
 ├─ ⏱ 1h 35' 18" 644ms  📋 6264  📄 4     🛠️ 18    🛠️ 6     🖥️ 30    ⚖  
 ├─ ⏱ 1h 36' 19" 226ms  📋 6328  📄 8     🛠️ 18    🛠️ 4     🖥️ 37    ⚖  
 ├─ ⏱ 1h 37' 20" 692ms  📋 6414  📄 5     🛠️ 17    🛠️ 33    🖥️ 29    ⚖  
 ├─ ⏱ 1h 38' 20" 771ms  📋 6494  📄 6     🛠️ 17    🛠️ 18    🖥️ 34    ⚖  
 ├─ ⏱ 1h 39' 21" 69ms  📋 6576  📄 2     🛠️ 17    🛠️ 8     🖥️ 34    ⚖  
 ├─ ⏱ 1h 40' 21" 581ms  📋 6658  📄 9     🛠️ 17    🛠️ 3     🖥️ 31    ⚖  
 ├─ ⏱ 1h 41' 22" 349ms  📋 6729  📄 3     🛠️ 16    🛠️ 29    🖥️ 29    ⚖  
 ├─ ⏱ 1h 42' 23" 842ms  📋 6799  📄 4     🛠️ 16    🛠️ 23    🖥️ 21    ⚖  
 ├─ ⏱ 1h 43' 23" 896ms  📋 6870  📄 1     🛠️ 16    🛠️ 13    🖥️ 36    ⚖  
 ├─ ⏱ 1h 44' 24" 179ms  📋 6945  📄 6     🛠️ 16    🛠️ 12    🖥️ 12    ⚖  
 ├─ ⏱ 1h 45' 24" 357ms  📋 7028  📄 2     🛠️ 15    🛠️ 34    🖥️ 21    ⚖  
 ├─ ⏱ 1h 46' 24" 973ms  📋 7084  📄 7     🛠️ 15    🛠️ 29    🖥️ 15    ⚖  
 ├─ ⏱ 1h 47' 25" 770ms  📋 7148  📄 4     🛠️ 15    🛠️ 23    🖥️ 39    ⚖  
 ├─ ⏱ 1h 48' 25" 913ms  📋 7215  📄 5     🛠️ 15    🛠️ 18    🖥️ 17    ⚖  
 ├─ ⏱ 1h 49' 27" 462ms  📋 7283  📄 2     🛠️ 15    🛠️ 7     🖥️ 17    ⚖  
 ├─ ⏱ 1h 50' 27" 550ms  📋 7353  📄 10    🛠️ 15    🛠️ 0     🖥️ 20    ⚖  
 ├─ ⏱ 1h 51' 30" 881ms  📋 7416  📄 10    🛠️ 15    🛠️ 7     🖥️ 24    ⚖  
 ├─ ⏱ 1h 52' 33" 520ms  📋 7477  📄 6     🛠️ 14    🛠️ 28    🖥️ 33    ⚖  
 ├─ ⏱ 1h 53' 34" 149ms  📋 7538  📄 3     🛠️ 14    🛠️ 18    🖥️ 42    ⚖  
 ├─ ⏱ 1h 54' 34" 179ms  📋 7605  📄 8     🛠️ 14    🛠️ 11    🖥️ 38    ⚖  
 ├─ ⏱ 1h 55' 34" 190ms  📋 7676  📄 2     🛠️ 14    🛠️ 3     🖥️ 3     ⚖  
 ├─ ⏱ 1h 56' 35" 77ms  📋 7735  📄 2     🛠️ 13    🛠️ 33    🖥️ 24    ⚖  
 ├─ ⏱ 1h 57' 36" 831ms  📋 7788  📄 8     🛠️ 13    🛠️ 33    🖥️ 15    ⚖  
 ├─ ⏱ 1h 58' 36" 889ms  📋 7845  📄 7     🛠️ 13    🛠️ 29    🖥️ 4     ⚖  
 ├─ ⏱ 1h 59' 37" 280ms  📋 7899  📄 8     🛠️ 13    🛠️ 22    🖥️ 44    ⚖  
 ├─ ⏱ 2h 37" 509ms    📋 7957  📄 6     🛠️ 13    🛠️ 15    🖥️ 36    ⚖  
 ├─ ⏱ 2h 1' 37" 557ms  📋 8018  📄 2     🛠️ 13    🛠️ 4     🖥️ 2     ⚖  
 ├─ ⏱ 2h 2' 37" 681ms  📋 8075  📄 2     🛠️ 12    🛠️ 34    🖥️ 23    ⚖  
 ├─ ⏱ 2h 3' 38" 478ms  📋 8143  📄 8     🛠️ 12    🛠️ 34    🖥️ 28    ⚖  
 ├─ ⏱ 2h 4' 41" 110ms  📋 8208  📄 9     🛠️ 12    🛠️ 29    🖥️ 17    ⚖  
 ├─ ⏱ 2h 5' 42" 366ms  📋 8271  📄 6     🛠️ 12    🛠️ 19    🖥️ 17    ⚖  
 ├─ ⏱ 2h 6' 42" 597ms  📋 8343  📄 8     🛠️ 12    🛠️ 14    🖥️ 2     ⚖  
 ├─ ⏱ 2h 7' 42" 842ms  📋 8405  📄 10    🛠️ 12    🛠️ 14    🖥️ 39    ⚖  
 ├─ ⏱ 2h 8' 42" 921ms  📋 8477  📄 5     🛠️ 12    🛠️ 0     🖥️ 25    ⚖  
 ├─ ⏱ 2h 9' 43" 469ms  📋 8562  📄 8     🛠️ 11    🛠️ 21    🖥️ 31    ⚖  
 ├─ ⏱ 2h 10' 44" 249ms  📋 8654  📄 2     🛠️ 11    🛠️ 10    🖥️ 32    ⚖  
 ├─ ⏱ 2h 11' 44" 988ms  📋 8733  📄 3     🛠️ 11    🛠️ 3     🖥️ 11    ⚖  
 ├─ ⏱ 2h 12' 46" 490ms  📋 8813  📄 5     🛠️ 10    🛠️ 34    🖥️ 2     ⚖  
 ├─ ⏱ 2h 13' 46" 956ms  📋 8888  📄 10    🛠️ 10    🛠️ 26    🖥️ 8     ⚖  
 ├─ ⏱ 2h 14' 47" 464ms  📋 8964  📄 3     🛠️ 10    🛠️ 16    🖥️ 5     ⚖  
 ├─ ⏱ 2h 15' 48" 27ms  📋 9039  📄 10    🛠️ 10    🛠️ 23    🖥️ 2     ⚖  
 ├─ ⏱ 2h 16' 48" 892ms  📋 9124  📄 4     🛠️ 10    🛠️ 1     🖥️ 38    ⚖  
 ├─ ⏱ 2h 17' 49" 311ms  📋 9185  📄 7     🛠️ 9     🛠️ 29    🖥️ 43    ⚖  
 ├─ ⏱ 2h 18' 49" 509ms  📋 9248  📄 4     🛠️ 9     🛠️ 23    🖥️ 1     ⚖  
 ├─ ⏱ 2h 19' 49" 698ms  📋 9314  📄 5     🛠️ 9     🛠️ 18    🖥️ 15    ⚖  
 ├─ ⏱ 2h 20' 50" 382ms  📋 9379  📄 8     🛠️ 9     🛠️ 15    🖥️ 13    ⚖  
 ├─ ⏱ 2h 21' 50" 882ms  📋 9454  📄 5     🛠️ 9     🛠️ 4     🖥️ 22    ⚖  
 ├─ ⏱ 2h 22' 53" 984ms  📋 9516  📄 9     🛠️ 9     🛠️ 2     🖥️ 46    ⚖  
 ├─ ⏱ 2h 23' 56" 984ms  📋 9577  📄 6     🛠️ 8     🛠️ 28    🖥️ 13    ⚖  
 ├─ ⏱ 2h 24' 57" 363ms  📋 9638  📄 3     🛠️ 8     🛠️ 18    🖥️ 27    ⚖  
 ├─ ⏱ 2h 25' 57" 630ms  📋 9703  📄 2     🛠️ 8     🛠️ 11    🖥️ 27    ⚖  
 ├─ ⏱ 2h 26' 58" 831ms  📋 9776  📄 2     🛠️ 8     🛠️ 3     🖥️ 17    ⚖  
 ├─ ⏱ 2h 28' 2" 113ms  📋 9836  📄 8     🛠️ 8     🛠️ 3     🖥️ 34    ⚖  
 ├─ ⏱ 2h 29' 2" 482ms  📋 9891  📄 3     🛠️ 7     🛠️ 28    🖥️ 19    ⚖  
 ├─ ⏱ 2h 30' 3" 510ms  📋 9947  📄 5     🛠️ 7     🛠️ 23    🖥️ 41    ⚖  
 ├─ ⏱ 2h 31' 5" 956ms  📋 10002 📄 6     🛠️ 7     🛠️ 20    🖥️ 39    ⚖  
 ├─ ⏱ 2h 32' 9" 516ms  📋 10064 📄 2     🛠️ 7     🛠️ 10    🖥️ 4     ⚖  
 ├─ ⏱ 2h 33' 9" 608ms  📋 10125 📄 2     🛠️ 7     🛠️ 3     🖥️ 35    ⚖  
 ├─ ⏱ 2h 34' 9" 664ms  📋 10186 📄 8     🛠️ 7     🛠️ 3     🖥️ 43    ⚖  
 ├─ ⏱ 2h 35' 10" 294ms  📋 10249 📄 3     🛠️ 6     🛠️ 27    🖥️ 40    ⚖  
 ├─ ⏱ 2h 36' 10" 599ms  📋 10313 📄 6     🛠️ 6     🛠️ 25    🖥️ 2     ⚖  
 ├─ ⏱ 2h 37' 10" 751ms  📋 10377 📄 7     🛠️ 6     🛠️ 15    🖥️ 8     ⚖  
 ├─ ⏱ 2h 38' 11" 385ms  📋 10442 📄 10    🛠️ 6     🛠️ 20    🖥️ 41    ⚖  
 ├─ ⏱ 2h 39' 12" 468ms  📋 10509 📄 3     🛠️ 6     🛠️ 0     🖥️ 34    ⚖  
 ├─ ⏱ 2h 40' 13" 182ms  📋 10591 📄 3     🛠️ 5     🛠️ 29    🖥️ 4     ⚖  
 ├─ ⏱ 2h 41' 14" 833ms  📋 10682 📄 2     🛠️ 5     🛠️ 18    🖥️ 30    ⚖  
 ├─ ⏱ 2h 42' 15" 131ms  📋 10784 📄 2     🛠️ 5     🛠️ 8     🖥️ 16    ⚖  
 ├─ ⏱ 2h 43' 15" 906ms  📋 10886 📄 2     🛠️ 4     🛠️ 33    🖥️ 28    ⚖  
 ├─ ⏱ 2h 44' 16" 202ms  📋 10963 📄 8     🛠️ 4     🛠️ 34    🖥️ 17    ⚖  
 ├─ ⏱ 2h 45' 17" 378ms  📋 11039 📄 8     🛠️ 4     🛠️ 25    🖥️ 11    ⚖  
 ├─ ⏱ 2h 46' 18" 553ms  📋 11121 📄 10    🛠️ 4     🛠️ 16    🖥️ 11    ⚖  
 ├─ ⏱ 2h 47' 18" 609ms  📋 11198 📄 8     🛠️ 4     🛠️ 10    🖥️ 25    ⚖  
 ├─ ⏱ 2h 48' 21" 122ms  📋 11269 📄 10    🛠️ 4     🛠️ 10    🖥️ 41    ⚖  
 ├─ ⏱ 2h 49' 21" 622ms  📋 11331 📄 3     🛠️ 3     🛠️ 24    🖥️ 43    ⚖  
 ├─ ⏱ 2h 50' 23" 187ms  📋 11396 📄 9     🛠️ 3     🛠️ 25    🖥️ 16    ⚖  
 ├─ ⏱ 2h 51' 26" 896ms  📋 11459 📄 2     🛠️ 3     🛠️ 10    🖥️ 47    ⚖  
 ├─ ⏱ 2h 52' 27" 897ms  📋 11526 📄 8     🛠️ 3     🛠️ 10    🖥️ 34    ⚖  
 ├─ ⏱ 2h 53' 28" 16ms  📋 11594 📄 7     🛠️ 2     🛠️ 35    🖥️ 21    ⚖  
 ├─ ⏱ 2h 54' 30" 530ms  📋 11655 📄 2     🛠️ 2     🛠️ 26    🖥️ 47    ⚖  
 ├─ ⏱ 2h 55' 30" 815ms  📋 11716 📄 9     🛠️ 2     🛠️ 22    🖥️ 25    ⚖  
 ├─ ⏱ 2h 56' 30" 990ms  📋 11779 📄 3     🛠️ 2     🛠️ 14    🖥️ 22    ⚖  
 ├─ ⏱ 2h 57' 31" 714ms  📋 11849 📄 5     🛠️ 2     🛠️ 10    🖥️ 22    ⚖  
 ├─ ⏱ 2h 58' 32" 999ms  📋 11914 📄 10    🛠️ 2     🛠️ 0     🖥️ 15    ⚖  
 ├─ ⏱ 2h 59' 33" 450ms  📋 11969 📄 4     🛠️ 1     🛠️ 31    🖥️ 44    ⚖  
 ├─ ⏱ 3h 33" 717ms    📋 12023 📄 2     🛠️ 1     🛠️ 24    🖥️ 9     ⚖  
 ├─ ⏱ 3h 1' 34" 713ms  📋 12079 📄 3     🛠️ 1     🛠️ 19    🖥️ 26    ⚖  
 ├─ ⏱ 3h 2' 34" 820ms  📋 12139 📄 6     🛠️ 1     🛠️ 17    🖥️ 38    ⚖  
 ├─ ⏱ 3h 3' 35" 856ms  📋 12194 📄 6     🛠️ 1     🛠️ 11    🖥️ 37    ⚖  
 ├─ ⏱ 3h 4' 40" 564ms  📋 12258 📄 7     🛠️ 1     🛠️ 8     🖥️ 22    ⚖  
 ├─ ⏱ 3h 5' 40" 786ms  📋 12324 📄 7     🛠️ 1     🛠️ 2     🖥️ 1     ⚖  
 ├─ ⏱ 3h 6' 42" 349ms  📋 12389 📄 8     🛠️ 0     🛠️ 29    🖥️ 32    ⚖  
 ├─ ⏱ 3h 7' 42" 787ms  📋 12456 📄 4     🛠️ 0     🛠️ 17    🖥️ 30    ⚖  
 ├─ ⏱ 3h 8' 42" 955ms  📋 12519 📄 4     🛠️ 0     🛠️ 11    🖥️ 14    ⚖  
 ├─ ⏱ 3h 9' 43" 56ms  📋 12586 📄 2     🛠️ 0     🛠️ 3     🖥️ 26    ⚖  
 ├─ ⏱ 3h 10' 50" 755ms  📋 12600 📄 6     🛠️ 0     🛠️ 1     🖥️ 39    ⚖  
 ├─ ⏱ 3h 11' 54" 997ms  📋 12600 📄 10    🛠️ 0     🛠️ 2     🖥️ 2     ⚖  
 ├─ 📑  Ficheiro Resultados/TorneioHeuristica.csv gravado.
 │  ⏱  Tempo real: 3h 12' 6" 246ms 
 │  ⏱  CPU total: 6d 6h 28' 53" 564ms 
 │  ⏱  Espera do gestor: 3h 12' 6" 3ms 
 │  ⏱  Espera trabalhadores: 1h 11' 22" 830ms 
 │  📊  Utilização:
 │  - Total: 97.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 3h 12' 6" 249ms ) ═══
</pre>
\endhtmlonly
</details>

Temos resultados de várias instâncias, a variar pelos dois parâmetros que afetam as heurísticas.

Cada instância tem neste caso parâmetros ideais, pelo que vamos primeiro apresentar os resultados por instância:

| Instância | Vitória Preta | Empate | Vitória Branca |
|:---:|:---:|:---:|:---:|
| 1 | |  1260 | | 
| 2 | |  1260 | | 
| 3 | |  1224 | 36 |
| 4 | 593 | 110 | 557 |
| 5 | 595 | |  665 |
| 6 | 18 | 1161 | 81 |
| 7 | 214 | 529 | 517 |
| 8 | 168 | 782 | 310 |
| 9 | 84 | 1079 | 97 |
| 10 | 195 | 798 | 267 |
| Total Geral | 1867 | 8203 | 2530 |

Podemos agora observar que apenas os dois primeiros jogos aparentam atualmente estar empatados, mesmo assumindo
uma heurística fraca contra uma forte. No entanto as duas últimas instâncias que até aqui aparentavam acabar sempre em empates,
mostram agora vários jogos que não terminaram em empate.

Nas instâncias 3 a 10 temos a melhor configuração para cada instância, a jogar de brancas e de pretas, bem como a sua eficácia no torneio:

| Instância | melhor Brancas | melhor Pretas | Eficácia Branca | Eficácia Preta |
|:---:|:---:|:---:|:---:|:---:|
| 3 | P15=300 | P15!=150 | 59% | 50% |
| 4 |  P15=400  |  P15=150 P16=20  |  83%  |  94% |
| 5 |  P15=300 P16=10  |  P15=150  |  83%  |  83% |
| 6 |  P15=800 P16=100  |  P15=300  |  63%  |  53% |
| 7 |  P15=400  |  P15=300  |  100%  |  51% |
| 8 |  P15=300  |  P15=300  |  73%  |  63% |
| 9 |  P15=200  |  P15=150  |  66%  |  57% |
| 10 |  P15=800 P16=500  |  P15=300 P16=10  |  73%  |  64% |

Podemos observar que:
- a heurística e principalmente o parâmetro P15, tem forte impacto na eficácia, caso contrário existiriam apenas valores a rondar os 50%
- a melhor configuração de brancas e pretas nem sempre coincide, é até raro que coincida
- na instância 7 uma das configurações ganha todos os jogos de brancas contra qualquer outra configuração de pretas
- nem sempre o jogador de brancas tem a melhor configuração, por vezes é igual às pretas, outras vezes as pretas são melhores, como é o caso da instância 4
- alguns jogos a melhor configuração tem uma eficácia baixa, como é o caso da instância 3

O facto da configuração de pretas ser mais modesta na valorização das ameaças imediatas, ficando por vezes com 150,
quando as brancas utilizam sempre valores de 200 para cima, pode significar que a vantagem de jogar de brancas, de modo
a ter mais hipóteses de converter em vitória, tem que se dar maior importância às ameaças curtas, mas para a defesa
é preferivel algo mais modesto. 

A eficácia foi utilizada com base nas outras configurações. Para afinar este valor podemos fazer novo torneio, com apenas configujrações boas,
ou com os parâmetros a variarem ligeiramente do melhor valor encontrado.
Nesse caso a eficácia reduz-se, mas é possível apurar com mais detalhe a melhor configuração para cada instância, eventualmente
executando vários jogos e não apenas um, entre cada par de instâncias.

Vamos no entanto ficar por aqui, já que estas configurações são já suficientes para ilustrar este processo, e avançamos para o torneio
poda.

Para simplicidade, em vez de uma configuração por instância, vamos optar por utilizar P15=300 e P16=100 já que é uma configuração que se comportou bem na maior parte das instâncias.


\anchor jel-a7
## Ação 7 - Torneio Poda

Temos dois parâmetros para a poda da árvore de procura. A poda heurística (PODA_HEURISTICA) e a poda cega (PODA_CEGA).
A poda cega é útil para quando há demasiados sucessores poder remover de forma aleatória, de modo a poder existir exploração.
Mas neste caso na maior instância tem 12 de lado, sendo o maior número de sucessores é 121.
Assim vamos testar apenas a poda heurística.

Vamos utilizar duas sementes, de modo a aumentar o número de jogos e reduzir o impacto da aleatoriedade.

- **Tipo de Teste / Objetivo**: Eficácia (PODA_HEURISTICA)
- **Definição**: Instâncias: 1:10; Configurações: P7=0 P1=2 P12=1 P11=1 P15=300 P16=100 P13=0,4,8,16,32
- **Esforço**: P3=1:2
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioPoda -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=300 P16=100 P3=1:2 x P13=0,4,8,16,32

<details>
  <summary>Ver script: torneioPoda.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=torneioPoda
#SBATCH --output=Resultados/torneioPoda.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioPoda
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioPoda -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=300 P16=100 P3=1:2 x P13=0,4,8,16,32
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>


</pre>
\endhtmlonly
</details>

(refazer)
Os resultados do torneio são os seguintes:

EficáciaBranco 

| P13  | - | 4 | 8 | 16 | 32 |
|:---:|---:|---:|---:|---:|---:|
| - | 0,45 | 0,59 | 0,45 | 0,53 | 0,51 |
| 4 | 0,46 | 0,6 | 0,55 | 0,4 | 0,46 |
| 8 | 0,41 | 0,61 | 0,45 | 0,43 | 0,45 |
| 16 | 0,5 | 0,63 | 0,43 | 0,4 | 0,5 |
| 32 | 0,44 | 0,58 | 0,43 | 0,51 | 0,48 |

EficáciaPreto

| P13  | - | 4 | 8 | 16 | 32 |
|:---:|---:|---:|---:|---:|---:|
| - | 0,55 | 0,41 | 0,55 | 0,48 | 0,49 |
| 4 | 0,54 | 0,4 | 0,45 | 0,6 | 0,54 |
| 8 | 0,59 | 0,39 | 0,55 | 0,58 | 0,55 |
| 16 | 0,5 | 0,38 | 0,58 | 0,6 | 0,5 |
| 32 | 0,56 | 0,43 | 0,58 | 0,49 | 0,53 |

Nas linhas está o valor da poda branca, nas colunas o valor da poda preta.
O conteúdo das tabelas é a eficácia do jogador branco e preto respetivamente.

Embora para as brancas o valor 16 pareça ser o melhor, face a jogador preto sem poda,
é apenas 5%, e para as pretas o valor sem poda é o melhor contra branco sem poda.

No global as alterações são pequenas, e não parecem justificar o uso da poda heurística.
Mesmo considerando apenas instâncias maiores, o impacto é superior mas oscilante, o que pode signicificar que
as diferenças são devido à aleatoriedade dos jogos, e não da variaçáo do parâmetro P13.

Assim sendo, vamos manter o valor da poda heurística a 0, ou seja, sem poda.


\anchor jel-a8
## Ação 8 - Torneio Ruido

Vamos agora estudar o efeito do ruído na heurística. Esperamos uma degradação da força de jogo, à medida que o ruído aumenta.
É importante quantificar este efeito, para podermos escolher valores adequados a diferentes níveis de jogo.


- **Tipo de Teste / Objetivo**: Eficácia (RUÍDO)
- **Definição**: Instâncias: 1:10; Configurações: P7=0 P1=2 P12=1 P11=1 P15=100,1000 x P13=0,4,8,16,32
- **Esforço**: (um só jogo)
- **Execução**: TProcuraAdversa 2 1:10 -R Resultados/TorneioPoda -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=100,1000 x P13=0,4,8,16,32
-

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


... (estudar o efeito do ruído)


<details>
  <summary>Ver script: torneioRuido.sh</summary>
<pre>

</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>

</pre>
\endhtmlonly
</details>




\anchor jel-a9
## Ação 9 - Torneio Níveis

Estando identificadas as variáveis críticas de desempenho estamos em condições de identificar configurações com diferentes níveis de força de jogo.

Pretendemos que a diferença de força de jogo entre níveis consecutivos, seja significativa e constante,
idealmente com 3 pontos em 4 jogos, ou seja, 75%.

Desta forma podemos ter diferentes níveis de jogo para diferentes dificuldades que o jogador humano pretender enfrentar,
podendo optar por um adversário artificial adequado à sua força de jogo atual. 

Um torneio entre os diferentes níveis deve portanto confirmar esta hipótese 75% de vitórias contra o nível imediatamente inferior.

O número de níveis tem de ir desde o jogador aleatório até à configuração mais forte encontrada nas ações anteriores.

<details>
  <summary>Ver script: torneioNiveis.sh</summary>
<pre>

</pre>
</details>
<details>
  <summary>Ver execução:</summary>
\htmlonly
<pre>

</pre>
\endhtmlonly
</details>



