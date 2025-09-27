# TProcura

[![GitHub issues](https://img.shields.io/github/issues/jcoelho72/TProcura.svg)](https://github.com/jcoelho72/TProcura/issues)
[![GitHub forks](https://img.shields.io/github/forks/jcoelho72/TProcura.svg)](https://github.com/jcoelho72/TProcura/network)
[![GitHub stars](https://img.shields.io/github/stars/jcoelho72/TProcura.svg)](https://github.com/jcoelho72/TProcura/stargazers)
[![GitHub license](https://img.shields.io/github/license/jcoelho72/TProcura.svg)](https://github.com/jcoelho72/TProcura/blob/main/LICENSE)


Biblioteca em C++ para **testes paramétricos** de algoritmos, e coleção de algoritmos de procura e otimização:
- procuras construtivas  
- procuras melhorativas (evolutivas e locais)  
- procuras adversas (minimax, alfa-beta, iterativo)

> Documentação completa em:  
> 👉 [TProcura - Documentação](https://jcoelho72.github.io/TProcura/index.html)


## 📑 Sumário

- [Sobre o Projeto](#s1)
- [Funcionalidades](#s2)
- [Hierarquia de Classes](#s3)
- [Instalação](#s4)
- [Uso](#s5)
- [Exemplos](#s6)
- [Bibliografia](#s7)
- [Licença](#s8)

---

\anchor s1
## Sobre o Projeto

O **TProcura** junta testes paramétricos e implementação genérica de algoritmos de procura.  
Em vez de alterar macros e recompilar a cada teste de mudança de parâmetros, propõe-se:

- Estrutura para uma lista de parâmetros, gerida na superclasse 
- Gerar automaticamente todas as combinações de parâmertros que o utilizador desejar 
- Executar instâncias para cada combinação de parâmetros, e recolher indicadores solicitados  
- Exportar resultados em CSV para análises em Excel, R ou Python  

A arquitetura baseia-se em superclasses que já implementam algoritmos de procura. O utilizador só precisa de:

1. Herdar a classe adequada  
2. Redefinir métodos de geração de sucessores, avaliação ou operadores, para o problema concreto, conforme adequado  
3. Declarar novos parâmetros e indicadores, se desejar  

Este projeto é utilizado nas Unidades Curriculares:

- [Introdução à Inteligência Artificial](https://guiadoscursos.uab.pt/ucs/introducao-a-inteligencia-artificial/) da Universidade Aberta.
- [Heurísticas Modernas](https://guiadoscursos.uab.pt/ucs/heuristicas-modernas-2/) da Universidade Aberta e Universidade de Tras-os-Montes e Alto Douro.

---

\anchor s2
## Funcionalidades

1. Modo interativo, linha de comando ou MPI (futuro)  
2. Geração automática de combinações de parâmetros  
3. Recolha de indicadores (tempo, custo, iterações, etc.)  
4. Exportação de resultados em CSV  
5. Procuras Construtivas:  
   - Largura / Profundidade / Custo uniforme  
   - Melhor-primeiro / A\* / IDA\* / Branch-and-Bound  
6. Procuras melhorativas:  
   - Algoritmos genéticos, simples - (futuro: algoritmos evolutivos, Scatter Search, sistemas artificiais imunes, inteligência de enxames)
   - Escalada do Monte - (futuro: pesquisa tabu, arrefecimento simulado, GRASP, procura com vizinhança variável e muito alargada) 
7. Procuras adversas:  
   - Minimax / Alfa-beta / iterativo / Hash-table de estados explorados (futuro: MCTS)  

---

\anchor s3
## 📦 Hierarquia de Classes

```text
TProcura                       # algoritmo
├─ TProcuraConstrutiva         # sucessores e heurística
│  └─ TProcuraAdversa          # sucessores e heurística
└─ TProcuraMelhorativa         # solução inicial, vizinhança, mutação, cruzamento, avaliação
   ├─ TRepresentacaoBinaria    # avaliação
   ├─ TRepresentacaoInteira    # avaliação
   ├─ TRepresentacaoPermutacao # avaliação
   ├─ TRepresentacaoReal       # avaliação
   └─ TRepresentacaoArvore     # avaliação
```


\anchor s4
## Instalação

Clonar o projeto, compilar um dos projetos de teste e executar. 

### Opção 1 - Clonar o Repositório 
```bash
git clone https://github.com/jcoelho72/TProcura.git
```
ou 

Aceder a [página do repositório](https://github.com/jcoelho72/TProcura/) e clique em **"Code" → "Open with Visual Studio"**.

### Opção 2 - Download Manual

Aceder a [página do repositório](https://github.com/jcoelho72/TProcura/) e clique em **"Code" → "Download ZIP"**.

Extraia os arquivos e siga as instruções de compilação (por exemplo, via Makefile, Visual Studio etc., conforme seu ambiente).

### Opção 3 - Utilizar como Submódulo

Para integrar o TProcura como parte de outro projeto, utilize um submódulo:

```bash
git submodule add https://github.com/jcoelho72/TProcura.git
```

---

\anchor s5
## Uso

Para implementar um novo problema utilizando uma das superclasses pode:
- identificar a superclasse mais adequada, e redefinir, criando uma subclasse;
- readaptar um problema similar já implementado.

Superclasses:
- TProcura  - caso o problema não seja de procura, poderá utilizar esta classe para fazer testes paramétricos
- TProcuraConstrutiva - indicado caso tenha um problema de procura, e adopte a abordagem construtiva
- TProcuraMelhorativa  - indicado caso tenha um problema de procura ou muito grande, e opte pela abordagem melhorativa
- TCodificacaoBinaria, TCodificacaoInteira, TCodificacaoPermutacao, TCodificacaoReal, TCodificacaoArvore - na abordagem melhorativa, caso a representação do seu problema encaixe numa destas (as mais comuns), utilize estas classes de modo a ter os operadores já disponíveis, basta implementar a avaliação.
- TProcuraAdversa - indicado para procuras adversas, ou seja jogos

---

\anchor s6
## Exemplos

Problemas de exemplo da classe TProcura:
1. [TesteTVetor](teste_tvector.html)

Problemas de exemplo da classe TProcuraConstrutiva:
1. Aspirador ([parte 1](teste_aspirador1.html), [parte 2](teste_aspirador2.html))
2. [Puzzle 8](teste_puzzle8.html)
3. [8 Damas](teste_8damas.html)
4. [Partição](teste_particao.html)
5. [Artificial](teste_artificial.html)

Problemas de exemplo da classe TProcuraMelhorativa:
1. [8 Damas CI](teste_8damas_ci.html) (TCodificacaoInteira)
2. [8 Damas CP](teste_8damas_cp.html) (TCodificacaoPermutacao)
3. [Partição CB](teste_particao_cb.html) (TCodificacaoBinaria)
4. ? (TCodificacaoReal)
5. ? (TCodificacaoArvore)

Problemas de exemplo da classe TProcuraAdversa:
1. [Jogo do Galo](teste_jogo_do_galo.html)
2. [Jogo em Linha](teste_jogo_em_linha.html)

Esses exemplos servem tanto para testar o repositório quanto para servir de base para novas implementações. 

---

\anchor s7
## Bibliografia

-	Russell, S. J., & Norvig, P. (2021). Artificial intelligence: A modern approach (4th ed.). Pearson. https://elibrary.pearson.de/book/99.150005/9781292401171
-	Eiben, A. E., & Smith, J. E. (2015). Introduction to evolutionary computing (2nd ed.). Springer. https://doi.org/10.1007/978-3-662-44874-8
-	Burke, E. K., & Kendall, G. (Eds.). (2014). Search methodologies: Introductory tutorials in optimization and decision support techniques (2nd ed.). Springer. https://doi.org/10.1007/978-1-4614-6940-7

---

\anchor s8
## Licença
Distribuído sob a licença MIT. Veja o arquivo [LICENSE](https://jcoelho72.github.io/TProcura/LICENSE.txt) para mais informações.

