@page tutorial_puzzle8bnb Puzzle8, BnB

| [Puzzle 8 melhor](tutorial_puzzle8melhor.html) | [Puzzle 8 Astar](tutorial_puzzle8astar.html) | [Puzzle 8 BnB](tutorial_puzzle8bnb.html) | 

\htmlonly

<p>Vamos agora manter o mesmo estado, e utilizar o Branch-and-Bound em vez do
  A-Start:</p>
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
    <tr>
      <td style="text-align: center;" valign="top" width="14%">cima</td>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">2</td>
              <td style="text-align: center;" valign="top"> </td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top">6</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">8</td>
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
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top">2</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top">6</td>
              <td style="text-align: center;" valign="top">3</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">7</td>
              <td style="text-align: center;" valign="top">5</td>
              <td style="text-align: center;" valign="top">8</td>
            </tr>
          </tbody>
        </table>
      </td>
      <td style="text-align: center;" valign="top" width="14%">baixo</td>
      <td valign="top" width="14%">
        <table border="3" width="100" cellspacing="3" cellpadding="3"
          align="middle">
          <tbody>
            <tr>
              <td style="text-align: center;" valign="top">1</td>
              <td style="text-align: center;" valign="top">6</td>
              <td style="text-align: center;" valign="top">2</td>
            </tr>
            <tr>
              <td style="text-align: center;" valign="top">4</td>
              <td style="text-align: center;" valign="top"> </td>
              <td style="text-align: center;" valign="top">3</td>
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
<p style="margin-right: 0px;" dir="ltr">A <strong>procura Branch-and-Bound
    (BnB)</strong> é uma procura aparentada com o melhor primeiro. No entanto, o
  melhor primeiro suspende a procura após encontrar a primeira solução. O BnB
  continua mas limitando a procura ao espaço de soluções que pode de facto
  melhorar a melhor solução encontrada. O valor da melhor solução encontrada é o
  Upper-Bound (UB), um limite máximo. O valor da heurística mais o custo num
  dado nó da árvore de procura, é o Lower Bound (LB), um limite mínimo.</p>
<p style="margin-right: 0px;" dir="ltr">A procura é cortada sempre que o LB é
  maior ou igual ao UB. Daí para baixo, sabemos que nunca encontraremos uma
  solução que melhore a que já temos, pelo que podemos corta a árvore de
  procura.</p>
<p style="margin-right: 0px;" dir="ltr">O nome do algoritmo deve-se às duas
  principais ações. O branch, é a ramificação ou geração de sucessores. De um
  estado são gerados os estados possíveis. Sem esta operação não seria possível
  explorar o espaço de estados. O bound é a operação de teste, verificar se
  LB&gt;=UB, de modo a cortar a árvore de procura sempre que possível.</p>
<p style="margin-right: 0px;" dir="ltr">O primeiro valor do UB deverá ser
  infinito, de modo a retornar a solução ótima. No entanto versões iterativas
  são possíveis. Caso se utilize um UB fictício K, se a árvore for completamente
  explorada sem encontrar uma única solução, então temos um LB=K+1. Caso se
  encontre uma solução, então a solução retornada será sempre ótima. Caso o
  algoritmo seja interrompido, se já encontrou uma solução, será um UB, mas sem
  garantia de otimalidade.</p>
<p style="margin-right: 0px;" dir="ltr">A vantagem deste algoritmo sobre o A* é
  a memória. Como procura em profundidade que é, não necessita de um grande
  volume de estados abertos não expandidos. No entanto a complexidade temporal é
  igual ao A*. O A* ao ser interrompido, podemos utilizar a menor heurística
  mais custo, como LB da instância, enquanto que se o BnB for interrompido,
  podemos utilizar o UB atual como um UB da instância.</p>
<p style="margin-right: 0px;" dir="ltr">Como temos um UB global, o passo a passo
  via tabela torna-se ainda mais complexo de perceber, pelo que deixa-se apenas
  a versão do ficheiro de Excel:</p>
<p style="margin-right: 0px;" dir="ltr">Ficheiro de Excel, passo a passo:</p>
<p><iframe
    src="https://onedrive.live.com/embed?resid=CB9D74B9743B54E1%21339649&amp;authkey=%21AG6tMTg7iMRde-4&amp;em=2&amp;wdAllowInteractivity=False&amp;ActiveCell='exp0'!A1&amp;wdHideGridlines=True&amp;wdHideHeaders=True&amp;wdDownloadButton=True&amp;wdInConfigurator=True&amp;wdInConfigurator=True"
    width="1700" height="600" frameborder="0" scrolling="no"></iframe></p>
<p style="margin-right: 0px;" dir="ltr">Neste exemplo, utilizamos um UB inicial
  de 10. Este valor é importante em problemas como o puzzle 8, em que não há
  limite de profundidade. O BnB antes de encontrar uma primeira solução, poderia
  perder-se. Ao indicarmos que apenas estamos interessados em soluções de 9 ou
  inferior, esse problema é resolvido.</p>
<p style="margin-right: 0px;" dir="ltr">Após a primeira expansão, há 4 estados.
  Mas apenas 2 têm o LB menor, igual a 5. Como o BnB é uma procura em
  profundidade, expandimos o último com menor LB, de entre os estados com o
  mesmo pai.</p>
<p style="margin-right: 0px;" dir="ltr">Na expansão 4, são gerados os <span
    style="font-size: calc(0.90375rem + 0.045vw);">estados 9 e 10. Esses estados
    são cortados dado que o LB=10 e o UB=10. Assim, continuando a explorar esses
    nós, nunca se poderia atingir uma solução com UB menor que 10, pelo que se
    corta esse ramo.</span></p>
<p style="margin-right: 0px;" dir="ltr"><span
    style="font-size: calc(0.90375rem + 0.045vw);">A procura retrocede para o
    nível anterior, dado que não há mais sucessores, expandido o estado 6.
    Ocorre o corte novamente.</span></p>
<p style="margin-right: 0px;" dir="ltr"><span
    style="font-size: calc(0.90375rem + 0.045vw);">A procura retrocede, mas para
    um ponto em que há ainda 3 estados por expandir. Assim, expandimos o estado
    2 que é o outro estado com menor LB. Notar que o LB se fosse perfeito, no
    estado 5 teria de dar um valor 10 ou superior, dado que esse estado foi
    explorado e não foi encontrada uma solução com UB=10. Um bom LB influencia
    grandemente a performance deste algoritmo. Mesmo este LB não sendo perfeito,
    evita continuar pelos estados 3 e 4 que têm logo um LB superior a 6, que
    sabemos ser o valor ótimo.</span></p>
<p style="margin-right: 0px;" dir="ltr"><span
    style="font-size: calc(0.90375rem + 0.045vw);">A partir deste ponto, o LB
    acerta sempre, guiando a procura para a solução ótima, obtida na expansão
    10. No entanto, se o algoritmo for interrompido na expansão 10, não sabemos
    que a solução é ótima. Temos de explorar os estados gerados não
    expandidos.</span></p>
<p style="margin-right: 0px;" dir="ltr"><span
    style="font-size: calc(0.90375rem + 0.045vw);">Na expansão 11 procura-se
    expandir todos os estados pendentes, mas com o novo UB, são todos cortados.
    Com o UB=10 não seriam cortados, mas com a nova informação é possível assim
    cortar rapidamente a árvore. É portanto importante que sejam explorados
    primeiro os estados melhores, e se encontre rapidamente uma boa solução,
    para se poder cortar mais a árvore de procura. Novamente, um bom LB pode
    contribuir para que tal ocorra.</span></p>
<hr>
<details>
<summary><strong>⚡ Ação:</strong> Explorar
  o ficheiro de Excel, procurando reproduzir o BnB com outra instância de 4
  movimentos aleatórios. Apresente o resultado no fórum. </summary>

<p><strong>Resposta</strong>: pergunta aberta. Colocar a resposta no fórum de
  modo a validar com a equipa docente e colegas.</p>

</details>

\endhtmlonly

| [Puzzle 8 melhor](tutorial_puzzle8melhor.html) | [Puzzle 8 Astar](tutorial_puzzle8astar.html) | [Puzzle 8 BnB](tutorial_puzzle8bnb.html) | 
