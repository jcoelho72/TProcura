@page teste_aspirador2 Teste Aspirador - Parte 2/2

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |

Execução de exemplo com base no problema do Aspirador. Pode acompanhar o teste excutando as ações localmente.

## Sumário

- [Ação 10 - Procura em Profundidade](#aspirador-a10)
- [Ação 11 - Efetuar uma procura em Profundidade Primeiro](#aspirador-a11)
- [Ação 12 - Ver uma árvore de procura maior](#aspirador-a12)
- [Ação 13 - Profundidade Iterativa](#aspirador-a13)
- [Ação 14 - Profundidade ilimitada](#aspirador-a14)
- [Ação 15 - Desafio Procura Profundidade](#aspirador-a15)

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

Selecione o problema do Aspirador: **1.**


\anchor aspirador-a10
## Ação 10 - Procura em Profundidade

![Profundidade Primeiro - expande primeiro os estados mais profundos](docs/images/aspirador_profundidade.png)

Avançamos agora para a procura em profundidade. 
Neste caso temos neste algoritmo diversas estratégias. 
Podemos executar esta procura com um limite de profundidade. 
Vamos fazer isso na instância 2, que sabemos ter uma solução de 3 movimentos.

\anchor aspirador-a11
## Ação 11 - Efetuar uma procura em Profundidade Primeiro

Utilizar a instância número 2, o algoritmo profundidade primeiro, 
com limite de profundidade a 3, com nível de debug máximo, ignorando repetidos e ver ações a 1: 
**1; 2; 3; 1; 3; 7; 3; 2; 4; 8; 1; 6; 1; *ENTER*; 6.**

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

O parâmetro 7 é o limite, com diferentes interpretações conforme o algoritmo.  
Na procura em largura o limite servia para limitar o número de estados gerados mas não expandidos. 
Aqui serve para limitar o nível de profundidade, que é fixado a 3. 

```entrada
Opção: 6
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

 P1=3 P2=4 P3=1 P4=10 P5=0 P6=1 P7=3 P8=1 P9=100 P10=0
 P11=0
Aspirador
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): completo | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 3 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
 * [*]
I1(Custo): -1 | I2(Tempo(ms)): 12 | I3(Iterações): 0 | I4(Expansões): 3 | I5(Gerações): 6 |
I6(Lower Bound): 0
____________________________________________________________________
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |
```

Podemos ver todos os estados gerados. 
A árvore tendo 3 níveis, permite dois movimentos, pelo que não foi descoberta a solução, retornando -1. 
Embora o indicador 6 não seja atualizado, este resultado pode ser utilizado para saber que não há nenhuma solução 
de comprimento inferior a 3, ou seja, é um lower bound, neste caso 4, já que o custo de cada movimento é unitário. 

Esta visualização da árvore da procura é interessante para pequenos problemas, 
mas naturalmente que procuras maiores torna-se impraticável. 
Podemos observar aqui que o estado inicial foi gerado novamente, dado que estamos a ignorar os repetidos.

\anchor aspirador-a12
## Ação 12 - Ver uma árvore de procura maior

Colocar a profundidade a 10, e o nível de debug a 3: **1; 2; 3; 7; 10; 2; 3; *ENTER*; 6.**

```entrada
Opção: 6
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
 P1=3 P2=3 P3=1 P4=10 P5=0 P6=1 P7=10 P8=1 P9=100 P10=0
 P11=0
Aspirador
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): detalhe | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 10 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
[.] .
I1(Custo): 9 | I2(Tempo(ms)): 22 | I3(Iterações): 0 | I4(Expansões): 12 | I5(Gerações): 24 |
I6(Lower Bound): 0
____________________________________________________________________
```
Com o nível debug a 3 vemos a árvore de procura apenas os estados folha, mas não os estados expandidos. 
A informação é mais reduzida, mas poderá ser uma boa forma de analisar 
os estados em que o algoritmo volta para trás, 
já que podem ter alguma característica relevante, ainda não implementada. 
A solução não é óptima, tem comprimento 9! Podemos visualizar a solução, introduza: **4.**

```entrada
Opção: 4

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
É com base nesse dilema que surge a procura em profundidade iterativa, 
no caso deste código é executada com o limite=0.

\anchor aspirador-a13
## Ação 13 - Profundidade Iterativa

Colocar a profundidade iterativa (limite a 0), e o nível de debug a 2: **1; 2; 3; 7; 0; 2; 2; *ENTER*; 6.**

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
 P1=3 P2=2 P3=1 P4=10 P5=0 P6=1 P7=0 P8=1 P9=100 P10=0
 P11=0
Aspirador
 P1(Algoritmo): Profundidade Primeiro | P2(Debug): passos | P3(Seed): 1 | P4(Tempo): 10 | P5(Iterações): 0
 P6(Ver): 1 | P7(Limite): 0 | P8(Repetidos): ignorar | P9(pesoAStar): 100 | P10(ruido): 0
 P11(baralhar): 0
[.] .
I1(Custo): 3 | I2(Tempo(ms)): 15 | I3(Iterações): 0 | I4(Expansões): 10 | I5(Gerações): 20 |
I6(Lower Bound): 0
____________________________________________________________________
```

Podemos observar que o algoritmo encontrou a solução de comprimento 3, a solução ótima. 
Fez várias iterações que não serviram para nada, antes de executar na iteração 4 com limite a 4. 
Mas essas árvores de procura são muito mais pequenas, pelo que o peso de executar essas procuras extra não é muito relevante.

Podemos ver também a versão compactada da árvore de procura, contendo apenas informação do estado, 
tal como na procura em largura, mas desta vez com informação de onde o estado veio. 
Pela observação da árvore é possível verificar que a maior parte das ramificações são de dois sucessores, 
o que é natural dado que este problema tem apenas duas salas.

Vamos agora ver o que acontece se não limitarmos a procura em profundidade, colocando o limite=-1

\anchor aspirador-a14
## Ação 14 - Profundidade ilimitada

Colocar a profundidade ilimitada (limite a -1), e o nível de debug a 1: 
**1; 2; 3; 7; -1; 2; 1; *ENTER*; 6.**

```entrada
Opção: 5
########
```

Temos um crash do programa, e bem cedo. 
Como a procura em profundidade está implementada de forma recursiva, houve um problema no stack. 
Se tivesse implementada com listas, teríamos um problema de memória, como na procura em largura. 
Entrou-se num ramo infinito, mesmo neste pequeno problema, como aliás é possível imaginar na solução da procura com nível 10. 

\anchor aspirador-a15
## Ação 15 - Desafio Procura Profundidade

Lembra-se de algo dado na procura em largura, que impede ciclos infinitos e poderia permitir o uso da procura em profundidade ilimitada?

<details>
  <summary>Resposta</summary>
Sim, não ignorar os estados repetidos não servem apenas para reduzir a árvore de procura. Evitam também ciclos infinitos. 
Com repetidos nos ascendentes ou gerados, consegue resolver com a procura em profundidade ilimitada, qualquer uma das 50 instâncias.
</details>

Está terminado esta execução de exemplo. Este problema tem uma heurística perfeita, pelo que, qualquer algoritmo informado 
encontra a solução ótima sem nunca se enganar. Iremos em outros problemas testar os algoritmos informados.

O custo de cada ação é sempre unitário, pelo que, o custo uniforme será mostrado num problema em que cada ação possa ter custo variável.
Deixamos também as configurações e os testes empíricos, com as opções 6 e 7 do menu dos testes manuais, para outros problemas. 

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [Artificial](teste_artificial.html) |
