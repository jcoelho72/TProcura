@page teste_tvector Teste TVector

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base na classe de teste de TVector. 
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcura, e execute.
No Linux na pasta `.../TProcura/Teste$` execute `make` seguido de `./bin/Release/TProcura`

Este exemplo serve para ilustrar as funcionalidades principais de testes paramétricos da classe TProcura.
Nos exemplos das subclasses ilustra-se as restantes funcionalidades.

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1: Menu 1 - Instância](#tvector-a1)
- [Ação 2: Menu 3 - Parâmetros](#tvector-a2)
- [Ação 3: Menu 6 - Executar](#tvector-a3)
- [Ação 4: Menu 5 - Indicadores](#tvector-a4)
- [Ação 5: Menu 7 - Configurações](#tvector-a5)
- [Ação 6: Menu 8 - Teste](#tvector-a6)
- [Ação 7: Linha de comando](#tvector-a7)
- [Ação 8: Execução MPI](#tvector-a8)


```entrada
TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
┌─ ☰ Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄  Instância  │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
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
## Ação 1: Menu 1 - Instância

Vamos ver o menu 1 instância. Introduza: 1; 2.

```entrada
Opção: 1

┌─ 📄 Instância ───────────────────────────────────────────────────────
│ ID atual: 1  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 2

TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #2000000: -498792314 -2114916689 -1334173636 ... 1289309513 1347067406 1395724283
┌─ ☰ Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄  Instância  │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```
Este menu permite inicializar os dados utilizados no algoritmo.
Esses dados iniciais são a instância, que pode ser gerada aleatoriamente ou fornecido um ficheiro.
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

┌─ 📄 Instância ───────────────────────────────────────────────────────
│ ID atual: 2  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 1

TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Add() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -498792314 -2114916689 -1334173636 ... 906240738 -1410932558 -1243737237
┌─ ☰ Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 📄  Instância  │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```

Notar que a instância é exatamente a mesma, como se pode confirmar pelos números iniciais e finais do vetor.

O menu **2 Explorar**, serve para explorar o problema manualmente, mas neste caso não definimos nenhuma função para
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

┌─ 📄 Instância ───────────────────────────────────────────────────────
│ ID atual: 1  Intervalo: [1–10]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto):

TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
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

═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ P1=2 P2=0 P3=2 P4=10 P5=0 P6=1
═╧═ 🏁  Execução terminada ⏱  81ms  ═══
TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): TVector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 1 | I2(Tempo(ms)): 80 | I3(Iterações): 1 | I4(IND_ORDENAR): 1
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
A execução arranca, os valores dos parâmetros em modo curto são mostrados, e de seguida a execução é terminada.
Ao teminar a execução é mostrado o tempo bruto utilizado, neste caso 80 milisegundos.
Podemos ver novamente os parâmetros utilizados, tendo sido executado o método Sort(), com a estrutura TVector.
O estado do vetor é visivel os três primeiros e últimos elementos, podendo-se confirmar que estes estão por ordem.

Como já houve uma execução, existe agora mais uma linha antes do menu, com os indicadors, I1 a I4.

Os três primeiros indicadores são de TProcura, o quarto indicador é definido em CTesteTVector.
O indicador I1 tem o resultado do algoritmo, normalmente ao valor / qualidade da solução, que aqui é sempre 1 a não ser que exista algum problema.
O indicador I2 tem o tempo consumido pelo algoritmo, em milisegundos, neste caso 80. 
Notar que este tempo é apenas de execução, não é contabilizado o tempo de inicialização (ao criar a instância).
O tempo de calcular os indicadores não é também comtabilizado.
O indicador I3 tem o número de iterações realizadas. 
O algoritmo deve atualizar as iterações, neste caso ordenou apenas uma vez.
Como queremos saber se a operação foi bem sucedida, definiu-se um indicador para testar se o vetor está ordenado.
Esse indicador é chamado após o algoritmo, e aqui retorna 1, confirmando que está ordenado. 
Em outros métodos que não ordenem o vetor, naturalmente que este indicador nesses casos, ao ser chamado irá retornar 0.

Vamos trocar um parâmetro, inicializar e executar novamente. Introduza: 3; 6; 2; *ENTER*; 1; *ENTER*; 6. 

```entrada
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ P1=2 P2=0 P3=2 P4=10 P5=0 P6=2
═╧═ 🏁  Execução terminada ⏱  60ms  ═══
TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): std::vector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): 1 | I2(Tempo(ms)): 59 | I3(Iterações): 1 | I4(IND_ORDENAR): 1
└──────────────────────────────────────────────────────────────────────
...
Opção:
```

Notar que o resultado em termos de dados final é 59, praticamente o mesmo. 
É natural já que ambas as estruturas de dados receberam a mesma instância.
A diferença de tempo em outra execução pode ser diferente.

---

\anchor tvector-a4
## Ação 4: Menu 5 - Indicadores

Vamos agora ver o menu dos indicadores. Introduza: 5.

```entrada
Opção: 5

┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): ☑  1º lugar
│ Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).
│ I2(Tempo(ms)): ☑  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ☑  3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_ORDENAR): ☑  4º lugar
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
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): ☐  inativo
│ Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).
│ I2(Tempo(ms)): ☑  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ☐  inativo
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_ORDENAR): ☑  1º lugar
│ verifica se o vetor está ordenado
└──────────────────────────────────────────────────────────────────────
Alterar indicador:
...
Opção: 6

═╤═ ►  Execução iniciada ═══
 ├─ Parâmetros ─ P1=2 P2=0 P3=2 P4=10 P5=0 P6=2
═╧═ 🏁  Execução terminada ⏱  12ms  ═══
TVector
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO): Sort() | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 2 | P4(LIMITE_TEMPO): 10
│ P5(LIMITE_ITERACOES): 0 | P6(ESTRUTURA_DADOS): std::vector
└──────────────────────────────────────────────────────────────────────
Dados #1000000: -2147476511 -2147469585 -2147464842 ... 2147468823 2147468881 2147475808
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I4(IND_ORDENAR): 1 | I2(Tempo(ms)): 12
└──────────────────────────────────────────────────────────────────────
...
Opção:
```
Podemos ver que agora apenas I4 seguido de I2 são apresentados. O tempo é também distinto, não tendo sido alterados nenhuns parametros.

---

\anchor tvector-a5
## Ação 5: Menu 7 - Configurações

Os métodos utilizados até aqui, permitem executar testes confortavelmente sem ter de andar a alterar código,
compilar e executar.
Pode-se ir registando os dados, e procurar tirar conclusões.

No entanto, execuções particulares podem ser enganadoras, como o tempo de execução da
ordenação entre TVector e o sort() da STL. 
Para existir garantias, temos de fazer muitas execuções, com diferentes parâmetros,
e poder processar os resultados posteriormente.

Assim, é crítico que se possa definir confortavelmente todas as configurações a executar,
de modo a obter resultados em bloco, e não um a um.

Introduza: 7.

```entrada
Opção: 7

 ├─ 🛠️ ─ P1=2 P2=0 P3=2 P4=10 P5=0 P6=2 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─  ⭐ atual
═╧═══════════════════
┌─ 📖 Sintaxe comando ──────────────────────────────────────────────────
│    id / -id - Seleciona configuração como atual ou apaga 'id'
│    Pk = <conj.> - Varia Pk na configuração atual (gera N configs)
│    Pk = <conj.> x Pw = <conj.> - produto externo (gera NxM configs)
│  Sintaxe de <conj.> : A,B,C | A:B | A:B:C
└──────────────────────────────────────────────────────────────────────
✏️ Comando:
```

Temos aqui a lista dos parâmetros atuais. Há apenas uma configuração, com os parâmetros que alteramos.
Se não alterarmos parâmetros, estes tomam o valor de omissão, nunca existindo um parâmetro sem valor definido.
Os parâmetros apenas podem ser alterados para valores dentro dos seus limites.

Existe atualmente apenas uma configuração, em que todos os parâmetros são comuns.
Vamos colocar o parâmetro P1, com o método, a variar de 1 a 12, para testar todos os métodos.

Introduza: P1=1:12

```entrada
✏️ Comando: P1=1:12

 ├─ 🛠️ ─ P2=0 P3=2 P4=10 P5=0 P6=2 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P1=2 ⭐ atual
 ├─ ⚙️ [2] ─ P1=1
 ├─ ⚙️ [3] ─ P1=3
 ├─ ⚙️ [4] ─ P1=4
 ├─ ⚙️ [5] ─ P1=5
 ├─ ⚙️ [6] ─ P1=6
 ├─ ⚙️ [7] ─ P1=7
 ├─ ⚙️ [8] ─ P1=8
 ├─ ⚙️ [9] ─ P1=9
 ├─ ⚙️ [10] ─ P1=10
 ├─ ⚙️ [11] ─ P1=11
 ├─ ⚙️ [12] ─ P1=12
═╧═══════════════════
┌─ 📖 Sintaxe comando ──────────────────────────────────────────────────
│    id / -id - Seleciona configuração como atual ou apaga 'id'
│    Pk = <conj.> - Varia Pk na configuração atual (gera N configs)
│    Pk = <conj.> x Pw = <conj.> - produto externo (gera NxM configs)
│  Sintaxe de <conj.> : A,B,C | A:B | A:B:C
└──────────────────────────────────────────────────────────────────────
✏️ Comando:
```

Notar que P1 já não é mostrado nos parâmetros comuns, mas sim os seus diversos valores nas configurações de 1 a 12.
A notação 1:12 significa os números de 1 a 12. 
Se tivessemos colocado 1:12:2 correspondia aos números de 1 a 12 mas em passos de 2.
Podiamos ter indicado também com a notação por vírgulas, com 1,2,3,4,5,6,7,8,9,10,11,12. 
Podemos misturar notações, por exemplo, podiamos especificar o conjunto 1:3,5:9:2,12, ou seja, os números 1,2,3,5,7,9,12.

Se pretendermos alterar apenas o valor de um parâmetro k para V, colocamos Pk=V. 
Se existirem dois ou mais valores, então pretendemos variar a configuração atual.

Vamos agora colocar dois parâmetros a variar em conjunto, ou seja, estamos interessados no produto externo.
Introduza: P3=1:2 x P6=1:3.

```entrada
✏️ Comando: P3=1:2 x P6=1:3

 ├─ 🛠️ ─ P2=0 P4=10 P5=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P1=2 P3=2 P6=2 ⭐ atual
 ├─ ⚙️ [2] ─ P1=1 P3=2 P6=2
 ├─ ⚙️ [3] ─ P1=3 P3=2 P6=2
 ├─ ⚙️ [4] ─ P1=4 P3=2 P6=2
 ├─ ⚙️ [5] ─ P1=5 P3=2 P6=2
 ├─ ⚙️ [6] ─ P1=6 P3=2 P6=2
 ├─ ⚙️ [7] ─ P1=7 P3=2 P6=2
 ├─ ⚙️ [8] ─ P1=8 P3=2 P6=2
 ├─ ⚙️ [9] ─ P1=9 P3=2 P6=2
 ├─ ⚙️ [10] ─ P1=10 P3=2 P6=2
 ├─ ⚙️ [11] ─ P1=11 P3=2 P6=2
 ├─ ⚙️ [12] ─ P1=12 P3=2 P6=2
 ├─ ⚙️ [13] ─ P1=2 P3=1 P6=1
 ├─ ⚙️ [14] ─ P1=2 P3=2 P6=1
 ├─ ⚙️ [15] ─ P1=2 P3=1 P6=2
 ├─ ⚙️ [16] ─ P1=2 P3=1 P6=3
 ├─ ⚙️ [17] ─ P1=2 P3=2 P6=3
═╧═══════════════════
┌─ 📖 Sintaxe comando ──────────────────────────────────────────────────
│    id / -id - Seleciona configuração como atual ou apaga 'id'
│    Pk = <conj.> - Varia Pk na configuração atual (gera N configs)
│    Pk = <conj.> x Pw = <conj.> - produto externo (gera NxM configs)
│  Sintaxe de <conj.> : A,B,C | A:B | A:B:C
└──────────────────────────────────────────────────────────────────────
✏️ Comando:
```

Foram dados 2 valores para P3 e 3 valores para P6, tendo sido produzidos mais 5 novas configurações,
já que uma é a configuração base (a atual).

Vamos agora utilizar as configurações num teste. Introduza: *ENTER*.

Avance para a próxima ação.

---

\anchor tvector-a6
## Ação 6: Menu 8 - Teste

Tendo configurações introduzidas, vamos agora executar um teste com estas configurações.
Introduza: 8; 1:3; *ENTER*.

A primeira pergunta é sobre quais as instâncias a excutar o teste, na qual pretendemos as 3 primeiras.
A segunda pergunta é para colocar os resultados num ficheiro de texto, para já não estamos interesados.

```entrada
Opção: 8

┌─ 📖 Sintaxe comando ────────────────────
│  Instâncias: A,B,C | A:B | A : B : C
└────────────────────────────────────────
📄 IDs das instâncias (1 a 10): 1:3
🗎  Ficheiro resultados (nada para mostrar no ecrã):


═╤═ Instâncias ═══ { 📄1 📄2 📄3 }
 ├─ 🛠️ ─ P2=0 P4=10 P5=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P1=2 P3=2 P6=2
 ├─ ⚙️ [2] ─ P1=1 P3=2 P6=2
 ├─ ⚙️ [3] ─ P1=3 P3=2 P6=2
 │ ...
 ├─ ⚙️ [15] ─ P1=2 P3=1 P6=2
 ├─ ⚙️ [16] ─ P1=2 P3=1 P6=3
 ├─ ⚙️ [17] ─ P1=2 P3=2 P6=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
┌──────┬───────┬───────────┬───────────┐
│ 📄    │ 🛠️    │ 💰         │ ⏱         │
├──────┼───────┼───────────┼───────────┤
│ 1    │ 1     │ 0         │ 63        │
│ 2    │ 1     │ 0         │ 126       │
│ 3    │ 1     │ 0         │ 196       │
│ 1    │ 2     │ 0         │ 3         │
│ 2    │ 2     │ 0         │ 8         │
│ 3    │ 2     │ 0         │ 10        │
│ 1    │ 3     │ 0         │ 3         │
│ 2    │ 3     │ 0         │ 10        │
│ 3    │ 3     │ 0         │ 23        │
│ 1    │ 4     │ 0         │ 0         │
│ 2    │ 4     │ 0         │ 0         │
│ 3    │ 4     │ 0         │ 1         │
│ 1    │ 5     │ 0         │ 61        │
│ 2    │ 5     │ 0         │ 127       │
│ 3    │ 5     │ 0         │ 198       │
│ 1    │ 6     │ 0         │ 129       │
│ 2    │ 6     │ 0         │ 286       │
│ 3    │ 6     │ 0         │ 438       │
│ 1    │ 7     │ 0         │ 131       │
│ 2    │ 7     │ 0         │ 275       │
│ 3    │ 7     │ 0         │ 456       │
│ 1    │ 8     │ 0         │ 148       │
│ 2    │ 8     │ 0         │ 357       │
│ 3    │ 8     │ 0         │ 422       │
│ 1    │ 9     │ 0         │ 141       │
│ 2    │ 9     │ 0         │ 275       │
│ 3    │ 9     │ 0         │ 452       │
│ 1    │ 10    │ 0         │ 0         │
│ 2    │ 10    │ 0         │ 1         │
│ 3    │ 10    │ 0         │ 1         │
│ 1    │ 11    │ 0         │ 0         │
│ 2    │ 11    │ 0         │ 0         │
│ 3    │ 11    │ 0         │ 21        │
│ 1    │ 12    │ 0         │ 0         │
│ 2    │ 12    │ 0         │ 0         │
│ 3    │ 12    │ 0         │ 0         │
│ 1    │ 13    │ 0         │ 69        │
│ 2    │ 13    │ 0         │ 157       │
│ 3    │ 13    │ 0         │ 230       │
│ 1    │ 14    │ 0         │ 67        │
│ 2    │ 14    │ 0         │ 145       │
│ 3    │ 14    │ 0         │ 251       │
│ 1    │ 15    │ 0         │ 60        │
│ 2    │ 15    │ 0         │ 130       │
│ 3    │ 15    │ 0         │ 200       │
│ 1    │ 16    │ 0         │ 62        │
│ 2    │ 16    │ 0         │ 134       │
│ 3    │ 16    │ 0         │ 193       │
│ 1    │ 17    │ 0         │ 60        │
│ 2    │ 17    │ 0         │ 128       │
│ 3    │ 17    │ 0         │ 196       │
└──────┴───────┴───────────┴───────────┘
┌─ 📊  Total 🛠️ 1 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 385 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 2 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 21 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 3 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 36 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 4 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 1 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 5 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 386 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 6 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 853 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 7 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 862 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 8 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 927 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 9 ──────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 868 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 10 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 2 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 11 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 21 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 12 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 0 Tempo(ms): 0 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 13 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 456 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 14 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 463 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 15 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 390 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 16 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 389 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
┌─ 📊  Total 🛠️ 17 ─────────────────────────────────────────────────────
│ IND_ORDENAR: 3 Tempo(ms): 384 Instâncias resolvidas: 3
└──────────────────────────────────────────────────────────────────────
🏆  Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|-07-|-08-|-09-|-10-|-11-|-12-|-13-|-14-|-15-|-16-|-17-|
 1    | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 2  2 |    |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 3  2 |  0 |    |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 4  2 |  0 |  0 |    |  2 |  3 |  3 |  3 |  3 |  0 |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 5  0 | -2 | -2 | -2 |    |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 6 -2 | -3 | -3 | -3 | -2 |    |  0 |  0 |  0 | -3 | -3 | -3 | -2 | -2 | -2 | -2 | -2 |-32
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 7 -2 | -3 | -3 | -3 | -2 |  0 |    |  0 |  0 | -3 | -3 | -3 | -2 | -2 | -2 | -2 | -2 |-32
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 8 -2 | -3 | -3 | -3 | -2 |  0 |  0 |    |  0 | -3 | -3 | -3 | -2 | -2 | -2 | -2 | -2 |-32
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
 9 -2 | -3 | -3 | -3 | -2 |  0 |  0 |  0 |    | -3 | -3 | -3 | -2 | -2 | -2 | -2 | -2 |-32
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
10  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |    |  0 |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
11  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |    |  0 |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
12  2 |  0 |  0 |  0 |  2 |  3 |  3 |  3 |  3 |  0 |  0 |    |  2 |  2 |  2 |  2 |  2 | 26
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
13  0 | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |    |  0 |  0 |  0 |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
14  0 | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |    |  0 |  0 |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
15  0 | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |  0 |    |  0 |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
16  0 | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |  0 |  0 |    |  0 | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
17  0 | -2 | -2 | -2 |  0 |  2 |  2 |  2 |  2 | -2 | -2 | -2 |  0 |  0 |  0 |  0 |    | -4
 |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|

═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  7" 318ms ) ═══
,,,
Opção:
```

As instâncias utilizadas e as configurações atuais são mostradas logo de início,
para clarificar o que vai ser executado no teste e poder identificar algum problema.

Podemos ver que durante a execução, nada é mostrado, sendo mostrados os resultados dos testes no final.

O parametro P2(NIVEL_DEBUG) controla do debug do algoritrmo durante a execução simples, no comando 6.
Num teste o debug do algoritmo é sempre colocado a 0, sendo este parametro utilizado para
mostrar informações do teste.

Como o teste foi rápido, não havia muito a mostrar, mas ao executar um teste longo,
é importante que saiba o estado atual do teste.

No final é mostrada primeiramente uma tabela de resultados, com apenas o custo e tempo, por cada instância e configuração em teste.
Como o custo não está nos indicadores calculados, ficou a zero, caso contrário ficaria a 1 já que foi assim que definimos nesta instância para sucesso.

Seguem-se os totais por configuração, e um torneio entre configurações, sendo contabilizada vitória para a configuração que tiver melhores resultados em mais instâncias.

O detalhe dos parametros em cada configuração é replicado no final, para associar os resultados aos parametros utilizados.

Infelizmente, pouco podemos concluir com este teste. 
O motivo é que não tinhamos uma pergunta formulada, mas solicitamos simplesmente execuções com diversas configurações.
Sabemos apenas que não há crash.

Vamos procurar fazer um teste mais estruturado.
Pretendemos fazer um teste de performance, na operação de ordenação.
Queremos saber como varia o tempo na operação de ordenação, com o tamanho do vetor.

Poderiamos estar a apagar as configurações uma a uma, mas vamos arrancar de novo, para não ter qualquer configuração.
Vamos agora colocar a informação de debug no máximo.
Introduza após arrancar: 7; P1=2 P2=4; *ENTER*; 8; 1:10; *ENTER*.


```entrada
Opção: 8

┌─ 📖 Sintaxe comando ────────────────────
│  Instâncias: A,B,C | A:B | A : B : C
└────────────────────────────────────────
📄 IDs das instâncias (1 a 10): 1:10
🗎  Ficheiro resultados (nada para mostrar no ecrã):


═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=4 P3=1 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:10   📄 Instâncias: 10   🛠️ Configurações: 1   🖥️ Processos: 1.
 ├─ ⏱                 📋 1     📄 1     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 62 1 1
 ├─ ⏱ 71ms            📋 2     📄 2     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 131 1 1
 ├─ ⏱ 225ms           📋 3     📄 3     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 224 1 1
 ├─ ⏱ 483ms           📋 4     📄 4     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 315 1 1
 ├─ ⏱ 845ms           📋 5     📄 5     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 518 1 1
 ├─ ⏱ 1" 444ms        📋 6     📄 6     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 452 1 1
 ├─ ⏱ 2" 6ms          📋 7     📄 7     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 513 1 1
 ├─ ⏱ 2" 603ms        📋 8     📄 8     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 660 1 1
 ├─ ⏱ 3" 372ms        📋 9     📄 9     🛠️ 1     🖥️ 1    🎯 1    ⚖  1 686 1 1
 ├─ ⏱ 4" 160ms        📋 10    📄 10    🛠️ 1     🖥️ 1    🎯 1    ⚖  1 786 1 1
┌──────┬───────┬───────────┬───────────┐
│ 📄    │ 🛠️    │ 💰         │ ⏱         │
├──────┼───────┼───────────┼───────────┤
│ 1    │ 1     │ 1         │ 62        │
│ 2    │ 1     │ 1         │ 131       │
│ 3    │ 1     │ 1         │ 224       │
│ 4    │ 1     │ 1         │ 315       │
│ 5    │ 1     │ 1         │ 518       │
│ 6    │ 1     │ 1         │ 452       │
│ 7    │ 1     │ 1         │ 513       │
│ 8    │ 1     │ 1         │ 660       │
│ 9    │ 1     │ 1         │ 686       │
│ 10   │ 1     │ 1         │ 786       │
└──────┴───────┴───────────┴───────────┘
┌─ 📊  Total 🛠️ 1 ──────────────────────────────────────────────────────
│ Resultado: 10 Tempo(ms): 4347 Iterações: 10 IND_ORDENAR: 10 Instâncias resolvidas: 10
└──────────────────────────────────────────────────────────────────────
🏆  Torneio (#instâncias melhores):
 |-01-|
 1    |  0
 |----|

═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  5" 79ms ) ═══
TVector
...
Opção:
```
A informação debug completa mostra por cada execução uma linha.
Em cada linha é identificado o instante, tarefa, instância, configuração, processo e finalmente os indicadores calculados.

Sobre os resultados mostrados em tabela, podemos ver que o tempo sobe, mas não de forma linear. 
A instância 1 tem 1 milhão de valores, leva 62 milisegundos.
A instância 10 tem 10 vezes mais tamanho, mas leva 786 milisegundos.
Foram execuções únicas, os valores podem variar demasiado.

Vamos colocar 10 instâncias de cada tipo, variando a semente, para assim ter mais precisão. 
Queremos desta vez ter os resultados no Excel (utilizando a pasta Resultados) e vamos colocar o debug a 1.

Introduza: 7; P1=2; P2=1; P3=1:10; *ENTER*; 8; 1:10; Resultados/tvetor_0.

```entrada
Opção: 8

┌─ 📖 Sintaxe comando ────────────────────
│  Instâncias: A,B,C | A:B | A : B : C
└────────────────────────────────────────
📄 IDs das instâncias (1 a 10): 1:10
🗎  Ficheiro resultados (nada para mostrar no ecrã): Resultados/tvetor_0


═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=1 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P3=1
 ├─ ⚙️ [2] ─ P3=2
 ├─ ⚙️ [3] ─ P3=3
 ├─ ⚙️ [4] ─ P3=4
 ├─ ⚙️ [5] ─ P3=5
 ├─ ⚙️ [6] ─ P3=6
 ├─ ⚙️ [7] ─ P3=7
 ├─ ⚙️ [8] ─ P3=8
 ├─ ⚙️ [9] ─ P3=9
 ├─ ⚙️ [10] ─ P3=10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:100   📄 Instâncias: 10   🛠️ Configurações: 10   🖥️ Processos: 1.
 ├─ 🗎  Ficheiro Resultados/tvetor_0.csv gravado.
 │  ⏱  Tempo real: 46" 488ms
 │  ⏱  CPU total: 46" 488ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  46" 498ms ) ═══
...
Opção:
```

Podemos ver uma primeira linha indicando que há 100 tarefas, 10 instâncias, 10 configurações e 1 processo, já que não estamos a executar em MPI.
Existe a indicação que o ficheiro Resultados/tvetor_01.csv foi gravado, em vez da tabela de resultados final da execução anterior.
No final é dado o tempo real, o tempo total de CPU e a utilização, que neste caso é 100% já que é um programa em série.

O ficheiro está pronto para fazermos uma análise com os relatórios dinâmicos. 
Colocando a instância nas linhas, e o tempo no conteúdo, deverá ser visivel o tempo crescente de forma estável, um pouco acima de linear.

![resultados](docs/images/tvetor1.png)

---

\anchor tvector-a7
## Ação 7: Linha de comando

Embora o modo interativo seja útil no desenvolvimento do algoritmo ou problema, 
os testes paramétricos é que nos vão suportar uma resposta a algum tipo de hipótese formada.

A linha de comando é normalmente mais simples, para por um lado poder colocar a correr num servidor, por outro,
pode ver exatamente o teste solicitado numa só linha, não estando dependente da interação do utilizador.

Vamos neste e nos testes seguintes, utilizar o modelo de teste descrito em [Testes de Algoritmos com o TProcura](investigacao.html)

Vamos recomeçar, sendo o primeiro passo conhecer os parametros e indicadores disponíveis.

Abra a linha de comando, localize o executável, e execute com argumento "-h".
Vamos executar na pasta Teste, pelo que funcionará a linha (Windows usar x64 Linux bin): 

```entrada
.../TProcura/Teste$ ../bin/Release/TProcura -h
```

Para simplificidade, omitimos a pasta e path do executável.

```entrada
./bin/Release/TProcura -h
Uso: ./bin/Release/TProcura <instâncias> [opções]
  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]
Opções:
  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)
  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)
  -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador
  -I <ind>        Lista de indicadores (e.g. 2,1,3)
  -h              Esta ajuda
  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - último campo
Exemplo: ./bin/Release/TProcura 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2
   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores

Lista de parâmetros:
┌─ ⚙️ Parâmetros ──────────────────────────────────────────────────────
│ P1(ALGORITMO):             Add()      ( 1 a  12)
│ P2(NIVEL_DEBUG):           NADA       ( 0 a  4)
│ P3(SEMENTE):               1          ( 1 a  1000000)
│ P4(LIMITE_TEMPO):          10         ( 1 a  3600)
│ P5(LIMITE_ITERACOES):      0          ( 0 a  1000000000)
│ P6(ESTRUTURA_DADOS):       TVector    ( 1 a  3)
└──────────────────────────────────────────────────────────────────────

Lista de indicadores:
┌─ ⚖ Indicadores ─────────────────────────────────────────────────────
│ I1(Resultado): ☑  1º lugar
│ Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).
│ I2(Tempo(ms)): ☑  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ☑  3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_ORDENAR): ☑  4º lugar
│ verifica se o vetor está ordenado
└──────────────────────────────────────────────────────────────────────
```

Podemos ver os parametros específicos do programa, e também a lista completa de parametros e indicadores
do algoritmo. Assim podemos saber o que utilizar na definição das configurações de execução.


### Teste: tvetor_1

Podemos neste teste reproduzir o teste anterior de acordo com o modelo de Teste.
Nesse teste queremos saber como varia o tempo na operação de ordenação, com o tamanho do vetor,
ou seja, pretendemos um teste de performance.

- **Tipo de Teste / Objetivo**: Performance (tempo vs tamanho)
- **Definição**: Instâncias: 1:10; Configurações: P1=2
- **Esforço**: P3=1; P3=1:10; P3=1:100
- **Execução**: TProcura 1:10 -R Resultados/tvetor_1 -P P1=2 P2=3 P3=1

Vamos explicar estes pontos. Temos primeiramente o teste identificado pelo nome do problema,
seguido pelo ID do teste: tvetor_1. Existindo outros testes, têm ID incremental e não colidem com este nome.
É identificado que se pretende um teste de performance, e estamos interesados em medir o tempo
pelo tamanho. Como o tamanho é dado pelo ID da instância, basta variar a instância e temos
os resultados para o teste de Performance.
Na definição do teste, para além das instâncias, fixamos a operação definida em P1 para 2, que é a ordenação.
Define-se ainda como repetir o teste com esforços distintos, para maior precisão.

Este teste foi já realizado duas vezes, uma com 1 execução em cada instância, outra com 10.
Mas basicamente foram o mesmo teste. Aqui considera-se que são versões distintas (A, B, C) do mesmo teste.
É simples e suficiente alterar P3 para aumentar o esforço, dado que as instâncias são geradas aleatoriamente,
alterando a semente altera-se a instância.

Finalmente a execução tem os argumentos a colocar na linha de comando,
não ficando o teste dependente da correta interação com o programa para que este seja bem introduzido.
Um simples copy/paste garante que o teste irá ser reproduzido à risca. Nesta linha apenas P2 é livre.

Subimos o nível de debug (P2) de 1 para 3, já que o nível 2 apenas reporta de minuto a minuto.
Tal como o modo teste, na execução via linha de comando, o algoritmo executa sempre com debug nível 0,
de modo a obter os melhores tempos. O parametro de debug é apenas para visualizar o andamento do teste.


```entrada
/TProcura/Teste$ ./bin/Release/TProcura 1:10 -R Resultados/tvetor_1 -P P1=2 P2=3 P3=1


═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=3 P3=1 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:10   📄 Instâncias: 10   🛠️ Configurações: 1   🖥️ Processos: 1.
 ├─ 🗎  Ficheiro Resultados/tvetor_1.csv gravado.
 │  ⏱  Tempo real: 5" 149ms
 │  ⏱  CPU total: 5" 149ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  5" 156ms ) ═══
```

No arranque, como habitualmente, são mostradas as instâncias e configurações,
de modo a que possa ser detectado um erro, e abortado o teste se necessário.

O teste arranca normalmente, e pára aos 5 segundos dado que o teste é no modo base.
Vamos fazer também a versão com esforço B, para podermos ficar com a situação que tinhamos no modo interativo.

```entrada
/TProcura/Teste$ ./bin/Release/TProcura 1:10 -R Resultados/tvetor_1B -P P1=2 P2=3 P3=1:10


═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=3 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P3=1
 ├─ ⚙️ [2] ─ P3=2
 ├─ ⚙️ [3] ─ P3=3
 ├─ ⚙️ [4] ─ P3=4
 ├─ ⚙️ [5] ─ P3=5
 ├─ ⚙️ [6] ─ P3=6
 ├─ ⚙️ [7] ─ P3=7
 ├─ ⚙️ [8] ─ P3=8
 ├─ ⚙️ [9] ─ P3=9
 ├─ ⚙️ [10] ─ P3=10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:100   📄 Instâncias: 10   🛠️ Configurações: 10   🖥️ Processos: 1.
 ├─ ⏱ 10" 364ms       📋 25    📄 5     🛠️ 3     🖥️ 1
 ├─ ⏱ 20" 411ms       📋 46    📄 6     🛠️ 5     🖥️ 1
 ├─ ⏱ 30" 764ms       📋 66    📄 6     🛠️ 7     🖥️ 1
 ├─ ⏱ 40" 881ms       📋 88    📄 8     🛠️ 9     🖥️ 1
 ├─ 🗎  Ficheiro Resultados/tvetor_1B.csv gravado.
 │  ⏱  Tempo real: 47" 572ms
 │  ⏱  CPU total: 47" 572ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  47" 579ms ) ═══
```
 
O tempo total sido de 47 segundos.
Com debug a 0 não iriamos ter nenhum input senão após o teste terminar.
Podemos ver com nível 3 um report a cada 10 segundos, com o número da tarefa atual,
o número da instância atual, configuração atual e número de processos.
Assim podemos ir vendo o andamento dos testes.

No final temos a mesmoa informação final que nos testes em modo interativo.
São em tudo iguais, a diferença aqui é termos utilizado o debug nível 3.

É preciso referenciar o hardware utilizado. Ao não ser num cluster em que o hardware é preparado
para execuções, torna-se complicada a reprodução fiel, principalmente se o tempo é
um indicador em estudo, como é este caso. Outras aplicações podem estar a executar e velocidade do CPU
variável, podem enviesar os resultados, o que foi o caso estas execuções.

- **hardwoare**: 11th Gen Intel(R) Core(TM) i7-1185G7 @ 3.00GHz, RAM 16.0 GB (4267 MT/s)


#### Análise e Conclusões

Os dois ficheiros produzidos, Resultados/tvetor_1.csv e Resultados/tvetor_1B.csv, podem ser importados e
analisados com qualquer software adequado, de modo a obter-se gráficos e tabelas que permitam observar
o que se pretende, e permitam realizar testes estatísticos.

Vamos utilizar o MS Excel, fazendo uso de importação de ficheiros para modelo de dados,
criação de gráficos e relatórios dinâmicos, e criação de medidas DAX.

- **Ficheiro de Análise**: tvetor.xlsx

Criamos um só ficheiro de análise, independente do número de testes.
Por esse motivo tem o nome único com o nome do problema.

- **Importação CSV**: importar todos os ficheiros CSV criados para modelo de dados.
	- Dados > Obter Dados > De Ficheiro > De Texto/CSV > tvetor_1.csv

![Janela de importação](docs/images/excel1.png)

Os dados devem estar corretos, caso o separador ou codificação não seja corretamente identificada, corrigir.
Vamos no entanto carregar para modelo de dados, e não direto para o Excel.
A vantagem deste passo torna-se evidênte em ficheiros grandes, reduzindo consideravelmente o tamanho do ficheiro de Excel,
e não existindo limite de 1 milhão de linhas.

Para colocar os dados no modelo de dados, temos de selecionar a opção "Carregar Para..."
![Carregar Para...](docs/images/excel2.png)

Na janela optamos por ligação apenas e adicionar ao modelo de dados:
![Importar dados](docs/images/excel3.png)

Este processo tem de ser repetido para os restantes ficheiros a processar, neste caso tvetor_1B.csv

Após o carregamento vemos as consultas e ligações com os ficheiros carregados, com 10 e 100 linhas:
![Consultas e Ligações](docs/images/excel4.png)

Caso não apareça ou tenha sido fechada, esta caixa pode ser ligada em
- Dados > Consultas e Ligações

O menu de contexto numa dessas ligações permite editar e alterar o que for necessário na consulta,
ou voltar a carregar o ficheiro caso tenha sido refrescado.

O friso "Power Pivot" é também importante, para estabelecer a ligação entre as duas consultas:
![Friso Power Pivot](docs/images/excel5.png)

Neste menu vamos para já para Gerir
![Gerir Power Pivot](docs/images/excel6.png)

Nesta janela podemos ver as consultas em baixo, com as colunas no modelo de dados.
Iremos voltar aqui para adicionar variáveis calculadas, se necessário.
Para já vamos para:
- Estrutura > Relações > Criar Relação

Podemos fazer uma relação entre as duas consultas, com base na instância:
![Criar Relação](docs/images/excel7.png)

Esta relação permite que se utilize dados de ambas as consultas, num mesmo relatório dinâmico.
Apenas podemos fazer esta operação porque uma das consultas tem uma linha por cada instância.

Estamos prontos para criar uma tabela dinâmica:
- Inserir > Tabela Dinâmica > A partir de modelo de dados

Ficamos com uma tabela dinâmica, em que podemos utilizar todos os campos das consultas que estão no modelo de dados:
![Campos da Tabela Dinâmica](docs/images/excel8.png)

Vamos obter o gráfico em bruto da performance:
- **Linhas**: Instância (usar a coluna de tvetor_1)
- **Valores**: I2 de ambas as consultas

Obtemos a primeira tabela de resultados:
![Instância vs soma Tempo](docs/images/excel9.png)

Naturalmente que uma das colunas tem 10 execuções a outra 1.
Podemos observar:
- há um efeito não linear, atendendo a que a instância 1 leva 65 ou 67,6 millisegundos a executar, enquanto a instância 10 com 10 vezes o tamanho, leva mais que 10 vezes o tempo
- os resultados de ambas as execuções não batem muito certo. Assim, o que é certo é que os valores obtidos são incertos.

Na execução com 10 corridas, podemos procurar obter a média e intervalo de confiança, com medidas DAX.
Para tal, é preciso adicionar medidas DAX na tabela tvetor_1B. 

Vamos começar pela média do tempo. Pode-se adicionar novas medidas adicionando nos Campos da Tabela Dinâmica,
no menu de contexto da consulta, ou no Power Pivot > Medidas > Nova Medida

![Nova Medida](docs/images/excel10.png)

- MédiaTempo = AVERAGE([I2(Tempo(ms))])
- N = COUNTROWS(tvetor_1B)
- DesvioPadrao = STDEV.S([I2(Tempo(ms))])
- ErroPadrao = [DesvioPadrao] / SQRT([N])
- IC_Inf = [MédiaTempo] - 1.96 * [ErroPadrao]
- IC_Sup = [MédiaTempo] + 1.96 * [ErroPadrao]

Nota: o valor de N deveria ser 30 ou superior, para ser utilizado o valor 1.96 para 95% de confiança.

Assim podemos obter uma informação mais precisa, dos dados que temos:

![Instância vs Tempo](docs/images/excel11.png)

Vemos que o intervalo de confiança de até 50 millisegundos, pelo que há relativa certeza nas décimas de segundo.
O intervalo de confiança foi por vezes violado considerando a execução base, o que é normal utilizando 95% de confiança,
em que 1 em cada 20 casos irá estar fora do intervalo. Por outro lado N é inferior a 30, e também
o facto de se utilizar um computador local, duas corridas em alturas distintas podem estar sujeitas
a processos em paralelo distintos, e ter enviasamento do tempo.

Melhores resultados serão obtidos numa excecução num cluster, e com N superior.

As medidas DAX permitem o calculo da estatística pretendida, embora dê algum trabalho a criar as variáveis,
fica automaticamente recalculada para os filtros que pretendermos. 

Podemos confirmar que há um efeito não linear no tempo.
Mesmo considerando os intervalos máximo para a instância 1, 71,1 millisegundos, 10 vezes este tempo
fica fora do intervalo de tempo da instância 10, que tem no mínimo 755 millisegundos.

Vamos avançar para o próximo teste.

### Teste: tvetor_2

Pretendemos agora, considerando todas as operações em teste, procurar saber se há diferença
entre alguma das estruturas de dados em termos de tempo. Estamos portanto perante um teste paramétrico.

- **Tipo de Teste / Objetivo**: Paramétrico (P6(ESTRUTURA_DADOS) vs P1(ALGORITMO) - irrelevante?)
- **Definição**: Instâncias: 1; Configurações: P1=1:12 x P6=1:3 x P3=1:10
- **Esforço**: 1; 1:4; 1:10
- **Execução**: TProcura 1 -R Resultados/tvetor_2 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10

Neste caso o esforço incide sobre as instâncias, com a versão A apenas com a instância 1.
Coloca-se no entanto 10 sementes aleatórias.


```entrada
/TProcura/Teste$ ./bin/Release/TProcura 1 -R Resultados/tvetor_2 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10


═╤═ Instâncias ═══ { 📄1 }
 ├─ 🛠️ ─ P2=3 P4=10 P5=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P1=1 P3=1 P6=1
 ├─ ⚙️ [2] ─ P1=2 P3=1 P6=1
 ├─ ⚙️ [3] ─ P1=3 P3=1 P6=1
 │ ...
 ├─ ⚙️ [358] ─ P1=10 P3=10 P6=3
 ├─ ⚙️ [359] ─ P1=11 P3=10 P6=3
 ├─ ⚙️ [360] ─ P1=12 P3=10 P6=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:360   📄 Instâncias: 1   🛠️ Configurações: 360   🖥️ Processos: 1.
 ├─ ⏱ 10" 41ms        📋 140   📄 1     🛠️ 140   🖥️ 1
 ├─ ⏱ 20" 53ms        📋 278   📄 1     🛠️ 278   🖥️ 1
 ├─ 🗎  Ficheiro Resultados/tvetor_2.csv gravado.
 │  ⏱  Tempo real: 25" 853ms
 │  ⏱  CPU total: 25" 853ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  25" 862ms ) ═══
```

Podemos ver que solicitá-mos muitas configurações. Se fosse engano, poderiamos ter abortado o teste.

Vamos ficar com apenas o esforço base, atendendo a que foi já 25 segundos.

#### Análise e Conclusões

Importamos de igual forma este ficheiro, mas não ligamos com as outras duas consultas dado que
não temos aqui todas as instâncias, nem uma relação entre ambos os testes que se pretenda explorar.

Ficamos com nova consulta, tvetor_2, com 360 linhas carregadas.

Podemos fazer desde logo o relatório dinâmico a partir do modelo de dados, colocando:
- **linhas**: P1(ALGORITMO)
- **colunas**: P6(ESTRUTURA_DADOS)
- **valores**: Soma I2(Tempo(ms))

Obtemos a seguinte tabela da Soma de I2(tempo(ms)):
| Rótulos de Linha | 1:TVector | 2:std::vector | 3:TVector/std::algorithm | Total Geral |
|:---:|---:|---:|---:|---:|
| 1:Add() | 63 | 38 | 71 | 172 |
| 10:operator=() | 7 | 0 | 8 | 15 |
| 11:operator+=() | 8 | 23 | 9 | 40 |
| 12:nada | 0 | 0 | 0 | 0 |
| 2:Sort() | 661 | 616 | 623 | 1900 |
| 3:RandomOrder() | 63 | 32 | 33 | 128 |
| 4:Invert() | 3 | 0 | 0 | 3 |
| 5:BeASet() | 664 | 672 | 667 | 2003 |
| 6:Difference() | 1467 | 1392 | 1479 | 4338 |
| 7:Union() | 2497 | 1413 | 2273 | 6183 |
| 8:Contained() | 1378 | 1252 | 1362 | 3992 |
| 9:Intersection() | 1454 | 1347 | 1476 | 4277 |
| Total Geral | 8265 | 6785 | 8001 | 23051 |

Podemos ver que os valores obtidos pelas estruturas são da mesma ordem de grandeza, mas o std::vetor
aparenta ser mais rápido em algumas operações, nomeadamente na operação Union(), ficando com ligeira vantagem em outras.

Para obter uma resposta com base estatística, vamos calcular os intervalos, como fizemos no teste 1.
As medidas são exatamente as mesmas, mas aplicadas a consulta tvetor_2:
- MédiaTempo2 = AVERAGE([I2(Tempo(ms))])
- N2 = COUNTROWS(tvetor_2)
- DesvioPadrao2 = STDEV.S([I2(Tempo(ms))])
- ErroPadrao2 = [DesvioPadrao2] / SQRT([N2])
- IC_Inf2 = [MédiaTempo2] - 1.96 * [ErroPadrao2]
- IC_Sup2 = [MédiaTempo2] + 1.96 * [ErroPadrao2]

Colocamos agora os limites nos valores
- **linhas**: P1(ALGORITMO)
- **colunas**: P6(ESTRUTURA_DADOS)
- **valores**: IC_Inf2, IC_Sup2


| Rótulos de Linha | 1:TVector<br>IC_Inf2 | IC_Sup2 | 2:std::vector<br>IC_Inf2 | IC_Sup2 | 3:TVector/std::algorithm<br>IC_Inf2 | IC_Sup2 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1:Add() | 5 | 7 | 3 | 5 | 5 | 9 |
| 10:operator=() | 0 | 1 | 0 | 0 | 1 | 1 |
| 11:operator+=() | 1 | 1 | 1 | 3 | 1 | 1 |
| 12:nada | 0 | 0 | 0 | 0 | 0 | 0 |
| 2:Sort() | 63 | 69 | 58 | 65 | 60 | 65 |
| 3:RandomOrder() | 5 | 8 | 3 | 4 | 3 | 4 |
| 4:Invert() | 0 | 1 | 0 | 0 | 0 | 0 |
| 5:BeASet() | 64 | 69 | 59 | 76 | 57 | 77 |
| 6:Difference() | 138 | 155 | 127 | 151 | 127 | 169 |
| 7:Union() | 227 | 272 | 128 | 154 | 214 | 240 |
| 8:Contained() | 126 | 150 | 113 | 137 | 123 | 150 |
| 9:Intersection() | 137 | 154 | 128 | 142 | 127 | 169 |

Podemos ver que a operação 7 de união, os intervalos de confiança não se intersectam, pelo que
a diferença é real entre amboas as operações. Nos restantes casos os intervalos de confiança
intersectam-se, pelo que este teste não permite saber se as médias são distintas.

A utilização de intervalos de confiança para saber se dois valores são distintos, é um teste conservador,
significando que pode haver casos em que os intervalos se intersectem, e exista forma com os mesmos dados e um teste
estatístico mais fino, de concluir a diferença.


---

\anchor tvector-a8
## Ação 8: Execução MPI

Vamos agora executar em MPI para tirar partido de vários processadores em paralelo.

Antes desta secção, sertifique-se que tem o MPI operacional, seguindo as instruções na secção Compilação e Execução do README.md.

Não esquecer de utilizar o binário MPI.

Usamos como referência o teste tvetor_1B com 47 segundos.

Chamamos agora à atenção para o parametro -M para especificar o modo:

```
 -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador
```

Na divisão estática, o modo de omissão, as tarefas são previamente divididas pelos processadores.
Este modo é excelente se todas as tarefas tiverem duração idêntica.

No modo gestor-trabalhador, a divisão das tarefas é gerida por um dos processos, o processo gestor, que distribui trabalho.
Assim, não há o risco de um processo já ter terminado, e outro ter ainda muitas tarefas para executar, tirando-se
melhor partido do CPU disponível caso as tarefas tenham tempo de realização distinto.

Vamos fazer dois testes, um com cada modo, e com 4 processadores. 

Linha de comando: mpiexec -n 4 TProcura 1:10 -R Resultados/tvetor_1Bm0 -P P1=2 P2=3 P3=1:10

```
TProcura/Teste$ mpiexec -n 4 ./bin/MPI/TProcura 1:10 -R Resultados/tvetor_1Bm0 -P P1=2 P2=3 P3=1:10


═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=3 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P3=1
 ├─ ⚙️ [2] ─ P3=2
 ├─ ⚙️ [3] ─ P3=3

═╤═ 🧪  Início do Teste (🖥️ 2) ═══
═╤═ 🧪  Início do Teste (🖥️ 3) ═══ ├─ ⚙️ [4] ─ P3=4
 ├─ ⚙️ [5] ─ P3=5
 ├─ ⚙️ [6] ─ P3=6

═╤═ 🧪  Início do Teste (🖥️ 1) ═══ ├─ ⚙️ [7] ─ P3=7
 ├─ ⚙️ [8] ─ P3=8
 ├─ ⚙️ [9] ─ P3=9
 ├─ ⚙️ [10] ─ P3=10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:100   📄 Instâncias: 10   🛠️ Configurações: 10   🖥️ Processos: 4.
 ├─ ⏱ 10" 374ms       📋 93    📄 3     🛠️ 10    🖥️ 4
═╧═ 🏁  Fim do Teste (🖥️ 2  ⏱  11" 173ms ) ═══
═╧═ 🏁  Fim do Teste (🖥️ 3  ⏱  13" 542ms ) ═══
═╧═ 🏁  Fim do Teste (🖥️ 1  ⏱  13" 542ms ) ═══
 ├─ 🗎  Ficheiro Resultados/tvetor_1Bm0.csv gravado.
 │  ⏱  Tempo real: 13" 534ms
 │  ⏱  CPU total: 54" 137ms
 │  📊  Utilização: 91.4%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  13" 541ms ) ═══
```

O arranque dos processos veio misturado com a lista de configurações em teste, que o processo 0 estava a mostrar.
O tempo de execução real foi de 13 segundos, mas o tempo total de execução foi de 54 segundos, e a utilização de 90%.
Significa que houve processadores parados, já sem nada para fazer, enquanto que outros ainda tinham tarefas,
mas não de forma muito evidente.

Podemos observar que o processo 2 terminou pouco depois dos 10 segundos.
O processo 0 é sempre o último a terminar, já que tem de no final juntar os ficheiros de resultados.
Isso não significa que não tenha ficado parado à espera dos outros.

Vamos agora ver o gestor-trabalhador, em que o trabalho ém falta é gerido centralmente.

Linha de comando: mpiexec -n 4 TProcura 1:10 -R Resultados/tvetor_1Bm1 -M 1 -P P1=2 P2=3 P3=1:10

```
/TProcura/Teste$ mpiexec -n 4 ./bin/MPI/TProcura 1:10 -R Resultados/tvetor_1Bm1
-M 1 -P P1=2 P2=3 P3=1:10

═╤═ 🧪  Início do Teste (🖥️ 2) ═══
═╤═ 🧪  Início do Teste (🖥️ 3) ═══

═╤═ Instâncias ═══ { 📄1 📄2 📄3 📄4 📄5 📄6 📄7 📄8 📄9 📄10 }
 ├─ 🛠️ ─ P1=2 P2=3 P4=10 P5=0 P6=1 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P3=1
 ├─ ⚙️ [2] ─ P3=2
 ├─ ⚙️ [3] ─ P3=3
 ├─ ⚙️ [4] ─ P3=4
 ├─ ⚙️ [5] ─ P3=5
 ├─ ⚙️ [6] ─ P3=6
 ├─ ⚙️ [7] ─ P3=7
 ├─ ⚙️ [8] ─ P3=8
 ├─ ⚙️ [9] ─ P3=9
 ├─ ⚙️ [10] ─ P3=10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
═╤═ 🧪  Início do Teste (🖥️ 1) ═══
 ├─ 📋 Tarefas:100   📄 Instâncias: 10   🛠️ Configurações: 10   🖥️ Processos: 4.
 ├─ ⏱ 10" 646ms       📋 63    📄 8     🛠️ 3     🖥️ 3     ⚖  1 657 1 1
═╧═ 🏁  Fim do Teste (🖥️ 2  ⏱  16" 420ms ) ═══
═╧═ 🏁  Fim do Teste (🖥️ 3  ⏱  16" 462ms ) ═══
═╧═ 🏁  Fim do Teste (🖥️ 1  ⏱  16" 496ms ) ═══
 ├─ 🗎  Ficheiro Resultados/tvetor_1Bm1.csv gravado.
 │  ⏱  Tempo real: 16" 497ms
 │  ⏱  CPU total: 49" 491ms
 │  ⏱  Espera do gestor: 16" 495ms
 │  ⏱  Espera trabalhadores: 111ms
 │  📊  Utilização:
 │  - Total: 74.8%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  16" 497ms ) ═══
```

Obteve-se uma taxa de utilização de 75%, neste caso inferior aos 90% do método estático.
O tempo real foi de 16 segundos, com tempo total de 49 segundos.
É um valor idêntico à distribuição de trabalho estática,
mesmo considerando que apenas 3 dos 4 processos processaram tarefas.

Em relação aos 47 segundos iniciais, reduziu-se para 1/3, tudo o resto permaneceu sem alterações.
Quanto maior os testes e maior o número de processadores, maior será o ganho da execução MPI.

No entanto para isso precisamos de ter acesso a um cluster.
Torna-se impraticável testes de volume utilizando computador próprio.

A submissão de trabalhos num cluster, será alvo de um caso de estudo, para exemplificação.



| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

