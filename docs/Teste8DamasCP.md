@page teste_8damas_cp Teste 8 Damas - Codificação por Permutação

| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |


Execução de exemplo com base no problema das 8 damas, com codificação por permutação.
Pode acompanhar o teste executando as ações localmente.

No Visual Studio, selecione o projeto TProcuraMelhorativa, e execute.
No Linux na pasta `.../TProcura/Melhorativa/Teste$` execute `make` seguido de `./bin/Release/TProcuraMelhorativa`

Nota: ao executar no terminal, os parâmetros, indicadores e outros elementos, aparecem com realce de cor para facilitar a leitura.

## Sumário

- [Ação 1 - Ver instâncias](#8damas-cp1)
- [Ação 2 - Resolver manualmente](#8damas-cp2)
- [Ação 3 - Algoritmos Evolutivos](#8damas-cp3)
- [Ação 4 - Testes Empíricos](#8damas-cp6)

\anchor 8damas-cp1
## Ação 1 - Ver instâncias

Vamos entrar no problema 8 Damas Permutação, introduza: **2.**

Vamos seguir a mesma linha das 8 damas, codificação inteira. Vamos alterar para a instância de tamanho 4.

Introduza: **1; 4.**

Notar que a instância é distinta da codificação inteira. De facto a instância incial da codificação inteira não tem
representação na codificação permutação, já que neste caso apenas há permutação da posição das damas, enquanto que
na solução inicial da codificação inteira há duas damas na mesma coluna.

\anchor 8damas-cp2
## Ação 2 - Resolver manualmente

Vamos resolver a instância manualmente. Introduza: **2**

Apenas ao gerar a população inicial, temos logo uma solução de custo 0, pelo que nem se chegou a gerar 4 elementos.

Assim, vamos sair e colocar uma dimensão maior para poder ver os operadores de cruzamento.

Introduza: ** 0; 1; 6; 2.**

Agora sim, temos uma população de 4 elementos com custos de 2 a 5. Vamos começar por testar o operador de mutação.
Introduza: **1; 1.**

Neste caso o operador é um vizinho de inserção, mas o elemento retirado está na mesma posição em que é inserido, na posição 0.
Vamos repetir. Introduza: **1; 1.**

Tal como na representação inteira, há vários operadores de mutação, sendo o mesmo verdade para os restantes operadores de cruzamento e vizinhança.

Desta vez inserimos o elemento na posição 1 (segundo na ordem), na posição 3 (quarto na ordem). Todos os outros elmentos ficaram iguais.
Em termos de custos ficou igual, continuam 4 pares de damas a atacarem-se, embora sejam pares distintos.

Vamos agora ao operador de cruzamento, vamos cruzar os dois melhores elemenotos.
Introduza: **2; 2; 3; 4.**

Nete caso o filho ficou com os 3 primeiros elementos da mãe, e o resto ficou pela ordem como que aparecem no pai.
Há apenas 2 pares de damas que se atacam, tal como a mãe.

Podemos agora testar o operador de vizinhança, tendo como ponto de partida o estado 4 com custo 2.
Introduza: **3; 4.**

Há 30 vizinhos, existindo vários com custo 1. Vamos escolher um deles e repetir o processo.
Introduza: **30; 3; 4;**

Neste caso temos novamente vários vizinhos de custo 1, mas nenhum de custo 0. Vamos escolher o primeiro e terminar.

Introduza: **1; 0.**

\anchor 8damas-cp3
## Ação 3 - Algoritmos Evolutivos

Vamos agora ver os algoritmos evolutivos nos diferentes níveis de debug, para esta instância de tamanho 6.

Introduza: **1; 6; 3; 2; 1; *ENTER*;6.**



Introduza: **1; 6; 3; 2; 2; *ENTER*;6.**


Introduza: **1; 6; 3; 2; 3; *ENTER*;6.**


Introduza: **1; 6; 3; 2; 4; *ENTER*;6.**


\anchor 8damas-cp4
## Ação 4 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

[Resultdos Deucalion](melhorativa__deucalion.html)








| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
