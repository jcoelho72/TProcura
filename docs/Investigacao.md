@page investigacao Testes de Algoritmos com o TProcura

## Sumário

- [Importância dos Testes](#investigacao-a1)
- [O Papel do TProcura](#investigacao-a2)
- [Características dos Testes no TProcura](#investigacao-a3)
- [O Ciclo do Investigador](#investigacao-a4)
- [Tipos de Testes](#investigacao-a5)
- [Modelo para Testes](#investigacao-a6)


\anchor investigacao-a1
## Importância dos Testes

A construção de novos e melhores algoritmos é um ponto crítico no desenvolvimento da sociedade,
permitindo fazer mais, e de forma mais eficiente.

Ao propor um novo algoritmo, o investigador deve suportar as afirmações que faz — nomeadamente
que o algoritmo é melhor ou complementar a outros existentes.
Só assim se convertem afirmações em conhecimento sólido, utilizável por outros.

Em muitos contributos científicos, o suporte pode vir de:
- Dados recolhidos de forma uniforme na sociedade (utilização de produtos ou serviços, inquéritos, etc.)
- Provas matemáticas (ex.: teoria da complexidade)
- Experiências controladas e replicáveis

No caso dos algoritmos, existe a particularidade de poderem ser testados de forma ilimitada,
dependendo apenas do poder computacional disponível. Assim, estamos em melhores condições
para suportar afirmações sobre o seu comportamento, desde que os testes sejam executados
de forma ordenada e documentada.

\anchor investigacao-a2
## O Papel do TProcura

Uma das principais funções do projeto TProcura é precisamente facilitar a execução de testes a algoritmos.
Além disso, o TProcura integra um conjunto de meta-algoritmos aplicáveis a problemas diversos
de procura e otimização, incluindo:
- Algoritmos construtivos
- Algoritmos melhorativos (evolutivos, locais, etc.)
- Algoritmos de procura adversa (minimax, alfa-beta, etc.)

O utilizador apenas precisa de implementar a parte específica do problema.
Os algoritmos genéricos, juntamente com os parâmetros utilizados, ficam prontos para teste.

\anchor investigacao-a3
## Características dos Testes no TProcura

Os testes realizados com o TProcura visam garantir que:

- São reproduzíveis — é possível executar novamente o mesmo teste
- Todas as condições estão completamente descritas (instâncias, parâmetros, indicadores)
- Não existem parâmetros ocultos que possam influenciar o resultado (incluindo números aleatórios, se usados)

\anchor investigacao-a4
## O Ciclo do Investigador

O investigador que desenvolve um novo algoritmo passa por um ciclo típico:
1. Ideia inicial
2. Refinamento e desenho
3. Implementação
4. Primeiros testes
5. Retorno à ideia e refinamento

Este ciclo é natural, mas pode tornar-se caótico: parâmetros espalhados no código,
resultados guardados em locais diferentes, alterações de última hora que invalidam comparações.
O TProcura visa disciplinar e simplificar este processo.

\anchor investigacao-a4
## Estrutura de um Teste

Para definir um teste, precisamos de três elementos fundamentais:
- Instâncias: dados concretos do problema (ex.: rede de estradas para o problema do caminho mais curto).
  Devem ser diversas e representativas, para suportar conclusões generalizáveis.
- Configurações: todos os valores dos parâmetros do algoritmo.
  Cada parâmetro representa uma escolha de desenho ou execução.
- Indicadores: resultados extraídos da execução.
	- Indicador principal: valor da solução (objetivo do problema)
	- Indicadores genéricos: tempo de execução, número de iterações
	- Indicadores específicos: métricas adicionais que validam ou explicam a solução obtida

Com esta estrutura, conseguimos separar a **análise do algoritmo** da **implementação** do código.


\anchor investigacao-a5
## Tipos de Testes

- Validação
  Verificar se os resultados são corretos (sem bugs).
- Paramétricos
  Explorar o impacto dos parâmetros:
  - Configurações alternativas (comparar A vs. B)
  - Parâmetro irrelevante (não altera significativamente os resultados)
  - Valor ideal do parâmetro (melhor valor entre todos)
  - Pares de parâmetros (melhor combinação conjunta)
- Performance
  Medir o tempo de execução em função da dimensão do problema.
- Eficiência / Qualidade
  Relacionar a qualidade da solução com a complexidade da instância.
- Limites
  Determinar até que dimensão de instâncias o algoritmo é utilizável.

\anchor investigacao-a6
## Modelo para Testes

Propõe-se esta estrutura para um teste, numa sequência de testes.

### Identificação
- Nome do problema ou sigla
- ID do teste sequencial

Os testes são uma sequência de testes, podendo um teste utilizar resultados de testes anteriores 
Utilizar o nome_ID para identificar o ficheiro de resultados.

### Tipo de Teste / Objetivo
- [Validação / Paramétrico / Performance / Eficiência / Limites]
- Objetivo: [ex.: obter melhor valor de um parâmetro]

A identificação do objetivo é importante para saber se se conseguiu, e
compreender a sequência de testes realizada.

### Definição do Teste
- Instâncias: [lista ou referência a ficheiros]
- Configurações: [parâmetros e respetivos valores]
- Indicadores: [solução, tempo, iterações, métricas específicas]

Estas definições são realizadas no TProcura, utilizando a facilidade
de definir várias configurações.

### Esforço
- Cargas de esforço:  
  - A: [base, ex.: P3=1]  
  - B: [descrição, ex.: P3=1:10]  
  - C: [descrição, ex.: P3=1:100]

O teste pode ter várias cargas de esforço, sendo a primeira a base.
No caso de ter uma componente aleatória, o P3 com a semente é uma forma
simples de se ter o mesmo teste em esforço maior.
No caso de se utilizar uma carga de esforço superior, digamos que B, para maior precisão,
o ficheiro de resultados fica com o nome nome_ID_B.

### Execução
- Linha de comando
- Output obtido

Execução com todos os parametros, pronta a reproduzir, utilizando a menor carga de esforço.

### Análise e Conclusões
- Gráficos: [ex.: tempo médio vs. dimensão]
- Estatísticas: [médias, desvios, testes de significância]
- Conclusões: [ex.: melhor valor para o parametro é K] 



