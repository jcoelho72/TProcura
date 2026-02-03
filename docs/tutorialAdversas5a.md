@page tutorial_adversas5a Procuras Adversas - Introdução

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 Introdução</span>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>

<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/803548145" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP5A.pdf)


\htmlonly

<div id="todas-perguntas" style="display:none;">

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que distingue um ambiente multiagente de um ambiente uni‑agente?</summary>
👉 Num ambiente multiagente existem vários agentes a atuar, cada um com os seus próprios objetivos, e as ações de um influenciam o resultado dos outros.
Num ambiente uni‑agente, o agente interage apenas com o ambiente, sem adversários nem colaboradores.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que tratar os outros agentes como “acaso” pode degradar a performance?</summary>
👉 Porque esta simplificação ignora que os outros agentes também tentam maximizar a sua utilidade.
Assumi‑los como aleatórios leva a decisões subótimas, já que o agente não antecipa ações adversas intencionais.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que significa um jogo ser de soma nula?</summary>
👉 Significa que a soma das utilidades dos jogadores é constante: o ganho de um corresponde exatamente à perda do outro.
Se um vence, o outro perde.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que jogos como dominó ou cartas são considerados jogos de soma nula, mas não são determinísticos?</summary>
👉 Porque o resultado depende tanto das ações dos jogadores como de elementos aleatórios, como a distribuição das peças ou cartas.
A soma das utilidades continua constante, mas o ambiente deixa de ser determinístico.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que caracteriza um jogo parcialmente observável?</summary>
👉 Cada jogador conhece apenas parte do estado do jogo.
Por exemplo, nas cartas ou dominó, cada jogador vê apenas as suas peças, não as dos adversários.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a presença de aleatoriedade altera o tipo de procura necessária?</summary>
👉 Porque o agente deixa de poder prever exatamente o resultado das ações.
Em vez de um único estado sucessor, existem distribuições de probabilidade, exigindo algoritmos que lidem com incerteza.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Dá um exemplo de situação multiagente episódica.</summary>
👉 Um concurso em que cada agente apresenta uma proposta numa única ronda.
Não há sequência de ações, mas continua a existir competição entre agentes.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que jogos dinâmicos e contínuos são difíceis para IA clássica?</summary>
👉 Porque o estado muda continuamente enquanto o agente delibera, e o espaço de estados é infinito ou muito grande,
dificultando a modelação e a procura exaustiva.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No jogo do galo, como se determina quem joga numa dada posição?</summary>
👉 Contando o número de marcas no tabuleiro: se X e O têm o mesmo número de marcas, joga X; caso contrário, joga O.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No jogo do galo, o que define uma ação válida?</summary>
👉 Uma ação é válida se a posição (linha, coluna) escolhida estiver vazia. Caso contrário, a ação leva ao estado impossível.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que acontece quando se tenta aplicar uma ação inválida?</summary>
👉 O modelo de transição devolve o estado impossível, indicando que a ação não pode ser aplicada ao estado atual.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Quais são as duas condições que determinam o fim do jogo do galo?</summary>
👉 O jogo termina quando não há casas vazias ou quando existe uma linha, coluna ou diagonal com três marcas iguais.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como é atribuída a utilidade num jogo de soma nula como o jogo do galo?</summary>
👉 Vitória → utilidade 1 para o vencedor e 0 para o perdedor.
Empate → utilidade igual para ambos, tipicamente 0.5.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o espaço de estados do jogo do galo inclui posições impossíveis?</summary>
👉 Porque a definição matemática permite qualquer combinação de marcas, mesmo que não possa ser atingida seguindo as regras (por exemplo, dois X seguidos sem O).
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como se obtêm os sucessores de um estado?</summary>
👉 Aplicando todas as ações válidas ao estado atual através do modelo de transição.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que distingue uma árvore de jogo de uma árvore de procura normal?</summary>
👉 Numa árvore de jogo, cada nível corresponde a um jogador diferente, alternando entre agentes adversos.
Numa procura normal, todas as ações pertencem ao mesmo agente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que se eliminam simetrias na árvore de jogo?</summary>
👉 Para reduzir o número de estados equivalentes, evitando analisar posições que são iguais por rotação ou reflexão,
tornando a procura mais eficiente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o X tem apenas 3 ações distintas no primeiro movimento?</summary>
👉 Porque todas as 9 posições possíveis são simétricas entre si, reduzindo-se a 3 classes equivalentes: canto, centro e lateral.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a alternância de jogadores é essencial na procura adversa?</summary>
👉 Porque cada jogador tenta maximizar a sua utilidade, e a decisão ótima depende das ações futuras do adversário,
não apenas das próprias.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que raramente é possível analisar toda a árvore de jogo?</summary>
👉 Porque o número de estados cresce exponencialmente com a profundidade,
tornando inviável explorar todas as possibilidades num jogo realista.
</details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a análise individual de cada agente é impraticável quando o número de agentes é muito elevado?</summary>
👉 Porque o número de combinações possíveis de ações cresce de forma explosiva, tornando impossível modelar ou prever o comportamento de cada agente isoladamente. Nestes casos, só é viável analisar efeitos globais, como acontece na economia. </details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Em que situação pode ser aceitável tratar outros agentes como aleatórios?</summary>
👉 Quando o comportamento dos outros agentes é imprevisível ou irrelevante para o objetivo principal, e a perda de precisão não compromete significativamente a performance do agente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que caracteriza um ambiente adverso em termos de objetivos dos agentes?</summary>
👉 Os agentes têm objetivos incompatíveis: maximizar o ganho próprio implica reduzir o ganho do adversário. Cada ação é tomada antecipando a resposta do outro.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que jogos parcialmente observáveis são mais difíceis para IA?</summary>
👉 Porque o agente não tem acesso ao estado completo do ambiente, sendo obrigado a raciocinar sobre estados possíveis, incerteza e informação oculta.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que puzzles não requerem procura adversa?</summary>
👉 Porque não existe adversário. O agente controla todas as ações e o ambiente não reage com objetivos próprios.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como se representa formalmente o estado inicial do jogo do galo?</summary>
👉 Como uma função que associa a cada posição da grelha 3×3 o valor “vazio”.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a função jog(s) depende apenas da contagem de marcas?</summary>
👉 Porque a alternância entre X e O é determinada unicamente pelo número de jogadas já feitas, dispensando regras adicionais.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é útil ter um estado “impossível” no modelo de transição?</summary>
👉 Para representar formalmente ações que violam as regras, permitindo que o algoritmo trate erros de forma consistente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o teste de fim de jogo pode exigir funções auxiliares?</summary>
👉 Porque verificar condições como “três em linha” ou “não há casas vazias” pode exigir percorrer o tabuleiro ou verificar padrões específicos.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a utilidade pode não ser de soma constante?</summary>
👉 Porque em muitos jogos ou cenários multiagente, o ganho de um jogador não implica necessariamente a perda proporcional do outro.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o espaço de estados inclui posições que nunca ocorrem num jogo real?</summary>
👉 Porque a definição matemática é genérica e não impõe restrições sobre a ordem das jogadas, permitindo combinações impossíveis como dois X seguidos.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual a relação entre ações possíveis e sucessores?</summary>
👉 Cada sucessor corresponde ao resultado de aplicar uma ação válida ao estado atual. A lista de sucessores é derivada diretamente das ações.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a alternância de jogadores torna a árvore de jogo diferente da árvore de procura clássica?</summary>
👉 Porque cada nível da árvore corresponde a um agente distinto, com objetivos diferentes, o que altera a forma como os valores são propagados.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual é a vantagem de eliminar estados simétricos?</summary>
👉 Reduz drasticamente o número de estados a analisar, sem perder informação relevante, tornando a procura mais eficiente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o jogador O tem 5 jogadas distintas após X jogar num canto?</summary>
👉 Porque várias respostas possíveis são simétricas entre si, restando apenas 5 posições realmente diferentes.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o algoritmo de procura adversa é independente do jogo?</summary>
👉 Porque opera sobre estados abstratos e funções genéricas (jog, ações, utilidade), não dependendo das regras específicas do jogo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a utilidade é essencial na procura adversa?</summary>
👉 Porque permite avaliar estados terminais e orientar a escolha de ações que maximizam o resultado esperado para o agente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como a informação oculta afeta a estratégia num jogo?</summary>
👉 O agente deve considerar múltiplos estados possíveis, aumentando a incerteza e exigindo raciocínio probabilístico.
</details>

</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversaslit.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_adversas5b.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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

