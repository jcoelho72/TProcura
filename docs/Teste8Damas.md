@page teste_8damas Teste 8 Damas

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


Execução de exemplo com base no problema das 8 Damas.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraConstrutiva, e execute.
No Linux na pasta `.../TProcura/Construtiva/Teste$` execute `make` seguido de `./bin/Release/TProcuraConstrutiva`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#8damas-a1)
- [Ação 2 - Resolver manualmente](#8damas-a2)
- [Ação 3 - Procura em Largura](#8damas-a3)
- [Ação 4 - Procura em Profundidade](#8damas-a4)
- [Ação 5 - Heurística](#8damas-a5)
- [Ação 6 - Testes Empíricos](#8damas-a6)


```entrada
┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 3
```

![8 Damas - colocar 8 damas no tabuleiro sem que se ataquem mutuamente](docs/images/8damas.png)

Vamos entrar no problema das 8 damas. Introduza: **3.**

```entrada
8 Damas
8 Damas
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
::  ::  ::  ::
  ::  ::  ::  ::
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```
Este estado vazio é um tabuleiro de 8x8. 
O objetivo é colocar damas no tabuleiro de xadrez, sem que as damas se ataquem mutuamente.

\anchor 8damas-a1
## Ação 1 - Ver instâncias

Vamos ver que instâncias temos. Introduza: **1; 4.**


```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 8  Intervalo: [4–40]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 4

8 Damas
...
::  ::
  ::  ::
::  ::
  ::  ::
...
Opção:
```

O tabuleiro foi generalizado a largura N. Podemos escolher entre 4 e 40 colunas.



\anchor 8damas-a2
## Ação 2 - Resolver manualmente

Há várias formas de se colocar damas no tabuleiro. 
Está implementada a colocação de uma dama, na linha superior que não esteja atacada.

Poder-se-ia permitir a colocação de uma dama em qualquer posição. 
No entanto, como em cada linha tem de estar uma dama, optamos por colocar sempre na primeira linha vazia.
Caso se tivessem implementado diferentes opções, seria adicionado um parametro,
e os sucessores seria distinto conforme o valor desse parâmetro.

Vamos resolver esta instância manualmente, para explorar o espaço de estados.
Introduza: **2; d1; d4; d2.**


```entrada
Opção: 2

═╤═ 💰 g:0 🔢 1|4|5 ═══
::  ::
  ::  ::
::  ::
  ::  ::
 │ └─ ⚡ ───── d1 d2 d3 d4
🔍  Sucessor [1-4, ação(ões), exe]: d1

┌─ ✅  Sucesso ────────
│ Executadas 1 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 3|10|8 ═══
♛   ::
  ::  ::
::  ::
  ::  ::
 │ └─ ⚡ ───── d3 d4
🔍  Sucessor [1-2, ação(ões), exe]: d4

┌─ ✅  Sucesso ────────
│ Executadas 1 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 5|13|10 ═══
♛   ::
  ::  ♛
::  ::
  ::  ::
 │ └─ ⚡ ───── d2
🔍  Sucessor [1-1, ação(ões), exe]: d2

┌─ ✅  Sucesso ────────
│ Executadas 1 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 7|14|11 ═══
♛   ::
  ::  ♛
::♛ ::
  ::  ::
 │ └─ ⚡ ─────
┌─ ℹ️  Informação ───
│ Sem sucessores.
└────────────────────
8 Damas
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
♛   ::
  ::  ♛
::♛ ::
  ::  ::
...
Opção:
```
Esta resolução correu mal e chegamos a um beco sem saida. 
Não há nenhuma coluna onde possa ser colocada a quarta dama sem que esteja atacada.

A escolha na primeira ação por d2 (ou d3), é crítica para obter a solução.

Neste problema a solução tem sempre o mesmo número de ações, igual a N.


\anchor 8damas-a3
## Ação 3 - Procura em Largura

Vamos fazer uma procura em largura, no tabuleiro de 4x4, debug completo. 
Vamos deixar desde já fixado o limite no número de iterações a 1000000. 
Introduza: **1; 4; 3; 2; 4; 5; 1000000; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 │ ::  ::
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d1 d2 d3 d4 { 🔖1 🔖2 🔖3 🔖4 }
 ├■═╤═ 🔖1 💰 g:1 🔢 1|4 ═══ { 🔖2 🔖3 🔖4 }
 │ ♛   ::
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d3 d4 { 🔖5 🔖6 }
 ├■═╤═ 🔖2 💰 g:1 🔢 2|6 ═══ { 🔖3 🔖4 🔖5 🔖6 }
 │ ::♛ ::
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d4 { 🔖7 }
 ├■═╤═ 🔖3 💰 g:1 🔢 3|7 ═══ { 🔖4 🔖5 🔖6 🔖7 }
 │ ::  ♛
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d1 { 🔖8 }
 ├■═╤═ 🔖4 💰 g:1 🔢 4|8 ═══ { 🔖5 🔖6 🔖7 🔖8 }
 │ ::  ::♛
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d1 d2 { 🔖9 🔖10 }
 ├■═╤═ 🔖5 💰 g:2 🔢 5|10 ═══ { 🔖6 🔖7 🔖8 🔖9 🔖10 }
 │ ♛   ::
 │   ::♛ ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ─────
 ├■═╤═ 🔖6 💰 g:2 🔢 6|10 ═══ { 🔖7 🔖8 🔖9 🔖10 }
 │ ♛   ::
 │   ::  ♛
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d2 { 🔖11 }
 ├■═╤═ 🔖7 💰 g:2 🔢 7|11 ═══ { 🔖8 🔖9 🔖10 🔖11 }
 │ ::♛ ::
 │   ::  ♛
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d1 { 🔖12 }
 ├■═╤═ 🔖8 💰 g:2 🔢 8|12 ═══ { 🔖9 🔖10 🔖11 🔖12 }
 │ ::  ♛
 │ ♛ ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d4 { 🔖13 }
 ├■═╤═ 🔖9 💰 g:2 🔢 9|13 ═══ { 🔖10 🔖11 🔖12 🔖13 }
 │ ::  ::♛
 │ ♛ ::  ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ───── d3 { 🔖14 }
 ├■═╤═ 🔖10 💰 g:2 🔢 10|14 ═══ { 🔖11 🔖12 🔖13 🔖14 }
 │ ::  ::♛
 │   ♛   ::
 │ ::  ::
 │   ::  ::
 │ └─ ⚡ ─────
 ├■═╤═ 🔖11 💰 g:3 🔢 11|14 ═══ { 🔖12 🔖13 🔖14 }
 │ ♛   ::
 │   ::  ♛
 │ ::♛ ::
 │   ::  ::
 │ └─ ⚡ ─────
 ├■═╤═ 🔖12 💰 g:3 🔢 12|14 ═══ { 🔖13 🔖14 }
 │ ::♛ ::
 │   ::  ♛
 │ ♛   ::
 │   ::  ::
 │ └─ ⚡ ───── d3 { 🔖15 }
 │  🎯 Solução encontrada! 💰  g:4
 │ ::♛ ::
 │   ::  ♛
 │ ♛   ::
 │   ::♛ ::
 ├─ ⚙️  Parâmetros ─ P1=1 P2=4 P3=1 P4=10 P5=1000000 P6=4 P7=0 P8=1 P11=0
═╧═ 🏁  Execução terminada ⏱  1ms  ═══
8 Damas
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4
│ P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
::♛ ::
  ::  ♛
♛   ::
  ::♛ ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 4 | I2(Tempo(ms)): 1 | I3(Iterações): 0 | I4(IND_EXPANSOES): 13 |
│ I5(IND_GERACOES): 15 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
A solução foi encontrada. No entanto, o algoritmo explora todos os estados do nível 3 antes de ver
o primeiro do nível 4. Neste problema, como a solução está no nível 4, acaba por não ser muito
interessante esta procura. Qualquer estado no nível 4 seria uma solução, e foram expandidos todos os
estados do nível 3. Não podia ser pior.

Não só este algoritmo gasta muito tempo nos níveis inferiores, a explorar completamente,
como a procura em profundidade ilimitada não tem problema, já que não existem ciclos infinitos.


\anchor 8damas-a4
## Ação 4 - Procura em Profundidade

Vamos executar a mesma instância com a procura em profundidade ilimitada.
Introduza: **1; 4; 3; 1; 3; 7; -1; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══
 │ ::  ::
 │   ::  ::
 │ ::  ::
 │   ::  ::
 │  ├■═╤═ 🔖1 💰 g:1 🔢 1|4 ═══ ⚡d1
 │  │ ♛   ::
 │  │   ::  ::
 │  │ ::  ::
 │  │   ::  ::
 │  │  ├■═╤═ 🔖5 💰 g:2 🔢 2|6 ═══ ⚡d3
 │  │  │ ♛   ::
 │  │  │   ::♛ ::
 │  │  │ ::  ::
 │  │  │   ::  ::
 │  │  │ 🍃
 │  │  └■═╤═ 🔖6 💰 g:2 🔢 3|6 ═══ ⚡d4
 │  │    ♛   ::
 │  │      ::  ♛
 │  │    ::  ::
 │  │      ::  ::
 │  │     └■═╤═ 🔖7 💰 g:3 🔢 4|7 ═══ ⚡d2
 │  │       ♛   ::
 │  │         ::  ♛
 │  │       ::♛ ::
 │  │         ::  ::
 │  │       🍃
 │  ├■═╤═ 🔖2 💰 g:1 🔢 5|7 ═══ ⚡d2
 │  │ ::♛ ::
 │  │   ::  ::
 │  │ ::  ::
 │  │   ::  ::
 │  │  └■═╤═ 🔖8 💰 g:2 🔢 6|8 ═══ ⚡d4
 │  │    ::♛ ::
 │  │      ::  ♛
 │  │    ::  ::
 │  │      ::  ::
 │  │     └■═╤═ 🔖9 💰 g:3 🔢 7|9 ═══ ⚡d1
 │  │       ::♛ ::
 │  │         ::  ♛
 │  │       ♛   ::
 │  │         ::  ::
 │  │        └■═╤═ 🔖10 💰 g:4 🔢 8|10 ═══ ⚡d3
 │  │          ::♛ ::
 │  │            ::  ♛
 │  │          ♛   ::
 │  │            ::♛ ::
 │  │           🎯 Solução encontrada! 💰  g:4
 │  │        │ ::♛ ::
 │  │        │   ::  ♛
 │  │        │ ♛   ::
 │  │        │   ::♛ ::
 │  │        │ 🎯 4 → 📈
 │  └─ { 🔖3 🔖4 }
 ├─ ⚙️  Parâmetros ─ P1=3 P2=4 P3=1 P4=10 P5=1000000 P6=4 P7=-1 P8=1 P11=0
═╧═ 🏁  Execução terminada ⏱   ═══
8 Damas
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Profundidade Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 4
│ P7(LIMITE): -1 | P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
::♛ ::
  ::  ♛
♛   ::
  ::♛ ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): 4 | I2(Tempo(ms)): 0 | I3(Iterações): 0 | I4(IND_EXPANSOES): 8 |
│ I5(IND_GERACOES): 10 | I6(IND_LOWER_BOUND): 0
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Podemos observar que o algoritmo em profundidade fez o mesmo erro que nós fizemos, foi escolher d1 na primeira ação.
No entanto, após ver que não é possível, testa a opção de d2 e encontra a solução.

Notar que os nós folha, foram atingidos por não haver sucessores na posição concreta, e não por
nível da árvore de procura, já que o limite foi colocado a -1, ou seja, ilimitado.

No final da procura, ainda havia um ramo para analisar, com dois estados pendentes.
Esses estados eram as ações d3 e d4 inicial, que são ações simétricas a d1 e d2.
Como temos  P8(ESTADOS_REPETIDOS): ignorar, estas ações são geradas.

Neste caso houve 8 expansões na procura em profundidade, contra 13 da procura em largura. 
Mas evidentemente que não será esta pequena instância que irá suportar as nossas conclusões. 
Temos um teste empírico na ação 6, com mais instâncias.

\anchor 8damas-a5
## Ação 5 - Heurística

Na abordagem construtiva, atendendo a que este problema tem o número de ações fixas, se as ações
tivessem custo variável, faria sentido uma heurística para estimar o custo até ao final. Sendo o custo fixo, 
apenas sabemos que se existir solução, a distância é conhecida e igual para todos os estados 
num determinado nível. Assim, não faz sentido construir uma heurítsica, nem ter procuras informadas
com a abordagem construtiva.

Podemos sempre considerar a hipótese de ter uma heurística ignorando a admissibilidade, apenas para guiar a procura.
No entanto neste problema não é claro que heurística possa ser.

Podemos ter no entanto outras opções que melhoram a abordagem construtiva. 
Uma das possibilidades é considerar ou não os estados repetidos. 
Neste problema temos 3 eixos de simetria. Significa que a mesma posição pode ao ser refletida em cada eixo,
transformar-se numa das outras, num total de 8 posições simétricas. 
Ao anular as simetrias por normalização do estado, e remoção de repetidos, o espaço de estados reduz-se.
As simetrias estão implementadas, pelo que vamos testar na próxima ação.

Outra possibilidade não implementada neste código, é a verificação se há linhas/colunas vazias, que 
estejam totalmente atacadas. Ao colocar duas ou três damas, estas podem cobrir a totalidade das casas
da última linha, e essa linha só é analisada no último nível. 
Esta implementação causa também mais peso, mas invalida estados antecipadamente. 

\anchor 8damas-a6
## Ação 6 - Testes Empíricos

Nos testes empíricos vamos passar para a interface da linha de comando, por ser mais simples.

Vamos obter primeiramente a lista de todos os parâmetros.

```entrada
/TProcura/Construtiva/Teste$ ./bin/Release/TProcuraConstrutiva -h

┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 3
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

Lista de parâmetros:
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Largura Primeiro ( 1 a  7)
│ P2(NIVEL_DEBUG):           NADA       ( 0 a  4)
│ P3(SEMENTE):               1          ( 1 a  1000000)
│ P4(LIMITE_TEMPO):          10         ( 1 a  3600)
│ P5(LIMITE_ITERACOES):      0          ( 0 a  1000000000)
│ P6(VER_ACOES):             4          ( 1 a  100)
│ P7(LIMITE):                0          (-1 a  1000000)
│ P8(ESTADOS_REPETIDOS):     ignorar    ( 1 a  3)
│ P11(BARALHAR_SUCESSORES):  0          ( 0 a  1)
└──────────────────────────────────────────────────────────────────────

Lista de indicadores:
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): ✔  1º lugar
│ o resultado é o custo da solução atual
│ I2(Tempo(ms)): ✔  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✔  3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_EXPANSOES): ✔  4º lugar
│ número de expansões efetuadas
│ I5(IND_GERACOES): ✔  5º lugar
│ número de estados gerados
│ I6(IND_LOWER_BOUND): ✔  6º lugar
│ valor mínimo para a melhor solução, se igual ao custo da solução obtida, então esta é ótima
└──────────────────────────────────────────────────────────────────────
```

Num primeiro teste pretendemos comparar a procura em largura com a procura em profundidade ilimitada, 
e respetivas versões com eliminação de estados repetidos.
Colocamos o P7=-1 para a procura em profundidade ilimitada, não afetando a procura em largura.
Colocamos debug nível 3.

```entrada
PS ...\Teste> TProcuraConstrutiva 4:13 -R Resultados/8Damast1 -P P2=3 P7=-1 P1=1,3 x P8=1,3
...
Opção: 3

 ├─ 🛠️  ─ P2=3 P3=1 P4=10 P5=0 P6=4 P7=-1 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P1=1 P8=1
 ├─ ⚙️ [2] ─ P1=3 P8=1
 ├─ ⚙️ [3] ─ P1=1 P8=3
 ├─ ⚙️ [4] ─ P1=3 P8=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:40   ↻ Instâncias: 10   🛠️ Configurações: 4   🖥️ Processos: 1.
HT: utilização 89%, reuso: 2.57 vezes
 ├─ 📄  Ficheiro Resultados/8Damast1.csv gravado.
 │  ⏱  Tempo real: 8" 534ms
 │  ⏱  CPU total: 8" 534ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  8" 534ms ) ═══
```

As 40 tarefas foram realizadas em menos de 10 segundos.

Soma de I2(Tempo(ms)):
| Rótulos de Linha | 1:Largura Primeiro<br> 1:ignorar | 3:gerados | 3:Profundidade Primeiro <br>1:ignorar | 3:gerados |
|:---:|---:|---:|---:|---:|
| 4 | 0 | 10 | 0 | 3 |
| 5 | 0 | 1 | 0 | 2 |
| 6 | 0 | 1 | 0 | 2 |
| 7 | 0 | 2 | 0 | 2 |
| 8 | 1 | 6 | 0 | 2 |
| 9 | 4 | 13 | 0 | 2 |
| 10 | 22 | 39 | 0 | 3 |
| 11 | 85 | 171 | 0 | 2 |
| 12 | 485 | 685 | 0 | 3 |
| 13 | 2984 | 3829 | 0 | 2 |
| Total Geral | 3581 | 4757 | 0 | 23 |


Podemos ver a clara superioridade da procura em profundidade ilimitada.
Todas as instâncias são resolvidas, mas em termos de tempo, a última leva 2 e 4 segundos pela procura em largura, e 0 segundos na procura em profundidade.

Soma de I4(Expansões):
| Rótulos de Linha | 1:Largura Primeiro<br> 1:ignorar | 3:gerados | 3:Profundidade Primeiro <br>1:ignorar | 3:gerados |
|:---:|---:|---:|---:|---:|
| 4 | 13 | 8 | 8 | 8 |
| 5 | 33 | 18 | 5 | 5 |
| 6 | 114 | 60 | 31 | 31 |
| 7 | 419 | 211 | 9 | 9 |
| 8 | 1665 | 839 | 113 | 113 |
| 9 | 6977 | 3490 | 41 | 41 |
| 10 | 30779 | 15392 | 102 | 102 |
| 11 | 149131 | 74567 | 52 | 52 |
| 12 | 773731 | 386869 | 261 | 261 |
| 13 | 4250877 | 2125440 | 111 | 111 |
| Total Geral | 5213739 | 2606894 | 733 | 733 |

Em termos de expansões, o máximo da procura em profundidade é algumas centenas, enquanto que a procur em largura tem na instância maior mais de um milhão de expansões.
A remoção de estados gerados repetidos, podemos observar na procura em largura que reduz em metade o número de expansões, mas duplica o tempo.

Não é possível com estas instâncias, observar diferença para a procura em profundidade. 

Vamos retirar as duas primeiras configurações do teste, para poder executar instâncias maiores.


```entrada
PS ...\Teste> TProcuraConstrutiva 14:23 -R Resultados/8Damast2 -P P2=3 P7=-1 P1=3 P8=1,3
...
Opção: 3

 ├─ 🛠️  ─ P1=3 P2=3 P3=1 P4=10 P5=0 P6=4 P7=-1 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P8=1
 ├─ ⚙️ [2] ─ P8=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:20   ↻ Instâncias: 10   🛠️ Configurações: 2   🖥️ Processos: 1.
 ├─ 📄  Ficheiro Resultados/8Damast2.csv gravado.
 │  ⏱  Tempo real: 3" 957ms
 │  ⏱  CPU total: 3" 957ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  3" 957ms ) ═══
```

| Rótulos de Linha | Soma de I2(Tempo(ms))<br>1:ignorar | 3:gerados | Soma de I4(Expansões)<br>1:ignorar | 3:gerados |
|:---:|---:|---:|---:|---:|
| 14 | 1 | 16 | 1899 | 1899 |
| 15 | 1 | 6 | 1359 | 1359 |
| 16 | 8 | 9 | 10052 | 2850 |
| 17 | 3 | 28 | 5374 | 5206 |
| 18 | 25 | 82 | 41299 | 28605 |
| 19 | 2 | 14 | 2545 | 4656 |
| 20 | 136 | 290 | 199635 | 112596 |
| 21 | 6 | 52 | 8562 | 20208 |
| 22 | 1285 | 1172 | 1737188 | 425154 |
| 23 | 18 | 802 | 25428 | 250250 |
| Total Geral | 1485 | 2471 | 2033341 | 852783 |


Podemos ver que o tempo continua menor se não se eliminarem os estados repetidos.
Na instância mais complexa, a 22, que levou 1.28 segundos, enquanto que com eliminação de repetidos foi 1,17 segundos.
No entanto, para essa instância o número de expansões foi de 1737188 ignorando repetidos, e de 425154 eliminando repetidos.
Em outras instâncias o tempo aparenta subir mais com os estados gerados, e só por sorte pode haver um resultado mais curto.

Confirma-se que neste problema, e também para o algoritmo em profundidade,
a eliminação de repetidos reduz o número de expansões, mas aumenta o tempo, não sendo compensador neste caso.

As instâncias pares aparentam ser mais complexas que as ímpares.

Qual é afinal a maior instância que se consegue resolver?
<details>
  <summary>Resposta:</summary>
Vamos usar apenas as instâncias pares, e até ao limite de 40, que é o que temos implementado. 
Utilizamos apenas a procura em profundidade ilimitada, sem eliminação de repetidos.
Vamos colcoar o debug a 4, já que são poucas tarefas.

```entrada
PS ...\Teste> TProcuraConstrutiva 24:40:2 -R Resultados/8Damast3 -P P2=4 P7=-1 P1=3 P8=1
...
Opção: 3

 ├─ 🛠️  ─ P1=3 P2=4 P3=1 P4=10 P5=0 P6=4 P7=-1 P8=1 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:9   ↻ Instâncias: 9   🛠️ Configurações: 1   🖥️ Processos: 1.
 ├─ ⏱                 📋 0     ↻ 24    🛠️ 0     🖥️ 1    🎯 24   ⚖  24 347 0 411608 411755 0
 ├─ ⏱ 347ms           📋 1     ↻ 26    🛠️ 0     🖥️ 1    🎯 26   ⚖  26 357 0 397699 397880 0
 ├─ ⏱ 704ms           📋 2     ↻ 28    🛠️ 0     🖥️ 1    🎯 28   ⚖  28 2787 0 3006298 3006508 0
 ├─ ⏱ 3" 491ms        📋 3     ↻ 30    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 10051598 10051835 0
 ├─ ⏱ 13" 491ms       📋 4     ↻ 32    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 9262352 9262634 0
 ├─ ⏱ 23" 491ms       📋 5     ↻ 34    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 8661432 8661748 0
 ├─ ⏱ 33" 491ms       📋 6     ↻ 36    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 8136140 8136498 0
 ├─ ⏱ 43" 492ms       📋 7     ↻ 38    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 7619227 7619631 0
 ├─ ⏱ 53" 492ms       📋 8     ↻ 40    🛠️ 0     🖥️ 1    🚫 ⏱ ⚖  -2 10000 0 7123911 7124371 0
 ├─ 📄  Ficheiro Resultados8Damast3.csv gravado.
 │  ⏱  Tempo real: 1' 3" 493ms
 │  ⏱  CPU total: 1' 3" 493ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  1' 3" 493ms ) ═══
```

Podemos ver logo nos logs do teste que consegue-se resolver até à instância 28 em 2,7 segundos.
Nas instâncias 30 a 40, não se consegue encontrar solução no limite de 10 segundos.

</details>


| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
