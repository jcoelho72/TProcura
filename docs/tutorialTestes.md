@page tutorial_testes Tutorial Testes Computacionais

Este tutorial concentra-se nos aspetos mais relevantes para a boa realização de testes computacionais.
Um teste destina-se a avaliar um programa num determinado aspeto, seja a sua funcionalidade (ausência de bugs),
seja a sua eficiência (quanto tempo leva), seja a sua eficácia (probabilidade de ser bem sucedido),
seja a sua qualidade (quão boas são as soluções), sejam os seus limites (até que tamanho funciona bem).

Podem ser definidos indicadores para melhor medir estas dimensões de forma mais apropriada para o problema em questão.
Algo cruzial é conhecer a sensibilidade dos parâmetros do algoritmo, de modo a identificar quais
os parâmetros críticos e quais os irrelevantes, de modo a poder ser acumulado conhecimento
que seja possível utilzar o algoritmo nas melhores condições possíveis.

Abordar os seguintes temas:
- importância dos testes - programador, investigador
- difentes tipos de testes
- resultados: testes estatísticos (média, intervalos de confiança, percentil)
- processamento de resultados (csv > Excel / Power Pivot, modelo de dados / medidas, indicadores calculados )
- testes com TProcura


Resultados no Deucalion:

- [Resultados Construtiva](construtiva__deucalion.html)
- [Resultados Melhorativa](melhorativa__deucalion.html)
- [Resultdos Adversa](teste_jogo_em_linha.html) - separar do Jogo em Linha?


# esboço Copilot

## Testes Computacionais em IA — Estrutura sugerida

1. Porque testar?
- variabilidade
- reprodutibilidade
- significância estatística
- volume de testes

2. Tipos de testes computacionais
- testes determinísticos vs estocásticos
- testes paramétricos vs não paramétricos
- comparação de algoritmos
- comparação de parâmetros
- análise de sensibilidade

3. Estatística mínima necessária
- média, variância, desvio padrão
- intervalos de confiança
- teste t (paramétrico)
- Wilcoxon/Mann‑Whitney (não paramétrico)
- tamanho de amostra

4. Ferramentas de análise
- PowerPivot/DAX - Excel avançado
- Python (opcional)
- alternativas (R, pandas)

5. Execução distribuída
- porque clusters são essenciais
- volume de testes vs significância
- como o TProcura abstrai MPI
- boas práticas

6. Exemplo completo com os teus dados
- problema, algoritmos, parâmetros, resultados, análise, conclusões


