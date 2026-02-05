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

<ul>
<li>O <b>indicador de desempenho</b> é definido como: <strong>[Maximizar/Minimizar]</strong> <strong>[unidade]</strong> de acerto (se existir uma pessoa da lista, o alerta é gerado, não sendo gerado c.c.).
Período de medição: <strong>[período]</strong>.</li>
<li>O ambiente tem dimensão <strong>[dimensões]</strong>, correspondendo a imagens capturadas em vários locais ao longo do tempo.</li>
<li>Os atuadores são <strong>[atuadores]</strong>, usados para obter as imagens capturadas. </li>
<li>Os sensores são <strong>[sensores]</strong>, usados para emitir o alerta da presença de uma pessoa na lista, e respetivo local. </li>
</ul>

<table style="width:100%; border-collapse:collapse; text-align:center;">
<tr> <th>[Maximizar/Minimizar]</th> <th>[unidade]</th> <th>[período]</th></tr>
<tr> <td>

<!-- Pergunta [Maximizar/Minimizar] -->
<details>
  <summary>◉ Maximizar</summary>
  ✔️ Correto — o objetivo é maximizar a percentagem de acerto.
</details>

<details>
  <summary>◉ Minimizar</summary>
  ✖️ Incorreto — não se pretende reduzir acertos.
</details>
</td><td>

<!-- Pergunta [unidade] -->
<details>
  <summary>◉ os metros</summary>
  ✖️ Incorreto — não mede desempenho.
</details>

<details>
  <summary>◉ as horas</summary>
  ✖️ Incorreto — não expressa qualidade de deteção.
</details>

<details>
  <summary>◉ a percentagem</summary>
  ✔️ Correto — a taxa de acerto é naturalmente expressa em percentagem.
</details>

<details>
  <summary>◉ as horas vezes a área</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ os metros quadrados</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ o número</summary>
  ✖️ Incorreto — não expressa qualidade.
</details>
</td><td>

<!-- Pergunta [período] -->
<details>
  <summary>◉ um assunto</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ uma viagem</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ um dia</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ um torneio</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ uma zona</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ uma corrida/jogo</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ um incêndio</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ um ficheiro</summary>
  ✔️ Correto — o agente processa um ficheiro de imagens.
</details>
</li></ul>

</td></tr>

<tr> <th>[dimensões]</th> <th>[atuadores]</th> <th>[sensores]</th></tr>

<tr><td>

<!-- Pergunta [dimensões] -->
<details>
  <summary>◉ 1D</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ 2D</summary>
  ✖️ Incorreto — falta a componente temporal.
</details>

<details>
  <summary>◉ 3D</summary>
  ✖️ Incorreto — não há perceção volumétrica.
</details>

<details>
  <summary>◉ 2D+1D</summary>
  ✔️ Correto — imagens (2D) ao longo do tempo (1D).
</details>

<details>
  <summary>◉ 3D+1D</summary>
  ✖️ Incorreto.
</details>

</td><td>

<!-- Pergunta [atuadores] -->
<details>
  <summary>◉ Interface da aplicação</summary>
  ✔️ Correto — o agente emite alertas via interface.
</details>

<details>
  <summary>◉ Movimentação terrestre</summary>
  ✖️ Incorreto — o agente não se move fisicamente.
</details>

<details>
  <summary>◉ Movimentação linear</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ Movimentação estrada</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ Movimentação em espaço controlado</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ Atuador específico</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ Movimentação aérea</summary>
  ✖️ Incorreto.
</details>

</td><td>

<!-- Pergunta [sensores] -->
<details>
  <summary>◉ Visão</summary>
  ✖️ Incorreto — o agente não “vê”, recebe ficheiros.
</details>

<details>
  <summary>◉ Sensores de presença</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ GPS</summary>
  ✖️ Incorreto.
</details>

<details>
  <summary>◉ Interface da aplicação</summary>
  ✔️ Correto — recebe as imagens via interface.
</details>

</td></tr>
</table>

<hr>

<h3>Classificação do ambiente</h3>

<table style="width:100%; border-collapse:collapse; text-align:center;">
<tr> <th>Observável</th> <th>Determinismo</th> <th>Episódico / Sequencial</th></tr>
<tr><td>
      <details><summary>◉ Completamente</summary>✔️ Correto.</details>
      <details><summary>◉ Parcialmente</summary>✖️ Incorreto.</details>
</td><td>
      <details><summary>◉ Determinístico</summary>✔️ Correto.</details>
      <details><summary>◉ Estocástico</summary>✖️ Incorreto.</details>
</td><td>
      <details><summary>◉ Episódico</summary>✔️ Correto.</details>
      <details><summary>◉ Sequencial</summary>✖️ Incorreto.</details>
</td></tr>
<tr> <th>Estático / Dinâmico</th> <th>Discreto / Contínuo</th> <th>Agentes</th></tr>
<tr><td>
      <details><summary>◉ Estático</summary>✖️ Incorreto.</details>
      <details><summary>◉ Dinâmico</summary>✔️ Correto.</details>
</td><td>
      <details><summary>◉ Discreto</summary>✖️ Incorreto.</details>
      <details><summary>◉ Contínuo</summary>✔️ Correto.</details>
</td><td>
      <details><summary>◉ Uni‑Agente</summary>✔️ Correto.</details>
      <details><summary>◉ Multi‑Agente</summary>✖️ Incorreto.</details>
</td></tr>
</table>

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
