@page tutorial_4damasescalada 4 Damas, Escalada do Monte

| [4 damas escalada](tutorial_4damasescalada.html) | [4 damas genético](tutorial_4damasgenetico.html) |

\htmlonly

<h1>4 Damas, Escalada do Monte</h1>
<p style="margin-right: 0px;" dir="ltr">Até este momento, os algoritmos
  apresentados exploraram o espaço de estados, em que uma solução vai sendo
  construída passo a passo. Ao obter o estado objectivo, obtêm-se a solução
  pretendida através do caminho desde o estado inicial ao estado objectivo. A
  procura desenrola-se no espaço das soluções parciais, dado que cada
  estado representa uma solução parcial do problema. Estes algoritmos chamam-se
  algoritmos construtivos, dado que tentam construir a solução.</p>
<p>Os algoritmos melhorativos desenrolam-se no espaço das soluções completas, em
  vez do espaço das soluções parciais, dado que cada estado representa uma
  solução completa do problema. Ao movimentarem-se de solução completa em
  solução completa, tentam melhorar a solução obtida, daí o nome atribuído de
  algoritmos melhorativos.</p>
<p>A <strong>escalada do monte</strong> começa num estado aleatório, e com base
  numa vizinhança definida, move-se para o estado vizinho que tiver melhor valor
  que o estado atual. Se todos os vizinhos forem iguais ou inferiores, então
  está-se num óptimo local: a procura pára caso já se tenha atingido o critério
  de paragem, ou recomeça novamente num outro estado aleatório. Na
  implementação há que optar por forçar a geração de todos os vizinhos, de forma
  a mover a procura para o vizinho mais promissor, ou mover a procura
  imediatamente assim que encontrar um vizinho melhor que o atual.</p>
<p>Vamos ver o caso das 4 Damas. Vamos considerar um estado, uma linha para cada
  dama de uma coluna, ou seja, em cada coluna colocar uma dama numa das linhas.
  Uma possível solução seria as damas todas na primeira linha. Nesse caso essa
  solução violaria a restrição das damas não se atacarem mutuamente. Para que o
  algoritmo procure uma solução sem essa restrição violada, o valor de cada
  solução considerada, é o número de pares de damas que se atacam mutuamente.
</p>
<p></p>
<table border="3" cellspacing="3" cellpadding="3">
  <tbody>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%">X</td>
      <td style="text-align: center;" valign="top" width="25%">X</td>
      <td style="text-align: center;" valign="top" width="25%">X</td>
      <td style="text-align: center;" valign="top" width="25%">X</td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Este estado, há 6 pares de damas a
  atacarem-se mutuamente. Portanto o valor da solução é 6, e pretende-se achar
  uma solução que minimize o número de pares de damas atacadas, ou seja, zero.
  Para gerar uma solução aleatória, basta gerar 4 números entre 1 e 4 para as
  posições de cada dama. Por exemplo, a sequência 3, 2, 4, 1 iria gerar o
  estado:</p>
<p style="margin-right: 0px;" dir="ltr"></p>
<table border="3" cellspacing="3" cellpadding="3">
  <tbody>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%">X</td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"><strong>X
        </strong></td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"><strong>X
        </strong></td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
    </tr>
    <tr>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%"> </td>
      <td style="text-align: center;" valign="top" width="25%">X</td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Neste estado apenas um par de damas está
  atacado.</p>
<p style="margin-right: 0px;" dir="ltr">Falta agora definir a vizinhança. Esta
  função tem de permitir a navegação pelo espaço de estados, permitindo em
  teoria que o algoritmo possa navegar entre dois pares de estados arbitrários.
  No entanto, se um estado tiver muitos vizinhos, tal pode ser também
  prejudicial ao algoritmo, pelo que vamos considerar os vizinhos que trocam
  apenas a posição de uma dama, mas apenas se a dama estiver atacada. Vamos
  iniciar o algoritmo desse estado:</p>
<p style="margin-right: 0px;" dir="ltr"></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="33%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="33%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="33%">
        <p align="center"><strong>Valor</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="33%">1</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%"><strong>1</strong></td>
    </tr>
    <tr>
      <td valign="top" width="33%">2</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">2</td>
    </tr>
    <tr>
      <td valign="top" width="33%">3</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">2</td>
    </tr>
    <tr>
      <td valign="top" width="33%">4</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">2</td>
    </tr>
    <tr>
      <td valign="top" width="33%">5</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">2</td>
    </tr>
    <tr>
      <td valign="top" width="33%">6</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">3</td>
    </tr>
    <tr>
      <td valign="top" width="33%">7</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">1</td>
    </tr>
  </tbody>
</table>
<p></p>
<p style="margin-right: 0px;" dir="ltr">Os vizinhos todos do estado 1 foram
  analisados, no entanto apenas um dos vizinhos tem o mesmo valor, não existindo
  nenhum vizinho melhor, portanto estamos num óptimo local. O algoritmo poderia
  acabar aqui, ou então reiniciar, no caso do critério de paragem não ter sido
  atingido. Vamos reiniciar, e os 4 números aleatórios seguintes são: 3, 3, 4,
  2.</p>
<p style="margin-right: 0px;" dir="ltr"></p>
<table border="2" cellspacing="2" cellpadding="2">
  <tbody>
    <tr>
      <td valign="top" width="33%">
        <p align="center"><strong>Geração</strong></p>
      </td>
      <td valign="top" width="33%">
        <p align="center"><strong>Estado</strong></p>
      </td>
      <td valign="top" width="33%">
        <p align="center"><strong>Valor</strong></p>
      </td>
    </tr>
    <tr>
      <td valign="top" width="33%">8</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%">
                <strong>X</strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%"><strong>2</strong></td>
    </tr>
    <tr>
      <td valign="top" width="33%">9 </td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">3</td>
    </tr>
    <tr>
      <td valign="top" width="33%">10 </td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">4</td>
    </tr>
    <tr>
      <td valign="top" width="33%">11</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">1</td>
    </tr>
    <tr>
      <td valign="top" width="33%">12</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">3</td>
    </tr>
    <tr>
      <td valign="top" width="33%">13</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                  <br></strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">2</td>
    </tr>
    <tr>
      <td valign="top" width="33%">14</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%">X</td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%"><strong>0</strong></td>
    </tr>
    <tr>
      <td valign="top" width="33%">15</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">4</td>
    </tr>
    <tr>
      <td valign="top" width="33%">16</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">3</td>
    </tr>
    <tr>
      <td valign="top" width="33%">17</td>
      <td valign="top" width="33%">
        <table border="3" cellspacing="3" cellpadding="3">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
              <td style="text-align: center;" valign="top" width="25%"><strong>X
                </strong></td>
              <td style="text-align: center;" valign="top" width="25%"> </td>
            </tr>
          </tbody>
        </table>
      </td>
      <td valign="top" width="33%">3</td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339644&amp;authkey=%21AGdyYchXeznaiuk&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1500" height="750" frameborder="0" scrolling="no"></iframe></p>
<p style="margin-right: 0px;" dir="ltr">Foram gerados 17 estados, os quais foram
  avaliados, e obteve-se a solução óptima. Notar que o algoritmo adoptado,
  explorou-se toda a vizinhança antes de decidir move o algoritmo para um estado
  melhor. Caso se tivesse optado por mover o algoritmo assim que encontre um
  melhor vizinho, na geração 11, parava-se a geração dos vizinhos do estado 8, e
  iniciava-se a geração dos vizinhos do estado 11.</p>
<p style="margin-right: 0px;" dir="ltr">Para ter uma melhor noção de como
  funciona esta procura, execute a procura novamente com outros valores
  aleatórios: imprima da template de resolução a folha "Melhorativas (4x4)", e
  utilize os números aleatórios à direita. </p>
<hr>
<details>
<summary><strong>⚡ Ação:</strong> Neste
  caso, se se optar por mover para o primeiro vizinho que seja melhor, não se
  encontrava a solução óptima nesta procura procura. Indique na resposta quantos
  mais estados seriam gerados, até se atingir um óptimo local.</summary>

<p><strong>Resposta</strong>: 6<br><br>Apenas os vizinhos seriam analisados, e
  como há 2 damas atacadas, há 6 vizinhos, e nenhum deles é melhor que a solução
  atual, pelo que é um óptimo local.</p>

</details>

\endhtmlonly

| [4 damas escalada](tutorial_4damasescalada.html) | [4 damas genético](tutorial_4damasgenetico.html) |
