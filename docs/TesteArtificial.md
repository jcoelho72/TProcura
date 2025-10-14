@page teste_artificial Teste Artificial

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


Execução de exemplo com base no problema artificial.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraConstrutiva, e execute.
No Linux na pasta `.../TProcura/Construtiva/Teste$` execute `make` seguido de `./bin/Release/TProcuraConstrutiva`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

Ficheiro não atualizado! (procurar atualizar este código para ter heurísticas)

## Sumário

- [Ação 1 - Ver instâncias](#artificia-a1)
- [Ação 2 - Resolver manualmente](#artificia-a2)
- [Ação 3 - Testes Empíricos](#artificia-a3)


```entrada
┌─ Teste TProcuraConstrutiva ──┐
│ 1 - Aspirador                │
│ 2 - Puzzle 8                 │
│ 3 - 8 Damas                  │
│ 4 - Partição                 │
│ 5 - Artificial               │
└──────────────────────────────┘
Opção: 5
```

Temos ainda a opção do problema artificial. Introduza: **5.**

```entrada
Artificial
┌─ ⚙️  Parâmetros ─────────────────────────────────────────────────────
│ P1(ALGORITMO): Largura Primeiro | P2(NIVEL_DEBUG): NADA | P3(SEMENTE): 1
│ P4(LIMITE_TEMPO): 10 | P5(LIMITE_ITERACOES): 1000000 | P6(VER_ACOES): 1
│ P7(LIMITE): 0 | P8(ESTADOS_REPETIDOS): ignorar | P11(BARALHAR_SUCESSORES): 0
└──────────────────────────────────────────────────────────────────────
 │  01-00-00-00
┌─ ☰  Menu ────────┬────────────────┬─────────────────────┬──────────────┐
│ 1 ↻  Inicializar │ 2 🔍  Explorar │ 3 ⚙️  Parâmetros    │ 4 ✔  Solução │
│ 5 ⚖  Indicadores │ 6 ►  Executar  │ 7 🛠️  Configurações │ 8 🧪  Teste  │
└──────────────────┴────────────────┴─────────────────────┴──────────────┘
Opção:
```

Estas instâncias artificiais não têm um problema concreto. 
Cada estado é abstrato e é representado por um inteiro. 
O primeiro estado é o estado 1. 
No entanto, cada instância tem diferentes características:
- Ramificação - existe valor mínimo e máximo, pelo que pode-se controlar se é elevada ou baixa, fixa ou variável.
- Nível do objetivo - pode-se definir o nível mínimo em que o objetivo pode estar, e assim indicar que é 8. Nesse caso apenas estados no nível 8 ou superior, é que podem ser objetivo.
- Nível máximo - a profundidade máxima em que há estados. Após este nível os sucessores ficam vazios.
- Objetivo - permite controlar a raridade do objetivo. Define-se um número K, se ID é objetivo então tem de ser multiplo de K. No caso de K=10, significa que todos os estados que tiverem ID a terminar com 0, são objetivo.
- Custo máximo - permite controlar custos das ações, fixos ou variáveis
- Repetição de estados - define-se um número K, ficando todos os IDs resto da divisão por K iguais. Assim, controla-se a probabilidade de um estado ser repetido, K menor há mais repetidos.
- Repetição de estados mas por nível - idêntico ao anterior, mas os estados apenas são repetidos de entre os que estão no mesmo nível.

Estas caracteristicas definem o espaço de estados, e permite avaliar os algoritmos de forma independente
dos problemas, ou testar o algoritmo em situações extermas, mesmo antes de ter um problema concreto que tenha essas características.

\anchor artificia-a1
## Ação 1 - Ver instâncias

Introduza: **1; 1.**

```entrada
ID atual: 1  Intervalo: [1-10]  Prefixo atual: 'instancia_'
Novo ID (ENTER mantém) ou novo prefixo (texto): 1
```

As instâncias têm características definidas na função CProblemaArtificial::CarregaInstancia().
Procurou-se ter instâncias de diferentes tipos.

|ID|Ramificação mínima|máxima|Nível Objetivo mínimo|máximo|objetivo|Custo máximo|Estados máximo|Estados nível máximo|Semente|Comentário|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|2|2|4|5|10|1|0|0|1| pequena instância, ramificação baixa, profundidade baixa, objetivo 1 em 10 (termina em 0)|
|4|4|1|6|10|1|100|0|2| ramificação média, estados máximos 100 (repetem-se, resto da divisão por 100). minNivelObjetivo tem de ser 1 sempre que maxEstados>0|
|6|6|5|7|10|1|0|100|3| estados máximos em cada nível 100 (repetem-se, resto da divisão por 100, mas sem colisões entre níveis)|
|1|4|4|7|10|10|0|0|4| custos não unitários (até 10), ramificação variável baixa|
|1|4|20|20|100|2|0|0|5| profundidade média, solução no último nível apenas, custos variáveis mas menos, objetivo 1 em 100 (termina em 00)|
|1|4|1|20|100|2|10000|0|6| máximo número de estados 10K (minNivelObjetivo tem de ser 1 sempre que maxEstados>0)|
|1|4|20|20|100|2|0|1000|7| máximo número de estados num nível 1K|
|10|20|10|20|100|1|0|0|8| ramificação média, profundidade média, solução variável, custo fixo|
|10|20|1|20|100|1|10000|0|9| máximo número de estados 10K (minNivelObjetivo tem de ser 1 sempre que maxEstados>0)|
|20|100|40|60|100|2|0|0|10| ramificação elevada, profundidade elevada| 

No entanto, infelizmente a heurística não é simulada, pelo que não dá para analisar algoritmos informados.

\anchor artificia-a2
2## Ação 2 - Resolver manualmente

Introduza: **2; 1; *ENTER*.**

```entrada
g:0 h:4 1|2|3
--<([1])>--
  +#1 g:1 h:3 1|2|3 a3293277081
  |--<([3293277081])>--
  +#2 g:1 h:3 1|2|3 a2068425467
   --<([2068425467])>--
Sucessor [1-2, ação(ões), exe]:1
g:0 h:3 2|4|6
--<([3293277081])>--
  +#1 g:1 h:2 2|4|6 a954181094
  |--<([954181094])>--
  +#2 g:1 h:2 2|4|6 a2222870430
   --<([2222870430])>--
Sucessor [1-2, ação(ões), exe]:

Artificial
 P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 1000000
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
--<([3293277081])>--
____________________________________________________________________
```
As ações são os próprios estados. Sem informação é complicado explorar o espaço de estados.
Nesta instância o objetivo termina com 0, pelo que explorando um bocado já daria para encontrar 
uma solução, mas seria sempre uma procura à sorte.


\anchor artificia-a3
## Ação 3 - Testes Empíricos

Vamos fazer testes empíricos na linha de comandos. 

Temos aqui o custo uniforme, atendendo que há instâncias com custos distintos por ação.
Vamos portanto comparar resultados da procura em largura, custo uniforme e procura em profundidade iterativa,
atendendo a que desconhecemos a profundidade máxima das instâncias. 
Vamos colocar os algoritmos informados, dado que embora não exista heurística, 
existe a distância até ao nível do objetivo, e poderá observar-se alguma diferença.


```entrada
PS ...\Teste> TProcuraConstrutiva 1:10 -R resultadoArtificial -P P1=1:7
...
Opção: 5
...
Ficheiro resultadoArtificial.csv gravado.
```

| Valores | Instância | 1:Largura Primeiro | 2:Custo Uniforme | 3:Profundidade Primeiro | 4:Melhor Primeiro | 5:A* | 6:IDA* | 7:Branch and Bound |
|:---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Soma de I1(Custo) | 1 | 4 | 4 | 4 | 4 | 4 | 4 | 4 |
|  | 2 | 2 | 2 | 2 | 4 | 2 | 2 | 2 |
|  | 3 | 5 | 5 | 5 | 7 | 5 | 5 | 5 |
|  | 4 | 28 | 24 | 28 | 32 | 24 | 24 | 24 |
|  | 5 | 29 | 23 | 29 | 29 | 23 | 23 | 23 |
|  | 6 | 9 | 9 | 9 | 30 | 9 | 9 | 9 |
|  | 7 | 29 | 22 | 29 | 29 | 22 | 22 | 22 |
|  | 8 | -2 | -2 | -2 | 20 | 10 | 10 | 10 |
|  | 9 | 2 | 2 | 2 | 13 | 2 | 2 | 2 |
|  | 10 | -2 | -2 | -2 | 87 | 40 | 40 | 40 |
| Soma de I2(Tempo(ms)) | 1 | 0 | 1 | 1 | 0 | 1 | 0 | 0 |
|  | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|  | 3 | 0 | 5 | 0 | 0 | 1 | 1 | 0 |
|  | 4 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|  | 5 | 647 | 168 | 1454 | 0 | 4 | 4 | 13 |
|  | 6 | 0 | 0 | 0 | 0 | 0 | 1 | 3 |
|  | 7 | 1785 | 351 | 3544 | 0 | 4 | 3 | 15 |
|  | 8 | 12410 | 11681 | 10001 | 0 | 1 | 1 | 3 |
|  | 9 | 0 | 2 | 0 | 0 | 1 | 1 | 9 |
|  | 10 | 14122 | 12821 | 10001 | 1 | 5 | 7 | 33 |
| Soma de I4(Expansões) | 1 | 8 | 18 | 15 | 7 | 7 | 5 | 7 |
|  | 2 | 3 | 6 | 4 | 4 | 6 | 15 | 24 |
|  | 3 | 260 | 1575 | 315 | 8 | 69 | 6 | 11 |
|  | 4 | 11 | 33 | 18 | 15 | 32 | 158 | 32 |
|  | 5 | 408686 | 83219 | 817729 | 25 | 2309 | 2755 | 5558 |
|  | 6 | 74 | 82 | 150 | 283 | 82 | 235 | 859 |
|  | 7 | 987178 | 172024 | 1989155 | 123 | 2969 | 1939 | 6311 |
|  | 8 | 3616818 | 2549679 | 2880994 | 50 | 40 | 52 | 1075 |
|  | 9 | 4 | 172 | 5 | 13 | 172 | 209 | 2122 |
|  | 10 | 1305934 | 904220 | 1359754 | 119 | 380 | 833 | 2849 |
| Total Soma de I1(Custo) |  | 104 | 87 | 104 | 255 | 141 | 141 | 141 |
| Total Soma de I2(Tempo(ms)) |  | 28964 | 25029 | 25001 | 1 | 17 | 18 | 76 |
| Total Soma de I4(Expansões) |  | 6318976 | 3711028 | 7048139 | 647 | 6066 | 6207 | 18848 |

Podemos observar aqui que há duas instâncias que não foram resolvidas pelos algoritmos cegos, as instâncias 8 e 10. 

O custo uniforme retorna a solução ótima para as instâncias 4, 5 e 7, enquanto que a procura em largura e profundidade iterativa,
retornam soluções piores. Isto acontece dado que o custo das ações não é unitário, e o custo uniforme utiliza essa informação.
O tempo é também melhor nestes casos.


As procuras informadas são bastante robustas, mesmo com a heurística mínima
indicando a informação até ao nível em que pode estar o estado objetivo. 
Estas 10 instâncias não são portanto complexas para estes algoritmos, tanto o A*, IDA** como o Branch-and-Bound, 
resolvem todas à optimalidade, e com bons tempos. O Melhor Primeiro é o mais eficiente, mas retorna soluções piores.

Assim, podem lidar com objetivos mais raros, profundos, e com ramificação mais elevada, que as utilizadas aqui.

A remoção de duplicados não foi ativada, mas algumas instâncias tinham repetidos, e essa situação melhora
naturalmente o desempanho dos algoritmos.

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
