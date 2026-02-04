@page tutorial_puzzle8largura ✏️ Puzzle 8, procura em largura

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Largura</span>
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

\htmlonly
<p style="margin-right: 0px;" dir="ltr">Agora analisamos a procura em largura,
  utilizando apenas 2 movimentos de exemplo desde a posição inicial:</p>
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
      <td valign="top" width="14%"> </td>
      <td valign="top" width="14%"> </td>
    </tr>
  </tbody>
</table>
<p></p>
<p> A <strong>procura em largura </strong>vai expandir primeiro os estados
  gerados à mais tempo, antes dos restantes, portanto expande pela mesma ordem
  que são gerados os estados.</p>
<p></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%">Geração</td>
      <td valign="top" width="20%">Estado</td>
      <td valign="top" width="20%">Nível</td>
      <td valign="top" width="20%">Pai</td>
      <td valign="top" width="20%">Expansão</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">1 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">1 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">2 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">3 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">3 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">4 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">5 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">5 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">6 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">7 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2  </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">3 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">9 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">1 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">2 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">3 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">7 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">4 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">6 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">5 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">8 </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2  </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">3 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">10  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">11  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">1 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">2 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">3 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">4 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">6 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">8 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">7 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">5 </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">12 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">13 Solução! </span><br><span
          class="" style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">1 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">2 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">3 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">4 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">5 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">6 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">7 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">8 </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5  </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339614&amp;authkey=%21AOUJy5z4Ef4i5l0&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1050" height="600" frameborder="0" scrolling="no"></iframe></p>
<p style="margin-right: 0px;" dir="ltr">Neste caso houve 13 gerações e 5
  expansões. O teste da solução final é feito na geração, dado que neste caso
  pode ser bastante compensador relativamente a realizar o teste na expansão. Na
  situação concreta, significaria que se teria de fazer 13 expansões em vez
  das 5 necessárias, embora o número de testes de solução final seja igual em
  ambos os casos.</p>
<p style="margin-right: 0px;" dir="ltr">Pode-se utilizar o campo do nível a
  subir em vez de descer, dado que o algoritmo não tem parâmetros, utilizando-se
  esse campo apenas para fins informativos.</p>
<p style="margin-right: 0px;" dir="ltr">O algoritmo apresenta uma pequena
  diferença de execução, expande o estado gerado à mais tempo, em vez de ser à
  menos tempo, mas apresenta uma grande diferença para o algoritmo de
  profundidade primeiro: o elevado número de estados gerados e não expandidos.
</p>
<hr>
<details>
<summary>
<strong>⚡ Ação:</strong>
  Refaça esta procura mas utilizando o mesmo estado de partida que nos exemplos
  anteriores:
<table border="3" width="100" cellspacing="3" cellpadding="3" align="middle">
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
</summary>

<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%">Geração</td>
      <td valign="top" width="20%">Estado</td>
      <td valign="top" width="20%">Nível</td>
      <td valign="top" width="20%">Pai</td>
      <td valign="top" width="20%">Expansão</td>
    </tr>
    <tr>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">1</td>
    </tr>
    <tr>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2</td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">3</td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">4</td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top"> </td>
              <td valign="top">2</td>
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
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">5</td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">6</td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">7</td>
    </tr>
    <tr>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">8</td>
    </tr>
    <tr>
      <td valign="top" width="20%">9</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">10</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top">1</td>
              <td valign="top">2</td>
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">11</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">6</td>
              <td valign="top">2</td>
            </tr>
            <tr>
              <td valign="top">4</td>
              <td valign="top"> </td>
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">12</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top">1</td>
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">13</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">3</td>
              <td valign="top"> </td>
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">14</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">1</td>
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">15</td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">1</td>
              <td valign="top">2</td>
              <td valign="top">3</td>
            </tr>
            <tr>
              <td valign="top">7</td>
              <td valign="top">4</td>
              <td valign="top">6</td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top">5</td>
              <td valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">16</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">17 Solução!</td>
      <td valign="top" width="20%">
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
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_puzzle8iterativa.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="teste_puzzle8.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
