@page tutorial_introducao2 👓 Introdução - Conceito de Agente

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 Conceito de Agente</span>
    <a href="tutorial_introducao2exe.html" style="color:#9cf;">✏️ Exercícios</a>
  </div>
</div>



<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/803549764" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso  -->

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um agente?</summary> 👉 Algo que está num ambiente, capta esse ambiente através de sensores e atua sobre ele através de atuadores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representam os sensores num agente?</summary> 👉 São os mecanismos que permitem ao agente observar o ambiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representam os atuadores num agente?</summary> 👉 São os mecanismos que permitem ao agente modificar o ambiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que determina as ações que o agente executa?</summary> 👉 O que o agente consegue observar através dos seus sensores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é que um agente é considerado racional?</summary> 👉 Quando executa a ação correta com base no conhecimento que tem. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é necessário definir o que é “correto” para avaliar racionalidade?</summary> 👉 Porque sem um critério de sucesso não é possível justificar que o comportamento é racional. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que sensores tem o agente aspirador apresentado?</summary> 👉 Sabe em que quarto está e se o quarto está limpo ou sujo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que ações pode executar o agente aspirador?</summary> 👉 Mover para a esquerda, mover para a direita e aspirar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o agente aspirador pode ser considerado racional?</summary> 👉 Porque limpa ambos os quartos rapidamente, independentemente do estado inicial. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o agente aspirador pode não ser racional em certas condições?</summary> 👉 Porque sem um indicador de performance definido, não se sabe se o comportamento é realmente o melhor. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um indicador de performance?</summary> 👉 Uma medida quantificável que avalia o sucesso da tarefa do agente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o indicador de performance deve ser operacional?</summary> 👉 Porque deve ser fácil de medir na prática. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que deve refletir o indicador de performance?</summary> 👉 Os objetivos do agente e eventuais restrições importantes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é importante definir o período de medição do indicador?</summary> 👉 Para garantir comparações justas entre agentes ou execuções. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é necessário indicar se o indicador deve ser maximizado ou minimizado?</summary> 👉 Para saber qual comportamento é preferível e avaliar racionalidade. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o ambiente de um agente?</summary> 👉 O contexto no qual o agente atua e realiza a sua tarefa. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como se determina a dimensão do ambiente?</summary> 👉 Pelo número de dimensões relevantes para o movimento ou atuação do agente (1D, 2D, 3D, +1D). </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que um elevador é considerado um ambiente 1D?</summary> 👉 Porque se move apenas linearmente entre andares. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que um automóvel é considerado um ambiente 2D?</summary> 👉 Porque se movimenta numa superfície com liberdade de direção. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando se adiciona +1D à dimensão do ambiente?</summary> 👉 Quando o tempo é um fator relevante para a tarefa. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza os atuadores de um agente?</summary> 👉 Permitem ao agente modificar o ambiente de acordo com a sua tarefa. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Dê um exemplo de atuador num agente de software.</summary> 👉 Geração de ficheiros ou envio de emails. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza os sensores de um agente?</summary> 👉 Permitem observar o que é relevante no ambiente para a tarefa. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Dê um exemplo de sensor num agente de elevador.</summary> 👉 Sensores que detetam o número de pessoas à espera num andar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é importante descrever bem sensores e atuadores?</summary> 👉 Porque determinam o que o agente pode observar e como pode agir. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente completamente observável?</summary> 👉 Aquele em que o agente consegue observar todo o estado relevante. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente parcialmente observável?</summary> 👉 Aquele em que o agente só observa parte do estado relevante. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue um ambiente determinístico de um aleatório?</summary> 👉 No determinístico, o próximo estado depende apenas da ação; no aleatório, existem fatores imprevisíveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente episódico?</summary> 👉 Um ambiente onde cada cenário é independente do anterior. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente sequencial?</summary> 👉 Um ambiente onde ações anteriores influenciam ações futuras. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente estático?</summary> 👉 Um ambiente que não muda enquanto o agente pensa. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente dinâmico?</summary> 👉 Um ambiente que pode mudar enquanto o agente decide. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue ambientes discretos de contínuos?</summary> 👉 Discretos têm estados finitos e bem definidos; contínuos têm valores contínuos como posição e orientação. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente uni‑agente?</summary> 👉 Um ambiente onde apenas um agente influencia o desempenho. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente multiagente?</summary> 👉 Um ambiente onde existem outras entidades com objetivos próprios, colaborativos ou adversários. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um agente reflexo simples?</summary> 👉 Atua com base em regras que dependem apenas da percepção atual. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um agente reflexo com modelo?</summary> 👉 Mantém memória interna do estado e usa-a para decidir ações. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um agente por objetivo?</summary> 👉 Utiliza um objetivo explícito e métodos de procura para encontrar uma solução. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um agente de utilidade?</summary> 👉 Usa uma função de utilidade para comparar soluções e escolher a melhor. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes de utilidade são mais flexíveis?</summary> 👉 Porque permitem modelar compromissos entre objetivos e escolher a solução com maior valor global. </details>


</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP2.pdf)

\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->


</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_introducao2lit.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_introducao2exe.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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
