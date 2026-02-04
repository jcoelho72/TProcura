@page tutorial_puzzle8prof ✏️ Puzzle 8, procura em profundidade nível 3

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
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Profundidade</span>
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

\htmlonly
<p><strong>Puzzle8</strong> é um jogo num tabuleiro de 3x3, em que uma das casas
  está vazia. Os movimentos possíveis a cada momento é mover para a casa vazia,
  o conteúdo de uma das casas ao lado. O objetivo é colocar o tabuleiro numa
  posição final. Para evitar alguns ciclos, pode-se não considerar o sucessor
  que volta para trás.</p>
<p style="margin-right: 0px;" dir="ltr">3 movimentos de exemplo desde a posição
  inicial:</p>
<p></p>
<table border="1" cellspacing="1" cellpadding="1">
  <tbody>
    <tr>
      <td valign="top" width="14%">
        <table>
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
              <td style="text-align: center;" valign="top"><strong>8 </strong>
              </td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">esquerda</td>
      <td valign="top" width="14%">
        <table>
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top"><strong>5 </strong>
              </td>
              <td style="text-align: center;" valign="top">6</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><strong>8 </strong>
              </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">cima</td>
      <td valign="top" width="14%">
        <table>
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><strong>6 </strong>
              </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top"><strong>5 </strong>
              </td>
              <td style="text-align: center;" valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">direita</td>
      <td valign="top" width="14%">
        <table>
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top"><strong>6 </strong>
              </td>
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
<p> A <strong>procura em profundidade</strong> vai expandir primeiro os estados
  gerados <span style="color: #333333;">há</span><span style="color: #333333;">
  </span>menos tempo, antes dos restantes.</p>
<p></p>
<table border="1" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%"><strong>Geração</strong></td>
      <td valign="top" width="20%"><strong>Estado</strong></td>
      <td valign="top" width="20%"><strong>Nível</strong></td>
      <td valign="top" width="20%"><strong>Pai</strong></td>
      <td valign="top" width="20%"><strong>Expansão</strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #ef4540;">1
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">1 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">2 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">3 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">4 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">6 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">7 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">5 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">8 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #ef4540;">3
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%"><span style="color: #ef4540;">0 </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;"><strong>1
          </strong></span></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">2
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">2
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">3
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">2
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1 </span></td>
      <td valign="top" width="20%"><strong><span style="color: #98ca3e;">6
          </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">4
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">2
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1 </span></td>
      <td valign="top" width="20%"><strong><span style="color: #7d9fd3;">2
          </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">5
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">1 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">2 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">3 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">4 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">6 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">8 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">7 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">5 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">1
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">4 </span></td>
      <td valign="top" width="20%"><strong><span style="color: #ef4540;">3
          </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #ef4540;">6
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">1 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">2 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">3 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">4 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">8 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">7 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">6 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">5 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #ef4540;">0
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%"><span style="color: #ef4540;">5 </span></td>
      <td valign="top" width="20%">5 limite</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #ef4540;">7
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">1 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">2 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">3 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">4 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">6 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">8 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">7 </span><br><span
                  style="color: #ef4540;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #ef4540;">5 </span><br><span
                  style="color: #ef4540;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #ef4540;">0
        </span><br><span style="color: #ef4540;"> </span></td>
      <td valign="top" width="20%"><span style="color: #ef4540;">5 </span></td>
      <td valign="top" width="20%">4 limite</td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">8
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">3 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">9
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">3 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #98ca3e;">10
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">1 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">2 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">3 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">4 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">5 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">6 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">7 </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">  </span><br><span
                  style="color: #98ca3e;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #98ca3e;">8 </span><br><span
                  style="color: #98ca3e;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">1
        </span><br><span style="color: #98ca3e;"> </span></td>
      <td valign="top" width="20%"><span style="color: #98ca3e;">3 </span></td>
      <td valign="top" width="20%"><strong><span style="color: #7d9fd3;">7
          </span></strong></td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">11
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">1 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">2 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">3 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">4 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">5 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">6 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;"> 7 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">8 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">0
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">10 </span></td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">12
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%">
        <table  border="3" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">1 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">2 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">3 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">4 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">5 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">6 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;">7 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"><span
                  style="color: #7d9fd3;"> 8 </span><br><span
                  style="color: #7d9fd3;"> </span></td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">0
        </span><br><span style="color: #7d9fd3;"> </span></td>
      <td valign="top" width="20%"><span style="color: #7d9fd3;">10 </span></td>
      <td valign="top" width="20%">8 Solução!</td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1!339598&authkey=!AIR_77DokuNpbLo&em=2"
    width="1050" height="500" frameborder="0" scrolling="no"></iframe></p>
<p style="margin-right: 0px;" dir="ltr">Nesta procura houve 12 estados gerados,
  e 8 estados expandidos. Foi encontrada a solução que passa pelos estados 12,
  10, 3, 1. </p>
<p style="margin-right: 0px;" dir="ltr">O que está nesta tabela e o que
  significam as cores? O código de cores significa que primeiro foi criado o
  estado 1 a vermelho, de seguida após a expansão 1 foram criados os estados 2 a
  4 a verde, após a expansão 2 foi criado o estado 5 a azul. Da expansão 3
  resultaram a vermelho os estados 6 e 7, as expansões 4 e 5 não resultaram
  novos estados dado que foi atingido o limite (nível a zero), e da expansão 6
  foram gerados os estados 8 a 10 a verde. Os estados 11 e 12 a azul foram
  gerados na expansão 7. <span style="text-transform: initial;">  </span></p>
<p style="margin-right: 0px;" dir="ltr"><span
    style="text-transform: initial;">Vendo a tabela mais em detalhe:</span></p>
<ul>
  <li>Na linha 1 está o estado inicial, ou seja, a posição que obtivemos quando
    desfizemos a posição inicial com 3 movimentos. Ora como partimos da
    posição inicial, sabemos que há uma solução em 3 movimentos, pelo que
    garantidamente com um algoritmo em profundidade limitado a nível 3
    encontraríamos sempre uma solução. </li>
  <li>Na primeira coluna está o número do estado, ou o número da geração do
    estado. Na segunda coluna está o estado em si. Como o algoritmo tem um nível
    de profundidade, guardamos na terceira coluna a informação do nível em que
    está a procura, marcando o estado inicial com o valor a que queremos fazer a
    procura, o valor 3, e sempre que gerarmos um estado, diminui-se este valor
    relativo ao valor do nível do estado pai. Na quarta coluna temos a
    informação do pai do estado, ou seja, o número do estado a partir do qual
    esse estado foi gerado, e no final temos o número de ordem de expansão.</li>
  <li>Começamos por expandir o primeiro estado, na linha 1, dando origem aos
    estados das linhas 2 a 4. O algoritmo prossegue expandindo não a linha 2,
    mas a última linha, a linha 4, daí o número de expansão da linha 4,
    resultando da linhas 5. Notar que o movimento inverso, que levava à posição
    inicial, não foi gerado, dado que se assume essa optimização, que evita
    alguns ciclos. A implementação desse teste é simples, dado que existe um
    campo em cada estado indicando o pai, pelo que se se gerar um filho igual ao
    pai, este pode ser imediatamente anulado.</li>
  <li>Prosseguindo, expande-se a linha 5, que gera as linhas 6 e 7, já com nível
    0. Significa que ou são solução final, ou não se pode gerar mais sucessores
    a partir desses estados, de forma a respeitar o limite de profundidade
    imposto. É o que acontece, expande-se a linha 7 e de seguida a linha 6, mas
    sem adicionar sucessores, apenas verificando se é um estado final. O último
    estado gerado mas não expandido, passa a ser o estado 3, que é expandido
    agora, em 6º lugar, gerando as linhas 8 a 10. Expande-se agora a linha 10,
    gerando as linhas 11 e 12, e ao expandir a linha 12 verifica-se que esta é
    um estado solução. O algoritmo pára, podendo reconstruir o caminho desde
    estado inicial ao estado final através da indicação dos estados pai.</li>
</ul>
<p></p>
<hr>

<details>
<summary><strong style="font-size: 0.9375rem;"> Atenção</strong><span
    style="font-size: 0.9375rem;">: Quantos estados foram gerados mas não
    expandidos?</span></summary>

Foram 4 estados gerados mas não expandidos. Correspondem às linhas que estão vazias, na coluna expansão.

</details>

\endhtmlonly

\htmlonly

<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="teste_aspirador2.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_puzzle8iterativa.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly
