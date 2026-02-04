@page tutorial_construtivas3a 👓 Procuras Construtivas - Procura Cega

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_construtivas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Construtivas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="opacity:0.7;">Algoritmos Cegos ›</span>
    <a href="tutorial_construtivaslit.html" style="color:#9cf;">📖 Leitura</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 Procura Cega</span>
    <a href="tutorial_construtivas3b.html" style="color:#9cf;">👓 Algoritmos</a>
    <span style="opacity:0.7;">Aspirador ›</span>
    <a href="teste_aspirador1.html" style="color:#9cf;">💻 Parte 1</a>
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


<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/803549264" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso  -->


</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP3A.pdf)

\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um problema de procura?</summary> 👉 Um problema de procura exige que o agente encontre uma solução através de uma sequência de ações que o leve de um estado inicial até um estado objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que os algoritmos cegos são chamados de não informados?</summary> 👉 Porque não utilizam qualquer informação adicional além da definição do problema; não têm conhecimento sobre que ações são melhores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa dizer que um estado é indivisível?</summary> 👉 Significa que o algoritmo trata o estado como uma unidade completa, sem decomposição interna ou estrutura adicional. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Em que condições o agente consegue validar se um estado é objetivo?</summary> 👉 Quando existe uma função teste ou um conjunto de estados finais que permite verificar se o estado satisfaz o objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que os algoritmos cegos precisam de explorar estados seguintes?</summary> 👉 Porque não têm informação sobre qual ação é melhor, sendo necessário explorar para descobrir um caminho até ao objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa o ambiente ser completamente observável?</summary> 👉 Significa que o agente consegue ver todo o estado do ambiente, como no exemplo do labirinto onde vê todas as bifurcações. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que implica o ambiente ser determinístico?</summary> 👉 Implica que cada ação leva sempre ao mesmo estado seguinte, sem aleatoriedade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que um ambiente sequencial exige uma sequência de ações?</summary> 👉 Porque o agente precisa de tomar várias decisões ao longo do tempo para atingir o estado final. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa o ambiente ser estático?</summary> 👉 Significa que o ambiente não muda enquanto o agente delibera sobre as ações a tomar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o ambiente deve ser discreto num problema de procura?</summary> 👉 Porque o número de estados e ações deve ser finito para permitir a procura. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que deve responder a definição do objetivo?</summary> 👉 Deve indicar claramente o que se pretende atingir, sem envolver grandezas a maximizar ou minimizar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual a diferença entre definir o objetivo por função teste ou por conjunto de estados finais?</summary> 👉 A função teste verifica se um estado é final; o conjunto de estados finais lista explicitamente todos os estados que satisfazem o objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representa o estado inicial?</summary> 👉 Representa a situação atual do agente e deve pertencer ao espaço de estados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são ações possíveis num problema de procura?</summary> 👉 São as decisões que o agente pode tomar a partir de um estado, definindo como pode progredir. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é que não existe um problema de procura?</summary> 👉 Quando não existem decisões a tomar; nesse caso o agente apenas segue o estado sem alternativas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que faz o modelo de transição?</summary> 👉 Dado um estado e uma ação, devolve o estado resultante dessa ação. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que pode acontecer se uma ação não for aplicável a um estado?</summary> 👉 O modelo de transição deve devolver um estado que represente impossibilidade, que não deve ser considerado sucessor. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como se define o custo de uma ação?</summary> 👉 Através de uma função que atribui um valor numérico ao custo de passar de um estado para outro. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a função sucessores?</summary> 👉 É a função que devolve todos os estados alcançáveis a partir de um estado aplicando cada ação possível. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Para que serve definir o espaço de estados explicitamente?</summary> 👉 Para compreender a dimensão do problema e garantir que todos os estados possíveis estão bem definidos. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são restrições num problema de procura?</summary> 👉 São condições que eliminam estados ou soluções que não interessam ou que não conduzem ao objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como podem as restrições melhorar a procura?</summary> 👉 Eliminando estados inúteis cedo, reduzindo o espaço de procura e o tempo necessário. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o processo de abstração?</summary> 👉 É omitir detalhes irrelevantes para manter o problema tratável, mantendo apenas o essencial. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é importante ver o problema de vários pontos de vista?</summary> 👉 Para garantir que a especificação está correta e que o problema modelado corresponde ao que se pretende resolver. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque devemos começar pelas perguntas mais fáceis ao definir um problema?</summary> 👉 Porque ajudam a clarificar o essencial e facilitam a tomada de decisões nas partes mais complexas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é útil definir custos diferentes para ações?</summary> 👉 Quando o desempenho do agente depende do custo total da solução, permitindo distinguir soluções ótimas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que demasiados detalhes tornam o problema proibitivo?</summary> 👉 Porque aumentam exponencialmente o espaço de estados, tornando a procura impraticável. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa um caminho num problema de procura?</summary> 👉 É uma sequência de estados ligados por ações sucessivas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como se relacionam sucessores e modelo de transição?</summary> 👉 A função sucessores pode ser construída aplicando o modelo de transição a todas as ações possíveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é preferível definir sucessores em vez de ações e modelo de transição?</summary> 👉 Quando as ações são complexas e é mais simples listar diretamente os estados seguintes. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como é representado um estado no problema do aspirador?</summary> 👉 Como um triplo contendo a posição do agente e a situação (suja/limpa) de cada uma das duas casas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é o objetivo no problema do aspirador?</summary> 👉 Ter ambas as casas limpas, independentemente da posição do agente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como é representado o espaço de estados no Puzzle 8?</summary> 👉 Como um triplo de triplos contendo uma permutação dos números 0 a 8, onde 0 representa o espaço vazio. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que restrição simples pode ser aplicada ao Puzzle 8?</summary> 👉 Impedir movimentos inversos consecutivos, como esq seguido de dir. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como é representado um estado no problema das 8 damas?</summary> 👉 Como um tuplo de 8 valores, cada um indicando a linha onde a dama dessa coluna está colocada. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que restrição impede que duas damas se ataquem?</summary> 👉 Não podem estar na mesma linha, nem na mesma coluna e diagonal. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que define o estado inicial no problema da partição?</summary> 👉 Um conjunto de números por colocar, com os conjuntos da esquerda e direita vazios. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é o objetivo no problema da partição?</summary> 👉 Colocar todos os números de forma que a soma dos dois lados seja igual. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque se coloca sempre o maior número primeiro na partição?</summary> 👉 Porque os números pequenos encaixam mais facilmente e isso reduz estados redundantes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são os dados da instância no problema da partição?</summary> 👉 O conjunto inicial de números a dividir, que não precisa de ser duplicado na árvore de procura. </details>

</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_construtivaslit.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_construtivas3b.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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
