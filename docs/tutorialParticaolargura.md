@page tutorial_particaolargura Partição, largura primeiro

| [Puzzle 8 profundidade](tutorial_puzzle8prof.html) | [Puzzle 8 iterativa](tutorial_puzzle8iterativa.html) | [Puzzle 8 largura](tutorial_puzzle8largura.html) | [Partição profundidade](tutorial_particaoprof.html) | [Partição largura](tutorial_particaolargura.html) | [4 damas profundidade](tutorial_4damasprof.html) | [4 damas largura](tutorial_4damaslargura.html) | 

\htmlonly
<p>Na procura em largura primeiro, utiliza-se os sucessores na sua melhor versão
  analisada no exercício anterior, isto é, não são gerados estados em que um dos
  grupos tem mais de metade do total dos números.</p>
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
          style="color: rgb(239, 69, 64);">1 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(5;4;3;2;2) 0 = 0 </span><br><span
          class="" style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">5 </span><br><span class=""
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
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(4;3;2;2) 5 = 0 </span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span><br><span class=""
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
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(4;3;2;2) 0 = 5 </span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">4 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class="" style="color: rgb(0, 0, 0);">3
        </span></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">4 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(3;2;2) 5 = 4 </span><br><span
          class="" style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">2 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">4 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">5 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(3;2;2) 4 = 5 </span><br><span
          class="" style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">3 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">5 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">6 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(2;2) 8 = 4 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">4 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">6 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">7 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(2;2) 5 = 7 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">2 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">4 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">7 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">8 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2;2) 7 = 5 </span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">5 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(152, 202, 62);">8 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">9 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2;2) 4 = 8 </span><br><span
          class="" style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">2 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">5 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(125, 159, 211);">9 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">10  </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(2) 8 = 6 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">1 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">6 </span></td>
      <td valign="top" width="20%"><strong><span class=""
            style="color: rgb(239, 69, 64);">10 </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">11 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">(2) 7 = 7 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">1 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">7 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">12 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">(2) 7 = 7 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">1 </span><br><span class=""
          style="color: rgb(152, 202, 62);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(152, 202, 62);">8 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">13 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">(2) 6 = 8 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">1 </span><br><span class=""
          style="color: rgb(125, 159, 211);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(125, 159, 211);">9 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">14 Soluçao! </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">8 = 8 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">0 </span><br><span class=""
          style="color: rgb(239, 69, 64);"> </span></td>
      <td valign="top" width="20%"><span class=""
          style="color: rgb(239, 69, 64);">10 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339634&amp;authkey=%21AG3TUk-n4WoWlBE&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="850" height="450" frameborder="0" scrolling="no"></iframe></p>
<p><span style="font-size: calc(0.90375rem + 0.045vw);">A procura levou 14
    gerações e 10 expansões. No entanto é nítido mais algum desperdício, alguns
    estados são analisados em duplicado. Os estados 2 e 3 são simétricos, já que
    são indiferentes um ou outro grupo, tal como os estados 4 e 5, entre outros.
    Já os estados 11 e 12 são exatamente iguais, muito embora possam ter
    associados números distintos num e noutro conjunto.</span></p>
<p>Pode-se ainda melhorar o gerador de sucessores, gerando estados que nunca
  tenham sido gerados. De forma a garantir que estados idênticos excepto na
  ordem dos grupos não são considerados distintos, pode-se ordenar o estado,
  colocando sempre o grupo com um número maior primeiro. Para verificar que o
  estado já foi gerado, tem de se ter uma hashtable de forma a poder fazer este
  teste em tempo constante.</p>
<hr>
<details>
<summary><strong> Ação:</strong>
  Aplique este algoritmo para este problema, com esta regra, de apenas gerar os
  estados que ainda não estiverem sido gerados, e ordenando os grupos por total
  somado. </summary>

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
      <td valign="top" width="20%">(4;3;2;2) 5 = 0</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2</td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">(3;2;2) 5 = 4</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">(2;2) 8 = 4</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">4</td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">(2;2) 7 = 5</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">5</td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">(2) 8 = 6</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">4 </td>
      <td valign="top" width="20%">6</td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">(2) 7 = 7</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">8 Solução!</td>
      <td valign="top" width="20%">8 = 8</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>

</details>

\endhtmlonly

| [Puzzle 8 profundidade](tutorial_puzzle8prof.html) | [Puzzle 8 iterativa](tutorial_puzzle8iterativa.html) | [Puzzle 8 largura](tutorial_puzzle8largura.html) | [Partição profundidade](tutorial_particaoprof.html) | [Partição largura](tutorial_particaolargura.html) | [4 damas profundidade](tutorial_4damasprof.html) | [4 damas largura](tutorial_4damaslargura.html) | 
