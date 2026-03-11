@page tutorial_introducao2exe ✏️ Introdução - Conceito de Agentes

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_introducao.html" style="color:#9cf; text-decoration:none;">Tutorial: Introdução</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="opacity:0.7;">Inteligência Artificial ›</span>
    <a href="tutorial_introducao1lit.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_introducao1.html" style="color:#9cf;">👓 Introdução</a>
    <a href="tutorial_introducao1exe.html" style="color:#9cf;">✏️ Exercícios</a>
    <span style="opacity:0.7;">Conceito de Agente ›</span>
    <a href="tutorial_introducao2lit.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_introducao2.html" style="color:#9cf;">👓 Conceito de Agente</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Exercícios</span>
  </div>
</div>

\endhtmlonly



## Exercícios

Análise de agentes.


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- Agente Recurso 09/10 Agente: Jogador de Xadrez  -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente que joga xadrez.  
O xadrez é um jogo de tabuleiro, por turnos, em que ambos os jogadores veem todas as peças no tabuleiro e jogam alternadamente, tentando dar xeque‑mate ao rei adversário.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de jogos ganhos (ou pontuação equivalente: vitória = 1, empate = 0.5, derrota = 0), relativamente ao total de jogos jogados.  
Período de medição: <strong>[período]</strong>.

<ul>

<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar o número/pontuação de jogos ganhos.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar vitórias contraria o objetivo do agente.
</details>
</li>

<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — taxa de vitórias/score médio é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número de vitórias é possível, embora menos normalizado.
</details>

<details><summary>os pontos</summary>
✔️ Aceite — 1/0.5/0 por jogo é uma métrica usual em torneios.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — tempo não mede qualidade de jogo (apenas ritmo).
</details>
</li>

<li>[período]

<details><summary>um jogo</summary>
✔️ Aceite — possível, mas pouco robusto estatisticamente.
</details>

<details><summary>uma sessão de jogos</summary>
✔️ Correto — período natural de avaliação.
</details>

<details><summary>um torneio</summary>
✔️ Aceite — adequado para avaliação agregada.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, correspondente ao tabuleiro de xadrez e às peças.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o tabuleiro é uma grelha bidimensional de 8x8 casas.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o tabuleiro.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — peças têm volume, mas o jogo é modelado em 2D.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente efetuar jogadas no tabuleiro.

<ul><li>[atuadores]

<details><summary>movimento de peças</summary>
✔️ Correto — o agente escolhe e executa jogadas válidas.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — meio de comunicação com o servidor/jogo.
</details>

<details><summary>movimento terrestre</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente observar o estado do tabuleiro.

<ul><li>[sensores]

<details><summary>leitura do estado do tabuleiro</summary>
✔️ Correto — o agente observa a posição de todas as peças.
</details>

<details><summary>histórico de jogadas</summary>
✔️ Aceite — pode ser usado para raciocínio adicional (repetições, en passant, etc.).
</details>

<details><summary>visão</summary>
✖️ Incorreto — num agente digital, o estado é simbólico, não visual.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não se aplica.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✔️ Correto — ambas as partes veem todas as peças e o estado do tabuleiro.
</details>
  <details><summary>Parcialmente</summary>
✖️ Incorreto — não há informação oculta.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✔️ Correto — o resultado de cada ação é totalmente determinado pelas regras do jogo.
</details>
  <details><summary>Aleatório</summary>
✖️ Incorreto — não há aleatoriedade no ambiente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — cada jogada depende fortemente das anteriores.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — o jogo é uma sequência de decisões interdependentes.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✔️ Correto — o tabuleiro não muda enquanto o agente “pensa”; só muda após uma jogada.
</details>
  <details><summary>Dinâmico</summary>
✖️ Incorreto — não há alterações espontâneas do estado.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Correto — estados (configurações de peças) e ações (jogadas) são discretos.
</details>
  <details><summary>Contínuo</summary>
✖️ Incorreto — não há variáveis contínuas relevantes.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✖️ Incorreto — o jogo envolve dois jogadores com objetivos opostos.
</details>
  <details><summary>Multiagente</summary>
✔️ Correto — trata‑se de um ambiente competitivo entre dois agentes.
</details>
</li>

</ul>

</div>


<!-- Agente Recurso 10/11 Agente: Jogador de Poker  -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente jogador de Poker.  
O Poker é um jogo de cartas em que cada jogador conhece apenas as suas próprias cartas e desconhece as dos adversários.  
Os jogadores podem apostar, aumentar a aposta, igualar ou desistir, tentando maximizar a probabilidade de ter a melhor mão ou de levar os adversários a desistir.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de decisões corretas (apostar quando vantajoso, desistir quando desfavorável), relativamente às situações reais observadas.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de decisões corretas e lucrativas.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar decisões corretas contraria o objetivo do agente.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de decisões corretas é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número de decisões corretas é possível, mas menos expressivo.
</details>

<details><summary>as fichas ganhas</summary>
✔️ Aceite — mede diretamente o sucesso financeiro, embora dependa de variância.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — tempo não mede qualidade de jogo.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>uma mão</summary>
✔️ Aceite — possível, mas demasiado granular.
</details>

<details><summary>uma sessão de jogo</summary>
✔️ Correto — período natural de avaliação.
</details>

<details><summary>um torneio</summary>
✔️ Aceite — adequado para avaliação agregada.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo cartas privadas, cartas comunitárias, apostas e ações dos adversários.

<ul><li>[dimensões]

<details><summary>não espacial / simbólico</summary>
✔️ Correto — o ambiente é essencialmente informacional e simbólico.
</details>

<details><summary>2D</summary>
✖️ Incorreto — não há navegação espacial relevante.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente realizar ações de jogo.

<ul><li>[atuadores]

<details><summary>aposta / raise</summary>
✔️ Correto — ação fundamental no Poker.
</details>

<details><summary>call / igualar</summary>
✔️ Correto — outra ação essencial.
</details>

<details><summary>fold / desistir</summary>
✔️ Correto — permite abandonar mãos desfavoráveis.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — meio de interação com a plataforma de jogo.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente obter informação sobre o estado do jogo.

<ul><li>[sensores]

<details><summary>leitura das cartas próprias</summary>
✔️ Correto — informação privada essencial.
</details>

<details><summary>leitura das cartas comunitárias</summary>
✔️ Correto — determina a força relativa da mão.
</details>

<details><summary>observação das apostas dos adversários</summary>
✔️ Correto — permite inferir força provável das mãos adversárias.
</details>

<details><summary>visão</summary>
✖️ Incorreto — não se aplica a agentes digitais.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não se aplica.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o agente não conhece as cartas dos adversários.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — apenas observa cartas comunitárias e ações dos adversários.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — o baralho é aleatório e as ações dos adversários são imprevisíveis.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Aceite parcialmente — cada mão pode ser vista como episódio isolado.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — decisões dentro de uma mão dependem das anteriores.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — apostas e cartas mudam enquanto o agente decide.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente evolui a cada ação.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Correto — ações e estados do jogo são discretos.
</details>
  <details><summary>Contínuo</summary>
✖️ Incorreto — não há variáveis contínuas relevantes.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✖️ Incorreto — o jogo envolve vários jogadores.
</details>
  <details><summary>Multiagente</summary>
✔️ Correto — vários agentes (jogadores) interagem com objetivos distintos.
</details>
</li>

</ul>

</div>


<!-- Agente Normal 11/12 Agente: Robôs de Exploração com Construção de Mapa -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem pequenos robôs de exploração, munidos de GPS mas sem mapa prévio, com capacidade de comunicação entre si.  
Os robôs tentam construir o mapa de caminhos a partir da posição inicial até uma distância máxima, não podendo mover‑se por zonas muito inclinadas ou pantanosas.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de área mapeada corretamente (sem entrar em zonas proibidas), relativamente à área total explorável.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a área mapeada corretamente.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar área mapeada contraria o objetivo dos robôs.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a área mapeada é naturalmente expressa em percentagem.
</details>

<details><summary>os metros quadrados</summary>
✔️ Aceite — mede diretamente a área explorada.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — distância percorrida não mede qualidade do mapa.
</details>

<details><summary>as horas</summary>
✖️ Aceite parcialmente — mede eficiência temporal, mas não qualidade do mapa.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>uma missão de exploração</summary>
✔️ Correto — período natural de avaliação.
</details>

<details><summary>um dia</summary>
✔️ Aceite — adequado para missões longas.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — útil para avaliação agregada.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo terreno, declives, zonas pantanosas e caminhos possíveis.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o mapa de caminhos é essencialmente bidimensional.
</details>

<details><summary>3D</summary>
✔️ Aceite parcialmente — inclinação é relevante, mas o mapa é construído em 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo aos robôs deslocarem‑se e comunicar entre si.

<ul><li>[atuadores]

<details><summary>movimento terrestre</summary>
✔️ Correto — os robôs deslocam‑se pelo terreno.
</details>

<details><summary>comunicação entre robôs</summary>
✔️ Correto — permite partilhar informação do mapa.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — meio de comunicação com operadores humanos.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — os robôs não voam.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo aos robôs detetar terreno, inclinação e zonas pantanosas.

<ul><li>[sensores]

<details><summary>GPS</summary>
✔️ Correto — fornece posição absoluta.
</details>

<details><summary>sensores de inclinação</summary>
✔️ Correto — evitam zonas demasiado inclinadas.
</details>

<details><summary>sensores de humidade</summary>
✔️ Aceite — úteis para detetar zonas pantanosas.
</details>

<details><summary>visão</summary>
✔️ Aceite — pode ajudar a identificar obstáculos.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — os robôs só observam a zona onde se encontram.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — é necessário deslocar‑se para observar outras zonas.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Aceite parcialmente — se o terreno for estático, mas ainda assim há incerteza sensorial.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — sensores podem falhar e o terreno pode ter variações imprevisíveis.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — a construção do mapa depende de passos anteriores.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — cada movimento influencia o mapa construído.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✔️ Aceite — o terreno não muda enquanto o robô pensa.
</details>
  <details><summary>Dinâmico</summary>
✖️ Incorreto — não há alterações rápidas no ambiente físico.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — o mapa pode ser representado discretamente.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — o terreno real é contínuo.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✖️ Incorreto — há vários robôs cooperativos.
</details>
  <details><summary>Multiagente</summary>
✔️ Correto — os robôs comunicam e constroem o mapa em conjunto.
</details>
</li>

</ul>

</div>



<!-- Agente Recurso 11/12 Agente: Robô de Limpeza Autónomo numa Fábrica -->
 
<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um robô de limpeza autónomo numa fábrica, responsável por aspirar o pó, evitando pessoas, máquinas e líquidos no chão.  
O robô tem ainda a capacidade de carregar a sua bateria e descarregar o depósito do aspirador num local específico da fábrica.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de área limpa corretamente (sem colisões, sem passar por zonas proibidas), relativamente à área total a limpar.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a área limpa corretamente.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar área limpa contraria o objetivo do robô.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a área limpa corretamente é naturalmente expressa em percentagem.
</details>

<details><summary>os metros quadrados</summary>
✔️ Aceite — mede diretamente a área limpa.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — distância percorrida não mede qualidade da limpeza.
</details>

<details><summary>as horas</summary>
✖️ Aceite parcialmente — tempo pode medir eficiência, mas não qualidade da limpeza.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um turno de limpeza</summary>
✔️ Correto — período natural de avaliação.
</details>

<details><summary>um dia</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — útil para avaliação global.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo corredores, máquinas, zonas de circulação e áreas com líquidos no chão.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o robô navega num plano bidimensional da fábrica.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — o espaço é tridimensional, mas a navegação é essencialmente 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao robô deslocar‑se, aspirar, carregar bateria e descarregar o depósito.

<ul><li>[atuadores]

<details><summary>movimento terrestre</summary>
✔️ Correto — o robô desloca‑se autonomamente pela fábrica.
</details>

<details><summary>aspirador</summary>
✔️ Correto — componente principal da limpeza.
</details>

<details><summary>mecanismo de descarga do depósito</summary>
✔️ Aceite — permite esvaziar o depósito no local apropriado.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — meio de comunicação com operadores humanos.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao robô detetar obstáculos, pessoas, máquinas e líquidos no chão.

<ul><li>[sensores]

<details><summary>sensores de proximidade</summary>
✔️ Correto — evitam colisões com pessoas e máquinas.
</details>

<details><summary>visão</summary>
✔️ Aceite — útil para detetar líquidos e obstáculos.
</details>

<details><summary>sensores de nível do depósito</summary>
✔️ Correto — indicam quando é necessário descarregar o aspirador.
</details>

<details><summary>sensor de bateria</summary>
✔️ Correto — permite ao robô saber quando deve recarregar.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o robô não vê toda a fábrica simultaneamente.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — apenas observa o que os sensores captam.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — pessoas movem‑se de forma imprevisível e podem surgir líquidos inesperados.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do robô.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — a limpeza depende de decisões anteriores (zonas já limpas, bateria, depósito cheio).
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — o robô segue um plano de ações encadeadas.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — pessoas e máquinas movem‑se, líquidos podem surgir.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente muda enquanto o robô opera.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — decisões (limpar, carregar, descarregar) são discretas.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — movimento e deteção espacial são contínuos.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um robô executa a tarefa.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há vários agentes cooperativos.
</details>
</li>

</ul>

</div>


<!-- Agente Normal 12/13 Agente: Recolha e Produção de Informação na Internet -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente na internet cujo objetivo é obter informações sobre um assunto pré‑determinado.  
Para o fazer, o agente pode ler páginas, blogs, fóruns e tudo o que encontrar na internet, mas também tem capacidade de se fazer passar por um ser humano e introduzir perguntas em fóruns e redes sociais.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de informações relevantes obtidas, relativamente ao total de informações disponíveis sobre o tema.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a quantidade de informação relevante recolhida.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar informação recolhida contraria o objetivo do agente.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de informação relevante obtida é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número de informações relevantes é possível, embora menos expressivo.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade da recolha de informação.
</details>

<details><summary>os bytes</summary>
✖️ Aceite parcialmente — mede volume de dados, mas não relevância.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>uma sessão de pesquisa</summary>
✔️ Correto — cada sessão pode ser avaliada individualmente.
</details>

<details><summary>um dia</summary>
✔️ Aceite — adequado para recolhas contínuas.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — útil para análise agregada.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo páginas web, fóruns, blogs e redes sociais.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — não representa a estrutura da internet.
</details>

<details><summary>2D</summary>
✖️ Aceite parcialmente — páginas são bidimensionais, mas o ambiente conceptual é mais abstrato.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação espacial.
</details>

<details><summary>não espacial / simbólico</summary>
✔️ Correto — o ambiente é essencialmente informacional e simbólico.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente interagir com conteúdos e publicar mensagens.

<ul><li>[atuadores]

<details><summary>envio de mensagens</summary>
✔️ Correto — o agente coloca perguntas em fóruns e redes sociais.
</details>

<details><summary>requisições HTTP</summary>
✔️ Correto — o agente lê páginas e conteúdos online.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — meio de comunicação com utilizadores humanos.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente obter informação da internet.

<ul><li>[sensores]

<details><summary>leitura de páginas web</summary>
✔️ Correto — principal forma de recolha de informação.
</details>

<details><summary>monitorização de fóruns</summary>
✔️ Correto — permite recolher respostas às perguntas colocadas.
</details>

<details><summary>visão</summary>
✖️ Incorreto — não se aplica a agentes puramente digitais.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não se aplica.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o agente não vê toda a internet.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — apenas observa páginas que consegue aceder ou que lhe respondem.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — respostas humanas e conteúdos online são imprevisíveis.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✔️ Aceite — cada pesquisa pode ser tratada como episódio independente.
</details>
  <details><summary>Sequencial</summary>
✔️ Aceite — se o agente usar histórico para melhorar pesquisas futuras.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — conteúdos online mudam continuamente.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente muda enquanto o agente pensa.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Correto — páginas, posts e respostas são entidades discretas.
</details>
  <details><summary>Contínuo</summary>
✖️ Incorreto — não há variáveis contínuas relevantes.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Aceite — se considerado um único agente de pesquisa.
</details>
  <details><summary>Multiagente</summary>
✔️ Aceite — se considerarmos que interage com múltiplos utilizadores humanos (agentes externos).
</details>
</li>

</ul>

</div>


<!-- Agente Recurso 24/25 Agente: Apoio à Medicação num Lar de Idosos -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente de apoio à medicação num lar de idosos.  
O agente é capaz de se deslocar autonomamente para atender os idosos, levando a medicação na altura adequada.  
Os medicamentos são carregados diariamente em pequenas caixas individuais para cada idoso e distribuídos em diferentes momentos do dia.  
O agente recolhe as caixas vazias após a administração e, ao final do dia, devolve-as à farmácia do lar para recarregar.  
Cada idoso utiliza uma pulseira que o identifica e transmite a sua localização, facilitando a deteção do momento de entrega.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de entregas corretas (entregar a medicação certa, ao idoso certo, no momento certo), relativamente ao total de entregas previstas.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de entregas corretas.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar entregas corretas não faz sentido.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de entregas corretas é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de entregas corretas é possível, mas menos expressivo.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade de entrega.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — não mede desempenho.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — a medicação é organizada diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>um mês</summary>
✔️ Aceite — útil para avaliação global.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo corredores, quartos, refeitórios e zonas de circulação do lar.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o robô navega num espaço bidimensional (planta do edifício).
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — o espaço é tridimensional, mas a navegação é essencialmente 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente deslocar‑se e entregar/recolher caixas de medicação.

<ul><li>[atuadores]

<details><summary>movimento terrestre</summary>
✔️ Correto — o agente desloca‑se autonomamente pelo lar.
</details>

<details><summary>mecanismo de entrega/recolha</summary>
✔️ Correto — permite entregar e recolher caixas de medicação.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de comunicação com operadores humanos.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o agente não voa.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente identificar idosos, localizar‑se e detetar obstáculos.

<ul><li>[sensores]

<details><summary>leitor de pulseiras RFID</summary>
✔️ Correto — identifica cada idoso e confirma a entrega.
</details>

<details><summary>GPS interno / localização indoor</summary>
✔️ Aceite — necessário para navegação em interiores.
</details>

<details><summary>sensores de proximidade</summary>
✔️ Correto — evitam colisões.
</details>

<details><summary>visão</summary>
✔️ Aceite — pode ser usada para navegação e deteção de pessoas.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o agente não vê todo o lar simultaneamente.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — apenas observa o que os sensores captam.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — idosos movem‑se de forma imprevisível.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — entregas dependem de horários e estados anteriores.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — o agente segue rotinas e ações encadeadas ao longo do dia.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — idosos movem‑se e o ambiente muda enquanto o agente pensa.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente é altamente dinâmico.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — decisões (entregar/recolher) são discretas.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — movimento e localização são contínuos.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um agente gere as entregas.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há vários agentes independentes.
</details>
</li>

</ul>

</div>


<!-- Agente Normal 24/25 Agente: Monitorização Agrícola com Drone e Sistema de Irrigação -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente de monitorização agrícola.  
O agente dispõe de um drone, um conjunto de sensores fixos no solo em pontos chave e controlo do sistema de irrigação.  
Pretende‑se que analise o estado das culturas e detete necessidades de irrigação, nunca ultrapassando a água ideal para a cultura nem a água disponível nos depósitos.  
O sistema de irrigação é composto por depósitos de água e rede de canais para ligação às zonas de cultivo.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de decisões corretas de irrigação (regar quando necessário, não regar quando não necessário), relativamente às situações reais observadas.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de decisões corretas de irrigação.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar decisões corretas não faz sentido.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de decisões corretas é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de decisões corretas é possível, mas menos expressivo.
</details>

<details><summary>os litros</summary>
✖️ Aceite parcialmente — mede consumo de água, mas não qualidade da decisão.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade de irrigação.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — decisões de irrigação podem ser avaliadas diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>um ciclo de cultivo</summary>
✔️ Aceite — período natural para avaliação global.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo campos agrícolas, relevo, zonas de irrigação e condições ambientais variáveis.

<ul><li>[dimensões]

<details><summary>3D</summary>
✔️ Correto — o drone opera em 3D e o terreno tem relevo.
</details>

<details><summary>2D</summary>
✖️ Aceite parcialmente — mapas agrícolas podem ser 2D, mas o ambiente real é 3D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente controlar o drone e o sistema de irrigação.

<ul><li>[atuadores]

<details><summary>controlo do sistema de irrigação</summary>
✔️ Correto — o agente abre/fecha canais e controla caudal.
</details>

<details><summary>movimento aéreo do drone</summary>
✔️ Correto — o agente posiciona o drone para recolha de dados.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de comunicação com operadores humanos.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente; o drone sim, mas em 3D.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente medir o estado das culturas e das condições ambientais.

<ul><li>[sensores]

<details><summary>sensores de humidade do solo</summary>
✔️ Correto — essenciais para detetar necessidade de irrigação.
</details>

<details><summary>visão</summary>
✔️ Correto — o drone usa câmaras para analisar o estado das culturas.
</details>

<details><summary>sensores térmicos</summary>
✔️ Aceite — úteis para detetar stress hídrico.
</details>

<details><summary>GPS</summary>
✔️ Aceite — necessário para navegação do drone.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o agente só observa zonas cobertas pelo drone e sensores fixos.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — há zonas não observadas continuamente.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — clima, evaporação e infiltração são imprevisíveis.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — decisões dependem de medições anteriores e evolução das culturas.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — o agente atualiza decisões ao longo do tempo.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — o estado das culturas e do solo muda continuamente.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente agrícola é altamente dinâmico.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — decisões (regar/não regar) são discretas.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — variáveis ambientais são contínuas.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um agente central gere o sistema.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há vários agentes independentes.
</details>
</li>

</ul>

</div>


<!-- Agente Recurso 23/24 Agente: Treinador Inteligente de Atleta -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente treinador de um atleta, que mede através de diversos sensores o estado físico do atleta.  
O agente permite analisar uma sessão de treino, acompanhar a evolução ao longo de várias sessões e, durante uma prova, aconselhar sobre o controlo de esforço e emitir alertas de proximidade a um estado de exaustão.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de previsões corretas sobre esforço, fadiga e risco de exaustão, relativamente às situações reais observadas.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de previsões corretas e alertas adequados.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar previsões corretas não faz sentido para um treinador.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de acerto é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de previsões corretas é possível, mas menos expressivo.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade de previsão.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — não mede desempenho do agente.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>uma sessão de treino</summary>
✔️ Correto — o desempenho pode ser avaliado por sessão.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se houver várias sessões.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>uma época desportiva</summary>
✔️ Aceite — período natural para avaliação global.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, incluindo pista, ginásio, percurso de prova e condições ambientais variáveis.

<ul><li>[dimensões]

<details><summary>3D</summary>
✔️ Correto — o atleta movimenta‑se num espaço tridimensional.
</details>

<details><summary>2D</summary>
✖️ Aceite parcialmente — mapas de treino podem ser 2D, mas o ambiente real é 3D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente comunicar recomendações e alertas ao atleta.

<ul><li>[atuadores]

<details><summary>emissão de alertas</summary>
✔️ Correto — o agente avisa sobre risco de exaustão.
</details>

<details><summary>aconselhamento de esforço</summary>
✔️ Correto — o agente ajusta recomendações durante treino/prova.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de comunicação com o atleta.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente medir o estado físico do atleta.

<ul><li>[sensores]

<details><summary>sensor cardíaco</summary>
✔️ Correto — mede frequência cardíaca.
</details>

<details><summary>acelerómetro</summary>
✔️ Correto — mede movimento e intensidade.
</details>

<details><summary>sensor de oxigénio no sangue</summary>
✔️ Aceite — útil para avaliar fadiga.
</details>

<details><summary>GPS</summary>
✔️ Aceite — útil para medir velocidade e percurso.
</details>

<details><summary>visão</summary>
✔️ Aceite — se o sistema incluir câmaras para análise de postura.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — o agente não observa todos os fatores externos (vento, terreno, outros atletas).
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — apenas observa o que os sensores captam.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — o estado físico do atleta varia de forma imprevisível.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — o treino e a prova têm continuidade.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — cada medição influencia recomendações seguintes.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — o estado do atleta muda continuamente.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente físico e fisiológico é altamente dinâmico.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — decisões (alertar/não alertar) são discretas.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — variáveis fisiológicas são contínuas.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um agente acompanha o atleta.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há vários agentes independentes.
</details>
</li>

</ul>

</div>


<!-- Agente Normal 23/24 Agente: Previsão de Tempo e Eventos Extremos numa Estância de Ski -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente que prevê o tempo e eventos extremos numa dada estância de ski, com base em dados históricos e medições em tempo real.  
A informação do agente é utilizada para decidir abrir ou não a estância no dia seguinte e, quando a estância está aberta, para fechar atempadamente caso um fenómeno extremo se aproxime.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de previsões corretas sobre condições perigosas e decisões adequadas (abrir/fechar).  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de previsões corretas e decisões adequadas.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar previsões corretas não faz sentido.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de acerto é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de previsões corretas é possível, mas menos expressivo.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade de previsão.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — não mede desempenho meteorológico.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — previsões são avaliadas diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>uma época de ski</summary>
✔️ Aceite — período natural para avaliação global.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com relevo, pistas, zonas de risco e condições atmosféricas variáveis.

<ul><li>[dimensões]

<details><summary>3D</summary>
✔️ Correto — a estância de ski é um ambiente tridimensional com altitude e relevo.
</details>

<details><summary>2D</summary>
✖️ Aceite parcialmente — mapas podem ser 2D, mas o ambiente real é 3D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente emitir decisões de abertura/fecho e alertas de risco.

<ul><li>[atuadores]

<details><summary>emissão de alertas</summary>
✔️ Correto — o agente comunica decisões de risco.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de comunicação com operadores humanos.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente obter dados meteorológicos e ambientais.

<ul><li>[sensores]

<details><summary>sensores meteorológicos</summary>
✔️ Correto — temperatura, vento, humidade, precipitação.
</details>

<details><summary>sensores de neve</summary>
✔️ Aceite — medem espessura e estabilidade da neve.
</details>

<details><summary>visão</summary>
✔️ Aceite — câmaras podem detetar fenómenos visuais (nevoeiro, avalanches).
</details>

<details><summary>GPS</summary>
✔️ Aceite — útil para localização de sensores móveis.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✖️ Incorreto — nem todas as zonas da estância são observáveis em tempo real.
</details>
  <details><summary>Parcialmente</summary>
✔️ Correto — o agente observa apenas o que os sensores captam.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✖️ Incorreto — o clima é intrinsecamente imprevisível.
</details>
  <details><summary>Aleatório</summary>
✔️ Correto — o estado seguinte não depende apenas das ações do agente.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — previsões dependem de medições anteriores.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — o agente atualiza previsões continuamente ao longo do tempo.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✖️ Incorreto — o clima muda enquanto o agente pensa.
</details>
  <details><summary>Dinâmico</summary>
✔️ Correto — o ambiente meteorológico é altamente dinâmico.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Aceite — decisões (abrir/fechar) são discretas.
</details>
  <details><summary>Contínuo</summary>
✔️ Aceite — variáveis meteorológicas são contínuas.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um agente central toma decisões.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há vários agentes independentes.
</details>
</li>

</ul>

</div>


<!-- Agente Recurso 22/23 Agente: Controlo de Stock de Produtos de Supermercado -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que controla o stock de produtos de um supermercado, emitindo ordens de reposição quando existem ruturas de stock ou quando produtos ultrapassam o prazo de validade.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de tempo médio em que existe rutura de stock ou produtos expirados.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo com ruturas de stock piora o desempenho.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo em que o supermercado tem produtos em falta ou expirados.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>as horas</summary>
✔️ Correto — o tempo médio sem stock pode ser expresso em horas.
</details>

<details><summary>os minutos</summary>
✔️ Aceite — possível, embora menos comum.
</details>

<details><summary>a percentagem</summary>
✖️ Aceite parcialmente — percentagem de tempo sem stock é possível, mas menos operacional.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem rutura de stock.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de ruturas é quantificável, mas não mede duração.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — o desempenho pode ser medido diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>um mês</summary>
✔️ Aceite — comum em gestão de stock.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com produtos, prateleiras, datas de validade e registos de entrada/saída.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o stock é organizado em prateleiras e corredores bidimensionais.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — os produtos têm volume, mas a gestão é essencialmente 2D.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente emitir ordens de reposição.

<ul><li>[atuadores]

<details><summary>ordem de reposição</summary>
✔️ Correto — o agente atua emitindo pedidos de reposição.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de comunicação com o sistema de gestão.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente obter informação sobre quantidades e validade dos produtos.

<ul><li>[sensores]

<details><summary>leitura de base de dados</summary>
✔️ Correto — o agente lê o stock e datas de validade.
</details>

<details><summary>visão</summary>
✔️ Aceite — se o sistema usar câmaras para ler prateleiras.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são relevantes para gestão de stock.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>
✔️ Correto — o agente tem acesso a toda a informação de stock e validade.
</details>
  <details><summary>Parcialmente</summary>
✖️ Incorreto — não há zonas ocultas relevantes.
</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>
✔️ Correto — o stock só muda quando registado; não há incerteza nas ações do agente.
</details>
  <details><summary>Aleatório</summary>
✖️ Incorreto — não há fatores imprevisíveis relevantes.
</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✔️ Correto — cada verificação de stock pode ser tratada independentemente.
</details>
  <details><summary>Sequencial</summary>
✖️ Aceite parcialmente — apenas se o agente planear reposições ao longo do tempo.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>
✔️ Correto — o ambiente não muda enquanto o agente pensa.
</details>
  <details><summary>Dinâmico</summary>
✖️ Incorreto — não há alterações rápidas durante o processamento.
</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>
✔️ Correto — quantidades de stock e datas são discretas.
</details>
  <details><summary>Contínuo</summary>
✖️ Incorreto — não há variáveis contínuas relevantes.
</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>
✔️ Correto — apenas um agente gere o stock.
</details>
  <details><summary>Multiagente</summary>
✖️ Incorreto — não há cooperação entre agentes.
</details>
</li>

</ul>

</div>



<!-- Agente Normal 22/23 Agente: Sistema de Robôs de Entrega de Comidas numa Cidade -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um sistema de robôs de entrega de comidas.  
Os robôs têm de satisfazer pedidos de recolha e entrega em diferentes pontos de uma cidade.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de tempo médio entre o pedido e a entrega.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo de entrega piora o serviço.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo médio de entrega.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os minutos</summary>
✔️ Correto — o tempo de entrega é naturalmente expresso em minutos.
</details>

<details><summary>as horas</summary>
✔️ Aceite — possível, embora menos prático.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não mede tempo.
</details>

<details><summary>os metros</summary>
✖️ Aceite parcialmente — mede distância percorrida, mas não desempenho temporal.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de entregas não mede qualidade temporal.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — o desempenho pode ser medido diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>uma entrega</summary>
✖️ Aceite parcialmente — demasiado granular para medir desempenho global.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com ruas, passeios, edifícios, tráfego e pontos de recolha/entrega.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o robô navega num mapa bidimensional da cidade.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas a navegação é essencialmente 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao robô deslocar‑se e recolher/entregar encomendas.

<ul><li>[atuadores]

<details><summary>movimento terrestre</summary>
✔️ Correto — o robô desloca‑se pela cidade.
</details>

<details><summary>braço de recolha</summary>
✔️ Aceite — se o robô recolher fisicamente a encomenda.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Aceite parcialmente — é o meio de comunicação, mas não o atuador principal.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não é indicado que o robô voe.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao robô localizar‑se e detetar obstáculos.

<ul><li>[sensores]

<details><summary>GPS</summary>
✔️ Correto — necessário para navegação urbana.
</details>

<details><summary>sensores de proximidade</summary>
✔️ Correto — evitam colisões.
</details>

<details><summary>visão</summary>
✔️ Aceite — pode ser usada para detetar obstáculos e pontos de entrega.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são essenciais para este tipo de robô.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o robô não vê toda a cidade.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — apenas observa o que está ao alcance dos sensores.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — tráfego, peões e obstáculos são imprevisíveis.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — as entregas dependem de decisões anteriores.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o robô segue um plano de ações encadeadas.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda enquanto o robô se desloca.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — tráfego e obstáculos mudam continuamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — as decisões (ir para X, recolher, entregar) são discretas.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — o movimento físico é contínuo.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Aceite — se considerado um robô isolado.</details>
  <details><summary>Multiagente</summary>✔️ Aceite — se vários robôs cooperarem.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 21/22 Agente: Guia de Museu com Estilo de Condução Conversacional -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que é um guia de museu, que replica o estilo de guias humanos, tendo para tal histórico de visitas de cada guia.  
O agente permite conversação com os visitantes e possui informação sobre as diversas obras em exposição.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de interações corretas e adequadas ao estilo do guia, relativamente às interações totais.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de interações adequadas ao estilo do guia.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar interações corretas não faz sentido para um guia.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de interações adequadas é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de interações corretas é possível, mas menos expressivo.
</details>

<details><summary>os minutos</summary>
✖️ Incorreto — minutos não medem qualidade de interação.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — não mede desempenho.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — não mede desempenho.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>uma visita</summary>
✔️ Correto — o desempenho pode ser medido por visita guiada.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se houver várias visitas.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — adequado para análise agregada.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com salas, corredores, obras de arte e visitantes.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o museu é um espaço bidimensional navegável.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há volume, mas a navegação é essencialmente 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente comunicar com os visitantes e orientar a visita.

<ul><li>[atuadores]

<details><summary>geração de fala</summary>
✔️ Correto — o agente comunica verbalmente com os visitantes.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — se o guia for digital, é o meio de interação.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca fisicamente (a menos que seja robótico, o que não é indicado).
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, permitindo ao agente obter o conteúdo da conversa e o contexto da visita.

<ul><li>[sensores]

<details><summary>microfone</summary>
✔️ Correto — necessário para captar as falas dos visitantes.
</details>

<details><summary>visão</summary>
✔️ Aceite — pode ser usado para identificar visitantes ou obras próximas.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — se o guia for digital, recebe texto diretamente.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não vê todo o museu nem todas as conversas simultaneamente.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — apenas observa o que está ao alcance dos sensores.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — as respostas dos visitantes são imprevisíveis.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — a conversa e a visita têm continuidade.</details>
  <details><summary>Sequencial</summary>✔️ Correto — cada interação influencia as seguintes.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — visitantes movem‑se e fazem perguntas enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — o ambiente muda continuamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — as interações podem ser vistas como eventos discretos.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — a conversação é contínua.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — apenas um guia conduz a visita.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — os visitantes não são agentes com objetivos competitivos.</details>
</li>

</ul>

</div>



<!-- Agente Especial 20/21 Agente: Sistema de Controlo de Semáforos num Nó Complexo -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que controla os semáforos de tráfego num nó complexo e com grande intensidade de tráfego.  
O agente deteta entrada e saída de veículos nos diversos ramais do nó, bem como o seu posicionamento dentro dos vários troços.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> em média que os veículos permanecem no nó de tráfego.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo de permanência aumenta congestionamento.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo médio que os veículos passam no nó.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os minutos</summary>
✔️ Correto — o tempo médio de permanência é naturalmente expresso em minutos.
</details>

<details><summary>as horas</summary>
✔️ Aceite — também é uma unidade válida, embora menos prática.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não mede tempo de permanência.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem congestionamento temporal.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de veículos processados não mede tempo.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — o desempenho pode ser medido diariamente.
</details>

<details><summary>uma hora</summary>
✔️ Aceite — adequado para nós com tráfego intenso.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — possível para análise agregada.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com o nó rodoviário, contendo as vias e ramais, bem como todas as ligações e sentidos de circulação.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o nó de tráfego é um espaço bidimensional com vias e ramais.
</details>

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas o controlo é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — não se trata de imagens temporais.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, permitindo ao agente controlar o estado dos semáforos e a informação visual aos condutores.

<ul><li>[atuadores]

<details><summary>controlo dos semáforos</summary>
✔️ Correto — o agente altera estados (verde/amarelo/vermelho).
</details>

<details><summary>indicação de direção</summary>
✔️ Aceite — pode incluir setas luminosas ou informação complementar.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se desloca.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Aceite parcialmente — é o meio de atuação, mas não o atuador conceptual.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong> de modo a detetar entrada, saída e posicionamento dos veículos.

<ul><li>[sensores]

<details><summary>sensores de presença</summary>
✔️ Correto — detetam veículos nos ramais.
</details>

<details><summary>sensores de proximidade</summary>
✔️ Aceite — usados para medir distâncias e posicionamento.
</details>

<details><summary>câmaras</summary>
✔️ Aceite — visão é comum em sistemas avançados de tráfego.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Aceite — se houver sensores em todos os ramais.</details>
  <details><summary>Parcialmente</summary>✔️ Aceite — se houver zonas sem cobertura sensorial.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o comportamento dos condutores é imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — decisões dependem do estado anterior do tráfego.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o controlo dos semáforos evolui em sequência.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o tráfego muda enquanto o agente decide.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — veículos entram e saem continuamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — estados dos semáforos são discretos.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — o movimento dos veículos é contínuo.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — um único agente controla o nó.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há vários agentes independentes.</details>
</li>

</ul>

</div>



<!-- Agente Recurso 20/21 Agente: Robôs para Extinção de Fogos Florestais -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um conjunto de robôs especialmente desenvolvidos para serem utilizados na extinção de fogos florestais.  
Os robôs têm de conhecer pontos de acesso à água (barragens, rios) e atuam de forma autónoma no controlo de incêndios em zonas não povoadas.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> ardidos.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar área ardida contraria totalmente o objetivo do agente.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar a percentagem de área ardida ao longo da época de incêndios.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a área ardida é expressa naturalmente em percentagem da área total.
</details>

<details><summary>os metros quadrados</summary>
✔️ Aceite — área ardida pode ser medida diretamente em m².
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem área ardida.
</details>

<details><summary>as horas</summary>
✖️ Aceite parcialmente — tempo até extinção é um indicador possível, mas não o principal.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de fogos extintos é quantificável, mas não operacional.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>a época de incêndios</summary>
✔️ Correto — o desempenho deve ser medido num período alargado.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível, mas menos representativo.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — também possível.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, embora o agente possa/deva ser aerotransportado e se mova em 3D. Parte da área florestal pode estar queimada ou em incêndio.

<ul><li>[dimensões]

<details><summary>2D</summary>
✔️ Correto — o ambiente relevante é a área florestal (superfície 2D), mesmo que o robô voe.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — o robô move‑se em 3D, mas o ambiente é modelado em 2D.
</details>

<details><summary>1D</summary>
✖️ Incorreto — não representa o ambiente.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — não se trata de imagens temporais.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, tratada por procedimentos internos, incluindo recolha de água e largada de água.

<ul><li>[atuadores]

<details><summary>movimento 3D</summary>
✔️ Correto — o agente desloca‑se para posições e altitudes específicas.
</details>

<details><summary>recolha de água</summary>
✔️ Aceite — é um atuador interno do robô.
</details>

<details><summary>largada de água</summary>
✔️ Correto — ação principal de combate ao fogo.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o robô não se move apenas linearmente.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um atuador físico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong> de vários tipos para deteção de fogos, identificação de posição, temperatura e gases perigosos.

<ul><li>[sensores]

<details><summary>visão</summary>
✔️ Correto — câmaras são essenciais para detetar focos de incêndio.
</details>

<details><summary>sensores de temperatura</summary>
✔️ Correto — permitem identificar zonas perigosas e evitar danos.
</details>

<details><summary>sensores de gases</summary>
✔️ Correto — detetam gases tóxicos ou perigosos para o robô.
</details>

<details><summary>GPS</summary>
✔️ Aceite — necessário para navegação.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são relevantes para incêndios florestais.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o robô só observa a zona onde se encontra.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — é necessário deslocar‑se para observar outras zonas.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — vento e propagação do fogo tornam o ambiente imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — as ações dependem de uma sequência (recolher água → largar água → regressar).</details>
  <details><summary>Sequencial</summary>✔️ Correto — o combate ao fogo exige ações encadeadas.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o fogo evolui enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — o ambiente muda rapidamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — o espaço é contínuo.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o robô opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✖️ Aceite parcialmente — apenas se considerado um robô isolado.</details>
  <details><summary>Multiagente</summary>✔️ Correto — vários robôs cooperam para minimizar área ardida.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 19/20 Agente: Processamento de Áudio para Conversão em Texto -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que processa áudio e procura converter para texto o máximo número de falas captadas.  
As falas podem ocorrer em simultâneo e em diferentes intensidades, sendo etiquetadas com a identificação do seu emissor.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de falas bem captadas, relativamente às existentes.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de falas corretamente identificadas e transcritas.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar falas captadas contraria o objetivo do agente.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de falas captadas é expressa naturalmente em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número de falas captadas é quantificável, mas não expressa proporcionalidade.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem desempenho de áudio.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não mede qualidade de captação.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o indicador.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um ficheiro</summary>
✔️ Correto — cada ficheiro de áudio é uma unidade de processamento.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se forem processados vários ficheiros ao longo do dia.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para medir desempenho global.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, atendendo a que o agente processa áudio.

<ul><li>[dimensões]

<details><summary>1D</summary>
✔️ Correto — o áudio é um sinal unidimensional ao longo do tempo.
</details>

<details><summary>2D</summary>
✖️ Incorreto — não se trata de imagem.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação espacial.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, ficando o resultado por exemplo em XML, com as falas etiquetadas.

<ul><li>[atuadores]

<details><summary>geração de ficheiro</summary>
✔️ Correto — o agente atua produzindo o ficheiro de saída com as falas etiquetadas.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se move.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio de exportação do resultado.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong> de modo a carregar o áudio.

<ul><li>[sensores]

<details><summary>carregamento de ficheiro</summary>
✔️ Correto — o agente lê o ficheiro de áudio como entrada.
</details>

<details><summary>microfone</summary>
✖️ Incorreto — o agente não capta áudio em tempo real.
</details>

<details><summary>visão</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não se aplica.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — todo o áudio está disponível ao agente.</details>
  <details><summary>Parcialmente</summary>✖️ Incorreto — não há partes ocultas do ficheiro.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✔️ Correto — o mesmo ficheiro produz sempre o mesmo resultado.</details>
  <details><summary>Aleatório</summary>✖️ Aceite parcialmente — apenas se for referido ruído, mas o input é fixo.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✔️ Correto — cada ficheiro é processado independentemente.</details>
  <details><summary>Sequencial</summary>✖️ Aceite parcialmente — apenas se houver continuidade entre ficheiros.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — o ficheiro não muda enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — não há alterações durante o processamento.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — o áudio está digitalizado.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — a origem do áudio é contínua.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — apenas um agente processa o áudio.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há cooperação entre agentes.</details>
</li>

</ul>

</div>



<!-- Agente Recurso 18/19 Agente: Jogador de Gamão (Backgammon) -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que é um jogador de Gamão (jogo de tabuleiro com componente aleatória devido ao lançamento dos dados).</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de vitórias.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a probabilidade média de vitória ao longo de várias partidas.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar vitórias não faz sentido num jogo competitivo.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de vitórias é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✔️ Aceite — número médio de vitórias é um indicador válido, desde que seja uma média.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem desempenho num jogo de tabuleiro.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não mede qualidade de jogo.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o indicador.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um conjunto de jogos</summary>
✔️ Correto — o desempenho deve ser medido ao longo de várias partidas.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se forem jogadas várias partidas no mesmo dia.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para avaliar desempenho.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Aceite parcialmente — uma única partida não é suficiente para medir desempenho médio.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com o tabuleiro, peças e regras do jogo.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o tabuleiro não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o tabuleiro é bidimensional.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Aceite parcialmente — existe tempo, mas a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong> de modo a executar o lance.

<ul><li>[atuadores]

<details><summary>execução do lance</summary>
✔️ Correto — o agente atua movendo peças segundo as regras.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — não se aplica a jogos de tabuleiro.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — se o jogo for digital, é o meio de atuação.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong> de modo a obter o estado do tabuleiro.

<ul><li>[sensores]

<details><summary>visão</summary>
✔️ Aceite — pode ser usado para interpretar o tabuleiro físico.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Correto — num jogo digital, o estado do tabuleiro é lido diretamente.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são relevantes para jogos de tabuleiro.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não conhece o resultado futuro dos dados.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — o estado atual é observável, mas o lançamento dos dados não.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o lançamento dos dados introduz aleatoriedade.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o próximo estado depende dos dados, não apenas das ações.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — cada jogada depende das anteriores.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o jogo evolui em sequência de jogadas.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — o tabuleiro não muda enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — não há alterações durante o raciocínio.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Correto — posições das peças e valores dos dados são discretos.</details>
  <details><summary>Contínuo</summary>✖️ Incorreto — não há variáveis contínuas relevantes.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✖️ Incorreto — há dois jogadores com objetivos opostos.</details>
  <details><summary>Multiagente</summary>✔️ Correto — trata‑se de um ambiente competitivo entre dois agentes.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 17/18 Agente: Sistema Avançado de Elevadores num Hotel -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um sistema de elevadores avançado num prédio de um hotel de elevada dimensão, com detetores de presença nas entradas.  
Pretende‑se a movimentação célere das pessoas para o seu piso de destino.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> em média que as pessoas estão no sistema de elevadores.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo de espera contraria o objetivo do sistema.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo médio de espera e deslocação.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>as horas</summary>
✔️ Aceite — o tempo médio pode ser expresso em horas, embora minutos seja mais comum.
</details>

<details><summary>os minutos</summary>
✔️ Correto — o tempo médio de espera é naturalmente expresso em minutos.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não mede tempo de espera.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem desempenho do elevador.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de viagens é quantificável, mas não mede tempo.
</details>

</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — o desempenho pode ser medido diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Aceite — possível se houver grande volume de dados.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não mede desempenho global do sistema.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para medir desempenho global.
</details>

</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com os andares em que o elevador pode parar.

<ul><li>[dimensões]

<details><summary>1D</summary>
✔️ Correto — o movimento do elevador é essencialmente linear (para cima e para baixo).
</details>

<details><summary>2D</summary>
✖️ Incorreto — o elevador não se move em duas dimensões.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong> e indicação visual de direção (subir/descer), bem como informação para quem aguarda.

<ul><li>[atuadores]

<details><summary>marcação de andares</summary>
✔️ Correto — o agente decide em que andares o elevador deve parar.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não controla diretamente o motor do elevador.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Aceite parcialmente — é o meio de comunicação, mas não o atuador principal.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, de modo a saber em que andares aguardam pessoas.

<ul><li>[sensores]

<details><summary>detetor de presença</summary>
✔️ Correto — identifica pessoas à espera nos andares.
</details>

<details><summary>visão</summary>
✖️ Aceite parcialmente — possível, mas não referido no enunciado.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não é mencionado.
</details>

<details><summary>sensores de proximidade</summary>
✖️ Incorreto — não são usados para identificar pessoas nos andares.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — o sistema pode ter sensores em todos os andares.</details>
  <details><summary>Parcialmente</summary>✖️ Incorreto — não há zonas ocultas relevantes.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — não se sabe quando chegam pessoas aos andares.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o fluxo de pessoas é imprevisível.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — as decisões dependem de estados anteriores.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o sistema toma decisões em sequência.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — enquanto o agente decide, o estado não muda instantaneamente.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — não há alterações rápidas durante o processo de decisão.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Correto — as decisões são discretas (parar ou não parar num andar).</details>
  <details><summary>Contínuo</summary>✖️ Incorreto — não há variáveis contínuas relevantes.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — um único agente controla todo o sistema.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — mesmo com vários elevadores, a gestão é centralizada.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 16/17 Agente: Robô Automático para Arar Solos -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um robô automático para arar solos antes de se iniciar uma plantação.  
Para o solo ficar bem areado, o robô deve passar 3 vezes pelo mesmo local, não se podendo mover com inclinação superior a 15%, nem entrar em terreno rochoso.  
Ao ser ativado num dado terreno, o robô irá procurar arar todo o solo a que puder ter acesso a partir do ponto inicial.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> dispendidas a arar.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo gasto a arar contraria o objetivo de eficiência.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo necessário para arar toda a área acessível.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>as horas</summary>
✔️ Correto — o tempo dispendido a arar é naturalmente expresso em horas.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não mede tempo de operação.
</details>

<details><summary>os metros</summary>
✖️ Aceite parcialmente — mede distância percorrida, mas não tempo.
</details>

<details><summary>os metros quadrados</summary>
✖️ Aceite parcialmente — mede área arada, mas não tempo dispendido.
</details>

<details><summary>o número</summary>
✖️ Incorreto — demasiado genérico.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não corresponde ao indicador pretendido.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>uma viagem</summary>
✖️ Incorreto — o robô não realiza “viagens”.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se o robô operar diariamente.
</details>

<details><summary>uma sessão</summary>
✔️ Correto — cada sessão de aragem pode ser medida individualmente.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para medir aragem.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, tendo em atenção zonas onde o agente pode passar mas não serve para arar (estradas) e zonas que não pode destruir (cercas).

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o robô opera numa superfície bidimensional (campo agrícola).
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas a navegação é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Aceite parcialmente — existe tempo, mas a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, e ativação/desativação da operação de arar.

<ul><li>[atuadores]

<details><summary>parte motora</summary>
✔️ Correto — permite deslocação e controlo da operação de arar.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o robô move‑se em 2D, não apenas linearmente.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o robô não voa.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um atuador físico.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, GPS, giroscópio e sensores de proximidade.

<ul><li>[sensores]

<details><summary>visão</summary>
✔️ Aceite — pode ser útil para identificar obstáculos e terreno.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são mencionados no enunciado.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o robô só observa a zona onde se encontra.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — o terreno não é totalmente observável.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o comportamento do solo e obstáculos pode ser imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — a aragem exige continuidade e planeamento.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o robô deve seguir um trajeto coerente para cobrir toda a área.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — o terreno e as minas não mudam enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — não há alterações rápidas no ambiente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — o terreno é contínuo.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o robô opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Aceite — se considerado como robô individual.</details>
  <details><summary>Multiagente</summary>✔️ Aceite — se vários robôs cooperarem na aragem.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 15/16 Agente: Gestor de Stock Alimentar numa Habitação -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente gestor de stock alimentar numa habitação.  
Os produtos consumidos e os que chegam do supermercado passam pela bancada, onde o sistema possui webcams para identificação dos produtos.  
O agente é responsável por gerar automaticamente uma encomenda quando o stock desce abaixo de certos limites.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> que existe um produto em falta no stock.  
Poderá existir uma restrição no número de produtos que se estragam por não serem consumidos.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo com produtos em falta contraria o objetivo do agente.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo em que existe rutura de stock.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>as horas</summary>
✔️ Correto — o tempo médio sem stock pode ser expresso em horas por semana.
</details>

<details><summary>a percentagem</summary>
✖️ Aceite parcialmente — percentagem de tempo sem stock é possível, mas menos operacional.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem rutura de stock.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de ruturas é quantificável, mas não mede duração.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o indicador.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Aceite — pode medir ruturas diariamente.
</details>

<details><summary>uma semana</summary>
✔️ Correto — é o período mais adequado para medir ruturas de stock.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não há viagens definidas.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para medir stock.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com os produtos adquiridos e consumidos ao longo do tempo.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o ambiente não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o agente observa produtos numa superfície (bancada).
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — os produtos têm volume, mas a tarefa é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Aceite parcialmente — há tempo, mas a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, para efetuar as encomendas dos produtos.

<ul><li>[atuadores]

<details><summary>Interface da aplicação</summary>
✔️ Correto — o agente atua enviando encomendas através da interface.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se move.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

<details><summary>parte motora</summary>
✖️ Incorreto — o agente não manipula fisicamente os produtos.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, para detetar os produtos adquiridos ou consumidos.

<ul><li>[sensores]

<details><summary>webcam</summary>
✔️ Correto — as webcams identificam os produtos na bancada.
</details>

<details><summary>visão</summary>
✔️ Aceite — categoria geral do sensor.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são usados para identificar produtos.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — o agente vê tudo o que passa pela bancada.</details>
  <details><summary>Parcialmente</summary>✖️ Incorreto — não há zonas ocultas relevantes para a tarefa.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✔️ Correto — identificar produtos e gerar encomendas não envolve incerteza significativa.</details>
  <details><summary>Aleatório</summary>✖️ Incorreto — não há fatores imprevisíveis relevantes.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✔️ Correto — cada produto é identificado independentemente dos anteriores.</details>
  <details><summary>Sequencial</summary>✖️ Incorreto — não há dependência entre momentos.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — o ambiente não muda enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — não há alterações rápidas no ambiente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Correto — os produtos são entidades discretas.</details>
  <details><summary>Contínuo</summary>✖️ Aceite parcialmente — o tempo é contínuo, mas a tarefa é discreta.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — há apenas um agente a gerir o stock.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há cooperação entre agentes.</details>
</li>

</ul>

</div>


<!-- Agente Recurso 14/15 Agente: Vigilância com Webcams em Centro Comercial -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que processa imagens obtidas através de webcams num centro comercial, e procura a identificação de uma lista pré‑determinada de pessoas, gerando alertas na segurança no caso de localizar uma pessoa da lista.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de acerto (se existir uma pessoa da lista, o alerta é gerado; caso contrário, não é).  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de acertos, isto é, gerar alertas corretos sempre que uma pessoa da lista aparece.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar acertos não faz sentido para um sistema de vigilância.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de acerto é naturalmente expressa em percentagem.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número absoluto de acertos é quantificável, mas não expressa proporcionalidade.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem deteção.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não mede qualidade de deteção.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o indicador.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um ficheiro</summary>
✔️ Correto — o agente processa ficheiros de imagem ou vídeo como unidades de trabalho.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se houver vários ficheiros ao longo do dia.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não há viagens definidas.
</details>

<details><summary>um minuto</summary>
✖️ Aceite parcialmente — demasiado curto para medir desempenho global.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com imagens capturadas em diversos locais ao longo do tempo.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — não representa imagens.
</details>

<details><summary>2D</summary>
✔️ Correto — as imagens são bidimensionais.
</details>

<details><summary>3D</summary>
✖️ Incorreto — o agente não usa profundidade tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Aceite parcialmente — há tempo, mas a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, para obter as imagens capturadas.

<ul><li>[atuadores]

<details><summary>disparar alarme</summary>
✔️ Correto — o agente atua emitindo alertas.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Aceite — é o meio pelo qual o alerta é enviado.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não se move.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, para emitir o alerta da presença de uma pessoa da lista e respetivo local.

<ul><li>[sensores]

<details><summary>webcam</summary>
✔️ Correto — as webcams são o sensor principal.
</details>

<details><summary>visão</summary>
✔️ Aceite — visão é a categoria geral do sensor.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são usados neste sistema.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — o agente observa tudo o que as webcams captam; esse é o universo relevante.</details>
  <details><summary>Parcialmente</summary>✖️ Aceite parcialmente — apenas se as webcams fossem móveis.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✔️ Correto — acionar o alarme não envolve incerteza.</details>
  <details><summary>Aleatório</summary>✖️ Incorreto — não há ações com resultados imprevisíveis.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✔️ Correto — cada imagem pode ser analisada isoladamente.</details>
  <details><summary>Sequencial</summary>✖️ Incorreto — não há dependência entre momentos.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — pessoas movem‑se continuamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — imagens são discretas.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — representam realidade contínua.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — há apenas um agente central.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — webcams não são agentes.</details>
</li>

</ul>

</div>


<!-- Agente Normal 21/22 Agente: Sistema de Condução que Replica o Estilo do Condutor  -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente de condução que replica o estilo de condução de um condutor, recebendo para tal o histórico de condução desse condutor.  
O objetivo é que o agente conduza de forma semelhante ao condutor original, considerando tempos, forças G aplicadas, consumo de combustível e comportamento geral.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de desvio relativamente à referência em termos de tempo, forças G e combustível gasto.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o desvio significaria conduzir pior do que o condutor de referência.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o desvio relativamente ao estilo do condutor real.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — o desvio pode ser expresso como percentagem relativamente ao estilo de referência.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem desvio de estilo de condução.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo isolado não mede desvio global.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede estilo de condução.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de desvios possíveis, mas não expressa proporcionalidade.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o indicador.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>uma viagem</summary>
✔️ Correto — o estilo pode ser avaliado por viagem.
</details>

<details><summary>um dia</summary>
✔️ Aceite — possível se houver várias viagens no mesmo dia.
</details>

<details><summary>um minuto</summary>
✖️ Incorreto — demasiado curto para avaliar estilo de condução.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto — não é o contexto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com estradas, faixas, cruzamentos, passeios, outros veículos, objetos e estado da estrada.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o veículo navega numa superfície bidimensional.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas a navegação é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, buzina e luzes.

<ul><li>[atuadores]

<details><summary>direção, aceleração, travagem</summary>
✔️ Correto — são os atuadores principais de um agente de condução.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente controla mais do que deslocação linear.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o veículo não voa.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um atuador físico.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, sensores de proximidade, sistema de captação e posicionamento nas faixas de rodagem, e posicionamento de outros veículos.

<ul><li>[sensores]

<details><summary>visão</summary>
✔️ Correto — câmaras são essenciais para identificar faixas, veículos e objetos.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são mencionados no enunciado.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não vê toda a estrada.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — só observa o que está ao alcance dos sensores.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — piso escorregadio ou falhas mecânicas tornam o ambiente imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o resultado das ações pode variar devido a fatores externos.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — a condução é contínua e depende de ações anteriores.</details>
  <details><summary>Sequencial</summary>✔️ Correto — seguir um trajeto exige decisões sucessivas.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda constantemente.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — veículos, objetos e condições variam enquanto o agente pensa.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — posição e movimento são contínuos.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o agente opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — o agente conduz um único veículo.</details>
  <details><summary>Multiagente</summary>✖️ Aceite parcialmente — apenas se fosse um sistema de condução de frota.</details>
</li>

</ul>

</div>



<!-- Agente Normal 20/21 Agente: Robôs para Desminagem de Minas Pessoais -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um conjunto de robôs construído especificamente para desativar <b>minas pessoais</b>.  
As minas pessoais são dispositivos explosivos simples, baratos e muito sensíveis, colocados no solo durante conflitos armados, permanecendo ativos durante décadas.  
O objetivo dos robôs é desminar áreas suspeitas, rebentando ou inativando as minas, garantindo a segurança do terreno.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> do raio do círculo desminado, centrado no ponto fornecido.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a área desminada, garantindo que não ficam “buracos” por explorar.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar o raio desminado contraria o objetivo do agente.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Aceite parcialmente — o raio pode ser expresso em metros, mas não representa diretamente área desminada.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não expressa raio ou área.
</details>

<details><summary>os metros quadrados</summary>
✔️ Correto — a área desminada é naturalmente expressa em m².
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de minas desativadas é um indicador possível, mas não mede continuidade espacial.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não mede área desminada.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não corresponde ao indicador pretendido.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um dia</summary>
✔️ Correto — a área desminada pode ser medida diariamente.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não há “viagens” definidas.
</details>

<details><summary>um minuto</summary>
✖️ Aceite parcialmente — demasiado curto para medir desminagem.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, terreno variado com possíveis minas pessoais.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o robô opera numa superfície bidimensional (terreno).
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas a navegação é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, gerar pressão extra para rebentar a mina (ou ativar o processo de inativação).

<ul><li>[atuadores]

<details><summary>parte motora</summary>
✔️ Correto — permite deslocação e aplicação de pressão sobre o solo.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o robô move‑se em 2D, não apenas linearmente.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o robô não voa.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um atuador físico.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, posição GPS e deteção de rebentamento de mina.

<ul><li>[sensores]

<details><summary>sensores de proximidade</summary>
✔️ Correto — ajudam a identificar irregularidades e possíveis minas.
</details>

<details><summary>visão</summary>
✔️ Aceite — pode ser útil para mapear terreno.
</details>

<details><summary>webcam</summary>
✔️ Aceite — forma concreta de visão.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o robô só observa a zona onde se encontra.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — o terreno não é totalmente observável.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o comportamento do solo e das minas é imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — a desminagem exige continuidade e planeamento.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o robô deve explorar posições em sequência, evitando buracos.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — as minas permanecem no mesmo local durante décadas.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — o ambiente não muda enquanto o agente pensa.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — o terreno é contínuo.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o robô opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Aceite — se considerado como sistema central.</details>
  <details><summary>Multiagente</summary>✔️ Aceite — vários robôs cooperam.</details>
</li>

</ul>

</div>



<!-- Agente Normal 19/20 Agente: Robôs da Polícia para Manter Recolher Obrigatório -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um conjunto de robôs da polícia, cujo objetivo é manter o recolher obrigatório numa zona citadina, imobilizando qualquer pessoa que o viole.  
As pessoas imobilizadas são depois detidas pela polícia e conduzidas a casa.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> que as pessoas estão fora de casa.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✖️ Incorreto — maximizar o tempo fora de casa contraria o objetivo do agente.
</details>

<details><summary>Minimizar</summary>
✔️ Correto — pretende‑se minimizar o tempo médio entre a deteção e a imobilização.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem tempo de resposta.
</details>

<details><summary>as horas</summary>
✔️ Aceite — o tempo médio até imobilização pode ser expresso em horas (ou minutos).
</details>

<details><summary>a percentagem</summary>
✖️ Aceite parcialmente — percentagem de pessoas detidas é um indicador possível, mas não o principal.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — número de pessoas detidas é quantificável, mas não reflete tempo de resposta.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com o objetivo.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>uma viagem</summary>
✖️ Incorreto — não há viagens definidas.
</details>

<details><summary>um dia</summary>
✔️ Correto — o desempenho pode ser medido diariamente.
</details>

<details><summary>um minuto</summary>
✔️ Aceite — o tempo médio de resposta pode ser medido em janelas curtas.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, em cidade, com ruas, passeios, pessoas e todo o tipo de obstáculos (móveis e imóveis).

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o robô navega numa superfície bidimensional (ruas e passeios).
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — há relevo, mas a navegação é essencialmente 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, parte sonora para aviso sonoro e sistema de imobilização do indivíduo em fuga.

<ul><li>[atuadores]

<details><summary>parte motora</summary>
✔️ Correto — permite deslocação e imobilização.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o robô move‑se em 2D, não apenas linearmente.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o robô não voa.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um atuador físico.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, navegação (GPS) e sensores de toque.

<ul><li>[sensores]

<details><summary>visão</summary>
✔️ Correto — o robô precisa de visão para identificar pessoas e obstáculos.
</details>

<details><summary>webcam</summary>
✔️ Aceite — é uma forma concreta de visão.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são mencionados no enunciado.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o robô não vê toda a cidade.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — só observa o que está ao alcance dos sensores.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o comportamento das pessoas é imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o estado seguinte não depende apenas das ações do agente.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>
✖️ Incorreto — as ações têm dependência temporal.
</details>
  <details><summary>Sequencial</summary>
✔️ Correto — patrulhar e imobilizar requerem ações em sequência.
</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda constantemente.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — pessoas e obstáculos movem‑se enquanto o agente pensa.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — a posição e movimento são contínuos.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o robô opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Aceite — se considerado como sistema central.</details>
  <details><summary>Multiagente</summary>✔️ Aceite — vários robôs cooperam.</details>
</li>

</ul>

</div>


<!-- Agente Normal 18/19 Agente: Sistema de Vigilância em Pombos com Webcams -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um sistema de vigilância de webcams colocadas nos pombos de uma cidade, para deteção de todo o tipo de infrações (assaltos a bancos, infrações de tráfego, passagem dos peões fora da passadeira, etc.).  
O sistema providencia à polícia uma lista de evidências de infrações por ordem de gravidade, não controlando naturalmente o trajeto dos pombos.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de infrações graves detetadas no momento, relativamente às gravadas (detetadas mais tarde).  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de infrações graves detetadas em tempo real, antes de perder a oportunidade de agir.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar deteções graves não faz sentido para um sistema de vigilância.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de deteção correta em tempo real é expressa em percentagem.
</details>

<details><summary>o número</summary>
✖️ Aceite parcialmente — mede infrações, mas não distingue entre detetadas no momento e detetadas tarde demais.
</details>

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem deteção de infrações.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não expressa qualidade de deteção.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com deteção de infrações.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>uma viagem</summary>
✖️ Incorreto — os pombos não têm “viagens” definidas.
</details>

<details><summary>um dia</summary>
✔️ Correto — é razoável medir a eficácia diária do sistema.
</details>

<details><summary>um minuto</summary>
✔️ Aceite — o feedback indica que o sistema pode operar em janelas curtas (1 minuto).
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um assunto</summary>
✖️ Incorreto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>.  
Pombos em movimento pela cidade, de forma não controlada, captando imagens ao longo do tempo e em diversas posições.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento dos pombos não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o sistema observa a cidade como um plano bidimensional.
</details>

<details><summary>3D</summary>
✖️ Aceite parcialmente — os pombos voam em 3D, mas o agente só usa imagens projetadas em 2D.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto — não é necessário modelar altitude para a tarefa.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, de modo a reportar a lista de infrações a enviar para a polícia.

<ul><li>[atuadores]

<details><summary>lista de infrações</summary>
✔️ Correto — o agente apenas produz relatórios; não controla os pombos.
</details>

<details><summary>movimento lateral</summary>
✖️ Incorreto — o agente não controla o movimento dos pombos.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — o agente não controla voo.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Aceite parcialmente — é o meio de envio, mas não o atuador conceptual.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong> e GPS.

<ul><li>[sensores]

<details><summary>webcam</summary>
✔️ Correto — as câmaras nos pombos são o sensor principal.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são usados neste sistema.
</details>

<details><summary>GPS</summary>
✖️ Aceite parcialmente — é um sensor, mas já está indicado fora da lacuna.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente só vê o que as webcams captam.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — a cidade não é totalmente observável.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o agente não controla o movimento dos pombos nem o que ocorre na cidade.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o ambiente é imprevisível.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✔️ Aceite — cada imagem ou sequência curta pode ser analisada isoladamente.</details>
  <details><summary>Sequencial</summary>✔️ Aceite — pode manter alertas ativos por algum tempo.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — a cidade muda enquanto o agente pensa.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — eventos surgem e desaparecem rapidamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Aceite — imagens são discretas.</details>
  <details><summary>Contínuo</summary>✔️ Aceite — representam realidade contínua.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — o processamento é centralizado.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — os pombos não são agentes independentes.</details>
</li>

</ul>

</div>



<!-- Agente Normal 17/18 Agente: Sistema de Navegação Automóvel -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um sistema de navegação automóvel, que aconselha o condutor sobre o melhor trajeto, tendo informações de tráfego e condições das vias.  
O sistema pode cruzar tempos realizados face aos previstos (acerto de velocidade acima/abaixo do esperado nas vias rápidas/lentas) e registar comportamento do condutor para melhorar o trajeto aconselhado.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de conselhos seguidos.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a percentagem de conselhos seguidos, pois isso indica que o sistema está a fornecer recomendações úteis.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar conselhos seguidos não faz sentido para um sistema de navegação.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem adesão a conselhos.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não expressa adesão ao aconselhamento.
</details>

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de conselhos seguidos é naturalmente expressa em percentagem.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com navegação.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✔️ Correto — também é possível medir o número absoluto de conselhos seguidos.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um assunto</summary>
✖️ Incorreto — não representa um período de medição.
</details>

<details><summary>uma viagem</summary>
✔️ Correto — o desempenho pode ser medido por viagem.
</details>

<details><summary>um dia</summary>
✔️ Correto — também é possível medir a adesão média diária.
</details>

<details><summary>um torneio</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com um mapa de estradas, informações externas e internas ao veículo, viagens e alertas/conselhos dados ao condutor.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o sistema opera num mapa bidimensional de estradas.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong> para aconselhamento de trajeto e propostas de desvios.

<ul><li>[atuadores]

<details><summary>aconselhamento de trajeto</summary>
✔️ Correto — o agente atua emitindo recomendações e desvios alternativos.
</details>

<details><summary>movimento linear</summary>
✖️ Incorreto — o agente não controla o movimento do veículo.
</details>

<details><summary>movimentação terrestre</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é o atuador principal, apenas o meio de comunicação.
</details>

<details><summary>movimentação aérea</summary>
✖️ Incorreto — não se aplica.
</details>

<details><summary>atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, informações externas (tráfego e condições das vias) e internas (velocidades médias adotadas pelo condutor vs previstas).

<ul><li>[sensores]

<details><summary>GPS</summary>
✔️ Correto — o GPS fornece posição e velocidade, essenciais para o sistema.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — não é referido no enunciado.
</details>

<details><summary>sensores de presença</summary>
✖️ Incorreto — não são relevantes para navegação.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um sensor.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — o agente tem acesso a toda a informação relevante disponível.</details>
  <details><summary>Parcialmente</summary>✖️ Incorreto — não há limitações significativas de perceção no contexto descrito.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — o condutor pode não seguir o conselho.</details>
  <details><summary>Aleatório</summary>✔️ Correto — o resultado das ações depende do comportamento imprevisível do condutor.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — decisões anteriores influenciam as seguintes.</details>
  <details><summary>Sequencial</summary>✔️ Correto — a viagem envolve decisões sucessivas.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✔️ Correto — o ambiente não muda enquanto o agente calcula um conselho.</details>
  <details><summary>Dinâmico</summary>✖️ Incorreto — o ambiente muda, mas não durante o processo de decisão imediata.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Correto — um trajeto é uma escolha discreta entre alternativas.</details>
  <details><summary>Contínuo</summary>✖️ Incorreto — não se trata de controlo contínuo do veículo.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — apenas um agente aconselha o condutor.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há interação com outros agentes.</details>
</li>

</ul>

</div>


<!-- Agente Normal 16/17 Agente: Sistema de Condução Ferroviária Automatizado -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um sistema de condução de transportes ferroviários totalmente automatizado, sem maquinistas humanos.  
O sistema possui diversos sensores que permitem a abertura/fecho de portas em segurança e permitem também a circulação de carruagens sem acidentes.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> em média que as pessoas estão no sistema de transportes.  
Poderá existir uma restrição no número de viagens com poucas pessoas (prejuízo).  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar o número médio de pessoas transportadas, garantindo eficiência e reduzindo viagens com baixa ocupação.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar o número de passageiros significaria operar com prejuízo e baixa utilização.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem ocupação de passageiros.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não expressa número médio de passageiros.
</details>

<details><summary>a percentagem</summary>
✔️ Correto — a taxa média de ocupação pode ser expressa em percentagem.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com transporte ferroviário.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede ocupação.
</details>

<details><summary>o número</summary>
✖️ Incorreto — demasiado genérico; não expressa média relativa.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um assunto</summary>
✖️ Incorreto — não representa um período de medição.
</details>

<details><summary>uma viagem</summary>
✔️ Correto — a média de ocupação pode ser medida por viagem.
</details>

<details><summary>um dia</summary>
✔️ Correto — também é possível medir a ocupação média diária.
</details>

<details><summary>um torneio</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, com a rede ferroviária e estações.

<ul><li>[dimensões]

<details><summary>1D</summary>
✔️ Correto — o movimento ferroviário é essencialmente linear ao longo das linhas.
</details>

<details><summary>2D</summary>
✖️ Incorreto — embora a rede possa ramificar, o movimento do agente é linear.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há navegação tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — a dimensão relevante é a linear.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, com possibilidade de mudança de linha em certos pontos e abertura/fecho de portas (controlado pelo subsistema).

<ul><li>[atuadores]

<details><summary>movimento linear</summary>
✔️ Correto — o agente controla aceleração, travagem e deslocação linear ao longo da linha.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

<details><summary>Movimentação terrestre</summary>
✖️ Incorreto — demasiado genérico; não descreve atuadores ferroviários.
</details>

<details><summary>Movimentação aérea</summary>
✖️ Incorreto — o agente não voa.
</details>

<details><summary>Atuador específico</summary>
✖️ Incorreto — demasiado vago.
</details>

<details><summary>Movimentação em espaço controlado</summary>
✖️ Incorreto — não descreve o controlo ferroviário.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, de modo a quantificar o número de pessoas nas gares.

<ul><li>[sensores]

<details><summary>sensores de presença</summary>
✔️ Correto — permitem contar pessoas nas plataformas.
</details>

<details><summary>webcam</summary>
✖️ Incorreto — possível, mas não indicado no enunciado.
</details>

<details><summary>GPS</summary>
✖️ Incorreto — não é usado para contar pessoas nas gares.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não observa toda a rede simultaneamente.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — observa apenas o que os sensores captam.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✔️ Correto — o movimento ferroviário é altamente previsível e controlado.</details>
  <details><summary>Aleatório</summary>✖️ Incorreto — não há fatores externos significativos que alterem o movimento.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — decisões anteriores influenciam as seguintes.</details>
  <details><summary>Sequencial</summary>✔️ Correto — o sistema opera continuamente ao longo do tempo.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda com entradas e saídas de passageiros.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — o fluxo de passageiros e carruagens varia constantemente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✔️ Correto — estados como “parado”, “em movimento”, “porta aberta” são discretos.</details>
  <details><summary>Contínuo</summary>✖️ Incorreto — não é necessário lidar com variáveis contínuas como posição analógica.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — o enunciado considera apenas um sistema de controlo.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há competição ou cooperação entre agentes.</details>
</li>

</ul>

</div>




<!-- Agente Normal 15/16 Agente: Quadricóptero Fotográfico Autónomo -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um quadricóptero (helicóptero com 4 motores) com o objetivo de tirar fotografias de uma zona o mais alargada possível.  
Tem uma autonomia limitada, podendo recarregar voltando à base, e possui um sistema autónomo que lhe permite manter uma altura segura e evitar colisões.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> que leva a fazer a cobertura fotográfica, considerando a sua autonomia.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a área fotografada, aproveitando ao máximo a autonomia disponível.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar a área fotografada contraria o objetivo do agente.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não representam área.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não mede cobertura fotográfica.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não expressa área coberta.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não corresponde ao indicador pretendido.
</details>

<details><summary>os metros quadrados</summary>
✔️ Correto — a área coberta é expressa em metros quadrados.
</details>

<details><summary>o número</summary>
✖️ Incorreto — demasiado genérico para medir cobertura.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um assunto</summary>
✖️ Incorreto — não representa um período de medição.
</details>

<details><summary>uma viagem</summary>
✔️ Correto — cada viagem do quadricóptero constitui uma unidade de medição da área coberta.
</details>

<details><summary>um dia</summary>
✔️ Correto — também é possível medir a área total coberta por dia, caso existam várias viagens.
</details>

<details><summary>um torneio</summary>
✖️ Incorreto — não se aplica ao contexto.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>uma corrida/jogo</summary>
✖️ Incorreto.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, uma vez que a altura está controlada por outro sistema.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o sistema principal apenas decide deslocações laterais na superfície a fotografar.
</details>

<details><summary>3D</summary>
✖️ Incorreto — a altitude é controlada por outro subsistema.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, voltar para a base / reabastecer / levantar voo.

<ul><li>[atuadores]

<details><summary>movimento lateral</summary>
✔️ Correto — o agente apenas indica deslocações laterais, já que altitude e colisões são tratadas por outro sistema.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

<details><summary>Movimentação terrestre</summary>
✖️ Incorreto — o agente é aéreo.
</details>

<details><summary>Movimentação linear</summary>
✖️ Incorreto — não descreve adequadamente o movimento lateral no plano.
</details>

<details><summary>Atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

<details><summary>Movimentação aérea</summary>
✖️ Incorreto — o movimento aéreo é controlado pelo subsistema, não pelo agente principal.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, GPS.

<ul><li>[sensores]

<details><summary>webcam</summary>
✔️ Correto — o quadricóptero usa câmaras para recolher fotografias.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

<details><summary>Sensores de presença</summary>
✖️ Incorreto — não são relevantes para a tarefa de cobertura fotográfica.
</details>

<details><summary>Visão</summary>
✖️ Incorreto — demasiado genérico; o sensor real é a webcam.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não vê toda a área de uma só vez.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — só observa a zona onde se encontra.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — vento e desvios automáticos tornam o movimento imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — as ações podem ter resultados diferentes devido a fatores externos.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — a sequência de movimentos influencia a cobertura.</details>
  <details><summary>Sequencial</summary>✔️ Correto — várias ações sucessivas são necessárias para fotografar toda a área.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda ao longo do tempo.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — condições e elementos visuais variam continuamente.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — posição e movimento são contínuos.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o agente opera num espaço real analógico.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — apenas um quadricóptero é considerado.</details>
  <details><summary>Multiagente</summary>✖️ Incorreto — não há competição ou cooperação com outros agentes.</details>
</li>

</ul>

</div>



<!-- Agente Normal 14/15 Agente: Carro de Corridas Autónomo -->

<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Considere um agente que é um carro de corridas em circuitos fechados, autónomo.  
O agente tem conhecimento das regras de corrida, que são impostas levando à desclassificação do agente se for envolvido numa violação das regras, sendo o objetivo final a obtenção da melhor classificação no final da corrida.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como:  
<strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> da posição final na classificação.  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — pretende‑se maximizar a posição média final (ou seja, obter classificações melhores ao longo das corridas).
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar a posição significaria procurar classificações piores, o que não faz sentido para um agente competitivo.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem desempenho competitivo.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não expressa diretamente a classificação final.
</details>

<details><summary>a percentagem</summary>
✖️ Incorreto — percentagem não representa a posição final na corrida.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com classificação.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✔️ Correto — a posição final é expressa numericamente (1.º, 2.º, 3.º…).
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um assunto</summary>
✖️ Incorreto — não representa um período de medição.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não corresponde ao contexto de corridas.
</details>

<details><summary>um dia</summary>
✖️ Incorreto — o desempenho é medido por corrida, não por dia.
</details>

<details><summary>um torneio</summary>
✖️ Incorreto — possível noutros contextos, mas aqui o período é a corrida individual.
</details>

<details><summary>uma zona</summary>
✖️ Incorreto — zona não é um período.
</details>

<details><summary>uma corrida/jogo</summary>
✔️ Correto — o desempenho é medido por corrida.
</details>

<details><summary>um incêndio</summary>
✖️ Incorreto.
</details>

<details><summary>um ficheiro</summary>
✖️ Incorreto — não se trata de processamento de ficheiros.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, um circuito fechado, com as posições dos carros adversários em movimento.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — o movimento não é linear.
</details>

<details><summary>2D</summary>
✔️ Correto — o carro move‑se numa superfície bidimensional (pista).
</details>

<details><summary>3D</summary>
✖️ Incorreto — a tarefa não envolve navegação tridimensional.
</details>

<details><summary>2D+1D</summary>
✖️ Incorreto — embora exista tempo, a dimensão relevante é a espacial.
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>.

<ul><li>[atuadores]

<details><summary>Direção, aceleração, travagem</summary>
✔️ Correto — são os atuadores que permitem controlar o carro.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

<details><summary>Movimentação aérea</summary>
✖️ Incorreto — o carro não voa.
</details>

<details><summary>Movimentação linear</summary>
✖️ Incorreto — o movimento não é apenas linear.
</details>

<details><summary>Atuador específico</summary>
✖️ Incorreto — demasiado genérico.
</details>

<details><summary>Movimentação em espaço controlado</summary>
✖️ Incorreto — não descreve atuadores reais do carro.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, sensores de proximidade, GPS, velocímetro.

<ul><li>[sensores]

<details><summary>Webcam</summary>
✔️ Correto — câmaras são usadas para perceção visual da pista e adversários.
</details>

<details><summary>Interface da aplicação</summary>
✖️ Incorreto — não é um agente de software.
</details>

<details><summary>Sensores de presença</summary>
✖️ Incorreto — não são adequados para corridas.
</details>

<details><summary>Visão</summary>
✖️ Incorreto — demasiado genérico; o sensor real é a webcam.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✖️ Incorreto — o agente não vê toda a pista.</details>
  <details><summary>Parcialmente</summary>✔️ Correto — só observa o que os sensores captam.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✖️ Incorreto — fatores externos tornam o ambiente imprevisível.</details>
  <details><summary>Aleatório</summary>✔️ Correto — vento, piso, colisões e outros fatores afetam o resultado.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✖️ Incorreto — ações anteriores influenciam as seguintes.</details>
  <details><summary>Sequencial</summary>✔️ Correto — a corrida é uma sequência contínua de decisões.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto — o ambiente muda constantemente.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — posições e condições variam ao longo do tempo.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto — posição, velocidade e trajetória são contínuas.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o ambiente envolve variáveis contínuas.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✖️ Incorreto — há vários carros com objetivos conflitantes.</details>
  <details><summary>Multiagente</summary>✔️ Correto — trata‑se de uma corrida com vários participantes.</details>
</li>

</ul>

</div>


<!--  Fim da lista  -->

</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_introducao2.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_introducao.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

<script>
document.addEventListener("DOMContentLoaded", function() {
  const todas = Array.from(document.querySelectorAll("#todas-perguntas .pergunta"));
  const idx = Math.floor(Math.random() * todas.length);
  const destino = document.getElementById("perguntas-escolhidas");
  destino.appendChild(todas[idx]);
});
</script>

\endhtmlonly
