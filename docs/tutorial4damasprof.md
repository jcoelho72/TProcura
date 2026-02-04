@page tutorial_4damasprof ✏️ 4 Damas, profundidade primeiro

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Profundidade</span>
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
<p>O problema das N Damas consiste em colocar damas de xadrez num tabuleiro com
  a mesma largura do número de damas, sem que nenhum par de damas se ataquem
  (horizontal, vertical, diagonal). Para resolver à mão vamos resolver o
  problema das 4 damas.</p>
<p style="margin-right: 0px;" dir="ltr">O estado inicial pode ser o tabuleiro
  sem qualquer dama colocada, sendo os sucessores os tabuleiros em que se coloca
  mais uma dama na primeira linha vazia, numa das casas não atacada pelas damas
  já existentes no tabuleiro.</p>
<p style="margin-right: 0px;" dir="ltr"></p>
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
        <table border="3"  cellspacing="3" cellpadding="3"
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
        <table border="3"  cellspacing="3" cellpadding="3"
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
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">3 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
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
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
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
          style="color: rgb(152, 202, 62);">1  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"> 1 </span></td>
      <td valign="top" width="20%"> <strong><span class=""
            style="color: rgb(152, 202, 62);">6 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">5 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table style="text-align: center;" border="3" 
          cellspacing="3" cellpadding="3" align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
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
          style="color: rgb(152, 202, 62);">1  </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);"> 1 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">2 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">6 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
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
          style="color: rgb(125, 159, 211);"> 2 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5  </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">4 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">7 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
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
          style="color: rgb(125, 159, 211);"> 2 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5 </span></td>
      <td valign="top" width="20%">3</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
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
          style="color: rgb(239, 69, 64);"> 3 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">6 </span></td>
      <td valign="top" width="20%">5</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">9 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);"> X </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">  </span><br><span class=""
                  style="color: rgb(152, 202, 62);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(152, 202, 62);">X  </span><br><span class=""
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
          style="color: rgb(152, 202, 62);"> 2 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">7 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">10  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);"> X </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">  </span><br><span class=""
                  style="color: rgb(125, 159, 211);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(125, 159, 211);">X  </span><br><span
                  class="" style="color: rgb(125, 159, 211);"> </span></td>
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
          style="color: rgb(125, 159, 211);">3 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">9  </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">8 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">11 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
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
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">X  </span><br><span class=""
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
                  style="color: rgb(239, 69, 64);"> X </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span class=""
                  style="color: rgb(239, 69, 64);">  </span><br><span class=""
                  style="color: rgb(239, 69, 64);"> </span></td>
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
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">4 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">10 </span></td>
      <td valign="top" width="20%">9 Solução!</td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339636&amp;authkey=%21AApsJ-IynpV0DcE&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1150" height="650" frameborder="0" scrolling="no"></iframe></p>
<p style="margin-right: 0px;" dir="ltr">Houve 11 gerações e 9 expansões. Neste
  problema há no entanto simetrias que foram ignoradas (horizontal, vertical,
  diagonal), o que pode levar a que sejam analisados estados em duplicado, tal
  como nos exemplos anteriores. Num problema desta dimensão não há problema, mas
  subindo a dimensão, a consideração das simetrias pode levar a poupanças muito
  consideráveis.</p>
<hr>
<details>
<summary><strong>⚡ Ação:</strong>
  Refaça a procura em profundidade considerando as simetrias, mas para o
  problema das 5 damas. </summary>

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
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
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
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top">X </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2</td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">3</td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">4</td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">5</td>
    </tr>
    <tr>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%">
        <table border="3"  cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top">X</td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
            </tr>
            <tr>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> </td>
              <td valign="top"> X</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">6 Solução!</td>
    </tr>
  </tbody>
</table>
</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="teste_particao.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_4damaslargura.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
