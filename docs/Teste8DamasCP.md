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

(fazer)

\anchor 8damas-cp2
## Ação 2 - Resolver manualmente

(fazer)

\anchor 8damas-cp3
## Ação 3 - Algoritmos Evolutivos

(fazer)

\anchor 8damas-cp4
## Ação 4 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).


### Teste: damascp_1

Este primeiro teste vamos querer ter um ponto de referência para a configuração base,
para as 8 damas e codificação de permutação.

- **Tipo de Teste / Objetivo**: Performance (tempo vs tamanho)
- **Definição**: Instâncias: 4:40; Configurações: (base)
- **Esforço**: P3=1:100
- **Execução**: TProcuraMelhorativa 2 4:40 -R Resultados/damascp_1 -M 1 -P P2=2 P3=1:100




### Teste: damascp_2

Vamos agora estudar o impacto do tamanho da população.


### Teste: damascp_3

Vamos agora estudar a probabilidade de mutação e cruzamento, parametros P7 e P8.


| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
