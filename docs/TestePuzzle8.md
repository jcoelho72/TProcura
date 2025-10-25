@page teste_puzzle8 Teste Puzzle 8

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


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
- [Ação 5 - Heurística](#puzzle8-a5)
- [Ação 6 - Melhor Primeiro](#puzzle8-a6)
- [Ação 7 - AStar](#puzzle8-a7)
- [Ação 8 - IDAStar](#puzzle8-a8)
- [Ação 9 - Branch-and-Bound](#puzzle8-a9)
- [Ação 10 - Testes Empíricos](#puzzle8-a10)


```entrada
┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 2
```

![Puzzle 8 - movimentar uma das peças para o espaço vazio](docs/images/puzzle8.png)


\anchor puzzle8-a1
## Ação 1 - Ver instâncias

Vamos entrar no problema Puzzle 8, introduza: **2.**

```entrada
Puzzle 8
┌─ ⚙️ Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 │  3  1  2
 │  4  7  5
 │  6  8  .
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   Instância  │ 2 🔍  Explorar │ 3 ⚙   Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖   Indicadores │ 6 ►   Executar │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
```
Aparece uma instância do Puzzle 8. Poderiamos procurar resolver manualmente. 
No entanto esta instância está distante da solução, pelo que vamos ver outra instância.
Introduza: **1;4.**

```entrada
Opção: 1

┌─ 📄 Instância ───────────────────────────────────────────────────────
│ ID atual: 40  Intervalo: [1–1000]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 4

Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 3  1  2
 6  4  5
 7  8  .
...
Opção:
```

Estavamos na instância 40, e existem instâncias de 1 a 1000. 
Como as instâncias são construídas com base em movimentos aleatórios em quantidade igual ao ID da instância,
ao escolher um ID de 4 garantimos que estamos a uma distância de 4 ou menos da solução.


\anchor puzzle8-a2
## Ação 2 - Resolver manualmente

Vamos então resolver a instância manualmente. Introduza: **2; dir dir baixo baixo; *ENTER*.**

```entrada
Opção: 2

═╤═ 💰 g:0 🎯 h:4 ⚖  1|2|3 ═══
 │  3  1  2
 │  6  4  5
 │  7  8  .
 │ └─ ⚡  ──── baixo dir
🔍 Sucessor [1-2, ação(ões), exe]: dir dir baixo baixo

┌─ ✔  ────────────────
│ Executadas 4 ações.
└─────────────────────
═╤═ 💰 g:0 ⚖  6|14|6 ═══
 │  .  1  2
 │  3  4  5
 │  6  7  8
 │ └─ ⚡  ──── cima esq
🔍 Sucessor [1-2, ação(ões), exe]:

Puzzle 8
...
 │  .  1  2
 │  3  4  5
 │  6  7  8
...
Opção:
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
 │  .  1  2
 │  3  4  5
 │  6  7  8
...
Opção:
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

═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 │  3  1  2
 │  6  4  5
 │  7  8  .
 │ └─ ⚡  ──── baixo dir { 🔖 1 🔖 2 }
 ├■═╤═ 🔖 1 💰 g:1 ⚖  1|2 ═══ { 🔖 2 }
 │  3  1  2
 │  6  4  .
 │  7  8  5
 │ └─ ⚡  ──── baixo dir { 🔖 3 🔖 4 }
 ├■═╤═ 🔖 2 💰 g:1 ⚖  2|4 ═══ { 🔖 3 🔖 4 }
 │  3  1  2
 │  6  4  5
 │  7  .  8
 │ └─ ⚡  ──── baixo dir { 🔖 5 🔖 6 }
 ├■═╤═ 🔖 3 💰 g:2 ⚖  3|6 ═══ { 🔖 4 🔖 5 🔖 6 }
 │  3  1  .
 │  6  4  2
 │  7  8  5
 │ └─ ⚡  ──── dir { 🔖 7 }
 ├■═╤═ 🔖 4 💰 g:2 ⚖  4|7 ═══ { 🔖 5 🔖 6 🔖 7 }
 │  3  1  2
 │  6  .  4
 │  7  8  5
 │ └─ ⚡  ──── baixo cima dir { 🔖 8 🔖 9 🔖 10 }
 ├■═╤═ 🔖 5 💰 g:2 ⚖  5|10 ═══ { 🔖 6 🔖 7 🔖 8 🔖 9 🔖 10 }
 │  3  1  2
 │  6  .  5
 │  7  4  8
 │ └─ ⚡  ──── baixo dir esq { 🔖 11 🔖 12 🔖 13 }
 ├■═╤═ 🔖 6 💰 g:2 ⚖  6|13 ═══ { 🔖 7 🔖 8 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 }
 │  3  1  2
 │  6  4  5
 │  .  7  8
 │ └─ ⚡  ──── baixo { 🔖 14 }
 ├■═╤═ 🔖 7 💰 g:3 ⚖  7|14 ═══ { 🔖 8 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 }
 │  3  .  1
 │  6  4  2
 │  7  8  5
 │ └─ ⚡  ──── cima dir { 🔖 15 🔖 16 }
 ├■═╤═ 🔖 8 💰 g:3 ⚖  8|16 ═══ { 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 }
 │  3  .  2
 │  6  1  4
 │  7  8  5
 │ └─ ⚡  ──── dir esq { 🔖 17 🔖 18 }
 ├■═╤═ 🔖 9 💰 g:3 ⚖  9|18 ═══ { 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 🔖 17 🔖 18 }
 │  3  1  2
 │  6  8  4
 │  7  .  5
 │ └─ ⚡  ──── dir esq { 🔖 19 🔖 20 }
 ├■═╤═ 🔖 10 💰 g:3 ⚖  10|20 ═══ { 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 🔖 17 🔖 18 🔖 19 🔖 20 }
 │  3  1  2
 │  .  6  4
 │  7  8  5
 │ └─ ⚡  ──── baixo cima { 🔖 21 🔖 22 }
 ├■═╤═ 🔖 11 💰 g:3 ⚖  11|22 ═══ { �12 �13 �14 … 🔖 20 🔖 21 🔖 22 } #11
 │  3  .  2
 │  6  1  5
 │  7  4  8
 │ └─ ⚡  ──── dir esq { 🔖 23 🔖 24 }
 ├■═╤═ 🔖 12 💰 g:3 ⚖  12|24 ═══ { �13 �14 �15 … 🔖 22 🔖 23 🔖 24 } #12
 │  3  1  2
 │  .  6  5
 │  7  4  8
 │ └─ ⚡  ──── baixo cima { 🔖 25 🔖 26 }
 ├■═╤═ 🔖 13 💰 g:3 ⚖  13|26 ═══ { �14 �15 �16 … 🔖 24 🔖 25 🔖 26 } #13
 │  3  1  2
 │  6  5  .
 │  7  4  8
 │ └─ ⚡  ──── baixo cima { 🔖 27 🔖 28 }
 ├■═╤═ 🔖 14 💰 g:3 ⚖  14|28 ═══ { �15 �16 �17 … 🔖 26 🔖 27 🔖 28 } #14
 │  3  1  2
 │  .  4  5
 │  6  7  8
 │ └─ ⚡  ──── baixo esq { 🔖 29 🔖 30 }
 │  🎯  Solução encontrada! 💰 g:4
 │  .  1  2
 │  3  4  5
 │  6  7  8
 ├─ Parâmetros ─ P1=1 P2=4 P3=1 P4=10 P5=0 P6=4 P7=0 P8=2 P11=0
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 4 | I2(Tempo(ms)): 1 | I3(Iterações): 0 | I4(IND_EXPANSOES): 15 |
│ I5(IND_GERACOES): 30 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Foi encontrada uma solução de distância 4. Podemos ver a ordem das expansões, houve estados expandidos 
que em nada contribuiam para a solução, mas serviram para garantir que não havia outra solução mais curta.

Vemos a lista de estados gerados não expandidos, vai cada vez aumentando, e na geração 14 já tinha
14 elementos. A partir de 10 elementos, em vez de colocar todos os elementos da lista, colocamos
apenas os primeiros e últimos, acompanhado com a quantidade de elementos.

Esta instância era fácil, mas e a instância inicial?
Vamos ver, mas reduzindo o debug para 2, e a semente para 2. Introduza: **3; 2; 2; 3; 2; *ENTER*; 1; 40; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 ├■═╤═ 🔖 1 💰 g:1 ⚖  1|4 ═══ { 🔖 2 🔖 3 🔖 4 }
 ├■═╤═ 🔖 2 💰 g:1 ⚖  2|6 ═══ { 🔖 3 🔖 4 🔖 5 🔖 6 }
 ├■═╤═ 🔖 3 💰 g:1 ⚖  3|8 ═══ { 🔖 4 🔖 5 🔖 6 🔖 7 🔖 8 }
 ├■═╤═ 🔖 4 💰 g:1 ⚖  4|10 ═══ { 🔖 5 🔖 6 🔖 7 🔖 8 🔖 9 🔖 10 }
 ├■═╤═ 🔖 5 💰 g:2 ⚖  5|12 ═══ { 🔖 6 🔖 7 🔖 8 🔖 9 🔖 10 🔖 11 🔖 12 }
 ├■═╤═ 🔖 6 💰 g:2 ⚖  6|13 ═══ { 🔖 7 🔖 8 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 }
 ├■═╤═ 🔖 7 💰 g:2 ⚖  7|14 ═══ { 🔖 8 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 }
 ├■═╤═ 🔖 8 💰 g:2 ⚖  8|15 ═══ { 🔖 9 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 }
 ├■═╤═ 🔖 9 💰 g:2 ⚖  9|16 ═══ { 🔖 10 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 }
 ├■═╤═ 🔖 10 💰 g:2 ⚖  10|17 ═══ { 🔖 11 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 🔖 17 }
 ├■═╤═ 🔖 11 💰 g:2 ⚖  11|18 ═══ { 🔖 12 🔖 13 🔖 14 🔖 15 🔖 16 🔖 17 🔖 18 }
 ├■═╤═ 🔖 12 💰 g:2 ⚖  12|19 ═══ { 🔖 13 🔖 14 🔖 15 🔖 16 🔖 17 🔖 18 🔖 19 }
 ├■═╤═ 🔖 13 💰 g:3 ⚖  13|20 ═══ { 🔖 14 🔖 15 🔖 16 🔖 17 🔖 18 🔖 19 🔖 20 }
 ├■═╤═ 🔖 14 💰 g:3 ⚖  14|22 ═══ { 🔖 15 🔖 16 🔖 17 🔖 18 🔖 19 🔖 20 🔖 21 🔖 22 }
 ├■═╤═ 🔖 15 💰 g:3 ⚖  15|24 ═══ { 🔖 16 🔖 17 🔖 18 🔖 19 🔖 20 🔖 21 🔖 22 🔖 23 🔖 24 }
 ├■═╤═ 🔖 16 💰 g:3 ⚖  16|26 ═══ { 🔖 17 🔖 18 🔖 19 🔖 20 🔖 21 🔖 22 🔖 23 🔖 24 🔖 25 🔖 26 }
 ├■═╤═ 🔖 17 💰 g:3 ⚖  17|28 ═══ { �18 �19 �20 … 🔖 26 🔖 27 🔖 28 } #11
...
 ├■═╤═ 🔖 1278 💰 g:11 ⚖  1278|2117 ═══ { �1279 �1280 �1281 … 🔖 2115 🔖 2116 🔖 2117 } #839
 ├■═╤═ 🔖 1279 💰 g:11 ⚖  1279|2119 ═══ { �1280 �1281 �1282 … 🔖 2117 🔖 2118 🔖 2119 } #840
 ├■═╤═ 🔖 1280 💰 g:11 ⚖  1280|2121 ═══ { �1281 �1282 �1283 … 🔖 2119 🔖 2120 🔖 2121 } #841
 ├■═╤═ 🔖 1281 💰 g:11 ⚖  1281|2123 ═══ { �1282 �1283 �1284 … 🔖 2121 🔖 2122 🔖 2123 } #842
 ├■═╤═ 🔖 1282 💰 g:11 ⚖  1282|2125 ═══ { �1283 �1284 �1285 … 🔖 2123 🔖 2124 🔖 2125 } #843
 ├■═╤═ 🔖 1283 💰 g:11 ⚖  1283|2127 ═══ { �1284 �1285 �1286 … 🔖 2125 🔖 2126 🔖 2127 } #844
 ├■═╤═ 🔖 1284 💰 g:11 ⚖  1284|2129 ═══ { �1285 �1286 �1287 … 🔖 2127 🔖 2128 🔖 2129 } #845
 │  🎯  Solução encontrada! 💰 g:12
 │  .  1  2
 │  3  4  5
 │  6  7  8
 ├─ Parâmetros ─ P1=1 P2=2 P3=2 P4=10 P5=0 P6=4 P7=0 P8=2 P11=0
═╧═ 🏁  Execução terminada ⏱   28ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): PASSOS | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 28 | I3(Iterações): 0 | I4(IND_EXPANSOES): 1285 |
│ I5(IND_GERACOES): 2131 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Foi encontrado um resultado com 12 movimentos, mas foram realizadas 1285 expansões, resultando em 2131 gerações.
Notar que a lista de estados gerados não expandidos foi continuamente crescendo, e no momento
em que foi encontrada a solução haviam 845 estados nesta lista.

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
Opção:
```

Nesta instância foram precisas 4 partes para mostrar a solução com 12 ações. 

Embora o estado inicial tenha sido obtido por 40 movimentos aleatórios desde o estado objetivo,
alguns dos movimentos acabaram por se inverter resultando numa instância à distãncia 12 do objetivo.

Utilizamos P3(SEMENTE)=2, naturalmente que outra semente aleatória poderia gerar um puzzle de 0 a 40 movimentos da solução.


\anchor puzzle8-a4
## Ação 4 - Procura em Profundidade

Vamos ver a procura em profundidade na instância 40, que sabemos ter uma solução de 12. 
Vamos alterar o algoritmo, colocar a profundidade a 4, debug a completo e visualização de ações a 1, 
para ser ver todos os estados. 
Introduza: **1; 40; 3; 1; 3; 7; 4; 2; 4; 6; 1; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══
 │  4  7  3
 │  1  .  2
 │  6  8  5
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|4 ═══ ⚡ baixo
 │  │  4  .  3
 │  │  1  7  2
 │  │  6  8  5
 │  │  ├■═╤═ 🔖 5 💰 g:2 ⚖  2|6 ═══ ⚡ dir
 │  │  │  .  4  3
 │  │  │  1  7  2
 │  │  │  6  8  5
 │  │  │  └■═╤═ 🔖 7 💰 g:3 ⚖  3|7 ═══ ⚡ cima
 │  │  │     1  4  3
 │  │  │     .  7  2
 │  │  │     6  8  5
 │  │  │    🍃 🪜
 │  │  └■═╤═ 🔖 6 💰 g:2 ⚖  3|7 ═══ ⚡ esq
 │  │     4  3  .
 │  │     1  7  2
 │  │     6  8  5
 │  │     └■═╤═ 🔖 8 💰 g:3 ⚖  4|8 ═══ ⚡ cima
 │  │        4  3  2
 │  │        1  7  .
 │  │        6  8  5
 │  │       🍃 🪜
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  4|8 ═══ ⚡ cima
 │  │  4  7  3
 │  │  1  8  2
 │  │  6  .  5
 │  │  ├■═╤═ 🔖 9 💰 g:2 ⚖  5|10 ═══ ⚡ dir
 │  │  │  4  7  3
 │  │  │  1  8  2
 │  │  │  .  6  5
 │  │  │  └■═╤═ 🔖 11 💰 g:3 ⚖  6|11 ═══ ⚡ baixo
 │  │  │     4  7  3
 │  │  │     .  8  2
 │  │  │     1  6  5
 │  │  │    🍃 🪜
 │  │  └■═╤═ 🔖 10 💰 g:2 ⚖  6|11 ═══ ⚡ esq
 │  │     4  7  3
 │  │     1  8  2
 │  │     6  5  .
 │  │     └■═╤═ 🔖 12 💰 g:3 ⚖  7|12 ═══ ⚡ baixo
 │  │        4  7  3
 │  │        1  8  .
 │  │        6  5  2
 │  │       🍃 🪜
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  7|12 ═══ ⚡ dir
 │  │  4  7  3
 │  │  .  1  2
 │  │  6  8  5
 │  │  ├■═╤═ 🔖 13 💰 g:2 ⚖  8|14 ═══ ⚡ baixo
 │  │  │  .  7  3
 │  │  │  4  1  2
 │  │  │  6  8  5
 │  │  │  └■═╤═ 🔖 15 💰 g:3 ⚖  9|15 ═══ ⚡ esq
 │  │  │     7  .  3
 │  │  │     4  1  2
 │  │  │     6  8  5
 │  │  │    🍃 🪜
 │  │  └■═╤═ 🔖 14 💰 g:2 ⚖  9|15 ═══ ⚡ cima
 │  │     4  7  3
 │  │     6  1  2
 │  │     .  8  5
 │  │     └■═╤═ 🔖 16 💰 g:3 ⚖  10|16 ═══ ⚡ esq
 │  │        4  7  3
 │  │        6  1  2
 │  │        8  .  5
 │  │       🍃 🪜
 │  └■═╤═ 🔖 4 💰 g:1 ⚖  10|16 ═══ ⚡ esq
 │     4  7  3
 │     1  2  .
 │     6  8  5
 │     ├■═╤═ 🔖 17 💰 g:2 ⚖  11|18 ═══ ⚡ baixo
 │     │  4  7  .
 │     │  1  2  3
 │     │  6  8  5
 │     │  └■═╤═ 🔖 19 💰 g:3 ⚖  12|19 ═══ ⚡ dir
 │     │     4  .  7
 │     │     1  2  3
 │     │     6  8  5
 │     │    🍃 🪜
 │     └■═╤═ 🔖 18 💰 g:2 ⚖  12|19 ═══ ⚡ cima
 │        4  7  3
 │        1  2  5
 │        6  8  .
 │        └■═╤═ 🔖 20 💰 g:3 ⚖  13|20 ═══ ⚡ dir
 │           4  7  3
 │           1  2  5
 │           6  .  8
 │          🍃 🪜
 ├─ Parâmetros ─ P1=3 P2=4 P3=2 P4=10 P5=0 P6=1 P7=4 P8=2 P11=0
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Profundidade Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 1 | P7(LIMITE): 4
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 4  7  3
 1  .  2
 6  8  5
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): -1 | I2(Tempo(ms)): 1 | I3(Iterações): 0 | I4(IND_EXPANSOES): 13 |
│ I5(IND_GERACOES): 20 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Foram vistos todos os estados, e não se encontrou uma solução.
No entanto todos os nós folha foram cortados devido ao limite, motivo pelo qual têm o icon da escada.
Vamos agora colocar o limite a 0, de modo a executar a iterativa, e debug no nível 2.
Introduza: **1; 40; 3; 7; 0; 2; 2; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├─────────── 🌳 🪜 1 ⏱  ────────────
 ├■═╤═ 💰 g:0  ═══ ─── 🍃 🪜
 ├─────────── 🌳 🪜 2 ⏱  ────────────
 ├■═╤═ 💰 g:0  ═══
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|4 ═══ ⚡ baixo ─── 🍃 🪜
 │  ├■═╤═ 🔖 2 💰 g:1 ⚖  1|4 ═══ ⚡ cima ─── 🍃 🪜
 │  ├■═╤═ 🔖 3 💰 g:1 ⚖  1|4 ═══ ⚡ dir ─── 🍃 🪜
 │  └■═╤═ 🔖 4 💰 g:1 ⚖  1|4 ═══ ⚡ esq ─── 🍃 🪜
 ├─────────── 🌳 🪜 3 ⏱  ────────────
 ├■═╤═ 💰 g:0 ⚖  1|4 ═══
 │  ├■═╤═ 🔖 5 💰 g:1 ⚖  2|8 ═══ ⚡ baixo
 │  │  ├■═╤═ 🔖 9 💰 g:2 ⚖  3|10 ═══ ⚡ dir ─── 🍃 🪜
 │  │  └■═╤═ 🔖 10 💰 g:2 ⚖  3|10 ═══ ⚡ esq ─── 🍃 🪜
 │  ├■═╤═ 🔖 6 💰 g:1 ⚖  3|10 ═══ ⚡ cima
 │  │  ├■═╤═ 🔖 11 💰 g:2 ⚖  4|12 ═══ ⚡ dir ─── 🍃 🪜
 │  │  └■═╤═ 🔖 12 💰 g:2 ⚖  4|12 ═══ ⚡ esq ─── 🍃 🪜
 │  ├■═╤═ 🔖 7 💰 g:1 ⚖  4|12 ═══ ⚡ dir
 │  │  ├■═╤═ 🔖 13 💰 g:2 ⚖  5|14 ═══ ⚡ baixo ─── 🍃 🪜
 │  │  └■═╤═ 🔖 14 💰 g:2 ⚖  5|14 ═══ ⚡ cima ─── 🍃 🪜
 │  └■═╤═ 🔖 8 💰 g:1 ⚖  5|14 ═══ ⚡ esq
 │     ├■═╤═ 🔖 15 💰 g:2 ⚖  6|16 ═══ ⚡ baixo ─── 🍃 🪜
 │     └■═╤═ 🔖 16 💰 g:2 ⚖  6|16 ═══ ⚡ cima ─── 🍃 🪜
 ├─────────── 🌳 🪜 4 ⏱  ────────────
 ├■═╤═ 💰 g:0 ⚖  6|16 ═══
 │  ├■═╤═ 🔖 17 💰 g:1 ⚖  7|20 ═══ ⚡ baixo
 │  │  ├■═╤═ 🔖 21 💰 g:2 ⚖  8|22 ═══ ⚡ dir
 │  │  │  └■═╤═ 🔖 23 💰 g:3 ⚖  9|23 ═══ ⚡ cima ─── 🍃 🪜
 │  │  └■═╤═ 🔖 22 💰 g:2 ⚖  9|23 ═══ ⚡ esq
 │  │     └■═╤═ 🔖 24 💰 g:3 ⚖  10|24 ═══ ⚡ cima ─── 🍃 🪜
 │  ├■═╤═ 🔖 18 💰 g:1 ⚖  10|24 ═══ ⚡ cima
 │  │  ├■═╤═ 🔖 25 💰 g:2 ⚖  11|26 ═══ ⚡ dir
 │  │  │  └■═╤═ 🔖 27 💰 g:3 ⚖  12|27 ═══ ⚡ baixo ─── 🍃 🪜
 │  │  └■═╤═ 🔖 26 💰 g:2 ⚖  12|27 ═══ ⚡ esq
 │  │     └■═╤═ 🔖 28 💰 g:3 ⚖  13|28 ═══ ⚡ baixo ─── 🍃 🪜
 │  ├■═╤═ 🔖 19 💰 g:1 ⚖  13|28 ═══ ⚡ dir
 │  │  ├■═╤═ 🔖 29 💰 g:2 ⚖  14|30 ═══ ⚡ baixo
 │  │  │  └■═╤═ 🔖 31 💰 g:3 ⚖  15|31 ═══ ⚡ esq ─── 🍃 🪜
 │  │  └■═╤═ 🔖 30 💰 g:2 ⚖  15|31 ═══ ⚡ cima
 │  │     └■═╤═ 🔖 32 💰 g:3 ⚖  16|32 ═══ ⚡ esq ─── 🍃 🪜
 │  └■═╤═ 🔖 20 💰 g:1 ⚖  16|32 ═══ ⚡ esq
 │     ├■═╤═ 🔖 33 💰 g:2 ⚖  17|34 ═══ ⚡ baixo
 │     │  └■═╤═ 🔖 35 💰 g:3 ⚖  18|35 ═══ ⚡ dir ─── 🍃 🪜
 │     └■═╤═ 🔖 34 💰 g:2 ⚖  18|35 ═══ ⚡ cima
 │        └■═╤═ 🔖 36 💰 g:3 ⚖  19|36 ═══ ⚡ dir ─── 🍃 🪜
 ├─────────── 🌳 🪜 5 ⏱  ────────────
...
 ├─────────── 🌳 🪜 13 ⏱ 59ms  ────────────
 ├■═╤═ 💰 g:0 ⚖  2699|4628 ═══
 │  ├■═╤═ 🔖 4629 💰 g:1 ⚖  2700|4632 ═══ ⚡ baixo
 │  │  ├■═╤═ 🔖 4633 💰 g:2 ⚖  2701|4634 ═══ ⚡ dir
 │  │  │  └■═╤═ 🔖 4635 💰 g:3 ⚖  2702|4635 ═══ ⚡ cima
 │  │  │     ├■═╤═ 🔖 4636 💰 g:4 ⚖  2703|4637 ═══ ⚡ cima
 │  │  │     │  └■═╤═ 🔖 4638 💰 g:5 ⚖  2704|4638 ═══ ⚡ esq
 │  │  │     │     ├■═╤═ 🔖 4639 💰 g:6 ⚖  2705|4640 ═══ ⚡ baixo
 │  │  │     │     │  ├■═╤═ 🔖 4641 💰 g:7 ⚖  2706|4643 ═══ ⚡ baixo
 │  │  │     │     │  │  ├■═╤═ 🔖 4644 💰 g:8 ⚖  2707|4645 ═══ ⚡ dir
 │  │  │     │     │  │  │  └■═╤═ 🔖 4646 💰 g:9 ⚖  2708|4646 ═══ ⚡ cima
 │  │  │     │     │  │  │     ├■═╤═ 🔖 4647 💰 g:10 ⚖  2709|4648 ═══ ⚡ cima
 │  │  │     │     │  │  │     │  └■═╤═ 🔖 4649 💰 g:11 ⚖  2710|4649 ═══ ⚡ esq
 │  │  │     │     │  │  │     │     ├■═╤═ 🔖 4650 💰 g:12 ⚖  2711|4651 ═══ ⚡ baixo ─── 🍃 🪜
 │  │  │     │     │  │  │     │     └■═╤═ 🔖 4651 💰 g:12 ⚖  2711|4651 ═══ ⚡ esq ─── 🍃 🪜
 │  │  │     │     │  │  │     └■═╤═ 🔖 4648 💰 g:10 ⚖  2711|4651 ═══ ⚡ esq
 │  │  │     │     │  │  │        ├■═╤═ 🔖 4652 💰 g:11 ⚖  2712|4654 ═══ ⚡ baixo
 │  │  │     │     │  │  │        │  ├■═╤═ 🔖 4655 💰 g:12 ⚖  2713|4656 ═══ ⚡ dir ─── 🍃 🪜
 │  │  │     │     │  │  │        │  └■═╤═ 🔖 4656 💰 g:12 ⚖  2713|4656 ═══ ⚡ esq ─── 🍃 🪜
 │  │  │     │     │  │  │        ├■═╤═ 🔖 4653 💰 g:11 ⚖  2713|4656 ═══ ⚡ cima
 │  │  │     │     │  │  │        │  ├■═╤═ 🔖 4657 💰 g:12 ⚖  2714|4658 ═══ ⚡ dir ─── 🍃 🪜
...
 │  │  │                             ├■═╤═ 🔖 5061 💰 g:12 ⚖  2943|5062 ═══ ⚡ baixo ─── 🍃 🪜
 │  │  │                             └■═╤═ 🔖 5062 💰 g:12 ⚖  2943|5062 ═══ ⚡ cima ─── 🍃 🪜
 │  │  └■═╤═ 🔖 4634 💰 g:2 ⚖  2943|5062 ═══ ⚡ esq
 │  │     └■═╤═ 🔖 5063 💰 g:3 ⚖  2944|5063 ═══ ⚡ cima
 │  │        ├■═╤═ 🔖 5064 💰 g:4 ⚖  2945|5065 ═══ ⚡ cima
 │  │        │  └■═╤═ 🔖 5066 💰 g:5 ⚖  2946|5066 ═══ ⚡ dir
 │  │        │     ├■═╤═ 🔖 5067 💰 g:6 ⚖  2947|5068 ═══ ⚡ baixo
 │  │        │     │  ├■═╤═ 🔖 5069 💰 g:7 ⚖  2948|5071 ═══ ⚡ baixo
 │  │        │     │  │  ├■═╤═ 🔖 5072 💰 g:8 ⚖  2949|5073 ═══ ⚡ dir
 │  │        │     │  │  │  └■═╤═ 🔖 5074 💰 g:9 ⚖  2950|5074 ═══ ⚡ cima
 │  │        │     │  │  │     ├■═╤═ 🔖 5075 💰 g:10 ⚖  2951|5076 ═══ ⚡ cima
 │  │        │     │  │  │     │  └■═╤═ 🔖 5077 💰 g:11 ⚖  2952|5077 ═══ ⚡ esq
 │  │        │     │  │  │     │     ├■═╤═ 🔖 5078 💰 g:12 ⚖  2953|5079 ═══ ⚡ baixo ─── 🍃 🪜
 │  │        │     │  │  │     │     └■═╤═ 🔖 5079 💰 g:12 ⚖  2953|5079 ═══ ⚡ esq ─── 🍃 🪜
 │  │        │     │  │  │     └■═╤═ 🔖 5076 💰 g:10 ⚖  2953|5079 ═══ ⚡ esq
 │  │        │     │  │  │        ├■═╤═ 🔖 5080 💰 g:11 ⚖  2954|5082 ═══ ⚡ baixo
 │  │        │     │  │  │        │  ├■═╤═ 🔖 5083 💰 g:12 ⚖  2955|5084 ═══ ⚡ dir
 │  │        │     │  │  │        │  │  🎯  Solução encontrada! 💰 g:12
 │  │        │     │  │  │        │  │  .  1  2
 │  │        │     │  │  │        │  │  3  4  5
 │  │        │     │  │  │        │  │  6  7  8  ─── 🎯 12 → 📈  ───  { 🔖 5084 }  ───  { 🔖 5081 🔖 5082 }  ───  { 🔖 5073 }  ───  { 🔖 5070 🔖 5071 }  ───  { 🔖 5068 }  ───  { 🔖 5065 }  ───  { 🔖 4630 🔖 4631 🔖 4632 }
 ├─ Parâmetros ─ P1=3 P2=2 P3=2 P4=10 P5=0 P6=1 P7=0 P8=2 P11=0
═╧═ 🏁  Execução terminada ⏱   63ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Profundidade Primeiro | P2(NIVEL_DEBUG): PASSOS | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 1 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ascendentes | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 63 | I3(Iterações): 0 | I4(IND_EXPANSOES): 2955 |
│ I5(IND_GERACOES): 5084 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

A procura em profundidade iterativa encontrou também a solução ótima, com 12 movimentos, na 13ª iteração.
Foram realizadas 2955 expansões e 5084 gerações, um valor superior à procura em largura.

Notar no entanto no parâmetro P8(ESTADOS_REPETIDOS): ascendentes. Significa que não foram gerados estados, 
que num dado ramo, já tinham ocorrido anteriormente. Esta é a opção de omissão para este problema, 
já que foi redefinido CPuzzle8::ResetParametros().

Vamos repetir esta execução, com debug no nível 1, e ignorando repetidos. 
Introduza: **1; 40; 3; 2; 1; 8; 1; *ENTER*; 6.**

```entrada
Opção: 6

Opção: 6

═╤═ ►  Execução iniciada ═══#########...#################
 ├■ 🎯  Solução encontrada! 💰 g:12
 │  .  1  2
 │  3  4  5
 │  6  7  8
 ├─ Parâmetros ─ P1=3 P2=1 P3=2 P4=10 P5=0 P6=1 P7=0 P8=1 P11=0
═╧═ 🏁  Execução terminada ⏱   83ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Profundidade Primeiro | P2(NIVEL_DEBUG): ATIVIDADE | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 1 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 83 | I3(Iterações): 0 | I4(IND_EXPANSOES): 156105 |
│ I5(IND_GERACOES): 440523 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Podemos ver que o número de expansões e gerações é consideravelmente superior. 
O tempo foi idêntico mesmo com mais gerações, mas isso deve-se ao nível de debug utilizado.

A verificação dos estados repetidos, é portanto um parametro bastante importante neste problema, em que
o mesmo estado pode surgir várias vezes. Vamos então testar a eliminação de todos os estados repetidos gerados.
Introduza: **1; 40; 3; 8; 3; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══####
 ├■ 🎯  Solução encontrada! 💰 g:12
 │  .  1  2
 │  3  4  5
 │  6  7  8
 ├─ Parâmetros ─ P1=3 P2=1 P3=2 P4=10 P5=0 P6=1 P7=0 P8=3 P11=0
═╧═ 🏁  Execução terminada ⏱   26ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Profundidade Primeiro | P2(NIVEL_DEBUG): ATIVIDADE | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 1 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): gerados | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 26 | I3(Iterações): 0 | I4(IND_EXPANSOES): 2647 |
│ I5(IND_GERACOES): 4400 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Podemos ver que o número de exapansões e gerações é ligeiramente inferior à configuração inicial,
de remover repetidos ascendentes.

Pergunta: o que acontecia se executar-mos a procura em profundidade ilimitada, ao deixar limite com -1, 
e sem verificar estados repetidos?
<details>
  <summary>Resposta</summary>
A procura não retorna, crasha devido a entrar num ciclo infinito.
</details>

\anchor puzzle8-a5
## Ação 5 - Heurística

Neste problema foi implementada a heurística com a distância na horizontal e vertical,
de cada peça até à sua posição final.
Esta heurística relaxa a situação de apenas ser possível mover para o local onde está o espaço, e 
retorna o valor que seria o correto caso cada peça pudesse mover-se por cima das outras.
É implementada no problema ao redefinir CPuzzle8::Heuristica().

Vamos começar por ver (notar que P6(VER_ACOES): 1 e P3(SEMENTE): 2).
Introduza: **1; 40; 2; dir baixo; *ENTER*.**

```entrada
Opção: 2

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
🔍 Sucessor [1-4, ação(ões), exe]: dir baixo

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
🔍 Sucessor [1-2, ação(ões), exe]:

Puzzle 8
...
 │  .  7  3
 │  4  1  2
 │  6  8  5
...
Opção:
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

Introduza: **1; 40; 3; 1; 4; 2; 3; 5; 1000000; 6; 4; 8; 3; *ENTER*; 6.**

```entrada
Opção: 6

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
...│  │  │  🎯  Solução encontrada! 💰 g:70
...
 ├─ Parâmetros ─ P1=4 P2=3 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P11=0
═╧═ 🏁  Execução terminada ⏱   11ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Melhor Primeiro | P2(NIVEL_DEBUG): DETALHE | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4
│ P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): gerados | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 70 | I2(Tempo(ms)): 11 | I3(Iterações): 128 | I4(IND_EXPANSOES): 70 |
│ I5(IND_GERACOES): 128 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Conseguimos uma solução de 70 ações, utilizando 70 expansões.
O output teve de ser cortado não pelo número de expansões mas pela profundidade.
O resultado em termos de esforço computacional é muito reduzido, pelo que a informação 
dada pela heurística foi útil. No entanto, a qualidade da solução baixa, já que fica com
70 de custo, quando sabemos existir uma solução de custo 12. 

\anchor puzzle8-a7
## Ação 7 - AStar

Vamos agora ver o comportamento do AStar, que garante a solução ótima. 

Introduza: **1; 40; 3; 1; 5; 2; 4; *ENTER*; 6.**

```entrada
Opção: 6

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
 ├■═╤═ 🔖 22 💰 g:11 🎯 h:1 ⚖  11|23|23 ═══ { �13 �5 �3 … 🔖 12 🔖 9 🔖 4 } #12
 │  3  1  2
 │  .  4  5
 │  6  7  8
 │ └─ ⚡  ──── baixo cima { 🔖 24 🔖 25 }
 ├■═╤═ 🔖 24 💰 g:12 ⚖  12|25|25 ═══ { �13 �5 �3 … 🔖 12 🔖 9 🔖 4 } #13
 │  .  1  2
 │  3  4  5
 │  6  7  8
 │  🎯  Solução encontrada! 💰 g:12
 │  .  1  2
 │  3  4  5
 │  6  7  8
 ├─ Parâmetros ─ P1=5 P2=4 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0 P11=0
═╧═ 🏁  Execução terminada ⏱   2ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): A* | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4 | P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): gerados
│ P9(PESO_ASTAR): 100 | P10(RUIDO_HEURISTICA): 0 | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 2 | I3(Iterações): 25 | I4(IND_EXPANSOES): 12 |
│ I5(IND_GERACOES): 25 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Foram utilizadas 12 expansões para obter a solução ótima de 12 movimentos.
Notar na lista ordenada, um dos piores estados é o estado 4, gerado no início, mas nem por isso
foi expandido, já que tinha um mau valor heurístico. Como colocamos P6(VER_ACOES): 4, não vemos os estados gerados,
colocando a 1 já poderiamos confirmar o motivo para que este estado permaneça no final da lista de estados gerados não expandidos.

Esta é uma instância simples para este algoritmo.

\anchor puzzle8-a8
## Ação 8 - IDAStar

O AStar pode ter problemas de memória em instâncias complexas, existindo o IDAStar que permite a mesma ordem
de expansão, mas sem o problema de memória, em troca de algum tempo de CPU extra, gasto ao expandir multiplas
vezes os mesmos estados. Vamos ver como se comporta nesta instância.

Introduza: **1; 40; 3; 1; 6; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├─────────── 🌳 📉  12 ⏱ 8ms  ────────────
 ├■═╤═ 💰 g:0 ⚖  |1 ═══
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
 ├─ Parâmetros ─ P1=6 P2=4 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0 P11=0
═╧═ 🏁  Execução terminada ⏱   11ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): IDA* | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4 | P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): gerados
│ P9(PESO_ASTAR): 100 | P10(RUIDO_HEURISTICA): 0 | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 11 | I3(Iterações): 29 | I4(IND_EXPANSOES): 14 |
│ I5(IND_GERACOES): 28 | I6(IND_LOWER_BOUND): 14
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Podemos ver que em termos de iterações, ao contrário da procura em profundidade iterativa,
tem menos iterações. 

O limite da iteração seguinte é determinado pelo menor valor dos estados
cortados, avançando mais que uma unidade de cada vez.
O primeiro limite é determinado pelo valor da heurística do estado inicial, que neste caso tinha o valor perfeito.

Acabou por ter apenas 14 expansões, enquanto que o AStar utilizou 12 expansões. 

Neste caso como houve uma só iteração, correu bastante bem. Mas mesmo que fosse o dobro das expansões,
é um pequeno preço a pagar por não ter problemas de memória.


\anchor puzzle8-a9
## Ação 9 - Branch-and-Bound

Vamos agora ver como se comporta o Branch-and-Bound, o último algoritmo informado. 
Este algoritmo pode ser visto como o Melhor Primeiro que continua a procura após a primeira solução.
No entanto restringe o espaço de procura apenas aos estados que melhoram a solução atual.

É um algoritmo em profundidade, pelo que não tem problemas de memória originados na procura em largura.
Vamos baixar o nível de debug para 1.

Introduza: **1; 40; 3; 1; 7; 2; 1; *ENTER*; 6.**

```entrada
Opção: 6

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
 ├─ Parâmetros ─ P1=7 P2=1 P3=2 P4=10 P5=1000000 P6=4 P7=0 P8=3 P9=100 P10=0 P11=0
═╧═ 🏁  Execução terminada ⏱   29ms  ═══
Puzzle 8
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Branch and Bound | P2(NIVEL_DEBUG): ATIVIDADE | P3(SEMENTE): 2
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4
│ P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): gerados | P9(PESO_ASTAR): 100
│ P10(RUIDO_HEURISTICA): 0 | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 .  1  2
 3  4  5
 6  7  8
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 12 | I2(Tempo(ms)): 29 | I3(Iterações): 6666 | I4(IND_EXPANSOES): 4110 |
│ I5(IND_GERACOES): 6666 | I6(IND_LOWER_BOUND): 14
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Vemos que primeiramente encontra a solução de 70 movimentos, e depois vai encontrando sucessivamente 
soluções melhores até que termina com a solução de 12. Gasta nesta instância um número 
consideravelmente superior de expansões e gerações, quando comparado com o AStar.

Podemos agora ver outras instâncias, e executar cada um dos algoritmos para ver qual é o melhor.
No entanto seria um trabalho fastidioso.

Não o fazer, ficariamos com a informação da performance dos algoritmos numa só instância, 
não necessariamente representativa de todas as instâncias.

É para melhor medir o desempenho de algoritmos e configurações, que existem os testes empíricos,
permitindo assim comparar algoritmos e/ou configurações num leque alargado de instâncias.

\anchor puzzle8-a10
## Ação 10 - Testes Empíricos

Vamos agora fazer testes empíricos, para comparar os algoritmos informados. 
As configurações e testes no modo interativo, foram exemplificados no exemplo de teste do TVector. 

Executamos o programa em linha de comando, pelo que vamos ver primeiramente todos os argumentos, com a opção "-h".

```entrada
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
   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores

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
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✓ 3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_EXPANSOES): ✓ 4º lugar
│ número de expansões efetuadas
│ I5(IND_GERACOES): ✓ 5º lugar
│ número de estados gerados
│ I6(IND_LOWER_BOUND): ✓ 6º lugar
│ valor mínimo para a melhor solução, se igual ao custo da solução obtida, então esta é ótima
└──────────────────────────────────────────────────────────────────────
```

A forma como temos o programa, requer interação do utilizador, pelo que tivemos que escolher a opção 2 para o Puzzle 8.

### Teste: puzzle8_1

Pretendemos comparar os algoritmos construtivos para este problema, P1=1,3:7.
Retiramos o custo uniforme atendendo a que é igual à procura em largura se as ações tiverem todas custo 1,
e utilizamos o valor de omissão da procura em profundidade, P7=0, para obter a profundidade iterativa.

Precisamos de selecionar instâncias, de simples a complexas.
Como tempos bastantes instâncias, vamos fixar a semente com 4 valores,
e alteramos o esforço do teste com o número de instâncias.

- **Tipo de Teste / Objetivo**: Paramétrico (P1=1,3:7)
- **Definição**: Instâncias: 1:1000:100; Configurações: P1=1,3:7 x P3=1:4
- **Esforço**: 1:1000:100; 1:1000:10; 1:1000
- **Execução**: TProcura 1:1000:100 -R Resultados/puzzle8_1 -P P2=3 P1=1,3:7 x P3=1:4


Assim, podemos executar o programa com a seguinte linha de comando:
```entrada
/TProcura/Construtiva/Teste$ ./bin/Release/TProcuraConstrutiva 1:1000:100 -R Resultados/puzzle8_1 -P P2=3 P1=1,3:7 x P3=1:4

┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
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
```

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

A versão da procura em profundidade, é a versão iterativa, com o parametro P7=0, sendo esse o valor de omissão.

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
Pelo contrário, os algoritmos informados têm um tempo muito reduzido, na ordem dos milisegundos.
Apenas o BnB tem algum tempo superior, mas que aparenta não ser dependnete da dificuldade da instância,
será mais relacionado com a sorte ou azar da primeira solução encontrada estar perto ou longe do ótimo.

Um maior volume de testes permitirá aferir que provavelmente o Melhor Primeiro é mais rápido principalmente em instâncias complicadas.

Como o Melhor Primeiro não obtém todas as soluções óptimas, poderiamos calcular a percentagem de desvio da
qualidade da solução até ao valor óptimo: %desvio = (ValorObtido - óptimo)/óptimo.
Este indicador seria útil para comparar dos algoritmos não exatos, de modo a aferir a qualidade das suas soluções.
Temos neste caso um só algoritmo, com soluções de muito má qualidade, pelo que não utilizaremos para já este indicador.


| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
