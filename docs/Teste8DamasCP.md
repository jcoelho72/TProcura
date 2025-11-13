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

- **Tipo de Teste / Objetivo**: Performance (Eficácia / Eficiência vs tamanho)
- **Definição**: Instâncias: 4:40; Configurações: (base)
- **Esforço**: P3=1:100
- **Execução**: TProcuraMelhorativa 2 4:40 -R Resultados/damascp_1 -M 1 -P P2=2 P3=1:100

Variáveis:
- Resolvido=(I1=0)
- Eficácia: Percentagem de instãncias resolvidas (=round(AVERAGE(bruto[Resolvido])*100;0))
- Eficiência: Tempo médio utilizado (=round(AVERAGE([I2(Tempo(ms))]);0))

A eficácia pode ser medido desta forma, atendendo a que se conhece o valor das soluções óptimas, que são soluções de custo 0.
Num problema de optimização esta solução não poderia ser adoptada.

<details>
  <summary>Ver execução:</summary>
```
═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m100 [90mP8=[0m50 [90mP9=[0m1 [90mP10=[0m150 [90mP13=[0m1 [90mP14=[0m100
 ├─ ⚙   ─ [90mP16=[0m1 [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m3 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1
 ├─ ⚙  [2] ─ [90mP3=[0m2
 ├─ ⚙  [3] ─ [90mP3=[0m3
 │ ...
 ├─ ⚙  [98] ─ [90mP3=[0m98
 ├─ ⚙  [99] ─ [90mP3=[0m99
 ├─ ⚙  [100] ─ [90mP3=[0m100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3700   📄 Instâncias: 37   🛠️ Configurações: 100   🖥️ Processos: 48.
 ├─ ⏱ 1' 37ms         📋 525   📄 37    🛠️ 87    🖥️ 19    ⚖  5 10000 376142 17882 394023 
 ├─ ⏱ 2' 51ms         📋 1014  📄 32    🛠️ 74    🖥️ 14    ⚖  4 10000 449876 21389 471264 
 ├─ ⏱ 3' 58ms         📋 1493  📄 33    🛠️ 61    🖥️ 41    ⚖  2 10000 430411 20463 450873 
 ├─ ⏱ 4' 407ms        📋 1986  📄 17    🛠️ 46    🖥️ 28    ⚖  0 637 57312 2722 60033 
 ├─ ⏱ 5' 1" 67ms      📋 2483  📄 18    🛠️ 34    🖥️ 18    ⚖  0 7161 608310 28915 637224 
 ├─ ⏱ 6' 1" 561ms     📋 2977  📄 30    🛠️ 21    🖥️ 21    ⚖  3 10000 488738 23237 511974 
 ├─ ⏱ 7' 1" 565ms     📋 3472  📄 10    🛠️ 6     🖥️ 3     ⚖  0 22 3090 146 3235 
 ├─ 📑  Ficheiro Resultados/damascp_1.csv gravado.
 │  ⏱  Tempo real: 7' 37" 19ms 
 │  ⏱  CPU total: 5h 57' 59" 877ms 
 │  ⏱  Espera do gestor: 7' 36" 942ms 
 │  ⏱  Espera trabalhadores: 3' 3" 742ms 
 │  📊  Utilização:
 │  - Total: 97.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 7' 37" 19ms ) ═══
```
</details>

| Instância | Eficácia | Eficiência |
|:---:|---:|---:|
| 4 | 100 | 0 |
| 5 | 100 | 0 |
| 6 | 100 | 1 |
| 7 | 100 | 1 |
| 8 | 100 | 2 |
| 9 | 100 | 5 |
| 10 | 100 | 23 |
| 11 | 100 | 48 |
| 12 | 100 | 74 |
| 13 | 100 | 155 |
| 14 | 100 | 353 |
| 15 | 100 | 518 |
| 16 | 100 | 816 |
| 17 | 100 | 2057 |
| 18 | 97 | 2924 |
| 19 | 77 | 4991 |
| 20 | 68 | 6104 |
| 21 | 35 | 8262 |
| 22 | 20 | 9007 |
| 23 | 9 | 9591 |
| 24 | 7 | 9694 |
| 25 | 5 | 9782 |
| 26 | 5 | 9781 |
| 27 | 2 | 9852 |
| 28 | 2 | 9964 |
| 29 | 1 | 9910 |
| 30 | 1 | 9910 |
| 31 | 0 | 10000 |
| 32 | 0 | 10000 |
| 33 | 0 | 10000 |
| 34 | 0 | 10000 |
| 35 | 0 | 10000 |
| 36 | 0 | 10000 |
| 37 | 0 | 10000 |
| 38 | 0 | 10000 |
| 39 | 0 | 10000 |
| 40 | 0 | 10000 |

Os problemas são todos resolvidos até à instância 17, após o qual a eficácia desce
ficando a baixo dos 10% na instância 22.
A eficiência vai também subindo, na instância 17 onde ainda todas as instâncias são resolvidas,
já leva 2 segundos em média.

Acaba por ter uma performance idêntica à codificação inteira, mas com tempos mais reduzidos.
No entanto, aparenta ter mais dificuldades com instâncias maiores, naturalmente utilizando como
referência a configuração base.

Utilizando o mesmo racional que nas 8 damas com codificação inteira, e também para mantermos
o conjunto de teste comparável entre as duas configurações, vamos utilizar as instâncias 10 a 19
para os testes seguintes, de modo a apurar a melhor marametrização.


### Teste: damascp_2

Da mesma forma que na codificação inteira, vamos ver o população do algoritmo evolutivo (P6),
utilizando exatamente os mesmos parametros, de modo a poder comparar diretamente codificações. 

- **Tipo de Teste / Objetivo**: População vs Eficiência
- **Definição**: Instâncias: 10:19; Configurações: P6=5,10,15,20,25,30,40,50,75,100,150,200
- **Esforço**: P3=1:100
- **Execução**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200

<details>
  <summary>Ver execução:</summary>
```
═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP7=[0m100 [90mP8=[0m50 [90mP9=[0m1 [90mP10=[0m150 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m3 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP6=[0m5
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP6=[0m5
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP6=[0m5
 │ ...
 ├─ ⚙  [1198] ─ [90mP3=[0m98 [90mP6=[0m200
 ├─ ⚙  [1199] ─ [90mP3=[0m99 [90mP6=[0m200
 ├─ ⚙  [1200] ─ [90mP3=[0m100 [90mP6=[0m200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:12000   📄 Instâncias: 10   🛠️ Configurações: 1200   🖥️ Processos: 48.
 ├─ ⏱ 1' 35ms         📋 918   📄 16    🛠️ 1121  🖥️ 8     ⚖  0 8873 575090 2860 577949 
 ├─ ⏱ 2' 70ms         📋 1824  📄 12    🛠️ 1018  🖥️ 4     ⚖  0 303 25825 170 25994 
 ├─ ⏱ 3' 132ms        📋 2907  📄 18    🛠️ 923   🖥️ 38    ⚖  0 8856 617724 6114 623837 
 ├─ ⏱ 4' 177ms        📋 4226  📄 13    🛠️ 778   🖥️ 8     ⚖  0 251 25724 503 26226 
 ├─ ⏱ 5' 181ms        📋 5912  📄 12    🛠️ 609   🖥️ 7     ⚖  0 147 16498 401 16898 
 ├─ ⏱ 6' 211ms        📋 7895  📄 14    🛠️ 413   🖥️ 40    ⚖  0 1123 116682 4479 121160 
 ├─ ⏱ 7' 217ms        📋 10545 📄 16    🛠️ 145   🖥️ 2     ⚖  0 134 18923 1714 20636 
 ├─ 📑  Ficheiro Resultados/damascp_2.csv gravado.
 │  ⏱  Tempo real: 7' 42" 303ms 
 │  ⏱  CPU total: 6h 2' 8" 263ms 
 │  ⏱  Espera do gestor: 7' 42" 60ms 
 │  ⏱  Espera trabalhadores: 2' 56" 133ms 
 │  📊  Utilização:
 │  - Total: 97.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 7' 42" 303ms ) ═══
```
</details>

| P6(População) | Eficácia | Eficiência |
|:---:|---:|---:|
| 5 | 91 | 1287 |
| 10 | 98 | 826 |
| 15 | 97 | 1148 |
| 20 | 98 | 1138 |
| 25 | 97 | 1389 |
| 30 | 97 | 1360 |
| 40 | 96 | 1582 |
| 50 | 95 | 1752 |
| 75 | 92 | 2201 |
| 100 | 88 | 2557 |
| 150 | 83 | 3051 |
| 200 | 81 | 3271 |

Na codificação permutação das 8 damas, ao contrário da codificação inteira, o valor da população mais eficiente é 10.
Esta codificação não é tão sensivel a este parametro como a codificação inteira, mantendo no geral valores altos
na eficácia e eficiência.

Vamos alterar o valor de omissão para P6=10.


### Teste: damascp_3

Seguem-se agora os parametros da probabilidade de cruzamento e mutação, parametros P7 e P8, com os valores de omissão de 100 e 50 respetivamente.

- **Tipo de Teste / Objetivo**: Paramétrico (P7 vs P8)
- **Definição**: Instâncias: 10:19; Configurações: P6=20 P7=0:100:25 x P8=0:100:25
- **Esforço**: P3=1:100
- **Execução**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_3 -M 1 -P P2=2 P6=10 P3=1:100 x P7=0:100:25 x P8=0:100:25


<details>
  <summary>Ver execução:</summary>
```
```
</details>

| N | Eficácia | Eficiência |
|:---:|---:|---:|
| 2 | 40 | 1265 |
| 3 | 0 | 2200 |


| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
