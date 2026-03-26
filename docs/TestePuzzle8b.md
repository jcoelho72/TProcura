@page teste_puzzle8b 💻 Puzzle 8 - Procuras Informadas

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_construtivas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Construtivas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="opacity:0.7;">Algoritmos Cegos ›</span>
    <a href="tutorial_construtivaslit.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_construtivas3a.html" style="color:#9cf;">👓 Procura Cega</a>
    <a href="tutorial_construtivas3b.html" style="color:#9cf;">👓 Algoritmos</a>
    <span style="opacity:0.7;">Aspirador ›</span>
    <a href="teste_aspirador1.html" style="color:#9cf;">💻 Parte 1</a>
    <a href="teste_aspirador2.html" style="color:#9cf;">💻 Parte 2</a>
    <span style="opacity:0.7;">Puzzle 8 ›</span>
    <a href="tutorial_puzzle8prof.html" style="color:#9cf;">✏️ Profundidade</a>
    <a href="tutorial_puzzle8iterativa.html" style="color:#9cf;">✏️ Iterativa</a>
    <a href="tutorial_puzzle8largura.html" style="color:#9cf;">✏️ Largura</a>
    <a href="teste_puzzle8.html" style="color:#9cf;">💻 Testar</a>
    <span style="opacity:0.7;">Partição ›</span>
    <a href="tutorial_particaoprof.html" style="color:#9cf;">✏️ Profundidade</a>
    <a href="tutorial_particaolargura.html" style="color:#9cf;">✏️ Largura</a>
    <a href="teste_particao.html" style="color:#9cf;">💻 Testar</a>
    <span style="opacity:0.7;">Damas ›</span>
    <a href="tutorial_4damasprof.html" style="color:#9cf;">✏️ Profundidade</a>
    <a href="tutorial_4damaslargura.html" style="color:#9cf;">✏️ Largura</a>
    <a href="teste_8damas.html" style="color:#9cf;">💻 Testar</a>
    <span style="opacity:0.7;">Algoritmos Informados ›</span>
    <a href="tutorial_construtivaslit2.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_construtivas4a.html" style="color:#9cf;">👓 Procura Informada</a>
    <span style="opacity:0.7;">Puzzle 8 ›</span>
    <a href="tutorial_puzzle8melhor.html" style="color:#9cf;">✏️ Melhor Primeiro</a>
    <a href="tutorial_puzzle8astar.html" style="color:#9cf;">✏️ A-star</a>
    <a href="tutorial_puzzle8bnb.html" style="color:#9cf;">✏️ BnB</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">💻 Testar</span>
  </div>
</div>

\endhtmlonly

Execução de exemplo com base no problema do Puzzle 8.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraConstrutiva, e execute.
No Linux na pasta `.../TProcura/Construtiva/Teste$` execute `make` seguido de `./bin/Release/TProcuraConstrutiva`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#puzzle8-a1)
- [Ação 2 - Resolver manualmente](#puzzle8-a2)
- [Ação 3 - Procura em Largura](#puzzle8-a3)
- [Ação 4 - Procura em Profundidade](#puzzle8-a4)
- [Ação 5 - Heurística](#puzzle8b-a5)
- [Ação 6 - Melhor Primeiro](#puzzle8b-a6)
- [Ação 7 - AStar](#puzzle8b-a7)
- [Ação 8 - IDAStar](#puzzle8b-a8)
- [Ação 9 - Branch-and-Bound](#puzzle8b-a9)
- [Ação 10 - Testes Empíricos](#puzzle8b-a10)



\anchor puzzle8b-a5
## Ação 5 - Heurística

Neste problema foi implementada a heurística com a distância na horizontal e vertical,
de cada peça até à sua posição final.
Esta heurística relaxa a situação de apenas ser possível mover para o local onde está o espaço, e 
retorna o valor que seria o correto caso cada peça pudesse mover-se por cima das outras.
É implementada no problema ao redefinir CPuzzle8::Heuristica().

Vamos começar por ver (notar que P6(VER_ACOES): 1 e P3(SEMENTE): 2).
Introduza: **1; 40; 2; dir baixo; *ENTER*.**


\htmlonly
<pre>
Opção: <span class="entrada">2</span>
═╤═ 💰 g:0 🎯 h:12 ⚖  1|4|5 ═══
 │  4  7  3 
 │  1  .  2 
 │  6  8  5 
 │  ├■═╤═ 💰 g:1 🎯 h:11 ⚖  1|4|5 ═══ baixo
 │  │  4  .  3 
 │  │  1  7  2 
 │  │  6  8  5 
 │  ├■═╤═ 💰 g:1 🎯 h:13 ⚖  1|4|5 ═══ cima
 │  │  4  7  3 
 │  │  1  8  2 
 │  │  6  .  5 
 │  ├■═╤═ 💰 g:1 🎯 h:11 ⚖  1|4|5 ═══ dir
 │  │  4  7  3 
 │  │  .  1  2 
 │  │  6  8  5 
 │  └■═╤═ 💰 g:1 🎯 h:13 ⚖  1|4|5 ═══ esq
 │     4  7  3 
 │     1  2  . 
 │     6  8  5 
🔍 Sucessor [1-4, ação(ões), exe]: <span class="entrada">dir baixo</span>
┌─ ✔  ────────────────
│ Executadas 2 ações. 
└─────────────────────
═╤═ 💰 g:0 🎯 h:10 ⚖  4|13|8 ═══
 │  .  7  3 
 │  4  1  2 
 │  6  8  5 
 │  ├■═╤═ 💰 g:1 🎯 h:11 ⚖  4|13|8 ═══ cima
 │  │  4  7  3 
 │  │  .  1  2 
 │  │  6  8  5 
 │  └■═╤═ 💰 g:1 🎯 h:11 ⚖  4|13|8 ═══ esq
 │     7  .  3 
 │     4  1  2 
 │     6  8  5 
🔍 Sucessor [1-2, ação(ões), exe]: <span class="entrada">↵</span>
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 2
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ascendentes | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 │  .  7  3 
 │  4  1  2 
 │  6  8  5 
...
Opção: 
</pre>
\endhtmlonly

Na informação de um estado, vemos não apenas o valor de g (o custo), mas também o valor de h.
O valor de h é a heuristica, que idealmente é uma estimativa conservadora da distância até ao objetivo.

No estado inicial a heurística é 12, porque:
- os números 2, 5, 8 estão a distância 1
- os números 1, 4, 7 estã à distância 2
- o número 3 está à distância 3

O total será 3 + 6 + 3 = 12.

Vamos ver como esta heurística guia os diferentes algoritmos informados.

\anchor puzzle8b-a6
## Ação 6 - Melhor Primeiro

Vamos executar o primeiro algoritmo informado, o melhor primeiro, que segue sempre pelo ramo 
com menor heurística, ou seja, mais perto do objetivo, daí o nome de melhor primeiro.

Este é um algoritmo em profundidade pelo que vamos deixar a configuração de remoção de estados
repetidos gerados, de modo a observar o desempenho deste algoritmo nas melhores condições.

Neste e em outras execuções das procuras informadas, vamos limitar o número de avaliações (iterações) a 1000000, 
de modo a ter um critério de paragem independente do tempo.

Introduza: **1; 40; 3; 1; 4; 2; 3; 5; 1000000; 6; 4; 8; 3; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0 🎯 h:10  ═══
 │  ├■═╤═ 🔖 1 💰 g:1 🎯 h:11 ⚖  1|4|4 ═══ ⚡ baixo
 │  │  ├■═╤═ 🔖 5 💰 g:2 🎯 h:10 ⚖  2|6|6 ═══ ⚡ dir
 │  │  │  └■═╤═ 🔖 7 💰 g:3 🎯 h:9 ⚖  3|7|7 ═══ ⚡ cima
 │  │  │     ├■═╤═ 🔖 8 💰 g:4 🎯 h:10 ⚖  4|9|9 ═══ ⚡ cima
 │  │  │     │  └■═╤═ 🔖 10 💰 g:5 🎯 h:11 ⚖  5|10|10 ═══ ⚡ esq
 │  │  │     │     ├■═╤═ 🔖 11 💰 g:6 🎯 h:10 ⚖  6|12|12 ═══ ⚡ baixo
 │  │  │     │     │  ├■═╤═ 🔖 13 💰 g:7 🎯 h:9 ⚖  7|15|15 ═══ ⚡ baixo
 │  │  │     │     │  │  ├■═╤═ 🔖 16 💰 g:8 🎯 h:8 ⚖  8|17|17 ═══ ⚡ dir
 │  │  │     │     │  │  │  └■═╤═ 🔖 18 💰 g:9 🎯 h:9 ⚖  9|18|18 ═══ ⚡ cima
 │  │  │     │     │  │  │     ├■═╤═ 🔖 19 💰 g:10 🎯 h:10 ⚖  10|20|20 ═══ ⚡ cima
...
...│  │  │     │     │  │  │  🎯  Solução encontrada! 💰 g:70
...
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>4 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>3 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   7ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Melhor Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 2
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(VER_ACOES):</span> 4
│ <span style="color:gray">P7(LIMITE):</span> 0 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> gerados | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 .  1  2 
 3  4  5 
 6  7  8 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 70 | <span style="color:gray">I2(Tempo(ms)):</span> 7 | <span style="color:gray">I3(Iterações):</span> 128 | <span style="color:gray">I4(IND_EXPANSOES):</span> 70 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 128 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Conseguimos uma solução de 70 ações, utilizando 70 expansões.
O output teve de ser cortado não pelo número de expansões mas pela profundidade.
O resultado em termos de esforço computacional é muito reduzido, pelo que a informação 
dada pela heurística foi útil. No entanto, a qualidade da solução baixa, já que fica com
70 de custo, quando sabemos existir uma solução de custo 12. 

\anchor puzzle8b-a7
## Ação 7 - AStar

Vamos agora ver o comportamento do AStar, que garante a solução ótima. 

Introduza: **1; 40; 3; 1; 5; 2; 4; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0 🎯 h:10  ═══ { } 
 │  4  7  3 
 │  1  .  2 
 │  6  8  5 
 │ └─ ⚡  ──── baixo cima dir esq { 🔖 1 🔖 2 🔖 3 🔖 4 } 
 ├■═╤═ 🔖 1 💰 g:1 🎯 h:11 ⚖  1|4|4 ═══ { 🔖 3 🔖 2 🔖 4 } 
 │  4  .  3 
 │  1  7  2 
 │  6  8  5 
 │ └─ ⚡  ──── dir esq { 🔖 5 🔖 6 } 
 ├■═╤═ 🔖 6 💰 g:2 🎯 h:10 ⚖  2|6|6 ═══ { 🔖 5 🔖 3 🔖 2 🔖 4 } 
 │  4  3  . 
 │  1  7  2 
 │  6  8  5 
 │ └─ ⚡  ──── cima { 🔖 7 } 
 ├■═╤═ 🔖 7 💰 g:3 🎯 h:9 ⚖  3|7|7 ═══ { 🔖 5 🔖 3 🔖 2 🔖 4 } 
 │  4  3  2 
 │  1  7  . 
 │  6  8  5 
 │ └─ ⚡  ──── cima dir { 🔖 8 🔖 9 } 
 ├■═╤═ 🔖 8 💰 g:4 🎯 h:8 ⚖  4|9|9 ═══ { 🔖 5 🔖 3 🔖 2 🔖 9 🔖 4 } 
 │  4  3  2 
 │  1  7  5 
 │  6  8  . 
 │ └─ ⚡  ──── dir { 🔖 10 } 
 ├■═╤═ 🔖 10 💰 g:5 🎯 h:7 ⚖  5|10|10 ═══ { 🔖 5 🔖 3 🔖 2 🔖 9 🔖 4 } 
 │  4  3  2 
 │  1  7  5 
 │  6  .  8 
 │ └─ ⚡  ──── baixo dir { 🔖 11 🔖 12 } 
 ├■═╤═ 🔖 11 💰 g:6 🎯 h:6 ⚖  6|12|12 ═══ { 🔖 5 🔖 3 🔖 2 🔖 12 🔖 9 🔖 4 } 
 │  4  3  2 
 │  1  .  5 
 │  6  7  8 
 │ └─ ⚡  ──── baixo dir esq { 🔖 13 🔖 14 🔖 15 } 
 ├■═╤═ 🔖 14 💰 g:7 🎯 h:5 ⚖  7|15|15 ═══ { 🔖 13 🔖 5 🔖 3 🔖 2 🔖 15 🔖 12 🔖 9 🔖 4 } 
 │  4  3  2 
 │  .  1  5 
 │  6  7  8 
 │ └─ ⚡  ──── baixo cima { 🔖 16 🔖 17 } 
 ├■═╤═ 🔖 16 💰 g:8 🎯 h:4 ⚖  8|17|17 ═══ { 🔖 13 🔖 5 🔖 3 🔖 2 🔖 17 🔖 15 🔖 12 🔖 9 🔖 4 } 
 │  .  3  2 
 │  4  1  5 
 │  6  7  8 
 │ └─ ⚡  ──── esq { 🔖 18 } 
 ├■═╤═ 🔖 18 💰 g:9 🎯 h:3 ⚖  9|18|18 ═══ { 🔖 13 🔖 5 🔖 3 🔖 2 🔖 17 🔖 15 🔖 12 🔖 9 🔖 4 } 
 │  3  .  2 
 │  4  1  5 
 │  6  7  8 
 │ └─ ⚡  ──── cima esq { 🔖 19 🔖 20 } 
 ├■═╤═ 🔖 19 💰 g:10 🎯 h:2 ⚖  10|20|20 ═══ { 🔖 13 🔖 5 🔖 3 🔖 2 🔖 20 🔖 17 🔖 15 🔖 12 🔖 9 🔖 4 } 
 │  3  1  2 
 │  4  .  5 
 │  6  7  8 
 │ └─ ⚡  ──── cima dir esq { 🔖 21 🔖 22 🔖 23 } 
 ├■═╤═ 🔖 22 💰 g:11 🎯 h:1 ⚖  11|23|23 ═══ { 🔖 13 🔖 5 🔖 3 … 🔖 12 🔖 9 🔖 4 } #12
 │  3  1  2 
 │  .  4  5 
 │  6  7  8 
 │ └─ ⚡  ──── baixo cima { 🔖 24 🔖 25 } 
 ├■═╤═ 🔖 24 💰 g:12 ⚖  12|25|25 ═══ { 🔖 13 🔖 5 🔖 3 … 🔖 12 🔖 9 🔖 4 } #13
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 │  🎯  Solução encontrada! 💰 g:12
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>5 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>3 <span style="color:gray">P9=</span>100 <span style="color:gray">P10=</span>0 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> A* | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 2 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> gerados
│ <span style="color:gray">P9(PESO_ASTAR):</span> 100 | <span style="color:gray">P10(RUIDO_HEURISTICA):</span> 0 | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 .  1  2 
 3  4  5 
 6  7  8 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 12 | <span style="color:gray">I2(Tempo(ms)):</span> 1 | <span style="color:gray">I3(Iterações):</span> 25 | <span style="color:gray">I4(IND_EXPANSOES):</span> 12 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 25 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Foram utilizadas 12 expansões para obter a solução ótima de 12 movimentos.
Notar na lista ordenada, um dos piores estados é o estado 4, gerado no início, mas nem por isso
foi expandido, já que tinha um mau valor heurístico. Como colocamos P6(VER_ACOES): 4, não vemos os estados gerados,
colocando a 1 já poderiamos confirmar o motivo para que este estado permaneça no final da lista de estados gerados não expandidos.

Esta é uma instância simples para este algoritmo.

\anchor puzzle8b-a8
## Ação 8 - IDAStar

O AStar pode ter problemas de memória em instâncias complexas, existindo o IDAStar que permite a mesma ordem
de expansão, mas sem o problema de memória, em troca de algum tempo de CPU extra, gasto ao expandir multiplas
vezes os mesmos estados. Vamos ver como se comporta nesta instância.

Introduza: **1; 40; 3; 1; 6; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─────────── 🌳 📉  12 ⏱ 1ms  ──────────── 
 ├■═╤═ 💰 g:0 🎯 h:10 ⚖  |1 ═══
 │  4  7  3 
 │  1  .  2 
 │  6  8  5 
 │  ├■═╤═ 🔖 1 💰 g:1 🎯 h:11 ⚖  1|4|5 ═══ ⚡ baixo
 │  │  4  .  3 
 │  │  1  7  2 
 │  │  6  8  5 
 │  │  ├■═╤═ 🔖 5 💰 g:2 🎯 h:10 ⚖  2|6|7 ═══ ⚡ dir
 │  │  │  .  4  3 
 │  │  │  1  7  2 
 │  │  │  6  8  5 
 │  │  │  └■═╤═ 🔖 7 💰 g:3 🎯 h:9 ⚖  3|7|8 ═══ ⚡ cima
 │  │  │     1  4  3 
 │  │  │     .  7  2 
 │  │  │     6  8  5 
 │  │  │     ├─🍃 14 → 📉  { 🔖 8 } 
 │  │  │     └─🍃  { 🔖 9 } 
 │  │  └■═╤═ 🔖 6 💰 g:2 🎯 h:10 ⚖  4|9|10 ═══ ⚡ esq
 │  │     4  3  . 
 │  │     1  7  2 
 │  │     6  8  5 
 │  │     └■═╤═ 🔖 10 💰 g:3 🎯 h:9 ⚖  5|10|11 ═══ ⚡ cima
 │  │        4  3  2 
 │  │        1  7  . 
 │  │        6  8  5 
 │  │        ├■═╤═ 🔖 11 💰 g:4 🎯 h:8 ⚖  6|12|13 ═══ ⚡ cima
 │  │        │  4  3  2 
 │  │        │  1  7  5 
 │  │        │  6  8  . 
 │  │        │  └■═╤═ 🔖 13 💰 g:5 🎯 h:7 ⚖  7|13|14 ═══ ⚡ dir
 │  │        │     4  3  2 
 │  │        │     1  7  5 
 │  │        │     6  .  8 
 │  │        │     ├■═╤═ 🔖 14 💰 g:6 🎯 h:6 ⚖  8|15|16 ═══ ⚡ baixo
 │  │        │     │  4  3  2 
 │  │        │     │  1  .  5 
 │  │        │     │  6  7  8 
 │  │        │     │  ├■═╤═ 🔖 16 💰 g:7 🎯 h:5 ⚖  9|18|19 ═══ ⚡ baixo
 │  │        │     │  │  4  .  2 
 │  │        │     │  │  1  3  5 
 │  │        │     │  │  6  7  8 
 │  │        │     │  │  ├■═╤═ 🔖 19 💰 g:8 🎯 h:4 ⚖  10|20|21 ═══ ⚡ dir
 │  │        │     │  │  │  .  4  2 
 │  │        │     │  │  │  1  3  5 
 │  │        │     │  │  │  6  7  8 
 │  │        │     │  │  │  └■═╤═ 🔖 21 💰 g:9 🎯 h:3 ⚖  11|21|22 ═══ ⚡ cima
 │  │        │     │  │  │     1  4  2 
 │  │        │     │  │  │     .  3  5 
 │  │        │     │  │  │     6  7  8 
 │  │        │     │  │  │     ├■═╤═ 🔖 23 💰 g:10 🎯 h:2 ⚖  12|23|24 ═══ ⚡ esq
 │  │        │     │  │  │     │  1  4  2 
 │  │        │     │  │  │     │  3  .  5 
 │  │        │     │  │  │     │  6  7  8 
 │  │        │     │  │  │     │  ├■═╤═ 🔖 24 💰 g:11 🎯 h:1 ⚖  13|26|27 ═══ ⚡ baixo
 │  │        │     │  │  │     │  │  1  .  2 
 │  │        │     │  │  │     │  │  3  4  5 
 │  │        │     │  │  │     │  │  6  7  8 
 │  │        │     │  │  │     │  │  ├■═╤═ 🔖 27 💰 g:12 ⚖  14|28|29 ═══ ⚡ dir
 │  │        │     │  │  │     │  │  │  .  1  2 
 │  │        │     │  │  │     │  │  │  3  4  5 
 │  │        │     │  │  │     │  │  │  6  7  8 
 │  │        │     │  │  │     │  │  │  🎯  Solução encontrada! 💰 g:12
 │  │        │     │  │  │     │  │  │  .  1  2 
 │  │        │     │  │  │     │  │  │  3  4  5 
 │  │        │     │  │  │     │  │  │  6  7  8 
 │  │        │     │  │  │     │  │  │ 🎯 12 → 📈 
 │  │        │     │  │  │     │  │  └─ { 🔖 28 } 
 │  │        │     │  │  │     │  └─ { 🔖 25 🔖 26 } 
 │  │        │     │  │  │     └─ { 🔖 22 } 
 │  │        │     │  │  └─ { 🔖 20 } 
 │  │        │     │  └─ { 🔖 17 🔖 18 } 
 │  │        │     └─ { 🔖 15 } 
 │  │        └─ { 🔖 12 } 
 │  └─ { 🔖 3 🔖 2 🔖 4 } 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>6 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>3 <span style="color:gray">P9=</span>100 <span style="color:gray">P10=</span>0 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   2ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> IDA* | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 2 | <span style="color:gray">P4(LIMITE_TEMPO):</span> 10
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> gerados
│ <span style="color:gray">P9(PESO_ASTAR):</span> 100 | <span style="color:gray">P10(RUIDO_HEURISTICA):</span> 0 | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 .  1  2 
 3  4  5 
 6  7  8 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 12 | <span style="color:gray">I2(Tempo(ms)):</span> 2 | <span style="color:gray">I3(Iterações):</span> 29 | <span style="color:gray">I4(IND_EXPANSOES):</span> 14 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 28 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 14
└──────────────────────────────────────────────────────────────────────
...
Opção:
</pre>
\endhtmlonly

Podemos ver que em termos de iterações, ao contrário da procura em profundidade iterativa,
tem menos iterações. 

O limite da iteração seguinte é determinado pelo menor valor dos estados
cortados, avançando mais que uma unidade de cada vez.
O primeiro limite é determinado pelo valor da heurística do estado inicial, que neste caso tinha o valor perfeito.

Acabou por ter apenas 14 expansões, enquanto que o AStar utilizou 12 expansões. 

Neste caso como houve uma só iteração, correu bastante bem. Mas mesmo que fosse o dobro das expansões,
é um pequeno preço a pagar por não ter problemas de memória.


\anchor puzzle8b-a9
## Ação 9 - Branch-and-Bound

Vamos agora ver como se comporta o Branch-and-Bound, o último algoritmo informado. 
Este algoritmo pode ser visto como o Melhor Primeiro que continua a procura após a primeira solução.
No entanto restringe o espaço de procura apenas aos estados que melhoram a solução atual.

É um algoritmo em profundidade, pelo que não tem problemas de memória originados na procura em largura.
Vamos baixar o nível de debug para 1.

Introduza: **1; 40; 3; 1; 7; 2; 1; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══#
 ├■ 🎯  Solução encontrada! 💰 g:70
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:68
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:64
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:60
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:52
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 └■ 🎯  Solução encontrada! 💰 g:50
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 #
 └■ 🎯  Solução encontrada! 💰 g:48
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 └■ 🎯  Solução encontrada! 💰 g:46
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 #
 ├■ 🎯  Solução encontrada! 💰 g:42
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:32
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:30
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├■ 🎯  Solução encontrada! 💰 g:28
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 #
 ├■ 🎯  Solução encontrada! 💰 g:24
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 #
 ├■ 🎯  Solução encontrada! 💰 g:12
 │  .  1  2 
 │  3  4  5 
 │  6  7  8 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>7 <span style="color:gray">P2=</span>1 <span style="color:gray">P3=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>4 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>3 <span style="color:gray">P9=</span>100 <span style="color:gray">P10=</span>0 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   17ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Branch and Bound | <span style="color:gray">P2(NIVEL_DEBUG):</span> ATIVIDADE | <span style="color:gray">P3(SEMENTE):</span> 2
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(VER_ACOES):</span> 4
│ <span style="color:gray">P7(LIMITE):</span> 0 | <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> gerados | <span style="color:gray">P9(PESO_ASTAR):</span> 100
│ <span style="color:gray">P10(RUIDO_HEURISTICA):</span> 0 | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 .  1  2 
 3  4  5 
 6  7  8 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 12 | <span style="color:gray">I2(Tempo(ms)):</span> 17 | <span style="color:gray">I3(Iterações):</span> 6666 | <span style="color:gray">I4(IND_EXPANSOES):</span> 4110 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 6666 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 14
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Vemos que primeiramente encontra a solução de 70 movimentos, e depois vai encontrando sucessivamente 
soluções melhores até que termina com a solução de 12. Gasta nesta instância um número 
consideravelmente superior de expansões e gerações, quando comparado com o AStar.

Podemos agora ver outras instâncias, e executar cada um dos algoritmos para ver qual é o melhor.
No entanto seria um trabalho fastidioso.

Não o fazer, ficariamos com a informação da performance dos algoritmos numa só instância, 
não necessariamente representativa de todas as instâncias.

É para melhor medir o desempenho de algoritmos e configurações, que existem os testes empíricos,
permitindo assim comparar algoritmos e/ou configurações num leque alargado de instâncias.

\anchor puzzle8b-a10
## Ação 10 - Testes Empíricos

Vamos agora fazer testes empíricos, para comparar os algoritmos informados. 
As configurações e testes no modo interativo, foram exemplificados no exemplo de teste do TVector. 

Executamos o programa em linha de comando, pelo que vamos ver primeiramente todos os argumentos, com a opção "-h".

\htmlonly
<pre>
/TProcura/Construtiva/Teste$ ./bin/Release/TProcuraConstrutiva -h

┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 2
Uso: ./bin/Release/TProcuraConstrutiva <instâncias> [opções]
  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]
Opções:
  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)
  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)
  -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador
  -I <ind>        Lista de indicadores (e.g. 2,1,3)
  -h              Esta ajuda
  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - último campo
Exemplo: ./bin/Release/TProcuraConstrutiva 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2
   Executar sem argumentos entra em modo interativo, para explorar todos os parâmetros e indicadores

┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO):             Largura Primeiro (1 a 7)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               1          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(VER_ACOES):             4          (1 a 100)
│ P7(LIMITE):                0          (-1 a 1000000)
│ P8(ESTADOS_REPETIDOS):     ascendentes (1 a 3)
│ P11(BARALHAR_SUCESSORES):  0          (0 a 1)
└──────────────────────────────────────────────────────────────────────
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): ✓ 1º lugar
│ o resultado é o custo da solução atual
│ I2(Tempo(ms)): ✓ 2º lugar
│ Tempo em milissegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✓ 3º lugar
│ Iterações do algoritmo, interpretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_EXPANSOES): ✓ 4º lugar
│ número de expansões efetuadas
│ I5(IND_GERACOES): ✓ 5º lugar
│ número de estados gerados
│ I6(IND_LOWER_BOUND): ✓ 6º lugar
│ valor mínimo para a melhor solução, se igual ao custo da solução obtida, então esta é ótima
└──────────────────────────────────────────────────────────────────────
</pre>
\endhtmlonly

A forma como temos o programa, requer interação do utilizador, pelo que tivemos que escolher a opção 2 para o Puzzle 8.

### Teste: puzzle8_1

Pretendemos comparar os algoritmos construtivos para este problema, P1=1,3:7.
Retiramos o custo uniforme atendendo a que é igual à procura em largura se as ações tiverem todas custo 1,
e utilizamos o valor por omissão da procura em profundidade, P7=0, para obter a profundidade iterativa.

Precisamos de selecionar instâncias, de simples a complexas.
Como tempos bastantes instâncias, vamos fixar a semente com 4 valores,
e alteramos o esforço do teste com o número de instâncias.

- **Tipo de Teste / Objetivo**: Paramétrico (P1=1,3:7)
- **Definição**: Instâncias: 1:1000:100; Configurações: P1=1,3:7 x P3=1:4
- **Esforço**: 1:1000:100; 1:1000:10; 1:1000
- **Execução**: TProcura 1:1000:100 -R Resultados/puzzle8_1 -P P2=3 P1=1,3:7 x P3=1:4


Assim, podemos executar o programa com a seguinte linha de comando:

\htmlonly
<pre>
/TProcura/Construtiva/Teste$ ./bin/Release/TProcuraConstrutiva 1:1000:100 -R Resultados/puzzle8_1 -P P2=3 P1=1,3:7 x P3=1:4

┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
└──────────────────────────────┘
Opção: 2


═╤═ Instâncias ═══ { 📄 1 📄 101 📄 201 📄 301 📄 401 📄 501 📄 601 📄 701 📄 801 📄 901 }
 ├─ 🛠️  ─ P2=3 P4=10 P5=0 P6=4 P7=0 P8=2 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ P1=1 P3=1
 ├─ ⚙  [2] ─ P1=3 P3=1
 ├─ ⚙  [3] ─ P1=4 P3=1
 │ ...
 ├─ ⚙  [22] ─ P1=5 P3=4
 ├─ ⚙  [23] ─ P1=6 P3=4
 ├─ ⚙  [24] ─ P1=7 P3=4
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:240   📄 Instâncias: 10   🛠️ Configurações: 24   🖥️ Processos: 1.
 ├─ ⏱ 12" 825ms       📋 64    📄 301   🛠️ 7     🖥️ 1
 ├─ ⏱ 23" 208ms       📋 74    📄 301   🛠️ 8     🖥️ 1
 ├─ ⏱ 40" 580ms       📋 130   📄 901   🛠️ 13    🖥️ 1
 ├─ ⏱ 59" 226ms       📋 140   📄 901   🛠️ 14    🖥️ 1
 ├─ ⏱ 1' 9" 343ms     📋 236   📄 501   🛠️ 24    🖥️ 1
 ├─ 📑  Ficheiro Resultados/puzzle8_1.csv gravado.
 │  ⏱  Tempo real: 1' 9" 758ms
 │  ⏱  CPU total: 1' 9" 758ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 1' 9" 758ms ) ═══
</pre>
\endhtmlonly

O ficheiro de resultados foi gravado, toda a execução decorreu em 1 minuto e 10 segundos, pelo que o nível 3 de debug
fez 4 relatório a cada 10 segundos. O nível 4 o relatório é em cada resultado, o que neste caso seria
demasiado já que há 240 tarefas. O nível 2 dá um report a cada minuto.

- **hardware**: 11th Gen Intel(R) Core(TM) i7-1185G7 @ 3.00GHz, RAM 16.0 GB (4267 MT/s)
- **Ficheiro de Análise**: puzzle8.xlsx

Vamos ver os resultados em bruto, para saber toais de P1 face a diversos indicadores:
- **Colunas**: Instância (usar a coluna de tvetor_1)
- **Linhas**: valores
- **Valores**: I1, I2, I4, máximo I1, Resolvido

Adicionamos uma coluna para somar as instâncias resolvidas, as que têm custo igual ou superior a 0.
O código -2 significa que a instância não foi resolvida, e -1 significa instância impossível.
Estas instâncias são todas possíveis devido à forma como foram geradas, através de movimentos aleatórios desde a posição objetivo.

Obtemos a seguinte tabela:

| Valores | 1:Largura Primeiro | 3:Profundidade Primeiro | 4:Melhor Primeiro | 5:A* | 6:IDA* | 7:Branch and Bound |
|:---:|---:|---:|---:|---:|---:|---:|
| Soma de I1(IND_CUSTO) | 730 | 699 | 8054 | 730 | 730 | 730 |
| Soma de I2(Tempo(ms)) | 26210 | 38293 | 18 | 31 | 47 | 4431 |
| Soma de I4(IND_EXPANSOES) | 29787206 | 59662841 | 8107 | 37266 | 61187 | 1734526 |
| Máximo de I1(IND_CUSTO)2 | 29 | 27 | 815 | 29 | 29 | 29 |
| Soma de Resolvido | 40 | 39 | 40 | 40 | 40 | 40 |

A versão da procura em profundidade, é a versão iterativa, com o parâmetro P7=0, sendo esse o valor por omissão.

Podemos agora confirmar que:
- procuras informadas são no geral mais eficientes em termos de tempo;
- a procura em profundidade primeiro iterativa foi o único a não conseguir resolver uma das instâncias, no limite dos 10 segundos;
- o Melhor Primeiro nem sempre retorna a solução ótima, todos os outros retornam sempre a solução ótima;
- os algoritmos informados mais eficientes em termos de esforço computacional, medido pelo tempo CPU e número de expansões são o Astar e IDAstar

Podemos fazer a versão de maior esforço, mas com um teste de 1 minuto, já sabemos que dificilmente o Astar
não será o melhor neste problema, atendendo a que tem um valor claramente inferior em termos de
expansões, embora o tempo seja similar ao IDAstar.

Maior esforço e intervalos de confiança são úteis apenas se pretendermos comprovar estatisticamente que o Melhor Primeiro é o mais rápido (sem retornar o óptimo),
seguido do Astar e depois do IDAstar.

Interessante também o valor do maior custo, ou seja, da instância mais complexa encontrada, corresponde a 29 movimentos.
O Melhor Primeiro chegou a dar soluções de 815 movimentos, o que em termos de qualidade da solução será certamente baixo,
atendendo a que a instância mais complexa tem apenas 29 movimentos.

Ficamos com a comparação dos algoritmos, e com a performance global.
Não temos um teste de performance, em que se cruza o tempo com a dificuldade da instância.
Neste caso o tamanho da instância é sempre o mesmo, mas as instâncias não são todas da mesma complexidade.
As que têm a solução ótima mais longa, podem ser consideradas mais complexas.

- **Tipo de Teste / Objetivo**: Performance (I2 (tempo) vs I1 (ótimo))

Como temos as soluções óptimas utilizando por exemplo o Astar, podemos extrair o I1 ótimo e fazer os gráficos com os resultados do teste puzzle8_1.

| Rótulos de Linha | 1:Largura Primeiro | 3:Profundidade Primeiro | 4:Melhor Primeiro | 5:A* | 6:IDA* | 7:Branch and Bound |
|:---:|---:|---:|---:|---:|---:|---:|
| 1 | 0 | 0 | 0 | 0 | 0 | 0 |
| 13 | 2 | 6 | 0 | 0 | 0 | 21 |
| 15 | 8 | 12 | 0 | 0 | 0 | 35 |
| 17 | 34 | 31 | 1 | 0 | 0 | 118 |
| 19 | 42 | 77 | 0 | 0 | 0 | 28 |
| 21 | 139 | 252 | 1 | 1 | 1 | 242 |
| 23 | 429 | 763 | 1 | 1 | 1 | 289 |
| 25 | 1430 | 2242 | 0 | 1 | 2 | 97 |
| 27 | 4659 | 8014 | 0 | 5 | 11 | 63 |
| 29 | 9389 | 10000 | 1 | 9 | 8 | 119 |

Com o esforço atual, existem apenas 40 instâncias. Não temos assim uma amostra de instâncias linear na dificuldade.
Para melhorar estes resultados é preciso mais instâncias, utilizando este mesmo teste mas com maior esforço.

Podemos no entanto observar o auemnto gradual do tempo nos algoritmos cegos.
Pelo contrário, os algoritmos informados têm um tempo muito reduzido, na ordem dos milissegundos.
Apenas o BnB tem algum tempo superior, mas que aparenta não ser dependnete da dificuldade da instância,
será mais relacionado com a sorte ou azar da primeira solução encontrada estar perto ou longe do ótimo.

Um maior volume de testes permitirá aferir que provavelmente o Melhor Primeiro é mais rápido principalmente em instâncias complicadas.

Como o Melhor Primeiro não obtém todas as soluções óptimas, poderiamos calcular a percentagem de desvio da
qualidade da solução até ao valor óptimo: %desvio = (ValorObtido - óptimo)/óptimo.
Este indicador seria útil para comparar dos algoritmos não exatos, de modo a aferir a qualidade das suas soluções.
Temos neste caso um só algoritmo, com soluções de muito má qualidade, pelo que não utilizaremos para já este indicador.


\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_puzzle8bnb.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_construtivas.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
