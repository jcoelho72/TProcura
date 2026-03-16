@page tutorial_introducao2lit 📖 Introdução - Conceito de Agente

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">📖 Leitura</span>
    <a href="tutorial_introducao2.html" style="color:#9cf;">👓 Conceito de Agente</a>
    <a href="tutorial_introducao2exe.html" style="color:#9cf;">✏️ Exercícios</a>
  </div>
</div>


\endhtmlonly



## 📖 Leituras

- (Russel & Norvig): Capítulo 2

## Bibliografia

-	Russell, S. J., & Norvig, P. (2021). Artificial intelligence: A modern approach (4th ed.). Pearson. http://aima.cs.berkeley.edu/


\htmlonly

<p></p>

<div id="todas-perguntas" style="display:none;">

<!-- perguntas sobre o recurso em estudo -->

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um agente segundo o capítulo?</summary> 👉 Um agente é qualquer entidade que perceciona o ambiente através de sensores e atua sobre ele através de atuadores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que são sensores e atuadores num agente?</summary> 👉 Sensores captam perceções do ambiente; atuadores executam ações que modificam o ambiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é uma percepção?</summary> 👉 É o conteúdo que os sensores do agente captam num dado instante. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a sequência de percepções?</summary> 👉 É o histórico completo de tudo o que o agente já percecionou. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a agent function?</summary> 👉 É a função matemática que mapeia qualquer sequência de perceções para uma ação. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é a diferença entre agent function e agent program?</summary> 👉 A agent function é uma descrição abstrata; o agent program é a implementação concreta que corre num sistema físico. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que a tabela da agent function pode ser infinita?</summary> 👉 Porque a sequência de perceções pode ter comprimento arbitrário. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> No mundo do aspirador, que perceções o agente recebe?</summary> 👉 A localização atual e se o quadrado está limpo ou sujo. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que ações estão disponíveis no mundo do aspirador simples?</summary> 👉 Mover para a esquerda, mover para a direita, aspirar, ou não fazer nada. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o conceito de agente é uma ferramenta analítica e não uma classificação rígida?</summary> 👉 Porque serve para analisar sistemas, não para dividir o mundo entre “agentes” e “não agentes”. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um agente racional?</summary> 👉 É um agente que faz a ação que maximiza o desempenho esperado, com base na sequência de perceções e no conhecimento disponível. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um indicador de desempenho?</summary> 👉 É o critério que avalia quão desejável é a sequência de estados do ambiente resultante das ações do agente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que definir um indicador de desempenho é difícil?</summary> 👉 Porque o agente pode explorar definições mal formuladas para maximizar o valor de formas indesejáveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Qual é o problema do aspirador se o desempenho for “quantidade de sujidade removida”?</summary> 👉 O agente pode limpar e sujar repetidamente o mesmo local para maximizar pontos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa consequencialismo no contexto da IA?</summary> 👉 Avaliar o comportamento do agente pelas consequências das suas ações. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quais são os quatro fatores que determinam o que é racional num dado momento?</summary> 👉 O indicador de desempenho, o conhecimento prévio, as ações disponíveis e a sequência de perceções. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que racionalidade não é perfeição?</summary> 👉 Porque racionalidade maximiza desempenho esperado, não o desempenho real, que depende de eventos imprevisíveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é omnisciência e porque é impossível?</summary> 👉 É saber o resultado real de todas as ações; é impossível porque o agente só pode agir com base no que perceciona. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é recolher informação?</summary> 👉 Ações realizadas para obter perceções futuras mais informativas, como “olhar antes de atravessar a rua”. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é autonomia num agente?</summary> 👉 A capacidade de agir com base nas próprias perceções e aprendizagem, em vez de depender totalmente do conhecimento do programador. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que um agente totalmente baseado em conhecimento prévio não é autónomo?</summary> 👉 Porque não adapta o comportamento com base na experiência e pode falhar quando o ambiente difere do esperado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que ilustra o exemplo do escaravelho do esterco?</summary> 👉 Que agentes sem capacidade de aprendizagem podem falhar quando o ambiente muda. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que demonstra o exemplo da vespa sphex?</summary> 👉 Que comportamento rígido e não adaptativo leva a falhas repetidas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes reais precisam de aprendizagem?</summary> 👉 Para corrigir conhecimento incorreto e adaptar-se a ambientes variáveis. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Quando é que um agente não precisa de aprender?</summary> 👉 Quando o ambiente é totalmente conhecido e previsível. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente da tarefa?</summary> 👉 É a descrição completa do problema a resolver, incluindo desempenho, ambiente, atuadores e sensores (PEAS). </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que significa PEAS?</summary> 👉 Performance, Environment, Actuators, Sensors. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que o PEAS deve ser definido antes de projetar o agente?</summary> 👉 Porque o design do agente depende totalmente das características do ambiente e dos objetivos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> No exemplo do táxi autónomo, que fatores compõem o o indicador de desempenho?</summary> 👉 Segurança, rapidez, conforto, legalidade, eficiência e lucro. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que elementos fazem parte do ambiente do táxi autónomo?</summary> 👉 Estradas, tráfego, peões, polícia, passageiros e condições meteorológicas. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que atuadores tem um táxi autónomo?</summary> 👉 Direção, acelerador, travão, sinais, buzina, display e voz. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que sensores tem um táxi autónomo?</summary> 👉 Câmaras, radar, GPS, sensores do motor, acelerómetro, microfones e touchscreen. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue um ambiente totalmente observável de um parcialmente observável?</summary> 👉 Num ambiente totalmente observável, os sensores captam todo o estado relevante; num parcialmente observável, parte do estado é desconhecida. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um ambiente não observável?</summary> 👉 Um ambiente onde o agente não recebe qualquer perceção. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue ambientes uni-agente de multiagente?</summary> 👉 Em uni-agente, só o agente principal influencia o desempenho; em multiagente, outros agentes também influenciam. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um ambiente competitivo?</summary> 👉 Os agentes têm objetivos opostos, como no xadrez. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um ambiente cooperativo?</summary> 👉 Os agentes beneficiam mutuamente ao atingir objetivos comuns. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue ambientes determinísticos de não determinísticos?</summary> 👉 Num ambiente determinístico, o próximo estado é totalmente determinado pela ação; num não determinístico, há incerteza. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que ambientes multiagente podem exigir comportamento aleatório?</summary> 👉 Para evitar previsibilidade que adversários possam explorar. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que ambientes parcialmente observáveis exigem memória interna?</summary> 👉 Porque o agente precisa de manter informação sobre o estado que não consegue observar diretamente. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes baseados em tabelas são impraticáveis?</summary> 👉 Porque o número de possíveis sequências de perceções cresce exponencialmente, tornando a tabela gigantesca e impossível de construir, armazenar ou aprender. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que caracteriza um agente reflexo simples?</summary> 👉 Escolhe ações apenas com base na percepção atual, ignorando toda a história de perceções. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é uma regra condição-ação?</summary> 👉 Uma regra do tipo if condição then ação, que liga diretamente perceções a ações. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes reflexos simples só funcionam bem em ambientes totalmente observáveis?</summary> 👉 Porque dependem exclusivamente da percepção atual; se parte do estado não for observável, podem tomar decisões erradas ou entrar em ciclos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Como a aleatoriedade pode ajudar um agente reflexo simples?</summary> 👉 Pode permitir escapar de ciclos infinitos em ambientes parcialmente observáveis, escolhendo ações aleatórias quando não há informação suficiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue um agente reflexo modelo?</summary> 👉 Mantém um estado interno que representa partes do mundo não observáveis diretamente, atualizado com base num modelo de transição e num modelo de sensores. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o modelo de transição?</summary> 👉 Conhecimento sobre como o mundo evolui ao longo do tempo e como as ações do agente alteram o estado do ambiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é o modelo de sensores?</summary> 👉 Conhecimento sobre como o estado do mundo se reflete nas perceções do agente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes reflexo modelo não conseguem sempre determinar o estado exato?</summary> 👉 Porque ambientes parcialmente observáveis introduzem incerteza, e o agente só pode manter a sua melhor estimativa do estado. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue um agente objetivo?</summary> 👉 Utiliza informação sobre objetivos desejáveis para escolher ações que conduzam ao estado pretendido. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes objetivo são mais flexíveis que agentes reflexo?</summary> 👉 Porque o comportamento pode ser alterado mudando apenas o objetivo, sem reescrever todas as regras de perceção‑ação. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Que áreas da IA tratam de encontrar sequências de ações para atingir objetivos?</summary> 👉 Procura (search) e planeamento (planning). </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que distingue um agente utilidade?</summary> 👉 Avalia estados segundo uma função de utilidade e escolhe ações que maximizam a utilidade esperada. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que objetivos são insuficientes em alguns ambientes?</summary> 👉 Porque apenas distinguem entre “satisfeito” e “não satisfeito”, sem permitir comparar diferentes graus de qualidade entre soluções. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é a utilidade esperada?</summary> 👉 A utilidade média ponderada pelas probabilidades dos diferentes resultados possíveis de uma ação. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Em que casos os agentes utilidade são superiores a agentes objetivo?</summary> 👉 Quando há objetivos conflitantes ou quando nenhum objetivo pode ser alcançado com certeza. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes utilidade são essenciais em ambientes incertos?</summary> 👉 Porque permitem tomar decisões racionais mesmo quando os resultados das ações são probabilísticos. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> O que é um agente aprendizagem?</summary> 👉 Um agente que melhora o seu desempenho ao longo do tempo, modificando os seus próprios componentes com base na experiência. </details>

<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que Turing defendia aprendizagem em vez de programação manual?</summary> 👉 Porque programar manualmente todos os comportamentos inteligentes seria demasiado trabalhoso; aprender é mais eficiente. </details>
<details class="pergunta"> <summary><strong>⚡ Ação:</strong> Porque é que agentes utilidade exigem algoritmos complexos?</summary> 👉 Porque precisam de prever resultados, calcular probabilidades e maximizar utilidade esperada, tarefas computacionalmente difíceis. </details>

</div>

<div id="perguntas-escolhidas"></div>

<p>Nova pergunta: <a href="" style="color:#9cf; font-weight:bold; margin-left:10px;">🎲</a></p>

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_introducao1exe.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_introducao2.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
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
