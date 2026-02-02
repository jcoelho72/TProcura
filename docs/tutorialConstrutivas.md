@page tutorial_construtivas Tutorial das procuras Construtivas

Este tutorial cobre os algoritmos de procura construtivos.
O nome "construtivo" significa que a solução vai sendo construida, passo a passo (ou ação a ação).
Antes de atingirmos o objetivo temos uma solução parcial, constituída pelos passos (ações) dados até ao momento.
Ao antigirmos o objetivo ficamos com uma solução completa.

Estes algoritmos estão divididos em cegos e informados. Os algoritmos cegos não utilizam informação heurística, apenas informação exata.
Os algoritmos informados, embora mais úteis, constroiem-se sobre estes, pelo que vamos primeiramente analisar
os algoritmos cegos, e de seguida os informados.

Propõe-se que faça este tutorial da seguinte forma:
- Veja o material existente, tanto na bibliografia como nos vídeos se disponível;
- Veja os exemplos passo a passo e procure responder às questões antes de ver as respostas;
- Continue com os exemplos de execução, para mais testes práticos e consolidação da matéria.

# Procuras Construtivas Cegas

Algoritmos cegos: largura-primeiro; profundidade-primeiro; iterativos;

Leituras (Russel & Norvig): Capítulo 3 (2ª edição) | Secções 3.1 a 3.4 (3ª e 4ª edição),

Vídeos (PVP 3A e 3B):

\htmlonly

<div style="width:320px; margin:10px 0;">
  <iframe 
    src="https://player.vimeo.com/video/803549264?title=0&byline=0&portrait=0"
    width="320" height="180" frameborder="0"
    allow="autoplay; fullscreen; picture-in-picture">
  </iframe>
</div>

<div style="width:320px; margin:10px 0;">
  <iframe 
    src="https://player.vimeo.com/video/807295853?title=0&byline=0&portrait=0"
    width="320" height="180" frameborder="0"
    allow="autoplay; fullscreen; picture-in-picture">
  </iframe>
</div>

\endhtmlonly


Exemplos passo a passo (PnP - Papel-e-Lápis):
1. [Puzzle 8 profundidade](tutorial_puzzle8prof.html)
2. [Puzzle 8 iterativa](tutorial_puzzle8iterativa.html)
3. [Puzzle 8 largura](tutorial_puzzle8largura.html)
4. [Partição profundidade](tutorial_particaoprof.html)
5. [Partição largura](tutorial_particaolargura.html)
6. [4 damas profundidade](tutorial_4damasprof.html)
7. [4 damas largura](tutorial_4damaslargura.html) 


# Procuras Construtivas Informadas

Algoritmos informados: melhor primeiro; A*; BnB.

Leituras (Russel & Norvig): Capítulo 4 (2ª edição) | Secções 3.5 (3ª e 4ª edição)

Vídeos (PVP 4A):

\htmlonly

<div style="width:320px; margin:10px 0;">
  <iframe 
    src="https://player.vimeo.com/video/803548744?title=0&byline=0&portrait=0"
    width="320" height="180" frameborder="0"
    allow="autoplay; fullscreen; picture-in-picture">
  </iframe>
</div>

\endhtmlonly


Exemplos passo a passo (PnP):

- [Puzzle 8 melhor](tutorial_puzzle8melhor.html) 
- [Puzzle 8 Astar](tutorial_puzzle8astar.html)
- [Puzzle 8 BnB](tutorial_puzzle8bnb.html)

# Exemplos de execução

1. Aspirador ([parte 1](teste_aspirador1.html), [parte 2](teste_aspirador2.html))
2. [Puzzle 8](teste_puzzle8.html)
3. [8 Damas](teste_8damas.html)
4. [Partição](teste_particao.html)




