@page teste_8damas_ci Teste 8 Damas - Codificação Inteira

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base no problema das 8 damas, com a codificação inteira.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute-o.
No Linux na pasta `.../TProcura/Melhorativa/Teste` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

## Sumário

- [Ação 1 - Ver instâncias](#damas-ci1)
- [Ação 2 - Resolver manualmente](#damas-ci2)
- [Ação 3 - Algoritmos evolutivos](#damas-ci3)
- [Ação 4 - Testes empíricos](#damas-ci4)

\htmlonly
<pre>
┌─ Teste TProcuraMelhorativa ──┐
│ 1 - 8 Damas (Inteira)        │
│ 2 - 8 Damas (Permutacao)     │
│ 3 - Partição (Binária)       │
└──────────────────────────────┘
Opção: <span class="entrada">1</span>
</pre>
\endhtmlonly


\anchor damas-ci1
## Ação 1 - Ver instâncias

Vamos entrar no problema 8 Damas Inteira, insira: **1.**

\htmlonly
<pre>
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::  ::  ♛   
  ::♛ ::  ::  ::
::  ::  ::  ::♛ 
♛ ::  ::  ::  ::
::  ::  ♛   ::  
  ::  ::  ::♛ ::
::  ::  ♛   ::  
  ::  ::  ::  ♛ 
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly

Temos uma instância das 8 Damas como no exemplo da TProcuraConstrutiva. 
Em vez de um tabuleiro vazio, em que iamos construindo a solução adicionando damas, 
existem damas já colocadas mas algumas atacam-se mutuamente.
Esta é uma solução completa aleatória, que pretendemos melhorar. 
Tem ainda violações, que são damas a atacarem-se, que neste contexto convertem-se em custos,
que pretendemos remover. Uma solução de custo 0 é prortanto uma solução válida.

Temos um número de parametros mais extenso,
embora os 5 primeiros parametros sejam os mesmos que no exemplo do teste TVector.
O último parametro é o P24, muito embora não estejam 24 parâmetros. 
O P11 por exemplo não é mostrado.
Alguns parâmetros só são ativos devido a valores de outros parametros.
Como temos o P1(ALGORITMO) em Algoritmos Evolutivos, este algoritmo tem muitos parametros, e por esse motivo
são mostrados bastantes. Iremos abordar cada um no momento próprio.

Vamos trocar para uma instância menor antes de avançarmos, para simplificar a nossa exploração.

Insira: **1; 4.**

\htmlonly
<pre>
Opção: <span class="entrada">1</span>
┌─ 📄 Instância ───────────────────────────────────────────────────────
│ <span style="color:gray">ID atual:</span> 8  <span style="color:gray">Intervalo:</span> [4–40]  
│ <span style="color:gray">Prefixo atual:</span> 'instancia_' 
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): <span class="entrada">4</span>
8 Damas (Inteira)
...
::  ♛   
  ::♛ ::
::  ::♛ 
♛ ::  ::
...
Opção: 
</pre>
\endhtmlonly

Estavamos na instância 8 e agora estamos na instância 4.
Temos um tabuleiro de 4x4 para colocar 4 damas.
Podiamos ter escolhido até tabuleiros de 40x40.


\anchor damas-ci2
## Ação 2 - Resolver manualmente

Vamos primeiro procurar resolver a instância manualmente, e ver a codificação inteira utilizada. Insira: **2.**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>0 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>3 3 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   4│   4│   4│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   4│    │   3│   1│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   4│   3│    │   3│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   4│   1│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Entramos num modo de expoloração manual com as operações dos algoritmos melhorativos.
No entanto a população foi fixada em 4, para melhor gerir a exploração manual.
Durante a geração da população dos 4 elementos foi encontrada uma solução de custo 2, que foi mostrada de imediato.
Arranca a época 0 (linha: " ├─┬─ 📆 0 ⏱  ──── 💰 g2-4"), tal como os algoritmos evolutivos, mas neste caso cada época é o resultado de aplicar um operador.

Podemos ver a população de 4 elementos com custos de 2 a 4.
É mostrado a codificação inteira e não as soluções a que correspondem. 
Assim pretendemos focar no que os algoritmos vêm, e não nas soluções.

A descodificação, ou seja, a conversão da codificação para uma solução, é neste caso simples:
cada número na posição K corresponde à coluna em que a dama da linha K deve estar.
A descodificação é normalmente necessária para avaliar o custo de uma solução,
neste caso o número de pares de damas a atacarem-se mutuamente.

A codificação de uma solução é também imediata.
No entanto em problemas complexos estas duas operações, codificar/descodificar uma solução,
podem ter custos computacionais consideráveis.

Como temos 4 damas temos 4 números de 0 a 3.

Podemos utilizar outra codificação, desde que exista forma de codificar todas as soluções de interesse,
ou seja, de uma solução converter na codificação única,
e descodificar, de uma codificação reconstruir a solução a que corresponde.

Há outras possibilidades de codificar o problema das 8 damas,
estando implementado a codificação com base na permutação, no próximo exemplo.

Na população os 4 elementos têm cor de fundo para auxiliar a identificação,
e os custos têm cor da letra para sinalizar os melhores elementos de forma visual.

Temos um mapa de distâncias entre os 4 elementos para dar uma ideia da diversidade da população. 
A medida de distancia de omissão é Hamming, significando que conta simplesmente os valores distintos.
Podemos alterar através do parametro P24(TIPO_DISTANCIA):. 
Há vários tipos de distâncias disponíveis dependendo da codificação.
Há dois elementos à distância de 1 unidade, o 2 e 4. De facto, estes diferem apenas no valor do segundo inteiro.

Temos 3 operações para testar, a mutação, cruzamento e vizinhança.
Vamos começar pela mutação, e mutar o indivíduo 4. Insira: **1; 4.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">1</span>
 │ ┌───── 🦠  ───── 
 │ │ 🧍  [1-4]: <span class="entrada">4</span>
 │ │ 🧍   3 3 1 0  mutar vizinho incDecValor (3,1)
 │ │ 🦠   3 3 1 1 
 │ │ ::  ::♛ 
 │ │   ::  ♛ 
 │ │ ::♛ ::  
 │ │   ♛   ::
 │ └────────────── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>0 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>3 3 1 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   4│   4│   4│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   4│    │   3│   2│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   4│   3│    │   4│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   4│   2│   4│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

A mutação acabou por trocar apenas um valor, o que se pode confirmar nas linhas 🧍(atual) e 🦠 (mutado),
com as codificaçõe seguidas e alinhadas.
Ficou uma solução igualmente má de custo 4. 
Podemos alterar a mutação no parâmetro P21(TIPO_MUTAR). 
Existem também vários operadores de mutação disponíveis dependente do tipo de codificação.

Vamos agora passar para o cruzamento, e cruzar o individuo 1 com o 3,
os dois melhores na população, e substituir o individuo 4. 
Insira: **2; 1; 3; 4.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">2</span>
 │ ┌───── 🧬  ───── 
 │ │ 🧍 Pai [1-4]: <span class="entrada">1</span>
 │ │ 🧍 Mãe [1-4]: <span class="entrada">3</span>
 │ │ 🧍 Filho [1-4]: <span class="entrada">4</span>
 │ │ 
 │ │ 🧍 Pai   0 2 0 3 
 │ │ 🧍 Mãe   1 0 3 0  cruzamento 1-ponto(s): 3 
 │ │ 🧬 Filho 0 2 0 0 
 │ │ ♛   ::  
 │ │   ::♛ ::
 │ │ ♛   ::  
 │ │ ♛ ::  ::
 │ └────────────── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>0 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 2 0 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   4│   4│   1│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   4│    │   3│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   4│   3│    │   3│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   1│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

O filho ficou quase igual ao pai, com os três primeiros elementos do pai, e o último da mãe. 
Existem vários tipos de operadores de cruzamento, controlados pelo parametro P20(TIPO_CRUZAR).
Diferentes operadores estão disponíveis em diferentes codificações, podendo cada operador ter também parâmetros próprios.

Falta-nos explorar o operador de vizinhança, pelo que vamos aplicar ao melhor individuo 1, e escolher o melhor vizinho. 
Insira: **3; 1; 1.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">1</span>
 │ │ 🧍   0 2 0 3  vizinhança incDecValor (limite 0)
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">1   </span>1 2 0 3  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">2   </span>0 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">3   </span>0 1 0 3  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">4   </span>0 2 1 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">5   </span>0 2 0 2  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 [1-5]: <span class="entrada">1</span>
 │ │ 
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
 │ │ ::♛ ::  
 │ │   ::♛ ::
 │ │ ♛   ::  
 │ │   ::  ♛ 
─┬───────────────────
 │ └────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1 2 0 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 2 0 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   4│   3│   2│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   4│    │   3│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   3│   3│    │   3│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   2│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

O melhor vizinho gerado tem custo 1, pelo que estamos mais perto. 
Foi feita a substituição da melhor solução.
Notar que o tipo de vizinhança é descrito, neste caso apenas incrementamos ou decrementamos cada valor em uma unidade.
Devido a esta opção, a vizinhança tem um número baixo de indivíduos.

Vamos insistir e ver os vizinhos deste novo elemento, e novamente escolher o melhor destes.
Insira: **3; 1; 3.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">1</span>
 │ │ 🧍   1 2 0 3  vizinhança incDecValor (limite 0)
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(101,101,0)">1   </span>2 2 0 3  💰 <span style="color:rgb(223,159,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,0)">2   </span>0 2 0 3  💰 <span style="color:rgb(223,159,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">3   </span>1 3 0 3  💰 <span style="color:rgb(159,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,0,101)">4   </span>1 1 0 3  💰 <span style="color:rgb(223,31,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,101)">5   </span>1 2 1 3  💰 <span style="color:rgb(223,31,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">6   </span>1 2 0 2  💰 <span style="color:rgb(223,159,31)">g:2</span>
 │ │ 🧍 [1-6]: <span class="entrada">3</span>
 │ │ 
 │ │ ::♛ ::  
 │ │   ::  ♛ 
 │ │ ♛   ::  
 │ │   ::  ♛ 
 │ └────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1 3 0 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 2 0 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   4│   3│   3│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   4│    │   3│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   3│   3│    │   3│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   3│   3│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Neste caso o vizinho tem o mesmo custo, mas é outro vizinho,
pelo que vale a pena ainda uma última vez, ver quais os seus vizinhos.
Insira: **3; 1; 5.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">1</span>
 │ │ 🧍   1 3 0 3  vizinhança incDecValor (limite 0)
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">1   </span>2 3 0 3  💰 <span style="color:rgb(223,31,31)"> g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">2   </span>0 3 0 3  💰 <span style="color:rgb(223,31,31)"> g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">3   </span>1 2 0 3  💰 <span style="color:rgb(159,223,31)"> g:1</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">4   </span>1 3 1 3  💰 <span style="color:rgb(223,159,31)"> g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">5   </span>1 3 0 2  💰 <span style="color:rgb(31,223,31)"> g:0</span>
 │ │ 🧍 [1-5]: <span class="entrada">5</span>
 │ │ 
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
 │ │ ::♛ ::  
 │ │   ::  ♛ 
 │ │ ♛   ::  
 │ │   ::♛ ::
─┬───────────────────
 │ └──────────────  └──────────────── 
8 Damas (Inteira)
...
::♛ ::  
  ::  ♛ 
♛   ::  
  ::♛ ::
...
Opção: 
</pre>
\endhtmlonly

Temos finalmente a solução de custo 0, o que pretendiamos. Uma solução com as 4 damas, sem se atacarem.
Ao selecionar o vizinho com a solução ótima, a exploração é interrompida, tal como qualquer algoritmo, 
sendo a solução obtida retornada. 



\anchor damas-ci3
## Ação 3 - Algoritmos evolutivos

Vamos agora ver como o algoritmo evolutivo poderia obter esta solução de forma automática, com a parametrização de omissão.
Insira: **1; 4; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>0 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 241 | <span style="color:gray">I4(Épocas):</span> 10 | 
│ <span style="color:gray">I5(Gerações):</span> 249
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos ver que o primeiro indicador, I1(Resultado) é igual a 0. Este é o custo da solução.
Podemos observar a solução e ver que as damas não se atacam, aliás, é exatamente a mesma solução obtida manualmente.

O segundo indicador I2(Tempo(ms)) é 0, o que significa que foi consumido menos de 1 milisegundo.

Temos o número de iterações a 241, que corresponde às avaliações efetuadas, e 10 épocas,
o que corresponde ao número de ciclos do algoritmo evolutivo.
Finalmente, temos o número de estados gerados a 249.

Há informação visível nos indicadores, mas não vemos nada em termos de funcionamento do algoritmo. 
O que aconteceu nestas 10 épocas?
Vendo a parametrização podemos ver que há população de 20, e toda a informação de operadores e opções.
Podemos obter na literatura qual a melhor parametrização para um dado problema ou tipo de problemas,
e utilizar como parametrização base. Mas estaremos satisfeitos com esta informação?
Não! Precisamos de ver o que se passou em concreto, para saber o que correu bem e menos bem, sem dependências de terceiros.
Queremos até mais tarde confirmar que a configuração base é a melhor parametrização possível, ou identificar qual é a mais adequada, pela via experimental.

Como podemos repetir todas as execuções, podemos ver a mesma execução com diferentes níveis de detalhe.
Vamos aproveitar esta execução que tem tamanho reduzido, para ir subindo o nível de debug.
Insira: **1; 4; 3; 2; 1; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══.
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  
  ::♛ ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>1 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> ATIVIDADE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 241 | <span style="color:gray">I4(Épocas):</span> 10 | 
│ <span style="color:gray">I5(Gerações):</span> 249
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Nesta repetição vemos um ponto de quando em quando, para saber que há atividade. 
No final são introduzidos 128 pontos, se o número de iterações for atingido.
Como gastamos muito poucas iterações e o limite é muito alto, estes pontos nem chegam a ser impressos.

Mas vemos algo importante. Sempre que se encontra uma melhor solução global,
é registado o tempo e a solução é mostrada ao utilizador.
Podemos ver que primeiro foi encontrada uma solução de custo 2,
de seguida outra de custo 1 e finalmente a de custo 0.

Sabemos mais alguma coisa do que se passou, mas não muito. Numa execução longa podemos ver quando as diferentes soluções são encontradas,
e se são encontradas soluções de custos incrementais, ou diretamente a solução de custo 0.

Vamos ver agora o nível de debug PASSOS.
Insira: **1; 4; 3; 2; 2; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 ├─── 📆 0 ⏱  ──── 💰 g2-5
 │ 🏆  ⏱  💰 g:1
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
 ├─── 📆 5 ⏱  ──── 💰 g1-5
 ├─── 📆 6 ⏱  ──── 💰 g1-4
 ├─── 📆 7 ⏱  ──── 💰 g1-5
 ├─── 📆 8 ⏱  ──── 💰 g1-5
 ├─── 📆 9 ⏱  ──── 💰 g1-4
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> PASSOS | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 241 | <span style="color:gray">I4(Épocas):</span> 10 | 
│ <span style="color:gray">I5(Gerações):</span> 249
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Temos agora a informação das diferentes épocas. 
Em cada época é registado o instante em que esta ocorre, neste caso apenas alguns milisegundos,
o número da época, e o menor e maior custo na população.

Aqui é possível observar que nesta procura, a melhor solução na população nunca piorou de uma época para a outra.
Dependente da parametrização, nem sempre esta situação é garantida.
A utilização de P16(ELITISMO)=1 garante
que pelo menos um elemento da população antiga,
irá manter-se caso na nova população não exista nenhum elemento com valor melhor ou igual.

Aumentamos o conhecimento, mas ainda estamos um pouco às escuras.
Sabemos em que as duas soluções intermédias foram encontradas logo ao gerar a população inicial, e na primeira geração.
Fora o parâmetro do elitismo, nada mais pode ser observado ou verificada a sua utilidade.

É tempo para aumentar o nível de debug para DETALHE.
Insira: **1; 4; 3; 2; 3; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  
  ::♛ ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 ├─┬─ 📆 1 ⏱  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g1-5 [📏 1-4 (μ=3, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ │  10│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│
 │ │  10│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-5 [📏 0-4 (μ=2, melhor/pior 2)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│
 │ │  10│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 5 ⏱  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(108,223,31)">   1</span>│
 │ │  10│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 6 ⏱  ──── 💰 g1-4 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,127,31)">   3</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 7 ⏱  ──── 💰 g1-5 [📏 0-4 (μ=2, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   5</span>│
 │ │  10│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 8 ⏱  ──── 💰 g1-5 [📏 1-4 (μ=2, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(108,223,31)">   1</span>│
 │ │  10│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 9 ⏱  ──── 💰 g1-4 [📏 0-4 (μ=2, melhor/pior 2)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>│
 │ └──────────────────────────────────── 
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 241 | <span style="color:gray">I4(Épocas):</span> 10 | 
│ <span style="color:gray">I5(Gerações):</span> 249
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Temos agora uma tabela para cada época e informação sobre as distâncias.
Na época 0, devido à linha `[📏 1-4 (μ=2, melhor/pior 3)]` sabemos que as distâncias entre indivíduos vão de 1 a 4, a média das distâncias é 2,
e a distância entre o melhor e o pior indivíduo é 3.

A cada linha da época segue-se agora uma tabela `🧍`.
Esta tabela tem para cada um dos 20 indivíduos na população o seu custo.
Tem 10 colunas e tantas linhas quantas necessárias, uma por cada dezena de indivíduos. 
O indivíduo 14 está na linha com índice 10 e coluna com índice 4, que na época 0 tinha custo 5.

Assim, podemos ter uma ideia mais detalhada dos custos dos indivíduos, e uma ideia da diversidade.
Se a diversidade da população for muito baixa, podemos observar a média de distâncias com valor baixo.
Se apenas alguns elementos tiverem um bom valor, e a maior parte tiver um valor mau, podemos também observar.

Idealmente pretendemos uma diversidade alta e alto valor nos indivíduos, portanto baixo custo.
Por vezes o que ocorre num problema mal afinado, é que todas as soluções ficam com o mesmo valor, e a diversidade é muito baixa.
Nesse caso o algoritmo fica estagnado, sendo essa a situação mais crítica a evitar.

Embora possamos observar a situação mais indesejável que pode ocorrer num algoritmo evolutivo, a estagnação,
nada sabemos sobre os indivíduos concretos, e o que se passa de uma população para a outra.

Há várias fases para passar de uma época para a outra, e muitos operadores são aplicados. 
Mas isso é interno aos algoritmos evolutivos, nada é visível neste nível de debug.

É portanto tempo para passarmos para o último nível de debug, COMPLETO.
Insira:  **1; 4; 3; 2; 4; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 2 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>3 3 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>3 1 2 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>3 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>2 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 0 0 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>3 0 0 2  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 3 1 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1 2 3 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>2 3 3 0  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0 0 1 0  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0 3 0 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1 2 1 2  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>3 0 1 1  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1 2 1 0  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0 0 2 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   3│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   2│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  75</span>│<span style="background-color:rgb(101,61,0)">  38</span>│<span style="background-color:rgb(101,91,0)">  49</span>│<span style="background-color:rgb(81,101,0)">  41</span>│<span style="background-color:rgb(51,101,0)">  43</span>│<span style="background-color:rgb(20,101,0)">  59</span>│<span style="background-color:rgb(0,101,10)">  51</span>│<span style="background-color:rgb(0,101,40)">  64</span>│<span style="background-color:rgb(0,101,71)">  33</span>│<span style="background-color:rgb(0,101,101)">  62</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  72</span>│<span style="background-color:rgb(0,40,101)">  46</span>│<span style="background-color:rgb(0,10,101)">  70</span>│<span style="background-color:rgb(20,0,101)">  25</span>│<span style="background-color:rgb(51,0,101)">  54</span>│<span style="background-color:rgb(81,0,101)">  67</span>│<span style="background-color:rgb(101,0,91)">  28</span>│<span style="background-color:rgb(101,0,61)">  57</span>│<span style="background-color:rgb(101,0,30)">  30</span>│<span style="background-color:rgb(101,0,0)">  36</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   2</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  
  ::♛ ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 14 ───── 📈 1 🟰 17 📉 2
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(108,223,31)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  9✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 4
 ├─┬─ 📆 1 ⏱  ──── 💰 g1-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 2 3 1  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>1 2 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>3 1 1 1  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>1 0 3 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>1 2 0 2  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 0 1 0  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0 0 1 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 3 0 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>1 3 3 0  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 2 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>3 1 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>3 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>3 0 1 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0 1 0 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>3 1 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>3 2 2 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>3 3 0 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   2│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   2│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   2│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   1│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   1│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   3│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  75</span>│<span style="background-color:rgb(101,61,0)">  43</span>│<span style="background-color:rgb(101,91,0)">  46</span>│<span style="background-color:rgb(81,101,0)">  38</span>│<span style="background-color:rgb(51,101,0)">  57</span>│<span style="background-color:rgb(20,101,0)">  64</span>│<span style="background-color:rgb(0,101,10)">  25</span>│<span style="background-color:rgb(0,101,40)">  30</span>│<span style="background-color:rgb(0,101,71)">  49</span>│<span style="background-color:rgb(0,101,101)">  62</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  36</span>│<span style="background-color:rgb(0,40,101)">  33</span>│<span style="background-color:rgb(0,10,101)">  72</span>│<span style="background-color:rgb(20,0,101)">  51</span>│<span style="background-color:rgb(51,0,101)">  70</span>│<span style="background-color:rgb(81,0,101)">  67</span>│<span style="background-color:rgb(101,0,91)">  54</span>│<span style="background-color:rgb(101,0,61)">  41</span>│<span style="background-color:rgb(101,0,30)">  28</span>│<span style="background-color:rgb(101,0,0)">  59</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   0</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   0</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   2</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(223,108,31)">   4</span>│
 │ │ │   10│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,108,31)">   4</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 10 ───── 📈 5 🟰 12 📉 3
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,108,31)">   4</span>│
 │ │ │   10│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  7✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g1-5
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-5
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-5
 ├─┬─ 📆 5 ⏱ 1ms  ──── 💰 g1-5
 ├─┬─ 📆 6 ⏱ 1ms  ──── 💰 g1-4
 ├─┬─ 📆 7 ⏱ 1ms  ──── 💰 g1-5
 ├─┬─ 📆 8 ⏱ 1ms  ──── 💰 g1-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>2 3 2 3  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 1 3 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>1 1 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>2 2 2 1  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>2 2 2 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>1 3 0 1  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 0 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0 2 3 1  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 1 0 1  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>1 2 0 3  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 3 0 3  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1 0 0 1  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>1 0 3 1  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0 2 3 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1 3 3 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 0 3 1  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>3 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>2 1 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>2 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>2 2 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   3│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   2│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   2│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  25</span>│<span style="background-color:rgb(101,61,0)">  64</span>│<span style="background-color:rgb(101,91,0)">  30</span>│<span style="background-color:rgb(81,101,0)">  41</span>│<span style="background-color:rgb(51,101,0)">  36</span>│<span style="background-color:rgb(20,101,0)">  57</span>│<span style="background-color:rgb(0,101,10)">  33</span>│<span style="background-color:rgb(0,101,40)">  67</span>│<span style="background-color:rgb(0,101,71)">  28</span>│<span style="background-color:rgb(0,101,101)">  75</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  70</span>│<span style="background-color:rgb(0,40,101)">  38</span>│<span style="background-color:rgb(0,10,101)">  51</span>│<span style="background-color:rgb(20,0,101)">  59</span>│<span style="background-color:rgb(51,0,101)">  49</span>│<span style="background-color:rgb(81,0,101)">  72</span>│<span style="background-color:rgb(101,0,91)">  54</span>│<span style="background-color:rgb(101,0,61)">  46</span>│<span style="background-color:rgb(101,0,30)">  62</span>│<span style="background-color:rgb(101,0,0)">  43</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   0</span>│<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,91,0)">   0</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   0</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│
 │ │ │   10│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,127,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,127,31)">   3</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 12 ───── 📈 3 🟰 14 📉 3
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,223,31)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  6✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 15 🧹 17
 ├─┬─ 📆 9 ⏱ 1ms  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 3 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 2 3 0  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>2 0 2 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>3 1 0 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0 3 1 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0 2 3 1  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>1 3 0 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 3 3 2  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>2 2 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 3 3 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1 2 0 1  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>3 0 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1 0 3 1  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>2 2 2 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>0 1 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>2 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>0 3 2 2  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>3 2 0 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1 2 0 1  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   2│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   2│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   3│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   2│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   2│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  57</span>│<span style="background-color:rgb(101,61,0)">  41</span>│<span style="background-color:rgb(101,91,0)">  49</span>│<span style="background-color:rgb(81,101,0)">  36</span>│<span style="background-color:rgb(51,101,0)">  51</span>│<span style="background-color:rgb(20,101,0)">  46</span>│<span style="background-color:rgb(0,101,10)">  72</span>│<span style="background-color:rgb(0,101,40)">  75</span>│<span style="background-color:rgb(0,101,71)">  67</span>│<span style="background-color:rgb(0,101,101)">  54</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  28</span>│<span style="background-color:rgb(0,40,101)">  33</span>│<span style="background-color:rgb(0,10,101)">  64</span>│<span style="background-color:rgb(20,0,101)">  30</span>│<span style="background-color:rgb(51,0,101)">  25</span>│<span style="background-color:rgb(81,0,101)">  59</span>│<span style="background-color:rgb(101,0,91)">  62</span>│<span style="background-color:rgb(101,0,61)">  43</span>│<span style="background-color:rgb(101,0,30)">  70</span>│<span style="background-color:rgb(101,0,0)">  38</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   2</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   2</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   0</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   0</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   2</span>│<span style="background-color:rgb(101,0,61)">   0</span>│<span style="background-color:rgb(101,0,30)">   2</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(20,0,101)">  14</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│
 │ │ │   10│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│
 │ 🏆  ⏱ 1ms  💰 g:0
─┴───────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 12 ───── 📈 3 🟰 11 📉 6
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(31,223,31)">   0</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ └──────────────────────────────────── 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> 1-ponto | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 1 | <span style="color:gray">I3(Iterações):</span> 241 | <span style="color:gray">I4(Épocas):</span> 10 | 
│ <span style="color:gray">I5(Gerações):</span> 249
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

A informação é agora bastante extensa,
mas cortamos a informação de debug desde a época 2 `├─┬─ 📆 2 ⏱  ──── 💰 g1-5` até à época 7 `├─┬─ 📆 7 ⏱ 1ms  ──── 💰 g1-5`.
Mostramos apenas as primeiras e últimas épocas.

Em cada época (vamos ver a época 0) temos agora toda a população (`├───── 🧍🧑‍🤝‍🧑🚶‍ ─────`),
mostrando a codificação de cada elemento e o seu custo (`🧍 1   0 2 0 3  💰 g:2`).
Temos após a população um mapa de distâncias entre indivíduos (`├───── 📏  ─────`), caso a população seja 10 ou menor,
ou pares de distâncias entre elementos consecutivos.
Assim ficamos com uma ideia mais completa da diversidade da população.

Mostramos informação de todas as fases. A primeira fase é a seleção dos pais (`├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ─────`).  
Há informação na época 0 de que irão ser selecionados 20 pais pelo método Roleta, com pressão 150 (`├───── Roleta, pressão 150 ─────`).
Este valor corresponde a 1,5, sendo que o valor 1 todos os membros têm a mesma probabilidade, e com 2
os melhores têm muito mais possibildiades de ser escolhidos.
A permilagem de cada indivíduo é colocada na tabela 100%.

Podemos ver a diferença entre o 1 e o 2, tendo o indivíduo 1 custo 2 e o indivíduo 2 custo 4.
A probabilidade de ser selecionado o indivíduo 1 é de 7,5% enquanto que o indivíduo 2 tem probabilidade de 3,8%.

Como resultado destas probabilidades, a tabela seguinte, #Pai, tem o número de vezes que cada indivíduo foi escolhido para pai.
O primeiro indivíduo foi escolhido 2 vezes.
Podemos ver alguns indivíduos que nem foram escolhidos, como o 4.

Terminada a fase de seleção dos pais, arranca a fase de reprodução (`├─┬─── FASE 🧬  Reproduzir 20 pais ─────`). 
Nesta fase temos os pais emparelhados (`├───── Pais (🧑‍🤝‍🧑 ) ─────`).
Na tabela IDs podemos ver os indivíduos da população original por uma ordem de reprodução.
Podemos confirmar que o indivíduo 1 está duas vezes, na posição 8 e 20. Irá reproduzir com o indivíduo 5 e 12.

Os filhos são gerados com base nestes pares, o primeiro com o segundo, o terceiro com o quarto e assim  sucessivamente. 
Há sempre dois filhos por cada casal de pais. Durante a geração dos filhos, foi encontrado uma solução melhor que o registo global.

As duas tabelas seguintes têm os custos dos pais (`├───── Pais (💰 ) ─────`) e dos filhos (`├───── Filhos (💰 ) 🧬 10  🦠 14 ───── 📈 1 🟰 17 📉 2`),
onde se pode ver o GAP geracional. 
Podemos ver por exemplo, o casal 11 e 12, tinham custo 2 e 5 e os seus filhos ficaram com custos 4 e 2. 
Neste caso um ficou entre os valores dos pais, o outro ficou com o melhor valor dos pais.

Na geração houve 1 melhoramento, 2 que pioraram o valor de ambos os pais, e 17 que ficaram entre o valor dos pais.
Esta informação está na linha dos filhos: `📈 1 🟰 17 📉 2`.

A fase de sobrevivência (`├─┬─── FASE ⚔️  Sobrevivência ─────`), atendendo a que o método é a idade, não há muito a mostrar,
dado que a geração nova substitui a geração antiga.
Há no entanto indicação sobre elite e imigrantes.
Neste caso a Elite não foi necessária, já que o melhor elemento da nova geração até é melhor que o melhor da geração anterior.
Nos imigrantes entrou 1, saindo o elemento 9: `├───── 🚶‍🌍 Imigrantes  9✖ →🆕 ─────`.

Ocorreu nesta época a fase de limpeza, tendo sido eliminado um elemento que estava duplicado, atendendo às configurações de omissão: `└───── FASE 🌈  Diversidade - limpeza ─────  🧹 4`

Esta análise permite ver a origem do elemento que tem a solução ótima. Focando agora na época 9, vemos que o filho com custo 0 é o 8.
Esse elemento tem como irmão uma solução de custo 4, e ambos os pais têm custo 3. Os pais sãos os elementos 12 e 14, vamos ver a sua codificação:
- `🧍 12  1 2 0 1  💰 g:3`
- `🧍 14  1 0 3 1  💰 g:3`

O estado de custo 0 é codificado com `2 0 3 1`. Parte da codificação está nos pais, mas o primeiro número não está, o que significa que a mutação trocou esse valor.
Vemos aqui um exemplo que a mutação ajudou, mas neste caso mesmo que o elemento 14 estivesse sozinho, após mutar incrementando o primeiro número, passa de uma
solução de custo 3 para uma solução de custo 0.

Esta é uma análise bastante completa tendo muita informação. 
Pode ser utilizada em instâncias pequenas para compreender os algoritmos e diferentes opções, 
e também para um dado problema procurar entender porque algumas parametrizações resultam melhor que outras.
Aumentando o entendimento no problema é possível que apareçam oportunidades de melhoria que se possam explorar.

Para identificar as melhores parametrizações, temos de ter testes empíricos, tal como nos restantes exemplos, e esse é o tema da próxima secção.

\anchor damas-ci4
## Ação 4 - Testes empíricos

O modo interativo é importante para compreender e aprender, mas para se poder tirar conclusões temos de ter 
um número considerável de execuções.

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

[Resultados Deucalion](melhorativa__deucalion.html)


Neste estudo foi identificada a melhor parametrização para este problema e codificação:
**P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P20=0.**

Podemos ver como a alteração da parametrização afeta este exemplo: 

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
♛   ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 2 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>3 1 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>1 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>3 3 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>3 1 2 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>3 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>2 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 0 0 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>3 0 0 2  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 3 1 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1 2 3 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>2 3 3 0  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0 0 1 0  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0 3 0 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1 2 1 2  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>3 0 1 1  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1 2 1 0  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0 0 2 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   3│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   2│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 175 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  88</span>│<span style="background-color:rgb(101,61,0)">  32</span>│<span style="background-color:rgb(101,91,0)">  48</span>│<span style="background-color:rgb(81,101,0)">  36</span>│<span style="background-color:rgb(51,101,0)">  40</span>│<span style="background-color:rgb(20,101,0)">  64</span>│<span style="background-color:rgb(0,101,10)">  52</span>│<span style="background-color:rgb(0,101,40)">  72</span>│<span style="background-color:rgb(0,101,71)">  24</span>│<span style="background-color:rgb(0,101,101)">  68</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  84</span>│<span style="background-color:rgb(0,40,101)">  44</span>│<span style="background-color:rgb(0,10,101)">  80</span>│<span style="background-color:rgb(20,0,101)">  12</span>│<span style="background-color:rgb(51,0,101)">  56</span>│<span style="background-color:rgb(81,0,101)">  76</span>│<span style="background-color:rgb(101,0,91)">  16</span>│<span style="background-color:rgb(101,0,61)">  60</span>│<span style="background-color:rgb(101,0,30)">  20</span>│<span style="background-color:rgb(101,0,0)">  28</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   2</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   2</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   0</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   0</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
::♛ ::  
  ::♛ ::
♛   ::  
  ::  ♛ 
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   5</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 0 ───── 📈 2 🟰 14 📉 4
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(108,223,31)">   1</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(108,223,31)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 5 🧹 20 🧹 16 🧹 18
 ├─┬─ 📆 1 ⏱  ──── 💰 g1-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>1 2 0 3  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 2 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>3 0 3 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>3 1 1 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>1 0 1 1  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>3 0 1 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 0 0 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0 0 1 1  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>3 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>2 3 3 0  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 3 0 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>3 1 2 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>3 1 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>3 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>3 0 2 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 3 0 2  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>2 1 1 0  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>3 2 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>2 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0 1 0 3  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   2│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   2│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   2│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   3│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   1│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   2│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 175 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  88</span>│<span style="background-color:rgb(101,61,0)">  36</span>│<span style="background-color:rgb(101,91,0)">  44</span>│<span style="background-color:rgb(81,101,0)">  20</span>│<span style="background-color:rgb(51,101,0)">  16</span>│<span style="background-color:rgb(20,101,0)">  24</span>│<span style="background-color:rgb(0,101,10)">  32</span>│<span style="background-color:rgb(0,101,40)">  48</span>│<span style="background-color:rgb(0,101,71)">  40</span>│<span style="background-color:rgb(0,101,101)">  68</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  60</span>│<span style="background-color:rgb(0,40,101)">  28</span>│<span style="background-color:rgb(0,10,101)">  64</span>│<span style="background-color:rgb(20,0,101)">  72</span>│<span style="background-color:rgb(51,0,101)">  80</span>│<span style="background-color:rgb(81,0,101)">  84</span>│<span style="background-color:rgb(101,0,91)">  56</span>│<span style="background-color:rgb(101,0,61)">  76</span>│<span style="background-color:rgb(101,0,30)">  52</span>│<span style="background-color:rgb(101,0,0)">  12</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   2</span>│<span style="background-color:rgb(101,61,0)">   0</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   0</span>│<span style="background-color:rgb(20,101,0)">   0</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   2</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   2</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 0 ───── 📈 2 🟰 14 📉 4
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,31,31)">   4</span>│
 │ │ │   10│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 2 🧹 7 🧹 8 🧹 12 🧹 17
 ├─┬─ 📆 2 ⏱  ──── 💰 g1-4
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-4
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-4
 ├─┬─ 📆 5 ⏱ 1ms  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 0 2 2  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>1 3 1 2  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0 3 2 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0 2 2 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>3 0 1 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0 3 3 3  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>3 3 3 2  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>3 3 0 2  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>2 0 3 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0 3 0 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 0 0 3  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>2 3 0 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0 3 0 2  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1 3 1 3  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>3 0 0 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>0 1 1 3  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0 0 1 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1 2 1 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0 0 1 1  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>2 2 3 3  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   3│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   2│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   3│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   2│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   2│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 175 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  13</span>│<span style="background-color:rgb(101,61,0)">  72</span>│<span style="background-color:rgb(101,91,0)">  36</span>│<span style="background-color:rgb(81,101,0)">  40</span>│<span style="background-color:rgb(51,101,0)">  44</span>│<span style="background-color:rgb(20,101,0)">  24</span>│<span style="background-color:rgb(0,101,10)">  20</span>│<span style="background-color:rgb(0,101,40)">  80</span>│<span style="background-color:rgb(0,101,71)">  88</span>│<span style="background-color:rgb(0,101,101)">  56</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  32</span>│<span style="background-color:rgb(0,40,101)">  64</span>│<span style="background-color:rgb(0,10,101)">  84</span>│<span style="background-color:rgb(20,0,101)">  76</span>│<span style="background-color:rgb(51,0,101)">  28</span>│<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(101,0,91)">  60</span>│<span style="background-color:rgb(101,0,61)">  68</span>│<span style="background-color:rgb(101,0,30)">  48</span>│<span style="background-color:rgb(101,0,0)">  52</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   0</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   0</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   2</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   0</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   2</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,31,31)">   4</span>│
 │ │ │   10│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(127,223,31)">   1</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 0 ───── 📈 5 🟰 12 📉 3
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│
 │ │ │   10│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(127,223,31)">   1</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(127,223,31)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 16 🧹 15 🧹 14
 ├─┬─ 📆 6 ⏱ 1ms  ──── 💰 g1-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 3 1 2  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 0 0 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>3 2 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>3 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0 0 3 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>2 2 2 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>1 0 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0 3 1 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1 3 0 3  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>1 3 1 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>2 3 3 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>2 0 3 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0 0 1 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0 3 3 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>2 2 3 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>2 3 0 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>3 0 1 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1 2 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0 3 3 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1 2 1 2  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   2│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   1│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   1│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   1│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 175 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  88</span>│<span style="background-color:rgb(101,61,0)">  16</span>│<span style="background-color:rgb(101,91,0)">  60</span>│<span style="background-color:rgb(81,101,0)">  52</span>│<span style="background-color:rgb(51,101,0)">  40</span>│<span style="background-color:rgb(20,101,0)">  28</span>│<span style="background-color:rgb(0,101,10)">  56</span>│<span style="background-color:rgb(0,101,40)">  68</span>│<span style="background-color:rgb(0,101,71)">  84</span>│<span style="background-color:rgb(0,101,101)">  64</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  20</span>│<span style="background-color:rgb(0,40,101)">  36</span>│<span style="background-color:rgb(0,10,101)">  24</span>│<span style="background-color:rgb(20,0,101)">  76</span>│<span style="background-color:rgb(51,0,101)">  72</span>│<span style="background-color:rgb(81,0,101)">  44</span>│<span style="background-color:rgb(101,0,91)">  48</span>│<span style="background-color:rgb(101,0,61)">  32</span>│<span style="background-color:rgb(101,0,30)">  80</span>│<span style="background-color:rgb(101,0,0)">  12</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   0</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   0</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   0</span>│<span style="background-color:rgb(20,0,101)">   2</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│
 │ │ │   10│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(108,223,31)">   1</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 0 ───── 📈 0 🟰 15 📉 5
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)">   5</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(184,223,31)">   2</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(223,108,31)">   4</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,184,31)">   3</span>⇄<span style="color:rgb(184,223,31)">   2</span>│<span style="color:rgb(223,108,31)">   4</span>⇄<span style="color:rgb(223,184,31)">   3</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 👑  Elite 1→13 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 5 🧹 10 🧹 12
 ├─┬─ 📆 7 ⏱ 1ms  ──── 💰 g1-5
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>3 3 1 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 0 0 2  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0 3 3 1  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0 0 3 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0 3 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>2 3 3 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>1 0 0 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>2 2 0 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1 3 1 3  💰 <span style="color:rgb(184,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0 3 1 2  💰 <span style="color:rgb(108,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 2 3 1  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>0 0 3 2  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0 0 0 1  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>3 3 1 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1 0 1 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1 2 1 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1 2 1 2  💰 <span style="color:rgb(223,31,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>2 2 2 3  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0 1 2 0  💰 <span style="color:rgb(223,108,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1 2 1 3  💰 <span style="color:rgb(223,184,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   3│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   2│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   2│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   3│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   4│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   1│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 175 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  60</span>│<span style="background-color:rgb(101,61,0)">  40</span>│<span style="background-color:rgb(101,91,0)">  76</span>│<span style="background-color:rgb(81,101,0)">  52</span>│<span style="background-color:rgb(51,101,0)">  32</span>│<span style="background-color:rgb(20,101,0)">  24</span>│<span style="background-color:rgb(0,101,10)">  48</span>│<span style="background-color:rgb(0,101,40)">  80</span>│<span style="background-color:rgb(0,101,71)">  84</span>│<span style="background-color:rgb(0,101,101)">  88</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  20</span>│<span style="background-color:rgb(0,40,101)">  68</span>│<span style="background-color:rgb(0,10,101)">  16</span>│<span style="background-color:rgb(20,0,101)">  36</span>│<span style="background-color:rgb(51,0,101)">  64</span>│<span style="background-color:rgb(81,0,101)">  72</span>│<span style="background-color:rgb(101,0,91)">  12</span>│<span style="background-color:rgb(101,0,61)">  44</span>│<span style="background-color:rgb(101,0,30)">  28</span>│<span style="background-color:rgb(101,0,0)">  56</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   0</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   0</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   0</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   0</span>│<span style="background-color:rgb(101,0,0)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│
 │ 🏆  ⏱ 1ms  💰 g:0
─┴───────────────────
::♛ ::  
  ::  ♛ 
♛   ::  
  ::♛ ::
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,127,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   1</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   4</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 0 ───── 📈 1 🟰 18 📉 1
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)">   4</span>⇄<span style="color:rgb(223,223,31)">   2</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">   4</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(223,127,31)">   3</span>│<span style="color:rgb(223,127,31)">   3</span>⇄<span style="color:rgb(31,223,31)">   0</span>│
 │ │ └──────────────────────────────────── 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>0 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>0 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
8 Damas (Inteira)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 0 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 175
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 0 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> uniforme | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> incDecValor
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::♛ ::  
  ::  ♛ 
♛   ::  
  ::♛ ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 1 | <span style="color:gray">I3(Iterações):</span> 209 | <span style="color:gray">I4(Épocas):</span> 8 | 
│ <span style="color:gray">I5(Gerações):</span> 215
└──────────────────────────────────────────────────────────────────────
...
Opção: </pre>
\endhtmlonly

Podemos ver que foram utilizadas apenas 8 épocas. Neste caso a solução foi gerada de pais com custo 3 e 4, tendo um irmão com custo 3.
Esses pais foram os estados 7 e 14:
- `🧍 7   1 0 0 2  💰 g:3`
- `🧍 14  3 3 1 3  💰 g:4`

A solução gerada resulta na codificação `1 3 0 2`, tendo sido utilizado o operador de cruzamento uniforme, e pela informação não houve mutações.
Assim este filho resultou em cada posição de um valor do pai ou da mãe. O operador de cruzamento inicial de 1 ponto, não poderia gerar este filho
destes dois pais, atendendo a que o primeiro e último número pertence ao elemento 7, mas o segundo número pertence ao elemento 14.
O operador uniforme pode perfeitamente gerar este filho.



| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
