@page teste_8damas_cp Teste 8 Damas - Codificação por Permutação

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


Execução de exemplo com base no problema das 8 damas, com codificação por permutação.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute.
No Linux na pasta `.../TProcura/Melhorativa/Teste$` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#8damas-cp1)
- [Ação 2 - Resolver manualmente](#8damas-cp2)
- [Ação 3 - Algoritmos Evolutivos](#8damas-cp3)
- [Ação 4 - Testes Empíricos](#8damas-cp6)

\htmlonly
<pre>
┌─ Teste TProcuraMelhorativa ──┐
│ 1 - 8 Damas (Inteira)        │
│ 2 - 8 Damas (Permutacao)     │
│ 3 - Partição (Binária)       │
└──────────────────────────────┘
Opção: <span class="entrada">2</span>
</pre>
\endhtmlonly


\anchor 8damas-cp1
## Ação 1 - Ver instâncias

Vamos entrar no problema 8 Damas Permutação, introduza: **2.**

\htmlonly
<pre>
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> inserir
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::  ::  ::♛ 
  ::  ::♛ ::  ::
::  ::♛ ::  ::  
♛ ::  ::  ::  ::
::  ♛   ::  ::  
  ::  ::  ♛   ::
::♛ ::  ::  ::  
  ::  ::  ::♛ ::
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly

Vamos seguir a mesma linha das 8 damas, codificação inteira. Vamos alterar para a instância de tamanho 4.
Introduza: **1; 4.**

\htmlonly
<pre>
Opção: <span class="entrada">1</span>
┌─ 📄 Instância ───────────────────────────────────────────────────────
│ <span style="color:gray">ID atual:</span> 8  <span style="color:gray">Intervalo:</span> [4–40]  
│ <span style="color:gray">Prefixo atual:</span> 'instancia_' 
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): <span class="entrada">4</span>
8 Damas (Permutação)
...
♛   ::  
  ::  ♛ 
::♛ ::  
  ::♛ ::
...
Opção: 
</pre>
\endhtmlonly

Notar que a instância é distinta da codificação inteira. De facto a instância incial da codificação inteira não tem
representação na codificação permutação, já que neste caso apenas há permutação da posição das damas, enquanto que
na solução inicial da codificação inteira há duas damas na mesma coluna.

\anchor 8damas-cp2
## Ação 2 - Resolver manualmente

Vamos resolver a instância manualmente. Introduza: **2**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g0-6
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(0,101,0)">1   </span>1 2 3 0  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,0,101)">2   </span>3 2 1 0  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">3   </span>2 0 3 1  💰 <span style="color:rgb(31,223,31)">g:0</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(0,101,0)">1   </span> <span style="background-color:rgb(0,0,101)">2   </span> <span style="background-color:rgb(101,0,0)">3   </span> 
 │ │ ────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(0,101,0)">1   </span>│    │   2│   3│
 │ │ <span style="background-color:rgb(0,0,101)">2   </span>│   2│    │   4│
 │ │ <span style="background-color:rgb(101,0,0)">3   </span>│   3│   4│    │
 │ │ ────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Apenas ao gerar a população inicial, temos logo uma solução de custo 0, pelo que nem se chegou a gerar 4 elementos.

Assim, vamos sair e colocar uma dimensão maior para poder ver os operadores de cruzamento.
Introduza: **0; 1; 6; 2.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">0</span>
 └──────────────── 
8 Damas (Permutação)
...
::  ♛   
♛ ::  ::
::  ::♛ 
  ♛   ::
...
Opção: <span class="entrada">1</span>
┌─ 📄 Instância ───────────────────────────────────────────────────────
│ <span style="color:gray">ID atual:</span> 4  <span style="color:gray">Intervalo:</span> [4–40]  
│ <span style="color:gray">Prefixo atual:</span> 'instancia_' 
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): <span class="entrada">6</span>
8 Damas (Permutação)
...
::  ::  ♛   
♛ ::  ::  ::
::  ::  ::♛ 
  ::  ♛   ::
::♛ ::  ::  
  ::♛ ::  ::
...
Opção: <span class="entrada">2</span>
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 1 4 3 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   5│   5│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   5│    │   6│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   5│   6│    │   6│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   3│   6│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Agora sim, temos uma população de 4 elementos com custos de 2 a 5. Vamos começar por testar o operador de mutação.
Introduza: **1; 1.**

\htmlonly
<pre>
│ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">1</span>
 │ ┌───── 🦠  ───── 
 │ │ 🧍  [1-4]: <span class="entrada">1</span>
 │ │ 🧍   2 1 4 3 5 0  mutar vizinho inserir (0,0)
 │ │ 🦠   2 1 4 3 5 0 
 │ │ ::  ♛   ::  
 │ │   ♛   ::  ::
 │ │ ::  ::  ♛   
 │ │   ::  ♛   ::
 │ │ ::  ::  ::♛ 
 │ │ ♛ ::  ::  ::
 │ └────────────── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 1 4 3 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   5│   5│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   5│    │   6│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   5│   6│    │   6│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   3│   6│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Neste caso o operador é um vizinho de inserção, mas o elemento retirado está na mesma posição em que é inserido, na posição 0.
Vamos repetir. Introduza: **1; 1.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">1</span>
 │ ┌───── 🦠  ───── 
 │ │ 🧍  [1-4]: <span class="entrada">1</span>
 │ │ 🧍   2 1 4 3 5 0  mutar vizinho inserir (1,3)
 │ │ 🦠   2 4 3 1 5 0 
 │ │ ::  ♛   ::  
 │ │   ::  ::♛ ::
 │ │ ::  ::♛ ::  
 │ │   ♛   ::  ::
 │ │ ::  ::  ::♛ 
 │ │ ♛ ::  ::  ::
 │ └────────────── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 4 3 1 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   6│   6│   5│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   6│    │   6│   3│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   6│   6│    │   6│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   5│   3│   6│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Tal como na representação inteira, há vários operadores de mutação, sendo o mesmo verdade para os restantes operadores de cruzamento e vizinhança.

Desta vez inserimos o elemento na posição 1 (segundo na ordem), na posição 3 (quarto na ordem). Todos os outros elmentos ficaram iguais.
Em termos de custos ficou igual, continuam 4 pares de damas a atacarem-se, embora sejam pares distintos.

Vamos agora ao operador de cruzamento, vamos cruzar os dois melhores elemenotos.
Introduza: **2; 2; 3; 4.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">2</span>
 │ ┌───── 🧬  ───── 
 │ │ 🧍 Pai [1-4]: <span class="entrada">2</span>
 │ │ 🧍 Mãe [1-4]: <span class="entrada">3</span>
 │ │ 🧍 Filho [1-4]: <span class="entrada">4</span>
 │ │ 
 │ │ 🧍 Pai   0 2 4 5 3 1 
 │ │ 🧍 Mãe   5 0 2 3 1 4  cruzamento OX 4 - 5
 │ │ 🧬 Filho 5 0 2 4 3 1 
 │ │ ::  ::  ::♛ 
 │ │ ♛ ::  ::  ::
 │ │ ::  ♛   ::  
 │ │   ::  ::♛ ::
 │ │ ::  ::♛ ::  
 │ │   ♛   ::  ::
 │ └────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g2-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 4 3 1 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>5 0 2 4 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   6│   6│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   6│    │   6│   4│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   6│   6│    │   3│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   4│   3│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos):
</pre>
\endhtmlonly

Nete caso o filho ficou com os 3 primeiros elementos da mãe, e o resto ficou pela ordem como que aparecem no pai.
Há apenas 2 pares de damas que se atacam, tal como a mãe.

Podemos agora testar o operador de vizinhança, tendo como ponto de partida o estado 4 com custo 2.
Introduza: **3; 4.**

\htmlonly
<pre>
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">4</span>
 │ │ 🧍   5 0 2 4 3 1  vizinhança inserir (limite 0)
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(101,20,0)">1   </span>0 5 2 4 3 1  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,40,0)">2   </span>0 2 5 4 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">3   </span>0 2 4 5 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,81,0)">4   </span>0 2 4 3 5 1  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,101,0)">5   </span>0 2 4 3 1 5  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">6   </span>0 5 2 4 3 1  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(61,101,0)">7   </span>5 2 0 4 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(40,101,0)">8   </span>5 2 4 0 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">9   </span>5 2 4 3 0 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,0)">10  </span>5 2 4 3 1 0  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,20)">11  </span>2 5 0 4 3 1  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">12  </span>5 2 0 4 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,61)">13  </span>5 0 4 2 3 1  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,81)">14  </span>5 0 4 3 2 1  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">15  </span>5 0 4 3 1 2  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,81,101)">16  </span>4 5 0 2 3 1  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,61,101)">17  </span>5 4 0 2 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">18  </span>5 0 4 2 3 1  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,20,101)">19  </span>5 0 2 3 4 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,0,101)">20  </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">21  </span>3 5 0 2 4 1  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(40,0,101)">22  </span>5 3 0 2 4 1  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(61,0,101)">23  </span>5 0 3 2 4 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">24  </span>5 0 2 3 4 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,101)">25  </span>5 0 2 4 1 3  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,81)">26  </span>1 5 0 2 4 3  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">27  </span>5 1 0 2 4 3  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,40)">28  </span>5 0 1 2 4 3  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,20)">29  </span>5 0 2 1 4 3  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">30  </span>5 0 2 4 1 3  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 [1-30]:
</pre>
\endhtmlonly

Há 30 vizinhos, existindo vários com custo 1. Vamos escolher um deles e repetir o processo.
Introduza: **30; 3; 4;**

\htmlonly
<pre>
 │ │ 🧍 [1-30]: <span class="entrada">30</span>
 │ │ 
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
 │ │ ::  ::  ::♛ 
 │ │ ♛ ::  ::  ::
 │ │ ::  ♛   ::  
 │ │   ::  ::♛ ::
 │ │ ::♛ ::  ::  
 │ │   ::  ♛   ::
─┬───────────────────
 │ └────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 4 3 1 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>5 0 2 4 1 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   6│   6│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   6│    │   6│   6│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   6│   6│    │   2│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   6│   2│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">4</span>
 │ │ 🧍   5 0 2 4 1 3  vizinhança inserir (limite 0)
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(101,20,0)">1   </span>0 5 2 4 1 3  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,40,0)">2   </span>0 2 5 4 1 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">3   </span>0 2 4 5 1 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,81,0)">4   </span>0 2 4 1 5 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,101,0)">5   </span>0 2 4 1 3 5  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">6   </span>0 5 2 4 1 3  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(61,101,0)">7   </span>5 2 0 4 1 3  💰 <span style="color:rgb(195,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(40,101,0)">8   </span>5 2 4 0 1 3  💰 <span style="color:rgb(195,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">9   </span>5 2 4 1 0 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,0)">10  </span>5 2 4 1 3 0  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,20)">11  </span>2 5 0 4 1 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">12  </span>5 2 0 4 1 3  💰 <span style="color:rgb(195,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,61)">13  </span>5 0 4 2 1 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,81)">14  </span>5 0 4 1 2 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">15  </span>5 0 4 1 3 2  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,81,101)">16  </span>4 5 0 2 1 3  💰 <span style="color:rgb(195,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,61,101)">17  </span>5 4 0 2 1 3  💰 <span style="color:rgb(223,31,31)">g:7</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">18  </span>5 0 4 2 1 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,20,101)">19  </span>5 0 2 1 4 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,0,101)">20  </span>5 0 2 1 3 4  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">21  </span>1 5 0 2 4 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(40,0,101)">22  </span>5 1 0 2 4 3  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(61,0,101)">23  </span>5 0 1 2 4 3  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">24  </span>5 0 2 1 4 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,101)">25  </span>5 0 2 4 3 1  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,81)">26  </span>3 5 0 2 4 1  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">27  </span>5 3 0 2 4 1  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,40)">28  </span>5 0 3 2 4 1  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,20)">29  </span>5 0 2 3 4 1  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">30  </span>5 0 2 4 3 1  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 [1-30]: 
</pre>
\endhtmlonly

Neste caso temos novamente vários vizinhos de custo 1, mas nenhum de custo 0. Vamos escolher o primeiro e terminar.
Introduza: **1; 0.**

\htmlonly
<pre>
 │ │ 🧍 [1-30]: <span class="entrada">1</span>
 │ │ 
 │ │ ♛   ::  ::  
 │ │   ::  ::  ♛ 
 │ │ ::  ♛   ::  
 │ │   ::  ::♛ ::
 │ │ ::♛ ::  ::  
 │ │   ::  ♛   ::
 │ └────────────── 
 ├─┬─ 📆 5 ⏱  ──── 💰 g1-4
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>2 4 3 1 5 0  💰 <span style="color:rgb(223,31,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(223,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,127,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0 5 2 4 1 3  💰 <span style="color:rgb(127,223,31)">g:1</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   6│   6│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   6│    │   6│   5│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   6│   6│    │   4│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   5│   4│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">0</span>
 └──────────────── 
8 Damas (Permutação)
...
::  ::  ::♛ 
♛ ::  ::  ::
::  ♛   ::  
  ::  ::♛ ::
::♛ ::  ::  
  ::  ♛   ::
...
Opção: 
</pre>
\endhtmlonly

\anchor 8damas-cp3
## Ação 3 - Algoritmos Evolutivos

Vamos agora ver os algoritmos evolutivos nos diferentes níveis de debug, para esta instância de tamanho 6.

Introduza: **1; 6; 3; 2; 1; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══.
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
::  ::  ♛   
  ::♛ ::  ::
─┬───────────────────
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>1 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> ATIVIDADE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> inserir
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 169 | <span style="color:gray">I4(Épocas):</span> 7 | 
│ <span style="color:gray">I5(Gerações):</span> 174
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Esta execução sabemos que há 7 épocas, pelo que este exemplo é bom para ser visto com maior detalhe. Vamos passar para o modo de detalhe seguinte.
Introduza: **1; 6; 3; 2; 2; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
::  ::  ♛   
  ::♛ ::  ::
─┬───────────────────
 ├─── 📆 0 ⏱  ──── 💰 g1-8
 ├─── 📆 1 ⏱  ──── 💰 g1-6
 ├─── 📆 2 ⏱  ──── 💰 g1-9
 ├─── 📆 3 ⏱  ──── 💰 g1-9
 ├─── 📆 4 ⏱  ──── 💰 g1-8
 ├─── 📆 5 ⏱  ──── 💰 g1-7
 ├─── 📆 6 ⏱  ──── 💰 g1-11
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> PASSOS | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> inserir
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 169 | <span style="color:gray">I4(Épocas):</span> 7 | 
│ <span style="color:gray">I5(Gerações):</span> 174
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos observar que os custos vão de 1 até à volta de 10. Confirma-se que a melhor solução nunca é degradada com a atual configuração.
Vamos avançar no nível de debug.
Introduza: **1; 6; 3; 2; 3; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
::  ::  ♛   
  ::♛ ::  ::
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g1-8 [📏 0-6 (μ=4, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,223,31)">   4</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(223,223,31)">   4</span>│<span style="color:rgb(223,127,31)">   6</span>│<span style="color:rgb(223,127,31)">   6</span>│<span style="color:rgb(223,223,31)">   4</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(223,175,31)">   5</span>│<span style="color:rgb(223,223,31)">   4</span>│
 │ │  10│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(223,175,31)">   5</span>│<span style="color:rgb(223,127,31)">   6</span>│<span style="color:rgb(223,31,31)">   8</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(79,223,31)">   1</span>│<span style="color:rgb(175,223,31)">   3</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g1-6 [📏 2-6 (μ=5, melhor/pior 6)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   6</span>│<span style="color:rgb(95,223,31)">   1</span>│<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   3</span>│<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(159,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(95,223,31)">   1</span>│<span style="color:rgb(223,223,31)">   3</span>│<span style="color:rgb(223,31,31)">   6</span>│<span style="color:rgb(223,95,31)">   5</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g1-9 [📏 2-6 (μ=4, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(223,31,31)">   9</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(223,201,31)">   5</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(159,223,31)">   3</span>│
 │ │  10│<span style="color:rgb(223,31,31)">   9</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(223,116,31)">   7</span>│<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(116,223,31)">   2</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-9 [📏 2-6 (μ=5, melhor/pior 6)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   9</span>│<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(116,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(223,116,31)">   7</span>│<span style="color:rgb(223,116,31)">   7</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(223,116,31)">   7</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(201,223,31)">   4</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-8 [📏 2-6 (μ=4, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,31,31)">   8</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(79,223,31)">   1</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(79,223,31)">   1</span>│<span style="color:rgb(79,223,31)">   1</span>│<span style="color:rgb(223,79,31)">   7</span>│<span style="color:rgb(175,223,31)">   3</span>│
 │ │  10│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(223,223,31)">   4</span>│<span style="color:rgb(223,175,31)">   5</span>│<span style="color:rgb(223,127,31)">   6</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(175,223,31)">   3</span>│<span style="color:rgb(127,223,31)">   2</span>│<span style="color:rgb(223,79,31)">   7</span>│<span style="color:rgb(79,223,31)">   1</span>│<span style="color:rgb(223,175,31)">   5</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 5 ⏱  ──── 💰 g1-7 [📏 2-6 (μ=5, melhor/pior 6)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,141,31)">   5</span>│<span style="color:rgb(86,223,31)">   1</span>│<span style="color:rgb(223,141,31)">   5</span>│<span style="color:rgb(223,195,31)">   4</span>│<span style="color:rgb(141,223,31)">   2</span>│<span style="color:rgb(141,223,31)">   2</span>│<span style="color:rgb(86,223,31)">   1</span>│<span style="color:rgb(141,223,31)">   2</span>│<span style="color:rgb(195,223,31)">   3</span>│<span style="color:rgb(223,195,31)">   4</span>│
 │ │  10│<span style="color:rgb(141,223,31)">   2</span>│<span style="color:rgb(223,141,31)">   5</span>│<span style="color:rgb(141,223,31)">   2</span>│<span style="color:rgb(223,86,31)">   6</span>│<span style="color:rgb(223,31,31)">   7</span>│<span style="color:rgb(223,141,31)">   5</span>│<span style="color:rgb(223,195,31)">   4</span>│<span style="color:rgb(223,195,31)">   4</span>│<span style="color:rgb(223,195,31)">   4</span>│<span style="color:rgb(141,223,31)">   2</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 6 ⏱  ──── 💰 g1-11 [📏 2-6 (μ=5, melhor/pior 5)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(66,223,31)">   1</span>│<span style="color:rgb(170,223,31)">   4</span>│<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(101,223,31)">   2</span>│
 │ │  10│<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(223,31,31)">  11</span>│<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(170,223,31)">   4</span>│<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(136,223,31)">   3</span>│
 │ └──────────────────────────────────── 
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
─┬───────────────────
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> inserir
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 169 | <span style="color:gray">I4(Épocas):</span> 7 | 
│ <span style="color:gray">I5(Gerações):</span> 174
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos observar que a diversidade mantém-se, sendo a distância média de 4 a 5 unidades.
Já sabiamos a variação do melhor e pior custo, mas ao ver o mapa completo podemos ter a noção de que o pior custo é apenas de um ou outro elemento.
A maior parte dos elementos têm um custo baixo. Há épocas que têm mais que um elemento com custo 1, mas a população não fica dominada por soluções todas
do mesmo custo.
Vamos ver agora o detalhe completo. Introduza: **1; 6; 3; 2; 4; *ENTER*; 6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:1
─┴───────────────────
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
::  ::  ♛   
  ::♛ ::  ::
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g1-8
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>2 1 4 3 5 0  💰 <span style="color:rgb(223,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(175,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>1 2 5 4 3 0  💰 <span style="color:rgb(223,127,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>4 0 1 2 3 5  💰 <span style="color:rgb(223,127,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>2 5 4 0 3 1  💰 <span style="color:rgb(223,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>2 4 1 0 3 5  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>4 0 2 1 3 5  💰 <span style="color:rgb(223,175,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0 5 4 2 3 1  💰 <span style="color:rgb(223,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 5 3 0 4 2  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>2 1 3 0 5 4  💰 <span style="color:rgb(175,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>1 2 0 5 3 4  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0 2 4 3 5 1  💰 <span style="color:rgb(223,175,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>4 0 1 2 3 5  💰 <span style="color:rgb(223,127,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1 0 3 4 5 2  💰 <span style="color:rgb(223,31,31)">g:8</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>4 2 1 5 3 0  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1 4 5 0 2 3  💰 <span style="color:rgb(127,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0 5 3 1 4 2  💰 <span style="color:rgb(79,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>4 3 0 5 1 2  💰 <span style="color:rgb(175,223,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   5│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   6│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   5│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   5│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   5│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   5│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   6│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   5│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  41</span>│<span style="background-color:rgb(101,61,0)">  62</span>│<span style="background-color:rgb(101,91,0)">  57</span>│<span style="background-color:rgb(81,101,0)">  43</span>│<span style="background-color:rgb(51,101,0)">  30</span>│<span style="background-color:rgb(20,101,0)">  28</span>│<span style="background-color:rgb(0,101,10)">  46</span>│<span style="background-color:rgb(0,101,40)">  72</span>│<span style="background-color:rgb(0,101,71)">  38</span>│<span style="background-color:rgb(0,101,101)">  49</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  67</span>│<span style="background-color:rgb(0,40,101)">  54</span>│<span style="background-color:rgb(0,10,101)">  70</span>│<span style="background-color:rgb(20,0,101)">  36</span>│<span style="background-color:rgb(51,0,101)">  33</span>│<span style="background-color:rgb(81,0,101)">  25</span>│<span style="background-color:rgb(101,0,91)">  64</span>│<span style="background-color:rgb(101,0,61)">  59</span>│<span style="background-color:rgb(101,0,30)">  75</span>│<span style="background-color:rgb(101,0,0)">  51</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   0</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   0</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   0</span>│<span style="background-color:rgb(101,0,91)">   2</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│
 │ │ │   10│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(95,223,31)">   1</span>⇄<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(223,223,31)">   3</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(223,223,31)">   3</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   3</span>⇄<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,31,31)">   6</span>⇄<span style="color:rgb(223,31,31)">   6</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 10 ───── 📈 3 🟰 10 📉 7
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)">   6</span>⇄<span style="color:rgb(223,223,31)">   3</span>│<span style="color:rgb(95,223,31)">   1</span>⇄<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(223,159,31)">   4</span>│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(223,223,31)">   3</span>⇄<span style="color:rgb(223,95,31)">   5</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(95,223,31)">   1</span>│<span style="color:rgb(223,31,31)">   6</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(223,159,31)">   4</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  7✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g1-6
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>4 0 5 2 1 3  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>2 4 0 1 3 5  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>4 0 1 2 3 5  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0 2 5 3 1 4  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0 5 4 2 1 3  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>2 1 3 0 5 4  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>2 1 0 5 3 4  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1 2 4 3 5 0  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>1 2 0 5 3 4  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 0 2 4 5 3  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>4 0 3 5 1 2  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>4 0 5 1 2 3  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>3 2 1 5 4 0  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>5 0 2 4 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>5 3 4 1 2 0  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0 5 3 1 4 2  💰 <span style="color:rgb(95,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>4 1 5 3 0 2  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1 4 5 2 3 0  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0 4 5 3 2 1  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   4│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   5│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   6│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   5│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   5│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  43</span>│<span style="background-color:rgb(101,61,0)">  62</span>│<span style="background-color:rgb(101,91,0)">  59</span>│<span style="background-color:rgb(81,101,0)">  28</span>│<span style="background-color:rgb(51,101,0)">  75</span>│<span style="background-color:rgb(20,101,0)">  64</span>│<span style="background-color:rgb(0,101,10)">  51</span>│<span style="background-color:rgb(0,101,40)">  36</span>│<span style="background-color:rgb(0,101,71)">  41</span>│<span style="background-color:rgb(0,101,101)">  67</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  38</span>│<span style="background-color:rgb(0,40,101)">  57</span>│<span style="background-color:rgb(0,10,101)">  46</span>│<span style="background-color:rgb(20,0,101)">  49</span>│<span style="background-color:rgb(51,0,101)">  70</span>│<span style="background-color:rgb(81,0,101)">  30</span>│<span style="background-color:rgb(101,0,91)">  72</span>│<span style="background-color:rgb(101,0,61)">  54</span>│<span style="background-color:rgb(101,0,30)">  25</span>│<span style="background-color:rgb(101,0,0)">  33</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   2</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(116,223,31)">   2</span>⇄<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(116,223,31)">   2</span>⇄<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(116,223,31)">   2</span>⇄<span style="color:rgb(223,201,31)">   5</span>│<span style="color:rgb(159,223,31)">   3</span>⇄<span style="color:rgb(223,159,31)">   6</span>│
 │ │ │   10│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(74,223,31)">   1</span>⇄<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(74,223,31)">   1</span>⇄<span style="color:rgb(116,223,31)">   2</span>│<span style="color:rgb(116,223,31)">   2</span>⇄<span style="color:rgb(223,201,31)">   5</span>│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   3</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 14 ───── 📈 1 🟰 12 📉 7
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(74,223,31)">   1</span>⇄<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(74,223,31)">   1</span>⇄<span style="color:rgb(74,223,31)">   1</span>│<span style="color:rgb(223,116,31)">   7</span>⇄<span style="color:rgb(201,223,31)">   4</span>│<span style="color:rgb(159,223,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   9</span>│
 │ │ │   10│<span style="color:rgb(159,223,31)">   3</span>⇄<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(74,223,31)">   1</span>⇄<span style="color:rgb(159,223,31)">   3</span>│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(223,201,31)">   5</span>│<span style="color:rgb(159,223,31)">   3</span>⇄<span style="color:rgb(223,31,31)">   9</span>│<span style="color:rgb(201,223,31)">   4</span>⇄<span style="color:rgb(201,223,31)">   4</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  18✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g1-9
 ├─┬─ 📆 3 ⏱  ──── 💰 g1-9
 ├─┬─ 📆 4 ⏱  ──── 💰 g1-8
 ├─┬─ 📆 5 ⏱  ──── 💰 g1-7
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>4 0 2 1 3 5  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>4 0 1 3 5 2  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0 3 2 1 5 4  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>5 4 3 1 0 2  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>3 2 5 1 4 0  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>2 1 5 3 0 4  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>5 4 1 3 0 2  💰 <span style="color:rgb(86,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0 2 5 1 3 4  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0 3 4 2 1 5  💰 <span style="color:rgb(195,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>4 5 1 3 2 0  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0 5 3 1 2 4  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>4 1 2 5 0 3  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>1 4 2 5 0 3  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1 4 5 2 3 0  💰 <span style="color:rgb(223,86,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>2 3 4 5 1 0  💰 <span style="color:rgb(223,31,31)">g:7</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>3 2 4 0 5 1  💰 <span style="color:rgb(223,141,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1 3 2 5 0 4  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1 3 0 4 5 2  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>4 2 1 0 5 3  💰 <span style="color:rgb(223,195,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>4 3 5 0 2 1  💰 <span style="color:rgb(141,223,31)">g:2</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   5│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   5│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   6│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   6│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   6│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   4│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   5│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  33</span>│<span style="background-color:rgb(101,61,0)">  75</span>│<span style="background-color:rgb(101,91,0)">  38</span>│<span style="background-color:rgb(81,101,0)">  41</span>│<span style="background-color:rgb(51,101,0)">  57</span>│<span style="background-color:rgb(20,101,0)">  62</span>│<span style="background-color:rgb(0,101,10)">  72</span>│<span style="background-color:rgb(0,101,40)">  67</span>│<span style="background-color:rgb(0,101,71)">  54</span>│<span style="background-color:rgb(0,101,101)">  46</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  59</span>│<span style="background-color:rgb(0,40,101)">  30</span>│<span style="background-color:rgb(0,10,101)">  64</span>│<span style="background-color:rgb(20,0,101)">  28</span>│<span style="background-color:rgb(51,0,101)">  25</span>│<span style="background-color:rgb(81,0,101)">  36</span>│<span style="background-color:rgb(101,0,91)">  49</span>│<span style="background-color:rgb(101,0,61)">  51</span>│<span style="background-color:rgb(101,0,30)">  43</span>│<span style="background-color:rgb(101,0,0)">  70</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   0</span>│<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   2</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   0</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   0</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   0</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(66,223,31)">   1</span>⇄<span style="color:rgb(170,223,31)">   4</span>│<span style="color:rgb(223,170,31)">   7</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(66,223,31)">   1</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(66,223,31)">   1</span>│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(101,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 10 ───── 📈 0 🟰 14 📉 6
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(170,223,31)">   4</span>│<span style="color:rgb(223,170,31)">   7</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(223,31,31)">  11</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(136,223,31)">   3</span>⇄<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(205,223,31)">   5</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(205,223,31)">   5</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(66,223,31)">   1</span>│<span style="color:rgb(205,223,31)">   5</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(223,170,31)">   7</span>⇄<span style="color:rgb(101,223,31)">   2</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍🌍 Imigrantes  1✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 3
 ├─┬─ 📆 6 ⏱ 1ms  ──── 💰 g1-11
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>4 5 3 2 1 0  💰 <span style="color:rgb(223,170,31)">g:7</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0 3 2 1 5 4  💰 <span style="color:rgb(205,223,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0 4 1 3 5 2  💰 <span style="color:rgb(66,223,31)">g:1</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>1 3 0 4 5 2  💰 <span style="color:rgb(170,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>4 3 5 0 2 1  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>5 3 2 1 4 0  💰 <span style="color:rgb(205,223,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>4 2 5 0 3 1  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>4 5 3 1 2 0  💰 <span style="color:rgb(205,223,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>4 0 3 2 5 1  💰 <span style="color:rgb(136,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0 2 4 1 5 3  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>1 2 3 5 0 4  💰 <span style="color:rgb(136,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>3 0 5 4 2 1  💰 <span style="color:rgb(136,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0 2 5 1 3 4  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>5 0 1 2 3 4  💰 <span style="color:rgb(223,31,31)">g:11</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1 4 2 5 0 3  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>2 3 4 5 1 0  💰 <span style="color:rgb(223,170,31)">g:7</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>3 1 2 5 4 0  💰 <span style="color:rgb(170,223,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>2 5 1 3 0 4  💰 <span style="color:rgb(101,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>4 3 5 1 0 2  💰 <span style="color:rgb(223,170,31)">g:7</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0 4 2 5 1 3  💰 <span style="color:rgb(136,223,31)">g:3</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   6│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   5│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   5│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   5│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   6│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   4│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   5│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   6│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   6│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  33</span>│<span style="background-color:rgb(101,61,0)">  38</span>│<span style="background-color:rgb(101,91,0)">  75</span>│<span style="background-color:rgb(81,101,0)">  43</span>│<span style="background-color:rgb(51,101,0)">  64</span>│<span style="background-color:rgb(20,101,0)">  36</span>│<span style="background-color:rgb(0,101,10)">  70</span>│<span style="background-color:rgb(0,101,40)">  41</span>│<span style="background-color:rgb(0,101,71)">  49</span>│<span style="background-color:rgb(0,101,101)">  72</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  54</span>│<span style="background-color:rgb(0,40,101)">  57</span>│<span style="background-color:rgb(0,10,101)">  67</span>│<span style="background-color:rgb(20,0,101)">  25</span>│<span style="background-color:rgb(51,0,101)">  62</span>│<span style="background-color:rgb(81,0,101)">  28</span>│<span style="background-color:rgb(101,0,91)">  46</span>│<span style="background-color:rgb(101,0,61)">  59</span>│<span style="background-color:rgb(101,0,30)">  30</span>│<span style="background-color:rgb(101,0,0)">  51</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   2</span>│<span style="background-color:rgb(0,101,40)">   0</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   2</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   0</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│
 │ 🏆  ⏱ 1ms  💰 g:0
─┴───────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(223,31,31)">  11</span>│<span style="color:rgb(66,223,31)">   1</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)">   3</span>│
 │ │ │   10│<span style="color:rgb(136,223,31)">   3</span>⇄<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(170,223,31)">   4</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 9 ───── 📈 4 🟰 13 📉 3
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(223,205,31)">   6</span>│<span style="color:rgb(170,223,31)">   4</span>⇄<span style="color:rgb(223,31,31)">  11</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)">   3</span>│<span style="color:rgb(205,223,31)">   5</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(31,223,31)">   0</span>│
 │ │ │   10│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(66,223,31)">   1</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(223,170,31)">   7</span>│<span style="color:rgb(136,223,31)">   3</span>⇄<span style="color:rgb(101,223,31)">   2</span>│<span style="color:rgb(101,223,31)">   2</span>⇄<span style="color:rgb(205,223,31)">   5</span>│<span style="color:rgb(136,223,31)">   3</span>⇄<span style="color:rgb(170,223,31)">   4</span>│
 │ │ └──────────────────────────────────── 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 20
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 100 | <span style="color:gray">P8(PROB_MUTAR):</span> 50 | <span style="color:gray">P9(SELECAO):</span> Roleta | <span style="color:gray">P10(PRESSAO):</span> 150
│ <span style="color:gray">P13(SOBREVIVENCIA):</span> Idade | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100 | <span style="color:gray">P16(ELITISMO):</span> 1
│ <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza | <span style="color:gray">P19(DIST_MINIMA):</span> 0
│ <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> inserir
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::♛ ::  
♛ ::  ::  ::
::  ::  ♛   
  ♛   ::  ::
::  ::  ::♛ 
  ::♛ ::  ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 1 | <span style="color:gray">I3(Iterações):</span> 169 | <span style="color:gray">I4(Épocas):</span> 7 | 
│ <span style="color:gray">I5(Gerações):</span> 174
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos identificar o filho 10 com custo 0, gerado por pais de custo 2 e 3. Vamos colocar os pais, que são os elementos 10 e 12, junto com o filho com a solução:
- Pai: `0 2 4 1 5 3`
- Mãe: `3 0 5 4 2 1`
- Filho: `3 0 4 1 5 2`

É visivel que os dois primeiros elementos vêm de um dos pais, e os restantes do outro pai.
Nenhum dos pais tinha custo 1, pelo que se a população fosse dominada por elementos de custo 1, estes dois elementos tinham menos probabilidade de se encontrarem e gerarem um filho com a solução.


- 
\anchor 8damas-cp4
## Ação 4 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

[Resultdos Deucalion](melhorativa__deucalion.html)

Neste estudo foi identificada a melhor parmetrização para este problema e codificação:
**P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0.**

Podemos ver como a alteração da parametrização afeta este exemplo: 

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├─┬─ 📆 0 ⏱  ──── 💰 g2-6
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">1   </span>2 1 4 3 5 0  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">2   </span>0 2 4 5 3 1  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">3   </span>5 0 2 3 1 4  💰 <span style="color:rgb(223,223,31)">g:3</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">4   </span>0 4 5 2 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">5   </span>1 2 5 4 3 0  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">6   </span>4 0 1 2 3 5  💰 <span style="color:rgb(223,31,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">7   </span>2 5 4 0 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">8   </span>2 4 1 0 3 5  💰 <span style="color:rgb(159,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">9   </span>4 0 2 1 3 5  💰 <span style="color:rgb(223,95,31)">g:5</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">10  </span>0 5 4 2 3 1  💰 <span style="color:rgb(223,159,31)">g:4</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(101,61,0)">1   </span> <span style="background-color:rgb(81,101,0)">2   </span> <span style="background-color:rgb(20,101,0)">3   </span> <span style="background-color:rgb(0,101,40)">4   </span> <span style="background-color:rgb(0,101,101)">5   </span> <span style="background-color:rgb(0,40,101)">6   </span> <span style="background-color:rgb(20,0,101)">7   </span> <span style="background-color:rgb(81,0,101)">8   </span> <span style="background-color:rgb(101,0,61)">9   </span> <span style="background-color:rgb(101,0,0)">10  </span> 
 │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(101,61,0)">1   </span>│    │   5│   5│   6│   5│   6│   4│   5│   6│   5│
 │ │ <span style="background-color:rgb(81,101,0)">2   </span>│   5│    │   6│   3│   4│   5│   3│   5│   5│   2│
 │ │ <span style="background-color:rgb(20,101,0)">3   </span>│   5│   6│    │   6│   6│   5│   6│   6│   4│   6│
 │ │ <span style="background-color:rgb(0,101,40)">4   </span>│   6│   3│   6│    │   4│   4│   4│   4│   5│   2│
 │ │ <span style="background-color:rgb(0,101,101)">5   </span>│   5│   4│   6│   4│    │   5│   5│   5│   5│   5│
 │ │ <span style="background-color:rgb(0,40,101)">6   </span>│   6│   5│   5│   4│   5│    │   5│   3│   2│   4│
 │ │ <span style="background-color:rgb(20,0,101)">7   </span>│   4│   3│   6│   4│   5│   5│    │   3│   5│   2│
 │ │ <span style="background-color:rgb(81,0,101)">8   </span>│   5│   5│   6│   4│   5│   3│   3│    │   4│   5│
 │ │ <span style="background-color:rgb(101,0,61)">9   </span>│   6│   5│   4│   5│   5│   2│   5│   4│    │   5│
 │ │ <span style="background-color:rgb(101,0,0)">10  </span>│   5│   2│   6│   2│   5│   4│   2│   5│   5│    │
 │ │ ────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 10 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Torneio, tamanho 10, probabilidade melhor 100 ───── 
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,61,0)">   0</span>│<span style="background-color:rgb(81,101,0)">   5</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,40)">   0</span>│<span style="background-color:rgb(0,101,101)">   0</span>│<span style="background-color:rgb(0,40,101)">   0</span>│<span style="background-color:rgb(20,0,101)">   0</span>│<span style="background-color:rgb(81,0,101)">   4</span>│<span style="background-color:rgb(101,0,61)">   0</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 10 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(81,0,101)">   8</span>⇄<span style="background-color:rgb(81,101,0)">   2</span>│<span style="background-color:rgb(20,101,0)">   3</span>⇄<span style="background-color:rgb(81,101,0)">   2</span>│<span style="background-color:rgb(81,0,101)">   8</span>⇄<span style="background-color:rgb(81,0,101)">   8</span>│<span style="background-color:rgb(81,0,101)">   8</span>⇄<span style="background-color:rgb(81,101,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   2</span>⇄<span style="background-color:rgb(81,101,0)">   2</span>│
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
::  ::  ♛   
  ::♛ ::  ::
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,223,31)">   3</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(159,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 0  🦠 10 ───── 📈 1 🟰 4 📉 5
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(31,223,31)">   0</span>│<span style="color:rgb(223,223,31)">   3</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,159,31)">   4</span>⇄<span style="color:rgb(159,223,31)">   2</span>│<span style="color:rgb(223,95,31)">   5</span>⇄<span style="color:rgb(223,31,31)">   6</span>│<span style="color:rgb(159,223,31)">   2</span>⇄<span style="color:rgb(223,223,31)">   3</span>│
 │ │ └──────────────────────────────────── 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙   ─ <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>2 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
8 Damas (Permutação)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Algoritmo Evolutivo | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 1000000 | <span style="color:gray">P6(POPULACAO):</span> 10
│ <span style="color:gray">P7(PROB_CRUZAR):</span> 0 | <span style="color:gray">P8(PROB_MUTAR):</span> 100 | <span style="color:gray">P9(SELECAO):</span> Torneio | <span style="color:gray">P11(TAMANHO_TORNEIO):</span> 10
│ <span style="color:gray">P12(PROB_MELHOR_TORNEIO):</span> 100 | <span style="color:gray">P13(SOBREVIVENCIA):</span> round-robin | <span style="color:gray">P14(PERC_DESCENDENTES):</span> 100
│ <span style="color:gray">P15(Q_ROUND_ROBIN):</span> 2 | <span style="color:gray">P16(ELITISMO):</span> 3 | <span style="color:gray">P17(IMIGRANTES):</span> 1 | <span style="color:gray">P18(DIVERSIDADE):</span> Limpeza
│ <span style="color:gray">P19(DIST_MINIMA):</span> 0 | <span style="color:gray">P20(TIPO_CRUZAR):</span> Order | <span style="color:gray">P21(TIPO_MUTAR):</span> 0 | <span style="color:gray">P22(TIPO_VIZINHO):</span> trocaPar
│ <span style="color:gray">P23(LIMITE_VIZINHOS):</span> 0 | <span style="color:gray">P24(TIPO_DISTANCIA):</span> Hamming
└──────────────────────────────────────────────────────────────────────
::  ::  ♛   
  ::♛ ::  ::
♛   ::  ::  
  ::  ::  ♛ 
::  ::♛ ::  
  ♛   ::  ::
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(Resultado):</span> 0 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 21 | <span style="color:gray">I4(Épocas):</span> 1 | 
│ <span style="color:gray">I5(Gerações):</span> 20
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Com a configuração optimizada, bastou uma época para encontrar a solução para esta instância.
O filho 2 foi gerado de dois pais de custo 2, e tem um irmão de custo 4.
Os pais são os elementos 8 e 2. Estes pais têm ambos o melhor custo, e foram escolhidos como pais 4 e 5 vezes.
Acabou por não serem vezes a mais, já que fizeram para também nos elementos 7 e 8, e tiveram filhos de custo 5 e 6.


| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
