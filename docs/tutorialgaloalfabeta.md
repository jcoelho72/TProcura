@page tutorial_galoalfabeta Procuras Adversas, MiniMax com cortes alfa/beta

| [Galo MiniMax](tutorial_galominimax.html) | [Galo alfa/beta](tutorial_galoalfabeta.html) | 

\htmlonly

<p>A procura efetuada anteriormente, explora todas as possibilidades,
  independentemente de serem realmente relevantes para a estratégia final ou
  não. No caso de se saber que numa linha alternativa, as brancas obtiveram um
  valor de 10, e atualmente está-se a ver uma linha em que as pretas já têm
  hipótese de optar por uma linha com 10 ou menos, então é completamente
  indiferente continuar a explorar as restantes alternativas, já que as brancas
  não irão escolher esta linha quando podem optar por uma que lhe garante um
  valor final de 10. Pode-se portanto cortar o resto da linha. Este corte
  chama-se corte alfa, dado que o valor de alfa é a melhor alternativa das
  brancas, e foi esse valor que foi utilizado de forma a suportar o corte. Se o
  raciocínio inverso fosse feito, chamar-se-ia corte beta.</p>
<p>Os valores iniciais de alfa/beta, dado que de início nem as brancas nem as
  pretas têm alternativas, são a derrota/vitória. Vamos fixar esses valores em
  -1000 (ganham as pretas) e 1000 (ganham as brancas), e repetir a procura
  anterior com os cortes alfa/beta:</p>
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
        <p align="center"><strong>Nível / Valor </strong></p>
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
      <td valign="top" width="20%">1<br>MAX <br>-1000/+1000</td>
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
      <td valign="top" width="20%">N1<br>1 </td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">4<br>MIN <br>1/+1000</td>
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
      <td valign="top" width="20%">N1<br>-1</td>
      <td valign="top" width="20%">1</td>
      <td valign="top" width="20%">3<br>MIN <br>1/+1000</td>
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
      <td valign="top" width="20%">2<br>MIN <br>-1000/+1000</td>
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
      <td valign="top" width="20%">-1000/+1000</td>
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
      <td valign="top" width="20%">-1000/1</td>
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
      <td valign="top" width="20%">1/+1000<br>(corte alfa)</td>
    </tr>
    <tr>
      <td valign="top" width="20%">8 </td>
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
      <td valign="top" width="20%">1/+1000<br>(corte alfa)</td>
    </tr>
  </tbody>
</table>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339662&amp;authkey=%21ADsS2U19ZadZ3HY&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1100" height="700" frameborder="0" scrolling="no"></iframe></p>
<p>Inicialmente o valor de alfa/beta é de -1000/+1000. Na expansão do estado 4,
  este valor é mantido, ainda não há qualquer alternativa, tal como no estado
  5. O estado 6 já é gerado, considerando que as pretas têm uma alternativa que
  é o estado 5, com valor 1. Este valor no entanto não teve nenhuma
  consequência, dado que o nível de profundidade era baixo, não tendo resultado
  em cortes.</p>
<p>A expansão do estado 3, já é feita com o conhecimento da expansão do estado
  4, onde as brancas podem optar obtendo 1. Portanto o valor de alfa é
  atualizado para 1. O primeiro estado expandido é o estado 7, que tem o valor
  -1. Ora como as brancas têm uma alternativa melhor ou igual, que vale 1, seria
  irrelevante gerar os restantes sucessores, dado que já se sabe ser preferível
  a opção das brancas pela alternativa. O corte alfa significa não gerar os
  restantes sucessores, e retorna imediatamente, mas desta vez com o valor -1 e
  não -2 como na procura exaustiva.</p>
<p>Na expansão do estado 2, o valor de alfa mantêm-se a 1, sendo gerado o estado
  8 com o valor igual à melhor alternativa das brancas, o valor 1. Continuar
  explorando os restantes sucessores seria inconsequente para o valor final a
  retornar, dado que se as pretas encontrassem um estado melhor (portanto mais
  baixo), as brancas escolheriam a alternativa, pelo que pode-se dar também o
  corte alfa, e prescindir da geração dos restantes sucessores. O valor a
  retornar é neste caso 1.</p>
<p>A estratégia calcula-se da mesma forma, neste caso é 1,4,5, tendo que se ter
  em atenção que apenas o valor dos primeiros estados com o valor do estado, é
  que têm o seu valor correcto, os restantes podem ter o valor incorreto devido
  a cortes. Seria incorreto considerar válida a estratégia: 1,2,8, já que o
  estado 2 embora tenha o mesmo valor que o estado pai 1, existe um estado irmão
  expandido/gerado primeiro com o valor igual, que é o estado 4, pelo que o
  valor do estado 2 pode não ser o correcto. Na realidade sabemos que não é
  realmente o correcto, do exemplo anterior o valor desse estado seria -1.</p>
<hr>
<details>
<summary><strong>⚡ Ação:</strong> Faça
  o MiniMax com cortes alfa/beta para o estado 4, nas condições acima, e indique
  quantos cortes alfa/beta executou.</summary>

Resposta:

</details>


\endhtmlonly

| [Galo MiniMax](tutorial_galominimax.html) | [Galo alfa/beta](tutorial_galoalfabeta.html) | 
