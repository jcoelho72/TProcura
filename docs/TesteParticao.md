@page teste_particao Teste Particao

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base no problema da Partição.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraConstrutiva, e execute.
No Linux na pasta `.../TProcura/Construtiva/Teste$` execute `make` seguido de `./bin/Release/TProcuraConstrutiva`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#particao-a1)
- [Ação 2 - Resolver manualmente](#particao-a2)
- [Ação 6 - Testes Empíricos](#particao-a3)


```entrada
┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 4
```

![Partição - separe os números em duas partes iguais](docs/images/particao.png)

Vamos escolher o problema da partição. Introduza: **4.**

```entrada
Partição
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 │  ├─ 📦92 → ◀️0 = ▶️0 ─
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```
Este problema consiste em dividir os números em duas partes que somem exatamente o mesmo valor.
Está no modo compato, vamos colocar no modo extendido para ver o conteúdo da instância.
Introduza: **3; 2; 4; *ENTER*.**

```entrada
Partição
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 │  ┌─ 📦92 → ◀️0 = ▶️0 ────────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2 9 9 13 16 17 24
 │  ├─ ◀️ ─
 │  ├─ ▶️ ─
 │  └──────────────────────────────────────────────────────────────────────
...
Opção:
```
Podemos agora ver os números a colocar. Somam no total 92, e tem que se colocar cada número numa das linhas.
A soma em cada linha tem de ser igual.


\anchor particao-a1
## Ação 1 - Ver instâncias

Vamos ver as instâncias que temos. Introduza: **1; 10.**

```entrada
Opção: 1

┌─ ↻  Inicializar ─────────────────────────────────────────────────────
│ ID atual: 10  Intervalo: [2–1000]
│ Prefixo atual: 'instancia_'
└──────────────────────────────────────────────────────────────────────
Novo ID (ENTER mantém) ou novo prefixo (texto): 10
```
Existem instâncias de 2 a 1000, correspondendo o ID à quantidade de números. 
As instâncias são geradas aleatoriamente, podendo existir instâncias impossíveis.

Deixemos a instância 10 para resolução manual.

\anchor particao-a2
## Ação 2 - Resolver manualmente

Vamos procurar resolver manualmente a intância. Introduza: **2; esq dir esq dir; dir; esq.**

```entrada
Opção: 2

═╤═ 💰 g:0 🔢 1|2|3 ═══
 │  ┌─ 📦92 → ◀️0 = ▶️0 ────────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2 9 9 13 16 17 24
 │  ├─ ◀️ ─
 │  ├─ ▶️ ─
 │  └──────────────────────────────────────────────────────────────────────
 │ └─ ⚡ ───── esq dir { 🔖1 🔖2 }
🔍  Sucessor [1-2, ação(ões), exe]: esq dir esq dir

┌─ ✅  Sucesso ────────
│ Executadas 4 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 6|12|6 ═══
 │  ┌─ 📦22 → ◀️40 = ▶️30 ──────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2 9 9
 │  ├─ ◀️ ─ 24 16
 │  ├─ ▶️ ─ 17 13
 │  └──────────────────────────────────────────────────────────────────────
 │ └─ ⚡ ───── esq dir { 🔖11 🔖12 }
🔍  Sucessor [1-2, ação(ões), exe]: dir

┌─ ✅  Sucesso ────────
│ Executadas 1 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 8|16|9 ═══
 │  ┌─ 📦13 → ◀️40 = ▶️39 ──────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2 9
 │  ├─ ◀️ ─ 24 16
 │  ├─ ▶️ ─ 17 13 9
 │  └──────────────────────────────────────────────────────────────────────
 │ └─ ⚡ ───── esq dir { 🔖15 🔖16 }
🔍  Sucessor [1-2, ação(ões), exe]: esq

┌─ ✅  Sucesso ────────
│ Executadas 1 ações.
└─────────────────────
═╤═ 💰 g:0 🔢 10|18|10 ═══
 │  ┌─ 📦4 → ◀️49 = ▶️39 ───────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2
 │  ├─ ◀️ ─ 24 16 9
 │  ├─ ▶️ ─ 17 13 9
 │  └──────────────────────────────────────────────────────────────────────
 │ └─ ⚡ ─────
┌─ ℹ️  Informação ───
│ Sem sucessores.
└────────────────────
Partição
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): COMPLETO | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 0 | P6(VER_ACOES): 4 | P7(LIMITE): 0
│ P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 │  ┌─ 📦4 → ◀️49 = ▶️39 ───────────────────────────────────────────────────
 │  ├─ 📦 ─ 2 2
 │  ├─ ◀️ ─ 24 16 9
 │  ├─ ▶️ ─ 17 13 9
 │  └──────────────────────────────────────────────────────────────────────
...
Opção:
```
Foi uma boa tentativa, mas no final um lado soma 49 do outro 39,
e os números que restam não chegam para equilibrar.

Tal como as 8 damas, o número de ações de uma solução completa é fixo.
É igual à quantidade de número a colocar.
Sabemos que não faz sentido a procura em largura nestes problemas.
Também pelos mesmos motivos que nas 8 damas, não se consegue uma heurística pelo que não faz sentido 
as procuras informadas.

Naturalmente que se poderia efetuar mais cortes dos que estão a ser feitos nesta implementação.
Vamos apenas comparar a remoção de repetidos gerados, relativamente a ignorar repetidos.

No caso da partição, após um número estar num lado, apenas a soma interessa. 
Como se coloca os números por ordem, um estado fica igual a todos os que têm o montante igual das peças colocadas.
Esquerda e direita é naturalmente irrelevante. 

Como o estado codificado fica pequeno, a expectativa para ganho por repetidos aumenta.

\anchor particao-a3
## Ação 3 - Testes Empíricos

Vamos fazer testes empíricos na linha de comandos. 

Vamos obter primeiramente a lista de todos os parâmetros.

```entrada
/TProcura/Construtiva/Teste$ ./bin/Release/TProcuraConstrutiva -h

┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 4
Uso: ./bin/Release/TProcuraConstrutiva <instâncias> [opções]
  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]
Opções:
  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)
  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)
  -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador
  -I <ind>        Lista de indicadores (e.g. 2,1,3)
  -h              Esta ajuda
  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - último campo
Exemplo: ./bin/Release/TProcuraConstrutiva 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2
   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores

Lista de parâmetros:
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO):             Largura Primeiro ( 1 a  7)
│ P2(NIVEL_DEBUG):           NADA       ( 0 a  4)
│ P3(SEMENTE):               1          ( 1 a  1000000)
│ P4(LIMITE_TEMPO):          10         ( 1 a  3600)
│ P5(LIMITE_ITERACOES):      0          ( 0 a  1000000000)
│ P6(VER_ACOES):             4          ( 1 a  100)
│ P7(LIMITE):                0          (-1 a  1000000)
│ P8(ESTADOS_REPETIDOS):     ignorar    ( 1 a  3)
│ P11(BARALHAR_SUCESSORES):  0          ( 0 a  1)
└──────────────────────────────────────────────────────────────────────

Lista de indicadores:
┌─ ⚖  Indicadores ─────────────────────────────────────────────────────
│ I1(IND_CUSTO): ✔  1º lugar
│ o resultado é o custo da solução atual
│ I2(Tempo(ms)): ✔  2º lugar
│ Tempo em milisegundos da execução (medida de esforço computacional).
│ I3(Iterações): ✔  3º lugar
│ Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).
│ I4(IND_EXPANSOES): ✔  4º lugar
│ número de expansões efetuadas
│ I5(IND_GERACOES): ✔  5º lugar
│ número de estados gerados
│ I6(IND_LOWER_BOUND): ✔  6º lugar
│ valor mínimo para a melhor solução, se igual ao custo da solução obtida, então esta é ótima
└──────────────────────────────────────────────────────────────────────
```


Temos para teste a procura em profundidade ilimitada, e pretendemos comparar ignorar estados repetidos,
ou remover todos os repetidos gerados.

```entrada
PS ...\Teste> TProcuraConstrutiva 10:19 -R Resultados/Particaot1 -P P2=3 P7=-1 P1=3 P8=1,3
...
Opção: 4

 ├─ 🛠️  ─ P1=3 P2=3 P3=1 P4=10 P5=0 P6=4 P7=-1 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P8=1
 ├─ ⚙️ [2] ─ P8=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:20   ↻ Instâncias: 10   🛠️ Configurações: 2   🖥️ Processos: 1.
 ├─ 📄  Ficheiro Resultados/Particaot1.csv gravado.
 │  ⏱  Tempo real: 20ms
 │  ⏱  CPU total: 20ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  20ms ) ═══
```

Podemos ver o resultado:

| Rótulos de Linha | Soma de I1(Custo)<br>1:ignorar | 3:gerados | Soma de I2(Tempo(ms))<br>1:ignorar | 3:gerados | Soma de I4(Expansões)<br>1:ignorar | 3:gerados |
|:---:|---:|---:|---:|---:|---:|---:|
| 10 | 8 | 8 | 0 | 6 | 27 | 27 |
| 11 | 10 | 10 | 0 | 1 | 17 | 17 |
| 12 | 12 | 12 | 0 | 1 | 20 | 20 |
| 13 | 12 | 12 | 0 | 1 | 20 | 20 |
| 14 | 14 | 14 | 0 | 1 | 24 | 24 |
| 15 | 15 | 15 | 0 | 1 | 25 | 25 |
| 16 | 16 | 16 | 0 | 1 | 26 | 26 |
| 17 | 17 | 17 | 0 | 1 | 106 | 103 |
| 18 | 18 | 18 | 0 | 1 | 77 | 77 |
| 19 | 19 | 19 | 0 | 1 | 32 | 32 |
| Total Geral | 141 | 141 | 0 | 15 | 374 | 371 |


As instâncias escolhidas são muito pequenas, e o tempo de execução é praticamente nulo.
Não servem para medir diferenças de tempo.
Apenas há diferença nas expansões na instância 17, devido a remoção de repetidos.


Vamos procurar instâncias maiores, como não sabemos a dimensão, vamos escolher algumas de dimensões distintas.

```entrada
PS ...\Teste> TProcuraConstrutiva 20:28:2,30:95:5,100:1000:100 -R Resultados/Particaot2 -P P2=3 P7=-1 P1=3 P8=1,3
...
Opção: 4

 ├─ 🛠️  ─ P1=3 P2=3 P3=1 P4=10 P5=0 P6=4 P7=-1 P11=0 (parâmetros comuns)
═╪═ Configurações ═══
 ├─ ⚙️ [1] ─ P8=1
 ├─ ⚙️ [2] ─ P8=3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:58   ↻ Instâncias: 29   🛠️ Configurações: 2   🖥️ Processos: 1.
 ├─ 📄  Ficheiro Resultados/Particaot2.csv gravado.
 │  ⏱  Tempo real: 157ms
 │  ⏱  CPU total: 157ms
 │  📊  Utilização: 100.0%
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱  157ms ) ═══
```

A execução terminou de imediato.

| Rótulos de Linha | Soma de I1(Custo)<br>1:ignorar | 3:gerados | Soma de I2(Tempo(ms))<br>1:ignorar | 3:gerados | Soma de I4(Expansões)<br>1:ignorar | 3:gerados |
|:---:|---:|---:|---:|---:|---:|---:|
| 20 | 18 | 18 | 0 | 7 | 87 | 85 |
| 22 | 21 | 21 | 0 | 1 | 35 | 35 |
| 24 | 23 | 23 | 0 | 1 | 135 | 102 |
| 26 | 25 | 25 | 0 | 1 | 66 | 65 |
| 28 | 27 | 27 | 0 | 1 | 44 | 44 |
| 30 | 30 | 30 | 0 | 1 | 50 | 50 |
| 35 | 35 | 35 | 0 | 1 | 58 | 58 |
| 40 | 40 | 40 | 0 | 1 | 67 | 67 |
| 45 | 45 | 45 | 0 | 1 | 76 | 76 |
| 50 | 50 | 50 | 0 | 1 | 83 | 83 |
| 55 | 54 | 54 | 0 | 1 | 119 | 118 |
| 60 | 60 | 60 | 0 | 2 | 142 | 142 |
| 65 | 65 | 65 | 0 | 1 | 111 | 111 |
| 70 | 70 | 70 | 0 | 1 | 119 | 119 |
| 75 | 74 | 74 | 0 | 1 | 123 | 123 |
| 80 | 79 | 79 | 0 | 2 | 132 | 132 |
| 85 | 85 | 85 | 0 | 2 | 166 | 166 |
| 90 | 88 | 88 | 0 | 2 | 332 | 240 |
| 95 | 95 | 95 | 0 | 3 | 559 | 470 |
| 100 | 99 | 99 | 0 | 2 | 168 | 168 |
| 200 | 198 | 198 | 1 | 3 | 339 | 339 |
| 300 | 299 | 299 | 1 | 4 | 511 | 511 |
| 400 | 398 | 398 | 2 | 5 | 681 | 681 |
| 500 | 500 | 500 | 4 | 7 | 1257 | 1257 |
| 600 | 599 | 599 | 6 | 11 | 1882 | 1881 |
| 700 | 700 | 700 | 5 | 10 | 1408 | 1407 |
| 800 | 800 | 800 | 6 | 11 | 1362 | 1362 |
| 900 | 899 | 899 | 8 | 12 | 1531 | 1531 |
| 1000 | 1000 | 1000 | 9 | 14 | 1700 | 1700 |
| Total Geral | 6476 | 6476 | 42 | 110 | 13343 | 13123 |


É agora claro que a remoção de repetidos gerados apenas consome mais tempo, sendo até raros os casos de instâncias com menos gerações.

Naturalmente que esta conclusão é válida apenas para as instâncias geradas,
que têm um método de geração que pode não garantir que temos instâncias complexas.
Mesmo as instâncias maiores são resolvidas em instantes.

As instâncias impossíveis são no geral mais difíceis, já que toda a árvgore tem de ser percorrida.



Qual é a maior instância que se conseguimos resolver com esta implemantação?
<details>
  <summary>Resposta:</summary>
Vamos usar apenas a remoção de repetidos. 
Como não sabemos qual é a maior instância que se consegue resolver,
e o melhor método tem um tempo insignificante na maior instância testada, a 29, 
fazemos primeiramente um teste de 10 em 10, até 200, para termos uma ideia.

```entrada
PS ...\Teste> TProcuraConstrutiva 30:200:10 -R resultadoParticaoC -P P7=-1 P1=3 P8=3
...
Opção: 4
...
Ficheiro resultadoParticaoC.csv gravado.
```

| Rótulos de Linha | Soma de I1(Custo) | Soma de I2(Tempo(ms)) | Soma de I4(Expansões) |
|:---:|---:|---:|---:|
| 30 | 30 | 15 | 50 |
| 40 | -1 | 10 | 7301 |
| 50 | 50 | 4 | 83 |
| 60 | 60 | 3 | 142 |
| 70 | 70 | 6 | 119 |
| 80 | 79 | 4 | 132 |
| 90 | -1 | 79 | 74065 |
| 100 | -1 | 132 | 130625 |
| 110 | 108 | 4 | 314 |
| 120 | -1 | 230 | 222208 |
| 130 | -1 | 291 | 269323 |
| 140 | 140 | 4 | 236 |
| 150 | 149 | 5 | 252 |
| 160 | -1 | 710 | 604753 |
| 170 | -1 | 814 | 655988 |
| 180 | 178 | 4 | 376 |
| 190 | 190 | 5 | 673 |
| 200 | 198 | 4 | 339 |
| Total Geral | 1245 | 2324 | 1966979 |

Todas as instâncias a baixo de 1 segundo, mas mesmo assim já perto do limite dos 10 segundos. 
A instância 100 levou 0.1 segundos, a 160 levou 0.7 segundos, pelo que o limite estará algures entre 200 e 300.
Assim, vamos testar a partir de 200, até 300, passos de 5.

| Rótulos de Linha | Soma de I1(Custo) | Soma de I2(Tempo(ms)) | Soma de I4(Expansões) |
|:---:|---:|---:|---:|
| 205 | -1 | 1638 | 1251882 |
| 210 | -1 | 1399 | 1107437 |
| 215 | -1 | 1824 | 1407324 |
| 220 | -1 | 1906 | 1516272 |
| 225 | 224 | 4 | 382 |
| 230 | 230 | 4 | 392 |
| 235 | 234 | 4 | 398 |
| 240 | 239 | 5 | 463 |
| 245 | 245 | 5 | 417 |
| 250 | 250 | 5 | 425 |
| 255 | 254 | 5 | 433 |
| 260 | 259 | 5 | 439 |
| 265 | 265 | 5 | 450 |
| 270 | 270 | 5 | 460 |
| 275 | -2 | 10001 | 6974880 |
| 280 | 280 | 5 | 1041 |
| 285 | -2 | 10001 | 7132853 |
| 290 | -2 | 10001 | 7017596 |
| 295 | -2 | 10001 | 6435970 |
| 300 | 299 | 5 | 511 |
| Total Geral | 3037 | 46828 | 32850025 |

A instância 275 não se consegue resolver em 10 segundos, mas a 220 sim.
As instâncias com solução, são mais simples, pelo que perturbam a análise. 
A instância impossível maior que se consegue resoolver, estará entre 220 e 275.

Naturalmente que com outra semente aleatória, iriamos ter instâncias diferentes, que podem ser mais complexas ou mais simples.

</details>

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
