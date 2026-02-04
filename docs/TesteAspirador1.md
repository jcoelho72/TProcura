@page teste_aspirador1 💻 Teste Aspirador - Parte 1/2

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">💻 Parte 1</span>
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
    <a href="teste_puzzle8b.html" style="color:#9cf;">💻 Testar</a>
  </div>
</div>

\endhtmlonly



Execução de exemplo com base no problema do Aspirador.

No Visual Studio, selecione o projeto TProcuraConstrutiva, e execute.
No Linux na pasta `.../TProcura/Construtiva/Teste$` execute `make` seguido de `./bin/Release/TProcuraConstrutiva`

Pode acompanhar o teste excutando as ações localmente.

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.


## Sumário

- [Ação 1 - Trocar de instância](#aspirador-a1)
- [Ação 2 - Explorar os sucessores](#aspirador-a2)
- [Ação 3 - Ver a solução/caminho realizada manualmente](#aspirador-a3)
- [Ação 4 - Ver a alterar um parâmetro](#aspirador-a4)
- [Ação 5 - Efetuer uma procura em Largura](#aspirador-a5)
- [Ação 6 - Editar opções A](#aspirador-a6)
- [Ação 7 - Editar opções B](#aspirador-a7)
- [Ação 8 - Resolver outra instância](#aspirador-a8)
- [Ação 9 - Desafio Procura em Largura](#aspirador-a8)

\htmlonly
<pre>
┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
└──────────────────────────────┘
Opção: <span class="entrada">1</span>
</pre>
\endhtmlonly


![Aspirador - espaço de estados para 2 salas](docs/images/aspirador.png)

Selecione o problema do Aspirador: **1.**

A versão deste problema foi generalizada no código para poderem existir N salas, 
uma ou lado das outras, e não apenas 2 como no manual, sendo em tudo o resto igual.


\htmlonly
<pre>
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 │ [*] *  .  * 
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly


Esta é a informação apresentada no teste manual. 
Na zona superior aparece o nome do problema, seguido dos parametros e valores atuais.
Podemos ver que o primeiro parametro é o ALGORITMO, e está selecionado de omissão a Largura Primeiro.
Em termos de NIVEL_DEBUG está selecionado o valor NADA, ou seja, não é mostrada informação de debug.
Seguem-se outros parametros, os quais alguns serão apresentados ao longo desta execução.
Os nomes dos parametros e valores, são os mesmos utilizados no código,
e por esse motivo não é utilizada acentuação.

Temos o estado atual após a caixa dos parametros, que tem uma visualização dependente do problema.

Após o estado temos o menu, com as opções de inicializar numa nova instância, 
explorar o espaço de estados, editar os parâmetros atuais, ver a solução atual,
escolher os indicadors a calcular após execução, 
executar o algoritmo selecionado com os parametros atuais, editar configurações
e executar um teste empírico com as configurações atuais.

Tanto os parâmetros como o menu, repetem-se em cada interação.
Para evitar repetição na documentação, o output é cortado sempre que não existam ambiguidades.

\anchor aspirador-a1
## Ação 1 - Trocar de instância

Escreva os seguintes números separados por Enter: **1; 2**

Temos hipótese aqui de alterar o prefixo da instância,
útil para situações em que se lê os dados da instância de um ficheiro.
Este problema as instâncias são geradas aleatoriamente,
e não lidas de ficheiros, pelo que escolhemos apenas o ID da instância.

Tínhamos inicialmente uma instância com 4 salas, estando o aspirador na terceira sala, 
estando as duas primeiras sujas:

\htmlonly
<pre>
Opção: <span class="entrada">1</span>
┌─ 📄 Instância ───────────────────────────────────────────────────────
│ <span style="color:gray">ID atual:</span> 4  <span style="color:gray">Intervalo:</span> [2–50]  
│ <span style="color:gray">Prefixo atual:</span> 'instancia_' 
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): <span class="entrada">2</span>
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 * [*]
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly


Agora temos uma instância com 2 salas, estando ambas sujas, e o aspirador está na segunda:
A representação do estado é algo que é implementado na sub-classe 
(neste caso em CAspirador::Debug()), de modo a se poder visualizar o estado em que estamos. 
Ao chamar Inicializar() podemos trocar o ID da instância. 
Para este problema o ID é utilizado para definir a dimensão da instância, e assim podemos 
escolher em ter uma instância maior ou menor. 
A sujidade das casas é gerada aleatoriamente. 
No entanto a semente aleatória é um parâmetro (P3(SEMENTE): 1), sendo sempre a mesma caso não se altere, 
garantindo assim que podemos obter a mesma instância mais tarde.

\anchor aspirador-a2
## Ação 2 - Explorar os sucessores

A partir do estado atual, introduza: **2; 1; 2.**

\htmlonly
<pre>
Opção: <span class="entrada">2</span>
═╤═ 💰 g:0 🎯 h:3 ⚖  1|2 ═══
 │  * [*]
 │ └─ ⚡  ──── esq asp
🔍 Sucessor [1-2, ação(ões), exe]: <span class="entrada">1</span>
┌─ ✔  ───────────────
│ Ação executada.    
└────────────────────
═╤═ 💰 g:0 🎯 h:3 ⚖  2|4 ═══
 │ [*] * 
 │ └─ ⚡  ──── dir asp
🔍 Sucessor [1-2, ação(ões), exe]: <span class="entrada">2</span>
┌─ ✔  ───────────────
│ Ação executada.    
└────────────────────
═╤═ 💰 g:0 🎯 h:2 ⚖  3|6 ═══
 │ [.] * 
 │ └─ ⚡  ──── dir asp
🔍 Sucessor [1-2, ação(ões), exe]: 
</pre>
\endhtmlonly


Podemos ver que o estado atual tem dois sucessores, o aspirador pode ir para a sala da esquerda,
ou aspirar a sala atual. 
Escolhemos o primeiro estado, e depois escolhemos o segundo, aspirar. 
Os sucessores são visualizados pelas suas ações, existindo três possíveis ações: esq, dir, asp.
Para indicar o número do sucessor, é preciso ver, 
já que o número 1 é para a primeira ação válida, na lista de sucessores. 
No entanto, as ações são unívocas. Podemos indicar várias ações de uma só vez.

Neste momento estamos na sala da esquerda, com a sala limpa, mas a sala da direita está suja. 
Complete os movimentos necessários para limpar ambas as salas, e saia da exploração dos sucessores.
Utilize desta vez o nome das ações e não número, introduzido duas ações de uma vez. 
Introduza: **dir asp; *ENTER*.**
Note que "dir asp" podem ser introduzidas de uma vez.

\htmlonly
<pre>
🔍 Sucessor [1-2, ação(ões), exe]: <span class="entrada">dir asp</span>
┌─ ✔  ────────────────
│ Executadas 2 ações. 
└─────────────────────
═╤═ 💰 g:0 ⚖  6|12 ═══
 │  . [.]
 │ └─ ⚡  ──── esq asp
🔍 Sucessor [1-2, ação(ões), exe]: <span class="entrada">↵</span>
Aspirador
...
 │  . [.]
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly


Ao receber as duas ações, estas foram executadas e indicado o número de ações executados com sucesso.
Se fosse uma solução completa, todas as ações até ao estado final,
esta operação seria uma verificação da solução.
Caso exista alguma ação inválida, a ação é rejeitada e o estado atual fica na primeira ação inválida.
Assim, é possível verificar ou identificar erros em soluções obtidas por métodos externos, sendo apresentada
a evidência de falha.

Para um problema novo, é sempre importante que explore os sucessores, nomeadamente procure resolver 
instâncias pequenas no modo manual. 
Tem duas vantagens: identifica bugs que tenha na sua implementação; ganha entendimento sobre 
o problema em questão, que lhe poderá levar a identificar optimizações que de outra 
forma lhe passariam desapercebidas.

\anchor aspirador-a3
## Ação 3 - Ver a solução realizada manualmente

O resultado da resolução manual da ação anterior, é visualizar apenas o último estado. 
No entanto houve um caminho, que ficou guardado. Introduza: **4.**

\htmlonly
<pre>
Opção: <span class="entrada">4</span>
══ ✔  Solução ══
 │  * [*] (💰 g:0) ⚡  → esq → asp → dir → asp
 │  . [.] (💰 g:4) 🎯 
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> NADA | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 4 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
 │  . [.]
...
Opção: 
</pre>
\endhtmlonly


Neste problema uma solução é um conjunto de ações, o caminho desde o estado inicial até ao estado final. 
É mostrado esse caminho visualizando as ações a partir do estado inicial. 
Foram 4 movimentos, mas houve um desperdício. No primeiro movimento, poderíamos ter logo aspirado. 
Em outros problemas, a solução pode ser apenas o estado final. Notar ainda na letra g, seguida de um número. 
Esta letra representa o custo g(n) no manual, e sempre que ocorra significa o custo desde o estado inicial até esse estado. 
Neste problema o custo não foi definido, pelo que é adoptado o valor de 1 unidade por cada movimento. 

A visualizaçãop de ações é mais curta e simples, mas podemos ver todos os estados também.
Para isso é preciso alterar o parâmetro P6(VER_ACOES).

\anchor aspirador-a4
## Ação 4 - Ver a alterar um parâmetro

Vamos editar o parâmetro P6(VER_ACOES). Introduza: **3**

\htmlonly
<pre>
Opção: <span class="entrada">3</span>
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span>             Largura Primeiro <span style="color:gray">(1 a 7)</span>
│ <span style="color:gray">P2(NIVEL_DEBUG):</span>           NADA       <span style="color:gray">(0 a 4)</span>
│ <span style="color:gray">P3(SEMENTE):</span>               1          <span style="color:gray">(1 a 1000000)</span>
│ <span style="color:gray">P4(LIMITE_TEMPO):</span>          10         <span style="color:gray">(1 a 3600)</span>
│ <span style="color:gray">P5(LIMITE_ITERACOES):</span>      0          <span style="color:gray">(0 a 1000000000)</span>
│ <span style="color:gray">P6(VER_ACOES):</span>             4          <span style="color:gray">(1 a 100)</span>
│ <span style="color:gray">P7(LIMITE):</span>                0          <span style="color:gray">(-1 a 1000000)</span>
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span>     ignorar    <span style="color:gray">(1 a 3)</span>
│ <span style="color:gray">P11(BARALHAR_SUCESSORES):</span>  0          <span style="color:gray">(0 a 1)</span>
└──────────────────────────────────────────────────────────────────────
Parâmetro:
</pre>
\endhtmlonly

Podemos ver todos os os parâmetros e valores mínimos e máximos.  
Podemos também editar qualquer parâmetro, como é o caso, o parâmetro 6, 
tem o valor 4, e pretendemos colocar a 1.
Caso seja definido no problema novos parâmetros, ficariam aqui também expostos ao utilizador para edição.
Introduza: **6; 1; *ENTER*; 4.**

\htmlonly
<pre>
Parâmetro: <span class="entrada">6</span>
┌─ ⚙  P6(VER_ACOES) ───────────────────────────────────────────────────
│ Mostra estado a cada K ações. Se 1 mostra sempre estados e nunca ações.
│ Intervalo: 1 a 100
└──────────────────────────────────────────────────────────────────────
VER_ACOES (atual 4): <span class="entrada">1</span>
...
Opção: <span class="entrada">4</span>
══ ✔  Solução ══
 │  * [*] (💰 g:0) ⚡ 
 │ [*] *  (💰 g:1) ⚡ 
 │ [.] *  (💰 g:2) ⚡ 
 │  . [*] (💰 g:3) ⚡ 
 │  . [.] (💰 g:4) 🎯 
Aspirador
...
 │  . [.]
...
Opção: 
</pre>
\endhtmlonly

Vemos agora a solução, o caminho com todos os estados intermédios do estado inicial até ao estado final.

\anchor aspirador-a5
## Ação 5 - Efetuer uma procura em Largura

![Procura em Largura - expande primeiro os estados menos profundos](docs/images/aspirador_largura.png)

Coloque na instância inicial, número 2, com nível de debug máximo: **1; 2; 3; 2; 4; *ENTER*; 6.**

A opção 1 já sabemos, inicia uma instância, neste caso 2. 
A opção 4 vamos alterar neste caso o parâmetro nível de debug. 
Há vários níveis de debug, sendo o 4 o valor que mostra a informação mais completa, embora extensa. 

\htmlonly
<pre>
...
Parâmetro: <span class="entrada">2</span>
┌─ ⚙  P2(NIVEL_DEBUG) ─────────────────────────────────────────────────
│ Nível de debug, de reduzido a completo.                              
│ <span style="color:gray">0:</span> NADA
│ <span style="color:gray">1:</span> ATIVIDADE
│ <span style="color:gray">2:</span> PASSOS
│ <span style="color:gray">3:</span> DETALHE
│ <span style="color:gray">4:</span> COMPLETO
└──────────────────────────────────────────────────────────────────────
NIVEL_DEBUG (atual 0): <span class="entrada">4</span>
...
 * [*]
...
Opção: <span class="entrada">6</span>
</pre>
\endhtmlonly

A opção 6 executa o algoritmo selecionado, que é a Largura Primeiro.

\htmlonly
<pre>
Opção: 
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 │  * [*]
 │  ├■═╤═ 🔖 1 💰 g:1 ⚖  1|2 ═══ esq
 │  │ [*] * 
 │  └■═╤═ 🔖 2 💰 g:1 ⚖  1|2 ═══ asp
 │     * [.]
 ├■═╤═ 🔖 1 💰 g:1 ⚖  1|2 ═══ { 🔖 2 } 
 │ [*] * 
 │  ├■═╤═ 🔖 3 💰 g:2 ⚖  2|4 ═══ dir
 │  │  * [*]
 │  └■═╤═ 🔖 4 💰 g:2 ⚖  2|4 ═══ asp
 │    [.] * 
 ├■═╤═ 🔖 2 💰 g:1 ⚖  2|4 ═══ { 🔖 3 🔖 4 } 
 │  * [.]
 │  ├■═╤═ 🔖 5 💰 g:2 ⚖  3|6 ═══ esq
 │  │ [*] . 
 │  └■═╤═ 🔖 6 💰 g:2 ⚖  3|6 ═══ asp
 │     * [.]
 ├■═╤═ 🔖 3 💰 g:2 ⚖  3|6 ═══ { 🔖 4 🔖 5 🔖 6 } 
 │  * [*]
 │  ├■═╤═ 🔖 7 💰 g:3 ⚖  4|8 ═══ esq
 │  │ [*] * 
 │  └■═╤═ 🔖 8 💰 g:3 ⚖  4|8 ═══ asp
 │     * [.]
 ├■═╤═ 🔖 4 💰 g:2 ⚖  4|8 ═══ { 🔖 5 🔖 6 🔖 7 🔖 8 } 
 │ [.] * 
 │  ├■═╤═ 🔖 9 💰 g:3 ⚖  5|10 ═══ dir
 │  │  . [*]
 │  └■═╤═ 🔖 10 💰 g:3 ⚖  5|10 ═══ asp
 │    [.] * 
 ├■═╤═ 🔖 5 💰 g:2 ⚖  5|10 ═══ { 🔖 6 🔖 7 🔖 8 🔖 9 🔖 10 } 
 │ [*] . 
 │  ├■═╤═ 🔖 11 💰 g:3 ⚖  6|12 ═══ dir
 │  │  * [.]
 │  └■═╤═ 🔖 12 💰 g:3 ⚖  6|12 ═══ asp
 │    [.] . 
 │  🎯  Solução encontrada! 💰 g:3
 │ [.] . 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>4 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱    ═══
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> COMPLETO | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
[.] . 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 3 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 0 | <span style="color:gray">I4(IND_EXPANSOES):</span> 6 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 12 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
┌─ ☰ Menu ─────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄   <span style="color:gray">Instância</span>  │ 2 🔍  <span style="color:gray">Explorar</span> │ 3 ⚙   <span style="color:gray">Parâmetros</span>    │ 4 ✔  <span style="color:gray">Solução</span> │
│ 5 ⚖   <span style="color:gray">Indicadores</span> │ 6 ►   <span style="color:gray">Executar</span> │ 7 🛠️  <span style="color:gray">Configurações</span> │ 8 🧪  <span style="color:gray">Teste</span>  │
└───────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção: 
</pre>
\endhtmlonly


Verificar que o número de expansões é 6 e gerações é 12. O resultado da procura é 3, sendo recolhido pelo I1(IND_CUSTO). 
Significa que a procura encontrou uma solução de comprimento 3. Notar que o I3(Iterações) e I6(IND_LOWER_BOUND) ficaram a 0, já que 
não são atualizados neste algoritmo.

No caso de não ter os resultados iguais, confirme se todos os parâmetros estão iguais.

Podemos ver a solução, tendo ficado guardada, tal como na resolução manual. Introduza: **4.**

\htmlonly
<pre>
Opção: <span class="entrada">4</span>
══ ✔  Solução ══
 * [*] (💰 g:0) ⚡ 
 * [.] (💰 g:1) ⚡ 
[*] .  (💰 g:2) ⚡ 
[.] .  (💰 g:3) 🎯 
...
[.] . 
...
Opção: 
</pre>
\endhtmlonly

Verifique que tem apenas 3 movimentos, ao contrário dos 4 obtidos na resolução manual.

A árvore da procura em largura não é desenhada na visualização textual, apenas na procura em profundidade.

Nesta procura o que podemos ver é cada estado expandido e respetivos sucessores gerados. 
Cada estado irá aparecer pela primeira vez quando é gerado, e uma segunda vez quando é expandido.

Existe uma etiqueta em cada estado que permite confirmar que cada estado gerado será expandido uma só vez.
É também mostrada a lista dos estados gerados não expandidos em cada passo.
O estado expandido é sempre o primeiro dessa lista, que consta na iteração anterior.

Na procura em largura expandimos sempre o estado gerado há mais tempo.

- Verificar que o segundo estado expandido, é o primeiro sucessor do primeiro estado expandido. 
O terceiro estado expandido é o segundo sucessor do primeiro estado expandido. 
Poder-se-ia continuar, o estado expandido seguinte é sempre o gerado há mais tempo.

Temos no entanto o mesmo estado inicial a ser gerado. De facto, o primeiro sucessor na segunda expansão, 
o estado 3, é o estado inicial que é gerado novamente.

Podemos lidar com estados repetidos de duas formas:

- Verificar se o estado a ser gerado, não tem já um ascendente - neste caso é preciso implementar a função Distinto() - Para fazer esta validação, o código tem de seguir pelos pais, e testar se são diferentes do atual.
- Verificar se o estado a ser gerado, não foi já gerado mesmo em outro ramo, desde que no mesmo nível ou anterior. Nesse caso o estado pode ser excluído, já que já terá sido tratado nesse outro ramo - para ter esta opção, é preciso implementar a função Codificar() que coloca o estado num vetor de bits - o código utiliza uma hashtable com perdas, para verificar se o estado já foi criado em tempo constante, não existindo problemas de memória mesmo em execuções longas devido às perdas. 

\anchor aspirador-a6
## Ação 6 - Editar opções A

Altere a opção para remover os repetidos com base nos ascendentes,
e o debug para nível 3: **1; 2; 3; 8; 2; 2; 3; *ENTER*; 6.**

- Verificar que o número de expansões é 5 e gerações é 6, uma melhoria.  O resultado da procura mantém-se em 3.

\htmlonly
<pre>
...
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 │  * [*]
 ├■═╤═ 🔖 1 💰 g:1 ⚖  1|2 ═══ { 🔖 2 } 
 │ [*] * 
 ├■═╤═ 🔖 2 💰 g:1 ⚖  2|3 ═══ { 🔖 3 } 
 │  * [.]
 ├■═╤═ 🔖 3 💰 g:2 ⚖  3|4 ═══ { 🔖 4 } 
 │ [.] * 
 ├■═╤═ 🔖 4 💰 g:2 ⚖  4|5 ═══ { 🔖 5 } 
 │ [*] . 
 │  🎯  Solução encontrada! 💰 g:3
 │ [.] . 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>3 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>2 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱    ═══
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> DETALHE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ascendentes | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
[.] . 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 3 | <span style="color:gray">I2(Tempo(ms)):</span> 0 | <span style="color:gray">I3(Iterações):</span> 0 | <span style="color:gray">I4(IND_EXPANSOES):</span> 5 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 6 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

A interação de troca de parâmetro não é mais mostrada para não saturar o texto. 

Podemos ver o nível de debug a 3. Tem apenas os estados expandidos, mas não vemos os estados gerados.
Vemos no entanto a lista dos estados gerados não expandidos, confirmando que é claramente menor.
Podemos também confirmar que o estado inicial não foi um dos gerados, caso contrário seria expandido na 4º ou 5º expansão.

\anchor aspirador-a7
## Ação 7 - Editar opções B

Alterar a  opção para remover os repetidos com base nos gerados, e alterar o debug para nível 2: 
**1; 2; 3; 8; 3; 2; 2; *ENTER*; 6.**

\htmlonly
<pre>
...
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══
 ├■═╤═ 💰 g:0  ═══ { }
 ├■═╤═ 🔖 1 💰 g:1 ⚖  1|2 ═══ { 🔖 2 } 
 ├■═╤═ 🔖 2 💰 g:1 ⚖  2|3 ═══ { 🔖 3 } 
 ├■═╤═ 🔖 3 💰 g:2 ⚖  3|4 ═══ { 🔖 4 } 
 ├■═╤═ 🔖 4 💰 g:2 ⚖  4|5 ═══ { 🔖 5 } 
 │  🎯  Solução encontrada! 💰 g:3
 │ [.] . 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>3 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   9ms  ═══
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> PASSOS | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> gerados | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
[.] . 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 3 | <span style="color:gray">I2(Tempo(ms)):</span> 9 | <span style="color:gray">I3(Iterações):</span> 0 | <span style="color:gray">I4(IND_EXPANSOES):</span> 5 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 6 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

Podemos ver que o estado já não é mostrado. Em cada expansão é mostrado o custo (g) seguido de dois números: 
expansões e gerações realizadas até ao momento.
A lista com os estados gerados nãó expandidos, é ainda visualizada no final.
No caso deste problema o estado é visualizado numa só linha, 
mas em outros problemas estes dois níveis de debug podem fazer diferença. 
Notar que não houve alteração no número de expansões e gerações, muito embora a técnica para 
lidar com os estados repetidos seja distinta.

É importante observar a procura em instâncias pequenas, para poder observar ineficiências, 
como os estados repetidos, ou mesmo bugs.

O nível de debug 1 insere um # por cada 1000 expansões, de modo a dar alguma noção de como vai a procura, 
e o nível 0 não dá qualquer informação. 

\anchor aspirador-a8
## Ação 8 - Resolver outra instância 

Repor a opção de ignorar os repetidos, colocar o debug no nível 1, e procurar resolver uma instância maior: 
**1; 10; 3; 8; 1; 2; 1; *ENTER*; 6.**

Pode haver um problema de memória. 
A instância é demasiado grande, e sem remover repetidos, rapidamente gera demasiados estados:  

\htmlonly
<pre>
...
 *  *  .  *  * [*] *  .  .  . 
...
Opção: <span class="entrada">6</span>
═╤═ ►  Execução iniciada ═══#######...#######
 │  🎯  Solução encontrada! 💰 g:13
 │ [.] .  .  .  .  .  .  .  .  . 
 ├─ Parâmetros ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>1 <span style="color:gray">P3=</span>1 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>0 <span style="color:gray">P6=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>1 <span style="color:gray">P11=</span>0
═╧═ 🏁  Execução terminada ⏱   626ms  ═══
Aspirador
┌─ ⚙ Parâmetros ──────────────────────────────────────────────────────
│ <span style="color:gray">P1(ALGORITMO):</span> Largura Primeiro | <span style="color:gray">P2(NIVEL_DEBUG):</span> ATIVIDADE | <span style="color:gray">P3(SEMENTE):</span> 1
│ <span style="color:gray">P4(LIMITE_TEMPO):</span> 10 | <span style="color:gray">P5(LIMITE_ITERACOES):</span> 0 | <span style="color:gray">P6(VER_ACOES):</span> 1 | <span style="color:gray">P7(LIMITE):</span> 0
│ <span style="color:gray">P8(ESTADOS_REPETIDOS):</span> ignorar | <span style="color:gray">P11(BARALHAR_SUCESSORES):</span> 0
└──────────────────────────────────────────────────────────────────────
[.] .  .  .  .  .  .  .  .  . 
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ <span style="color:gray">I1(IND_CUSTO):</span> 13 | <span style="color:gray">I2(Tempo(ms)):</span> 626 | <span style="color:gray">I3(Iterações):</span> 0 | <span style="color:gray">I4(IND_EXPANSOES):</span> 516031 | 
│ <span style="color:gray">I5(IND_GERACOES):</span> 1513017 | <span style="color:gray">I6(IND_LOWER_BOUND):</span> 0
└──────────────────────────────────────────────────────────────────────
...
Opção: 
</pre>
\endhtmlonly

São demasiados estados gerados, 1,5 milhões, em 0.4 segundos. 
Há um # que é colocado no output a cada 1000 expansões. 
Se desconfiamos que com tanto estado, dificilmente a solução pode ser óptima, podemos ver a solução.
Introduza: **4**

\htmlonly
<pre>
Opção: <span class="entrada">4</span>
══ ✔  Solução ══
 *  *  .  *  * [*] *  .  .  .  (💰 g:0) ⚡ 
 *  *  .  *  *  * [*] .  .  .  (💰 g:1) ⚡ 
 *  *  .  *  *  * [.] .  .  .  (💰 g:2) ⚡ 
 *  *  .  *  * [*] .  .  .  .  (💰 g:3) ⚡ 
 *  *  .  *  * [.] .  .  .  .  (💰 g:4) ⚡ 
 *  *  .  * [*] .  .  .  .  .  (💰 g:5) ⚡ 
 *  *  .  * [.] .  .  .  .  .  (💰 g:6) ⚡ 
 *  *  . [*] .  .  .  .  .  .  (💰 g:7) ⚡ 
 *  *  . [.] .  .  .  .  .  .  (💰 g:8) ⚡ 
 *  * [.] .  .  .  .  .  .  .  (💰 g:9) ⚡ 
 * [*] .  .  .  .  .  .  .  .  (💰 g:10) ⚡ 
 * [.] .  .  .  .  .  .  .  .  (💰 g:11) ⚡ 
[*] .  .  .  .  .  .  .  .  .  (💰 g:12) ⚡ 
[.] .  .  .  .  .  .  .  .  .  (💰 g:13) 🎯 
</pre>
\endhtmlonly

Não houve desperdício visivel nesta solução. 
O algoritmo procura em largura garante-nos que esta solução é ótima, dado que o custo de cada ação é unitário.

Para lidar com o problema de memória, podíamos limitar a procura em largura com o parâmetro limite, 
fixando a 100 ou 1000 estados, mas perdendo a optimalidade.

A melhor solução para lidar com este problema é eliminar estados repetidos, idealmente todos os gerados. 
Mas se mesmo assim a procura em largura resultar num problema de memória, a utilização de um limite, 
poderá ser uma opção, 
mantendo-se apenas um determinado número limitado de estados gerados não expandidos. 
Esta abordagem perde a optimalidade, e também a garantia de construir um caminho do estado inicial ao final, 
o que poderá não ser problemático em alguns problemas.


\anchor aspirador-a9
## Ação 9 - Desafio Procura em Largura

Com a procura em largura, até que tamanho consegue obter a solução ótima do aspirador?

<details>
  <summary>Resposta:</summary>
Depende das condições de execução, vamos colocar na resposta o VPL com a 512MB.
Consegue resolver com P8(Repetidos)=gerados, até à instância 19, existindo problema de memória na instância 20. 
Num computador pessoal pode variar, e o limite de tempo pode ocorrer antes do problema de memória. 
Limitando a 1000 e mantendo os replicados gerados, a procura em largura consegue resolver até à instancia 50, a maior considerada no código. A utilização do limite não permite garantir a otimalidade da solução
A utilização de repetidos com base nos ascendentes, permite também resolver o problema de memória, mas ganha-se o problema de tempo, sendo uma solução viável até à instância 44, mantendo o tempo limite em 10 segundos.
</details>


\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_construtivas3b.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="teste_aspirador2.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
