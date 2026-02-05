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
    <a href="tutorial_introducao2exe.html" style="color:#9cf;">✏️ Exercícios</a>
  </div>
</div>

\endhtmlonly



## Exercícios

Análise de agentes.


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->


<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que processa imagens obtidas através de webcams num centro comercial, e procura a identificação de uma lista pré‑determinada de pessoas, gerando alertas na segurança quando encontra alguém da lista.</p>

<hr>

<p>Complete as seguintes frases para descrever o agente:</p>

<ul>

<!-- INDICADOR DE DESEMPENHO -->
<li>O <b>indicador de desempenho</b> é definido como: <strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de acerto (se existir uma pessoa da lista, o alerta é gerado, não sendo gerado caso contrário).  
Período de medição: <strong>[período]</strong>.

<ul>

<!-- Max/Min -->
<li>[Maximizar/Minimizar]

<details><summary>Maximizar</summary>
✔️ Correto — o objetivo é aumentar a taxa de acerto, ou seja, gerar alertas corretos sempre que uma pessoa da lista aparece.
</details>

<details><summary>Minimizar</summary>
✖️ Incorreto — minimizar acertos não faz sentido para um agente de deteção.
</details>
</li>

<!-- Unidade -->
<li>[unidade]

<details><summary>os metros</summary>
✖️ Incorreto — metros não medem qualidade de deteção.
</details>

<details><summary>as horas</summary>
✖️ Incorreto — tempo não expressa precisão do agente.
</details>

<details><summary>a percentagem</summary>
✔️ Correto — a taxa de acerto é naturalmente expressa em percentagem.
</details>

<details><summary>as horas vezes a área</summary>
✖️ Incorreto — não tem relação com deteção de pessoas.
</details>

<details><summary>os metros quadrados</summary>
✖️ Incorreto — área não mede desempenho.
</details>

<details><summary>o número</summary>
✖️ Incorreto — um número absoluto não expressa qualidade.
</details>
</li>

<!-- Período -->
<li>[período]

<details><summary>um assunto</summary>
✖️ Incorreto — não representa um período de medição.
</details>

<details><summary>uma viagem</summary>
✖️ Incorreto — não corresponde ao processamento de imagens.
</details>

<details><summary>um dia</summary>
✖️ Incorreto — possível, mas não é o período adequado para um ficheiro de imagens.
</details>

<details><summary>um torneio</summary>
✖️ Incorreto.
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
✔️ Correto — o agente processa um ficheiro de imagens como unidade de trabalho.
</details>
</li>

</ul>
</li>

<!-- AMBIENTE -->
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, correspondendo a imagens capturadas em vários locais ao longo do tempo.

<ul><li>[dimensões]

<details><summary>1D</summary>
✖️ Incorreto — não representa imagens.
</details>

<details><summary>2D</summary>
✖️ Incorreto — falta a componente temporal.
</details>

<details><summary>3D</summary>
✖️ Incorreto — não há perceção volumétrica.
</details>

<details><summary>2D+1D</summary>
✔️ Correto — imagens (2D) capturadas ao longo do tempo (1D).
</details>

<details><summary>3D+1D</summary>
✖️ Incorreto — não há dados tridimensionais.
</details>

</li></ul>
</li>

<!-- ATUADORES -->
<li>Os atuadores são <strong>[atuadores]</strong>, usados para emitir os alertas gerados pelo agente.

<ul><li>[atuadores]

<details><summary>Interface da aplicação</summary>
✔️ Correto — o agente comunica alertas através da interface.
</details>

<details><summary>Movimentação terrestre</summary>
✖️ Incorreto — o agente não se desloca fisicamente.
</details>

<details><summary>Movimentação linear</summary>
✖️ Incorreto.
</details>

<details><summary>Movimentação estrada</summary>
✖️ Incorreto.
</details>

<details><summary>Movimentação em espaço controlado</summary>
✖️ Incorreto.
</details>

<details><summary>Atuador específico</summary>
✖️ Incorreto — não existe atuador físico dedicado.
</details>

<details><summary>Movimentação aérea</summary>
✖️ Incorreto.
</details>

</li></ul>
</li>

<!-- SENSORES -->
<li>Os sensores são <strong>[sensores]</strong>, usados para carregar as imagens capturadas.

<ul><li>[sensores]

<details><summary>Visão</summary>
✖️ Incorreto — o agente não “vê”, recebe ficheiros.
</details>

<details><summary>Sensores de presença</summary>
✖️ Incorreto.
</details>

<details><summary>GPS</summary>
✖️ Incorreto.
</details>

<details><summary>Interface da aplicação</summary>
✔️ Correto — as imagens são carregadas via interface.
</details>

</li></ul>
</li>

</ul>

<hr>

<h3>Classificação do ambiente</h3>

<ul>

<li>Observável
  <details><summary>Completamente</summary>✔️ Correto — o agente recebe todas as imagens necessárias.</details>
  <details><summary>Parcialmente</summary>✖️ Incorreto.</details>
</li>

<li>Determinismo
  <details><summary>Determinístico</summary>✔️ Correto — o processamento é determinístico.</details>
  <details><summary>Estocástico</summary>✖️ Incorreto.</details>
</li>

<li>Episódico / Sequencial
  <details><summary>Episódico</summary>✔️ Correto — cada ficheiro é tratado como episódio independente.</details>
  <details><summary>Sequencial</summary>✖️ Incorreto.</details>
</li>

<li>Estático / Dinâmico
  <details><summary>Estático</summary>✖️ Incorreto.</details>
  <details><summary>Dinâmico</summary>✔️ Correto — as imagens representam eventos que evoluem no tempo.</details>
</li>

<li>Discreto / Contínuo
  <details><summary>Discreto</summary>✖️ Incorreto.</details>
  <details><summary>Contínuo</summary>✔️ Correto — o fluxo temporal das imagens é contínuo.</details>
</li>

<li>Agentes
  <details><summary>Uni‑Agente</summary>✔️ Correto — apenas um agente atua.</details>
  <details><summary>Multi‑Agente</summary>✖️ Incorreto.</details>
</li>

</ul>

</div>






</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_construtivas.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_construtivas3a.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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
