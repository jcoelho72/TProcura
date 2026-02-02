@page tutorial_4damaslargura 4 Damas, largura primeiro

| [Puzzle 8 profundidade](tutorial_puzzle8prof.html) | [Puzzle 8 iterativa](tutorial_puzzle8iterativa.html) | [Puzzle 8 largura](tutorial_puzzle8largura.html) | [Partição profundidade](tutorial_particaoprof.html) | [Partição largura](tutorial_particaolargura.html) | [4 damas profundidade](tutorial_4damasprof.html) | [4 damas largura](tutorial_4damaslargura.html) | 

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

| [Puzzle 8 profundidade](tutorial_puzzle8prof.html) | [Puzzle 8 iterativa](tutorial_puzzle8iterativa.html) | [Puzzle 8 largura](tutorial_puzzle8largura.html) | [Partição profundidade](tutorial_particaoprof.html) | [Partição largura](tutorial_particaolargura.html) | [4 damas profundidade](tutorial_4damasprof.html) | [4 damas largura](tutorial_4damaslargura.html) | 
