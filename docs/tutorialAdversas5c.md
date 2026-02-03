@page tutorial_adversas5c Procuras Adversas - Monte Carlo

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <a href="tutorial_adversas5a.html" style="color:#9cf;">👓 Introdução</a>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">👓 Monte Carlo</span>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>

<div style="display:flex; gap:20px;">
<iframe src="https://player.vimeo.com/video/827645296" width="300" height="169" frameborder="0" allow="fullscreen"></iframe>
</div>

<div id="todas-perguntas" style="display:none;">

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual é a ideia fundamental da procura Monte Carlo?</summary>
👉 Simular muitos jogos completos e escolher a ação com maior utilidade média.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Em que difere o Monte Carlo do MiniMax?</summary>
👉 O Monte Carlo não explora a árvore completa; baseia-se em simulações rápidas de jogos completos.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Quando a simulação de jogo termina?</summary>
👉 Quando se atinge um estado final, retornando a utilidade desse estado.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que é a política de jogo numa simulação Monte Carlo?</summary>
👉 A regra que define como escolher jogadas durante a simulação, podendo ser aleatória ou enviesada.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é útil manter alguma aleatoriedade na política de jogo?</summary>
👉 Para gerar jogos distintos e estimar melhor a probabilidade de vitória.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o Monte Carlo é vantajoso em jogos com elevada ramificação?</summary>
👉 Porque evita explorar a árvore completa, cujo tamanho cresce exponencialmente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como se calcula o valor de uma ação no Monte Carlo?</summary>
👉 Pela média das utilidades obtidas nas simulações dessa ação.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é importante simular muitos jogos?</summary>
👉 Para obter uma estimativa mais precisa da utilidade esperada.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque simular mais vezes as melhores ações?</summary>
👉 Para aumentar a precisão onde mais importa, sem desperdiçar tempo em ações fracas.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque construir uma pequena árvore antes das simulações?</summary>
👉 Para distribuir as simulações pelas ações possíveis e começar o jogo num estado mais profundo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo de Monte Carlo com 2 jogadores, como se escolhe o melhor lance?</summary>
👉 Somando os pontos das simulações (vitórias e empates) e escolhendo o lance com maior total.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Que pontuação foi usada para avaliar resultados no exemplo de Monte Carlo com 2 jogadores?</summary>
👉 Vitória vale 2 pontos e empate vale 1 ponto.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que fazer se uma simulação demorar demasiado?</summary>
👉 Interromper e atribuir empate para não atrasar o processo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é útil reutilizar simulações de lances fortes?</summary>
👉 Porque esses lances são mais prováveis de serem escolhidos na jogada seguinte.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o Monte Carlo funciona mesmo com políticas fracas?</summary>
👉 Porque a repetição de muitas simulações compensa decisões subótimas individuais.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como se calcula a utilidade no exemplo de Monte Carlo de 3 jogadores?</summary>
👉 Somando vitórias e empates para cada jogador, atribuindo 2 pontos por vitória e 1 por empate.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> No exemplo de Monte Carlo de 3 jogadores, porque é que o jogador 1 escolhe a terceira alternativa?</summary>
👉 Porque essa alternativa tem o maior total de pontos entre as simulações.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O Monte Carlo precisa de alterações para 3 jogadores?</summary>
👉 Não, apenas passa a somar utilidades para três jogadores em vez de dois.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que caracteriza um jogo com ambiente aleatório?</summary>
👉 A existência de eventos não controlados pelos jogadores, como lançar dados.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que é um nó de acaso numa árvore de jogo?</summary>
👉 Um estado onde ocorre um evento aleatório em vez de uma jogada de um jogador.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como o MiniMax trata um nó de acaso?</summary>
👉 Calcula a utilidade média das alternativas, em vez de maximizar ou minimizar.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque não há cortes alfa/beta em nós de acaso?</summary>
👉 Porque não há jogador a maximizar ou minimizar; não se aplicam limites de decisão.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o MiniMax sofre com aleatoriedade?</summary>
👉 Porque a ramificação aumenta muito, tornando a árvore demasiado grande.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque é que o Monte Carlo não é afetado pela aleatoriedade?</summary>
👉 Porque a simulação já é aleatória por natureza, e os nós de acaso são tratados como jogadas aleatórias.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como se calcula o valor de um nó de acaso no exemplo do MiniMax aleatório?</summary>
👉 Pela média dos resultados finais das alternativas desse nó.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o jogador 1 escolhe a segunda alternativa no exemplo do MiniMax aleatório?</summary>
👉 Porque essa alternativa tem a maior média de utilidade.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Como o Monte Carlo aleatório, trata um nó de acaso na simulação?</summary>
👉 Como uma jogada aleatória, tal como definido pela política de jogo.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> De que depende a precisão do Monte Carlo?</summary>
👉 Da qualidade da política de jogo e do número de simulações realizadas.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que caracteriza um jogo parcialmente observável?</summary>
👉 Parte do estado do jogo não é visível para alguns agentes.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o estado é um subconjunto de S, em jogos parcialmente observáveis?</summary>
👉 Porque o agente só sabe que pode estar em alguns estados, compatíveis com o que observa, não sabe o estado exato em que está.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque gerar sucessores é pesado em jogos parcialmente observáveis?</summary>
👉 Porque é necessário aplicar cada ação a todos os estados possíveis do subconjunto.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o MiniMax é impraticável em jogos parcialmente observáveis?</summary>
👉 Porque o número de estados possíveis cresce demasiado, tornando a árvore enorme.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o Monte Carlo também é impraticável nesses jogos?</summary>
👉 Porque seria necessário simular jogos para muitos estados possíveis, tornando o processo demasiado pesado.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> O que é um estado de crença?</summary>
👉 Uma estimativa do estado real, escolhida de entre os estados compatíveis com a informação observada.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Quando atualizar o estado de crença?</summary>
👉 Sempre que surgem novas evidências que eliminam estados possíveis.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o estado de crença é uma solução subótima?</summary>
👉 Porque assume apenas um estado possível, ignorando que o estado real pode ser um entre muitos possíveis.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Qual é o exemplo clássico de jogo parcialmente observável?</summary>
👉 Jogos de cartas, onde cada jogador desconhece as cartas dos adversários.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque o dominó é parcialmente observável?</summary>
👉 Porque cada jogador vê apenas as suas peças, não as dos outros.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Porque jogos parcialmente observáveis são considerados difíceis atualmente?</summary>
👉 Porque o volume de estados possíveis é enorme e difícil de gerir computacionalmente.
</details>

<details class="pergunta">
<summary><strong>⚡ Ação:</strong> Em que cenários o Monte Carlo é claramente superior ao MiniMax?</summary>
👉 Em jogos com elevada ramificação ou com elementos aleatórios, onde a árvore de jogo se torna demasiado grande.
</details>

</div>

\endhtmlonly

[📄 Ver slides (PDF)](PVP5C.pdf)

\htmlonly

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>


<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversas5b.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_galominimax.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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

