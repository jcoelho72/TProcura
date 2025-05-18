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
- [Exemplos](#exemplos)
- [Licença](#licença)

## Sobre o Projeto

Apresenta a implementação de algoritmos voltados para [procuras construtivas](#), com foco em explorar soluções de otimização e problemas práticos.  

*Pretende-se que sirva como repositório central para procuras construtivas, enquanto projetos derivados possam contemplar procuras melhorativas e procuras adversas. 
Estes três projetos podem servir de base para a implementação de problemas concretos, sendo criado também um projeto para mais exemplos de problemas.*

Recursos utilizados na UC de [Introdução à Inteligência Artificial](https://guiadoscursos.uab.pt/ucs/introducao-a-inteligencia-artificial/), 
da [Licenciatura em Engenharia Informática](https://guiadoscursos.uab.pt/ucs/introducao-a-inteligencia-artificial/) da [Universidade Aberta](https://portal.uab.pt/)

Bibliografia da UC, e base teórica para o projeto: 
Russell, S. J., & Norvig, P. (2021). Artificial Intelligence: A Modern Approach (4th ed.). Pearson.

## Estado do Projeto

> :warning: Este projeto ainda está em desenvolvimento.  
> Atualizações frequentes e melhorias estão sendo implementadas.

## Funcionalidades

- Implementação de algoritmos de procura construtiva na superclasse.
- Exploração do espaço de estados de forma manual
- Execução de algoritmos cegos: Procura em Largura, Profundidade Primeiro, Custo Uniforme
- Execução de algoritmos informados: Melhor Primeiro, AStar, IDAStar, Branch-and-Bound
- Executar de testes manuais e testes empíricos (várias instâncias e vários algoritmos/parametrizações).

## Instalação e Uso

Clonar o projeto, compilar e executar. Teste a classe com problemas implementados. 

Para implementar um novo problema, redefina a superclasse TProcuraConstrutiva, implementando os seguintes métodos de [Redefinição Mandatória](https://jcoelho72.github.io/TProcuraConstrutiva/group__RedefinicaoMandatoria.html):

- Duplicar(): Cria um objecto que é uma cópia deste.
- Copiar(): Fica com uma cópia do objecto.
- SolucaoVazia(): Coloca o objecto no estado inicial da procura.
- Sucessores(): Coloca em sucessores a lista de estados sucessores.
- SolucaoCompleta(): Verifica se o estado actual é objectivo (é uma solução completa)
- TesteManual(): Inicializa a interação com o utilizador.

Essas implementações podem utilizar os modelos existentes na documentação. Estes métodos permitem a execução dos algoritmos de procura construtivos. 

Para optimizar a execução dos algoritmos e enriquecer a sua funcionalidade, recomenda-se também implementar os 
[Métodos Sugeridos](https://jcoelho72.github.io/TProcuraConstrutiva/group__RedefinicaoSugerida.html). Esses métodos adicionais podem oferecer suporte a funcionalidades avançadas e contribuir para uma melhor exploração do espaço de estados.

## Exemplos

Estão implementados alguns problemas, tendo sido realizados testes de modo a exemplificar o funcionamento da classe TProcuraConstrutiva: 

1. Aspirador ([parte 1](teste_aspirador1), [parte 2](teste_aspirador2))
2. [Puzzle 8](teste_puzzle8)
3. [8 Damas](teste_8damas)
4. [Partição](teste_particao)
5. [Artificial](teste_artificial)

### Clonando o Repositório
```bash
git clone https://github.com/jcoelho72/TProcuraConstrutiva.git
```

## Licença
Distribuído sob a licença MIT. Veja o arquivo [LICENSE](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt) para mais informações.

