@page teste_particao_cb Teste Particao - Codificação Binária

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base no problema da Partição, com codificação binária.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute.
No Linux na pasta `.../TProcura/Melhorativa/Teste$` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#particao-cb1)
- [Ação 2 - Resolver manualmente](#particao-cb2)
- [Ação 3 - Algoritmos Evolutivos](#particao-cb3)
- [Ação 4 - Testes Empíricos](#particao-cb4)

\htmlonly
<pre>
┌─ Teste TProcuraMelhorativa ──┐
│ 1 - 8 Damas (Inteira)        │
│ 2 - 8 Damas (Permutacao)     │
│ 3 - Partição (Binária)       │
└──────────────────────────────┘
Opção: <span class="entrada">3</span>
</pre>
\endhtmlonly

\anchor particao-cb1
## Ação 1 - Ver instâncias

Vamos entrar no problema da Partição, com representação binária, introduza: **3.**

\htmlonly
<pre>
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> NADA | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ├─ 📦1192 → ◀️711 = ▶️481 ─
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   [90mInstância</span>  │ 2 🔍  [90mExplorar</span> │ 3 ⚙   [90mParâmetros</span>    │ 4 ✔  [90mSolução</span> │
│ 5 ⚖   [90mIndicadores</span> │ 6 ►   [90mExecutar</span> │ 7 🛠️  [90mConfigurações</span> │ 8 🧪  [90mTeste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly

Temos inicialmente uma instância de 10 elementos, mas devido ao nível de debug não vemos o estado completo.
Introduza: **3; 2; 4; *ENTER*.**

\htmlonly
<pre>
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> COMPLETO | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ┌─ 📦1192 → ◀️711 = ▶️481 ──────────────────────────────────────────────
 ├─ ◀️ ─ 106 111 114 124 124 132
 ├─ ▶️ ─ 107 109 124 141
 └──────────────────────────────────────────────────────────────────────
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   [90mInstância</span>  │ 2 🔍  [90mExplorar</span> │ 3 ⚙   [90mParâmetros</span>    │ 4 ✔  [90mSolução</span> │
│ 5 ⚖   [90mIndicadores</span> │ 6 ►   [90mExecutar</span> │ 7 🛠️  [90mConfigurações</span> │ 8 🧪  [90mTeste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly

Agora podemos ver os números todos, já num dos lados (esquerda ou direita). 

Vamos deixar esta instância.
Significa que temos de decidir para cada um dos 10 elementos, em que lado fica, esquerda ou direita,
de modo a que o somatório seja igual.

\anchor particao-cb2
## Ação 2 - Resolver manualmente

Vamos resolver a instância manualmente. Introduza: **2**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
 ├─┬─ 📆 0 ⏱  ──── 💰 g432-662
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1111110001 💰 <span style="color:rgb(223,164,31)">g:432</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0000001001 💰 <span style="color:rgb(223,31,31)">g:662</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1100011111 💰 <span style="color:rgb(223,111,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0001100010 💰 <span style="color:rgb(223,138,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   7│   6│   6│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   7│    │   5│   5│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   6│   5│    │   8│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   6│   5│   8│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): 
</pre>
\endhtmlonly

Como a codificação é binária, temos uma sequência de bits, 0/1, tantos quantos os números existentes, neste caso 10.

O valor do custo é a diferença obtida após a divisão dos núemros. Pretende-se uma instância de custo 0, ou seja, ambos os
lados com o mesmo somatório.

Vamos testar a mutação. Introduza: **1; 1.**

\htmlonly
<pre>
│ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">1</span>
 │ ┌───── 🦠  ───── 
 │ │ 🧍  [1-4]: <span class="entrada">1</span>
 │ │ 🧍   1111110001 mutar vizinho #bits 1 (9)
 │ │ 🦠   1111110000
 │ 🏆  ⏱  💰 g:150
─┴───────────────────
 │ │  ┌─ 📦1192 → ◀️671 = ▶️521 ──────────────────────────────────────────────
 │ │  ├─ ◀️ ─ 106 107 109 111 114 124
 │ │  ├─ ▶️ ─ 124 124 132 141
 │ │  └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ └────────────── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g150-662
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1111110000 💰 <span style="color:rgb(118,223,31)">g:150</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>0000001001 💰 <span style="color:rgb(223,31,31)">g:662</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1100011111 💰 <span style="color:rgb(223,111,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0001100010 💰 <span style="color:rgb(223,138,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   8│   7│   5│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   8│    │   5│   5│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   7│   5│    │   8│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   5│   5│   8│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): 
</pre>
\endhtmlonly

Foi mutado o bit na posição 9. O custo melhorou, sendo agora o melhor dos custos, mesmo assim 150, ainda distante de 0.

Vamos testar o cruzamento nos dois melhores, elementos 1 e 4.
Introduza: **2; 1; 4; 2.**

\htmlonly
<pre>
│ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">2</span>
 │ ┌───── 🧬  ───── 
 │ │ 🧍 Pai [1-4]: <span class="entrada">1</span>
 │ │ 🧍 Mãe [1-4]: <span class="entrada">4</span>
 │ │ 🧍 Filho [1-4]: <span class="entrada">2</span>
 │ │ 
 │ │ 🧍 Pai   1111110000
 │ │ 🧍 Mãe   0001100010 cruzamento 1-ponto(s): 8 
 │ │ 🧬 Filho 1111110010
 │ │  ┌─ 📦1192 → ◀️803 = ▶️389 ──────────────────────────────────────────────
 │ │  ├─ ◀️ ─ 106 107 109 111 114 124 132
 │ │  ├─ ▶️ ─ 124 124 141
 │ │  └──────────────────────────────────────────────────────────────────────
 │ └────────────── 
 ├─┬─ 📆 2 ⏱  ──── 💰 g150-524
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1111110000 💰 <span style="color:rgb(141,223,31)">g:150</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>1111110010 💰 <span style="color:rgb(223,112,31)">g:414</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1100011111 💰 <span style="color:rgb(223,31,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0001100010 💰 <span style="color:rgb(223,65,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   1│   7│   5│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   1│    │   6│   4│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   7│   6│    │   8│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   5│   4│   8│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): 
</pre>
\endhtmlonly

Foi aplicado o cruzamento a 1 ponto, tendo o ponto sido na posição 8. Assim o filho ficou com 8 bits do pai, e os dois últimos bits da mãe.
Ficou com um custo de 414, entre o pai e a mãe.

Vamos agora testar a vizinhança, usando o melhor estado. Introduza: **3; 1.**

\htmlonly
<pre>
│ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">1</span>
 │ │ 🧍   1111110000 vizinhança 1 bits
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">1   </span>0111110000 💰 <span style="color:rgb(86,223,31)">g:62</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">2   </span>1011110000 💰 <span style="color:rgb(88,223,31)">g:64</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">3   </span>1101110000 💰 <span style="color:rgb(92,223,31)">g:68</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">4   </span>1110110000 💰 <span style="color:rgb(95,223,31)">g:72</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">5   </span>1111010000 💰 <span style="color:rgb(100,223,31)">g:78</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">6   </span>1111100000 💰 <span style="color:rgb(118,223,31)">g:98</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">7   </span>1111111000 💰 <span style="color:rgb(223,61,31)">g:398</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">8   </span>1111110100 💰 <span style="color:rgb(223,61,31)">g:398</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">9   </span>1111110010 💰 <span style="color:rgb(223,47,31)">g:414</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">10  </span>1111110001 💰 <span style="color:rgb(223,31,31)">g:432</span>
 │ │ 🧍 [1-10]: 
</pre>
\endhtmlonly


Temos vários vizinhos com custo inferior, em que estes vizinhos é trocado um só bit. Vamos escolher o vizinho 1 e repetir.
Introduza: **1; 3; 1.**

\htmlonly
<pre>
│ │ 🧍 [1-10]: <span class="entrada">1</span>
 │ │ 
 │ 🏆  ⏱  💰 g:62
─┴───────────────────
 │ │  ┌─ 📦1192 → ◀️565 = ▶️627 ──────────────────────────────────────────────
 │ │  ├─ ◀️ ─ 107 109 111 114 124
 │ │  ├─ ▶️ ─ 106 124 124 132 141
 │ │  └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ └────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g62-524
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>0111110000 💰 <span style="color:rgb(77,223,31)">g:62</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>1111110010 💰 <span style="color:rgb(223,112,31)">g:414</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1100011111 💰 <span style="color:rgb(223,31,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0001100010 💰 <span style="color:rgb(223,65,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   2│   8│   4│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   2│    │   6│   4│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   8│   6│    │   8│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   4│   4│   8│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">3</span>
 │ ┌───── 🧍🧍 ───── 
 │ │ 🧍 [1-4]: <span class="entrada">1</span>
 │ │ 🧍   0111110000 vizinhança 1 bits
 │ ├───── Vizinhos ───── 
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">1   </span>1111110000 💰 <span style="color:rgb(216,223,31)">g:150</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">2   </span>0011110000 💰 <span style="color:rgb(223,73,31)">g:276</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">3   </span>0101110000 💰 <span style="color:rgb(223,68,31)">g:280</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">4   </span>0110110000 💰 <span style="color:rgb(223,63,31)">g:284</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">5   </span>0111010000 💰 <span style="color:rgb(223,56,31)">g:290</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">6   </span>0111100000 💰 <span style="color:rgb(223,31,31)">g:310</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">7   </span>0111111000 💰 <span style="color:rgb(223,184,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">8   </span>0111110100 💰 <span style="color:rgb(223,184,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">9   </span>0111110010 💰 <span style="color:rgb(223,165,31)">g:202</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">10  </span>0111110001 💰 <span style="color:rgb(223,142,31)">g:220</span>
 │ │ 🧍 [1-10]: 
</pre>
\endhtmlonly

Neste caso todos os vizinhos têm um custo superior ao próprio, sendo o vizinho de melhor custo o pai deste, portanto voltariamos
ao mesmo estado se o escolhessemos. Estamos no óptimo local.

Vamos escolher um vizinho e terminar. Introduza: **1; 0.**

\htmlonly
<pre>
 │ │ 🧍 [1-10]: <span class="entrada">1</span>
 │ │ 
 │ │  ┌─ 📦1192 → ◀️671 = ▶️521 ──────────────────────────────────────────────
 │ │  ├─ ◀️ ─ 106 107 109 111 114 124
 │ │  ├─ ▶️ ─ 124 124 132 141
 │ │  └──────────────────────────────────────────────────────────────────────
 │ └────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g150-524
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">1   </span>1111110000 💰 <span style="color:rgb(141,223,31)">g:150</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">2   </span>1111110010 💰 <span style="color:rgb(223,112,31)">g:414</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">3   </span>1100011111 💰 <span style="color:rgb(223,31,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">4   </span>0001100010 💰 <span style="color:rgb(223,65,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │  🧍  <span style="background-color:rgb(51,101,0)">1   </span> <span style="background-color:rgb(0,101,101)">2   </span> <span style="background-color:rgb(51,0,101)">3   </span> <span style="background-color:rgb(101,0,0)">4   </span> 
 │ │ ────┼────┼────┼────┼────┼
 │ │ <span style="background-color:rgb(51,101,0)">1   </span>│    │   1│   7│   5│
 │ │ <span style="background-color:rgb(0,101,101)">2   </span>│   1│    │   6│   4│
 │ │ <span style="background-color:rgb(51,0,101)">3   </span>│   7│   6│    │   8│
 │ │ <span style="background-color:rgb(101,0,0)">4   </span>│   5│   4│   8│    │
 │ │ ────┴────┴────┴────┴────┴
 │ └─■ ⚡ Operação (1 🦠 Mutar, 2 🧬 Cruzar, 3 🧍🧍Vizinhos): <span class="entrada">0</span>
 └──────────────── 
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> COMPLETO | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ┌─ 📦1192 → ◀️565 = ▶️627 ──────────────────────────────────────────────
 ├─ ◀️ ─ 107 109 111 114 124
 ├─ ▶️ ─ 106 124 124 132 141
 └──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly


\anchor particao-cb3
## Ação 3 - Algoritmos Evolutivos

Vamos  ver os algoritmos evolutivos nos diferentes níveis de debug, para esta instância de tamanho 10.

Introduza: **1; 10; 3; 2; 1; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══.
 │ 🏆  ⏱  💰 g:204
─┴───────────────────
 ├─ 📦1192 → ◀️494 = ▶️698 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:14
─┴───────────────────
 ├─ 📦1192 → ◀️603 = ▶️589 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:8
─┴───────────────────
 ├─ 📦1192 → ◀️592 = ▶️600 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:6
─┴───────────────────
 ├─ 📦1192 → ◀️593 = ▶️599 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
 ├─ 📦1192 → ◀️595 = ▶️597 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
─┬───────────────────
 ├─ Parâmetros ─ [90mP1=</span>1 [90mP2=</span>1 [90mP3=</span>1 [90mP4=</span>10 [90mP5=</span>1000000 [90mP6=</span>20 [90mP7=</span>100 [90mP8=</span>50 [90mP9=</span>1 [90mP10=</span>150 [90mP13=</span>1
 ├─ ⚙   ─ [90mP14=</span>100 [90mP16=</span>1 [90mP17=</span>1 [90mP18=</span>3 [90mP19=</span>0 [90mP20=</span>1 [90mP21=</span>0 [90mP22=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> ATIVIDADE | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ [90mI1(Resultado):</span> 0 | [90mI2(Tempo(ms)):</span> 0 | [90mI3(Iterações):</span> 232 | [90mI4(Épocas):</span> 10 | 
│ [90mI5(Gerações):</span> 240
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly


Introduza: **1; 10; 3; 2; 2; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:204
─┴───────────────────
 ├─ 📦1192 → ◀️494 = ▶️698 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:14
─┴───────────────────
 ├─ 📦1192 → ◀️603 = ▶️589 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:8
─┴───────────────────
 ├─ 📦1192 → ◀️592 = ▶️600 ─
─┬───────────────────
 ├─── 📆 0 ⏱  ──── 💰 g8-1192
 ├─── 📆 1 ⏱  ──── 💰 g8-944
 │ 🏆  ⏱  💰 g:6
─┴───────────────────
 ├─ 📦1192 → ◀️593 = ▶️599 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
 ├─ 📦1192 → ◀️595 = ▶️597 ─
─┬───────────────────
 ├─── 📆 2 ⏱  ──── 💰 g2-710
 ├─── 📆 3 ⏱  ──── 💰 g2-910
 ├─── 📆 4 ⏱  ──── 💰 g2-732
 ├─── 📆 5 ⏱  ──── 💰 g2-532
 ├─── 📆 6 ⏱  ──── 💰 g2-696
 ├─── 📆 7 ⏱  ──── 💰 g2-514
 ├─── 📆 8 ⏱  ──── 💰 g2-680
 ├─── 📆 9 ⏱  ──── 💰 g2-524
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
─┬───────────────────
 ├─ Parâmetros ─ [90mP1=</span>1 [90mP2=</span>2 [90mP3=</span>1 [90mP4=</span>10 [90mP5=</span>1000000 [90mP6=</span>20 [90mP7=</span>100 [90mP8=</span>50 [90mP9=</span>1 [90mP10=</span>150 [90mP13=</span>1
 ├─ ⚙   ─ [90mP14=</span>100 [90mP16=</span>1 [90mP17=</span>1 [90mP18=</span>3 [90mP19=</span>0 [90mP20=</span>1 [90mP21=</span>0 [90mP22=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> PASSOS | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ [90mI1(Resultado):</span> 0 | [90mI2(Tempo(ms)):</span> 0 | [90mI3(Iterações):</span> 232 | [90mI4(Épocas):</span> 10 | 
│ [90mI5(Gerações):</span> 240
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly


Introduza: **1; 10; 3; 2; 3; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:204
─┴───────────────────
 ├─ 📦1192 → ◀️494 = ▶️698 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:14
─┴───────────────────
 ├─ 📦1192 → ◀️603 = ▶️589 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:8
─┴───────────────────
 ├─ 📦1192 → ◀️592 = ▶️600 ─
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g8-1192 [📏 0-9 (μ=5, melhor/pior 5)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(170,223,31)"> 432</span>│<span style="color:rgb(223,201,31)"> 662</span>│<span style="color:rgb(200,223,31)"> 524</span>│<span style="color:rgb(185,223,31)"> 478</span>│<span style="color:rgb(97,223,31)"> 204</span>│<span style="color:rgb(36,223,31)">  14</span>│<span style="color:rgb(171,223,31)"> 434</span>│<span style="color:rgb(223,31,31)">1192</span>│<span style="color:rgb(223,182,31)"> 722</span>│<span style="color:rgb(179,223,31)"> 460</span>│
 │ │  10│<span style="color:rgb(51,223,31)">  62</span>│<span style="color:rgb(178,223,31)"> 458</span>│<span style="color:rgb(103,223,31)"> 222</span>│<span style="color:rgb(181,223,31)"> 466</span>│<span style="color:rgb(223,181,31)"> 726</span>│<span style="color:rgb(34,223,31)">   8</span>│<span style="color:rgb(40,223,31)">  26</span>│<span style="color:rgb(106,223,31)"> 234</span>│<span style="color:rgb(36,223,31)">  14</span>│<span style="color:rgb(191,223,31)"> 498</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g8-944 [📏 1-9 (μ=4, melhor/pior 6)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,146,31)"> 662</span>│<span style="color:rgb(44,223,31)">  32</span>│<span style="color:rgb(56,223,31)">  62</span>│<span style="color:rgb(133,223,31)"> 250</span>│<span style="color:rgb(215,223,31)"> 452</span>│<span style="color:rgb(111,223,31)"> 196</span>│<span style="color:rgb(207,223,31)"> 434</span>│<span style="color:rgb(42,223,31)">  26</span>│<span style="color:rgb(139,223,31)"> 266</span>│<span style="color:rgb(223,130,31)"> 700</span>│
 │ │  10│<span style="color:rgb(223,113,31)"> 742</span>│<span style="color:rgb(223,131,31)"> 698</span>│<span style="color:rgb(157,223,31)"> 310</span>│<span style="color:rgb(37,223,31)">  14</span>│<span style="color:rgb(35,223,31)">   8</span>│<span style="color:rgb(143,223,31)"> 276</span>│<span style="color:rgb(127,223,31)"> 236</span>│<span style="color:rgb(127,223,31)"> 236</span>│<span style="color:rgb(223,118,31)"> 730</span>│<span style="color:rgb(223,31,31)"> 944</span>│
 │ └──────────────────────────────────── 
 │ 🏆  ⏱  💰 g:6
─┴───────────────────
 ├─ 📦1192 → ◀️593 = ▶️599 ─
─┬───────────────────
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
 ├─ 📦1192 → ◀️595 = ▶️597 ─
─┬───────────────────
 ├─┬─ 📆 2 ⏱  ──── 💰 g2-710 [📏 1-9 (μ=4, melhor/pior 5)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(159,223,31)"> 236</span>│<span style="color:rgb(35,223,31)">   6</span>│<span style="color:rgb(169,223,31)"> 256</span>│<span style="color:rgb(159,223,31)"> 236</span>│<span style="color:rgb(112,223,31)"> 150</span>│<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(164,223,31)"> 246</span>│<span style="color:rgb(51,223,31)">  36</span>│<span style="color:rgb(223,165,31)"> 462</span>│<span style="color:rgb(39,223,31)">  14</span>│
 │ │  10│<span style="color:rgb(157,223,31)"> 234</span>│<span style="color:rgb(223,173,31)"> 448</span>│<span style="color:rgb(177,223,31)"> 270</span>│<span style="color:rgb(223,199,31)"> 398</span>│<span style="color:rgb(49,223,31)">  32</span>│<span style="color:rgb(159,223,31)"> 236</span>│<span style="color:rgb(65,223,31)">  62</span>│<span style="color:rgb(55,223,31)">  44</span>│<span style="color:rgb(223,31,31)"> 710</span>│<span style="color:rgb(173,223,31)"> 262</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 3 ⏱  ──── 💰 g2-910 [📏 1-9 (μ=4, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(136,223,31)"> 250</span>│<span style="color:rgb(131,223,31)"> 236</span>│<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(151,223,31)"> 284</span>│<span style="color:rgb(39,223,31)">  18</span>│<span style="color:rgb(142,223,31)"> 262</span>│<span style="color:rgb(223,205,31)"> 498</span>│<span style="color:rgb(223,128,31)"> 680</span>│<span style="color:rgb(214,223,31)"> 434</span>│<span style="color:rgb(154,223,31)"> 292</span>│
 │ │  10│<span style="color:rgb(124,223,31)"> 220</span>│<span style="color:rgb(57,223,31)">  62</span>│<span style="color:rgb(223,31,31)"> 910</span>│<span style="color:rgb(223,136,31)"> 662</span>│<span style="color:rgb(223,196,31)"> 518</span>│<span style="color:rgb(128,223,31)"> 230</span>│<span style="color:rgb(47,223,31)">  36</span>│<span style="color:rgb(128,223,31)"> 230</span>│<span style="color:rgb(220,223,31)"> 448</span>│<span style="color:rgb(103,223,31)"> 170</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 4 ⏱  ──── 💰 g2-732 [📏 1-9 (μ=5, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(142,223,31)"> 212</span>│<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(41,223,31)">  18</span>│<span style="color:rgb(223,198,31)"> 414</span>│<span style="color:rgb(223,143,31)"> 518</span>│<span style="color:rgb(162,223,31)"> 250</span>│<span style="color:rgb(46,223,31)">  28</span>│<span style="color:rgb(223,161,31)"> 484</span>│<span style="color:rgb(223,31,31)"> 732</span>│<span style="color:rgb(223,180,31)"> 448</span>│
 │ │  10│<span style="color:rgb(186,223,31)"> 296</span>│<span style="color:rgb(223,50,31)"> 696</span>│<span style="color:rgb(166,223,31)"> 258</span>│<span style="color:rgb(223,169,31)"> 468</span>│<span style="color:rgb(223,137,31)"> 530</span>│<span style="color:rgb(41,223,31)">  18</span>│<span style="color:rgb(48,223,31)">  32</span>│<span style="color:rgb(168,223,31)"> 262</span>│<span style="color:rgb(53,223,31)">  42</span>│<span style="color:rgb(176,223,31)"> 276</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 5 ⏱  ──── 💰 g2-532 [📏 1-8 (μ=4, melhor/pior 2)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,215,31)"> 276</span>│<span style="color:rgb(178,223,31)"> 204</span>│<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(44,223,31)">  18</span>│<span style="color:rgb(223,66,31)"> 484</span>│<span style="color:rgb(184,223,31)"> 212</span>│<span style="color:rgb(197,223,31)"> 230</span>│<span style="color:rgb(36,223,31)">   6</span>│<span style="color:rgb(223,92,31)"> 448</span>│<span style="color:rgb(223,44,31)"> 514</span>│
 │ │  10│<span style="color:rgb(223,31,31)"> 532</span>│<span style="color:rgb(223,76,31)"> 470</span>│<span style="color:rgb(191,223,31)"> 222</span>│<span style="color:rgb(158,223,31)"> 176</span>│<span style="color:rgb(223,90,31)"> 450</span>│<span style="color:rgb(223,52,31)"> 504</span>│<span style="color:rgb(37,223,31)">   8</span>│<span style="color:rgb(223,53,31)"> 502</span>│<span style="color:rgb(39,223,31)">  10</span>│<span style="color:rgb(223,73,31)"> 474</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 6 ⏱  ──── 💰 g2-696 [📏 1-10 (μ=4, melhor/pior 3)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(192,223,31)"> 292</span>│<span style="color:rgb(191,223,31)"> 290</span>│<span style="color:rgb(141,223,31)"> 200</span>│<span style="color:rgb(183,223,31)"> 276</span>│<span style="color:rgb(147,223,31)"> 210</span>│<span style="color:rgb(143,223,31)"> 204</span>│<span style="color:rgb(51,223,31)">  36</span>│<span style="color:rgb(167,223,31)"> 246</span>│<span style="color:rgb(167,223,31)"> 246</span>│<span style="color:rgb(152,223,31)"> 220</span>│
 │ │  10│<span style="color:rgb(41,223,31)">  18</span>│<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(156,223,31)"> 226</span>│<span style="color:rgb(153,223,31)"> 222</span>│<span style="color:rgb(52,223,31)">  38</span>│<span style="color:rgb(159,223,31)"> 232</span>│<span style="color:rgb(223,137,31)"> 504</span>│<span style="color:rgb(192,223,31)"> 292</span>│<span style="color:rgb(223,31,31)"> 696</span>│<span style="color:rgb(51,223,31)">  36</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 7 ⏱  ──── 💰 g2-514 [📏 1-9 (μ=4, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(39,223,31)">  10</span>│<span style="color:rgb(194,223,31)"> 218</span>│<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(220,223,31)"> 254</span>│<span style="color:rgb(223,69,31)"> 464</span>│<span style="color:rgb(170,223,31)"> 186</span>│<span style="color:rgb(203,223,31)"> 230</span>│<span style="color:rgb(223,78,31)"> 452</span>│<span style="color:rgb(214,223,31)"> 246</span>│<span style="color:rgb(189,223,31)"> 212</span>│
 │ │  10│<span style="color:rgb(37,223,31)">   8</span>│<span style="color:rgb(188,223,31)"> 210</span>│<span style="color:rgb(67,223,31)">  48</span>│<span style="color:rgb(217,223,31)"> 250</span>│<span style="color:rgb(195,223,31)"> 220</span>│<span style="color:rgb(182,223,31)"> 202</span>│<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(223,106,31)"> 414</span>│<span style="color:rgb(223,31,31)"> 514</span>│<span style="color:rgb(57,223,31)">  34</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 8 ⏱  ──── 💰 g2-680 [📏 1-8 (μ=4, melhor/pior 7)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,106,31)"> 548</span>│<span style="color:rgb(142,223,31)"> 196</span>│<span style="color:rgb(223,143,31)"> 482</span>│<span style="color:rgb(223,131,31)"> 502</span>│<span style="color:rgb(223,31,31)"> 680</span>│<span style="color:rgb(155,223,31)"> 220</span>│<span style="color:rgb(223,151,31)"> 468</span>│<span style="color:rgb(136,223,31)"> 186</span>│<span style="color:rgb(136,223,31)"> 186</span>│<span style="color:rgb(178,223,31)"> 260</span>│
 │ │  10│<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(172,223,31)"> 250</span>│<span style="color:rgb(37,223,31)">  10</span>│<span style="color:rgb(180,223,31)"> 264</span>│<span style="color:rgb(191,223,31)"> 284</span>│<span style="color:rgb(183,223,31)"> 270</span>│<span style="color:rgb(175,223,31)"> 256</span>│<span style="color:rgb(223,141,31)"> 486</span>│<span style="color:rgb(223,136,31)"> 494</span>│<span style="color:rgb(172,223,31)"> 250</span>│
 │ └──────────────────────────────────── 
 ├─┬─ 📆 9 ⏱  ──── 💰 g2-524 [📏 1-9 (μ=4, melhor/pior 4)]
 │ │🧍     1    2    3    4    5    6    7    8    9   10 
 │ │────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │   0│<span style="color:rgb(223,90,31)"> 444</span>│<span style="color:rgb(201,223,31)"> 232</span>│<span style="color:rgb(52,223,31)">  28</span>│<span style="color:rgb(39,223,31)">  10</span>│<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(52,223,31)">  28</span>│<span style="color:rgb(214,223,31)"> 250</span>│<span style="color:rgb(211,223,31)"> 246</span>│<span style="color:rgb(223,97,31)"> 434</span>│<span style="color:rgb(167,223,31)"> 186</span>│
 │ │  10│<span style="color:rgb(204,223,31)"> 236</span>│<span style="color:rgb(223,59,31)"> 486</span>│<span style="color:rgb(223,87,31)"> 448</span>│<span style="color:rgb(56,223,31)">  34</span>│<span style="color:rgb(223,31,31)"> 524</span>│<span style="color:rgb(53,223,31)">  30</span>│<span style="color:rgb(192,223,31)"> 220</span>│<span style="color:rgb(223,218,31)"> 268</span>│<span style="color:rgb(223,72,31)"> 468</span>│<span style="color:rgb(223,65,31)"> 478</span>│
 │ └──────────────────────────────────── 
 │ 🏆  ⏱  💰 g:0
─┴───────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
─┬───────────────────
 ├─ Parâmetros ─ [90mP1=</span>1 [90mP2=</span>3 [90mP3=</span>1 [90mP4=</span>10 [90mP5=</span>1000000 [90mP6=</span>20 [90mP7=</span>100 [90mP8=</span>50 [90mP9=</span>1 [90mP10=</span>150 [90mP13=</span>1
 ├─ ⚙   ─ [90mP14=</span>100 [90mP16=</span>1 [90mP17=</span>1 [90mP18=</span>3 [90mP19=</span>0 [90mP20=</span>1 [90mP21=</span>0 [90mP22=</span>1
═╧═ 🏁  Execução terminada ⏱    ═══
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> DETALHE | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ├─ 📦1192 → ◀️596 = ▶️596 ─
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ [90mI1(Resultado):</span> 0 | [90mI2(Tempo(ms)):</span> 0 | [90mI3(Iterações):</span> 232 | [90mI4(Épocas):</span> 10 | 
│ [90mI5(Gerações):</span> 240
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly


Introduza: **1; 10; 3; 2; 4; *ENTER*;6.**

\htmlonly
<pre>
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 │ 🏆  ⏱  💰 g:204
─┴───────────────────
 ┌─ 📦1192 → ◀️494 = ▶️698 ──────────────────────────────────────────────
 ├─ ◀️ ─ 114 124 124 132
 ├─ ▶️ ─ 106 107 109 111 124 141
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ 🏆  ⏱  💰 g:14
─┴───────────────────
 ┌─ 📦1192 → ◀️603 = ▶️589 ──────────────────────────────────────────────
 ├─ ◀️ ─ 109 114 124 124 132
 ├─ ▶️ ─ 106 107 111 124 141
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ 🏆  ⏱  💰 g:8
─┴───────────────────
 ┌─ 📦1192 → ◀️592 = ▶️600 ──────────────────────────────────────────────
 ├─ ◀️ ─ 106 107 114 124 141
 ├─ ▶️ ─ 109 111 124 124 132
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 ├─┬─ 📆 0 ⏱  ──── 💰 g8-1192
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>1111110001 💰 <span style="color:rgb(170,223,31)">g:432</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0000001001 💰 <span style="color:rgb(223,201,31)">g:662</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>1100011111 💰 <span style="color:rgb(200,223,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0001100010 💰 <span style="color:rgb(185,223,31)">g:478</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0000101110 💰 <span style="color:rgb(97,223,31)">g:204</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0010101110 💰 <span style="color:rgb(36,223,31)">g:14</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>1111011010 💰 <span style="color:rgb(171,223,31)">g:434</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0000000000 💰 <span style="color:rgb(223,31,31)">g:1192</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1110101111 💰 <span style="color:rgb(223,182,31)">g:722</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0001100001 💰 <span style="color:rgb(179,223,31)">g:460</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0111100100 💰 <span style="color:rgb(51,223,31)">g:62</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1110101101 💰 <span style="color:rgb(178,223,31)">g:458</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>1000100101 💰 <span style="color:rgb(103,223,31)">g:222</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0100001010 💰 <span style="color:rgb(181,223,31)">g:466</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0010010000 💰 <span style="color:rgb(223,181,31)">g:726</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1100100101 💰 <span style="color:rgb(34,223,31)">g:8</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0011010101 💰 <span style="color:rgb(40,223,31)">g:26</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>0010101010 💰 <span style="color:rgb(106,223,31)">g:234</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0010101110 💰 <span style="color:rgb(36,223,31)">g:14</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1101010111 💰 <span style="color:rgb(191,223,31)">g:498</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   7│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   8│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   7│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   7│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   7│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   7│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   7│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   8│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  54</span>│<span style="background-color:rgb(101,61,0)">  33</span>│<span style="background-color:rgb(101,91,0)">  36</span>│<span style="background-color:rgb(81,101,0)">  41</span>│<span style="background-color:rgb(51,101,0)">  62</span>│<span style="background-color:rgb(20,101,0)">  70</span>│<span style="background-color:rgb(0,101,10)">  51</span>│<span style="background-color:rgb(0,101,40)">  25</span>│<span style="background-color:rgb(0,101,71)">  30</span>│<span style="background-color:rgb(0,101,101)">  46</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  64</span>│<span style="background-color:rgb(0,40,101)">  49</span>│<span style="background-color:rgb(0,10,101)">  59</span>│<span style="background-color:rgb(20,0,101)">  43</span>│<span style="background-color:rgb(51,0,101)">  28</span>│<span style="background-color:rgb(81,0,101)">  75</span>│<span style="background-color:rgb(101,0,91)">  67</span>│<span style="background-color:rgb(101,0,61)">  57</span>│<span style="background-color:rgb(101,0,30)">  72</span>│<span style="background-color:rgb(101,0,0)">  38</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   2</span>│<span style="background-color:rgb(0,40,101)">   0</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   0</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   2</span>│<span style="background-color:rgb(101,0,0)">   0</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│
 │ │ │   10│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,201,31)"> 662</span>⇄<span style="color:rgb(181,223,31)"> 466</span>│<span style="color:rgb(200,223,31)"> 524</span>⇄<span style="color:rgb(103,223,31)"> 222</span>│<span style="color:rgb(106,223,31)"> 234</span>⇄<span style="color:rgb(103,223,31)"> 222</span>│<span style="color:rgb(51,223,31)">  62</span>⇄<span style="color:rgb(36,223,31)">  14</span>│<span style="color:rgb(223,31,31)">1192</span>⇄<span style="color:rgb(179,223,31)"> 460</span>│
 │ │ │   10│<span style="color:rgb(185,223,31)"> 478</span>⇄<span style="color:rgb(171,223,31)"> 434</span>│<span style="color:rgb(34,223,31)">   8</span>⇄<span style="color:rgb(97,223,31)"> 204</span>│<span style="color:rgb(40,223,31)">  26</span>⇄<span style="color:rgb(34,223,31)">   8</span>│<span style="color:rgb(36,223,31)">  14</span>⇄<span style="color:rgb(51,223,31)">  62</span>│<span style="color:rgb(36,223,31)">  14</span>⇄<span style="color:rgb(170,223,31)"> 432</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 13 ───── 📈 4 🟰 6 📉 10
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,201,31)"> 662</span>⇄<span style="color:rgb(42,223,31)">  32</span>│<span style="color:rgb(51,223,31)">  62</span>⇄<span style="color:rgb(112,223,31)"> 250</span>│<span style="color:rgb(176,223,31)"> 452</span>⇄<span style="color:rgb(94,223,31)"> 196</span>│<span style="color:rgb(171,223,31)"> 434</span>⇄<span style="color:rgb(40,223,31)">  26</span>│<span style="color:rgb(117,223,31)"> 266</span>⇄<span style="color:rgb(223,189,31)"> 700</span>│
 │ │ │   10│<span style="color:rgb(223,176,31)"> 742</span>⇄<span style="color:rgb(223,190,31)"> 698</span>│<span style="color:rgb(131,223,31)"> 310</span>⇄<span style="color:rgb(105,223,31)"> 228</span>│<span style="color:rgb(36,223,31)">  14</span>⇄<span style="color:rgb(101,223,31)"> 216</span>│<span style="color:rgb(120,223,31)"> 276</span>⇄<span style="color:rgb(107,223,31)"> 236</span>│<span style="color:rgb(107,223,31)"> 236</span>⇄<span style="color:rgb(223,180,31)"> 730</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  14✖ →🆕 ───── 
 │ │ ├───── 👑  Elite 16→15 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 1 ⏱  ──── 💰 g8-944
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>1111101110 💰 <span style="color:rgb(223,146,31)">g:662</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0010110101 💰 <span style="color:rgb(44,223,31)">g:32</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0111100100 💰 <span style="color:rgb(56,223,31)">g:62</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0010101100 💰 <span style="color:rgb(133,223,31)">g:250</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>1111010101 💰 <span style="color:rgb(215,223,31)">g:452</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0010010101 💰 <span style="color:rgb(111,223,31)">g:196</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0000100101 💰 <span style="color:rgb(207,223,31)">g:434</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>1100100110 💰 <span style="color:rgb(42,223,31)">g:26</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1001100010 💰 <span style="color:rgb(139,223,31)">g:266</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0000100010 💰 <span style="color:rgb(223,130,31)">g:700</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0001100000 💰 <span style="color:rgb(223,113,31)">g:742</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1000000001 💰 <span style="color:rgb(223,131,31)">g:698</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0111100000 💰 <span style="color:rgb(157,223,31)">g:310</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0010101110 💰 <span style="color:rgb(37,223,31)">g:14</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1100100101 💰 <span style="color:rgb(35,223,31)">g:8</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1100010111 💰 <span style="color:rgb(143,223,31)">g:276</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1100010001 💰 <span style="color:rgb(127,223,31)">g:236</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1100001001 💰 <span style="color:rgb(127,223,31)">g:236</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0100001000 💰 <span style="color:rgb(223,118,31)">g:730</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1111111011 💰 <span style="color:rgb(223,31,31)">g:944</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   7│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   3│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   2│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   5│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   2│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   7│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  38</span>│<span style="background-color:rgb(101,61,0)">  67</span>│<span style="background-color:rgb(101,91,0)">  64</span>│<span style="background-color:rgb(81,101,0)">  54</span>│<span style="background-color:rgb(51,101,0)">  41</span>│<span style="background-color:rgb(20,101,0)">  62</span>│<span style="background-color:rgb(0,101,10)">  43</span>│<span style="background-color:rgb(0,101,40)">  70</span>│<span style="background-color:rgb(0,101,71)">  51</span>│<span style="background-color:rgb(0,101,101)">  33</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  28</span>│<span style="background-color:rgb(0,40,101)">  36</span>│<span style="background-color:rgb(0,10,101)">  46</span>│<span style="background-color:rgb(20,0,101)">  72</span>│<span style="background-color:rgb(51,0,101)">  75</span>│<span style="background-color:rgb(81,0,101)">  49</span>│<span style="background-color:rgb(101,0,91)">  59</span>│<span style="background-color:rgb(101,0,61)">  57</span>│<span style="background-color:rgb(101,0,30)">  30</span>│<span style="background-color:rgb(101,0,0)">  25</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   2</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   0</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   0</span>│<span style="background-color:rgb(20,0,101)">   2</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   2</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   0</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(20,0,101)">  14</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│
 │ │ │   10│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│
 │ 🏆  ⏱  💰 g:6
─┴───────────────────
 ┌─ 📦1192 → ◀️593 = ▶️599 ──────────────────────────────────────────────
 ├─ ◀️ ─ 106 107 124 124 132
 ├─ ▶️ ─ 109 111 114 124 141
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ 🏆  ⏱  💰 g:2
─┴───────────────────
 ┌─ 📦1192 → ◀️595 = ▶️597 ──────────────────────────────────────────────
 ├─ ◀️ ─ 107 109 114 124 141
 ├─ ▶️ ─ 106 111 124 124 132
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,31,31)"> 944</span>⇄<span style="color:rgb(223,131,31)"> 698</span>│<span style="color:rgb(143,223,31)"> 276</span>⇄<span style="color:rgb(127,223,31)"> 236</span>│<span style="color:rgb(133,223,31)"> 250</span>⇄<span style="color:rgb(215,223,31)"> 452</span>│<span style="color:rgb(127,223,31)"> 236</span>⇄<span style="color:rgb(42,223,31)">  26</span>│<span style="color:rgb(37,223,31)">  14</span>⇄<span style="color:rgb(223,113,31)"> 742</span>│
 │ │ │   10│<span style="color:rgb(111,223,31)"> 196</span>⇄<span style="color:rgb(139,223,31)"> 266</span>│<span style="color:rgb(44,223,31)">  32</span>⇄<span style="color:rgb(37,223,31)">  14</span>│<span style="color:rgb(56,223,31)">  62</span>⇄<span style="color:rgb(207,223,31)"> 434</span>│<span style="color:rgb(42,223,31)">  26</span>⇄<span style="color:rgb(35,223,31)">   8</span>│<span style="color:rgb(127,223,31)"> 236</span>⇄<span style="color:rgb(223,146,31)"> 662</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 10 ───── 📈 9 🟰 6 📉 5
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(127,223,31)"> 236</span>⇄<span style="color:rgb(34,223,31)">   6</span>│<span style="color:rgb(135,223,31)"> 256</span>⇄<span style="color:rgb(127,223,31)"> 236</span>│<span style="color:rgb(92,223,31)"> 150</span>⇄<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(131,223,31)"> 246</span>⇄<span style="color:rgb(37,223,31)">  14</span>│<span style="color:rgb(46,223,31)">  36</span>⇄<span style="color:rgb(219,223,31)"> 462</span>│
 │ │ │   10│<span style="color:rgb(37,223,31)">  14</span>⇄<span style="color:rgb(126,223,31)"> 234</span>│<span style="color:rgb(213,223,31)"> 448</span>⇄<span style="color:rgb(141,223,31)"> 270</span>│<span style="color:rgb(193,223,31)"> 398</span>⇄<span style="color:rgb(44,223,31)">  32</span>│<span style="color:rgb(127,223,31)"> 236</span>⇄<span style="color:rgb(213,223,31)"> 448</span>│<span style="color:rgb(56,223,31)">  62</span>⇄<span style="color:rgb(49,223,31)">  44</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  8✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ─────  🧹 17
 ├─┬─ 📆 2 ⏱  ──── 💰 g2-710
 ├─┬─ 📆 3 ⏱  ──── 💰 g2-910
 ├─┬─ 📆 4 ⏱  ──── 💰 g2-732
 ├─┬─ 📆 5 ⏱ 1ms  ──── 💰 g2-532
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0100111101 💰 <span style="color:rgb(223,215,31)">g:276</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0000101110 💰 <span style="color:rgb(178,223,31)">g:204</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0110100101 💰 <span style="color:rgb(33,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0110011001 💰 <span style="color:rgb(44,223,31)">g:18</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0111100111 💰 <span style="color:rgb(223,66,31)">g:484</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0001100101 💰 <span style="color:rgb(184,223,31)">g:212</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0110010001 💰 <span style="color:rgb(197,223,31)">g:230</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0011100101 💰 <span style="color:rgb(36,223,31)">g:6</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0100000101 💰 <span style="color:rgb(223,92,31)">g:448</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0101110111 💰 <span style="color:rgb(223,44,31)">g:514</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0110100000 💰 <span style="color:rgb(223,31,31)">g:532</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1000100001 💰 <span style="color:rgb(223,76,31)">g:470</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>1100110110 💰 <span style="color:rgb(191,223,31)">g:222</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0001001011 💰 <span style="color:rgb(158,223,31)">g:176</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0111101110 💰 <span style="color:rgb(223,90,31)">g:450</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1100101111 💰 <span style="color:rgb(223,52,31)">g:504</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0011011010 💰 <span style="color:rgb(37,223,31)">g:8</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1011010111 💰 <span style="color:rgb(223,53,31)">g:502</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1011000101 💰 <span style="color:rgb(39,223,31)">g:10</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0101000001 💰 <span style="color:rgb(223,73,31)">g:474</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   4│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   5│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   4│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   8│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  49</span>│<span style="background-color:rgb(101,61,0)">  59</span>│<span style="background-color:rgb(101,91,0)">  75</span>│<span style="background-color:rgb(81,101,0)">  64</span>│<span style="background-color:rgb(51,101,0)">  36</span>│<span style="background-color:rgb(20,101,0)">  57</span>│<span style="background-color:rgb(0,101,10)">  51</span>│<span style="background-color:rgb(0,101,40)">  72</span>│<span style="background-color:rgb(0,101,71)">  46</span>│<span style="background-color:rgb(0,101,101)">  28</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  25</span>│<span style="background-color:rgb(0,40,101)">  41</span>│<span style="background-color:rgb(0,10,101)">  54</span>│<span style="background-color:rgb(20,0,101)">  62</span>│<span style="background-color:rgb(51,0,101)">  43</span>│<span style="background-color:rgb(81,0,101)">  30</span>│<span style="background-color:rgb(101,0,91)">  70</span>│<span style="background-color:rgb(101,0,61)">  33</span>│<span style="background-color:rgb(101,0,30)">  67</span>│<span style="background-color:rgb(101,0,0)">  38</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   0</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│
 │ │ │   10│<span style="background-color:rgb(101,0,30)">  19</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(20,101,0)">   6</span>⇄<span style="background-color:rgb(51,0,101)">  15</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(0,101,71)">   9</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,137,31)"> 504</span>⇄<span style="color:rgb(223,148,31)"> 484</span>│<span style="color:rgb(153,223,31)"> 222</span>⇄<span style="color:rgb(223,131,31)"> 514</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(223,156,31)"> 470</span>│<span style="color:rgb(223,153,31)"> 474</span>⇄<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(35,223,31)">   6</span>⇄<span style="color:rgb(41,223,31)">  18</span>│
 │ │ │   10│<span style="color:rgb(37,223,31)">  10</span>⇄<span style="color:rgb(128,223,31)"> 176</span>│<span style="color:rgb(148,223,31)"> 212</span>⇄<span style="color:rgb(223,167,31)"> 450</span>│<span style="color:rgb(143,223,31)"> 204</span>⇄<span style="color:rgb(36,223,31)">   8</span>│<span style="color:rgb(183,223,31)"> 276</span>⇄<span style="color:rgb(223,168,31)"> 448</span>│<span style="color:rgb(158,223,31)"> 230</span>⇄<span style="color:rgb(223,138,31)"> 502</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 10 ───── 📈 5 🟰 9 📉 6
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(192,223,31)"> 292</span>⇄<span style="color:rgb(191,223,31)"> 290</span>│<span style="color:rgb(141,223,31)"> 200</span>⇄<span style="color:rgb(183,223,31)"> 276</span>│<span style="color:rgb(147,223,31)"> 210</span>⇄<span style="color:rgb(143,223,31)"> 204</span>│<span style="color:rgb(51,223,31)">  36</span>⇄<span style="color:rgb(167,223,31)"> 246</span>│<span style="color:rgb(157,223,31)"> 228</span>⇄<span style="color:rgb(167,223,31)"> 246</span>│
 │ │ │   10│<span style="color:rgb(152,223,31)"> 220</span>⇄<span style="color:rgb(41,223,31)">  18</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(156,223,31)"> 226</span>│<span style="color:rgb(153,223,31)"> 222</span>⇄<span style="color:rgb(52,223,31)">  38</span>│<span style="color:rgb(159,223,31)"> 232</span>⇄<span style="color:rgb(223,137,31)"> 504</span>│<span style="color:rgb(192,223,31)"> 292</span>⇄<span style="color:rgb(223,31,31)"> 696</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  9✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 6 ⏱ 1ms  ──── 💰 g2-696
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>1011010000 💰 <span style="color:rgb(192,223,31)">g:292</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0011010111 💰 <span style="color:rgb(191,223,31)">g:290</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0100001101 💰 <span style="color:rgb(141,223,31)">g:200</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0100111101 💰 <span style="color:rgb(183,223,31)">g:276</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0001001110 💰 <span style="color:rgb(147,223,31)">g:210</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0000111010 💰 <span style="color:rgb(143,223,31)">g:204</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0001101101 💰 <span style="color:rgb(51,223,31)">g:36</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0001101100 💰 <span style="color:rgb(167,223,31)">g:246</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1001001010 💰 <span style="color:rgb(167,223,31)">g:246</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0111100101 💰 <span style="color:rgb(152,223,31)">g:220</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0110011001 💰 <span style="color:rgb(41,223,31)">g:18</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>0110100101 💰 <span style="color:rgb(32,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0101000101 💰 <span style="color:rgb(156,223,31)">g:226</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1000100101 💰 <span style="color:rgb(153,223,31)">g:222</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1110100001 💰 <span style="color:rgb(52,223,31)">g:38</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>0101110110 💰 <span style="color:rgb(159,223,31)">g:232</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>1100110111 💰 <span style="color:rgb(223,137,31)">g:504</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>0100101111 💰 <span style="color:rgb(192,223,31)">g:292</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1111100111 💰 <span style="color:rgb(223,31,31)">g:696</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0001111001 💰 <span style="color:rgb(51,223,31)">g:36</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   4│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   2│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   4│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   8│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   4│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   4│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   7│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   7│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  30</span>│<span style="background-color:rgb(101,61,0)">  36</span>│<span style="background-color:rgb(101,91,0)">  62</span>│<span style="background-color:rgb(81,101,0)">  38</span>│<span style="background-color:rgb(51,101,0)">  57</span>│<span style="background-color:rgb(20,101,0)">  59</span>│<span style="background-color:rgb(0,101,10)">  67</span>│<span style="background-color:rgb(0,101,40)">  41</span>│<span style="background-color:rgb(0,101,71)">  43</span>│<span style="background-color:rgb(0,101,101)">  54</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  72</span>│<span style="background-color:rgb(0,40,101)">  75</span>│<span style="background-color:rgb(0,10,101)">  49</span>│<span style="background-color:rgb(20,0,101)">  51</span>│<span style="background-color:rgb(51,0,101)">  64</span>│<span style="background-color:rgb(81,0,101)">  46</span>│<span style="background-color:rgb(101,0,91)">  28</span>│<span style="background-color:rgb(101,0,61)">  33</span>│<span style="background-color:rgb(101,0,30)">  25</span>│<span style="background-color:rgb(101,0,0)">  70</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   2</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   0</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   4</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(159,223,31)"> 232</span>⇄<span style="color:rgb(223,31,31)"> 696</span>│<span style="color:rgb(41,223,31)">  18</span>⇄<span style="color:rgb(153,223,31)"> 222</span>│<span style="color:rgb(156,223,31)"> 226</span>⇄<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(223,137,31)"> 504</span>│<span style="color:rgb(152,223,31)"> 220</span>⇄<span style="color:rgb(147,223,31)"> 210</span>│
 │ │ │   10│<span style="color:rgb(167,223,31)"> 246</span>⇄<span style="color:rgb(167,223,31)"> 246</span>│<span style="color:rgb(51,223,31)">  36</span>⇄<span style="color:rgb(143,223,31)"> 204</span>│<span style="color:rgb(52,223,31)">  38</span>⇄<span style="color:rgb(191,223,31)"> 290</span>│<span style="color:rgb(183,223,31)"> 276</span>⇄<span style="color:rgb(51,223,31)">  36</span>│<span style="color:rgb(141,223,31)"> 200</span>⇄<span style="color:rgb(192,223,31)"> 292</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 11 ───── 📈 6 🟰 6 📉 8
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(37,223,31)">  10</span>⇄<span style="color:rgb(151,223,31)"> 218</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(171,223,31)"> 254</span>│<span style="color:rgb(223,159,31)"> 464</span>⇄<span style="color:rgb(223,153,31)"> 474</span>│<span style="color:rgb(134,223,31)"> 186</span>⇄<span style="color:rgb(158,223,31)"> 230</span>│<span style="color:rgb(223,165,31)"> 452</span>⇄<span style="color:rgb(167,223,31)"> 246</span>│
 │ │ │   10│<span style="color:rgb(148,223,31)"> 212</span>⇄<span style="color:rgb(36,223,31)">   8</span>│<span style="color:rgb(147,223,31)"> 210</span>⇄<span style="color:rgb(58,223,31)">  48</span>│<span style="color:rgb(169,223,31)"> 250</span>⇄<span style="color:rgb(152,223,31)"> 220</span>│<span style="color:rgb(142,223,31)"> 202</span>⇄<span style="color:rgb(32,223,31)">   2</span>│<span style="color:rgb(223,186,31)"> 414</span>⇄<span style="color:rgb(223,131,31)"> 514</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  6✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 7 ⏱ 1ms  ──── 💰 g2-514
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>1011000101 💰 <span style="color:rgb(39,223,31)">g:10</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0100001110 💰 <span style="color:rgb(194,223,31)">g:218</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0001111100 💰 <span style="color:rgb(33,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0100111000 💰 <span style="color:rgb(220,223,31)">g:254</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0010100001 💰 <span style="color:rgb(223,69,31)">g:464</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0000101101 💰 <span style="color:rgb(170,223,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0001101010 💰 <span style="color:rgb(203,223,31)">g:230</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0000101010 💰 <span style="color:rgb(223,78,31)">g:452</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1001001010 💰 <span style="color:rgb(214,223,31)">g:246</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0001100101 💰 <span style="color:rgb(189,223,31)">g:212</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0011001110 💰 <span style="color:rgb(37,223,31)">g:8</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>1110100101 💰 <span style="color:rgb(188,223,31)">g:210</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0010100111 💰 <span style="color:rgb(67,223,31)">g:48</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>0110100001 💰 <span style="color:rgb(217,223,31)">g:250</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0100100101 💰 <span style="color:rgb(195,223,31)">g:220</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>1000011001 💰 <span style="color:rgb(182,223,31)">g:202</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0110100101 💰 <span style="color:rgb(33,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1111100110 💰 <span style="color:rgb(223,106,31)">g:414</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0101110111 💰 <span style="color:rgb(223,31,31)">g:514</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>1001101100 💰 <span style="color:rgb(57,223,31)">g:34</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   7│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   3│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   3│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   6│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   7│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   3│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   6│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   6│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  67</span>│<span style="background-color:rgb(101,61,0)">  49</span>│<span style="background-color:rgb(101,91,0)">  72</span>│<span style="background-color:rgb(81,101,0)">  36</span>│<span style="background-color:rgb(51,101,0)">  28</span>│<span style="background-color:rgb(20,101,0)">  59</span>│<span style="background-color:rgb(0,101,10)">  43</span>│<span style="background-color:rgb(0,101,40)">  30</span>│<span style="background-color:rgb(0,101,71)">  41</span>│<span style="background-color:rgb(0,101,101)">  51</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  70</span>│<span style="background-color:rgb(0,40,101)">  54</span>│<span style="background-color:rgb(0,10,101)">  62</span>│<span style="background-color:rgb(20,0,101)">  38</span>│<span style="background-color:rgb(51,0,101)">  46</span>│<span style="background-color:rgb(81,0,101)">  57</span>│<span style="background-color:rgb(101,0,91)">  75</span>│<span style="background-color:rgb(101,0,61)">  33</span>│<span style="background-color:rgb(101,0,30)">  25</span>│<span style="background-color:rgb(101,0,0)">  64</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   2</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   0</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   2</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   1</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   1</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,91,0)">   3</span>⇄<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(20,0,101)">  14</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(51,0,101)">  15</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(101,0,91)">  17</span>│
 │ │ │   10│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(0,101,10)">   7</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(33,223,31)">   2</span>⇄<span style="color:rgb(37,223,31)">  10</span>│<span style="color:rgb(58,223,31)">  48</span>⇄<span style="color:rgb(36,223,31)">   8</span>│<span style="color:rgb(172,223,31)"> 250</span>⇄<span style="color:rgb(51,223,31)">  34</span>│<span style="color:rgb(155,223,31)"> 220</span>⇄<span style="color:rgb(223,125,31)"> 514</span>│<span style="color:rgb(145,223,31)"> 202</span>⇄<span style="color:rgb(33,223,31)">   2</span>│
 │ │ │   10│<span style="color:rgb(223,160,31)"> 452</span>⇄<span style="color:rgb(223,181,31)"> 414</span>│<span style="color:rgb(161,223,31)"> 230</span>⇄<span style="color:rgb(136,223,31)"> 186</span>│<span style="color:rgb(154,223,31)"> 218</span>⇄<span style="color:rgb(151,223,31)"> 212</span>│<span style="color:rgb(36,223,31)">   8</span>⇄<span style="color:rgb(223,153,31)"> 464</span>│<span style="color:rgb(149,223,31)"> 210</span>⇄<span style="color:rgb(33,223,31)">   2</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 15 ───── 📈 3 🟰 5 📉 12
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,106,31)"> 548</span>⇄<span style="color:rgb(142,223,31)"> 196</span>│<span style="color:rgb(223,143,31)"> 482</span>⇄<span style="color:rgb(223,131,31)"> 502</span>│<span style="color:rgb(223,31,31)"> 680</span>⇄<span style="color:rgb(155,223,31)"> 220</span>│<span style="color:rgb(223,151,31)"> 468</span>⇄<span style="color:rgb(136,223,31)"> 186</span>│<span style="color:rgb(136,223,31)"> 186</span>⇄<span style="color:rgb(178,223,31)"> 260</span>│
 │ │ │   10│<span style="color:rgb(42,223,31)">  18</span>⇄<span style="color:rgb(223,142,31)"> 484</span>│<span style="color:rgb(172,223,31)"> 250</span>⇄<span style="color:rgb(37,223,31)">  10</span>│<span style="color:rgb(180,223,31)"> 264</span>⇄<span style="color:rgb(191,223,31)"> 284</span>│<span style="color:rgb(183,223,31)"> 270</span>⇄<span style="color:rgb(175,223,31)"> 256</span>│<span style="color:rgb(223,141,31)"> 486</span>⇄<span style="color:rgb(223,136,31)"> 494</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  11✖ →🆕 ───── 
 │ │ ├───── 👑  Elite 17→11 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 8 ⏱ 1ms  ──── 💰 g2-680
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0001111111 💰 <span style="color:rgb(223,106,31)">g:548</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>1110011100 💰 <span style="color:rgb(142,223,31)">g:196</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0010100010 💰 <span style="color:rgb(223,143,31)">g:482</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>1011001111 💰 <span style="color:rgb(223,131,31)">g:502</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>0000001010 💰 <span style="color:rgb(223,31,31)">g:680</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0100100101 💰 <span style="color:rgb(155,223,31)">g:220</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0000101100 💰 <span style="color:rgb(223,151,31)">g:468</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0000101101 💰 <span style="color:rgb(136,223,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>1111001010 💰 <span style="color:rgb(136,223,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0011100010 💰 <span style="color:rgb(178,223,31)">g:260</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0110100101 💰 <span style="color:rgb(33,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>0101110101 💰 <span style="color:rgb(172,223,31)">g:250</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0100110110 💰 <span style="color:rgb(37,223,31)">g:10</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1001101011 💰 <span style="color:rgb(180,223,31)">g:264</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>0110100100 💰 <span style="color:rgb(191,223,31)">g:284</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>0011100111 💰 <span style="color:rgb(183,223,31)">g:270</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0011011110 💰 <span style="color:rgb(175,223,31)">g:256</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>1011011101 💰 <span style="color:rgb(223,141,31)">g:486</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>0001100100 💰 <span style="color:rgb(223,136,31)">g:494</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0010110100 💰 <span style="color:rgb(172,223,31)">g:250</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   7│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   6│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   6│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   1│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   4│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   3│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   7│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   3│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   3│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  28</span>│<span style="background-color:rgb(101,61,0)">  64</span>│<span style="background-color:rgb(101,91,0)">  38</span>│<span style="background-color:rgb(81,101,0)">  30</span>│<span style="background-color:rgb(51,101,0)">  25</span>│<span style="background-color:rgb(20,101,0)">  62</span>│<span style="background-color:rgb(0,101,10)">  41</span>│<span style="background-color:rgb(0,101,40)">  67</span>│<span style="background-color:rgb(0,101,71)">  70</span>│<span style="background-color:rgb(0,101,101)">  51</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  75</span>│<span style="background-color:rgb(0,40,101)">  59</span>│<span style="background-color:rgb(0,10,101)">  72</span>│<span style="background-color:rgb(20,0,101)">  49</span>│<span style="background-color:rgb(51,0,101)">  43</span>│<span style="background-color:rgb(81,0,101)">  46</span>│<span style="background-color:rgb(101,0,91)">  54</span>│<span style="background-color:rgb(101,0,61)">  36</span>│<span style="background-color:rgb(101,0,30)">  33</span>│<span style="background-color:rgb(101,0,0)">  57</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   0</span>│<span style="background-color:rgb(101,61,0)">   2</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   0</span>│<span style="background-color:rgb(51,101,0)">   1</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   2</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   2</span>│<span style="background-color:rgb(20,0,101)">   1</span>│<span style="background-color:rgb(51,0,101)">   0</span>│<span style="background-color:rgb(81,0,101)">   1</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   1</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(20,0,101)">  14</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│<span style="background-color:rgb(0,10,101)">  13</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  11</span>⇄<span style="background-color:rgb(0,101,40)">   8</span>│<span style="background-color:rgb(101,0,0)">  20</span>⇄<span style="background-color:rgb(101,0,30)">  19</span>│<span style="background-color:rgb(0,101,101)">  10</span>⇄<span style="background-color:rgb(101,0,61)">  18</span>│<span style="background-color:rgb(81,0,101)">  16</span>⇄<span style="background-color:rgb(0,10,101)">  13</span>│<span style="background-color:rgb(0,40,101)">  12</span>⇄<span style="background-color:rgb(51,101,0)">   5</span>│
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(136,223,31)"> 186</span>⇄<span style="color:rgb(33,223,31)">   2</span>│<span style="color:rgb(175,223,31)"> 256</span>⇄<span style="color:rgb(155,223,31)"> 220</span>│<span style="color:rgb(142,223,31)"> 196</span>⇄<span style="color:rgb(180,223,31)"> 264</span>│<span style="color:rgb(142,223,31)"> 196</span>⇄<span style="color:rgb(223,151,31)"> 468</span>│<span style="color:rgb(37,223,31)">  10</span>⇄<span style="color:rgb(223,143,31)"> 482</span>│
 │ │ │   10│<span style="color:rgb(33,223,31)">   2</span>⇄<span style="color:rgb(136,223,31)"> 186</span>│<span style="color:rgb(172,223,31)"> 250</span>⇄<span style="color:rgb(223,136,31)"> 494</span>│<span style="color:rgb(178,223,31)"> 260</span>⇄<span style="color:rgb(223,141,31)"> 486</span>│<span style="color:rgb(183,223,31)"> 270</span>⇄<span style="color:rgb(37,223,31)">  10</span>│<span style="color:rgb(172,223,31)"> 250</span>⇄<span style="color:rgb(223,31,31)"> 680</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 9 ───── 📈 5 🟰 10 📉 5
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,164,31)"> 444</span>⇄<span style="color:rgb(162,223,31)"> 232</span>│<span style="color:rgb(47,223,31)">  28</span>⇄<span style="color:rgb(37,223,31)">  10</span>│<span style="color:rgb(33,223,31)">   2</span>⇄<span style="color:rgb(47,223,31)">  28</span>│<span style="color:rgb(172,223,31)"> 250</span>⇄<span style="color:rgb(170,223,31)"> 246</span>│<span style="color:rgb(223,170,31)"> 434</span>⇄<span style="color:rgb(136,223,31)"> 186</span>│
 │ │ │   10│<span style="color:rgb(164,223,31)"> 236</span>⇄<span style="color:rgb(223,141,31)"> 486</span>│<span style="color:rgb(223,162,31)"> 448</span>⇄<span style="color:rgb(223,151,31)"> 468</span>│<span style="color:rgb(51,223,31)">  34</span>⇄<span style="color:rgb(223,119,31)"> 524</span>│<span style="color:rgb(48,223,31)">  30</span>⇄<span style="color:rgb(155,223,31)"> 220</span>│<span style="color:rgb(182,223,31)"> 268</span>⇄<span style="color:rgb(223,151,31)"> 468</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE ⚔️  Sobrevivência ───── 
 │ │ ├───── ⏳  Idade ───── 
 │ │ ├───── 🚶‍♂️🌍 Imigrantes  14✖ →🆕 ───── 
 │ │ └──────────────────────────────────── 
 │ └───── FASE 🌈  Diversidade - limpeza ───── 
 ├─┬─ 📆 9 ⏱ 1ms  ──── 💰 g2-524
 │ ├───── 🧍🧑‍🤝‍🧑🚶‍ ───── 
 │ │ 🧍 <span style="background-color:rgb(101,30,0)">1   </span>0010000101 💰 <span style="color:rgb(223,90,31)">g:444</span>
 │ │ 🧍 <span style="background-color:rgb(101,61,0)">2   </span>0101111010 💰 <span style="color:rgb(201,223,31)">g:232</span>
 │ │ 🧍 <span style="background-color:rgb(101,91,0)">3   </span>0100110101 💰 <span style="color:rgb(52,223,31)">g:28</span>
 │ │ 🧍 <span style="background-color:rgb(81,101,0)">4   </span>0100110110 💰 <span style="color:rgb(39,223,31)">g:10</span>
 │ │ 🧍 <span style="background-color:rgb(51,101,0)">5   </span>1010011010 💰 <span style="color:rgb(33,223,31)">g:2</span>
 │ │ 🧍 <span style="background-color:rgb(20,101,0)">6   </span>0111100001 💰 <span style="color:rgb(52,223,31)">g:28</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,10)">7   </span>0010110100 💰 <span style="color:rgb(214,223,31)">g:250</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,40)">8   </span>0001110100 💰 <span style="color:rgb(211,223,31)">g:246</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,71)">9   </span>0000100101 💰 <span style="color:rgb(223,97,31)">g:434</span>
 │ │ 🧍 <span style="background-color:rgb(0,101,101)">10  </span>0000101101 💰 <span style="color:rgb(167,223,31)">g:186</span>
 │ │ 🧍 <span style="background-color:rgb(0,71,101)">11  </span>0011110110 💰 <span style="color:rgb(204,223,31)">g:236</span>
 │ │ 🧍 <span style="background-color:rgb(0,40,101)">12  </span>0100100010 💰 <span style="color:rgb(223,59,31)">g:486</span>
 │ │ 🧍 <span style="background-color:rgb(0,10,101)">13  </span>0000011100 💰 <span style="color:rgb(223,87,31)">g:448</span>
 │ │ 🧍 <span style="background-color:rgb(20,0,101)">14  </span>1001101100 💰 <span style="color:rgb(56,223,31)">g:34</span>
 │ │ 🧍 <span style="background-color:rgb(51,0,101)">15  </span>1100011111 💰 <span style="color:rgb(223,31,31)">g:524</span>
 │ │ 🧍 <span style="background-color:rgb(81,0,101)">16  </span>0100011110 💰 <span style="color:rgb(53,223,31)">g:30</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,91)">17  </span>0111100101 💰 <span style="color:rgb(192,223,31)">g:220</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,61)">18  </span>0110100010 💰 <span style="color:rgb(223,218,31)">g:268</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,30)">19  </span>1111000111 💰 <span style="color:rgb(223,72,31)">g:468</span>
 │ │ 🧍 <span style="background-color:rgb(101,0,0)">20  </span>0110000001 💰 <span style="color:rgb(223,65,31)">g:478</span>
 │ ├───── 📏  ───── 
 │ │ 🧍    🧍   📏  
 │ │ ────┼────┼────┼
 │ │ <span style="background-color:rgb(101,30,0)">1   </span>│<span style="background-color:rgb(101,61,0)">2   </span>│   9│
 │ │ <span style="background-color:rgb(101,91,0)">3   </span>│<span style="background-color:rgb(81,101,0)">4   </span>│   2│
 │ │ <span style="background-color:rgb(51,101,0)">5   </span>│<span style="background-color:rgb(20,101,0)">6   </span>│   8│
 │ │ <span style="background-color:rgb(0,101,10)">7   </span>│<span style="background-color:rgb(0,101,40)">8   </span>│   2│
 │ │ <span style="background-color:rgb(0,101,71)">9   </span>│<span style="background-color:rgb(0,101,101)">10  </span>│   1│
 │ │ <span style="background-color:rgb(0,71,101)">11  </span>│<span style="background-color:rgb(0,40,101)">12  </span>│   5│
 │ │ <span style="background-color:rgb(0,10,101)">13  </span>│<span style="background-color:rgb(20,0,101)">14  </span>│   4│
 │ │ <span style="background-color:rgb(51,0,101)">15  </span>│<span style="background-color:rgb(81,0,101)">16  </span>│   2│
 │ │ <span style="background-color:rgb(101,0,91)">17  </span>│<span style="background-color:rgb(101,0,61)">18  </span>│   4│
 │ │ <span style="background-color:rgb(101,0,30)">19  </span>│<span style="background-color:rgb(101,0,0)">20  </span>│   4│
 │ │ ────┴────┴────┴
 │ ├─┬─── FASE 🧩  Selecionar 20 🧑‍🤝‍🧑 pais ───── 
 │ │ ├───── Roleta, pressão 150 ───── 
 │ │ │ 100%    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">  38</span>│<span style="background-color:rgb(101,61,0)">  54</span>│<span style="background-color:rgb(101,91,0)">  70</span>│<span style="background-color:rgb(81,101,0)">  72</span>│<span style="background-color:rgb(51,101,0)">  75</span>│<span style="background-color:rgb(20,101,0)">  67</span>│<span style="background-color:rgb(0,101,10)">  46</span>│<span style="background-color:rgb(0,101,40)">  49</span>│<span style="background-color:rgb(0,101,71)">  41</span>│<span style="background-color:rgb(0,101,101)">  59</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">  51</span>│<span style="background-color:rgb(0,40,101)">  28</span>│<span style="background-color:rgb(0,10,101)">  36</span>│<span style="background-color:rgb(20,0,101)">  62</span>│<span style="background-color:rgb(51,0,101)">  25</span>│<span style="background-color:rgb(81,0,101)">  64</span>│<span style="background-color:rgb(101,0,91)">  57</span>│<span style="background-color:rgb(101,0,61)">  43</span>│<span style="background-color:rgb(101,0,30)">  33</span>│<span style="background-color:rgb(101,0,0)">  30</span>│
 │ │ ├───── Número de seleções ───── 
 │ │ │ #Pai    1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(101,30,0)">   1</span>│<span style="background-color:rgb(101,61,0)">   1</span>│<span style="background-color:rgb(101,91,0)">   1</span>│<span style="background-color:rgb(81,101,0)">   1</span>│<span style="background-color:rgb(51,101,0)">   2</span>│<span style="background-color:rgb(20,101,0)">   1</span>│<span style="background-color:rgb(0,101,10)">   1</span>│<span style="background-color:rgb(0,101,40)">   1</span>│<span style="background-color:rgb(0,101,71)">   1</span>│<span style="background-color:rgb(0,101,101)">   1</span>│
 │ │ │   10│<span style="background-color:rgb(0,71,101)">   1</span>│<span style="background-color:rgb(0,40,101)">   1</span>│<span style="background-color:rgb(0,10,101)">   0</span>│<span style="background-color:rgb(20,0,101)">   2</span>│<span style="background-color:rgb(51,0,101)">   0</span>│<span style="background-color:rgb(81,0,101)">   2</span>│<span style="background-color:rgb(101,0,91)">   1</span>│<span style="background-color:rgb(101,0,61)">   1</span>│<span style="background-color:rgb(101,0,30)">   0</span>│<span style="background-color:rgb(101,0,0)">   1</span>│
 │ │ └──────────────────────────────────── 
 │ ├─┬─── FASE 🧬  Reproduzir 20 pais ───── 
 │ │ ├───── Pais (🧑‍🤝‍🧑 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="background-color:rgb(0,101,71)">   9</span>⇄<span style="background-color:rgb(101,91,0)">   3</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(81,101,0)">   4</span>│<span style="background-color:rgb(51,101,0)">   5</span>⇄<span style="background-color:rgb(0,101,101)">  10</span>│<span style="background-color:rgb(101,30,0)">   1</span>⇄<span style="background-color:rgb(20,101,0)">   6</span>│<span style="background-color:rgb(101,0,91)">  17</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│
 │ │ │   10│<span style="background-color:rgb(20,0,101)">  14</span>⇄<span style="background-color:rgb(101,0,0)">  20</span>│<span style="background-color:rgb(101,61,0)">   2</span>⇄<span style="background-color:rgb(0,40,101)">  12</span>│<span style="background-color:rgb(101,0,61)">  18</span>⇄<span style="background-color:rgb(0,71,101)">  11</span>│<span style="background-color:rgb(20,0,101)">  14</span>⇄<span style="background-color:rgb(81,0,101)">  16</span>│<span style="background-color:rgb(0,101,40)">   8</span>⇄<span style="background-color:rgb(0,101,10)">   7</span>│
 │ 🏆  ⏱ 1ms  💰 g:0
─┴───────────────────
 ┌─ 📦1192 → ◀️596 = ▶️596 ──────────────────────────────────────────────
 ├─ ◀️ ─ 107 109 124 124 132
 ├─ ▶️ ─ 106 111 114 124 141
 └──────────────────────────────────────────────────────────────────────
─┬───────────────────
 │ │ ├───── Pais (💰 ) ───── 
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(214,223,31)"> 434</span>⇄<span style="color:rgb(43,223,31)">  28</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(36,223,31)">  10</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(110,223,31)"> 186</span>│<span style="color:rgb(218,223,31)"> 444</span>⇄<span style="color:rgb(43,223,31)">  28</span>│<span style="color:rgb(124,223,31)"> 220</span>⇄<span style="color:rgb(44,223,31)">  30</span>│
 │ │ │   10│<span style="color:rgb(46,223,31)">  34</span>⇄<span style="color:rgb(223,213,31)"> 478</span>│<span style="color:rgb(129,223,31)"> 232</span>⇄<span style="color:rgb(223,210,31)"> 486</span>│<span style="color:rgb(144,223,31)"> 268</span>⇄<span style="color:rgb(131,223,31)"> 236</span>│<span style="color:rgb(46,223,31)">  34</span>⇄<span style="color:rgb(44,223,31)">  30</span>│<span style="color:rgb(135,223,31)"> 246</span>⇄<span style="color:rgb(136,223,31)"> 250</span>│
 │ │ ├───── Filhos (💰 ) 🧬 10  🦠 12 ───── 📈 3 🟰 3 📉 14
 │ │ │ 🧍     1    2    3    4    5    6    7    8    9   10 
 │ │ │ ────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼
 │ │ │    0│<span style="color:rgb(223,213,31)"> 478</span>⇄<span style="color:rgb(136,223,31)"> 250</span>│<span style="color:rgb(43,223,31)">  28</span>⇄<span style="color:rgb(128,223,31)"> 230</span>│<span style="color:rgb(131,223,31)"> 236</span>⇄<span style="color:rgb(127,223,31)"> 228</span>│<span style="color:rgb(223,114,31)"> 714</span>⇄<span style="color:rgb(129,223,31)"> 232</span>│<span style="color:rgb(223,213,31)"> 478</span>⇄<span style="color:rgb(223,120,31)"> 698</span>│
 │ │ │   10│<span style="color:rgb(223,194,31)"> 524</span>⇄<span style="color:rgb(31,223,31)">   0</span>│<span style="color:rgb(43,223,31)">  28</span>⇄<span style="color:rgb(223,31,31)"> 910</span>│<span style="color:rgb(223,121,31)"> 696</span>⇄<span style="color:rgb(134,223,31)"> 244</span>│<span style="color:rgb(131,223,31)"> 238</span>⇄<span style="color:rgb(125,223,31)"> 222</span>│<span style="color:rgb(32,223,31)">   2</span>⇄<span style="color:rgb(154,223,31)"> 292</span>│
 │ │ └──────────────────────────────────── 
 ├─ Parâmetros ─ [90mP1=</span>1 [90mP2=</span>4 [90mP3=</span>1 [90mP4=</span>10 [90mP5=</span>1000000 [90mP6=</span>20 [90mP7=</span>100 [90mP8=</span>50 [90mP9=</span>1 [90mP10=</span>150 [90mP13=</span>1
 ├─ ⚙   ─ [90mP14=</span>100 [90mP16=</span>1 [90mP17=</span>1 [90mP18=</span>3 [90mP19=</span>0 [90mP20=</span>1 [90mP21=</span>0 [90mP22=</span>1
═╧═ 🏁  Execução terminada ⏱   1ms  ═══
Partição (Binária)
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ [90mP1(ALGORITMO):</span> Algoritmo Evolutivo | [90mP2(NIVEL_DEBUG):</span> COMPLETO | [90mP3(SEMENTE):</span> 1
│ [90mP4(LIMITE_TEMPO):</span> 10 | [90mP5(LIMITE_ITERACOES):</span> 1000000 | [90mP6(POPULACAO):</span> 20
│ [90mP7(PROB_CRUZAR):</span> 100 | [90mP8(PROB_MUTAR):</span> 50 | [90mP9(SELECAO):</span> Roleta | [90mP10(PRESSAO):</span> 150
│ [90mP13(SOBREVIVENCIA):</span> Idade | [90mP14(PERC_DESCENDENTES):</span> 100 | [90mP16(ELITISMO):</span> 1
│ [90mP17(IMIGRANTES):</span> 1 | [90mP18(DIVERSIDADE):</span> Limpeza | [90mP19(DIST_MINIMA):</span> 0
│ [90mP20(TIPO_CRUZAR):</span> 2-pontos | [90mP21(TIPO_MUTAR):</span> 0 | [90mP22(TIPO_VIZINHO):</span> 1
└──────────────────────────────────────────────────────────────────────
 ┌─ 📦1192 → ◀️596 = ▶️596 ──────────────────────────────────────────────
 ├─ ◀️ ─ 107 109 124 124 132
 ├─ ▶️ ─ 106 111 114 124 141
 └──────────────────────────────────────────────────────────────────────
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ [90mI1(Resultado):</span> 0 | [90mI2(Tempo(ms)):</span> 1 | [90mI3(Iterações):</span> 232 | [90mI4(Épocas):</span> 10 | 
│ [90mI5(Gerações):</span> 240
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly


Podemos ver que a solução não foi obtida da instância de custo 2, mas sim da instância de custo 478 com outrra de custo 250.
Esta observação é importante para que não seja dado demasiada importância ao melhor elemento, descartando os restantes.
É sempre importante ter diversidade na população, e permitir que elementos piores se reproduzam.

\anchor particao-cb4
## Ação 3 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

[Resultdos Deucalion](melhorativa__deucalion.html)




| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
