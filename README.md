# TProcuraConstrutiva

[![GitHub issues](https://img.shields.io/github/issues/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/issues)
[![GitHub forks](https://img.shields.io/github/forks/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/network)
[![GitHub stars](https://img.shields.io/github/stars/jcoelho72/TProcuraConstrutiva.svg)](https://github.com/jcoelho72/TProcuraConstrutiva/stargazers)
[![GitHub license](https://img.shields.io/github/license/jcoelho72/TProcuraConstrutiva.svg)](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt)

Uma coleção de algoritmos e implementações para **procuras e otimizações** em problemas complexos.

## Sumário

- [Sobre o Projeto](#sobre-o-projeto)
- [Estado do Projeto](#estado-do-projeto)
- [Funcionalidades](#funcionalidades)
- [Instalação e Uso](#instalação-e-uso)
- [Documentação](#documentação)
- [Exemplos](#exemplos)
- [Contribuindo](#contribuindo)
- [Licença](#licença)
- [Contato](#contato)

## Sobre o Projeto

Apresenta a implementação de algoritmos voltados para [procuras construtivas](#), com foco em explorar soluções de otimização e problemas práticos.  
*A ideia é que este projeto sirva como repositório central para procuras construtivas, enquanto projetos derivados possam contemplar procuras melhorativas e procuras adversas. Estes três projetos podem servir de base para a implementação de problemas concretos, sendo criado também um porjeto para  exemplos de problemas implementados.*

## Estado do Projeto

> :warning: Este projeto ainda está em desenvolvimento.  
> Atualizações frequentes e melhorias estão sendo implementadas.

## Funcionalidades

- Implementação de algoritmos de procura construtiva na superclasse.
- A redefinição da classe, permite implementação de novos problemas, e utilizar algoritmos construtivos.
- Possibilita a exploração do espaço de estados manualmente
- Permite a execução de algoritmos cegos: Procura em Largura, Profundidade Primeiro, Custo Uniforme
- Permite a execução de algoritmos informados: Melhor Primeiro, AStar, IDAStar, Branch-and-Bound
- Executar tanto testes manuais, como testes empíricos (utilizando várias instâncias e comparando vários algoritmos e parametrizações).

## Instalação e Uso

### Pré-requisitos

- Compilador de C++
- [Doxygen](http://www.doxygen.nl/) para gerar a documentação
- [Git](https://git-scm.com/) para controle de versão

### Clonando o Repositório
```bash
git clone https://github.com/jcoelho72/TProcuraConstrutiva.git
```

## Licença
Distribuído sob a licença MIT. Veja o arquivo [LICENSE](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt) para mais informações.
