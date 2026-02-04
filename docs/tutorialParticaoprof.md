@page tutorial_particaoprof ✏️ Partição, profundidade primeiro

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Profundidade</span>
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
\htmlonly
<p>O problema da <strong>partição</strong> consiste em dividir um conjunto de
  números em dois grupos, de forma a que somem exatamente o mesmo valor.</p>
<p>Suponhamos a seguinte instância: 5;4;3;2;2. Os valores estão por ordem
  decrescente, existindo o número 2 repetido. Estes números podem ser colocados
  em dois grupos 5+3 = 4+2+2.</p>
<p>Considerando o estado vazio como sendo todos os números ainda por colocar, os
  sucessores de um determinado estado pode consistir na colocação do número mais
  alto num dos dois grupos. A ramificação é portanto binária, e a profundidade
  máxima igual à quantidade de números. Poder-se-ia optar por um conjunto de
  sucessores que consistia em colocar qualquer número num dos grupos, mas assim
  ter-se-ia uma ramificação muito superior, e é indiferente a ordem pela qual os
  números são colocados nos grupos.</p>
<p>A representação do estado é autoexplicativa.</p>
<p></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%"><strong>Geração</strong></td>
      <td valign="top" width="20%"><strong>Estado</strong></td>
      <td valign="top" width="20%"><strong>Nível</strong></td>
      <td valign="top" width="20%"><strong>Pai</strong></td>
      <td valign="top" width="20%"><strong>Expansão</strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">1</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(5;4;3;2;2) 0 = 0</span><br><span
          class="" style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">5</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"><strong>1</strong></span></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(4;3;2;2) 5 = 0</span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">3</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(4;3;2;2) 0 = 5</span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">2</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">4</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(3;2;2) 4 = 5</span><br><span
          class="" style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">18</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(3;2;2) 0 = 9</span><br><span
          class="" style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">3</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">6</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(2;2) 3 = 9</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">5</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">11</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">7</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(2;2) 0 = 12</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">5</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">4</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">8</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2) 2 = 12</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">7</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">8</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">9</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2) 0 = 14</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">7</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">5</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">10</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 = 14</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">0</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">9</span></td>
      <td valign="top" width="20%">7</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">11</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">0 = 16</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">0</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">9</span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(0, 0, 0);">6</span></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">12</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">4 = 12</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8</span></td>
      <td valign="top" width="20%">10</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">13</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2 = 14</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8</span></td>
      <td valign="top" width="20%">9</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">14</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2) 5 = 9</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">6</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">15</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">15</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2) 3 = 11</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">6</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">12</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">16</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5 = 11</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">0</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">15</span></td>
      <td valign="top" width="20%">14</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">17</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3 = 13</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">0</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">15</span></td>
      <td valign="top" width="20%">13</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">18</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">7 = 9</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">14</span></td>
      <td valign="top" width="20%">17</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">19</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">5 = 11</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">14</span></td>
      <td valign="top" width="20%">16</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">20</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2;2) 7 = 5</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4</span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">21</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2;2) 4 = 8</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">19</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">22</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(2) 6 = 8</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">1</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">21</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">23</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">23</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(2) 4 = 10</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">1</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">21</span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">20</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">24</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">6 = 10</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">23</span></td>
      <td valign="top" width="20%">22</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">25</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">4 = 12</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">23</span></td>
      <td valign="top" width="20%">21</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">26</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">8 = 8</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">0</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">22</span></td>
      <td valign="top" width="20%">25 Solução!</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">27</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">6 = 10</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">0</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">22</span></td>
      <td valign="top" width="20%">24</td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339615&amp;authkey=%21AJQzYj3h_C0WHsU&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1250" height="450" frameborder="0" scrolling="no"></iframe></p>
<p>A solução foi encontrada com 27 gerações e 25 expansões. No entanto há vários
  estados que já se saberia não poderem levar a uma divisão válida, mas
  continuaram a ser explorados. Por exemplo o estado 5, embora num dos grupos já
  some 9, excedendo portanto o limite de 8, mesmo assim expande-se logo na 3ª
  expansão este estado, desperdiçando tempo já que não leva a lado nenhum. Para
  que o algoritmo não incorra nesse tipo de desperdícios, o conjunto de
  sucessores tem de ser redefinido, não gerando estados em que um dos grupos já
  ultrapassa metade da soma de todos os números.</p>
<hr>
<details>
<summary><strong>⚡ Ação:
  </strong>Refaça esta procura já com o novo sucessor.</summary>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%"><strong>Geração</strong></td>
      <td valign="top" width="20%"><strong>Estado</strong></td>
      <td valign="top" width="20%"><strong>Nível</strong></td>
      <td valign="top" width="20%"><strong>Pai</strong></td>
      <td valign="top" width="20%"><strong>Expansão</strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">(5;4;3;2;2) 0 = 0</td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">1</td>
    </tr>
    <tr>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">(4;3;2;2) 5 = 0</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">(4;3;2;2) 0 = 5</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2</td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">(3;2;2) 4 = 5</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">3</td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">(2;2) 7 = 5</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">(2;2) 4 = 8</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">4</td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">(2) 6 = 8</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">5</td>
    </tr>
    <tr>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%">8 = 8</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">6 Solução!</td>
    </tr>
  </tbody>
</table>

</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="teste_puzzle8.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_particaolargura.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
