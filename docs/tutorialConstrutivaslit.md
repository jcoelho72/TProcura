@page tutorial_construtivaslit 📖 Procuras Construtivas - Algoritmos Cegos

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_construtivas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Construtivas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <span style="opacity:0.7;">Algoritmos Cegos ›</span>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">📖 Leitura</span>
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
    <a href="tutorial_construtivaslit2.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_construtivas4a.html" style="color:#9cf;">👓 Procura Informada</a>
    <span style="opacity:0.7;">Puzzle 8 ›</span>
    <a href="tutorial_puzzle8melhor.html" style="color:#9cf;">✏️ Melhor Primeiro</a>
    <a href="tutorial_puzzle8astar.html" style="color:#9cf;">✏️ A-star</a>
    <a href="tutorial_puzzle8bnb.html" style="color:#9cf;">✏️ BnB</a>
    <a href="teste_puzzle8b.html" style="color:#9cf;">💻 Testar</a>
  </div>
</div>

\endhtmlonly


Algoritmos cegos: largura-primeiro; profundidade-primeiro; iterativos;

## 📖 Leituras

- (Russel & Norvig): Secções 3.1 a 3.4 (3ª e 4ª edição) | Capítulo 3 (2ª edição) 

## Bibliografia

-	Russell, S. J., & Norvig, P. (2021). Artificial intelligence: A modern approach (4th ed.). Pearson. http://aima.cs.berkeley.edu/


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um agente de resolução de problemas?</summary> 👉 É um agente que procura uma sequência de ações que o leve do estado inicial até um estado objetivo, utilizando um processo de procura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Em que tipo de ambientes os agentes de resolução de problemas operam neste capítulo?</summary> 👉 Em ambientes episódicos, determinísticos, totalmente observáveis, estáticos, discretos e conhecidos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a formulação do objetivo?</summary> 👉 É o processo em que o agente define o que pretende alcançar, restringindo as ações relevantes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a formulação do problema?</summary> 👉 É a definição dos estados, ações, modelo de transição, estado inicial e estados objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a formulação do problema é uma abstração?</summary> 👉 Porque ignora detalhes irrelevantes do mundo real, mantendo apenas o que é necessário para encontrar uma solução. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa um sistema ser “open‑loop”?</summary> 👉 Significa que o agente executa a sequência de ações sem consultar novos perceptos, assumindo que o ambiente não muda. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é que um agente deve usar um sistema “closed‑loop”?</summary> 👉 Quando o ambiente é incerto, parcialmente observável ou pode mudar durante a execução. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um estado objetivo?</summary> 👉 Um estado que satisfaz a condição definida pelo método IS‑GOAL do problema. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um caminho numa procura?</summary> 👉 Uma sequência de ações que liga o estado inicial a um estado objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza uma solução ótima?</summary> 👉 É a solução com menor custo total entre todas as soluções possíveis. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a abstração é essencial na formulação de problemas?</summary> 👉 Porque reduz a complexidade, permitindo que o agente encontre soluções sem ser sobrecarregado por detalhes irrelevantes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue problemas padronizados de problemas reais?</summary> 👉 Problemas padronizados têm formulações simples e exatas; problemas reais têm formulações complexas e dependem do domínio. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quantos estados tem o mundo do aspirador com duas células?</summary> 👉 Oito estados, resultantes das combinações de posição e sujidade. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que define o estado no 8‑puzzle?</summary> 👉 A posição de cada peça e do espaço vazio na grelha 3×3. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que metade dos estados do 8‑puzzle não têm solução?</summary> 👉 Porque o espaço de estados está dividido em duas classes de paridade, e apenas uma é alcançável a partir de um dado estado inicial. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza o problema de Knuth (4, √, !)?</summary> 👉 Tem um espaço de estados infinito, porque a operação fatorial pode gerar números arbitrariamente grandes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que torna o Sokoban um problema difícil?</summary> 👉 O número enorme de estados e a necessidade de evitar posições irrecuperáveis ao empurrar caixas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que problemas reais como viagens aéreas exigem estados mais complexos?</summary> 👉 Porque o custo e as ações dependem de fatores históricos, horários, ligações e restrições adicionais. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um problema de touring como o TSP?</summary> 👉 O objetivo é visitar um conjunto de locais, minimizando o custo total da viagem. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a navegação de robôs tem um espaço de estados muito grande?</summary> 👉 Porque envolve posições contínuas e múltiplos graus de liberdade, como ângulos de juntas. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a árvore de procura?</summary> 👉 É a estrutura construída pelo algoritmo, contendo caminhos possíveis desde o estado inicial. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a fronteira?</summary> 👉 O conjunto de nós gerados mas ainda não expandidos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa um estado ter sido “atingido”?</summary> 👉 Que existe pelo menos um nó na árvore correspondente a esse estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a árvore de procura pode ter vários nós para o mesmo estado?</summary> 👉 Porque diferentes sequências de ações podem levar ao mesmo estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o modelo de transição?</summary> 👉 A função RESULT(s,a) que indica o estado resultante de aplicar a ação a no estado s. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que ciclos são problemáticos na procura?</summary> 👉 Porque podem gerar caminhos infinitos ou repetidos, desperdiçando tempo e memória. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue procura em árvore de procura em grafo?</summary> 👉 A procura em grafo evita gerar estados já atingidos, prevenindo repetições. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a procura em grafo é mais eficiente?</summary> 👉 Porque evita expandir estados repetidos, reduzindo o espaço de procura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é que a procura em árvore pode ser preferível?</summary> 👉 Quando o espaço de estados é pequeno ou quando não é possível testar estados repetidos. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um algoritmo de procura cego?</summary> 👉 Não utiliza qualquer informação adicional além da definição do problema; não sabe que ações são melhores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que determina o comportamento de um algoritmo cego?</summary> 👉 A forma como escolhe o próximo nó da fronteira para expandir. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a ordem de expansão é crucial?</summary> 👉 Porque determina que caminhos são explorados primeiro e afeta tempo, memória e completude. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa expandir um nó?</summary> 👉 Gerar todos os sucessores aplicando as ações possíveis ao estado do nó. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a procura cega pode explorar muitos estados desnecessários?</summary> 👉 Porque não tem forma de distinguir estados promissores de estados irrelevantes. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a ramificação b?</summary> 👉 O número máximo de sucessores que um nó pode ter. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a profundidade da solução d?</summary> 👉 O número de ações no caminho mais curto até um estado objetivo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a profundidade máxima m?</summary> 👉 O comprimento do caminho mais longo possível na árvore de procura. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que custos negativos são problemáticos?</summary> 👉 Porque podem criar ciclos de custo total negativo, levando a soluções infinitas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a procura cega é importante apesar das limitações?</summary> 👉 Porque fornece a base conceptual para algoritmos informados e garante completude em muitos casos. </details>





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
