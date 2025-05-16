@page teste_aspirador Teste Aspirador

Execução de exemplo com base no problema do Aspirador. Pode acompanhar o teste excutando as ações localmente.

```entrada
Teste TProcurasConstrutivas
Problema:
  1 - Aspirador
  2 - Puzzle 8
  3 - 8 Damas
  4 - Partição
  5 - Artificial
Opção: 1
```

![Aspirador - espaço de estados para 2 salas](docs/images/aspirador.png)

Selecione o problema do Aspirador: **1.**

A versão deste problema foi generalizada no código para poderem existir N salas, uma ou lado das outras, e não apenas 2 como no manual, sendo em tudo o resto igual.


```entrada
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
 *  * [.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Esta é a informação apresentada no teste manual. 
Na zona superior aparece o nome do problema, seguido dos parametros e valores atuais.
Podemos ver que o primeiro parametro é o algoritmo, e está selecionado de omissão a Largura Primeiro.
Em termos de Debug está selecionado o valor nada, ou seja, não é mostrada informação de debug.
Seguem-se outros parametros, os quais alguns serão apresentados ao longo desta execução.

Termina com a linha que tem estatísticas sobre a última execução efetuadal. 
Após esta linha está o estado atual, que tem uma visualização dependente do problema.

Após o estado temos o menu, com as opções de inicializar numa nova instância, 
explorar o espaço de estados, ver a solução/caminho atual, alterar parametros,
executar o algoritmo selecionado com os parametros atuais, gravar configuração
e executar um teste empírico.

## Ação 1 - Trocar de instância

Escreva os seguintes números separados por Enter: **1; 2**

Tínhamos inicialmente uma instância com 4 salas, estando o aspirador na terceira sala, estando as duas primeiras sujas:

```entrada
Opção: 1

Nova instância (atual 4) [2-50]: 2

Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
 * [*]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Agora temos uma instância com 2 salas, estando ambas sujas, e o aspirador está na segunda:
A representação do estado é algo que é implementado na sub-classe (neste caso em CAspirador::Debug()), de modo a se poder visualizar o estado em que estamos. 
Ao chamar a SolucaoVazia podemos trocar o ID da instância. 
Para este problema o ID é utilizado para definir a dimensão da instância, e assim podemos escolher em ter uma instância maior ou menor. 
A sujidade das casas é gerada aleatoriamente. 
No entanto a semente aleatória é um parâmetro, sendo sempre a mesma caso não se altere, 
garantindo assim que podemos obter a mesma instância mais tarde.

## Ação 2 - Explorar os sucessores

A partir do estado atual, introduza: **2; 1; 2.**

```entrada
Opção: 2
g:0 h:3 1|2
 * [*]
Ações: esq asp
Sucessor [1-2, ação(ões), exe]:1
g:0 h:3 2|4
[*] *
Ações: dir asp
Sucessor [1-2, ação(ões), exe]:2
g:0 h:2 3|6
[.] *
Ações: dir asp
```

Podemos ver que o estado atual tem dois sucessores, o aspirador pode ir para a sala da esquerda, ou aspirar a sala atual. 
Escolhemos o primeiro estado, e depois escolhemos o segundo, aspirar. 
Os sucessores são visualizados pelas suas ações, existindo três possíveis ações: esq, dir, asp.
Para indicar o número do sucessor, é preciso ver, já que o número 1 é para a primeira ação válida, na lista de sucessores. 
No entanto, as ações são unívocas. Podemos indicar várias ações de uma só vez.

Neste momento estamos na sala da esquerda, com a sala limpa, mas a sala da direita está suja. 
Complete os movimentos necessários para limpar ambas as salas, e saia da exploração dos sucessores.
Utilize desta vez o nome das ações e não número, introduzido duas ações de uma vez. Introduza: **dir asp; *ENTER*.**
Note que "dir asp" podem ser introduzidas de uma vez.

```entrada
Sucessor [1-2, ação(ões), exe]:dir asp
Executadas 2 ações com sucesso.
g:0 6|12
 . [.]
Ações: esq asp
Sucessor [1-2, ação(ões), exe]:

Aspirador
...
[Estatísticas] expansões 6 | gerações 12 | avaliações 0
 . [.]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Para um problema novo, é sempre importante que explore os sucessores, nomeadamente procure resolver instâncias pequenas. 
Tem duas vantagens: identifica bugs que tenha na sua implementação; ganha entendimento sobre o problema em questão, 
que lhe poderá levar a identificar optimizações que de outra foram lhe passariam desapercebidas.

## Ação 3 - Ver a solução/caminho realizada manualmente

Introduza: **3.**

```entrada
Opção: 3

 * [*] (g:0)  esq asp dir asp
 . [.] (g:4)
Aspirador
...
[Estatísticas] expansões 7 | gerações 14 | avaliações 0
 . [.]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Neste problema uma solução é um conjunto de ações, o caminho desde o estado inicial até ao estado final. 
É mostrado esse caminho visualizando as ações a partir do estado inicial. 
Foram 4 movimentos, mas houve um desperdício. No primeiro movimento, poderíamos ter logo aspirado. 
Em outros problemas, a solução pode ser apenas o estado final. Notar ainda na letra g, seguida de um número. 
Esta letra representa o custo g(n) no manual, e sempre que ocorra significa o custo desde o estado inicial até esse estado. 
Neste problema o custo não foi definido, pelo que é adoptado o valor de 1 unidade por cada movimento. 

A visualizaçãop de ações é mais curta e simples, mas podemos ver todos os estados também.
Para isso é preciso alterar o parâmetro P3(Ver).

## Ação 4 - Ver a alterar um parâmetro

Introduza: **4**

```entrada
Opção: 4

P1(Algoritmo): Largura Primeiro (1 a 7)
P2(Debug): nada (0 a 4)
P3(Ver): 4 (1 a 100)
P4(Seed): 1 (1 a 1000000)
P5(Tempo): 10 (1 a 3600)
P6(Gerações): 0 (0 a 1000000000)
P7(Expansões): 0 (0 a 1000000000)
P8(Avaliações): 0 (0 a 1000000000)
P9(Limite): 0 (-1 a 1000000)
P10(Repetidos): ignorar (1 a 3)
P11(pesoAStar): 100 (0 a 10000)
P12(ruido): 0 (-100 a 100)
P13(baralhar): 0 (0 a 1)
```
Podemos ver todos os os parâmetros e valores mínimos e máximos. 
Podemos também editar qualquer parâmetro, como é o caso, o parâmetro 3, tem o valor 4, e pretendemos colocar a 1.
Caso seja definido no problema novos parâmetros, ficariam aqui também expostos ao utilizador para edição.
Introduza: **3; 1; *ENTER*; 3.**

```entrada
Opção: 4

P1(Algoritmo): Largura Primeiro (1 a 7)
P2(Debug): nada (0 a 4)
P3(Ver): 4 (1 a 100)
...
Parametro:3

Mostra estado a cada K ações. Se 1 mostra sempre estados e nunca ações.
Ver (atual 4): 1

P1(Algoritmo): Largura Primeiro (1 a 7)
P2(Debug): nada (0 a 4)
P3(Ver): 1 (1 a 100)
...
Parametro:

Aspirador
...
[Estatísticas] expansões 7 | gerações 14 | avaliações 0
 . [.]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
Opção: 3

 * [*] (g:0)
[*] *  (g:1)
[.] *  (g:2)
 . [*] (g:3)
 . [.] (g:4)
Aspirador
...
[Estatísticas] expansões 7 | gerações 14 | avaliações 0
 . [.]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Vemos agora a solução, o caminho com todos os estados intermédios do estado inicial até ao estado final.

## Ação 5 - Efetuer uma procura em Largura

![Procura em Largura - expande primeiro os estados menos profundos](docs/images/aspirador_largura.png)

Coloque na instância inicial, número 2, com nível de debug máximo: **1; 2; 4; 2; 4; *ENTER*; 5.**

A opção 1 já sabemos, inicia uma instância, neste caso 2. A opção 4 vamos alterar neste caso o parâmetro nível de debug. 
Há vários níveis de debug, sendo o 4 o valor que mostra a informação mais completa, embora extensa. 

```entrada
Opção: 1

Nova instância (atual 2) [2-50]: 2

Aspirador
...
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
Opção: 4

P1(Algoritmo): Largura Primeiro (1 a 7)
P2(Debug): nada (0 a 4)
...
Parametro:2

Nível de debug, de reduzido a completo.
0: nada
1: atividade
2: passos
3: detalhe
4: completo
Debug (atual 0): 4

P1(Algoritmo): Largura Primeiro (1 a 7)
P2(Debug): completo (0 a 4)
...
Parametro:
...
[Estatísticas] expansões 0 | gerações 0 | avaliações 0
 * [*]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
A opção 5 executa o algoritmo selecionado, que é a Largura Primeiro.

```entrada
Opção: 5

g:0
 * [*]
  +#1 g:1 1|2 esq
  |[*] *
  +#2 g:1 1|2 asp
    * [.]
g:1 1|2
[*] *
  +#1 g:2 2|4 dir
  | * [*]
  +#2 g:2 2|4 asp
   [.] *
g:1 2|4
 * [.]
  +#1 g:2 3|6 esq
  |[*] .
  +#2 g:2 3|6 asp
    * [.]
g:2 3|6
 * [*]
  +#1 g:3 4|8 esq
  |[*] *
  +#2 g:3 4|8 asp
    * [.]
g:2 4|8
[.] *
  +#1 g:3 5|10 dir
  | . [*]
  +#2 g:3 5|10 asp
   [.] *
g:2 5|10
[*] .  Solução encontrada!
[.] . (g:3)
P1:1 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
Resultado: 3 (0,019s)
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 6 | gerações 12 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Verificar que o número de expansões é 6 e gerações é 12. O resultado da procura é 3, o que significa que a procura encontrou uma solução de comprimento 3.
Podemos ver a solução. Introduza: **3.**

```entrada
Opção: 3

 * [*] (g:0)
 * [.] (g:1)
[*] .  (g:2)
[.] .  (g:3)
Aspirador
...
[Estatísticas] expansões 6 | gerações 12 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Verifique que tem apenas 3 movimentos, ao contrário dos 4 obtidos na resolução manual.

A árvore da procura em largura não é desenhada na visualização textual, apenas na procura em profundidade. 
Nesta procura o que podemos ver é cada estado expandido e respetivos sucessores gerados. 
Cada estado irá aparecer pela primeira vez quando é gerado, e uma segunda vez quando é expandido. 
Na procura em largura, expandimos sempre o estado gerado há mais tempo.

- Verificar que o segundo estado expandido, é o primeiro sucessor do primeiro estado expandido. 
O terceiro estado expandido é o segundo sucessor do primeiro estado expandido. 
Poder-se-ia continuar, o estado expandido seguinte é sempre o gerado há mais tempo.


Temos no entanto o mesmo estado inicial a ser gerado. De facto, o primeiro sucessor na segunda expansão, 
é o primeiro estado que é gerado novamente.

Podemos lidar com estados repetidos de duas formas:

- Verificar se o estado a ser gerado, não tem já um ascendente - neste caso é preciso implementar a função Distinto() - Para fazer esta validação, o código tem de seguir pelos pais, e testar se são diferentes do atual.
- Verificar se o estado a ser gerado, não foi já gerado mesmo em outro ramo, desde que no mesmo nível ou anterior. Nesse caso o estado pode ser excluído, já que já terá sido tratado nesse outro ramo - para ter esta opção, é preciso implementar a função Codificar() que coloca o estado num vetor de bits - o código utiliza uma hashtable com perdas, para verificar se o estado já foi criado em tempo constante, não existindo problemas de memória mesmo em execuções longas devido às perdas. 

## Ação 6 - Editar opções A

Altere a opção para remover os repetidos com base nos ascendentes, e o debug para nível 3: **1; 2; 4; 10; 2; 2; 3; *ENTER*; 5.**

- Verificar que o número de expansões é 5 e gerações é 6, uma melhoria.  O resultado da procura mantém-se em 3.

```entrada
Opção: 5

g:0
 * [*]
g:1 1|2
[*] *
g:1 2|3
 * [.]
g:2 3|4
[.] *
g:2 4|5
[*] .  Solução encontrada!
[.] . (g:3)
P1:1 P2:3 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:2
P11:100 P12:0 P13:0
Resultado: 3 (0,013s)
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): detalhe | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ascendentes | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 5 | gerações 6 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
A interação de troca de parâmetro não é mais mostrada para não saturar o texto. 
Caso esteja a reproduzir o teste, confirme que tem os parâmetros iguais aos valores atuais, visiveis na interface.

Podemos ver o nível de debug a 3. Tem apenas os estados expandidos, mas não vemos os estados gerados. 
Mesmo assim podemos confirmar que o estado inicial não foi gerado, caso contrário seria expandido na 4º ou 5º expansão.

## Ação 7 - Editar opções B

Alterar a  opção para remover os repetidos com base nos gerados, e alterar o debug para nível 2: 
**1; 2; 4; 10; 3; 2; 2; *ENTER*; 5.**

```entrada
Opção: 5

g:0
g:1 1|2
g:1 2|3
g:2 3|4
g:2 4|5 Solução encontrada!
[.] . (g:3)
P1:1 P2:2 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:3
P11:100 P12:0 P13:0
Resultado: 3 (0,013s)
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): passos | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): gerados | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 5 | gerações 6 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Podemos ver que o estado já não é mostrado. Em cada expansão é mostrado o custo (g), seguido de dois números: 
expansões e gerações realizadas até ao momento. No caso deste problema o estado é visualizado numa só linha, 
mas em outros problemas estes dois níveis de debug podem fazer diferença. 
Notar que não houve alteração no número de expansões e gerações, muito embora a técnica para 
lidar com os estados repetidos seja distinta.

É importante observar a procura em instâncias pequenas, para poder observar ineficiências, como os estados repetidos, ou mesmo bugs.

O nível de debug 1 insere um # por cada 1000 expansões, de modo a dar alguma noção de como vai a procura, 
e o nível 0 não dá qualquer informação. 

## Ação 8 - Resolver outra instância 

Repor a opção de ignorar os repetidos, colocar o debug no nível 1, e procurar resolver uma instância maior: 
**1; 8; 4; 10; 1; 2; 1; *ENTER*; 5.**

Pode haver um problema de memória. A instância é demasiado grande, e sem remover repetidos, rapidamente gera demasiados estados:  

```entrada
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): atividade | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 5 | gerações 6 | avaliações 0
 *  * [.] .  *  *  *  *
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
Opção: 5
################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################## Solução encontrada!
 .  .  .  .  .  .  . [.](g:15)
P1:1 P2:1 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
Resultado: 15 (5,351s)
Aspirador
P1(Algoritmo): Largura Primeiro | P2(Debug): atividade | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 1681451 | gerações 4840697 | avaliações 0
 .  .  .  .  .  .  . [.]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
São demasiados estados gerados, quase 5 milhões, e 5 segundos. 
Há um # que é colocado no output a cada 1000 expansões. 
Se desconfiamos que com tanto estado, dificilmente a solução pode ser óptima, podemos ver a solução.
Introduza: **3**

```entrada
Opção: 3

 *  * [.] .  *  *  *  *  (g:0)
 * [*] .  .  *  *  *  *  (g:1)
[*] *  .  .  *  *  *  *  (g:2)
[.] *  .  .  *  *  *  *  (g:3)
 . [*] .  .  *  *  *  *  (g:4)
 . [.] .  .  *  *  *  *  (g:5)
 .  . [.] .  *  *  *  *  (g:6)
 .  .  . [.] *  *  *  *  (g:7)
 .  .  .  . [*] *  *  *  (g:8)
 .  .  .  . [.] *  *  *  (g:9)
 .  .  .  .  . [*] *  *  (g:10)
 .  .  .  .  . [.] *  *  (g:11)
 .  .  .  .  .  . [*] *  (g:12)
 .  .  .  .  .  . [.] *  (g:13)
 .  .  .  .  .  .  . [*] (g:14)
 .  .  .  .  .  .  . [.] (g:15)
 ```
 Não houve desperdício visivel nestga solução. 
 O algoritmo procura em largura garante-nos que esta solução é ótima, dado que o custo de cada ação é unitário.

Para lidar com o problema de memória, podíamos limitar a procura em largura com o parâmetro limite, fixando a 100 ou 1000 estados, mas perdendo a optimalidade.

A melhor solução para lidar com este problema é eliminar estados repetidos, idealmente todos os gerados. 
Mas se mesmo assim a procura em largura resultar num problema de memória, a utilização de um limite, poderá ser uma opção, 
mantendo-se apenas um determinado número limitado de estados gerados não expandidos. 
Esta abordagem perde a optimalidade, e também a garantia de construir um caminho do estado inicial ao final, 
o que poderá não ser problemático em alguns problemas.


## Ação 9 - Desafio Procura em Largura

Com a procura em largura, até que tamanho consegue obter a solução ótima do aspirador?

<details>
  <summary>Resposta:</summary>
Depende das condições de execução, vamos colocar na resposta o VPL com a 512MB.
Consegue resolver com replicados gerados, até à instância 19, existindo problema de memória na instância 20.
Limitando a 1000 e mantendo os replicados gerados, a procura em largura consegue resolver até à instancia 50, a maior considerada no código. A utilização do limite não permite garantir a otimalidade da solução
A utilização de repetidos com base nos ascendentes, permite também resolver o problema de memória, mas ganha-se o problema de tempo, sendo uma solução viável até à instância 44, mantendo o tempo limite em 10 segundos.
</details>


## Ação 10 - Procura em Profundidade

![Profundidade Primeiro - expande primeiro os estados mais profundos](docs/images/aspirador_profundidade.png)

Avançamos agora para a procura em profundidade. 
Neste caso temos neste algoritmo diversas estratégias. 
Podemos executar esta procura com um limite de profundidade. 
Vamos fazer isso na instância 2, que sabemos ter uma solução de 3 movimentos.

## Ação 11 - Efetuar uma procura em Profundidade Primeiro

Utilizar a instância número 2, o algoritmo profundidade primeiro, com limite de profundidade a 3, com nível de debug máximo, e ignorando repetidos: 
**1; 2; 4; 1; 3; 9; 3; 2; 4; 10; 1; *ENTER*; 5.**

O parâmetro 1 é o algoritmo, em que o 3 é a profundidade primeiro.

```entrada
Algoritmo base a executar.
1: Largura Primeiro
2: Custo Uniforme
3: Profundidade Primeiro
4: Melhor Primeiro
5: A*
6: IDA*
7: Branch and Bound
Algoritmo (atual 1):
```

O parâmetro 9 é o limite, com diferentes interpretações conforme o algoritmo.  
Na procura em largura o limite servia para limitar o número de estados gerados mas não expandidos. 
Aqui serve para limitar o nível de profundidade, que é fixado a 3. 

```entrada
Opção: 5
g:0
 * [*]
  +g:1 1|2 esq
  |[*] *
  |  +g:2 2|4 dir
  |  | * [*]
  |  |
  |  +g:2 2|4 asp
  |   [.] *
  |
  +g:1 2|4 asp
    * [.]
     +g:2 3|6 esq
     |[*] .
     |
     +g:2 3|6 asp
       * [.]

P1:3 P2:4 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:3 P10:1
P11:100 P12:0 P13:0
Resultado: -1 (0,012s)
Aspirador
P1(Algoritmo): Profundidade Primeiro | P2(Debug): completo | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 3 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 3 | gerações 6 | avaliações 0
 * [*]
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Podemos ver todos os estados gerados. 
A árvore tendo 3 níveis, permite dois movimentos, pelo que não foi descoberta a solução, retornando -1. 
Este resultado pode ser utilizado para saber que não há nenhuma solução de comprimento inferior a 3, ou seja, é um lower bound.

Esta visualização da árvore da procura é interessante para pequenos problemas, 
mas naturalmente que procuras maiores torna-se impraticável. 
Podemos observar aqui que o estado inicial foi gerado novamente, dado que estamos a ignorar os repetidos.

## Ação 12 - Ver uma árvore de procura maior

Colocar a profundidade a 10, e o nível de debug a 3: **1; 2; 4; 9; 10; 2; 3; *ENTER*; 5.**

```entrada
Opção: 5
--+--+--+--+--+--+--+--+--+= g:9 9|18
  |  |  |  |  |  |  |  |  |[*] *
  |  |  |  |  |  |  |  |  += g:9 9|18
  |  |  |  |  |  |  |  |    * [.]
  |  |  |  |  |  |  |  +--+= g:9 10|20
  |  |  |  |  |  |  |     | . [*]
  |  |  |  |  |  |  |     += g:9 10|20
  |  |  |  |  |  |  |      [.] *
  |  |  |  |  |  |  +--+--+= g:9 12|24
  |  |  |  |  |  |     |  | * [.]
  |  |  |  |  |  |     |  + Solução encontrada!
[.] . (g:9)
P1:3 P2:3 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:10 P10:1
P11:100 P12:0 P13:0
Resultado: 9 (0,021s)
Aspirador
P1(Algoritmo): Profundidade Primeiro | P2(Debug): detalhe | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 10 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 12 | gerações 24 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```
Com o nível debug a 3 vemos a árvore de procura apenas os estados folha, mas não os estados expandidos. 
A informação é mais reduzida, mas poderá ser uma boa forma de analisar os estados em que o algoritmo volta para trás, 
já que podem ter alguma característica relevante, ainda não implementada. 
A solução não é óptima, tem comprimento 9! Podemos visualizar a solução, introduza: **3.**
```entrada
Opção: 3

 * [*] (g:0)
[*] *  (g:1)
 * [*] (g:2)
[*] *  (g:3)
 * [*] (g:4)
[*] *  (g:5)
 * [*] (g:6)
 * [.] (g:7)
[*] .  (g:8)
[.] .  (g:9)
```

Como o algoritmo é cego, segue a ordem dos sucessores. 
Neste caso está sempre a trocar de posição antes de aspirar. 
Apenas foi ver as alternativas quando teve de voltar para trás, devido ao limite de profundidade. 
Se tivéssemos escolhido uma profundidade menor, a solução obtida seria também menor. 
Mas se a profundidade fosse menor que a solução mais curta, não iriamos obter nenhuma solução. 
É com base nesse dilema que surge a procura em profundidade iterativa, no caso deste código é executada com o limite=0.

## Ação 13 - Profundidade Iterativa

Colocar a profundidade iterativa (limite a 0), e o nível de debug a 2: **1; 2; 4; 9; 0; 2; 2; *ENTER*; 5.**

```entrada
Iteração 1:
= g:0
Iteração 2:
--+= g:1 1|2
  += g:1 1|2
Iteração 3:
--+--+= g:2 3|6
  |  += g:2 3|6
  +--+= g:2 4|8
     += g:2 4|8
Iteração 4:
--+--+--+= g:3 7|14
  |  |  += g:3 7|14
  |  +--+= g:3 8|16
  |     += g:3 8|16
  +--+--+= g:3 10|20
     |  + Solução encontrada!
[.] . (g:3)
P1:3 P2:2 P3:1 P4:1 P5:10 P6:0 P7:0 P8:0 P9:0 P10:1
P11:100 P12:0 P13:0
Resultado: 3 (0,016s)
Aspirador
P1(Algoritmo): Profundidade Primeiro | P2(Debug): passos | P3(Ver): 1 | P4(Seed): 1
P5(Tempo): 10 | P6(Gerações): 0 | P7(Expansões): 0 | P8(Avaliações): 0
P9(Limite): 0 | P10(Repetidos): ignorar | P11(pesoAStar): 100 | P12(ruido): 0
P13(baralhar): 0
[Estatísticas] expansões 10 | gerações 20 | avaliações 0
[.] .
_______________________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste
```

Podemos observar que o algoritmo encontrou a solução de comprimento 3, a solução ótima. 
Fez várias iterações que não serviram para nada, antes de executar na iteração 4 com limite a 4. 
Mas essas árvores de procura são muito mais pequenas, pelo que o peso de executar essas procuras extra não é muito relevante.

Podemos ver também a versão compactada da árvore de procura, contendo apenas informação do estado, 
tal como na procura em largura, mas desta vez com informação de onde o estado veio. 
Pela observação da árvore é possível verificar que a maior parte das ramificações são de dois sucessores, 
o que é natural dado que este problema tem apenas duas salas.

Vamos agora ver o que acontece se não limitarmos a procura em profundidade, colocando o limite=-1

## Ação 14 - Profundidade ilimitada

Colocar a profundidade ilimitada (limite a -1), e o nível de debug a 1: 
**1; 2; 4; 9; -1; 2; 1; *ENTER*; 5.**

```entrada
Opção: 5
########
```

Temos um crash do programa, e bem cedo. 
Como a procura em profundidade está implementada de forma recursiva, houve um problema no stack. 
Se tivesse implementada com listas, teríamos um problema de memória, como na procura em largura. 
Entrou-se num ramo infinito, mesmo neste pequeno problema, como aliás é possível imaginar na solução da procura com nível 10. 

## Ação 15 - Desafio Procura Profundidade

Lembra-se de algo dado na procura em largura, que impede ciclos infinitos e poderia permitir o uso da procura em profundidade ilimitada?

<details>
  <summary>Resposta</summary>
Sim, não ignorar os estados repetidos não servem apenas para reduzir a árvore de procura. Evitam também ciclos infinitos. 
Com repetidos nos ascendentes ou gerados, consegue resolver com a procura em profundidade ilimitada, qualquer uma das 50 instâncias.
</details>

Está terminado esta execução de exemplo. Fica para execuções de outros problemas o teste de algoritmos informados, 
bem como o custo uniforme e os testes empíricos, com as opções 6 e 7 do menu dos testes manuais. 
