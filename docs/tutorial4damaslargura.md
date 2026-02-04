@page tutorial_4damaslargura ✏️ 4 Damas, largura primeiro

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Largura</span>
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
<h1>4 Damas, largura primeiro</h1>
<p>A procura em largura, com as simetrias:</p>
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
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
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
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"> 1 </span></td>
      <td valign="top" width="20%"> <strong><span class=""
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
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"> 1 </span></td>
      <td valign="top" width="20%"> <strong><span class=""
            style="color: rgb(239, 69, 64);">3 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">4 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">X </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">X </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);"> 2 </span></td>
      <td valign="top" width="20%"> 4</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">X </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);"> 2 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">5 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">6 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">X  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);"> 2 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">3 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">6 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">7 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">X </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">X  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"> 3 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">5 </span></td>
      <td valign="top" width="20%">7</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">8 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">X  </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);"> 3 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">6 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">8 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">9 Solução! </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);"> 4 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339638&amp;authkey=%21AABDle4EhphohNY&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1150" height="650" frameborder="0" scrolling="no"></iframe></p>
<p>Mesmo com a procura em largura, tendo simetrias, apenas foram gerados 9
  estados, e expandidos 8 estados.</p>
<p>Há pormenores que não são detectados em instâncias desta dimensão, no entanto
  uma análise prévia manual, de uma versão reduzida do problema em mãos, pode
  dar um grande avanço no conhecimento do problema concreto.</p>
<p>As mesmas dificuldades da resolução manual tem também o computador em outra
  escala. A dificuldade de a partir de um estado gerar os sucessores. Se for
  muito complicado, poderá tornar-se uma operação muito relevante. Por outro
  lado, se o teste de estado objectivo for complexo, pode também tornar-se num
  fator demasiado relevante. Finalmente, o número de estados gerados mas ainda
  não expandidos, se for muito elevado, na resolução manual requer muitas folhas
  de papel, enquanto que no computador poderá não haver memória suficiente.</p>
<hr>
<details>
<summary><strong>⚡ Ação</strong>:
  Faça a mesma procura, para as 5 damas.</summary>
  
A resposta é 23. Atenção que na expansão
  17, o estado gerado seria igual ao estado 20 (simetria diagonal), pelo que não
  deve ser gerado.

</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_4damasprof.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="teste_8damas.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
