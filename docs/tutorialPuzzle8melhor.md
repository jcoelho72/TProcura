@page tutorial_puzzle8melhor ✏️ Puzzle 8, procura melhor primeiro

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
    <a href="tutorial_construtivaslit2.html" style="color:#9cf;">📖 Leitura</a>
    <a href="tutorial_construtivas4a.html" style="color:#9cf;">👓 Procura Informada</a>
    <span style="opacity:0.7;">Puzzle 8 ›</span>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Melhor Primeiro</span>
    <a href="tutorial_puzzle8astar.html" style="color:#9cf;">✏️ A-star</a>
    <a href="tutorial_puzzle8bnb.html" style="color:#9cf;">✏️ BnB</a>
    <a href="teste_puzzle8b.html" style="color:#9cf;">💻 Testar</a>
  </div>
</div>

\endhtmlonly
\htmlonly

<p><span
    style="font-size: 0.9375rem; font-family: Verdana, sans-serif;">Mantemos o
    mesmo exemplo utilizado nas procuras cegas:</span></p>
<p></p>
<table border="1" cellspacing="1" cellpadding="1">
  <tbody>
    <tr>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">6</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top">8</td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">esquerda</td>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">6</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">cima</td>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top">6</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">direita</td>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top">6</td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
    </tr>
  </tbody>
</table>
<p></p>
<p></p>
<p>A <strong>procura melhor primeiro </strong>vai expandir primeiro os estados
  gerados há menos tempo, antes dos restantes, mas de entre os estados com o
  mesmo pai, expande primeiro os que tiverem um valor heurístico menor, dado
  serem esses os mais promissores. Portanto tem que se calcular o valor da
  função heurística, que devolverá uma estimativa para a distância até um estado
  objetivo. Para este problema podemos ter a distância de Manhattan, que é a
  distância na horizontal e vertical de cada número até à sua posição final.</p>
<p>Este algoritmo pode ser basicamente idêntico à procura em profundidade cega,
  mas alterando a ordem de expansão, o que leva a que possa ser também colocado
  um limite. Neste caso vamos utilizar o limite 10, significando que não deve
  explorar soluções com mais de 10 passos.</p>
<p></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="17%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Heurística</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Nível</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Pai</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Expansão</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">1</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">3</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">10</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">0</span></td>
      <td valign="top" width="17%"><strong><span class=""
            style="color: rgb(152, 202, 62);">1</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">2</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">4</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">9</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">1</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">3</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">2</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">9</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">1</span></td>
      <td valign="top" width="17%"><strong><span class=""
            style="color: rgb(125, 159, 211);">2</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">4</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5</span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">4</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">9</span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(152, 202, 62);">1</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">5</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">3</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">8</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">3</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">6</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">3</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">8</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">3</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">7</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8</span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">1</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">8</span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(125, 159, 211);">3</span></td>
      <td valign="top" width="17%"><strong><span class=""
            style="color: rgb(239, 69, 64);">3</span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">8</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">2</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">7</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">7</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">9</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8</span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">0 Solução!</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">7</span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="17%"><span class=""
          style="color: rgb(239, 69, 64);">7</span></td>
      <td valign="top" width="17%"> </td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339639&amp;authkey=%21AEd5ggYnqI1BFTc&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="700" height="600" frameborder="0" scrolling="no"></iframe></p>
<p>Considerando que o teste de estado objetivo se faz na função heurística, já
  que é suposto devolver 0 no caso de ser um estado objetivo, a procura leva 3
  expansões, tendo sido gerados e avaliados 9 estados.</p>
<p style="margin-right: 0px;" dir="ltr">Após a expansão do estado 1, foram
  gerados e avaliados 3 estados, dos quais optou-se por expandir o estado 3 já
  que desses é o que possui o menor valor heurístico, portanto poderá estar mais
  perto de um estado objetivo. Resultante da expansão do estado 3, foram gerados
  3 estados, tendo sido nesse caso o estado 7 o de menor valor, e assim por
  diante. Não foi preciso voltar atrás neste exemplo; o algoritmo foi direto à
  solução a três passos. Se por exemplo tivesse atingido o limite, teria de
  voltar para trás, escolhendo sempre para expandir, de entre os últimos estados
  gerados mas não expandidos com o mesmo pai (e no mesmo nível), o que tiver
  menor valor heurístico.</p>
<p>Se a heurística for muito boa, este algoritmo segue a direito sem problemas.
  No entanto, por vezes a utilização de uma boa heurística tem custos
  computacionais incomportáveis. Mais: nas procuras informadas, é normalmente
  mais pesada a função heurística, sendo portanto mais relevante o número de
  avaliações, podendo no entanto trocar com a geração de sucessores, no caso de
  se optar por uma heurística leve.</p>
<hr>

<details>
<summary><strong>⚡ Ação</strong>: <span
    style="font-size: 0.9375rem;">Considere que o estado de partida era o estado
    4 da resolução acima. Execute este algoritmo e indique o número dos estados
    expandidos por ordem de expansão, separados por vírgulas sem espaços.</span>
</summary>

<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="17%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Heurística</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Nível</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Pai</strong></p>
      </td>
      <td valign="top" width="17%">
        <p align="center"><strong>Expansão</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="17%">1</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">6</td>
              <td valign="top">8</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">4</td>
      <td valign="top" width="17%">10</td>
      <td valign="top" width="17%">0</td>
      <td valign="top" width="17%">1</td>
    </tr>
    <tr>
      <td valign="top" width="17%">2</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">6</td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">3</td>
      <td valign="top" width="17%">9</td>
      <td valign="top" width="17%">1</td>
      <td valign="top" width="17%">2</td>
    </tr>
    <tr>
      <td valign="top" width="17%">3</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">6</td>
              <td valign="top">8</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top"> </td>
              <td valign="top">5</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">5</td>
      <td valign="top" width="17%">9</td>
      <td valign="top" width="17%">1</td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%">4</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">6</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">4</td>
      <td valign="top" width="17%">8</td>
      <td valign="top" width="17%">2</td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%">5</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top"> </td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">2</td>
      <td valign="top" width="17%">8</td>
      <td valign="top" width="17%">2</td>
      <td valign="top" width="17%">3</td>
    </tr>
    <tr>
      <td valign="top" width="17%">6</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top"> </td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">2</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">3</td>
      <td valign="top" width="17%">7</td>
      <td valign="top" width="17%">5</td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%">7</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top">4</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">3</td>
      <td valign="top" width="17%">7</td>
      <td valign="top" width="17%">5</td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%">8</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">5</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top"> </td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">1</td>
      <td valign="top" width="17%">7</td>
      <td valign="top" width="17%">5</td>
      <td valign="top" width="17%">4</td>
    </tr>
    <tr>
      <td valign="top" width="17%">9</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">5</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top">7</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">2</td>
      <td valign="top" width="17%">6</td>
      <td valign="top" width="17%">8</td>
      <td valign="top" width="17%"> </td>
    </tr>
    <tr>
      <td valign="top" width="17%">10</td>
      <td valign="top" width="17%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top">5</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">8</td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="17%">0 Solução!</td>
      <td valign="top" width="17%">6</td>
      <td valign="top" width="17%">8</td>
      <td valign="top" width="17%"> </td>
    </tr>
  </tbody>
</table>

</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_construtivas4a.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_puzzle8astar.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
