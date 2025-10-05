@page teste_tvector Teste TVector

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base na classe de teste de TVector. 
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcura, e execute.
No Linux na pasta `.../TProcura/Teste$` execute `make` seguido de `./bin/Release/TProcura`

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
- [Ação 8: Execução MPI](#tvector-a8)
- [Ação 9: Desafio CTesteTVector](#tvector-a9)


```entrada
TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```

Ao arrancar com o programa sem argumentos, entramos no modo interativo, com o teste manual. 
Esta é a informação apresentada. 
Na zona superior aparece o nome do problema (neste caso TVector),
seguido de uma caixa com os parametros com os valores atuais.
Iremos detalhar os parametrors mais adiante.
Segue-se uma zona com informação sobre os dados do problema concreto a resolver,
a instância, neste caso é um vetor de números aleatórios, com 1 milhão de elementos.
Temos vários algoritmos, em que cada um testa um método da classe TVector.
Segue-se uma outra caixa com o menu e os seus 8 comandos, os quais iremos cobrir neste exemplo. 
Entre os dados e o menu, após ter exsitido uma execução, são apresentados os indicadores relativos à última execução.
Iremos detalhar também estes indicadores.

---

\anchor tvector-a1
## Ação 1: Menu 1 - Inicializar

Vamos ver o menu 1 ↻ inicializar. Introduza: 1; 2.

```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 1  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 2

TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #2000000: -498792314 -2114916689 -1334173636 ... 1289309513 1347067406 1395724283
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```
Este menu permite inicializar os dados utilizados no algoritmo.
Temos a indicação do ID da instância atual, que é 1.
Estão definidas instâncias de 1 a 10.
Essas instâncias significam que o tamanho do vetor é 1 milhão vezes o ID da instância.
Ao escolhermos a instância 2, vemos que o vetor fica com 2 milhões de dados. 
Fizemos a visualização apenas dos primeiros 3 e últimos 3 elementos,
mas neste caso é suficiente para sabermos que trocamos de instância, já que os números são diferentes.
São diferentes os últimos números, mas os primeiros são iguais,
já que não alteramos a semente do gerador aleatório.
Podiamos também ter introduzido um texto, para alterar o prefixo atual. 
Este texto é importante se os dados de teste estivessem em ficheiros. 
Neste caso fizemos um gerador de dados, geramos os dados aleatoriamente e colocamos no vetor,
não é preciso o ficheiro.

Vamos voltar para a instãncia 1, para confirmar que é a mesma,
apenas assim se pode garantir que tudo o que se faz em TProcura, é reproduzivel. Introduza: 1; 1.

```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 2  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 1

TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```

Notar que a instância é exatamente a mesma, como se pode confirmar pelos números iniciais e finais do vetor.

O menu **2 🔍 Explorar**, serve para explorar o problema manualmente, mas neste caso não definimos nenhuma função para
expplorar os dados. Esta função está definida para as subclasses de TProcura, para os métodos construtivos e melhorativos.
Não é necessário definir função nenhuma, e o utilizador pode sempre explorar manualmente o problema, porque não, tentar resolvê-lo,
e assim ganhar sensibilidade. Vamos deixar esta exploração para os exemplos das subclasses.

Notar que o menu no modo interativo, é sempre visualizado, colocando-se o prompt "Opção:".
Para evitar repetição, vamos omitar o menu no resto deste exemplo.

---

\anchor tvector-a2
## Ação 2: Menu 3 - Parâmetros

Avançamos para o menu **3 ⚙️ Parâmetros**. Introduza: 3.

```entrada
Opção: 3

┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Add()      (1 a 12)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               1          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    (1 a 3)
└──────────────────────────────────────────────────────────────────────
Parametro:
```
Podemos ver os parametros que já tinhamos visto, mas agora com mais detalhe.
Temos o ID do parâmetro, nome do parâmetro, e valor atribuído.
O nome dos parametros é igual à macro no código.
Alguns parâmetros têm texto quando as opções são categóricas, outros têm números para valores quantitativos.
Não existem números reais nos parâmetros, tendo de ser convertidos sempre para inteiros. 
Mesmo os parâmetros categóricos, têm um número inteiro associado a cada valor.
Cada parâmetro tem um intervalo mínimo e máximo em inteiros, que pode tomar.

Vamos ver as opções no parâmetro 1, que é o método a ser executado. Introduza: 1.

```entrada
Parametro:1

┌─ ⚙️  P1(ALGORITMO) ──────────────────────────────────────────────────
│ Método para teste.
│ 1: Add()
│ 2: Sort()
│ 3: RandomOrder()
│ 4: Invert()
│ 5: BeASet()
│ 6: Difference()
│ 7: Union()
│ 8: Contained()
│ 9: Intersection()
│ 10: operator=()
│ 11: operator+=()
│ 12: nada
└──────────────────────────────────────────────────────────────────────
ALGORITMO (atual 1):
```

Como o parâmetro é categórico, aparecem todos os valores que pode tomar, juntamente com os seus nomes. 
Este parâmetro foi povoado na classe CTesteTVector, onde foram definidos estes métodos.
A função do parâmetro 1 é sempre escolher o método/algoritmo a executar, mas os métodos/algoritmos variam conforme a subclasse.
Ao utilizar uma das subclasses genéricas de TProcura, esta já tem um conjunto de algoritmos implementados, ficando esta lista preenchida.

Caso não pretenda alterar um parâmetro, pode sempre carregar em ENTER para manter o valor atual. 
Vamos alterar para a ordenação, e de seguida vamos ver o parâmetro 2. Introduza: 2; 2.

```entrada
ALGORITMO (atual 1): 2

┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Sort()     (1 a 12)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               1          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    (1 a 3)
└──────────────────────────────────────────────────────────────────────
Parametro:2

┌─ ⚙️  P2(NIVEL_DEBUG) ────────────────────────────────────────────────
│ Nível de debug, de reduzido a completo.
│ 0: NADA
│ 1: ATIVIDADE
│ 2: PASSOS
│ 3: DETALHE
│ 4: COMPLETO
└──────────────────────────────────────────────────────────────────────
NIVEL_DEBUG (atual 0):
```
Notar que agora o valor associado a P1 é "Sort()".
Ao escolhermos o parâmetro P2 vamos ver o parâmetro que define o nível de debug.
Este parâmetro é de TProcura, e não é necessário alterar, a não ser que se pretenda mais que 4 níveis de debug.

Ao alterar este parâmetro, o algoritmo, caso tenha condicionais sobre este parâmetro, irá mostrar os detalhes do que está a fazer.
Prevê-se estes níveis, em que o nível 1 deve apresentar apenas um caracter de tempos a tempos, de modo a confirmar-se que o algoritmo está a funcionar.
No nível 2 deve-se dar a indicação do passo/iteração em que vai, ou grande passo, no caso do número de iterações ser elevado.
No nível 3 detalhe, já é de esperar detalhe sobre todas as iterações.
No nivel 4 completo, todo o detalhe deve ser dado em todos os passos, de modo a constituir uma prova de que o resultado é correto.

Estes níveis têm o intuito de poder observar bugs, caso existam. 
Têm também um carácter didático, já que nas classes de procura, pode-se observar os algoritmos com o nível que se pretender.
Assim, está-se a contribuir para a compreensão do algoritmo, aplicado a um dado problema.

No caso do TVector, os algoritmos estão implementados sem debug, pelo que este valor não é utilizado.

Avançamos para o parâmetro P3, "SEMENTE". Introduza: *ENTER*; 3; 2; *ENTER*.


```entrada
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Sort()     (1 a 12)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               1          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    (1 a 3)
└──────────────────────────────────────────────────────────────────────
Parametro:3

┌─ ⚙️  P3(SEMENTE) ────────────────────────────────────────────────────
│ Semente aleatória para inicializar a sequência de números pseudo-aleatórios.
│ Intervalo: 1 a 1000000
└──────────────────────────────────────────────────────────────────────
SEMENTE (atual 1): 2

┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Sort()     (1 a 12)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               2          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    (1 a 3)
└──────────────────────────────────────────────────────────────────────
Parametro:

TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
...
Opção: 
```
O P3 tem a semente aleatória. No entanto, voltamos ao menu inicial e a instância é a mesma.
É preciso inicializar e com esta nova semente, já irá ser criada uma nova instância. Introduza: 1; *ENTER*.

```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 1  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto):

TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: 277845151 613458960 -1719828728 ... -639822065 75868536 1051675791
...
Opção:
```

Agora sim, podemos ver que os três primeiros e últimos números são completamente distintos. 

Os outros dois parâmetros, o P4 LIMITE_TEMPO, tem o tempo em segundos para o algoritmo executar,
e P5 LIMITE_ITERACOES, é um parâmetro genérico para limitar o número de iterações.
Como não temos nestes algoritmos definidas iterações, não iremos utilizar.

O P6 é um parâmetro definido na classe CTesteTVector, e tem a estrutura em teste. Introduza: 3; 6.

```entrada
Opção: 3

┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Sort()     (1 a 12)
│ P2(NIVEL_DEBUG):           NADA       (0 a 4)
│ P3(SEMENTE):               2          (1 a 1000000)
│ P4(LIMITE_TEMPO):          10         (1 a 3600)
│ P5(LIMITE_ITERACOES):      0          (0 a 1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    (1 a 3)
└──────────────────────────────────────────────────────────────────────
Parametro:6

┌─ ⚙️  P6(ESTRUTURA_DADOS) ────────────────────────────────────────────
│ Estrutura de dados utilizada para vetor.
│ 1: TVector
│ 2: std::vector
│ 3: TVector/std::algorithm
└──────────────────────────────────────────────────────────────────────
ESTRUTURA_DADOS (atual 1):
```

Foram definidas 3 opções pela qual os métodos podem ser executados. 
Utilizando exclusivamente a TVector, a opção atual.
A segunda opção é não utilizando TVector, mas sim std::vector e algoritmos da STL equivalentes aos métodos em teste de TVector.
A terceira opção é um misto entre utilizar TVector, mas na ordenação e deteção de estados únicos, utilizar os métodos da STL.

Vamos deixar como está. Introduza: *ENTER*; *ENTER*.

O menu *4 ✔  Solução* será ilustrado com um problema de procura, já que nestes métodos, a solução é o estado do vetor após aplicadas as operações.

---

\anchor tvector-a3
## Ação 3: Menu 6 - Executar

Avançamos para o menu *6 ►  Executar*. Introduza: 6.

```entrada
Opção: 6

══ ►  Executar ══
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1=2 P2=0 P3=2 P4=10 P5=0 P6=1
└──────────────────────────────────────────────────────────────────────
══ 🏁  Execução terminada ══
TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 1 | I2(Tempo(ms)): 70 | I3(Iterações): 1 | I4(IND_ORDENAR): 1
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
A execução arranca, os valores dos parâmetros em modo curto são mostrados, e de seguida a execução é terminada. 
Podemos ver novamente os parâmetros utilizados, tendo sido executado o método Sort(), com a estrutura TVector.
O estado do vetor é visivel os três primeiros e últimos elementos, podendo-se confirmar que estes estão por ordem.

Como já houve uma execução, existe agora mais uma linha antes do menu, com os indicadors, I1 a I4.

Os três primeiros indicadores são de TProcura, o quarto indicador é definido em CTesteTVector.
O indicador I1 tem o resultado do algoritmo, normalmente ao valor / qualidade da solução, que aqui é sempre 1 a não ser que exista algum problema.
O indicador I2 tem o tempo consumido pelo algoritmo, em milisegundos, neste caso 70. 
Notar que este tempo é apenas de execução, não é contabilizado o tempo de inicialização (ao criar a instância).
O tempo de calcular os indicadores não é também comtabilizado.
O indicador I3 tem o número de iterações realizadas. 
O algoritmo deve atualizar as iterações, neste caso ordenou apenas uma vez.
Como queremos saber se a operação foi bem sucedida, definiu-se um indicador para testar se o vetor está ordenado.
Esse indicador é chamado após o algoritmo, e aqui retorna 1, confirmando que está ordenado. 
Em outros métodos que não ordenem o vetor, naturalmente que este indicador nesses casos, ao ser chamado irá retornar 0.

Vamos trocar um parâmetro, inicializar e executar novamente. Introduza: 3; 6; 2; *ENTER*; 1; *ENTER*; 6. 

```entrada
...
══ 🏁  Execução terminada ══
TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): std::vector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 1 | I2(Tempo(ms)): 73 | I3(Iterações): 1 | I4(IND_ORDENAR): 1
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Notar que o resultado em termos de dados final é 73, praticamente o mesmo. 
É natural já que ambas as estruturas de dados receberam a mesma instância.
O tempo foi 3 milisegundos superior, mas outra execução o tempo CPU pode ser distinto.

---

\anchor tvector-a4
## Ação 4: Menu 5 - Indicadores

Vamos agora ver o menu dos indicadores. Introduza: 5.

```entrada
Opção: 5

┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): ✔  1º lugar
│ Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).
│ I2(Tempo(ms)): ✔  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✔  3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_ORDENAR): ✔  4º lugar
│ verifica se o vetor está ordenado
└──────────────────────────────────────────────────────────────────────
Alterar indicador:
```

De omissão estão todos os indicadores ligados, e são chamados por ordem de ID. 
No entanto, por vezes pretende-se verificar a solução, executando verificações/validações. 
Outras vezes pretende-se obter informação sobre a instância, que nem está relacionada com a execução do algoritmo.
Pode-se ainda querer fazer ações após o algoritmo, de transformação da solução, ou gravação da solução para ficheiro.

Com os indicadores é possível definir as ações a executar após o algoritmo, por uma dada ordem, ou se uma dada ação irá ser
executada ou não.

Neste caso temos apenas um indicador definido, que é um indicador de verificação, testando se o vetor ficou ordenado.

Com esta interface podemos remover e adicionar indicadores existentes por outra ordem. 
Vamos por exemplo colocar visivel primeiro I4 e depois I2, não mostrando os restanes.

Introduza: 1;2;3;2;*ENTER*;1;*ENTER*;6.

```entrada
...
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): ✖  inativo
│ Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).
│ I2(Tempo(ms)): ✔  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✖  inativo
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_ORDENAR): ✔  1º lugar
│ verifica se o vetor está ordenado
└──────────────────────────────────────────────────────────────────────
Alterar indicador:
...
══ 🏁  Execução terminada ══
TVector
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): std::vector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I4(IND_ORDENAR): 1 | I2(Tempo(ms)): 63
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Podemos ver que agora apenas I4 seguido de I2 são apresentados. O tempo é também distinto, não tendo sido alterados nenhuns parametros.

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
Se tiver dois ou mais números, então pretendemos variar a configuração atual.

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
  1 |  1 |        1 |       80 |
  2 |  1 |        1 |       10 |
  3 |  1 |        1 |        9 |
  1 |  2 |        0 |        4 |
  2 |  2 |        0 |       12 |
  3 |  2 |        0 |       13 |
  1 |  3 |        0 |       56 |
  2 |  3 |        0 |       70 |
  3 |  3 |        0 |       57 |
  1 |  4 |        0 |        1 |
  2 |  4 |        0 |        1 |
  3 |  4 |        0 |        1 |
  1 |  5 |        1 |      284 |
  2 |  5 |        1 |       39 |
  3 |  5 |        1 |       45 |
  1 |  6 |        1 |      132 |
  2 |  6 |        1 |       52 |
  3 |  6 |        1 |       58 |
  1 |  7 |        1 |       54 |
  2 |  7 |        1 |       56 |
  3 |  7 |        1 |       70 |
  1 |  8 |        1 |       37 |
  2 |  8 |        1 |       47 |
  3 |  8 |        1 |       44 |
  1 |  9 |        1 |       56 |
  2 |  9 |        1 |       18 |
  3 |  9 |        1 |       17 |
  1 | 10 |        1 |        0 |
  2 | 10 |        1 |        0 |
  3 | 10 |        1 |        0 |
  1 | 11 |        0 |        1 |
  2 | 11 |        0 |        2 |
  3 | 11 |        0 |        4 |
  1 | 12 |        0 |        0 |
  2 | 12 |        0 |        0 |
  3 | 12 |        0 |        0 |
  1 | 13 |        1 |      244 |
  2 | 13 |        1 |       31 |
  3 | 13 |        1 |       31 |
  1 | 14 |        1 |       30 |
  2 | 14 |        1 |       31 |
  3 | 14 |        1 |       52 |
  1 | 15 |        1 |      285 |
  2 | 15 |        1 |       27 |
  3 | 15 |        1 |       29 |
  1 | 16 |        1 |       78 |
  2 | 16 |        1 |      163 |
  3 | 16 |        1 |      271 |
  1 | 17 |        1 |       78 |
  2 | 17 |        1 |      171 |
  3 | 17 |        1 |      267 |
----|----|----------|----------|resolvidas
Total  1 |        3 |       99 | 3
Total  2 |        0 |       29 | 3
Total  3 |        0 |      183 | 3
Total  4 |        0 |        3 | 3
Total  5 |        3 |      368 | 3
Total  6 |        3 |      242 | 3
Total  7 |        3 |      180 | 3
Total  8 |        3 |      128 | 3
Total  9 |        3 |       91 | 3
Total 10 |        3 |        0 | 3
Total 11 |        0 |        7 | 3
Total 12 |        0 |        0 | 3
Total 13 |        3 |      306 | 3
Total 14 |        3 |      113 | 3
Total 15 |        3 |      341 | 3
Total 16 |        3 |      512 | 3
Total 17 |        3 |      516 | 3
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|-07-|-08-|-09-|-10-|-11-|-12-|-13-|-14-|-15-|-16-|-17-|
 1    |  0 |  0 |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  7
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 2  0 |    |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 3  0 |  0 |    |  0 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  1 |  2 |  6
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 4  0 |  0 |  0 |    |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 5 -1 | -1 | -1 | -1 |    | -1 | -1 | -1 | -1 | -1 | -1 | -1 |  0 | -1 |  0 |  1 |  1 |-10
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 6  0 | -1 |  0 | -1 |  1 |    |  0 |  0 |  0 | -1 | -1 | -1 |  1 | -1 |  1 |  2 |  2 |  1
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 7  0 |  0 |  0 |  0 |  1 |  0 |    |  0 |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  7
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 8  0 |  0 |  0 |  0 |  1 |  0 |  0 |    |  0 |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  7
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 9  0 |  0 |  0 |  0 |  1 |  0 |  0 |  0 |    |  0 |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  7
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
10  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |    |  0 |  0 |  1 |  0 |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
11  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |    |  0 |  1 |  0 |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
12  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |    |  1 |  0 |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
13 -1 | -1 | -1 | -1 |  0 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |    | -1 |  0 |  1 |  1 |-10
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
14  0 |  0 |  0 |  0 |  1 |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  1 |    |  1 |  2 |  2 |  8
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
15 -1 | -1 | -1 | -1 |  0 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |  0 | -1 |    |  1 |  1 |-10
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
16 -2 | -2 | -1 | -2 | -1 | -2 | -2 | -2 | -2 | -2 | -2 | -2 | -1 | -2 | -1 |    |  0 |-26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
17 -2 | -2 | -2 | -2 | -1 | -2 | -2 | -2 | -2 | -2 | -2 | -2 | -1 | -2 | -1 |  0 |    |-27
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
Dados #3000000: -2147483260 -2147483145 -2147476511 ... 2147476201 2147479659 2147481540
____________________________________________________________________
```

Podemos ver que durante a execução, é mostrada a configuração atual, a instância a ser resolvida.
No final são mostrados resultados para cada configuração e instância, agregasdos por configuração.
Os indicadores selecionados fazem parte da tabela de resultados.

Podemos ver que o indicador definido na subclasse, Ordenado, retorna 1 nos métodos cujo resultado final o vetor fica ordenado, e 0 nos restantes.

É mostrado ainda um torneio entre configurações, para saber a que é mais rápida.
Para permitir a reprodução e identificar eventuais enganos, é mostrado no final os valores exatos de cada configuração.

Infelizmente, pouco podemos concluir com este teste. 
O motivo é que não tinhamos uma pergunta formulada, mas solicitamos simplesmente execuções com diversas configurações.
Sabemos apenas que não há crash.

Vamos formular uma pergunta. Pretendemos saber como varia o tempo na operação de ordenação, com o tamanho do vetor.

Poderiamos estar a apagar as configurações uma a uma, mas vamos arrancar de novo, para não ter qualquer configuração.
Introduza após arrancar: 7; P1=2; *ENTER*; 8; 1:10; *ENTER*; 0.

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
  1 |  1 |        1 |       84 |        1 |        1 |
  2 |  1 |        1 |      278 |        1 |        1 |
  3 |  1 |        1 |      414 |        1 |        1 |
  4 |  1 |        1 |      570 |        1 |        1 |
  5 |  1 |        1 |      590 |        1 |        1 |
  6 |  1 |        1 |      827 |        1 |        1 |
  7 |  1 |        1 |      947 |        1 |        1 |
  8 |  1 |        1 |     1111 |        1 |        1 |
  9 |  1 |        1 |     1170 |        1 |        1 |
 10 |  1 |        1 |     1314 |        1 |        1 |
----|----|----------|----------|----------|----------|resolvidas
Total  1 |       10 |     7305 |       10 |       10 | 10
...
```
Podemos ver que o tempo sobe, mas não de forma linear. 
A instância 1 tem 1 milhão de valores, leva 84 milisegundos.
A instância 10 tem 10 vezes mais tamanho, mas leva mais que 840 milisegundos, foi 1314.
Foram execuções únicas, os valores podem variar demasiado.

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

Existe a indicação que o ficheiro resultado.csv foi gravado. 

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

Abra a linha de comando, localize o executável, e execute com argumento "-h".
Vamos executar na pasta Teste, pelo que funcionará a linha: 

```entrada
C:\...\TProcura\Teste> ../x64/Release/TProcura -h
```

Para simplificidade, omitimos a pasta e path do executável.

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
Exemplo: TProcura.exe 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2
   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores

Lista de parâmetros:
 P1(Método): Add() (1 a 12)
 P2(Debug): nada (0 a 4)
 P3(Seed): 1 (1 a 1000000)
 P4(Tempo): 10 (1 a 3600)
 P5(Iterações): 0 (0 a 1000000000)
 P6(Estrutura): TVector (1 a 3)

Lista de indicadores:

I1(Resultado): 1º lugar (Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).)
I2(Tempo(ms)): 2º lugar (Tempo em milisegundos da execução (medida de esforço computacional).)
I3(Iterações): 3º lugar (Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).)
I4(Ordenado): 4º lugar (verifica se o indicador está ordenado)
```

A lista completa de parametros e indicadores é também mostrada, para permitir saber o que se pode utilizar na definição das configurações de execução.

Podemos assim reproduzir o teste anterior com a seguinte entrada.

Linha de comando: TProcura.exe 1:10 -R resultado2 -P P1=2 P2=4 P3=1:10

O nível de debug destina-se à informação a reportar sobre o andamento do teste, 
e não do algoritmo que executa sempre com debug nível 0, de modo a obter os melhores tempos.

```entrada
PS ...\Teste> TProcura 1:10 -R resultado2 -P P1=2 P2=4 P3=1:10
Parâmetros comuns:
 P1=2 P2=4 P4=10 P5=0 P6=1
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
Teste com 100 tarefas, 10 instâncias, 10 configurações, utilizando 1 processo(s). instância 1:
Solução: .DONE.instância 2:
Solução: .DONE.instância 3:
Solução: .DONE.instância 4:
Solução: .DONE.instância 5:
Solução: .DONE.
1" 358ms  Tarefa 5. instância 6:
Solução: .DONE.instância 7:
Solução: .DONE.
2" 547ms  Tarefa 7. instância 8:
...
46" 376ms  Tarefa 95. instância 6:
Solução: .DONE.instância 7:
Solução: .DONE.
47" 666ms  Tarefa 97. instância 8:
Solução: .DONE.instância 9:
Solução: .DONE.
49" 204ms  Tarefa 99. instância 10:
Solução: .DONE.
Ficheiro resultado2.csv gravado.
Tempo real: 50" 117ms
CPU total: 50" 120ms
Taxa de utilização: 100,0%
```

O tempo total foi de 50 segundos, com debug a 0 não iriamos ter nenhum input senão após o teste terminar.

Podemos agora processar o ficheiro e confirmar que tem resultados idênticos.

| Rótulos de Linha | Média de I2 (Tempo ms) |
|:----------------:|-----------------------:|
|        1         |                  71,2  |
|        2         |                 153,1  |
|        3         |                 231,3  |
|        4         |                 309,0  |
|        5         |                 389,2  |
|        6         |                 472,1  |
|        7         |                 564,9  |
|        8         |                 645,0  |
|        9         |                 732,1  |
|       10         |                 836,0  |
| **Total Geral**  |               **440,4**|

Utilizamos agora as tabelas diretamente, em vez de imagens do Excel. 

Os valores são distintos devido a ter sido executado num outro computador, mas tem exactamente a mesma tendência.
A média do tempo sobe com o tamanho, mas não de forma linear.

Estando respondida a questão inicial sobre o tempo de ordenação, podemos com este código procurar responder a outra questão:

- considerando todas as operações em teste, há diferença entre alguma das estruturas de dados em termos de tempo?

De modo a ter uma resposta rápida mas com várias iteraçoes, vamos utilizar apenas as instâncias 1 e 3, mas mantendo 10 sementes aleatórias.
Temos também de variar a estrutura de dados.

Linha de comando: TProcura 1,3 -R resultadosTudo -P P1=1:12 x P3=1:10 x P6=1:3

Podemos processar no relatório dinâmico, colocando nas linhas P1 com os métodos, nas colunas P6 com as estruturas, 
e no conteúdo I2 com o tempo.

Soma de I2(Tempo(ms)):
| Rótulos de Linha | 1:TVector | 2:std::vector | 3:TVector/std::algorithm |
|:----------------:|----------:|--------------:|-------------------------:|
| 1:Add()          |       160 |           180 |                      178 |
| 10:operator=()   |        29 |            10 |                       28 |
| 11:operator+=()  |        30 |            54 |                       31 |
| 12:nada          |         0 |             0 |                        0 |
| 2:Sort()         |      3048 |          3355 |                     3432 |
| 3:RandomOrder()  |       404 |           613 |                      601 |
| 4:Invert()       |        27 |            10 |                        9 |
| 5:BeASet()       |      3081 |          3577 |                     3411 |
| 6:Difference()   |      6504 |          7300 |                     7358 |
| 7:Union()        |      9634 |          6990 |                    10792 |
| 8:Contained()    |      5994 |          6788 |                     6610 |
| 9:Intersection() |      6533 |          7129 |                     7420 |
| **Total Geral**  |   **35444** |      **36006** |                 **39870** |


Segundo estes resultados, TVector tem uma ligeira vantagem em termos de tempo na ordenação, mas é pior na união e outras operações, e no final há uma diferença de 1 segundo em 35. 
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
## Ação 8: Execução MPI




---

\anchor tvector-a9
## Ação 9: Desafio CTesteTVector

Será a ordenação de TVector mais rápida ou mais lenta ue a ordenação da STL?
Que testes pode fazer para procurar dar uma resposta fundamentada?

<details>
  <summary>Resposta:</summary>
Deve procurar executar com instâncias de dimensão razoável, vamos utilizar a 10 que é a maior.
Deve-se executar várias vezes, e apenas na operação de ordenação.
Linha de comando: TProcura 10 -R resultadosSort -P P1=2 P3=1:10 x P6=1:3

| Valores | 1:TVector | 2:std::vector | 3:TVector/std::algorithm | 
|:---:|---:|---:|---:|
| Mínimo de I2(Tempo(ms)) | 772 | 844 | 888 | 
| Média de I2(Tempo(ms)) | 801,8 | 915,9 | 915,5 | 
| Máximo de I2(Tempo(ms)) | 830 | 956 | 937 | 

Os resultados aparentam confirmar que há uma certa vantagem para o algoritmo,
certamente mais simples do TVector nestes vetores. Um teste estatístico poderá dar resposta se as médias são distintas ou não,
mas tudo indica que sim.
Este pode ser um efeito de uma codificação intensa do STL não beneficiar de optimizações que tenham sido introduzidas no compilador, 
ao contrário de um código que seja compilado na altura.
</details>

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

