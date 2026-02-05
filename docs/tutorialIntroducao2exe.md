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

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que processa imagens obtidas através de webcams num centro comercial, e procura a identificação de uma lista pré‑determinada de pessoas, gerando alertas para a segurança quando encontra alguém da lista.</p>

<hr>

<h4>1. Indicador de desempenho</h4>

<details>
  <summary>Minimizar</summary>
  ✖️ <strong>Incorreto.</strong> O objetivo não é reduzir algo, mas sim aumentar a taxa de acerto do sistema.
</details>

<details>
  <summary>Maximizar</summary>
  ✔️ <strong>Correto.</strong> O agente deve maximizar a percentagem de acerto na identificação das pessoas da lista.
</details>

<hr>

<h4>2. Unidade / período de medição</h4>

<details>
  <summary>os metros</summary>
  ✖️ <strong>Incorreto.</strong> A distância não é relevante para medir desempenho.
</details>

<details>
  <summary>as horas</summary>
  ✖️ <strong>Incorreto.</strong> O tempo pode ser útil para estatísticas, mas não mede diretamente o desempenho.
</details>

<details>
  <summary>a percentagem</summary>
  ✔️ <strong>Correto.</strong> A taxa de acerto é naturalmente expressa em percentagem.
</details>

<details>
  <summary>as horas vezes a área</summary>
  ✖️ <strong>Incorreto.</strong> Não é uma métrica significativa para este agente.
</details>

<details>
  <summary>os metros quadrados</summary>
  ✖️ <strong>Incorreto.</strong> A área monitorizada não mede desempenho.
</details>

<details>
  <summary>o número</summary>
  ✖️ <strong>Incorreto.</strong> Um número absoluto não expressa qualidade de deteção.
</details>

<hr>

<h4>3. Ambiente — dimensão</h4>

<details>
  <summary>2D</summary>
  ✖️ <strong>Incorreto.</strong> As imagens têm dimensão espacial, mas falta a componente temporal.
</details>

<details>
  <summary>3D</summary>
  ✖️ <strong>Incorreto.</strong> O agente não recebe informação volumétrica, apenas imagens.
</details>

<details>
  <summary>2D+1D</summary>
  ✔️ <strong>Correto.</strong> As imagens são 2D e chegam ao longo do tempo (1D temporal).
</details>

<details>
  <summary>1D</summary>
  ✖️ <strong>Incorreto.</strong> Não corresponde ao tipo de perceção do agente.
</details>

<hr>

<h4>4. Atuadores</h4>

<details>
  <summary>Interface da aplicação</summary>
  ✔️ <strong>Correto.</strong> O agente atua emitindo alertas através da interface.
</details>

<details>
  <summary>Movimentação terrestre</summary>
  ✖️ <strong>Incorreto.</strong> O agente não se desloca fisicamente.
</details>

<details>
  <summary>Movimentação linear</summary>
  ✖️ <strong>Incorreto.</strong> Não existe movimento físico.
</details>

<details>
  <summary>Movimentação estrada</summary>
  ✖️ <strong>Incorreto.</strong> Não é um agente móvel.
</details>

<details>
  <summary>Movimentação em espaço controlado</summary>
  ✖️ <strong>Incorreto.</strong> Não se aplica.
</details>

<details>
  <summary>Atuador específico</summary>
  ✖️ <strong>Incorreto.</strong> Não existe um atuador físico dedicado.
</details>

<details>
  <summary>Movimentação aérea</summary>
  ✖️ <strong>Incorreto.</strong> O agente não voa nem se move.
</details>

<hr>

<h4>5. Sensores</h4>

<details>
  <summary>Visão</summary>
  ✖️ <strong>Incorreto.</strong> O agente não “vê” diretamente — recebe imagens via interface.
</details>

<details>
  <summary>Sensores de presença</summary>
  ✖️ <strong>Incorreto.</strong> Não utiliza sensores físicos de presença.
</details>

<details>
  <summary>GPS</summary>
  ✖️ <strong>Incorreto.</strong> Não há localização geográfica envolvida.
</details>

<details>
  <summary>Interface da aplicação</summary>
  ✔️ <strong>Correto.</strong> O agente recebe as imagens através da interface.
</details>

<hr>

<h4>6. Classificação do ambiente</h4>

<details>
  <summary>Observável completamente</summary>
  ✔️ <strong>Correto.</strong> O agente recebe todas as imagens disponíveis; não há estado oculto relevante.
</details>

<details>
  <summary>Observável parcialmente</summary>
  ✖️ <strong>Incorreto.</strong> Embora existam ângulos mortos no mundo real, no modelo do problema o agente recebe toda a informação necessária.
</details>

<details>
  <summary>Determinístico</summary>
  ✔️ <strong>Correto.</strong> Dado o estado (imagem) e o algoritmo, o resultado é sempre o mesmo.
</details>

<details>
  <summary>Estocástico</summary>
  ✖️ <strong>Incorreto.</strong> Não há aleatoriedade no modelo.
</details>

<details>
  <summary>Episódico</summary>
  ✔️ <strong>Correto.</strong> Cada imagem pode ser tratada como um episódio independente.
</details>

<details>
  <summary>Sequencial</summary>
  ✖️ <strong>Incorreto.</strong> O agente não depende de estados anteriores para decidir.
</details>

<details>
  <summary>Dinâmico</summary>
  ✔️ <strong>Correto.</strong> O ambiente muda enquanto o agente processa (pessoas movem-se).
</details>

<details>
  <summary>Estático</summary>
  ✖️ <strong>Incorreto.</strong> O ambiente não permanece fixo.
</details>

<details>
  <summary>Contínuo</summary>
  ✔️ <strong>Correto.</strong> As imagens chegam continuamente ao longo do tempo.
</details>

<details>
  <summary>Discreto</summary>
  ✖️ <strong>Incorreto.</strong> Não há estados discretos bem definidos.
</details>

<details>
  <summary>Uni‑Agente</summary>
  ✔️ <strong>Correto.</strong> Apenas um agente está a atuar.
</details>

<details>
  <summary>Multi‑Agente</summary>
  ✖️ <strong>Incorreto.</strong> Não há outros agentes a interagir.
</details>

</div>


<div class="pergunta">

<p><strong>🧩 Exercício:</strong> Suponha que tem um agente que processa imagens obtidas através de webcams num centro comercial, e procura a identificação de uma lista pré‑determinada de pessoas, gerando alertas na segurança quando encontra alguém da lista.</p>

<hr>

<h3>Indicador de desempenho</h3>

<p>O indicador de desempenho é definido como: <em>Em branco 1</em> <strong>[Maximizar/Minimizar]</strong> <em>Em branco 2</em> <strong>[unidade]</strong> de acerto. Período de medição: <em>Em branco 3</em> <strong>[período]</strong>.</p>

<!-- Pergunta 1 -->
<details>
  <summary>◉ Maximizar</summary>
  ✔️ Correto — o objetivo é maximizar a percentagem de acerto.
</details>

<details>
  <summary>◉ Minimizar</summary>
  ✖️ Incorreto — não se pretende reduzir acertos.
</details>

<!-- Pergunta 2 -->
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

<!-- Pergunta 3 (período de medição) -->
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

<hr>

<h3>Ambiente</h3>

<p>O ambiente tem dimensão <em>Em branco 4</em> <strong>[1D / 2D / 3D / 2D+1D / 3D+1D]</strong>, correspondendo a imagens capturadas em vários locais ao longo do tempo.</p>

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

<hr>

<h3>Atuadores</h3>

<p>Os atuadores são <em>Em branco 5</em> <strong>[lista de atuadores]</strong>, usados para emitir alertas.</p>

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

<hr>

<h3>Sensores</h3>

<p>Os sensores são <em>Em branco 6</em> <strong>[lista de sensores]</strong>, usados para carregar as imagens.</p>

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

<hr>

<h3>Classificação do ambiente</h3>

<table style="width:100%; border-collapse:collapse; text-align:center;">
  <tr>
    <th>Observabilidade</th>
    <th>Determinismo</th>
    <th>Episódico / Sequencial</th>
    <th>Estático / Dinâmico</th>
    <th>Discreto / Contínuo</th>
    <th>Agentes</th>
  </tr>
  <tr>
    <td>
      <details><summary>◉ Observável completamente</summary>✔️ Correto.</details>
      <details><summary>◉ Observável parcialmente</summary>✖️ Incorreto.</details>
    </td>
    <td>
      <details><summary>◉ Determinístico</summary>✔️ Correto.</details>
      <details><summary>◉ Estocástico</summary>✖️ Incorreto.</details>
    </td>
    <td>
      <details><summary>◉ Episódico</summary>✔️ Correto.</details>
      <details><summary>◉ Sequencial</summary>✖️ Incorreto.</details>
    </td>
    <td>
      <details><summary>◉ Estático</summary>✖️ Incorreto.</details>
      <details><summary>◉ Dinâmico</summary>✔️ Correto.</details>
    </td>
    <td>
      <details><summary>◉ Discreto</summary>✖️ Incorreto.</details>
      <details><summary>◉ Contínuo</summary>✔️ Correto.</details>
    </td>
    <td>
      <details><summary>◉ Uni‑Agente</summary>✔️ Correto.</details>
      <details><summary>◉ Multi‑Agente</summary>✖️ Incorreto.</details>
    </td>
  </tr>
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
