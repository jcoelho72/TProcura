@page tutorial_construtivaslit2 📖 Procuras Construtivas - Algoritmos Informados

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_construtivas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Construtivas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="opacity:0.7;">Algoritmos Cegos ›</span>
    <a href="tutorial_construtivaslit.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_construtivas3a.html" style="color:#9cf;">👓 Procura Cega</a>
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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">📖 Leitura</span>
    <a href="tutorial_construtivas4a.html" style="color:#9cf;">👓 Procura Informada</a>
    <span style="opacity:0.7;">Puzzle 8 ›</span>
    <a href="tutorial_puzzle8melhor.html" style="color:#9cf;">✏️ Melhor Primeiro</a>
    <a href="tutorial_puzzle8astar.html" style="color:#9cf;">✏️ A-star</a>
    <a href="tutorial_puzzle8bnb.html" style="color:#9cf;">✏️ BnB</a>
    <a href="teste_puzzle8b.html" style="color:#9cf;">💻 Testar</a>
  </div>
</div>

\endhtmlonly


Algoritmos informados: melhor primeiro; A*; BnB.

## 📖 Leituras

- (Russel & Norvig): Capítulo 4 (2ª edição) | Secções 3.5 e 3.6 (3ª e 4ª edição)

## Bibliografia

-	Russell, S. J., & Norvig, P. (2021). Artificial intelligence: A modern approach (4th ed.). Pearson. https://elibrary.pearson.de/book/99.150005/9781292401171


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->


<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza o Melhor Primeiro (greedy best‑first)?</summary> 👉 Expande sempre o nó com menor valor heurístico h(n), tentando aproximar-se rapidamente do objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o Melhor Primeiro (greedy best‑first) pode falhar em encontrar a solução ótima?</summary> 👉 Porque ignora o custo já percorrido e pode escolher caminhos aparentemente promissores mas mais longos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa h(n) na procura informada?</summary> 👉 É a estimativa do custo do caminho mais barato do estado atual até um estado objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a heurística da distância em linha reta é útil no exemplo da Roménia?</summary> 👉 Porque está correlacionada com as distâncias reais das estradas, fornecendo uma estimativa razoável. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> A procura Melhor Primeiro (greedy best‑first) é completa?</summary> 👉 É completa apenas em espaços de estados finitos. </details>0
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a procura Melhor Primeiro (greedy best‑first) pode ser muito rápida com uma boa heurística?</summary> 👉 Porque tende a expandir apenas estados próximos do objetivo, evitando explorar toda a árvore. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa dizer que a heurística não pode ser calculada a partir da definição do problema?</summary> 👉 Que a heurística depende de conhecimento externo ao modelo formal, como mapas ou propriedades do domínio. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a procura Melhor Primeiro (greedy best‑first) é chamada “gananciosa”?</summary> 👉 Porque tenta sempre aproximar-se do objetivo no passo imediato, sem considerar consequências futuras. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é a principal desvantagem da procura Melhor Primeiro (greedy best‑first)?</summary> 👉 Pode encontrar soluções muito piores do que a ótima. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que representa f(n) no A*?</summary> 👉 f(n) = g(n) + h(n), estimando o custo total da solução passando por n. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa uma heurística ser admissível?</summary> 👉 Que nunca sobrestima o custo real até ao objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a admissibilidade garante otimalidade no A*?</summary> 👉 Porque impede que o algoritmo descarte caminhos que podem levar à solução ótima. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa uma heurística ser consistente?</summary> 👉 Que satisfaz a desigualdade triangular: h(n) ≤ c(n,a,n') + h(n'). </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a consistência evita reintroduzir estados na fronteira?</summary> 👉 Porque garante que a primeira vez que um estado é alcançado corresponde ao caminho ótimo até ele. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são “contornos” numa procura A*?</summary> 👉 Regiões do espaço de estados onde todos os nós têm f(n) ≤ um certo valor. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que os contornos do A* se alongam na direção do objetivo?</summary> 👉 Porque a heurística orienta a expansão para estados mais promissores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que nós são certamente expandidos pelo A?</summary> 👉 Todos os nós com f(n) < C, onde C* é o custo da solução ótima. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o A* é considerado “otimamente eficiente”?</summary> 👉 Porque nenhum algoritmo que use a mesma heurística pode expandir menos nós sem perder otimalidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o A* pode expandir muitos nós mesmo com heurísticas boas?</summary> 👉 Porque o número de estados com f(n) < C* pode ser exponencial. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que faz o weighted A*?</summary> 👉 Usa f(n) = g(n) + W × h(n), dando mais peso à heurística. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o weighted A* encontra soluções mais rapidamente?</summary> 👉 Porque foca a procura mais fortemente na direção do objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O weighted A* é ótimo?</summary> 👉 Não; encontra soluções dentro de um fator W do custo ótimo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é uma heurística não admissível?</summary> 👉 Uma heurística que pode sobrestimar o custo real até ao objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que heurísticas não admissíveis podem ser úteis?</summary> 👉 Porque podem reduzir drasticamente o número de estados explorados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o “detour index”?</summary> 👉 Um fator multiplicativo aplicado à distância em linha reta para aproximar distâncias reais. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é o principal problema do A* em termos de memória?</summary> 👉 Precisa guardar todos os estados na fronteira e na tabela de alcançados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como o IDA* resolve o problema de memória?</summary> 👉 Usa profundidade iterativa com limite em f(n), evitando armazenar todos os estados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o IDA* pode ter muitas iterações?</summary> 👉 Porque cada novo limite pode acrescentar apenas um estado ao contorno. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue o RBFS do IDA*?</summary> 👉 O RBFS mantém valores f “backup” para decidir quando reexpandir subárvores, usando memória linear. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a heurística h(n) é aplicada ao nó e não apenas ao estado?</summary> 👉 Por tradição e consistência com f(n) e g(n), embora a heurística dependa apenas do estado e não da estrutura do nó. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa dizer que uma heurística “correlaciona‑se” com o custo real?</summary> 👉 Significa que valores mais baixos da heurística tendem a corresponder a estados mais próximos da solução, tornando‑a útil para orientar a procura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o A* não expande imediatamente um estado objetivo quando ele aparece na fronteira?</summary> 👉 Porque só o expande quando tiver o menor valor f(n), garantindo que não existe outro caminho potencialmente mais barato. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que acontece se a heurística for admissível apenas ao longo de um dos caminhos ótimos?</summary> 👉 O A* encontra esse caminho ótimo, mesmo que a heurística seja má noutros estados. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que heurísticas inconsistentes podem obrigar a reintroduzir estados na fronteira?</summary> 👉 Porque podem surgir caminhos alternativos com custo g(n) mais baixo, exigindo atualizar sucessores e reavaliar o estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa dizer que o A* “poda” estados?</summary> 👉 Significa que evita expandir estados cujo valor f(n) é superior ao custo da solução ótima, eliminando-os sem os explorar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que os contornos de g(n) são circulares, mas os de f(n) são alongados?</summary> 👉 Porque g(n) cresce uniformemente em todas as direções, enquanto f(n) incorpora h(n), que direciona a expansão para o objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa um nó estar “no contorno do objetivo”?</summary> 👉 Que o seu valor f(n) é exatamente igual ao custo da solução ótima C*, podendo ser expandido antes da solução final. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o A* pode expandir vários nós com f(n) = C* antes de encontrar o objetivo?</summary> 👉 Porque todos esses nós são candidatos a caminhos ótimos e o algoritmo não sabe qual deles conduz ao objetivo até os expandir. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que heurísticas mais informativas reduzem o número de nós com f(n) < C?</summary> 👉 Porque aproximam melhor o custo real, estreitando os contornos e reduzindo a área que o A precisa explorar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza uma heurística “demasiado fraca”?</summary> 👉 Produz valores muito semelhantes para muitos estados, oferecendo pouca orientação e aproximando o A* do custo uniforme. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o weighted A* pode ser visto como “semi‑ganancioso”?</summary> 👉 Porque aumenta o peso da heurística, aproximando-se do comportamento ganancioso, mas sem ignorar totalmente o custo g(n). </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue bounded‑suboptimal search de bounded‑cost search?</summary> 👉 A bounded‑suboptimal garante uma solução dentro de um fator W do ótimo; a bounded‑cost exige apenas que o custo seja inferior a um limite C. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o IDA* funciona particularmente bem no Puzzle 8?</summary> 👉 Porque os valores f(n) são inteiros e formam contornos discretos, permitindo progressão regular entre iterações. </details>


</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="teste_8damas.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_construtivas4a.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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

