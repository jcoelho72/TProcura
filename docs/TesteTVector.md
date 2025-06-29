@page teste_tvector Teste TVector

Execução de exemplo com base na classe de teste de TVector. 
Pode acompanhar o teste excutando as ações localmente.
Este exemplo serve para ilustrar as funcionalidades principais de testes paramétricos da classe TProcura.
Nos exemplos das subclasses ilustra-se as restantes funcionalidades.

## Sumário

- [Ação 1: Menu 1 - Inicializar](#tvector-a1)
- [Ação 2: Menu 3 - Parâmetros](#tvector-a2)
- [Ação 3: Menu 6 - Executar](#tvector-a3)
- [Ação 4: Menu 5 - Indicadores](#tvector-a4)
- [Ação 5: Menu 7 - Configurações](#tvector-a5)
- [Ação 6: Menu 8 - Teste](#tvector-a6)
- [Ação 7: Linha de comando](#tvector-a7)
- [Ação 8: Desafio CTesteTVector](#tvector-a8)


```entrada
TVector
 P1(Método): Add() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
Opção:
```

Ao arrancar com o programa sem argumentos, entramos no modo interativo, com o teste manual. 
Esta é a informação apresentada. 
Na zona superior aparece o nome do problema (neste caso TVector), seguido dos parametros e valores atuais. Iremos detalhar os parametrors mais adiante.
Segue-se uma zona com informação sobre os dados do problema concreto a resolver, a instância, neste caso é um vetor de números aleatórios, com 1 milhão de elementos.
Temos vários algoritmos, em que cada um testa um método da classe TVector.
Segue-se o menu com 8 comandos, os quais iremos cobrir neste exemplo. 
Entre os dados e o menu, após ter exsitido uma execução, são apresentados os indicadores relativos à última execução. Iremos detalhar também estes indicadores.

---

\anchor tvector-a1
## Ação 1: Menu 1 - Inicializar

Vamos ver o menu 1, inicializar. Introduza: 1; 2.

```entrada
ID atual: 1  Intervalo: [1-10]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto): 2

TVector
 P1(Método): Add() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #2000000: -498792314 -2114916689 -1334173636 ... 1289309513 1347067406 1395724283
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
Opção:
```
Este menu permite inicializar os dados utilizados no algoritmo. Temos a indicação do ID da instância atual, que é 1.
Estão definidas instâncias de 1 a 10. Essas instâncias significam que o tamanho do vetor é 1 milhão vezes o ID da instância.
Ao escolhermos a instância 2, vemos que o vetor fica com 2 milhões de dados. 
Fizemos a visualização apenas dos primeiros 3 e últimos 3 elementos, mas neste caso é suficiente para sabermos que trocamos de instância, já que os números são diferentes.
São diferentes os últimos números, mas os primeiros são iguais, já que não alteramos a semente do gerador aleatório.
Podiamos também ter introduzido um texto, para alterar o prefixo atual. 
Este texto é importante se os dados de teste estivessem em ficheiros. 
Neste caso fizemos um gerador de dados, geramos os dados aleatoriamente e colocamos no vetor, não é preciso o ficheiro.

Vamos voltar para a instãncia 1, para confirmar que é a mesma, apenas assim se pode garantir que tudo o que se faz em TProcura, é reproduzivel. Introduza: 1; 1.

```entrada
ID atual: 2  Intervalo: [1-10]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto): 1

TVector
 P1(Método): Add() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
Opção:
```

Notar que a instância é exatamente a mesma, como se pode confirmar pelos números iniciais e finais do vetor.

O menu **2 - Explorar**, serve para explorar o problema manualmente, mas neste caso não definimos nenhuma função para
expplorar os dados. Esta função está definida para as subclasses de TProcura, para os métodos construtivos e melhorativos.
Não é necessário definir função nenhuma, e o utilizador pode sempre explorar manualmente o problema, por que não, tentar resolvê-lo,
e assim ganhar sensibilidade. Vamovs deixar esta exploração para os exemplos das subclasses.

Notar que o menu é sempre visualizado, colocando-se o prompt "Opção:". Para evitar repetição, vamos omitar o menu no resto deste exemplo.

---

\anchor tvector-a2
## Ação 2: Menu 3 - Parâmetros

Avançamos para o menu **3 - Parâmetros**. Introduza: 3.

```entrada
Opção: 3

 P1(Método): Add() (1 a 12)
P2(Debug): nada (0 a 4)
P3(Seed): 1 (1 a 1000000)
P4(Tempo): 10 (1 a 3600)
P5(Iterações): 0 (0 a 1000000000)
P6(Estrutura): TVector (1 a 3)
Parametro:
```
Podemos ver os parametros quer já tinhamos visto, com mais detalhe. Temos o ID do parâmetro, nome do parâmetro, e valor atribuído.
Alguns parâmetros têm texto, quando as opções são categóricas, outros têm números, para valores quantitativos.
Não existem números reais nos parâmetros, tendo de ser convertidos sempre para inteiro. 
Mesmo os parâmetros categóricos, têm um número inteiro associado a cada valor.
Cada parâmetro tem um valor mínimo e máximo em inteiros, que pode tomar.

Vamos ver as opções no parâmetro 1, é o método a ser executado. Introduza: 1.

```entrada
Parametro:1

Método para teste.
1: Add()
2: Sort()
3: RandomOrder()
4: Invert()
5: BeASet()
6: Difference()
7: Union()
8: Contained()
9: Intersection()
10: operator=()
11: operator+=()
12: nada
Método (atual 1):
```

Como o parâmetro é catégórico, aparecem todos os valores que pode tomar, juntamente com os seus nomes. 
Este parâmetro foi povoado na classe CTesteTVector, onde foram definidos estes métodos.
A função do parâmetro 1 é sempre escolher o método/algoritmo a executar, mas os métodos/algoritmos variam conforme a subclasse.
Ao utilizar uma das subclasses genéricas de TProcura, esta já tem um conmjunto de algoritmos implementados, ficando esta lista preenchida.

Caso não pretenda alterar um parâmetro, pode sempre carregar em ENTER para manter o valor atual. 
Vamos alterar para a ordenação, e de seguida vamos ver o parâmetro 2. Introduza: 2; 2.

```entrada
Método (atual 1): 2

 P1(Método): Sort() (1 a 12)
P2(Debug): nada (0 a 4)
P3(Seed): 1 (1 a 1000000)
P4(Tempo): 10 (1 a 3600)
P5(Iterações): 0 (0 a 1000000000)
P6(Estrutura): TVector (1 a 3)
Parametro:2

Nível de debug, de reduzido a completo.
0: nada
1: atividade
2: passos
3: detalhe
4: completo
Debug (atual 0):
```
Notar que agora o valor associado a P1 é "Sort()". Ao escolhermos o parâmetro P2 vamos ver o parâmetro que define o nível de debug.
Este parâmetro é de TProcura, e não é necessário alterar, a não ser que se pretenda mais que 3 níveis de debug.

Ao alterar este parâmetro, o algoritmo, caso tenha condicionais sobre este parâmetro, irá mostrar os detalhes do que está a fazer.
Prevê-se estes níveis, em que o nível 1 deve apresentar apenas um caracter de tempos a tempos, de modo a confirmar-se que o algoritmo está a funcionar.
No nível 2 deve-se dar a indicação do passo/iteração em que vai, ou grande passo, no caso do número de iterações ser elevado.
No nível 3 detalhe, já é de esperar detalhe sobre todas as iterações.
No nivel 4 completo, todo o detalhe deve ser dado em todos os passos, de modo a constituir uma prova de que o resultado é correto.~´

Estes níveis têm o intuito de poder observar bugs, caso existam. 
Mas têm também um carácter didático, já que nas classes de procura, pode-se observar os algoritmos com o nível que se pretender.
Assim está-se a contribuir para a compreensão do algoritmo, aplicado a um dado problema.

No caso do TVector, os algoritmos estão implementados sem debug, pelo que este valor não é utilziado.

Avançamos para o parâmetro P3, "Seed". Introduza: *ENTER*; 3; 2; *ENTER*.


```entrada
Debug (atual 0):

 P1(Método): Sort() (1 a 12)
P2(Debug): nada (0 a 4)
P3(Seed): 1 (1 a 1000000)
P4(Tempo): 10 (1 a 3600)
P5(Iterações): 0 (0 a 1000000000)
P6(Estrutura): TVector (1 a 3)
Parametro:3

Semente aleatória para inicializar a sequência de números pseudo-aleatórios.
Seed (atual 1): 2

 P1(Método): Sort() (1 a 12)
P2(Debug): nada (0 a 4)
P3(Seed): 2 (1 a 1000000)
P4(Tempo): 10 (1 a 3600)
P5(Iterações): 0 (0 a 1000000000)
P6(Estrutura): TVector (1 a 3)
Parametro:

TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
```
O P3 tem a semente aleatória. No entanto, voltamos ao menu inicial e a instância é a mesma.
É preciso inicializar e com esta nova semente, já irá ser criada uma nova instância. Introduza: 1; *ENTER*.

```entrada
Opção: 1

ID atual: 1  Intervalo: [1-10]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto):

TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: 277845151 613458960 -1719828728 ... -639822065 75868536 1051675791
```

Agora sim, podemos ver que os três primeiros e últimos números são completamente distintos. 

Os outros dois parâmetros, o P4 Iterações, é um parâmetro genérico para limitar o número de iterações.
Como não temos nestes algoritmos definidas iterações, não iremos utilizar.

O P6 é um parâmetro definido na classe CTesteTVector, e tem a estrutura em teste. Introduza: 3; 6.

```entrada
Opção: 3

 P1(Método): Sort() (1 a 12)
P2(Debug): nada (0 a 4)
P3(Seed): 2 (1 a 1000000)
P4(Tempo): 10 (1 a 3600)
P5(Iterações): 0 (0 a 1000000000)
P6(Estrutura): TVector (1 a 3)
Parametro:6

Estrutura de dados utilizada para vetor.
1: TVector
2: std::vector
3: TVector/std::algorithm
Estrutura (atual 1):
```

Foram definidas 3 opções pela qual os métodos podem ser executados. 
Utilizando exclusivamente a TVector, a opção atual.
A segunda opção é não utilizando TVector, mas sim std::vector e algoritmos da STL equivalentes aos métodos em teste de TVector.
A terceira opção é um misto entre utilizar TVector, mas na ordenação e deteção de estados únicos, utilizar os métodos da STL.

Vamos deixar como está. Introduza: *ENTER*; *ENTER*.

O menu *4 - Solução* será ilustrado com um problema de procura, nestes métodos a solução é o estado do vetor após aplicadas as operações.

---

\anchor tvector-a3
## Ação 3: Menu 6 - Executar

Avançamos para o menu *6 - Executar*. Introlduza: 6.

```entrada
Opção: 6

 P1=2 P2=0 P3=2 P4=10 P5=0 P6=1
TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
I1(Resultado): 1 | I2(Tempo(ms)): 82 | I3(Iterações): 1 | I4(Ordenado): 1
____________________________________________________________________
```
Os valores dos parâmetros em modo curso são mostrawdos, e de seguida a execução é completada. 
Podemos ver novamente os parâmetros utilizados, tendo sido executado o método Sort(), com a estrutura TVector.
O estado do vetor é visivel os três priemiros e últimos elementos, podendo-se confirmar que estes estão por ordem.

Como já houve uma execução, existe agora mais uma linha antes do menu, com os indicadors, I1 a I4.

Os três primeiros indicadores são de TProcura, o quarto indicador é definido em CTesteTVector.
O indicador I1 tem o resultado do algoritmo, que aqui retorna sempre 1 a não ser que exista algum problema.
O indicador I2 tem o tempo consumido pelo algoritmo, em milisegundos, neste caso 82. 
Notar que este tempo é apenas de execução, não é contabilizado o tempo de inicialização (ao criar a instância).
O tempo de calcular os indicadores não é também comtabilizado.
O indicador I3 tem o número de iterações realizadas. 
O algoritmo deve atualizar as iterações, neste caso ordenou apenas uma vez.
Como queremos saber se a operação foi bem sucedida, definiu-se um indicador para testar se o vetor está ordenado.
Esse indicador é chamado após o algoritmo, e aqui retorna 1, confirmando que está ordenado. 
Em outros métodos, que não ordenem o vetor, naturalemnte que este indiador ao ser chamado, irá retornar 0.

Vamos trocar um parâmetro, inicializar e executar novamente. Introduza: 3; 6; 2; *ENTER*; 1; *ENTER*; 6. 

```entrada
TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): std::vector
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
I1(Resultado): 1 | I2(Tempo(ms)): 83 | I3(Iterações): 1 | I4(Ordenado): 1
____________________________________________________________________
```

Notar que o resultado em termos de dados final, é exatamente o mesmo. 
É natural já que ambas as estruturas de dados receberam a mesma instância.
O tempo foi um milisegundo superior, mas outra execução o tempo CPU pode ser distinto.


---

\anchor tvector-a4
## Ação 4: Menu 5 - Indicadores

Vamos agora ver o menu dos indicadores. Introduza: 5.

```entrada
Opção: 5


I1(Resultado): 1º lugar (Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).)
I2(Tempo(ms)): 2º lugar (Tempo em milisegundos da execução (medida de esforço computacional).)
I3(Iterações): 3º lugar (Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).)
I4(Ordenado): 4º lugar (verifica se o indicador está ordenado)
Alterar indicador:
```

De omissão estão todos os indicadores ligados, e são chamados por ordem de ID. 
No entanto, por vezes pretende-se verificar a solução, executando verificações/validações. 
Outras vezes pretende-se obter informação sobre a instância, que nem está relacionada com a execução do algoritmo.
Pode-se ainda querer fazer ações após o algoritmo, de transofmração da solução, ou gravação da solução para ficheiro.

Com os indicadores é possível definir as ações a executar após o algoritmo, por uma dada ordem, ou se uma dada ação irá ser
executada ou não.

Neste caso temos apenas um indicador definido, que é um indicador de verificação, testando se o vetor ficou ordenado.

Com esta interface podemos remover e adicionar indicadores existentes por outra ordem. 
Vamos por exemplo colocar visivel primeiro I4 e depois I2, não mostrando os restanes.

Introduza: 1;2;3;2;*ENTER*;1;*ENTER*;6.

```entrada
...
I1(Resultado): inativo (Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).)
I2(Tempo(ms)): 2º lugar (Tempo em milisegundos da execução (medida de esforço computacional).)
I3(Iterações): inativo (Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).)
I4(Ordenado): 1º lugar (verifica se o indicador está ordenado)
Alterar indicador:
...
TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
I4(Ordenado): 1 | I2(Tempo(ms)): 90
____________________________________________________________________
```

Podemos ver que agora apenas I4 seguido de I2 são apresentados.


---

\anchor tvector-a5
## Ação 5: Menu 7 - Configurações

Os métodos utilizados até aqui, permitem executar testes confortavelmente sem ter de andar a alterar código, compilar e executar.
Pode-se ir registando os dados, e procurar tirar conclusões.

No entanto, execuções particulares podem ser enganadoras, como o tempo de execução da ordenação entre TVector e o sort() da STL. 
Para existir garantias, temos de fazer muitas execuções, com diferentes parâmetros, e poder processar os resultados posteriormente.

Assim, é crítico que se possa definir confortavelmente todas as configurações a executar, de modo a obter resultados em bloco, e não um a um.

Introduza: 7.

```entrada
Opção: 7

Parâmetros comuns:
 P1=2 P2=0 P3=2 P4=10 P5=0 P6=2
- Configurações geradas (total: 1) -
  [1] --- atual
Sintaxe comando:
  id / -id     - Seleciona configuração como atual ou apaga 'id'
  Pk=<conj.>   - Varia Pk na configuração atual (gera N configurações)
  Pk=<conj.> x Pw=<conj.> - produto externo de Pk e Pw (gera NxM configurações)
Sintaxe de <conj.> (apenas inteiros, sem espaços):
  A ou A,B,C   - único valor ou enumeração
  A:B ou A:B:C - intervalo A a B, ou com passo C
Comando:
```

Temos aqui a lista dos parâmetros atuais. Há apenas uma configuração, com os parâmetros que alteramos.
Se não alterarmos parâmetros, estes tomam o valor de omissão, nunca existindo um parâmetro sem valor definido.
Os parâmetros apenas podem ser alterados para valores dentro dos seus limites.

Existe atualmente apenas uma configuração, em que todos os parâmetros são comuns.
Vamos colocar o parâmetro P1, com o método, a variar de 1 a 12, para testar todos os métodos.

Introduza: P1=1:12

```entrada
Comando: P1=1:12

Parâmetros comuns:
 P2=0 P3=2 P4=10 P5=0 P6=2
- Configurações geradas (total: 12) -
 P1=2 [1] --- atual
 P1=1 [2]
 P1=3 [3]
 P1=4 [4]
 P1=5 [5]
 P1=6 [6]
 P1=7 [7]
 P1=8 [8]
 P1=9 [9]
 P1=10 [10]
 P1=11 [11]
 P1=12 [12]
Sintaxe comando:
  id / -id     - Seleciona configuração como atual ou apaga 'id'
  Pk=<conj.>   - Varia Pk na configuração atual (gera N configurações)
  Pk=<conj.> x Pw=<conj.> - produto externo de Pk e Pw (gera NxM configurações)
Sintaxe de <conj.> (apenas inteiros, sem espaços):
  A ou A,B,C   - único valor ou enumeração
  A:B ou A:B:C - intervalo A a B, ou com passo C
Comando:
```

Notar que P1 já não é mostrado nos parâmetros comuns, mas sim os seus diversos valores nas configurações de 1 a 12.
A notação 1:12 significa os números de 1 a 12. 
Se tivessemos colocado 1:12:2 correspondia aos números de 1 a 12 mas em passos de 2.
Podiamos ter indicado também com a notação por vírgulas, com 1,2,3,4,5,6,7,8,9,10,11,12. 
Podemos misturar notações, por exemplo, podiamos especificar o conjunto 1:3,5:9:2,12, ou seja, os números 1,2,3,5,7,9,12.

Se pretendermos alterar apenas o valor de um parâmetro k para V, colocamos Pk=V. 
Se tiver dois ou mais números, então pretendemos variar a configujração atual.

Vamos agora colocar dois parâmetros a variar em conjunto, ou seja, estamos interessados no produto externo.
Introduza: P3=1:2 x P6=1:3.

```entrada
Comando: P3=1:2 x P6=1:3

Parâmetros comuns:
 P2=0 P4=10 P5=0
- Configurações geradas (total: 17) -
 P1=2 P3=2 P6=2 [1] --- atual
 P1=1 P3=2 P6=2 [2]
 P1=3 P3=2 P6=2 [3]
 P1=4 P3=2 P6=2 [4]
 P1=5 P3=2 P6=2 [5]
 P1=6 P3=2 P6=2 [6]
 P1=7 P3=2 P6=2 [7]
 P1=8 P3=2 P6=2 [8]
 P1=9 P3=2 P6=2 [9]
 P1=10 P3=2 P6=2 [10]
 P1=11 P3=2 P6=2 [11]
 P1=12 P3=2 P6=2 [12]
 P1=2 P3=1 P6=1 [13]
 P1=2 P3=2 P6=1 [14]
 P1=2 P3=1 P6=2 [15]
 P1=2 P3=1 P6=3 [16]
 P1=2 P3=2 P6=3 [17]
 ...
```

Foram dados 2 valores para P3 e 3 valores para P6, tendo sido produzidos mais 5 novas configurações, já que uma é a configuração base (a atual).

Vamos agora utilizar as configurações num teste. Introduza: *ENTER*.

Avance para a próxima ação.

---

\anchor tvector-a6
## Ação 6: Menu 8 - Teste

Tendo configurações introduzidas, vamos agora executar um teste com estas configurações.
Introduza: 8; 1:3; *ENTER*; 0.

A primeira pergunta é sobre quais as instâncias a excutar o teste, na qual pretendemos as 3 primeiras.
A segunda pergunta é para colocar os resultados num ficheiro de texto, para já não estamos interesados.
A terceira pergunta permite que se vejam as soluções assim que cada execução termina, também não precisamos neste teste.

```entrada
Opção: 8

Sintaxe (apenas inteiros, sem espaços):
  A ou A,B,C   - único valor ou enumeração
  A:B ou A:B:C - intervalo A a B, ou com passo C
Introduza IDs das instâncias (de 1 a 10): 1:3
Ficheiro (nada para mostrar no ecrã):
Mostrar soluções? 0

 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): std::vector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
 P1(Método): Add() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): std::vector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
...
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector/std::algorithm
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
 ID |conf|  Ordenado| Tempo(ms)|
----|----|----------|----------|
  1 |  1 |        1 |       87 |
  2 |  1 |        1 |      203 |
  3 |  1 |        1 |      283 |
  1 |  2 |        1 |        4 |
  2 |  2 |        1 |       12 |
  3 |  2 |        1 |       10 |
  1 |  3 |        1 |       11 |
  2 |  3 |        1 |       21 |
  3 |  3 |        1 |       53 |
  1 |  4 |        1 |        1 |
  2 |  4 |        1 |        0 |
  3 |  4 |        1 |        1 |
  1 |  5 |        1 |       78 |
  2 |  5 |        1 |      178 |
  3 |  5 |        1 |      268 |
  1 |  6 |        1 |      175 |
  2 |  6 |        1 |      344 |
  3 |  6 |        1 |      618 |
  1 |  7 |        1 |      237 |
  2 |  7 |        1 |      526 |
  3 |  7 |        1 |      801 |
  1 |  8 |        1 |      243 |
  2 |  8 |        1 |      352 |
  3 |  8 |        1 |      521 |
  1 |  9 |        1 |      182 |
  2 |  9 |        1 |      367 |
  3 |  9 |        1 |      574 |
  1 | 10 |        1 |        1 |
  2 | 10 |        1 |        1 |
  3 | 10 |        1 |        1 |
  1 | 11 |        1 |        1 |
  2 | 11 |        1 |        1 |
  3 | 11 |        1 |        2 |
  1 | 12 |        1 |        0 |
  2 | 12 |        1 |        0 |
  3 | 12 |        1 |        0 |
  1 | 13 |        1 |       86 |
  2 | 13 |        1 |      160 |
  3 | 13 |        1 |      284 |
  1 | 14 |        1 |       91 |
  2 | 14 |        1 |      180 |
  3 | 14 |        1 |      305 |
  1 | 15 |        1 |       92 |
  2 | 15 |        1 |      181 |
  3 | 15 |        1 |      283 |
  1 | 16 |        1 |       80 |
  2 | 16 |        1 |      176 |
  3 | 16 |        1 |      296 |
  1 | 17 |        1 |       82 |
  2 | 17 |        1 |      168 |
  3 | 17 |        1 |      262 |
----|----|----------|----------|resolvidas
Total  1 |        3 |      573 | 3
Total  2 |        3 |       26 | 3
Total  3 |        3 |       85 | 3
Total  4 |        3 |        2 | 3
Total  5 |        3 |      524 | 3
Total  6 |        3 |     1137 | 3
Total  7 |        3 |     1564 | 3
Total  8 |        3 |     1116 | 3
Total  9 |        3 |     1123 | 3
Total 10 |        3 |        3 | 3
Total 11 |        3 |        4 | 3
Total 12 |        3 |        0 | 3
Total 13 |        3 |      530 | 3
Total 14 |        3 |      576 | 3
Total 15 |        3 |      556 | 3
Total 16 |        3 |      552 | 3
Total 17 |        3 |      512 | 3
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|-07-|-08-|-09-|-10-|-11-|-12-|-13-|-14-|-15-|-16-|-17-|
 1    | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  2 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |  0 | -2
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 2  2 |    |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 3  2 |  0 |    |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 4  2 |  0 |  0 |    |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 5  0 | -2 | -2 | -2 |    |  2 |  3 |  3 |  3 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |  0 | -1
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 6 -2 | -3 | -3 | -3 | -2 |    |  2 |  0 |  0 | -3 | -3 | -3 | -2 | -2 | -2 | -2 | -2 |-30
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 7 -3 | -3 | -3 | -3 | -3 | -2 |    | -2 | -2 | -3 | -3 | -3 | -3 | -3 | -3 | -3 | -3 |-45
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 8 -3 | -3 | -3 | -3 | -3 |  0 |  2 |    |  0 | -3 | -3 | -3 | -3 | -3 | -3 | -3 | -3 |-37
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 9 -2 | -3 | -3 | -3 | -3 |  0 |  2 |  0 |    | -3 | -3 | -3 | -2 | -2 | -2 | -3 | -3 |-33
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
10  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |    |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
11  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |    |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
12  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |    |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
13  0 | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  2 | -2 | -2 | -2 |    |  0 |  0 |  0 |  0 | -2
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
14  0 | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  2 | -2 | -2 | -2 |  0 |    |  0 |  0 |  0 | -2
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
15  0 | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  2 | -2 | -2 | -2 |  0 |  0 |    |  0 |  0 | -2
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
16  0 | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  3 | -2 | -2 | -2 |  0 |  0 |  0 |    |  0 | -1
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
17  0 | -2 | -2 | -2 |  0 |  2 |  3 |  3 |  3 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |    | -1
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
Parâmetros comuns:
 P2(Debug): nada | P4(Tempo): 10 | P5(Iterações): 0
- Configurações geradas (total: 17) -
 P1(Método): Sort() | P3(Seed): 2 | P6(Estrutura): std::vector [1]
 P1(Método): Add() | P3(Seed): 2 | P6(Estrutura): std::vector [2]
 P1(Método): RandomOrder() | P3(Seed): 2 | P6(Estrutura): std::vector [3]
 P1(Método): Invert() | P3(Seed): 2 | P6(Estrutura): std::vector [4]
 P1(Método): BeASet() | P3(Seed): 2 | P6(Estrutura): std::vector [5]
 P1(Método): Difference() | P3(Seed): 2 | P6(Estrutura): std::vector [6]
 P1(Método): Union() | P3(Seed): 2 | P6(Estrutura): std::vector [7]
 P1(Método): Contained() | P3(Seed): 2 | P6(Estrutura): std::vector [8]
 P1(Método): Intersection() | P3(Seed): 2 | P6(Estrutura): std::vector [9]
 P1(Método): operator=() | P3(Seed): 2 | P6(Estrutura): std::vector [10]
 P1(Método): operator+=() | P3(Seed): 2 | P6(Estrutura): std::vector [11]
 P1(Método): nada | P3(Seed): 2 | P6(Estrutura): std::vector [12]
 P1(Método): Sort() | P3(Seed): 1 | P6(Estrutura): TVector [13]
 P1(Método): Sort() | P3(Seed): 2 | P6(Estrutura): TVector [14]
 P1(Método): Sort() | P3(Seed): 1 | P6(Estrutura): std::vector [15]
 P1(Método): Sort() | P3(Seed): 1 | P6(Estrutura): TVector/std::algorithm [16]
 P1(Método): Sort() | P3(Seed): 2 | P6(Estrutura): TVector/std::algorithm [17]

TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 2 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): std::vector
Dados #1000000: 277845151 613458960 -1719828728 ... -639822065 75868536 1051675791
____________________________________________________________________
```

Podemos ver que durante a execução, é mostrada a configuração atual, a instância a ser resolvida.
No final são mostrados resultados para cada configuração e instância, agregasdos por configuração.
Os indicadores selecionados fazem parte da tabela de resultados.

É mostrando ainda um torneio entre configurações, para saber a que é mais rápida.
Para permitir a reprodução, é mostrrado no final os valores exatos de cada configuração.

Infelizmente, pouco podemos deduzir deste teste. 
O motivo é que não tinhamos uma pergunta formulada, mas solicitamos simplesmente corridas.
Sabemos apenas que não há crash.

Vamos formular uma pergunta. Pretendemos saber como varia o tempo na operação de ordenação, com o tamanho do vetor.

Poderiamos estar a apagar as configurações uma a uma, mas vamos arrancar de novo, para não ter qualquer configuração.
Introduza após arrancar: 7; P1=2; *ENTER*; 8; 1:10; *ENMTER*; 0.

```entrada
...
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
Instância 4: DONE.
Instância 5: DONE.
Instância 6: DONE.
Instância 7: DONE.
Instância 8: DONE.
Instância 9: DONE.
Instância 10: DONE.
 ID |conf| Resultado| Tempo(ms)| Iterações|  Ordenado|
----|----|----------|----------|----------|----------|
  1 |  1 |        1 |       72 |        1 |        1 |
  2 |  1 |        1 |      154 |        1 |        1 |
  3 |  1 |        1 |      238 |        1 |        1 |
  4 |  1 |        1 |      335 |        1 |        1 |
  5 |  1 |        1 |      436 |        1 |        1 |
  6 |  1 |        1 |      555 |        1 |        1 |
  7 |  1 |        1 |      691 |        1 |        1 |
  8 |  1 |        1 |      823 |        1 |        1 |
  9 |  1 |        1 |     1145 |        1 |        1 |
 10 |  1 |        1 |     1064 |        1 |        1 |
----|----|----------|----------|----------|----------|resolvidas
Total  1 |       10 |     5513 |       10 |       10 | 10
...
```
Podemos ver que o tempo sobe, mas não de forma linear. 
A instância 1 tem 1 milhão de valores, leva 72 milisegundos.
A instância 10 tem 10 vezes mais tamanho, mas leva mais que 720 milisegundos, foi 1064.
Notar que a instância 9 levou mais tempo. 
Como houve uma só execução, esta situação pode ocorrer. 

Vamos colocar 10 instâncias de cada tipo, variando a semente, para assim ter mais precisão. 
Queremos desta vez ter os resultados no Excel.

Introduza: 7; P3=1:10; *ENTER*; 8; 1:10; resultado; 0.

```entrada
...
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 10 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
Instância 4: DONE.
Instância 5: DONE.
Instância 6: DONE.
Instância 7: DONE.
Instância 8: DONE.
Instância 9: DONE.
Instância 10: DONE.
Ficheiro resultado.csv gravado.
TVector
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
____________________________________________________________________
```

Existe a indicação que o ficheiro resultado.csv foi gravado. Pode aceder aqui: ![resultados.csv](docs/images/resultados.csv)

O ficheiro está pronto para fazermos uma análise com os relatórios dinâmcios. 
Colocando a instância nas linhas, e o tempo no conteúdo, deverá ser visivel o tempo crescente de forma estável, um pouco acima de linear.

![resultados](docs/images/resultados.png)

---

\anchor tvector-a7
## Ação 7: Linha de comando

Embora o modo interativo seja útil no desenvolvimento do algoritmo ou problema, 
os testes paramétricos é que nos vão suportar uma resposta a algum tipo de hipótese formada.

A linha de comando é normalmente mais simples, para por um lado poder colocar a correr num servidor, por outro,
pode ver exatamente o teste solicitado numa só linha, não estando dependente da interação do utilizador.

Abra a linha de comando, localize o executável, e execute com argumento "-h"

```entrada
TProcura.exe -h
Uso: TProcura.exe <instâncias> [opções]
  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]
Opções:
  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)
  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)
  -I <ind>        Lista de indicadores (e.g. 2,1,3)
  -S              Mostrar soluções durante a execução
  -h              Esta ajuda
  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - último campo
Exemplo: C:\Work\Git\TProcura\x64\Release\TProcura.exe 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2
   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores
```

Podemos assim reproduzir o teste anterior com a seguinte entrada.

Linha de comando: TProcura.exe 1:10 -R resultados -P P1=2 P3=1:10

```entrada
PS ...\Teste> TProcura 1:10 -R resultados -P P1=2 P3=1:10

Parâmetros comuns:
 P1=2 P2=0 P4=10 P5=0 P6=1
- Configurações geradas (total: 10) -
 P3=1 [1]
 P3=2 [2]
 P3=3 [3]
 P3=4 [4]
 P3=5 [5]
 P3=6 [6]
 P3=7 [7]
 P3=8 [8]
 P3=9 [9]
 P3=10 [10]
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
Instância 4: DONE.
Instância 5: DONE.
Instância 6: DONE.
Instância 7: DONE.
Instância 8: DONE.
Instância 9: DONE.
Instância 10: DONE.
...
 P1(Método): Sort() | P2(Debug): nada | P3(Seed): 10 | P4(Tempo): 10 | P5(Iterações): 0
P6(Estrutura): TVector
Instância 1: DONE.
Instância 2: DONE.
Instância 3: DONE.
Instância 4: DONE.
Instância 5: DONE.
Instância 6: DONE.
Instância 7: DONE.
Instância 8: DONE.
Instância 9: DONE.
Instância 10: DONE.
Ficheiro resultados.csv gravado.
```

Podemos agora processar o ficheiro e confirmar que tem resultados idênticos, com ligeiras variações no tempo.

Estando respondida a questão inicial sobre o tempo de ordenação, podemos com este código procurar responder a outra questão:

- considerando todas as operações em teste, há diferença entre alguma das estruturas de dados em termos de tempo?

De modo a ter uma resposta rápida mas com várias iteraçoes, vamos utilizar apenas as instâncias 1 e 3, mas mantendo 10 sementes aleatórias.
Temos também de variar a estrutura de dados.

Linha de comando: TProcura 1,3 -R resultadosTudo -P P1=1:12 x P3=1:10 x P6=1:3

Podemos processar no relatório dinâmico, colocando nas linhas P1 com os métodos, nas colunas P6 com as estruturas, e no conteúdo I2 com o tempo.

![resultadosTudo](docs/images/resultadosTudo.png)

Segundo estes resultados, TVector tem até uma ligeira vantagem em termos de tempo. 
Foram utilizadas instãncias pequenas para que o teste possa ser rápido.
Em qualquer caso pode-se afirmar que não há uma perda muito grande por utilizar TVector em vez do código STL.

Um ficheiro script com a linha de comandos, tem toda a informação para reproduzir o teste, pelo que pode facilitar a identificação do que foi feito.
Por outro lado, o ficheiro de resultados tem também todos os valores utilizados, pelo que se houve algum engano na especificação dos parâmetros, o valor utilizado incorreto é visivel nos resultados.
Há uma clara separação da fase de implementação da fase de teste. 
O resultado de um teste pode levantar outras questões, e provocar outro teste. 
Se a implementação tiver todas as opções em parâmetros, não é necessário alternar com programação entre testes. 
Apenas após a identificação de bugs, é que a programação é necessária.

---

\anchor tvector-a8
## Ação 8: Desafio CTesteTVector

Será a ordenação de TVector mais rápida ou mais lenta ue a ordenação da STL?
Que testes pode fazer para procurar dar uma resposta fundamentada?

<details>
  <summary>Resposta:</summary>
Deve procurar executar com instâncias de dimensão razoável, vamos utilziar a 10 que é a maior.
Deve-se executar várias vezes, e apenas na operação de ordenação.
Linha de comando: TProcura 10 -R resultadosSort -P P1=2 P3=1:10 x P6=1:3
As diferenças não são relevantes, pode-se ver que não apenas as médias, mas os tempos mínimos e máximos são idênticos. 
Assim, os testes realizados não permitem aferir que um método é superior ao outro.

![resultadosSort](docs/images/resultadosSort.png)


</details>


