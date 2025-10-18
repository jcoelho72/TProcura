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
┌─ Teste TProcuraMelhorativa ──┐
│ 1 - 8 Damas (Inteira)        │
│ 2 - 8 Damas (Permutacao)     │
│ 3 - Partição (Binária)       │
└──────────────────────────────┘
Opção: 1
```


\anchor 8damas-ci1
## Ação 1 - Ver instâncias

Vamos entrar no problema 8 Damas Inteira, introduza: **1.**

```entrada
8 Damas (Inteira)
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20
│ P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50 | P9(SELECAO): Roleta | P10(PRESSAO): 150
│ P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100 | P16(ELITISMO): 1
│ P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
│ P20(TIPO_CRUZAR): 1-ponto | P21(TIPO_MUTAR): 0 | P22(TIPO_VIZINHO): incDecValor
│ P23(LIMITE_VIZINHOS): 0 | P24(TIPO_DISTANCIA): Hamming
└──────────────────────────────────────────────────────────────────────
::  ::  ::  ♛
  ::♛ ::  ::  ::
::  ::  ::  ::♛
♛ ::  ::  ::  ::
::  ::  ♛   ::
  ::  ::  ::♛ ::
::  ::  ♛   ::
  ::  ::  ::  ♛
┌─ ☰ Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```
Temos uma instância das 8 Damas como no exemplo da TProcuraConstrutiva. 
Em vez de um tabuleiro vazio, em que iamos construindo a solução adicionando damas, 
existem damas já colocadas mas que se atacam mutuamente.
Esta é uma solução completa aleatória, que pretendemos melhorar. 
Tem ainda violações, que são damas a atacarem-se, que neste contexto transfoormam-se em custos,
que pretendemos remover. 

Temos um número de parametros mais extenso,
embora os 5 primeiros parametros sejam os mesmos que no exemplo do teste TVector.
O último parametro é o P24, muito embora não estejam 24 parametros. 
O P11 por exemplo não é mostrado.
Alguns parametros só são ativos devido a valores de outros parametros.
Como temos o P1(ALGORITMO) em Algoritmos Evolutivos, este algoritmo tem muitos parametros, e por esse motivo
são mostrados bastantes. Iremos abordar cada um no momento próprio.

Vamos trocar para uma instância menor antes de avançarmos, para simplificar a nossa exploração.

Introduza: **1;4.**

```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 8  Intervalo: [4–40]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 4

8 Damas (Inteira)
...
::  ♛
  ::♛ ::
::  ::♛
♛ ::  ::
...
Opção:
```

Estavamos na instância 8 e agora estamos na instância 4. Temos um tabuleiro de 4x4 para colcoar 4 damas.
Podiamos ter escolhido até tabuleiros de 40x40.


\anchor 8damas-ci2
## Ação 2 - Resolver manualmente

Vamos então resolver a instância manualmente. Introduza: **2.**

```entrada
pção: 2

 │ 🏆 ⏱  💰 g:2
─┴───────────────────
♛   ::
  ::♛ ::
♛   ::
  ::  ♛
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   3 3 1 0  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │1   │2   │3   │4   │
 │ │ ────┼────┼────┼────┼────┼
 │ │ 1   │    │   4│   4│   4│
 │ │ 2   │   4│    │   3│   1│
 │ │ 3   │   4│   3│    │   3│
 │ │ 4   │   4│   1│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos):
```
Entramos num modo de expoloração manual, com as operações dos algoritmos melhorativos.
No entanto a população foi fixada a 4, para podermos melhor gerir a exploração manual.
Durante a geração da população de 4 elementos, foi encontrada uma solução de custo 2, mostrada.
Arranca a época 0 (linha: " ├─┬─ 📆 0 ⏱  ──── 💰 g2-4"), tal como os algoritmos evolutivos, mas neste caso cada época é o resultado de aplicar um operador.

Podemos ver a população de 4 elementos, com custos de 2 a 4.
É mostrado a codificação inteira, e não as soluções a que correspondem. 
Assim pretendemos focar no que os algoritmos vêm, e não na conversão na solução.

Na documentação não existem cores, ao executar num terminal que suporte, os 4 elementos têm cor de fundo,
e os custos têm cor para sinalizar os melhores elementos de forma visual.

Temos um mapa de diversidade, com as distâncias entre os 4 elemnentos. 
A medida de distancia de omissão é Hamming, significando que conta simplesmente os valores distintos.
Podemos alterar através do parametro P24(TIPO_DISTANCIA):. 
Há vários tipos de distâncias disponíveis dependendo da codificação.
Há dois elmentos à distância de 1 unidade, o 2 e 4. De facto, estes diferem apenas no valor do segundo inteiro.

Temos 3 operações para testar, a mutação, cruzamento e vizinhança.
Vamos começar pela mutação, para mutar o indivíduo 4. Introduza: **1; 4.**

```entrada
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): 1
 │ ┌───── ✨ ─────
 │ │ 🧑‍🔬 [1-4]: 4
 │ │ 📍  3 3 1 0  mutar vizinho incDecValor (3,1)
 │ │ ✨  3 3 1 1
 │ │ ::  ::♛
 │ │   ::  ♛
 │ │ ::♛ ::
 │ │   ♛   ::
 │ └──────────────
 ├─┬─ 📆 1 ⏱  ──── 💰 g2-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   3 3 1 1  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │1   │2   │3   │4   │
 │ │ ────┼────┼────┼────┼────┼
 │ │ 1   │    │   4│   4│   4│
 │ │ 2   │   4│    │   3│   2│
 │ │ 3   │   4│   3│    │   4│
 │ │ 4   │   4│   2│   4│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos):
```

A mutação acabou por trocar apenas um valor, o que se pode confirmar nas linhas Atual e Mutado,
com as codificaçõe seguidas e alinhadas.
Ficou uma solução igualmente má. 
Podemos alterar a mutação no parametro P21(TIPO_MUTAR). 
Existem também vários operadores de mutação disponíveis dependente do tipo de codificação.

Vamos agora passar para o cruzamento, e cruzar o individuo 1 com o 3,
os dois melhores na população, e substituir o individuo 4. 
Introduza: **2; 1; 3; 4.**

```entrada
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): 2
 │ ┌───── 🧬 ─────
 │ │ 🧑‍🔬 Pai [1-4]: 1
 │ │ 🧑‍🔬 Mãe [1-4]: 3
 │ │ 🧑‍🔬 Filho [1-4]: 4
 │ │
 │ │ 📍 Pai   0 2 0 3
 │ │ 📍 Mãe   1 0 3 0  cruzamento 1-ponto(s): 3
 │ │ 🧬 Filho 0 2 0 0
 │ │ ♛   ::
 │ │   ::♛ ::
 │ │ ♛   ::
 │ │ ♛ ::  ::
 │ └──────────────
 ├─┬─ 📆 2 ⏱ 1ms  ──── 💰 g2-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   0 2 0 0  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │1   │2   │3   │4   │
 │ │ ────┼────┼────┼────┼────┼
 │ │ 1   │    │   4│   4│   1│
 │ │ 2   │   4│    │   3│   3│
 │ │ 3   │   4│   3│    │   3│
 │ │ 4   │   1│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos):
```
O filho ficou quase igual ao pai, com os três primeiros elmentos da do pai, e o último da mãe. 
Existem vários tipos de operadores de cruzamento, controlados pelo parametro P20(TIPO_CRUZAR).
Diferentes operadores estão disponíveis em diferentes codificações, podendo cada operador ter também parâmetros próprios.

Falta-nos explorar o operador de vizinhança, pelo que vamos aplicar ao melhor individuo 1, e escolher o melhor vizinho. 
Introduza: **3; 1; 1.**

```entrada
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): 3
 │ ┌───── 🔗 ─────
 │ │ 🧑‍🔬 [1-4]: 1
 │ │ 📍  0 2 0 3  vizinhança incDecValor (limite 0)
 │ ├───── 🔗 Vizinhos ─────
 │ │ 🧑‍🔬 1   1 2 0 3  💰 g:1
 │ │ 🧑‍🔬 2   0 3 0 3  💰 g:3
 │ │ 🧑‍🔬 3   0 1 0 3  💰 g:5
 │ │ 🧑‍🔬 4   0 2 1 3  💰 g:2
 │ │ 🧑‍🔬 5   0 2 0 2  💰 g:2
 │ │ 🧑‍🔬 [1-5]: 1
 │ │
 │ 🏆 ⏱ 1ms  💰 g:1
─┴───────────────────
 │ │ ::♛ ::
 │ │   ::♛ ::
 │ │ ♛   ::
 │ │   ::  ♛
─┬───────────────────
 │ └──────────────
 ├─┬─ 📆 3 ⏱ 1ms  ──── 💰 g1-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   1 2 0 3  💰 g:1
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   0 2 0 0  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │1   │2   │3   │4   │
 │ │ ────┼────┼────┼────┼────┼
 │ │ 1   │    │   4│   3│   2│
 │ │ 2   │   4│    │   3│   3│
 │ │ 3   │   3│   3│    │   3│
 │ │ 4   │   2│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos):
```

O vizinho gerado tem custo 1, pelo que estamos mais perto. 
Foi feita a substituição da melhor solução.
Notar que o tipo de vizinhança é descrito, neste caso apenas incrementamos ou decrementamos cada valor em uma unidade.
Devido a esta opção, a vizinhança tem um número controlado de indivíduos.

Vamos insistir e ver os vizinhos deste novo elemento, e novamente escolher o melhor destes.
Introduza: **3; 1; 3.**

```entrada
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): 3
 │ ┌───── 🔗 ─────
 │ │ 🧑‍🔬 [1-4]: 1
 │ │ 📍  1 2 0 3  vizinhança incDecValor (limite 0)
 │ ├───── 🔗 Vizinhos ─────
 │ │ 🧑‍🔬 1   2 2 0 3  💰 g:2
 │ │ 🧑‍🔬 2   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 3   1 3 0 3  💰 g:1
 │ │ 🧑‍🔬 4   1 1 0 3  💰 g:3
 │ │ 🧑‍🔬 5   1 2 1 3  💰 g:3
 │ │ 🧑‍🔬 6   1 2 0 2  💰 g:2
 │ │ 🧑‍🔬 [1-6]: 3
 │ │
 │ │ ::♛ ::
 │ │   ::  ♛
 │ │ ♛   ::
 │ │   ::  ♛
 │ └──────────────
 ├─┬─ 📆 4 ⏱ 2ms  ──── 💰 g1-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   1 3 0 3  💰 g:1
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   0 2 0 0  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │1   │2   │3   │4   │
 │ │ ────┼────┼────┼────┼────┼
 │ │ 1   │    │   4│   3│   3│
 │ │ 2   │   4│    │   3│   3│
 │ │ 3   │   3│   3│    │   3│
 │ │ 4   │   3│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos):
```

Neste caso o vizinho tem o mesmo custo, mas é outro vizinho,
pelo que vale a pena ainda uma última vez, ver quais os seus vizinhos.
Introduza: **3; 1; 5.**

```entrada
 │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): 3
 │ ┌───── 🔗 ─────
 │ │ 🧑‍🔬 [1-4]: 1
 │ │ 📍  1 3 0 3  vizinhança incDecValor (limite 0)
 │ ├───── 🔗 Vizinhos ─────
 │ │ 🧑‍🔬 1   2 3 0 3  💰 g:3
 │ │ 🧑‍🔬 2   0 3 0 3  💰 g:3
 │ │ 🧑‍🔬 3   1 2 0 3  💰 g:1
 │ │ 🧑‍🔬 4   1 3 1 3  💰 g:2
 │ │ 🧑‍🔬 5   1 3 0 2  💰 g:0
 │ │ 🧑‍🔬 [1-5]: 5
 │ │
 │ 🏆 ⏱ 2ms  💰 g:0
─┴───────────────────
 │ │ ::♛ ::
 │ │   ::  ♛
 │ │ ♛   ::
 │ │   ::♛ ::
─┬───────────────────
 │ └──────────────  
8 Damas (Inteira)
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20
│ P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50 | P9(SELECAO): Roleta | P10(PRESSAO): 150
│ P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100 | P16(ELITISMO): 1
│ P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
│ P20(TIPO_CRUZAR): 1-ponto | P21(TIPO_MUTAR): 0 | P22(TIPO_VIZINHO): incDecValor
│ P23(LIMITE_VIZINHOS): 0 | P24(TIPO_DISTANCIA): Hamming
└──────────────────────────────────────────────────────────────────────
::♛ ::
  ::  ♛
♛   ::
  ::♛ ::
┌─ ☰ Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
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

═╤═ ►  Execução iniciada ═══
 ├─ ⚙️  Parâmetros ─ P1=1 P2=0 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1
═╧═ 🏁  Execução terminada ⏱   ═══
8 Damas (Inteira)
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20
│ P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50 | P9(SELECAO): Roleta | P10(PRESSAO): 150
│ P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100 | P16(ELITISMO): 1
│ P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
│ P20(TIPO_CRUZAR): 1-ponto | P21(TIPO_MUTAR): 0 | P22(TIPO_VIZINHO): incDecValor
│ P23(LIMITE_VIZINHOS): 0 | P24(TIPO_DISTANCIA): Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 0 | I2(Tempo(ms)): 0 | I3(Iterações): 241 | I4(Épocas): 10 |
│ I5(Gerações): 250
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Podemos ver que o primeiro indicador, I1(Resultado) é igual a 0. Este é o custo da solução.
Podemos observar a solução e ver que as damas não se atacam, aliás, é exatamente a mesma solução obtida manualmente.

O segundo indicador I2(Tempo(ms)) é 0, o que significa que foi consumido menos de 1 milisegundo.

Temos o número de iterações a 241, que corresponde às avaliações efetuadas, e 10 épocas,
o que corresponde ao número de ciclos do algoritmo evolutivo.
Finalmente, temos o número de estados gerados a 250.

Há informação visivel nos indicadores, mas não vemos nada em termos de funcionamento do algoritmo. 
O que aconteceu nestas 10 épocas?
Vendo a parametrização podemos ver que há população de 20, e toda a informação de operadores e opções.
Mas estaremos satisfeitos com esta informação?
Não, precisamos de ver o que se passou, para saber o que correu bem e menos bem.

Como podemos repetir todas as execuções, podemos ver a mesma execução com diferentes níveis de detalhe.
Vamos aproveitar esta execução que tem tamanho reduzido, para ir subindo o nível de debug.
Introduza: **1; 4; 3; 2; 1; *ENTER*; 6.**


```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══.
 │ 🏆 ⏱  💰 g:2
─┴───────────────────
♛   ::
  ::♛ ::
♛   ::
  ::  ♛
─┬───────────────────
 │ 🏆 ⏱  💰 g:1
─┴───────────────────
♛   ::
  ::♛ ::
::  ::♛
  ♛   ::
─┬───────────────────
 │ 🏆 ⏱  💰 g:0
─┴───────────────────
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
─┬───────────────────
 ├─ ⚙️  Parâmetros ─ P1=1 P2=1 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1
═╧═ 🏁  Execução terminada ⏱   ═══
8 Damas (Inteira)
...
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 0 | I2(Tempo(ms)): 0 | I3(Iterações): 241 | I4(Épocas): 10 |
│ I5(Gerações): 250
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Nesta repetição vemos um ponto de quando em quando, para saber que há atividade. 
No final são introduzidos 128 pontos, se o número de iterações for atingido.
Como gastamos muito poucas iterações e o limite é muito alto, estes pontos nem são visiveis.

Mas vemos algo importante. Sempre que se encontra uma melhor solução global,
é registado o tempo e a solução é mostrada ao utilizador.
Podemos ver que primeiro foi encontrada uma solução de custo 2,
de seguida outra de custo 1 e finalmente a de custo 0.

Sabemos mais alguma coisa do que se passou, mas não muito.

Vamos ver agora o nível de debug PASSOS.
Introduza: **1; 4; 3; 2; 2; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 │ 🏆 ⏱  💰 g:2
─┴───────────────────
♛   ::
  ::♛ ::
♛   ::
  ::  ♛
─┬───────────────────
 ├─── 📆 0 ⏱  ──── 💰 g2-5
 │ 🏆 ⏱  💰 g:1
─┴───────────────────
♛   ::
  ::♛ ::
::  ::♛
  ♛   ::
─┬───────────────────
 ├─── 📆 1 ⏱  ──── 💰 g1-5
 ├─── 📆 2 ⏱  ──── 💰 g1-5
 ├─── 📆 3 ⏱  ──── 💰 g1-5
 ├─── 📆 4 ⏱  ──── 💰 g1-5
 ├─── 📆 5 ⏱ 1ms  ──── 💰 g1-5
 ├─── 📆 6 ⏱ 1ms  ──── 💰 g1-4
 ├─── 📆 7 ⏱ 1ms  ──── 💰 g1-5
 ├─── 📆 8 ⏱ 1ms  ──── 💰 g1-5
 ├─── 📆 9 ⏱ 1ms  ──── 💰 g1-4
 │ 🏆 ⏱ 1ms  💰 g:0
─┴───────────────────
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
─┬───────────────────
 ├─ ⚙️  Parâmetros ─ P1=1 P2=2 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1
═╧═ 🏁  Execução terminada ⏱  1ms  ═══
8 Damas (Inteira)
...
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 0 | I2(Tempo(ms)): 1 | I3(Iterações): 241 | I4(Épocas): 10 |
│ I5(Gerações): 250
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Temos agora a informação das diferentes épocas. 
Em cada época é registado o instante em que esta ocorre, neste caso apenas alguns milisegundos,
o número da época, e o menor e maior custo na população.

Aqui é possível observar que nesta procura, a melhor solução na população nunca piorou de uma época para a outra.
Dependente da parametrização, nem sempre esta situação é garantida.
A utilização de P16(ELITISMO)=1 garante
que pelo menos um elemento da população antiga,
irá manter-se caso na nova população não exista nenhum elemento com valor melhor ou igual.

Aumentamos o conhecimento, mas ainda estamos um pouco às escuras. 
Fora o parametro do elitismo, nada mais pode ser observado ou verificada a sua utilidade.

É tempo para aumentar o nível de debug para DETALHE.
Introduza: **1; 4; 3; 2; 3; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 │ 🏆 ⏱  💰 g:2
─┴───────────────────
♛   ::
  ::♛ ::
♛   ::
  ::  ♛
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   2│   4│   3│   4│   4│   2│   3│   2│   4│   2│
 │ │  10│   2│   4│   2│   5│   3│   2│   5│   3│   5│   4│
 │ └────────────────────────────────────
 │ 🏆 ⏱  💰 g:1
─┴───────────────────
♛   ::
  ::♛ ::
::  ::♛
  ♛   ::
─┬───────────────────
 ├─┬─ 📆 1 ⏱ 1ms  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   1│   4│   4│   4│   3│   2│   5│   4│   3│   2│
 │ │  10│   4│   4│   2│   3│   2│   2│   3│   4│   4│   3│
 │ └────────────────────────────────────
 ├─┬─ 📆 2 ⏱ 1ms  ──── 💰 g1-5 [📏 1-4 (μ=3, melhor/pior 3)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   2│   4│   3│   5│   2│   3│   4│   3│   3│   4│
 │ │  10│   4│   3│   2│   2│   4│   1│   3│   2│   4│   2│
 │ └────────────────────────────────────
 ├─┬─ 📆 3 ⏱ 1ms  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   4│   3│   5│   3│   4│   2│   1│   4│   4│   3│
 │ │  10│   3│   1│   3│   3│   3│   3│   2│   4│   2│   4│
 │ └────────────────────────────────────
 ├─┬─ 📆 4 ⏱ 1ms  ──── 💰 g1-5 [📏 0-4 (μ=2, melhor/pior 2)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   4│   2│   1│   2│   3│   1│   4│   4│   3│   3│
 │ │  10│   4│   3│   3│   3│   1│   5│   3│   3│   2│   4│
 │ └────────────────────────────────────
 ├─┬─ 📆 5 ⏱ 1ms  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   1│   4│   1│   3│   3│   4│   2│   4│   4│   1│
 │ │  10│   4│   2│   4│   3│   3│   3│   5│   2│   3│   4│
 │ └────────────────────────────────────
 ├─┬─ 📆 6 ⏱ 1ms  ──── 💰 g1-4 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   3│   4│   3│   2│   4│   2│   1│   4│   1│   2│
 │ │  10│   4│   3│   1│   3│   4│   3│   2│   3│   1│   3│
 │ └────────────────────────────────────
 ├─┬─ 📆 7 ⏱ 1ms  ──── 💰 g1-5 [📏 0-4 (μ=2, melhor/pior 4)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   3│   3│   4│   4│   2│   3│   3│   2│   1│   5│
 │ │  10│   4│   3│   4│   1│   2│   1│   1│   3│   5│   4│
 │ └────────────────────────────────────
 ├─┬─ 📆 8 ⏱ 2ms  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   5│   2│   4│   4│   4│   3│   4│   1│   5│   1│
 │ │  10│   1│   4│   3│   3│   3│   1│   3│   4│   3│   4│
 │ └────────────────────────────────────
 ├─┬─ 📆 9 ⏱ 2ms  ──── 💰 g1-4 [📏 0-4 (μ=2, melhor/pior 2)]
 │ │🧑‍🔬💰│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│   2│   3│   2│   3│   2│   2│   1│   1│   2│   2│
 │ │  10│   4│   3│   2│   3│   4│   2│   2│   3│   2│   3│
 │ └────────────────────────────────────
 │ 🏆 ⏱ 2ms  💰 g:0
─┴───────────────────
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
─┬───────────────────
 ├─ ⚙️  Parâmetros ─ P1=1 P2=3 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1
═╧═ 🏁  Execução terminada ⏱  2ms  ═══
8 Damas (Inteira)
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): DETALHE | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20
│ P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50 | P9(SELECAO): Roleta | P10(PRESSAO): 150
│ P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100 | P16(ELITISMO): 1
│ P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
│ P20(TIPO_CRUZAR): 1-ponto | P21(TIPO_MUTAR): 0 | P22(TIPO_VIZINHO): incDecValor
│ P23(LIMITE_VIZINHOS): 0 | P24(TIPO_DISTANCIA): Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛
♛ ::  ::
::  ::♛
  ♛   ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 0 | I2(Tempo(ms)): 2 | I3(Iterações): 241 | I4(Épocas): 10 |
│ I5(Gerações): 250
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Temos agora uma tabela para cada época e informação sobre as distâncias.
Na época 0 sabemos que as distâncias entre indivíduos vão de 1 a 4, a média das distâncias é 2,
e a distância entre o melhor e o pior indivíduo é 3.

A cada linha da época segue-se agora uma tabela "🧑‍🔬💰".
Esta tabela tem para cada um dos 20 indivíduos na população o seu custo.
Tem 10 colunas e tantas linhas quantas necessárias, uma por cada dezena de indivíduos. 
O indivíduo 14 está na linha com índice 10 e coluna com índice 4, que na época 0 tinha custo 5.

Assim, podemos ter uma ideia mais detalhada dos custos dos indivíduos, e uma ideia da diversidade.
Se a diversidade da população for muito baixa, podemos observar a média de distâncias com valor baixo.
Se apenas alguns elementos tiverem um bom valor, e a maior parte tiver um valor mau, podemos também observar.

Idealmente pretendemos uma diversidade alta e alto valor nos indivíduos, portanto baixo custo.
Por vezes o que ocorre num problema mal afinado, é que todas as soluções ficam com o mesmo valor, e a diversidade seja muito baixa.
Nesse caso o algoritmo fica estagnado, sendo essa a situação mais crítica a evitar.

Embora possamos observar a situação mais indesejáveis que pode ocorrer num algoritmo evolutivo, a estagnação,
nada sabemos sobre os indivíduos concretos, e o que se passa de uma população para a outra.

Há várias fases para passar de uma época para a outra, e muitos operadores são aplicados. 
Mas isso é interno aos algoritmos evolutivos, nada é visivel neste nível de debug.

É portanto tempo para passarmos para o último nível de debug, COMPLETO.
Introduza:  **1; 4; 3; 2; 4; *ENTER*; 6.**

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 │ 🏆 ⏱  💰 g:2
─┴───────────────────
♛   ::
  ::♛ ::
♛   ::
  ::  ♛
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-5
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 2   3 1 1 0  💰 g:4
 │ │ 🧑‍🔬 3   1 0 3 0  💰 g:3
 │ │ 🧑‍🔬 4   3 3 1 0  💰 g:4
 │ │ 🧑‍🔬 5   3 1 2 3  💰 g:4
 │ │ 🧑‍🔬 6   3 0 2 3  💰 g:2
 │ │ 🧑‍🔬 7   3 0 3 0  💰 g:3
 │ │ 🧑‍🔬 8   2 0 2 3  💰 g:2
 │ │ 🧑‍🔬 9   0 0 0 3  💰 g:4
 │ │ 🧑‍🔬 10  3 0 0 2  💰 g:2
 │ │ 🧑‍🔬 11  0 3 1 1  💰 g:2
 │ │ 🧑‍🔬 12  1 2 3 0  💰 g:4
 │ │ 🧑‍🔬 13  2 3 3 0  💰 g:2
 │ │ 🧑‍🔬 14  0 0 1 0  💰 g:5
 │ │ 🧑‍🔬 15  0 3 0 0  💰 g:3
 │ │ 🧑‍🔬 16  3 0 0 3  💰 g:2
 │ │ 🧑‍🔬 17  1 2 1 2  💰 g:5
 │ │ 🧑‍🔬 18  3 0 1 1  💰 g:3
 │ │ 🧑‍🔬 19  1 2 1 0  💰 g:5
 │ │ 🧑‍🔬 20  0 0 2 2  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │ 🧑‍🔬 │ 📏 │
 │ │ ────┼────┼────┼
 │ │ 17  │13  │   4│
 │ │ 14  │18  │   2│
 │ │ 1   │19  │   3│
 │ │ 6   │15  │   4│
 │ │ 12  │3   │   1│
 │ │ 2   │9   │   4│
 │ │ 10  │8   │   3│
 │ │ 4   │20  │   4│
 │ │ 11  │7   │   4│
 │ │ 16  │5   │   2│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🎯 Selecionar 20 🧑‍🤝‍🧑 pais ─────
 │ │ ├───── Roleta, pressão 150 ─────
 │ │ │ 100%│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  75│  38│  49│  41│  43│  59│  51│  64│  33│  62│
 │ │ │   10│  72│  46│  70│  25│  54│  67│  28│  57│  30│  36│
 │ │ ├───── Número de seleções ─────
 │ │ │ #Pai│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   1│   1│   1│   1│   1│   1│   1│   1│   1│   1│
 │ │ │   10│   1│   1│   2│   0│   1│   2│   0│   1│   1│   1│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE Reproduzir 20 pais ─────
 │ │ ├───── Pais (🧑‍🤝‍🧑) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  12⇄  16│  15⇄  16│   9⇄   4│   6⇄  11│   3⇄  13│
 │ │ │   10│   5⇄   7│  18⇄  13│   2⇄  19│  10⇄   8│  20⇄   1│
 │ 🏆 ⏱ 1ms  💰 g:1
─┴───────────────────
::  ♛
♛ ::  ::
::  ::♛
♛ ::  ::
─┬───────────────────
 │ │ ├───── Pais (💰) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   4⇄   2│   3⇄   2│   4⇄   4│   2⇄   2│   3⇄   2│
 │ │ │   10│   4⇄   3│   3⇄   2│   4⇄   5│   2⇄   2│   4⇄   2│
 │ │ ├───── Filhos (💰) 🧬10  ✨9 ───── 📈3 ➖12 📉5
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   4⇄   2│   3⇄   2│   5⇄   4│   2⇄   4│   2⇄   2│
 │ │ │   10│   1⇄   2│   2⇄   4│   3⇄   5│   4⇄   4│   4⇄   2│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE 🛡️ Sobrevivência ─────
 │ │ ├───── ⏳ Idade ─────
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  12✖ →🆕 ─────
 │ │ └────────────────────────────────────
 │ └───── FASE Diversidade - limpeza ─────  🧹✖ 18
 ├─┬─ 📆 1 ⏱ 1ms  ──── 💰 g1-5
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 2 2  💰 g:4
 │ │ 🧑‍🔬 2   0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 3   2 0 3 2  💰 g:3
 │ │ 🧑‍🔬 4   3 0 2 3  💰 g:2
 │ │ 🧑‍🔬 5   1 2 1 0  💰 g:5
 │ │ 🧑‍🔬 6   3 3 1 0  💰 g:4
 │ │ 🧑‍🔬 7   2 0 1 1  💰 g:2
 │ │ 🧑‍🔬 8   3 3 3 0  💰 g:4
 │ │ 🧑‍🔬 9   3 0 2 0  💰 g:2
 │ │ 🧑‍🔬 10  3 1 2 0  💰 g:2
 │ │ 🧑‍🔬 11  2 0 3 0  💰 g:1
 │ │ 🧑‍🔬 12  2 0 2 3  💰 g:2
 │ │ 🧑‍🔬 13  3 3 1 1  💰 g:4
 │ │ 🧑‍🔬 14  3 1 0 3  💰 g:3
 │ │ 🧑‍🔬 15  3 0 1 0  💰 g:5
 │ │ 🧑‍🔬 16  3 0 0 0  💰 g:4
 │ │ 🧑‍🔬 17  0 0 0 3  💰 g:4
 │ │ 🧑‍🔬 18  3 0 0 3  💰 g:2
 │ │ 🧑‍🔬 19  3 3 0 0  💰 g:3
 │ │ 🧑‍🔬 20  0 2 0 1  💰 g:2
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │ 🧑‍🔬 │ 📏 │
 │ │ ────┼────┼────┼
 │ │ 10  │19  │   2│
 │ │ 6   │9   │   2│
 │ │ 7   │2   │   4│
 │ │ 3   │8   │   3│
 │ │ 11  │14  │   4│
 │ │ 20  │16  │   3│
 │ │ 17  │12  │   2│
 │ │ 1   │13  │   4│
 │ │ 15  │4   │   2│
 │ │ 5   │18  │   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🎯 Selecionar 20 🧑‍🤝‍🧑 pais ─────
 │ │ ├───── Roleta, pressão 150 ─────
 │ │ │ 100%│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  33│  54│  51│  57│  25│  36│  62│  38│  64│  72│
 │ │ │   10│  75│  70│  30│  49│  28│  41│  43│  67│  46│  59│
 │ │ ├───── Número de seleções ─────
 │ │ │ #Pai│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   1│   1│   1│   1│   1│   0│   2│   0│   2│   1│
 │ │ │   10│   2│   1│   1│   1│   0│   1│   1│   1│   1│   1│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE Reproduzir 20 pais ─────
 │ │ ├───── Pais (🧑‍🤝‍🧑) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  10⇄  12│  13⇄   4│  16⇄   5│   2⇄  17│  19⇄  20│
 │ │ │   10│  11⇄  11│  18⇄  14│   7⇄   7│   3⇄   9│   1⇄   9│
 │ │ ├───── Pais (💰) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   2│   4⇄   2│   4⇄   5│   2⇄   4│   3⇄   2│
 │ │ │   10│   1⇄   1│   2⇄   3│   2⇄   2│   3⇄   2│   4⇄   2│
 │ │ ├───── Filhos (💰) 🧬10  ✨10 ───── 📈3 ➖10 📉7
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   4⇄   2│   2⇄   2│   2⇄   3│   2⇄   2│   4⇄   1│
 │ │ │   10│   3⇄   2│   2⇄   4│   4⇄   5│   3⇄   2│   2⇄   2│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE 🛡️ Sobrevivência ─────
 │ │ ├───── ⏳ Idade ─────
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  20✖ →🆕 ─────
 │ │ └────────────────────────────────────
 │ └───── FASE Diversidade - limpeza ─────  🧹✖ 18 🧹✖ 8 🧹✖ 15
 ├─┬─ 📆 2 ⏱ 1ms  ──── 💰 g1-6
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   0 2 2 3  💰 g:4
 │ │ 🧑‍🔬 2   3 0 2 3  💰 g:2
 │ │ 🧑‍🔬 3   3 0 2 2  💰 g:2
 │ │ 🧑‍🔬 4   3 0 2 0  💰 g:2
 │ │ 🧑‍🔬 5   2 0 1 1  💰 g:2
 │ │ 🧑‍🔬 6   2 0 0 1  💰 g:3
 │ │ 🧑‍🔬 7   3 0 0 3  💰 g:2
 │ │ 🧑‍🔬 8   2 0 0 0  💰 g:4
 │ │ 🧑‍🔬 9   2 0 3 0  💰 g:1
 │ │ 🧑‍🔬 10  0 3 0 0  💰 g:3
 │ │ 🧑‍🔬 11  0 2 1 1  💰 g:2
 │ │ 🧑‍🔬 12  0 2 0 3  💰 g:2
 │ │ 🧑‍🔬 13  0 0 0 3  💰 g:4
 │ │ 🧑‍🔬 14  1 2 1 1  💰 g:5
 │ │ 🧑‍🔬 15  2 3 1 1  💰 g:3
 │ │ 🧑‍🔬 16  2 0 2 0  💰 g:2
 │ │ 🧑‍🔬 17  0 3 2 1  💰 g:4
 │ │ 🧑‍🔬 18  0 1 1 1  💰 g:4
 │ │ 🧑‍🔬 19  2 3 3 2  💰 g:4
 │ │ 🧑‍🔬 20  3 2 1 0  💰 g:6
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │ 🧑‍🔬 │ 📏 │
 │ │ ────┼────┼────┼
 │ │ 1   │16  │   3│
 │ │ 10  │18  │   3│
 │ │ 6   │17  │   3│
 │ │ 13  │20  │   4│
 │ │ 4   │11  │   4│
 │ │ 12  │7   │   2│
 │ │ 9   │14  │   4│
 │ │ 2   │19  │   4│
 │ │ 3   │5   │   3│
 │ │ 15  │8   │   3│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🎯 Selecionar 20 🧑‍🤝‍🧑 pais ─────
 │ │ ├───── Roleta, pressão 150 ─────
 │ │ │ 100%│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  38│  59│  62│  57│  64│  49│  54│  33│  75│  51│
 │ │ │   10│  67│  70│  36│  28│  46│  72│  43│  41│  30│  25│
 │ │ ├───── Número de seleções ─────
 │ │ │ #Pai│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   1│   1│   2│   1│   1│   1│   1│   1│   1│   1│
 │ │ │   10│   2│   1│   1│   0│   1│   2│   1│   0│   1│   0│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE Reproduzir 20 pais ─────
 │ │ ├───── Pais (🧑‍🤝‍🧑) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  12⇄   5│  15⇄   8│   9⇄  17│  11⇄  16│   1⇄  10│
 │ │ │   10│   6⇄  11│   3⇄   2│  16⇄   4│  13⇄   3│   7⇄  19│
 │ │ ├───── Pais (💰) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   2│   3⇄   4│   1⇄   4│   2⇄   2│   4⇄   3│
 │ │ │   10│   3⇄   2│   2⇄   2│   2⇄   2│   4⇄   2│   2⇄   4│
 │ │ ├───── Filhos (💰) 🧬10  ✨13 ───── 📈0 ➖15 📉5
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   4⇄   5│   4⇄   3│   4⇄   2│   4⇄   5│   4⇄   3│
 │ │ │   10│   3⇄   3│   2⇄   5│   2⇄   2│   3⇄   4│   2⇄   3│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE 🛡️ Sobrevivência ─────
 │ │ ├───── ⏳ Idade ─────
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  1✖ →🆕 ─────
 │ │ ├───── 👑 Elite 9→5 ─────
 │ │ └────────────────────────────────────
 │ └───── FASE Diversidade - limpeza ─────
 ├─┬─ 📆 3 ⏱ 2ms  ──── 💰 g1-5
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   2 2 3 2  💰 g:5
 │ │ 🧑‍🔬 2   0 0 0 2  💰 g:4
 │ │ 🧑‍🔬 3   0 0 3 2  💰 g:3
 │ │ 🧑‍🔬 4   0 0 2 0  💰 g:4
 │ │ 🧑‍🔬 5   2 0 3 0  💰 g:1
 │ │ 🧑‍🔬 6   0 0 2 2  💰 g:4
 │ │ 🧑‍🔬 7   3 3 2 3  💰 g:5
 │ │ 🧑‍🔬 8   2 0 0 0  💰 g:4
 │ │ 🧑‍🔬 9   0 2 2 1  💰 g:3
 │ │ 🧑‍🔬 10  0 3 0 3  💰 g:3
 │ │ 🧑‍🔬 11  0 3 0 0  💰 g:3
 │ │ 🧑‍🔬 12  0 2 1 1  💰 g:2
 │ │ 🧑‍🔬 13  1 2 1 0  💰 g:5
 │ │ 🧑‍🔬 14  0 3 3 0  💰 g:2
 │ │ 🧑‍🔬 15  2 0 2 1  💰 g:2
 │ │ 🧑‍🔬 16  2 3 1 2  💰 g:3
 │ │ 🧑‍🔬 17  2 3 0 1  💰 g:4
 │ │ 🧑‍🔬 18  2 2 0 3  💰 g:2
 │ │ 🧑‍🔬 19  0 0 1 1  💰 g:3
 │ │ 🧑‍🔬 20  1 2 0 1  💰 g:3
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │ 🧑‍🔬 │ 📏 │
 │ │ ────┼────┼────┼
 │ │ 3   │16  │   3│
 │ │ 2   │10  │   2│
 │ │ 14  │17  │   3│
 │ │ 7   │1   │   4│
 │ │ 15  │11  │   4│
 │ │ 9   │8   │   4│
 │ │ 20  │18  │   2│
 │ │ 19  │12  │   1│
 │ │ 6   │4   │   1│
 │ │ 13  │5   │   3│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🎯 Selecionar 20 🧑‍🤝‍🧑 pais ─────
 │ │ ├───── Roleta, pressão 150 ─────
 │ │ │ 100%│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  25│  41│  46│  36│  75│  33│  28│  38│  49│  62│
 │ │ │   10│  57│  70│  30│  64│  72│  59│  43│  67│  54│  51│
 │ │ ├───── Número de seleções ─────
 │ │ │ #Pai│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   1│   1│   1│   0│   2│   1│   0│   1│   1│   1│
 │ │ │   10│   1│   2│   0│   2│   1│   1│   1│   1│   1│   1│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE Reproduzir 20 pais ─────
 │ │ ├───── Pais (🧑‍🤝‍🧑) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  14⇄   8│  16⇄   5│   2⇄  19│  12⇄  18│  17⇄   5│
 │ │ │   10│  20⇄   9│  14⇄  11│   3⇄   6│  15⇄  12│   1⇄  10│
 │ │ ├───── Pais (💰) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   4│   3⇄   1│   4⇄   3│   2⇄   2│   4⇄   1│
 │ │ │   10│   3⇄   3│   2⇄   3│   3⇄   4│   2⇄   2│   5⇄   3│
 │ │ ├───── Filhos (💰) 🧬10  ✨8 ───── 📈4 ➖13 📉3
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   2│   3⇄   3│   4⇄   4│   2⇄   2│   2⇄   4│
 │ │ │   10│   4⇄   3│   4⇄   1│   4⇄   2│   4⇄   1│   1⇄   3│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE 🛡️ Sobrevivência ─────
 │ │ ├───── ⏳ Idade ─────
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  9✖ →🆕 ─────
 │ │ └────────────────────────────────────
 │ └───── FASE Diversidade - limpeza ─────  🧹✖ 14 🧹✖ 8 🧹✖ 18
 ├─┬─ 📆 4 ⏱ 2ms  ──── 💰 g1-4
 │ ├───── 👥 ─────
 │ │ 🧑‍🔬 1   2 2 3 1  💰 g:2
 │ │ 🧑‍🔬 2   2 2 0 3  💰 g:2
 │ │ 🧑‍🔬 3   0 0 2 1  💰 g:3
 │ │ 🧑‍🔬 4   2 2 1 1  💰 g:3
 │ │ 🧑‍🔬 5   0 0 0 2  💰 g:4
 │ │ 🧑‍🔬 6   0 0 2 2  💰 g:4
 │ │ 🧑‍🔬 7   0 3 3 0  💰 g:2
 │ │ 🧑‍🔬 8   1 2 3 1  💰 g:4
 │ │ 🧑‍🔬 9   2 3 0 1  💰 g:4
 │ │ 🧑‍🔬 10  2 2 3 0  💰 g:3
 │ │ 🧑‍🔬 11  2 2 0 2  💰 g:4
 │ │ 🧑‍🔬 12  1 2 0 3  💰 g:1
 │ │ 🧑‍🔬 13  0 3 1 1  💰 g:2
 │ │ 🧑‍🔬 14  2 1 1 2  💰 g:4
 │ │ 🧑‍🔬 15  2 0 3 0  💰 g:1
 │ │ 🧑‍🔬 16  0 3 0 0  💰 g:3
 │ │ 🧑‍🔬 17  0 1 0 2  💰 g:3
 │ │ 🧑‍🔬 18  1 1 1 0  💰 g:4
 │ │ 🧑‍🔬 19  0 3 1 2  💰 g:1
 │ │ 🧑‍🔬 20  0 2 1 0  💰 g:4
 │ ├───── 🌈  ─────
 │ │  🧑‍🔬 │ 🧑‍🔬 │ 📏 │
 │ │ ────┼────┼────┼
 │ │ 7   │18  │   3│
 │ │ 2   │12  │   1│
 │ │ 16  │19  │   2│
 │ │ 9   │13  │   2│
 │ │ 4   │10  │   2│
 │ │ 17  │5   │   1│
 │ │ 8   │3   │   3│
 │ │ 20  │1   │   3│
 │ │ 11  │6   │   3│
 │ │ 14  │15  │   3│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🎯 Selecionar 20 🧑‍🤝‍🧑 pais ─────
 │ │ ├───── Roleta, pressão 150 ─────
 │ │ │ 100%│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│  62│  59│  46│  49│  38│  28│  64│  30│  33│  51│
 │ │ │   10│  41│  72│  67│  36│  75│  54│  57│  43│  70│  25│
 │ │ ├───── Número de seleções ─────
 │ │ │ #Pai│   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   1│   2│   0│   1│   1│   1│   1│   1│   0│   1│
 │ │ │   10│   1│   2│   1│   1│   1│   1│   1│   1│   2│   0│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE Reproduzir 20 pais ─────
 │ │ ├───── Pais (🧑‍🤝‍🧑) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄  18│   5⇄  12│   1⇄   6│  14⇄  19│  12⇄  15│
 │ │ │   10│  19⇄   2│  17⇄  11│   8⇄  16│  13⇄   4│  10⇄   7│
 │ 🏆 ⏱ 3ms  💰 g:0
─┴───────────────────
::♛ ::
  ::  ♛
♛   ::
  ::♛ ::
─┬───────────────────
 │ │ ├───── Pais (💰) ─────
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   4│   4⇄   1│   2⇄   4│   4⇄   1│   1⇄   1│
 │ │ │   10│   1⇄   2│   3⇄   4│   4⇄   3│   2⇄   3│   3⇄   2│
 │ │ ├───── Filhos (💰) 🧬10  ✨14 ───── 📈4 ➖9 📉7
 │ │ │  🧑‍🔬 │   1│   2│   3│   4│   5│   6│   7│   8│   9│  10│
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│   2⇄   2│   2⇄   3│   3⇄   3│   4⇄   3│   2⇄   3│
 │ │ │   10│   3⇄   3│   5⇄   2│   1⇄   4│   0⇄   5│   1⇄   4│
 │ │ └────────────────────────────────────
 │ ├─┬─── FASE 🛡️ Sobrevivência ─────
 │ │ ├───── ⏳ Idade ─────
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  11✖ →🆕 ─────
 │ │ └────────────────────────────────────
 │ └───── FASE Diversidade - limpeza ─────  🧹✖ 11 🧹✖ 13
 ├─ ⚙️  Parâmetros ─ P1=1 P2=4 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1
═╧═ 🏁  Execução terminada ⏱  3ms  ═══
8 Damas (Inteira)
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Algoritmo Evolutivo | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(POPULACAO): 20
│ P7(PROB_CRUZAR): 100 | P8(PROB_MUTAR): 50 | P9(SELECAO): Roleta | P10(PRESSAO): 150
│ P13(SOBREVIVENCIA): Idade | P14(PERC_DESCENDENTES): 100 | P16(ELITISMO): 1
│ P17(IMIGRANTES): 1 | P18(DIVERSIDADE): Limpeza | P19(DIST_MINIMA): 0
│ P20(TIPO_CRUZAR): 1-ponto | P21(TIPO_MUTAR): 0 | P22(TIPO_VIZINHO): incDecValor
│ P23(LIMITE_VIZINHOS): 0 | P24(TIPO_DISTANCIA): Hamming
└──────────────────────────────────────────────────────────────────────
::♛ ::
  ::  ♛
♛   ::
  ::♛ ::
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 0 | I2(Tempo(ms)): 3 | I3(Iterações): 132 | I4(Épocas): 5 |
│ I5(Gerações): 136
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

A informação é agora bastante extensa, mas houve apenas 5 épocas, ao contrário das 10 nos outros modos de debug.
Neste modo de debug é utilizado o gerador aleatório para fazer uma amostra das distâncias entre elementos
da população, conduzindo o este a outra execução.

Em cada época temos agora toda a população, mostrando a codificação de cada elemento e o seu custo.
Temos após a população um mapa de distâncias entre indivíduos, caso a população seja 10 ou menor,
ou uma amostra de distâncias com um emparelhamento aleatório. Assim dá-se uma ideia mais completa da diversidade da população.

Mostra-se informação de todas as fases. A primeira fase é a seleção dos pais. 
Há informação na época 0 de que irão ser selecionados 20 pais pelo método Roleta, com pressão 150.
Este valor corresponde a 1,5, sendo que o valor 1 todos os membros têm a mesma probabilidade, e com 2
os melhores têm muito mais possibildiades de ser escolhidos.
A permilagem de cada indivíduo é colocada na tabela 100%.

Podemos ver a diferença entre o 1 e o 2, tendo o indivíduo 1 custo 2 e o indivíduo 2 custo 4.
A probabilidade de ser selecionado o indivíduo 1 é de 7,5% enquanto que o indivíduo 2 tem probabilidade de 3,8%.

Como resultado destas probabilidades, a tabela seguinte, #Pai, tem o número de vezes que cada indivíduo foi escolhido para pai.
O primeiro indivíduo foi escolhido 1 vez, mas tinha melhores possibilidades de ser escolhido duas vezes.
Podemos ver alguns indivíduos que nem foram escolhidos, como o 14.

Terminada a fase de seleção dos pais, arranca a fase de reprodução. 
Nesta fase temos os pais emparelhados. Na tabela IDs podemos ver os indivíduos da população original por uma ordem de reprodução.
Podemos confirmar que o indivíduo 13 está duas vezes, na posição 10 e 14. Irá reproduzir com o indivíduo 3 e 18.

Os filhos são gerados com base nestes pares, o primeiro com o segundo, o terceiro com o quarto e assim  sucessivamente. 
Há sempre dois filhos por cada casal de pais. Durante a geração dos filhos, foi encontrado uma solução melhor que o registo global.

As duas tabelas seguintes têm os custos dos pais e dos filhos, onde se pode ver o GAP geracional. 
Podemos ver por exemplo, o casal 11 e 12, tinham custo 4 e 3 e os seus filhos ficaram com custos 1 e 2.
Neste caso ambos melhoraram o valor dos pais, mas na geração houve 3 melhoramentos, 5 que pioraram o
valor de ambos os pais, e 10 que ficaram entre o valor dos pais.

A fase de sobrevivência, atendendo a que o método é a idade, não há muito a mostrar,
dado que a geração nova substitui a geração antiga.
Há no entanto indicação sobre elite e imigrantes.
Neste caso a Elite não foi necessária, já que o melhor elemento da nova geração até é melhor que o melhor da geração anterior.

Ocorreu nesta época a fase de limpeza, tendo sido eliminado um elemento que estava duplicado, atendendo às configurações de omissão.

Podemos ver na época 4, onde foi encontrada a melhor solução, que os pais dessa solução,
tinham custo 2 e 3, e essa solução teve um "irmão" com custo 5.
Podemos ainda ver na tabela de IDs que esses dois pais eram na verdade a solução 13 e 4,
ambos seleciondados apenas 1 vez na seleção de pais.
Por um acaso ficaram seguidos, tendo-se chegado a solução num caso, e piorrando no outro.

Esta é uma análise bastante completa, tendo muita informação. 
Pode ser utilizada em instâncias pequenas para compreender os algoritmos e diferentes opções, 
e também para um dado problema procurar entender porque algumas parametrizações resultam melhor que outras.
Aumentando o entendimento no problema, é possível que apareçam oportunidades de melhoria que se possam explorar.

Para identificar as melhores parametrizações, temos de ter testes empíricos, tal como nos restantes exemplos, e esse é o tema da próxima secção.

\anchor 8damas-ci4
## Ação 4 - Testes Empíricos

O modo interativo é importante para compreender e aprender, mas para se poder tirar conclusões temos de ter 
um número considerável de execuções. 

Vamos agora procurar saber qual a melhor parametrização dos algoritmos evolutivos para as 8 damas, codificação inteira.

Começamos por executar a parametrização de omissão nas primeiras instâncias.
Como o algoritmo é aleatório, é crítico fazer mais que uma execução. 
No entanto neste exemplo, sem processamento paralelo, vamos fazer apeans 1 execução.
Colocamos o nível de debug a PASSO, para ter alguma informação durante execução.

Notar que nos testes empíricos, o nível de debug destina-se à informação sobre o progresso da execução global,
mas o algoritmo é executado sempre sem qualquer debug, de modo a obtermos a melhor performance.

Linha de comando: TProcuraMelhorativa 4:40 -R damasCIt1 -P P2=3 

```entrada
/TProcura/Melhorativa/Teste$ ./bin/Release/TProcuraMelhorativa 4:40 -R Resultados/damasCIt1 -P P2=2
...
Opção: 1

 ├─ 🛠️  ─ P1=1 P2=3 P3=1 P4=10 P5=1000000 P6=20 P7=100 P8=50 P9=1 P10=150 P13=1
 ├─ ⚙️  ─ P14=100 P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:37   ↻ Instâncias: 37   🛠️ Configurações: 1   🖥️ Processos: 1.
 ├─ ⏱ 14" 182ms       📋 18    ↻ 22    🛠️ 1     🖥️ 1
 ├─ ⏱ 27" 214ms       📋 21    ↻ 25    🛠️ 1     🖥️ 1
 ├─ ⏱ 41" 344ms       📋 24    ↻ 28    🛠️ 1     🖥️ 1
 ├─ ⏱ 55" 102ms       📋 26    ↻ 30    🛠️ 1     🖥️ 1
 ├─ ⏱ 1' 9" 794ms     📋 28    ↻ 32    🛠️ 1     🖥️ 1
 ├─ ⏱ 1' 25" 727ms    📋 30    ↻ 34    🛠️ 1     🖥️ 1
 ├─ ⏱ 1' 43" 524ms    📋 32    ↻ 36    🛠️ 1     🖥️ 1
 ├─ ⏱ 2' 1" 813ms     📋 34    ↻ 38    🛠️ 1     🖥️ 1
 ├─ ⏱ 2' 21" 507ms    📋 36    ↻ 40    🛠️ 1     🖥️ 1
 ├─ 📄  Ficheiro Resultados/damasCIt1.csv gravado.
 │  ⏱  Tempo real: 2' 31" 507ms
 │  ⏱  CPU total: 2' 31" 507ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  2' 31" 507ms ) ═══
```

Houve reporte a cada 10 segundos, e a execução demorou menos de 3 minutos.
Os tempos de execução não foram afetados por ter o nível de debug a 3, apenas é influenciada a informação sobre o progresso das execuções.

Podemos agora ver a tabela de resultados:

| Instância | I1(Resultado) | I2(Tempo(ms)) | I3(Iterações) | I4(Épocas) |
|:---:|---:|---:|---:|---:|
| 4 | 0 | 1 | 241 | 10 |
| 5 | 0 | 0 | 210 | 9 |
| 6 | 0 | 0 | 105 | 4 |
| 7 | 0 | 2 | 2040 | 95 |
| 8 | 0 | 3 | 2063 | 96 |
| 9 | 0 | 16 | 9500 | 446 |
| 10 | 0 | 5 | 3066 | 144 |
| 11 | 0 | 72 | 40402 | 1898 |
| 12 | 0 | 56 | 34942 | 1641 |
| 13 | 0 | 365 | 201347 | 9467 |
| 14 | 0 | 277 | 146253 | 6879 |
| 15 | 0 | 397 | 184587 | 8681 |
| 16 | 0 | 40 | 15886 | 748 |
| 17 | 0 | 1812 | 689898 | 32461 |
| 18 | 0 | 1082 | 403174 | 18973 |
| 19 | 0 | 2052 | 695640 | 32722 |
| 20 | 0 | 2171 | 676772 | 31860 |
| 21 | 1 | 3581 | 1000002 | 47056 |
| 22 | 1 | 3639 | 1000013 | 47060 |
| 23 | 0 | 1697 | 458090 | 21565 |
| 24 | 1 | 3907 | 1000002 | 47070 |
| 25 | 0 | 1454 | 347321 | 16343 |
| 26 | 1 | 4615 | 1000014 | 47080 |
| 27 | 1 | 5288 | 1000009 | 47090 |
| 28 | 2 | 5479 | 1000015 | 47111 |
| 29 | 1 | 5348 | 1000020 | 47103 |
| 30 | 1 | 6400 | 1000009 | 47095 |
| 31 | 1 | 6284 | 1000021 | 47090 |
| 32 | 1 | 6431 | 1000013 | 47107 |
| 33 | 1 | 6633 | 1000016 | 47096 |
| 34 | 1 | 7176 | 1000006 | 47117 |
| 35 | 2 | 7567 | 1000004 | 47105 |
| 36 | 1 | 7336 | 1000019 | 47121 |
| 37 | 2 | 7675 | 1000002 | 47122 |
| 38 | 2 | 7945 | 1000002 | 47122 |
| 39 | 3 | 8558 | 1000014 | 47116 |
| 40 | 2 | 8730 | 1000008 | 47121 |

A parametrização de omissão consegue resolver até à instância 20, mas após essa instância,
falha por número de iterações.

Não interressa ter instâncias demasiado simples ou demasiado complicadas nos testes. 
Como estes testes não vão ser num cluster, convém ter um conjunto de teste reduzido.
Pretendemos melhorar o algoritmo no ponto de transição. 
Assim, vamos escolher para conjunto de teste, as instâncias 17 a 26.

O primeiro parametro a averiguar, é o tamanho da população.



Linha de comando: TProcuraMelhorativa 17:26 -R Resultados/damasCIt2 -P P2=2 P6=10,20,30,50,100,200

Notar que repetimos a população 20, da qual já tinhamos resultados. 
Poderiamos aproveitar, mas não só é mais simples repetir, como repetindo garante-se condições de igualdade entre execuções.

```entrada
Opção: 1

 ├─ 🛠️  ─ P1=1 P2=2 P3=1 P4=10 P5=1000000 P7=100 P8=50 P9=1 P10=150 P13=1 P14=100
 ├─ ⚙️  ─ P16=1 P17=1 P18=3 P19=0 P20=1 P21=0 P22=1 P23=0 P24=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P6=10
 ├─ ⚙️ [2] ─ P6=20
 ├─ ⚙️ [3] ─ P6=30
 ├─ ⚙️ [4] ─ P6=50
 ├─ ⚙️ [5] ─ P6=100
 ├─ ⚙️ [6] ─ P6=200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:60   ↻ Instâncias: 10   🛠️ Configurações: 6   🖥️ Processos: 1.
 ├─ ⏱ 1' 376ms        📋 20    ↻ 17    🛠️ 3     🖥️ 1
 ├─ ⏱ 2' 4" 425ms     📋 46    ↻ 23    🛠️ 5     🖥️ 1
 ├─ ⏱ 3' 5" 996ms     📋 59    ↻ 26    🛠️ 6     🖥️ 1
 ├─ 📄  Ficheiro Resultados/damasCIt2.csv gravado.
 │  ⏱  Tempo real: 3' 12" 509ms
 │  ⏱  CPU total: 3' 12" 509ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  3' 12" 509ms ) ═══
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
embora sem grande precisão dado que 10 instâncias mas apenas uma execução por cada configuração e instância.

Parametro de omissão alterado: P6(POPULACAO)=30 

Vamos agora estudar a probabilidade de mutação e cruzamento, parametros P7 e P8.

Linha de comando: TProcuraMelhorativa 17:26 -R Resultados/damasCIt3 -P P2=2 P6=30 P7=0:100:25 x P8=0:100:25



| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
