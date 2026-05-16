@page tutorial_adversas5b Procuras Adversas - MiniMax

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <a href="tutorial_adversas5a.html" style="color:#9cf;">👓 Introdução</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 MiniMax</span>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>

<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/827644802" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

<div id="todas-perguntas" style="display:none;">

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual é o objetivo principal do algoritmo MiniMax?</summary>
👉 Determinar a melhor ação para o jogador atual, assumindo que todos os jogadores jogam de forma ótima, retornando também a utilidade esperada.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que em jogos de soma nula a utilidade pode ser representada por um único número?</summary>
👉 Porque o ganho de um jogador corresponde exatamente à perda do outro, permitindo representar o estado com um valor único positivo ou negativo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que faz o MiniMax quando recebe um estado final?</summary>
👉 Retorna imediatamente a utilidade desse estado e nenhuma ação, terminando a recursão.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o MiniMax analisa todas as ações válidas?</summary>
👉 Para garantir que encontra a melhor jogada possível, considerando todas as alternativas do jogador e do adversário.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como o MiniMax decide qual ação é a melhor?</summary>
👉 Compara as utilidades resultantes de cada ação e escolhe a que maximiza a utilidade do jogador atual.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o MiniMax é considerado uma procura em profundidade?</summary>
👉 Porque explora cada ramo da árvore até ao fim antes de voltar atrás, tal como a procura em profundidade clássica.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o MiniMax não pára quando encontra uma solução?</summary>
👉 Porque precisa avaliar todas as alternativas para garantir que a solução encontrada é realmente a melhor possível.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o MiniMax pode usar uma utilidade por jogador?</summary>
👉 Em jogos com mais de dois jogadores, cada jogador tem objetivos próprios, exigindo uma utilidade separada para cada um.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo de 2 jogadores, porque é que o primeiro ramo retorna verde?</summary>
👉 Porque todos os estados finais desse ramo correspondem a vitória do jogador 2, logo essa é a utilidade propagada.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo de 2 jogadores, porque é que o jogador 1 escolhe o terceiro movimento no exemplo?</summary>
👉 Porque esse movimento conduz à utilidade mais favorável para si, comparando com as alternativas anteriores.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que representam as cores laranja, verde e cinzento no exemplo de 2 jogadores?</summary>
👉 Laranja representa vitória do jogador 1, verde vitória do jogador 2 e cinzento um empate.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo de 3 jogadores, como decide o jogador 3?</summary>
👉 Escolhe sempre o estado que maximiza a sua própria utilidade, ignorando as utilidades dos outros jogadores.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que existem 6 resultados possíveis no exemplo de 3 jogadores?</summary>
👉 Porque cada jogador pode vencer, empatar ou perder, originando combinações distintas de resultados.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O MiniMax muda quando há 3 jogadores?</summary>
👉 A lógica é a mesma, mas cada jogador maximiza a sua própria utilidade, e a comparação é feita apenas sobre o valor desse jogador.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que representam alfa e beta no MiniMax com cortes?</summary>
👉 Representam as melhores alternativas já conhecidas para cada jogador, usadas para decidir quando cortar ramos.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Quando ocorre um corte alfa/beta?</summary>
👉 Quando um jogador adversário já tem uma alternativa melhor ou igual ao valor atual, tornando inútil explorar mais ações.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que os cortes alfa/beta poupam tempo?</summary>
👉 Porque evitam explorar ramos que não podem alterar a decisão final, reduzindo o número de estados analisados.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o alfa inicial pode ser a vitória do adversário?</summary>
👉 Porque representa a pior alternativa possível para o jogador MAX, servindo como limite inferior.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o beta inicial pode ser a vitória do jogador MAX?</summary>
👉 Porque representa a pior alternativa possível para o jogador MIN, servindo como limite superior.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Quando é que alfa ou beta são atualizados?</summary>
👉 Quando o jogador atual encontra uma utilidade melhor do que a sua melhor alternativa conhecida.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o segundo ramo do exemplo MiniMaxAB é cortado?</summary>
👉 Porque o jogador 2 já tem uma alternativa verde, melhor do que o cinzento encontrado, tornando inútil explorar mais.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo MiniMaxAB, porque é que alguns estados do nível 3 são cortados imediatamente?</summary>
👉 Porque o valor encontrado é pior do que a melhor alternativa do adversário, ativando a condição de corte.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que ordenar sucessores melhora o desempenho do MiniMaxAB?</summary>
👉 Porque explorar primeiro os melhores movimentos aumenta a probabilidade de cortes mais cedo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No MiniMaxAB ordenado, porque é que a ordem correta poupa mais estados?</summary>
👉 Porque os melhores valores surgem mais cedo, permitindo cortar ramos inteiros antes de os explorar.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é necessário limitar a profundidade na procura adversa?</summary>
👉 Porque a árvore de jogo cresce exponencialmente e é impraticável explorá‑la totalmente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que significa relaxar o problema para criar uma heurística?</summary>
👉 Simplificar o problema, por exemplo assumindo que só um jogador joga, para estimar a distância até ao objetivo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que são características relevantes numa heurística?</summary>
👉 Elementos do estado que influenciam a utilidade, como material no xadrez ou ameaças no jogo do galo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que ameaças a 1 jogada têm peso maior?</summary>
👉 Porque exigem resposta imediata e têm impacto direto no resultado, devendo influenciar mais a avaliação.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a heurística pode oscilar no meio de uma troca?</summary>
👉 Porque o estado avaliado reflete apenas a jogada atual, sem considerar a resposta do adversário.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que é a zona de estabilidade na procura limitada?</summary>
👉 Uma região onde a heurística deixa de variar significativamente, permitindo parar a expansão.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque restringir movimentos após o limite de profundidade?</summary>
👉 Para analisar apenas ações que alteram significativamente a heurística, evitando ruído.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual é a principal vantagem da procura iterativa?</summary>
👉 Permite usar o melhor resultado disponível dentro do tempo limite, aprofundando progressivamente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a procura iterativa melhora os cortes alfa/beta?</summary>
👉 Porque usa os valores da iteração anterior para ordenar sucessores, aumentando a eficiência dos cortes.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como uma hashtable ajuda na procura iterativa?</summary>
👉 Evita recalcular estados já avaliados, reutilizando resultados entre iterações.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o centro tem valor mais alto na heurística do jogo do galo?</summary>
👉 Porque uma marca no centro cria mais ameaças e aumenta as possibilidades de vitória.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque considerar ameaças a 2 jogadas?</summary>
👉 Porque indicam potencial estratégico futuro, mesmo que não sejam imediatas.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O MiniMaxAB altera o resultado final quando comparado com o MiniMax?</summary>
👉 Não, apenas reduz o número de estados analisados; o resultado é o mesmo do MiniMax completo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que a ordem dos sucessores não altera o resultado?</summary>
👉 Porque o algoritmo continua a considerar todas as alternativas relevantes; apenas muda a eficiência.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que acontece se a profundidade for demasiado pequena?</summary>
👉 A heurística pode avaliar estados demasiado superficiais, levando a decisões fracas.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que heurísticas são essenciais em jogos reais?</summary>
👉 Porque a árvore completa é demasiado grande para ser explorada, exigindo estimativas para orientar a procura.
</details>

</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP5B.pdf)

\htmlonly


<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>


<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversas5a.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_adversas5c.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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

