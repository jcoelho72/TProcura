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

- **Tipo de Teste / Objetivo**: Performance (Eficácia / Eficiência vs tamanho)
- **Definição**: Instâncias: 2:1000; Configurações: (base)
- **Esforço**: P3=1:10
- **Execução**: TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_1 -M 1 -P P2=2 P3=1:10

Variáveis:
- Resolvido=(I1=0)
- Eficácia: Percentagem de instãncias resolvidas (=round(AVERAGE(bruto[Resolvido])*100;0))
- Eficiência: Tempo médio utilizado (=round(AVERAGE([I2(Tempo(ms))]);0))

A eficácia pode ser definida desta forma, atendendo a que este algoritmo apenas pode detectar a isntância resolvida as que têm solução.
Para as instância sem solução, irá procurar a solução com diferença mínima, não existindo forma de comprovar que é de facto a mínima pela natureza da abordagem melhorativa.

<details>
  <summary>Ver execução:</summary>
```
═╤═ Instâncias ═══ { 📄 2 📄 3 📄 4 … 📄 998 📄 999 📄 1000 } #999
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m100 [90mP8=[0m50 [90mP9=[0m1 [90mP10=[0m150 [90mP13=[0m1 [90mP14=[0m100
 ├─ ⚙   ─ [90mP16=[0m1 [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1
 ├─ ⚙  [2] ─ [90mP3=[0m2
 ├─ ⚙  [3] ─ [90mP3=[0m3
 ├─ ⚙  [4] ─ [90mP3=[0m4
 ├─ ⚙  [5] ─ [90mP3=[0m5
 ├─ ⚙  [6] ─ [90mP3=[0m6
 ├─ ⚙  [7] ─ [90mP3=[0m7
 ├─ ⚙  [8] ─ [90mP3=[0m8
 ├─ ⚙  [9] ─ [90mP3=[0m9
 ├─ ⚙  [10] ─ [90mP3=[0m10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:9990   📄 Instâncias: 999   🛠️ Configurações: 10   🖥️ Processos: 48.
 ├─ ⏱ 1' 143ms        📋 459   📄 621   🛠️ 9     🖥️ 20    ⚖  64068 10001 129663 6145 135807 
 ├─ ⏱ 2' 413ms        📋 999   📄 91    🛠️ 9     🖥️ 11    ⚖  426 10000 737334 34966 772299 
 ├─ ⏱ 3' 419ms        📋 1436  📄 576   🛠️ 8     🖥️ 10    ⚖  0 1789 24421 1157 25577 
 ├─ ⏱ 4' 470ms        📋 1971  📄 121   🛠️ 8     🖥️ 8     ⚖  436 10000 583891 27682 611572 
 ├─ ⏱ 5' 586ms        📋 2410  📄 608   🛠️ 7     🖥️ 39    ⚖  0 1625 21033 997 22029 
 ├─ ⏱ 6' 626ms        📋 2940  📄 151   🛠️ 7     🖥️ 13    ⚖  2264 10000 481535 22826 504360 
 ├─ ⏱ 7' 668ms        📋 3384  📄 616   🛠️ 6     🖥️ 41    ⚖  0 496 6340 300 6639 
 ├─ ⏱ 8' 844ms        📋 3909  📄 181   🛠️ 6     🖥️ 30    ⚖  4692 10000 410694 19465 430158 
 ├─ ⏱ 9' 996ms        📋 4355  📄 711   🛠️ 5     🖥️ 4     ⚖  88054 10002 113099 5359 118457 
 ├─ ⏱ 10' 1" 32ms     📋 4894  📄 197   🛠️ 5     🖥️ 3     ⚖  3670 10000 382721 18139 400859 
 ├─ ⏱ 11' 1" 417ms    📋 5350  📄 721   🛠️ 4     🖥️ 33    ⚖  130592 10001 111615 5290 116904 
 ├─ ⏱ 12' 1" 460ms    📋 5871  📄 217   🛠️ 4     🖥️ 41    ⚖  5510 10000 349454 16564 366017 
 ├─ ⏱ 13' 1" 488ms    📋 6334  📄 731   🛠️ 3     🖥️ 42    ⚖  86224 10001 110777 5249 116025 
 ├─ ⏱ 14' 1" 613ms    📋 6848  📄 239   🛠️ 3     🖥️ 42    ⚖  8774 10000 320768 15203 335970 
 ├─ ⏱ 15' 1" 737ms    📋 7314  📄 747   🛠️ 2     🖥️ 9     ⚖  92892 10002 108338 5135 113472 
 ├─ ⏱ 16' 1" 923ms    📋 7821  📄 263   🛠️ 2     🖥️ 39    ⚖  9098 10000 294446 13952 308397 
 ├─ ⏱ 17' 1" 945ms    📋 8296  📄 770   🛠️ 1     🖥️ 45    ⚖  2 10000 103291 4893 108183 
 ├─ ⏱ 18' 2" 217ms    📋 8794  📄 291   🛠️ 1     🖥️ 10    ⚖  15436 10001 266955 12654 279608 
 ├─ ⏱ 19' 2" 320ms    📋 9269  📄 732   🛠️ 0     🖥️ 10    ⚖  0 1525 16535 783 17317 
 ├─ ⏱ 20' 2" 368ms    📋 9779  📄 301   🛠️ 0     🖥️ 12    ⚖  16622 10001 259325 12289 271613 
 ├─ 📑  Ficheiro Resultados/particaocb_1.csv gravado.
 │  ⏱  Tempo real: 20' 28" 691ms 
 │  ⏱  CPU total: 16h 2' 28" 500ms 
 │  ⏱  Espera do gestor: 20' 28" 492ms 
 │  ⏱  Espera trabalhadores: 53" 537ms 
 │  📊  Utilização:
 │  - Total: 97.8%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.9% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 20' 28" 692ms ) ═══
```
</details>

| N | Eficácia | Eficiência |
|:---:|---:|---:|
| 2 | 40 | 1265 |
| 3 | 0 | 2200 |
| 4 | 30 | 1687 |
| 5 | 0 | 2721 |
| 6 | 40 | 1794 |
| 7 | 0 | 3239 |
| 8 | 50 | 1726 |
| 9 | 0 | 3624 |
| 10 | 100 | 0 |
| 11 | 0 | 3950 |
| 12 | 100 | 1 |
| 13 | 0 | 4269 |
| 14 | 100 | 1 |
| 994 | 80 | 4976 |
| 995 | 0 | 10001 |
| 996 | 70 | 4391 |
| 997 | 0 | 10001 |
| 998 | 90 | 2824 |
| 999 | 0 | 10002 |
| 1000 | 80 | 4548 |

A tabela foi cortada devido à sua extensão, mas mantém o mesmo padrão.

Cada instância é gerada com base no número aleatório, pelo que neste caso não temos apenas 999 instâncias.
Como foram utilizadas 10 corridas com valores diferentes para P3 por cada tamanho, temos 9990 instâncias.

As instâncias ímpares não são resolvidas, as pares a partir da instância 10 são todas resolvidas,
e apenas exporadicamente há uma instância par não resolvida.

Como a abordagem melhorativa não permite resolver instâncias sem solução, provavelemnente a razão para
não se encontrar a solução é por não existir a solução. Em algumas instâncias é possível confirmar com base
na execução das procuras construtivas, outras não.

Assim vamos utilizar para conjunto de teste apenas instâncias pares, que tenham sido todas resolvidas (com os 10 valores de P3),
com os maiores tempos.

Teste: 948,864,930,922,764,692,806,926,904,870 


### Teste: particaocb_2

Vamos agora estudar o impacto do tamanho da população.

Embora este problema seja distinto do problema das 8 damas, vamos manter os mesmos valores de teste,
de modo a apurar o impacto da população na eficiência, cobrindo assim populações desde 5 a 200.
As instâncias que utilizamos sabemos terem todas solução, pelo que apenas a eficiência irá ser medida.

- **Tipo de Teste / Objetivo**: População vs Eficiência
- **Definição**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=5,10,15,20,25,30,40,50,75,100,150,200
- **Esforço**: P3=1:10
- **Execução**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_2 -M 1 -P P2=2 P3=1:10 x P6=5,10,15,20,25,30,40,50,75,100,150,200


<details>
  <summary>Ver execução:</summary>
```
═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP7=[0m100 [90mP8=[0m50 [90mP9=[0m1 [90mP10=[0m150 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP6=[0m5
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP6=[0m5
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP6=[0m5
 │ ...
 ├─ ⚙  [118] ─ [90mP3=[0m8 [90mP6=[0m200
 ├─ ⚙  [119] ─ [90mP3=[0m9 [90mP6=[0m200
 ├─ ⚙  [120] ─ [90mP3=[0m10 [90mP6=[0m200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:1200   📄 Instâncias: 10   🛠️ Configurações: 120   🖥️ Processos: 48.
 ├─ ⏱ 1' 104ms        📋 479   📄 692   🛠️ 77    🖥️ 19    ⚖  0 4513 48748 954 49701 
 ├─ ⏱ 2' 117ms        📋 1172  📄 870   🛠️ 3     🖥️ 47    ⚖  0 895 27369 4530 31898 
 ├─ 📑  Ficheiro Resultados/particaocb_2.csv gravado.
 │  ⏱  Tempo real: 2' 12" 320ms 
 │  ⏱  CPU total: 1h 43' 39" 43ms 
 │  ⏱  Espera do gestor: 2' 12" 295ms 
 │  ⏱  Espera trabalhadores: 4' 52" 925ms 
 │  📊  Utilização:
 │  - Total: 93.3%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 95.3% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 2' 12" 320ms ) ═══
```
</details>

| P6(População) | Eficácia | Eficiência |
|:---:|---:|---:|
| 5 | 73 | 5307 |
| 10 | 93 | 3510 |
| 15 | 94 | 3186 |
| 20 | 100 | 4528 |
| 25 | 91 | 4528 |
| 30 | 94 | 3417 |
| 40 | 86 | 4433 |
| 50 | 92 | 3960 |
| 75 | 80 | 5487 |
| 100 | 75 | 5850 |
| 150 | 61 | 7522 |
| 200 | 49 | 7553 |

O parametro P6(População) tem a eficácia a 100% apenas no valor de omissão 20.
No entanto existem valores com melhor eficiência.
Não se vê no entanto uma tendência clara, apenas uma zona que aparenta ser melhor, entre 10 e 50 elementos,
em que o tempo médio é inferior a 5 segundos. Assim, considera-se que este parametro não é crítico, pelo menos na
configuração atual dos restantes parametros, pelo que optou-se por manter o valor de omissão: P6=20.

### Teste: particaocb_3

Vamos estudar a probabilidade de cruzamento e mutação, parametros P7 e P8, com os valores de omissão de 100 e 50 respetivamente.

- **Tipo de Teste / Objetivo**: Paramétrico (P7 vs P8)
- **Definição**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0:100:25 x P8=0:100:25
- **Esforço**: P3=1:10
- **Execução**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_3 -M 1 -P P2=2 P6=20 P3=1:10 x P7=0:100:25 x P8=0:100:25

<details>
  <summary>Ver execução:</summary>
```
═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP9=[0m1 [90mP10=[0m150 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1 [90mP17=[0m1
 ├─ ⚙   ─ [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP7=[0m0 [90mP8=[0m0
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP7=[0m0 [90mP8=[0m0
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP7=[0m0 [90mP8=[0m0
 │ ...
 ├─ ⚙  [248] ─ [90mP3=[0m8 [90mP7=[0m100 [90mP8=[0m100
 ├─ ⚙  [249] ─ [90mP3=[0m9 [90mP7=[0m100 [90mP8=[0m100
 ├─ ⚙  [250] ─ [90mP3=[0m10 [90mP7=[0m100 [90mP8=[0m100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:2500   📄 Instâncias: 10   🛠️ Configurações: 250   🖥️ Processos: 48.
 ├─ ⏱ 1' 42ms         📋 796   📄 806   🛠️ 184   🖥️ 28    ⚖  2 10000 110901 5271 116171 
 ├─ ⏱ 2' 96ms         📋 1472  📄 806   🛠️ 112   🖥️ 4     ⚖  2 10002 130660 6108 136767 
 ├─ ⏱ 3' 204ms        📋 1990  📄 864   🛠️ 56    🖥️ 38    ⚖  0 8788 128487 5760 134246 
 ├─ ⏱ 4' 304ms        📋 2394  📄 870   🛠️ 15    🖥️ 17    ⚖  4 10000 138154 6152 144305 
 ├─ 📑  Ficheiro Resultados/particaocb_3.csv gravado.
 │  ⏱  Tempo real: 4' 31" 238ms 
 │  ⏱  CPU total: 3h 32' 28" 181ms 
 │  ⏱  Espera do gestor: 4' 31" 186ms 
 │  ⏱  Espera trabalhadores: 3' 44" 479ms 
 │  📊  Utilização:
 │  - Total: 96.2%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 4' 31" 238ms ) ═══
```
</details>

| P7 vs P8 | 0 | 25 | 50 | 75 | 100 | Total Geral |
|:---:|---:|---:|---:|---:|---:|---:|
| 0 | 9994 | 6911 | 4902 | 3660 | 2742 | 5642 |
| 25 | 9788 | 7188 | 4779 | 3370 | 3288 | 5682 |
| 50 | 8268 | 5411 | 4109 | 3166 | 3301 | 4851 |
| 75 | 6097 | 4487 | 4106 | 4365 | 4213 | 4654 |
| 100 | 3833 | 4069 | 4528 | 3993 | 4731 | 4231 |
| Total Geral | 7596 | 5613 | 4485 | 3711 | 3655 | 5012 |

A melhor parametrização é tal como nas 8 damas com a codificação de permutação, P7=0 e P8=100,
o que significa que o cruzamento nunca é realizado, e é sempre aplicada a mutação.
A diferença é de 4,5 segundos para a configuração de base, baixando para 2,7 segundos, o que é
uma diferença considerável. Assim vamos mudar a configuração base para P7=0 e P8=100.

### Teste: particaocb_4

Mesmo sem operadores de cruzamento a estratégia de seleção de pais tem influência no algoritmo.

P9(SELECAO) tem três valores possíveis:
- 1: Roleta (omissão)
- 2: Torneio
- 3: Uniforme

- **Tipo de Teste / Objetivo**: Paramétrico P9
- **Definição**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=1:3
- **Esforço**: P3=1:10
- **Execução**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_4 -M 1 -P P2=2 P6=20 P7=0 P8=100 P3=1:10 x P9=1:3

<details>
  <summary>Ver execução:</summary>
```
```
</details>

Eficiência

| P7 vs P8 | 0 | 25 | 50 | 75 | 100 | Total Geral |
|:---:|---:|---:|---:|---:|---:|---:|
| 0 | 3574 | 1999 | 1225 | 545 | 175 | 1504 |





| [TesteTVector](teste_tvector.html) | [Aspirador 1](teste_aspirador1.html) | [Aspirador 2](teste_aspirador2.html) | [Puzzle 8](teste_puzzle8.html) | [8 Damas](teste_8damas.html) | [Partição](teste_particao.html) | [8 Damas CI](teste_8damas_ci.html) | [8 Damas CP](teste_8damas_cp.html) | [Partição CB](teste_particao_cb.html) |
