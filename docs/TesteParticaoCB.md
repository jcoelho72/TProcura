@page teste_particao_cb Teste Particao - Codificação Binária

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |

Execução de exemplo com base no problema da Partição, com codificação binária.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute.
No Linux na pasta `.../TProcura/Melhorativa/Teste$` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#particao-cb1)
- [Ação 2 - Resolver manualmente](#particao-cb2)
- [Ação 3 - Algoritmos Evolutivos](#particao-cb3)
- [Ação 4 - Testes Empíricos](#particao-cb4)

\anchor particao-cb1
## Ação 1 - Ver instâncias

Vamos entrar no problema da Partição, com representação binária, introduza: **3.**

Temos inicialmente uma instância de 10 elementos, mas devido ao nível de debug não vemos o estado completo.
Introduza: **3; 2; 4; *ENTER*.**

Agora podemos ver os números todos, já num dos lados (esquerda ou direita). 

Vamos deixar esta instância.
Significa que temos de decidir para cada um dos 10 elementos, em que lado fica, esquerda ou direita,
de modo a que o somatório seja igual.

\anchor particao-cb2
## Ação 2 - Resolver manualmente

Vamos resolver a instância manualmente. Introduza: **2**

Como a codificação é binária, temos uma sequência de bits, 0/1, tantos quantos os números existentes, neste caso 10.

O valor do custo é a diferença obtida após a divisão dos núemros. Pretende-se uma instância de custo 0, ou seja, ambos os
lados com o mesmo somatório.

Vamos testar a mutação. Introduza: **1; 1.**

Foi mutado o bit na posição 9. O custo melhorou, sendo agora o melhor dos custos, mesmo assim 150, ainda distante de 0.

Vamos testar o cruzamento nos dois melhores, elementos 1 e 4.
Introduza: **2; 1; 4; 2.**

Foi aplicado o cruzamento a 1 ponto, tendo o ponto sido na posição 8. Assim o filho ficou com 8 bits do pai, e os dois últimos bits da mãe.
Ficou com um custo de 414, entre o pai e a mãe.

Vamos agora testar a vizinhança, usando o melhor estado. Introduza: **3; 1.**

Temos vários vizinhos com custo inferior, em que estes vizinhos é trocado um só bit. Vamos escolher o vizinho 1 e repetir.
Introduza: **1; 3; 1.**

Neste caso todos os vizinhos têm um custo superior ao próprio, sendo o vizinho de melhor custo o pai deste, portanto voltariamos
ao mesmo estado se o escolhessemos. Estamos no óptimo local.

Vamos escolher um vizinho e terminar. Introduza: **1; 0.**


\anchor particao-cb3
## Ação 3 - Algoritmos Evolutivos

Vamos  ver os algoritmos evolutivos nos diferentes níveis de debug, para esta instância de tamanho 10.

Introduza: **1; 10; 3; 2; 1; *ENTER*;6.**



Introduza: **1; 10; 3; 2; 2; *ENTER*;6.**


Introduza: **1; 10; 3; 2; 3; *ENTER*;6.**


Introduza: **1; 10; 3; 2; 4; *ENTER*;6.**


Podemos ver que a solução não foi obtida da instância de custo 2, mas sim da instância de custo 478 com outrra de custo 250.
Esta observação é importante para que não seja dado demasiada importância ao melhor elemento, descartando os restantes.
É sempre importante ter diversidade na população, e permitir que elementos piores se reproduzam.

\anchor particao-cb4
## Ação 3 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

[Resultdos Deucalion](melhorativa__deucalion.html)




| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
