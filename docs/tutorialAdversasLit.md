@page tutorial_adversaslit Procuras Adversas - Literatura

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">📖 Literatura</span>
    <a href="tutorial_adversas5a.html" style="color:#9cf;">👓 Introdução</a>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <a href="tutorial_galominimax.html" style="color:#9cf;">✏️ Galo MiniMax</a>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>

\endhtmlonly


Algoritmos: MiniMax; Monte Carlo;

## 📖 Leituras

- (Russel & Norvig): Capítulo 5 ou 6, conforme edição (Procura Adversa)

## Bibliografia

-	Russell, S. J., & Norvig, P. (2021). Artificial intelligence: A modern approach (4th ed.). Pearson. http://aima.cs.berkeley.edu/


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quais são as três formas de encarar ambientes multiagente segundo o capítulo?</summary> 👉 Economia (agentes em grande número), agentes como parte estocástica do ambiente, e modelação explícita via procura adversa. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é inadequado modelar adversários como eventos aleatórios?</summary> 👉 Porque adversários têm intenção de derrotar o agente, ao contrário de fenómenos naturais. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que características têm os jogos mais estudados em IA?</summary> 👉 Determinísticos, dois jogadores, turn-taking, informação perfeita e soma zero. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quais são os elementos formais que definem um jogo?</summary> 👉 Estado inicial, jogador a mover, ações legais, modelo de transição, teste terminal e função utilidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um estado terminal?</summary> 👉 É um estado onde o jogo termina e a utilidade pode ser avaliada. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual o papel da função utilidade num jogo?</summary> 👉 Atribuir um valor numérico ao resultado final para cada jogador. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual a diferença entre árvore de procura e grafo do espaço de estados?</summary>
👉 A árvore de procura expande sequências de jogadas; o grafo do espaço de estado representa todos os estados possíveis, independentemente de uma sequência de jogo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a árvore de procura do xadrez é impraticável de explorar?</summary>
👉 Porque tem mais de 10⁴⁰ estados, tornando impossível percorrê-la totalmente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa uma estratégia ótima para MAX?</summary> 👉 Uma estratégia que maximiza a utilidade assumindo que MIN joga de forma ótima. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o valor minimax de um estado?</summary> 👉 A utilidade esperada assumindo jogo ótimo de ambos os jogadores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual o valor minimax de um estado terminal?</summary> 👉 A utilidade desse estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que faz MAX num estado não terminal?</summary> 👉 Escolhe a ação cujo sucessor tem maior valor minimax. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que faz MIN num estado não terminal?</summary> 👉 Escolhe a ação cujo sucessor tem menor valor minimax. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual a complexidade temporal do minimax?</summary>
👉 O(b^m), onde b é o fator de ramificação e m a profundidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque o minimax puro é impraticável em jogos reais?</summary> 👉 Porque o número de estados cresce exponencialmente com a profundidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque o minimax pode não ser a melhor estratégia contra adversários fracos?</summary> 👉 Porque pode existir um lance arriscado que explora erros prováveis do adversário. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como se representa a utilidade em jogos com mais de dois jogadores?</summary> 👉 Como um vetor com uma componente por jogador. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como um jogador decide num jogo multijogador?</summary> 👉 Escolhe o sucessor que maximiza a sua própria componente da utilidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque podem surgir alianças em jogos multijogador?</summary> 👉 Porque jogadores fracos podem cooperar para impedir que um jogador forte vença. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque pode haver cooperação em jogos não soma zero?</summary> 👉 Porque existem estados que beneficiam simultaneamente vários jogadores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é a ideia central dos cortes alfa-beta?</summary> 👉 Evitar explorar ramos que não podem influenciar a decisão final. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representa α?</summary> 👉 O melhor valor encontrado até agora para MAX ao longo do caminho. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representa β?</summary> 👉 O melhor valor encontrado até agora para MIN ao longo do caminho. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando ocorre um corte alfa-beta?</summary> 👉 Quando o valor atual é pior do que α ou β, tornando inútil explorar mais. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque a ordem dos sucessores influencia a eficiência do alfa‑beta?</summary> 👉 Porque avaliar primeiro movimentos promissores aumenta a probabilidade de cortes, reduzindo drasticamente o número de estados explorados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é a complexidade temporal no melhor caso do alfa‑beta?</summary> 👉 O(b^(m/2)), reduzindo a profundidade efetiva para metade em comparação com o minimax puro. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que acontece ao alfa‑beta se os movimentos forem avaliados na pior ordem possível?</summary> 👉 O algoritmo degrada-se para o desempenho do minimax, explorando praticamente todos os estados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a killer move heuristic?</summary> 👉 Uma técnica que tenta primeiro movimentos que foram bons em situações anteriores, aumentando a probabilidade de cortes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque a procura iterativa melhora o alfa‑beta?</summary>
👉 Porque as iterações anteriores fornecem uma boa ordenação de movimentos para iterações mais profundas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Para que servem as hashtables?</summary>
👉 Para armazenar valores de estados já explorados, evitando recomputações e acelerando a procura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que jogos como o xadrez beneficiam de hashtables?</summary> 👉 Porque diferentes sequências de jogadas podem levar ao mesmo estado, permitindo reutilizar resultados anteriores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual a diferença entre estratégias Tipo A e Tipo B?</summary> 👉 Tipo A explora largamente até uma profundidade fixa; Tipo B explora profundamente apenas ramos promissores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Em que jogos a estratégia Tipo A é mais adequada?</summary> 👉 Em jogos com ramificação moderada, como o xadrez, onde é possível explorar várias jogadas em largura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque a estratégia Tipo B é usada em jogos como o Go?</summary> 👉 Porque o Go tem ramificação muito elevada, tornando inviável explorar largamente; é preferível aprofundar apenas ramos promissores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que determina o cutoff test?</summary> 👉 Quando parar a expansão, com base na profundidade ou propriedades do estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque uma heurística imperfeita pode induzir erros?</summary> 👉 Porque pode avaliar mal estados superficiais, levando a escolhas subótimas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como o minimax lida com nós de acaso?</summary> 👉 Substitui max/min por valor esperado, calculando a média ponderada das utilidades. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque o alfa‑beta não pode cortar em nós de acaso?</summary> 👉 Porque não há jogador a maximizar ou minimizar; não existem limites α ou β aplicáveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque o Monte Carlo lida naturalmente com aleatoriedade?</summary> 👉 Porque a simulação já incorpora eventos aleatórios, tornando os nós de acaso apenas mais um passo da política de jogo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que uma estratégia ótima deve ser condicional e não apenas uma sequência fixa de jogadas?</summary> 👉 Porque a jogada ótima depende das respostas do adversário; uma estratégia fixa falharia se o adversário não seguisse o caminho esperado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Em que situação pode ser racional escolher um lance “arriscado” em vez do minimax?</summary> 👉 Quando o adversário é fraco ou limitado computacionalmente, aumentando a probabilidade de cometer um erro que beneficie o jogador. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque aumentar a profundidade de procura melhora a qualidade das decisões?</summary> 👉 Porque permite antecipar mais respostas do adversário e evitar armadilhas que só surgem várias jogadas à frente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a explosão combinatória nas árvores de jogo?</summary> 👉 O crescimento exponencial do número de estados à medida que a profundidade aumenta, tornando a procura completa impraticável. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são transposições num jogo como o xadrez?</summary> 👉 Situações em que diferentes sequências de jogadas levam ao mesmo estado final, permitindo reutilizar resultados anteriores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque as hashtables podem duplicar a profundidade alcançável?</summary> 👉 Porque evitam recalcular subárvores inteiras, poupando tempo e permitindo explorar mais profundamente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é importante que a heurística seja estável entre níveis consecutivos?</summary> 👉 Porque grandes oscilações podem levar a decisões inconsistentes e cortes prematuros incorretos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue jogos de informação perfeita de jogos parcialmente observáveis?</summary> 👉 Em jogos de informação perfeita, todos os jogadores veem o estado completo; nos parcialmente observáveis, parte do estado é oculta. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque o valor esperado substitui o minimax em nós de acaso?</summary> 👉 Porque não há adversário a escolher; o resultado depende de probabilidades, não de intenções. </details>


</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversas.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_adversas5a.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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
