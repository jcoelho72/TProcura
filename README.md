# TProcuraConstrutiva

[![GitHub issues](https://img.shields.io/github/issues/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/issues)
[![GitHub forks](https://img.shields.io/github/forks/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/network)
[![GitHub stars](https://img.shields.io/github/stars/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/stargazers)
[![GitHub license](https://img.shields.io/github/license/jcoelho72/TProcuraConstrutiva.svg)](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt)

Uma coleção de algoritmos e implementações para **procuras e otimizações** em problemas complexos.

A documentação completa está disponível em:  
👉 [TProcuraConstrutiva - Documentação](https://jcoelho72.github.io/TProcuraConstrutiva/index.html)


## Sumário

- [Sobre o Projeto](#s1)
- [Estado do Projeto](#s2)
- [Funcionalidades](#s3)
- [Instalação](#s4)
- [Uso](#s5)
- [Exemplos](#s6)
- [Licença](#s7)

\anchor s1
## Sobre o Projeto

Uma coleção de algoritmos e implementações para [procuras construtivas](#), 
criada como ponto de partida para a implementação de novos problemas e estratégias de procura. 
Esse repositório serve como base para explorar e desenvolver soluções em problemas de otimização.

Recursos utilizados na UC de [Introdução à Inteligência Artificial](https://guiadoscursos.uab.pt/ucs/introducao-a-inteligencia-artificial/), 
da [Licenciatura em Engenharia Informática](https://guiadoscursos.uab.pt/ucs/introducao-a-inteligencia-artificial/) da [Universidade Aberta](https://portal.uab.pt/)

Bibliografia da UC, e base teórica para o projeto: 
Russell, S. J., & Norvig, P. (2021). Artificial Intelligence: A Modern Approach (4th ed.). Pearson.

\anchor s2
## Estado do Projeto

> :warning: Este projeto ainda está em desenvolvimento.  
> Atualizações frequentes e melhorias estão sendo implementadas.

\anchor s3
## Funcionalidades

- Implementação de algoritmos de procura construtiva na superclasse.
- Exploração do espaço de estados de forma manual
- Execução de algoritmos cegos: Procura em Largura, Profundidade Primeiro, Custo Uniforme
- Execução de algoritmos informados: Melhor Primeiro, AStar, IDAStar, Branch-and-Bound
- Executar de testes manuais e testes empíricos (várias instâncias e vários algoritmos/parametrizações).

\anchor s4
## Instalação e Execução

Clonar o projeto, compilar e executar. 

### Opção 1 - Clonar o Repositório 
```bash
git clone https://github.com/jcoelho72/TProcuraConstrutiva.git
```
### Opção 2 - Download Manual

Aceder a [página do repositório](https://github.com/jcoelho72/TProcuraConstrutiva/) e clique em **"Code" → "Download ZIP"**.

Extraia os arquivos e siga as instruções de compilação (por exemplo, via Makefile, Visual Studio etc., conforme seu ambiente).

### Opção 3 - Utilizar como Submódulo

Para integrar o TProcuraConstrutiva como parte de outro projeto, utilize um submódulo:

```bash
git submodule add https://github.com/jcoelho72/TProcuraConstrutiva.git
```
Essa opção é útil se pretender manter o código atualizado.

Teste a classe com problemas implementados. 

\anchor s5
## Uso

Para implementar um novo problema utilizando o TProcuraConstrutiva, pode:
- redefinir a superclasse TProcuraConstrutiva de raiz;
- readaptar um problema similar e adaptá-lo.

### Redefinição Mandatória

Ao redefinir a superclasse, é essencial que sejam implementados os seguintes métodos: 
- Duplicar(): Cria um objecto que é uma cópia deste.
- Copiar(): Fica com uma cópia do objecto.
- SolucaoVazia(): Coloca o objecto no estado inicial da procura.
- Sucessores(): Coloca em sucessores a lista de estados sucessores.
- SolucaoCompleta(): Verifica se o estado actual é objectivo (é uma solução completa)
- TesteManual(): Inicializa a interação com o utilizador.

[Documentação dos métodos de Redefinição Mandatória](https://jcoelho72.github.io/TProcuraConstrutiva/group__RedefinicaoMandatoria.html):

### Métodos Sugeridos

Para otimizar a execução e enriquecer as funcionalidades, recomenda-se também a implementação dos 
[Métodos Sugeridos](https://jcoelho72.github.io/TProcuraConstrutiva/group__RedefinicaoSugerida.html). 
Estes métodos adicionais podem fornecer suporte a funções avançadas e melhorar a exploração do espaço de estados.

\anchor s6
## Exemplos

Alguns problemas estão implementados para demonstrar o funcionamento da classe TProcuraConstrutiva:
1. Aspirador ([parte 1](teste_aspirador1.html), [parte 2](teste_aspirador2.html))
2. [Puzzle 8](teste_puzzle8.html)
3. [8 Damas](teste_8damas.html)
4. [Partição](teste_particao.html)
5. [Artificial](teste_artificial.html)

Esses exemplos servem tanto para testar o repositório quanto para servir de base para novas implementações.

\anchor s7
## Licença
Distribuído sob a licença MIT. Veja o arquivo [LICENSE](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt) para mais informações.

