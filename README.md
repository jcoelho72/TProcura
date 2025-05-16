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
- [Exploração do Espaço de Estados e Testes](#exploração-do-espaço-de-estados-e-testes)
- [Exemplos](#exemplos)
- [Contribuindo](#contribuindo)
- [Licença](#licença)
- [Contato](#contato)

## Sobre o Projeto

Apresenta a implementação de algoritmos voltados para [procuras construtivas](#), com foco em explorar soluções de otimização e problemas práticos.  

*Pretende-se que sirva como repositório central para procuras construtivas, enquanto projetos derivados possam contemplar procuras melhorativas e procuras adversas. 
Estes três projetos podem servir de base para a implementação de problemas concretos, sendo criado também um porjeto para  exemplos de problemas implementados.*

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

Clonar o projeto, compilar e executar. Teste a classe com problemas artificiais. 

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

## Exploração do Espaço de Estados e Testes

Após implementar os métodos obrigatórios (e, se possível, os sugeridos), você poderá explorar e testar os algoritmos de procura construtiva. No teste manual, as opções disponíveis são:

1. Inicializar – Define o estado inicial utilizando uma instância concreta do problema.
2. Explorar – Navega, de forma interativa, pelo espaço de estados, permitindo executar ações válidas e testar resoluções manuais.
3. Solução/Caminho – Exibe a solução completa ou o caminho atual para a solução, seja obtido manualmente ou por um algoritmo.
4. Parâmetros – Mostra todos os parâmetros configuráveis e permite alterar seus valores, tanto os definidos pela superclasse quanto os específicos do problema.
5. Executar – Executa o algoritmo com os parâmetros atualmente configurados; isso inclui os limites de execução, tempo e a seleção do algoritmo.
6. Configurações – Permite adicionar a configuração atual como um novo cenário ou apagar configurações existentes, as quais são utilizadas no teste empírico.
7. Teste – Executa testes empíricos sobre um conjunto de instâncias e configurações, possibilitando comparações entre diferentes algoritmos e/ou parâmetros.

Essa abordagem de testes empíricos permite analisar o desempenho de algoritmos em diversos cenários, considerando a diversidade e o grau de dificuldade das instâncias de teste.

### Clonando o Repositório
```bash
git clone https://github.com/jcoelho72/TProcuraConstrutiva.git
```

## Licença
Distribuído sob a licença MIT. Veja o arquivo [LICENSE](https://jcoelho72.github.io/TProcuraConstrutiva/LICENSE.txt) para mais informações.
