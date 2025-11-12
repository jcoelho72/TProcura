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
- [Ação 3 - Testes Empíricos](#particao-cb3)

\anchor particao-cp1
## Ação 1 - Ver instâncias

(fazer)

\anchor particao-cp2
## Ação 2 - Resolver manualmente

(fazer)


\anchor particao-cb3
## Ação 3 - Testes Empíricos

Atendendo ao volume de parametros nos algoritmos evolutivos,
estes testes vão utilizar desde logo um cluster (Deucalion).

### Teste: particaocb_1

Iniciamos o primeiro teste com um ponto de referência para a configuração base,
para a partição cvom codificação binária.

- **Tipo de Teste / Objetivo**: Performance (tempo vs tamanho)
- **Definição**: Instâncias: 2:1000; Configurações: (base)
- **Esforço**: P3=1:10
- **Execução**: TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_1 -P P2=2 P3=1:10


### Teste: particaocb_2

Vamos agora estudar o impacto do tamanho da população.


### Teste: particaocb_3

Vamos agora estudar a probabilidade de mutação e cruzamento, parametros P7 e P8.



| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
