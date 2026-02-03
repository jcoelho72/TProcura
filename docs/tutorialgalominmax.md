@page tutorial_galominimax Procuras Adversas, Jogo do Galo, MinMax

\htmlonly

<div style="padding:12px; border:1px solid #444; border-radius:6px; background:#222; margin:20px 0; color:#ddd;">
  <div style="font-size:12px; opacity:0.8; margin-bottom:6px;">
    <a href="tutorial_adversas.html" style="color:#9cf; text-decoration:none;">Tutorial: Procuras Adversas</a>
  </div>
  <div style="display:flex; flex-wrap:wrap; gap:12px; justify-content:center;">
    <a href="tutorial_adversaslit.html" style="color:#9cf;">📖 Literatura</a>
    <a href="tutorial_adversas5a.html" style="color:#9cf;">👓 Introdução</a>
    <a href="tutorial_adversas5b.html" style="color:#9cf;">👓 MiniMax</a>
    <a href="tutorial_adversas5c.html" style="color:#9cf;">👓 Monte Carlo</a>
    <span style="font-weight:bold; text-decoration:underline; color:#fff;">✏️ Galo MiniMax</span>
    <a href="tutorial_galoalfabeta.html" style="color:#9cf;">✏️ Galo alfa/beta</a>
    <a href="teste_jogo_do_galo.html" style="color:#9cf;">💻 Jogo do Galo</a>
    <a href="teste_jogo_em_linha.html" style="color:#9cf;">💻 Jogo em Linha</a>
  </div>
</div>


\endhtmlonly


\htmlonly

<p>As procuras anteriores consideram que se está a tentar realizar um
  determinado objectivo, sem qualquer oposição. No caso dos jogos, tenta-se
  também realizar um objectivo, no entanto há outros agentes a tentar realizar
  os seus próprios objetivos. O caso mais simples, é quando há apenas dois
  agentes, com objetivos opostos, um jogo entre dois adversários.</p>
<p></p>
<p>O <strong>jogo do galo</strong> joga-se num tabuleiro de 3x3, em que cada
  jogador coloca à vez a sua marca num quadrado vazio. O objectivo do jogo é
  obter 3 marcas em linha reta (horizontal, vertical ou diagonal).</p>
<p>O <strong>MiniMax</strong> funciona de modo idêntico ao algoritmo de
  profundidade primeiro, mas em cada estado final tem o valor de
  vitória/derrota/empate (para as brancas, que é o jogador que começa a jogar).
  Se o nível máximo foi atingido e ainda não é um estado final, deve ser
  retornada uma estimativa para o valor do estado, aproximando-se do valor da
  vitória no caso da posição estar favorável às brancas, ou próximo do valor
  derrota no caso da posição estar favorável às pretas. Em cada estado, o
  MiniMax retorna o valor máximo dos seus sucessores, no caso de ser as brancas
  a jogar, e o valor mínimo dos seus sucessores, no caso de ser as pretas a
  jogar. Após correr, obtêm-se uma estratégia de jogo com base nos sucessores
  que determinaram o valor de cada estado.</p>
<p>No jogo do galo, pode-se remover estados simétricos, considerando a simetria
  horizontal, vertical e diagonal. Relativamente à função com a estimativa do
  estado, vamos considerar o seguinte: somar as possibilidades a duas jogadas de
  ganhar o jogo, e subtrair as do adversário, somando também as possibilidades
  de ganhar a uma jogada mas com peso 10.</p>
<p></p>
<p>Vamos fazer a procura do MiniMax com nível de profundidade limite 2:</p>
<p></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Nível/Valor</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Pai</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Expansão</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N2<br>1</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">1<br>MAX</td>
    </tr>
    <tr>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N1<br>-1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">4<br>MIN</td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N1<br>-2</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">3<br>MIN</td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N1<br>1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2<br>MIN</td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>1</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>2</td>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>-1</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>0</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">9</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>-2</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">10</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>-1</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">11</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>0</td>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">12</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>1</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">13</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>0</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">14</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>-1</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">15</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>1</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">16</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>0</td>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339660&amp;authkey=%21AAGLr2ztJ1ygvo4&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!G5&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1100" height="700" frameborder="0" scrolling="no"></iframe></p>
<p>A expansão é feita como se fosse um algoritmo em profundidade. O estado 1 ao
  ser expandido gera os estados 2 a 4. Não gera mais porque os restantes
  sucessores são idênticos aos três gerados a menos de operações de simetrias
  (horizontal, vertical, diagonal). Esses três estados ficam no nível 1, já que
  o estado 1 está no nível 2, e enquanto o estado 1 procura maximizar, os
  estados 2 a 4 procuram minimizar, daí a indicação de MAX e MIN.</p>
<p>O estado 4 é expandido, dando lugar aos estados 5 e 6, de nível 0. Como são
  de nível 0, não há lugar a mais expansões, pelo que é calculado o valor do
  estado. O estado 5 tem 3 hipóteses de vitória a dois lances para as brancas, e
  2 hipóteses de vitória a dois lances para as pretas, ficando portanto com
  valor 1. Já o estado 6 tem 3 hipóteses para as brancas contra 1 hipótese para
  as pretas, ficando com valor 2. Como o estado 4 procura minimizar, o valor do
  estado 4 fica com o valor 1, que é o mínimo entre 1 e 2.</p>
<p>Expande-se o estado 3, resultando nos estados 7 a 11, com valores entre -2 e
  0. Como se pretende minimizar, o valor do estado 3 é -2. Repetindo-se o
  processo para o estado 2, obtêm-se o valor de -1 para esse estado.</p>
<p>Após explorar todos os sucessores do estado 1, pode-se calcular o seu valor,
  com base no valor máximo dos seus sucessores, dado que é um estado MAX. entre
  -2, -1 e 1, o valor máximo é 1.</p>
<p>A estratégia resultante é portanto a seguinte: as brancas devem optar pelo
  estado 4, e no segundo lance, as pretas devem optar pelo estado 5, de forma a
  cada força maximizar as suas possibilidades: 1,4,5</p>
<p>Naturalmente que a estratégia resultante de uma procura com maior
  profundidade pode ser diferente.</p>
<hr>
<details>
<summary><strong>⚡ Ação</strong>: Assuma
  que as brancas jogaram para o estado 4, e volte a repetir este algoritmo.
  Indique qual é agora a nova estratégia, com o número dos estados separados por
  vírgulas, como indicado acima: 1,4,5</summary>

<p dir="ltr" style="text-align: left;"><strong>Resposta</strong>: 1,2,9</p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="20%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Nível/Valor</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Pai</strong></p>
      </td>
      <td valign="top" width="20%">
        <p align="center"><strong>Expansão</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N2<br>12</td>
      <td valign="top" width="20%">0</td>
      <td valign="top" width="20%">1<br>MIN</td>
    </tr>
    <tr>
      <td valign="top" width="20%">2</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N1<br>12 </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">3<br>MAX</td>
    </tr>
    <tr>
      <td valign="top" width="20%">3</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N1<br>13 </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">2<br>MAX</td>
    </tr>
    <tr>
      <td valign="top" width="20%">4</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>13</td>
      <td valign="top" width="20%">3 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">5</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>12</td>
      <td valign="top" width="20%">3 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">6</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>13 </td>
      <td valign="top" width="20%">3 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">7</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>3 </td>
      <td valign="top" width="20%">3 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">8</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>11 </td>
      <td valign="top" width="20%">2 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">9</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>12 </td>
      <td valign="top" width="20%">2 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">10</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%">X</td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>11 </td>
      <td valign="top" width="20%">2 </td>
      <td valign="top" width="20%"> </td>
    </tr>
    <tr>
      <td valign="top" width="20%">11</td>
      <td valign="top" width="20%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td valign="top" width="33%">O</td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
              <td valign="top" width="33%"> </td>
            </tr>
            <tr>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%"> </td>
              <td valign="top" width="33%">X</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="20%">N0<br>3</td>
      <td valign="top" width="20%">2 </td>
      <td valign="top" width="20%"> </td>
    </tr>
  </tbody>
</table>
</details>


<div style="margin:30px 0; display:flex; justify-content:space-between;">
  <a href="tutorial_adversas5c.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     ◀ Passo anterior </a>
  <a href="tutorial_galoalfabeta.html" style="padding:6px 12px; background:#222; border:1px solid #444; border-radius:4px; color:#9cf;">
     Próximo passo ▶ </a>
</div>

\endhtmlonly

