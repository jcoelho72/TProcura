@page melhorativa__deucalion Deucalion - testes melhorativos

Testes da classe TProcuraMelhorativa no cluster Deucalion.

A documentação do cluster Deucalion pode ser encontrada em: https://docs.deucalion.macc.fccn.pt/
A forma como se pode obter acesso ao cluster, bem como a submissão de trabalhos, está descrita nessa documentação.

Vamos realizar testes paramétricos para as três implementações (CI, CP e CB)
com o objetivo de identificar a melhor parametrização, no contexto dos algoritmos evolutivos.
Pretendemos determinar quais os parâmetros que têm impacto relevante na eficácia (resolução) e na eficiência (tempo).

Os diversos testes irão ser feitos em paralelo nas três implementações:
- 8 damas codificação inteira (CI)
- 8 damas codificação por permutação (CP)
- partição codificação binária (CB)

Como todos os problemas são de procura e o indicador I1 mede o número de violações,
definimos as seguintes variáveis de análise:

Variáveis:
- Resolvido=(I1=0)
- Eficácia: Percentagem de instâncias resolvidas (=round(AVERAGE(bruto[Resolvido])*100;0))
- Eficiência: Tempo médio utilizado (=round(AVERAGE([I2(Tempo(ms))]);0))

Estas serão as variáveis de performance que iremos monitorizar para identificar a melhor parametrização.

O indicador de eficiência conta as instâncias não resolvidas como tendo o tempo limite (10 s).
Como muitas dessas instâncias exigiriam muito mais tempo se o limite fosse removido,
a média de tempos reportada é otimista — subestima o tempo real necessário.
Assim, a eficiência medida não pode exceder 10 s por instância
e tende a mascarar a gravidade de instâncias que, sem limite, precisariam de muito mais tempo.


Assim, instâncias que simplesmente não terminam dentro do limite não penalizam muito a eficiência,
já que sem este limite iriam ser eventualmente resolvidas com um tempo maior.
O indicador da eficácia não distingue entre duas instâncias resolvidas,
mesmo que uma leve 0,1 segundos e a outra 5 segundos.

Um problema em que se pretenda otimizar, ao contrário destes que são de procura, ou seja, se pretendessemos minimizar I1,
teria de ter indicadores distintos, como distância relativa à solução ótima, ou a um valor mínimo conhecido.

Para averiguar se as diferenças obtidas na eficiência (tempo), são ou não relevantes, vamos calcular também o
intervalo de confiança a 95% para a eficiência, bem como o percentil de 10 e 90% e mediana:

- ICinf = round(AVERAGE([I2(Tempo(ms))]) - 1.96 * STDEV.S([I2(Tempo(ms))]) / SQRT(COUNTROWS(bruto));0)
- ICsup = round(AVERAGE([I2(Tempo(ms))]) + 1.96 * STDEV.S([I2(Tempo(ms))]) / SQRT(COUNTROWS(bruto));0)
- P10 = round(PERCENTILEX.INC('bruto'; [I2(Tempo(ms))]; 0,1);0)
- P90 = round(PERCENTILEX.INC('bruto'; [I2(Tempo(ms))]; 0,9);0)
- Med = round(PERCENTILEX.INC('bruto'; [I2(Tempo(ms))]; 0,5);0)


## Teste 1

Vamos fazer um teste de performance inicial com a configuração base, ou seja, todos os parâmetros no seu
valor por omissão. Pretendemos ter uma avaliação sobre um conjunto alargado de instâncias, em termos de eficácia,
se o algoritmo foi bem sucedido, e eficiência, se foi rápido. Esta será uma referência que iremos repetir no final
com a configuração encontrada, e assim quantificar o ganho da realização dos testes paramétricos.

Como os três problemas utilizam codificações distintas, vamos identificar os problemas por CI (8 damas codificação inteira),
CP (8 damas codificação permutação) e CB (partição codificação binária).

Para as 8 damas com a codificação inteira e permutação, vamos utilizar o conjunto completo de instâncias. Como o algoritmo é aleatório,
vamos executar 100 execuções de modo a ganhar precisão sobre a capacidade da configuração base de resolver uma dada instância.

No problema da partição tem instâncias de 2 a 1000 (quantidade de números), e a instância é gerada aleatoriamente, pelo que por cada valor de P3
existe uma nova instância. Assim, para manter um volume razoável, variamos o esforço de P3 de 1 a 10.

- **Tipo de Teste / Objetivo**: Performance (Eficácia / Eficiência vs tamanho)
- **Definição**:
	- **ci+cp**: Instâncias: 4:40; Configurações: (base)
	- **cb**: Instâncias: 2:1000; Configurações: (base)
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 4:40 -R Resultados/damasci_1 -M 1 -P P2=2 P3=1:100
	- **cp**: TProcuraMelhorativa 2 4:40 -R Resultados/damascp_1 -M 1 -P P2=2 P3=1:100
	- **cb**: TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_1 -M 1 -P P2=2 P3=1:10

\htmlonly
<details>
  <summary>Ver script: evolutivos1.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos1
#SBATCH --output=Resultados/evolutivos1.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_1
srun bin/MPI/TProcuraMelhorativa 1 4:40 -R Resultados/damasci_1 -M 1 -P P2=2 P3=1:100
# Teste: damascp_1
srun bin/MPI/TProcuraMelhorativa 2 4:40 -R Resultados/damascp_1 -M 1 -P P2=2 P3=1:100
# Teste: particaocb_1
srun bin/MPI/TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_1 -M 1 -P P2=2 P3=1:10
</pre>
</details>
<details>
<summary>Ver comandos no cluster</summary>
No cluster submetemos o trabalho com o comando:
<pre>
/TProcura/Melhorativa/Teste$ sbatch evolutivos1.sh
</pre>
Podemos ver se o trabalho está em execução com:
<pre>
/TProcura/Melhorativa/Teste$ squeue --me
</pre>
Para verificar o output do trabalho, mesmo durante a execução, consultamos o ficheiro Resultados/construtiva.txt vendo o final do ficheiro
<pre>
/TProcura/Melhorativa/Teste$ tail -f Resultados/evolutivos1.txt
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 │ ...
 ├─ ⚙  [98] ─ <span style="color:gray">P3=</span>98
 ├─ ⚙  [99] ─ <span style="color:gray">P3=</span>99
 ├─ ⚙  [100] ─ <span style="color:gray">P3=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3700   📄 Instâncias: 37   🛠️ Configurações: 100   🖥️ Processos: 48.
 ├─ ⏱ 1' 17ms         📋 510   📄 14    🛠️ 86    🖥️ 19    ⚖  0 1110 110559 5198 115756 
 ├─ ⏱ 2' 259ms        📋 1017  📄 30    🛠️ 74    🖥️ 45    ⚖  1 10000 390577 18393 408969 
 ├─ ⏱ 3' 318ms        📋 1501  📄 25    🛠️ 59    🖥️ 18    ⚖  0 389 19454 916 20369 
 ├─ ⏱ 4' 1" 288ms     📋 1988  📄 23    🛠️ 47    🖥️ 23    ⚖  0 6153 342982 16136 359117 
 ├─ ⏱ 5' 1" 698ms     📋 2489  📄 15    🛠️ 33    🖥️ 14    ⚖  0 3123 289744 13630 303373 
 ├─ ⏱ 6' 1" 796ms     📋 2974  📄 21    🛠️ 20    🖥️ 46    ⚖  0 3527 221558 10421 231978 
 ├─ ⏱ 7' 1" 836ms     📋 3445  📄 37    🛠️ 8     🖥️ 13    ⚖  2 10001 288301 13589 301889 
 ├─ 📑  Ficheiro Resultados/damasci_1.csv gravado.
 │  ⏱  Tempo real: 7' 40" 920ms 
 │  ⏱  CPU total: 6h 1' 3" 221ms 
 │  ⏱  Espera do gestor: 7' 40" 842ms 
 │  ⏱  Espera trabalhadores: 3' 19" 779ms 
 │  📊  Utilização:
 │  - Total: 97.0%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 7' 40" 920ms ) ═══

═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 │ ...
 ├─ ⚙  [98] ─ <span style="color:gray">P3=</span>98
 ├─ ⚙  [99] ─ <span style="color:gray">P3=</span>99
 ├─ ⚙  [100] ─ <span style="color:gray">P3=</span>100
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

═╤═ Instâncias ═══ { 📄 2 📄 3 📄 4 … 📄 998 📄 999 📄 1000 } #999
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 ├─ ⚙  [4] ─ <span style="color:gray">P3=</span>4
 ├─ ⚙  [5] ─ <span style="color:gray">P3=</span>5
 ├─ ⚙  [6] ─ <span style="color:gray">P3=</span>6
 ├─ ⚙  [7] ─ <span style="color:gray">P3=</span>7
 ├─ ⚙  [8] ─ <span style="color:gray">P3=</span>8
 ├─ ⚙  [9] ─ <span style="color:gray">P3=</span>9
 ├─ ⚙  [10] ─ <span style="color:gray">P3=</span>10
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
</pre>
</details>
\endhtmlonly

### Resultados: damasci_1

| Instância | Eficácia | Eficiência |
|:---:|---:|---:|
| 4 | 100 | 0 |
| 5 | 100 | 1 |
| 6 | 100 | 16 |
| 7 | 100 | 15 |
| 8 | 100 | 40 |
| 9 | 100 | 66 |
| 10 | 100 | 213 |
| 11 | 100 | 358 |
| 12 | 100 | 475 |
| 13 | 100 | 779 |
| 14 | 100 | 1073 |
| 15 | 100 | 1688 |
| 16 | 99 | 1980 |
| 17 | 95 | 3455 |
| 18 | 94 | 4102 |
| 19 | 83 | 4985 |
| 20 | 66 | 5545 |
| 21 | 48 | 7279 |
| 22 | 38 | 8247 |
| 23 | 31 | 8365 |
| 24 | 22 | 8830 |
| 25 | 10 | 9514 |
| 26 | 11 | 9582 |
| 27 | 6 | 9690 |
| 28 | 6 | 9631 |
| 29 | 1 | 9965 |
| 30 | 2 | 9889 |
| 31 | 3 | 9976 |
| 32 | 1 | 9953 |
| 33 | 0 | 10000 |
| 34 | 0 | 10000 |
| 35 | 0 | 10000 |
| 36 | 0 | 10000 |
| 37 | 1 | 9966 |
| 38 | 0 | 10000 |
| 39 | 0 | 10000 |
| 40 | 0 | 10000 |

Os problemas são todos resolvidos até à instância 15, após o qual a eficácia desce
ficando a baixo dos 10% na instância 27.
A eficiência vai também piorando (subindo), na instância 15 onde ainda todas as instâncias são resolvidas,
já leva 1,7 segundos em média.

Com base nesses resultados, definimos o conjunto de teste para a região de transição entre instâncias fáceis e difíceis.
Isto evita incluir instâncias demasiado simples (que não diferenciam parametrizações) e instâncias muito difíceis
(que consomem o tempo limite), concentrando o esforço em casos que evidenciam diferenças de desempenho.

Escolhemos o intervalo de instâncias 10–19: a instância 10 é ainda relativamente rápida (≈0,2 s),
e a instância 19 já apresenta casos não resolvidos (tempo médio ≈5 s), pelo que o intervalo
é adequado para discriminar parametrizações.

### Resultados: damascp_1

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
o conjunto de teste comparável entre as duas codificações, vamos utilizar as instâncias 10 a 19
para os testes seguintes, de modo a apurar a melhor parametrização.


### Resultados: particaocb_1

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
e apenas esporadicamente há uma instância par não resolvida.

A abordagem melhorativa não encontra soluções quando a instância não tem solução.
Provavelmente as instâncias ímpares não têm solução; em alguns casos isso pode ser verificado por procura construtiva,
noutras não.

Por isso, o conjunto de teste para CB será constituído apenas por instâncias pares que foram todas resolvidas
(10 valores de P3) e apresentam maiores tempos; isto maximiza a informação útil.

Conjunto de teste: 948,864,930,922,764,692,806,926,904,870 

## Teste 2

Vamos agora iniciar o estudo dos parâmetros. Adoptamos a ordem com que estão definidos.
Alguns parâmetros são dependentes do valor de outros, pelo que são analisados em conjunto.

Arrancamos com o parâmetro P6 população. Este é um parâmetro determinante nos algoritmos evolutivos.

O valor por omissão é 20, vamos variar em valores baixos e altos.
Vamos começar com o valor 5, embora valores mais baixos
sejam possíveis, mas assim o algoritmo evolutivo assemelha-se a uma procura local e para funcionar
tem de se alterar outros parâmetros. Iremos estudar esta vertente numa fase posterior.

- **Tipo de Teste / Objetivo**: População vs Eficiência
- **Definição**:
	- **ci+cp**: Instâncias: 10:19; Configurações: P6=5,10,15,20,25,30,40,50,75,100,150,200
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=5,10,15,20,25,30,40,50,75,100,150,200
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 10:19 -R Resultados/damasci_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200
	- **cp**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_2 -M 1 -P P2=2 P3=1:10 x P6=5,10,15,20,25,30,40,50,75,100,150,200

\htmlonly
<details>
  <summary>Ver script: evolutivos2.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos2
#SBATCH --output=Resultados/evolutivos2.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_2
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200
# Teste: damascp_2
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200
# Teste: particaocb_2
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_2 -M 1 -P P2=2 P3=1:10 x P6=5,10,15,20,25,30,40,50,75,100,150,200

</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P6=</span>5
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P6=</span>5
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P6=</span>5
 │ ...
 ├─ ⚙  [1198] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P6=</span>200
 ├─ ⚙  [1199] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P6=</span>200
 ├─ ⚙  [1200] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P6=</span>200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:12000   📄 Instâncias: 10   🛠️ Configurações: 1200   🖥️ Processos: 48.
 ├─ ⏱ 1' 279ms        📋 490   📄 19    🛠️ 1157  🖥️ 44    ⚖  1 10002 511940 2540 514479 
 ├─ ⏱ 2' 290ms        📋 976   📄 16    🛠️ 1102  🖥️ 43    ⚖  0 505 30180 149 30328 
 ├─ ⏱ 3' 378ms        📋 1452  📄 10    🛠️ 1059  🖥️ 38    ⚖  0 4826 430353 2839 433191 
 ├─ ⏱ 4' 398ms        📋 1967  📄 16    🛠️ 1003  🖥️ 9     ⚖  0 235 15112 99 15210 
 ├─ ⏱ 5' 435ms        📋 2513  📄 16    🛠️ 952   🖥️ 40    ⚖  0 4852 338872 3340 342211 
 ├─ ⏱ 6' 496ms        📋 3112  📄 16    🛠️ 891   🖥️ 12    ⚖  0 2891 210821 2757 213577 
 ├─ ⏱ 7' 592ms        📋 3766  📄 10    🛠️ 826   🖥️ 26    ⚖  0 3388 365929 4784 370712 
 ├─ ⏱ 8' 616ms        📋 4553  📄 10    🛠️ 745   🖥️ 46    ⚖  0 290 34610 674 35283 
 ├─ ⏱ 9' 788ms        📋 5506  📄 14    🛠️ 649   🖥️ 34    ⚖  0 195 17749 429 18177 
 ├─ ⏱ 10' 798ms       📋 6657  📄 11    🛠️ 535   🖥️ 7     ⚖  0 578 68506 2183 70688 
 ├─ ⏱ 11' 817ms       📋 8034  📄 15    🛠️ 403   🖥️ 2     ⚖  0 2995 267380 10161 277540 
 ├─ ⏱ 12' 820ms       📋 9408  📄 18    🛠️ 276   🖥️ 33    ⚖  1 10000 889716 54940 944655 
 ├─ ⏱ 13' 837ms       📋 10286 📄 14    🛠️ 177   🖥️ 5     ⚖  0 5942 825726 74208 899933 
 ├─ ⏱ 14' 844ms       📋 10950 📄 10    🛠️ 105   🖥️ 21    ⚖  0 116 22552 2021 24572 
 ├─ ⏱ 15' 948ms       📋 11444 📄 13    🛠️ 60    🖥️ 5     ⚖  1 5785 1000004 165040 1165043 
 ├─ ⏱ 16' 1" 36ms     📋 11930 📄 16    🛠️ 12    🖥️ 23    ⚖  2 7266 1000002 165104 1165105 
 ├─ 📑  Ficheiro Resultados/damasci_2.csv gravado.
 │  ⏱  Tempo real: 16' 17" 581ms 
 │  ⏱  CPU total: 12h 45' 46" 314ms 
 │  ⏱  Espera do gestor: 16' 17" 326ms 
 │  ⏱  Espera trabalhadores: 3' 35" 288ms 
 │  📊  Utilização:
 │  - Total: 97.5%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.5% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 16' 17" 581ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P6=</span>5
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P6=</span>5
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P6=</span>5
 │ ...
 ├─ ⚙  [1198] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P6=</span>200
 ├─ ⚙  [1199] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P6=</span>200
 ├─ ⚙  [1200] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P6=</span>200
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

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>50 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P6=</span>5
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P6=</span>5
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P6=</span>5
 │ ...
 ├─ ⚙  [118] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P6=</span>200
 ├─ ⚙  [119] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P6=</span>200
 ├─ ⚙  [120] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P6=</span>200
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
</pre>
</details>
\endhtmlonly

### Resultados: damasci_2

| P6(População) | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 5 | 24 | 5815 | 5649 | 5981 | 867 | 6384 | 8791 |
| 10 | 65 | 4301 | 4057 | 4545 | 141 | 2643 | 9733 |
| 15 | 89 | 2674 | 2466 | 2882 | 104 | 954 | 10000 |
| 20 | 97 | **1840** | 1690 | 1989 | 102 | 815 | 5339 |
| 25 | 96 | 2031 | 1867 | 2195 | 122 | 859 | 6386 |
| 30 | 96 | 2272 | 2100 | 2444 | 118 | 1059 | 6860 |
| 40 | 92 | 2642 | 2450 | 2834 | 108 | 1331 | 8919 |
| 50 | 88 | 3209 | 2995 | 3422 | 125 | 1673 | 10000 |
| 75 | 74 | 4336 | 4088 | 4583 | 217 | 2590 | 10001 |
| 100 | 66 | 4960 | 4699 | 5221 | 172 | 3747 | 10001 |
| 150 | 56 | 5728 | 5464 | 5992 | 270 | 6393 | 10002 |
| 200 | 53 | 5973 | 5710 | 6236 | 418 | 8336 | 10003 |


Podemos observar que a população a 20, o valor por omissão, é nesta codificação o valor com melhores resultados.
O intervalo de confiança a 95% no valor 20 intersecta o de 25, mas é claramente melhor que todos os restantes valores.
Tem também claramente o melhor valor para o percentil de 90%.
O valor 10 ou inferior, e 40 ou superior, aparenta danificar consideravelmente a eficácia e a eficiência.

Mantemos o valor por omissão P6=20.

### Resultados: damascp_2

| P6(População) | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 5 | 91 | 1287 | 1155 | 1420 | 8 | 165 | 6077 |
| 10 | 98 | **826** | 722 | 929 | 7 | 109 | 2424 |
| 15 | 97 | 1148 | 1011 | 1286 | 10 | 190 | 3786 |
| 20 | 98 | 1138 | 1004 | 1272 | 14 | 219 | 3405 |
| 25 | 97 | 1389 | 1237 | 1540 | 14 | 257 | 4624 |
| 30 | 97 | 1360 | 1216 | 1505 | 15 | 281 | 4323 |
| 40 | 96 | 1582 | 1419 | 1744 | 21 | 336 | 5556 |
| 50 | 95 | 1752 | 1581 | 1924 | 21 | 435 | 6119 |
| 75 | 92 | 2201 | 2007 | 2395 | 25 | 605 | 8061 |
| 100 | 88 | 2557 | 2345 | 2769 | 27 | 723 | 10000 |
| 150 | 83 | 3051 | 2815 | 3286 | 27 | 891 | 10001 |
| 200 | 81 | 3271 | 3028 | 3513 | 35 | 1046 | 10001 |

Na codificação permutação das 8 damas, ao contrário da codificação inteira, o valor da população mais eficiente é 10.
O intervalo de confiança nem intersecta qualquer um dos restantes valores.
O percentil de 90% é claramente o melhor.
Esta codificação no entanto não é tão sensivel a este parâmetro como a codificação inteira, mantendo no geral bons valores 
na eficácia e eficiência.

Vamos alterar o valor por omissão para P6=10.

### Resultados: particaocb_2

| P6(População) | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 5 | 73 | 5307 | 4601 | 6014 | 786 | 4227 | 10000 |
| 10 | 93 | 3510 | 2905 | 4115 | 356 | 2487 | 9165 |
| 15 | 94 | 3186 | 2648 | 3723 | 396 | 2674 | 6723 |
| 20 | 100 | 4528 | 3997 | 5059 | 898 | 4752 | 8365 |
| 25 | 91 | 4528 | 3937 | 5118 | 1130 | 4063 | 9560 |
| 30 | 94 | 3417 | 2831 | 4002 | 442 | 2514 | 8439 |
| 40 | 86 | 4433 | 3792 | 5075 | 873 | 3583 | 10001 |
| 50 | 92 | 3960 | 3419 | 4502 | 655 | 3366 | 7933 |
| 75 | 80 | 5487 | 4866 | 6108 | 1682 | 5343 | 10004 |
| 100 | 75 | 5850 | 5184 | 6517 | 1347 | 5569 | 10006 |
| 150 | 61 | 7522 | 6999 | 8045 | 3414 | 8132 | 10012 |
| 200 | 49 | 7553 | 6959 | 8147 | 3073 | 10001 | 10023 |

O parâmetro P6(População) tem a eficácia a 100% apenas no valor por omissão 20.
No entanto existem valores com melhor eficiência.
Não se vê no entanto uma tendência clara, apenas uma zona que aparenta ser melhor, entre 10 e 50 elementos,
em que o tempo médio é inferior a 5 segundos. Os intervalos de confiança intersectam-se quase todos.
Assim, considera-se que este parâmetro não é crítico, e pelo menos na
configuração atual dos restantes parâmetros não há um claro valor melhor,
pelo que optou-se por manter o valor por omissão: P6=20.

## Teste 3

Vamos agora estudar a probabilidade de cruzamento e mutação, parâmetros P7 e P8, com os valores por omissão de 100 e 50 respetivamente.
Estes dois parâmetros são estudados em conjunto, já que se não existir cruzamento torna-se crítica a mutação, e vice-versa.
Existem estratégias que funcionam só com mutação ou só com cruzamento. Os operadores utilizados poderiam ser alvo de estudo,
mas de momento vamos manter os operadores por omissão e estudar apenas a probabilidade de aplicação.

- **Tipo de Teste / Objetivo**: Paramétrico (P7 vs P8)
- **Definição**:
	- **ci**: Instâncias: 10:19; Configurações: P6=20 P7=0:100:25 x P8=0:100:25
	- **cp**: Instâncias: 10:19; Configurações: P6=10 P7=0:100:25 x P8=0:100:25
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0:100:25 x P8=0:100:25
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 10:19 -R Resultados/damasci_3 -M 1 -P P2=2 P6=20 P3=1:100 x P7=0:100:25 x P8=0:100:25
	- **cp**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_3 -M 1 -P P2=2 P6=10 P3=1:100 x P7=0:100:25 x P8=0:100:25
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_3 -M 1 -P P2=2 P6=20 P3=1:10 x P7=0:100:25 x P8=0:100:25

\htmlonly
<details>
  <summary>Ver script: evolutivos3.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos3
#SBATCH --output=Resultados/evolutivos3.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_3
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_3 -M 1 -P P2=2 P6=20 P3=1:100 x P7=0:100:25 x P8=0:100:25
# Teste: damascp_3
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_3 -M 1 -P P2=2 P6=10 P3=1:100 x P7=0:100:25 x P8=0:100:25
# Teste: particaocb_3
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_3 -M 1 -P P2=2 P6=20 P3=1:10 x P7=0:100:25 x P8=0:100:25
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1
 ├─ ⚙   ─ <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 │ ...
 ├─ ⚙  [2498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [2499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [2500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:25000   📄 Instâncias: 10   🛠️ Configurações: 2500   🖥️ Processos: 48.
 ├─ ⏱ 1' 28ms         📋 889   📄 13    🛠️ 2413  🖥️ 5     ⚖  0 2043 222418 10576 232993 
 ├─ ⏱ 2' 76ms         📋 1703  📄 17    🛠️ 2343  🖥️ 27    ⚖  1 10000 817038 38857 855894 
 ├─ ⏱ 3' 83ms         📋 2507  📄 14    🛠️ 2251  🖥️ 23    ⚖  0 1218 124813 5926 130738 
 ├─ ⏱ 4' 149ms        📋 3275  📄 13    🛠️ 2174  🖥️ 1     ⚖  0 1301 146932 6970 153901 
 ├─ ⏱ 5' 185ms        📋 4011  📄 13    🛠️ 2102  🖥️ 8     ⚖  0 2032 229520 10889 240408 
 ├─ ⏱ 6' 340ms        📋 4750  📄 18    🛠️ 2033  🖥️ 23    ⚖  0 8248 653587 31021 684607 
 ├─ ⏱ 7' 348ms        📋 5682  📄 19    🛠️ 1937  🖥️ 24    ⚖  0 3537 253298 12019 265316 
 ├─ ⏱ 8' 441ms        📋 6639  📄 18    🛠️ 1850  🖥️ 2     ⚖  1 10000 780185 36992 817176 
 ├─ ⏱ 9' 768ms        📋 7466  📄 17    🛠️ 1753  🖥️ 44    ⚖  0 578 48667 2304 50970 
 ├─ ⏱ 10' 778ms       📋 8225  📄 13    🛠️ 1682  🖥️ 6     ⚖  0 2951 340133 16059 356191 
 ├─ ⏱ 11' 995ms       📋 8888  📄 13    🛠️ 1611  🖥️ 36    ⚖  0 774 89346 4215 93560 
 ├─ ⏱ 12' 1" 22ms     📋 9486  📄 19    🛠️ 1559  🖥️ 32    ⚖  0 9075 679259 32026 711284 
 ├─ ⏱ 13' 1" 22ms     📋 10177 📄 13    🛠️ 1482  🖥️ 1     ⚖  0 9 1078 50 1127 
 ├─ ⏱ 14' 1" 86ms     📋 11526 📄 14    🛠️ 1348  🖥️ 27    ⚖  0 679 71741 3368 75108 
 ├─ ⏱ 15' 1" 164ms    📋 12497 📄 12    🛠️ 1251  🖥️ 10    ⚖  0 1179 148732 6957 155688 
 ├─ ⏱ 16' 1" 209ms    📋 13264 📄 19    🛠️ 1183  🖥️ 1     ⚖  1 10000 769816 35847 805662 
 ├─ ⏱ 17' 1" 282ms    📋 13944 📄 12    🛠️ 1108  🖥️ 12    ⚖  0 2432 315866 14685 330550 
 ├─ ⏱ 18' 1" 294ms    📋 14449 📄 11    🛠️ 1055  🖥️ 35    ⚖  0 46 6695 307 7001 
 ├─ ⏱ 19' 1" 327ms    📋 14942 📄 16    🛠️ 1013  🖥️ 13    ⚖  1 10000 960370 44370 1004739 
 ├─ ⏱ 20' 1" 333ms    📋 16557 📄 13    🛠️ 848   🖥️ 18    ⚖  0 1669 198531 9157 207687 
 ├─ ⏱ 21' 1" 352ms    📋 17723 📄 17    🛠️ 728   🖥️ 25    ⚖  0 406 36264 1665 37928 
 ├─ ⏱ 22' 1" 385ms    📋 18446 📄 13    🛠️ 656   🖥️ 20    ⚖  0 1023 127514 5785 133298 
 ├─ ⏱ 23' 1" 429ms    📋 19034 📄 18    🛠️ 605   🖥️ 41    ⚖  1 10000 852515 38721 891235 
 ├─ ⏱ 24' 1" 443ms    📋 19434 📄 15    🛠️ 562   🖥️ 8     ⚖  1 9102 1000019 44698 1044716 
 ├─ ⏱ 25' 1" 493ms    📋 19835 📄 15    🛠️ 522   🖥️ 27    ⚖  1 9080 1000005 44711 1044715 
 ├─ ⏱ 26' 1" 551ms    📋 21163 📄 16    🛠️ 386   🖥️ 26    ⚖  0 1062 105705 4754 110458 
 ├─ ⏱ 27' 1" 587ms    📋 22332 📄 13    🛠️ 270   🖥️ 20    ⚖  0 2908 370317 16531 386847 
 ├─ ⏱ 28' 1" 605ms    📋 23044 📄 14    🛠️ 202   🖥️ 32    ⚖  0 8443 996097 44469 1040565 
 ├─ ⏱ 29' 1" 891ms    📋 23424 📄 15    🛠️ 160   🖥️ 41    ⚖  0 4840 544514 24042 568555 
 ├─ ⏱ 30' 2" 151ms    📋 23820 📄 10    🛠️ 119   🖥️ 20    ⚖  0 2319 390676 17246 407921 
 ├─ ⏱ 31' 2" 158ms    📋 24189 📄 19    🛠️ 86    🖥️ 47    ⚖  8 10000 882900 37781 920680 
 ├─ ⏱ 32' 2" 265ms    📋 24538 📄 13    🛠️ 50    🖥️ 18    ⚖  3 7216 1000002 42794 1042795 
 ├─ ⏱ 33' 2" 339ms    📋 24889 📄 17    🛠️ 16    🖥️ 19    ⚖  5 9841 1000019 42810 1042828 
 ├─ 📑  Ficheiro Resultados/damasci_3.csv gravado.
 │  ⏱  Tempo real: 33' 30" 97ms 
 │  ⏱  CPU total: 1d 2h 14' 34" 540ms 
 │  ⏱  Espera do gestor: 33' 29" 569ms 
 │  ⏱  Espera trabalhadores: 3' 29" 152ms 
 │  📊  Utilização:
 │  - Total: 97.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 33' 30" 97ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1
 ├─ ⚙   ─ <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 │ ...
 ├─ ⚙  [2498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [2499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [2500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:25000   📄 Instâncias: 10   🛠️ Configurações: 2500   🖥️ Processos: 48.
 ├─ ⏱ 1' 104ms        📋 6456  📄 15    🛠️ 1856  🖥️ 45    ⚖  0 563 86598 7857 94454 
 ├─ ⏱ 2' 113ms        📋 10547 📄 16    🛠️ 1445  🖥️ 1     ⚖  0 134 18923 1714 20636 
 ├─ ⏱ 3' 115ms        📋 13113 📄 13    🛠️ 1189  🖥️ 29    ⚖  0 117 22293 1988 24280 
 ├─ ⏱ 4' 123ms        📋 15586 📄 16    🛠️ 941   🖥️ 8     ⚖  0 117 16620 1500 18119 
 ├─ ⏱ 5' 178ms        📋 17733 📄 15    🛠️ 727   🖥️ 30    ⚖  0 502 82422 7327 89748 
 ├─ ⏱ 6' 180ms        📋 19281 📄 13    🛠️ 572   🖥️ 29    ⚖  0 377 78370 6727 85096 
 ├─ ⏱ 7' 193ms        📋 21522 📄 14    🛠️ 353   🖥️ 35    ⚖  0 1526 257932 22953 280884 
 ├─ ⏱ 8' 310ms        📋 23016 📄 17    🛠️ 201   🖥️ 4     ⚖  0 1850 275558 24150 299707 
 ├─ ⏱ 9' 440ms        📋 24048 📄 17    🛠️ 103   🖥️ 35    ⚖  1 6430 1000003 85486 1085488 
 ├─ ⏱ 10' 499ms       📋 24841 📄 11    🛠️ 16    🖥️ 19    ⚖  0 180 44295 3664 47958 
 ├─ 📑  Ficheiro Resultados/damascp_3.csv gravado.
 │  ⏱  Tempo real: 10' 18" 807ms 
 │  ⏱  CPU total: 8h 4' 43" 915ms 
 │  ⏱  Espera do gestor: 10' 18" 309ms 
 │  ⏱  Espera trabalhadores: 2' 45" 830ms 
 │  📊  Utilização:
 │  - Total: 97.4%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 10' 18" 807ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1
 ├─ ⚙   ─ <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>0
 │ ...
 ├─ ⚙  [248] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [249] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
 ├─ ⚙  [250] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>100
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
</pre>
</details>
\endhtmlonly

### Resultados: damasci_3

Eficiência

| P7 vs P8 | 0 | 25 | 50 | 75 | 100 | 
|:---:|---:|---:|---:|---:|---:|
| 0 | 8072 | 7043 | 5680 | 4749 | 3835 | 
| 25 | 7293 | 4677 | 4256 | 4224 | 3840 |
| 50 | 3814 | 2814 | 3363 | 3653 | 3578 |
| 75 | 1854 | 1837 | 2507 | 3153 | 3452 |
| 100 | **1332** | 1465 | 1841 | 2673 | 3372 |

A configuração que aparenta ser a melhor, é com P7=100 e P8=0, ou seja, sem mutação.
Assim o valor original de P8=50 não é o melhor para a atual configuração.
Colocar este parâmetro a 0 reduz a diversidade, mas não elimina, atendendo a que existe um elemento estrangeiro em cada geração
que constantemente insere diversidade na população.

Assim sendo vamos manter o valor de P7=100 e alterar P8=0.

### Resultados: damascp_3

Eficiência

| P7 vs P8 | 0 | 25 | 50 | 75 | 100 | 
|:---:|---:|---:|---:|---:|---:|
| 0 | 3574 | 1999 | 1225 | 545 | **175** | 
| 25 | 2695 | 1843 | 1287 | 641 | 229 |
| 50 | 2062 | 1628 | 1212 | 771 | 295 |
| 75 | 1417 | 1313 | 1091 | 846 | 406 |
| 100 | 699 | 734 | 825 | 801 | 621 | 

Estes resultados apontam para a melhor parametrização a colocação de P7=0 e P8=100, o inverso da codificação inteira.
Com esta estratégia os operadores de cruzamento nem são utilizados.

Vamos portanto alterar os valores para P7=0 e P8=100.
O tempo médio de resolução está bastante baixo, 0,17 segundos, quase 10 vezes menos que a codificação inteira.
No entanto vamos manter o conjunto de instâncias de teste para manter a eficiência comparável com os restantes testes
e com a codificação inteira.

### Resultados: particaocb_3

| P7 vs P8 | 0 | 25 | 50 | 75 | 100 | 
|:---:|---:|---:|---:|---:|---:|
| 0 | 9994 | 6911 | 4902 | 3660 | **2742** | 
| 25 | 9788 | 7188 | 4779 | 3370 | 3288 |
| 50 | 8268 | 5411 | 4109 | 3166 | 3301 |
| 75 | 6097 | 4487 | 4106 | 4365 | 4213 |
| 100 | 3833 | 4069 | 4528 | 3993 | 4731 |

A melhor parametrização é tal como nas 8 damas com a codificação de permutação, P7=0 e P8=100,
o que significa que o cruzamento nunca é realizado, e é sempre aplicada a mutação.
A diferença é de 4,5 segundos para a configuração de base, baixando para 2,7 segundos, o que é
uma diferença considerável. Assim vamos mudar a configuração base para P7=0 e P8=100.

## Teste 4

Analisamos agora P9(SELECAO). Este parâmetro escolhe a estratégia de seleção de pais.

Existem três valores:
- 1: Roleta (valor por omissão)
- 2: Torneio
- 3: Uniforme

A roleta tem um parâmetro, o torneio tem dois, e o uniforme não tem parâmetros.
Neste teste usamos os parâmetros internos por omissão para apurar se há diferenças significativas na estratégia de seleção dos pais.
Caso existam, cada método deve ser otimizado separadamente, variando os seus parâmetros internos, de modo a poder
comparar a melhor versão de cada uma das estratégias de seleção dos pais. 

- **Tipo de Teste / Objetivo**: Paramétrico P9
- **Definição**:
	- **ci**: Instâncias: 10:19; Configurações: P6=20 P7=100 P8=0 P9=1:3
	- **cp**: Instâncias: 10:19; Configurações: P6=10 P7=0 P8=100 P9=1:3
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=1:3
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 10:19 -R Resultados/damasci_4 -M 1 -P P2=2 P6=20 P7=100 P8=0 P3=1:100 x P9=1:3
	- **cp**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_4 -M 1 -P P2=2 P6=10 P7=0 P8=100 P3=1:100 x P9=1:3
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_4 -M 1 -P P2=2 P6=20 P7=0 P8=100 P3=1:10 x P9=1:3

\htmlonly
<details>
  <summary>Ver script: evolutivos4.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos4
#SBATCH --output=Resultados/evolutivos4.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_4
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_4 -M 1 -P P2=2 P6=20 P7=100 P8=0 P3=1:100 x P9=1:3
# Teste: damascp_4
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_4 -M 1 -P P2=2 P6=10 P7=0 P8=100 P3=1:100 x P9=1:3
# Teste: particaocb_4
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_4 -M 1 -P P2=2 P6=20 P7=0 P8=100 P3=1:10 x P9=1:3
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P9=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P9=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P9=</span>1
 │ ...
 ├─ ⚙  [298] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P9=</span>3
 ├─ ⚙  [299] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P9=</span>3
 ├─ ⚙  [300] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P9=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3000   📄 Instâncias: 10   🛠️ Configurações: 300   🖥️ Processos: 48.
 ├─ ⏱ 1' 20ms         📋 405   📄 17    🛠️ 265   🖥️ 37    ⚖  2 10000 915482 41837 957318 
 ├─ ⏱ 2' 200ms        📋 791   📄 10    🛠️ 221   🖥️ 13    ⚖  0 453 74607 3372 77978 
 ├─ ⏱ 3' 278ms        📋 1571  📄 10    🛠️ 143   🖥️ 16    ⚖  0 116 19944 817 20760 
 ├─ 📑  Ficheiro Resultados/damasci_4.csv gravado.
 │  ⏱  Tempo real: 3' 57" 711ms 
 │  ⏱  CPU total: 3h 6' 12" 401ms 
 │  ⏱  Espera do gestor: 3' 57" 647ms 
 │  ⏱  Espera trabalhadores: 5' 12" 742ms 
 │  📊  Utilização:
 │  - Total: 95.2%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 97.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 3' 57" 711ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P9=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P9=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P9=</span>1
 │ ...
 ├─ ⚙  [298] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P9=</span>3
 ├─ ⚙  [299] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P9=</span>3
 ├─ ⚙  [300] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P9=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3000   📄 Instâncias: 10   🛠️ Configurações: 300   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/damascp_4.csv gravado.
 │  ⏱  Tempo real: 15" 161ms 
 │  ⏱  CPU total: 11' 52" 555ms 
 │  ⏱  Espera do gestor: 15" 100ms 
 │  ⏱  Espera trabalhadores: 1' 19" 645ms 
 │  📊  Utilização:
 │  - Total: 86.9%
 │  - Gestor: 0.2%
 │  - Trabalhadores: 88.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 15" 161ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P10=</span>150 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P9=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P9=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P9=</span>1
 │ ...
 ├─ ⚙  [28] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P9=</span>3
 ├─ ⚙  [29] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P9=</span>3
 ├─ ⚙  [30] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P9=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:300   📄 Instâncias: 10   🛠️ Configurações: 30   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/particaocb_4.csv gravado.
 │  ⏱  Tempo real: 27" 370ms 
 │  ⏱  CPU total: 21' 26" 379ms 
 │  ⏱  Espera do gestor: 27" 362ms 
 │  ⏱  Espera trabalhadores: 5' 52" 712ms 
 │  📊  Utilização:
 │  - Total: 71.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 72.6% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 27" 370ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_4

| P9 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 1:Roleta | 99 | **1332** | 1220 | 1443 | 94 | 661 | 3536 |
| 2:Torneio | 94 | 2173 | 1999 | 2348 | 110 | 869 | 6906 |
| 3:Uniforme | 27 | 7363 | 7154 | 7573 | 1123 | 8705 | 10000 |

Podemos observar que é crítica a estratégia de seleção dos pais. O método uniforme é claramente pior e não tem parâmetros,
pelo que descartamos. Pelo intervalo de confiança, com os valores por omissão, o método roleta seria o escolhido.
No entanto os métodos Roleta e Torneio têm parâmetros e precisam de ser explorados para identificar a melhor configuração.


### Resultados: damascp_4

| P9 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 1:Roleta | 100 | 175 | 154 | 196 | 4 | 48 | 454 |
| 2:Torneio | 100 | **115** | 101 | 128 | 3 | 31 | 307 |
| 3:Uniforme | 100 | 342 | 301 | 382 | 6 | 80 | 1029 |

Podemos observar também diferenças grandes entre estratégias de seleção de pais.
Descartamos a seleção uniforme, que não tem parâmetros e tem uma eficiência inferior.
Nas restantes duas estratégias temos de identificar a melhor parametrização, para poder fazer uma escolha informada.

### Resultados: particaocb_4

| P9 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 1:Roleta | 95 | 2742 | 2239 | 3245 | 292 | 2156 | 5882 |
| 2:Torneio | 100 | **2005** | 1646 | 2365 | 241 | 1548 | 4343 |
| 3:Uniforme | 89 | 4589 | 3987 | 5192 | 586 | 4087 | 10000 |

Na partição observamos o mesmo que nas 8 damas em ambas as codificações, que a estratégias de seleção de pais é um passo crítico.
Descartamos a seleção uniforme, que não tem parâmetros e tem uma eficiência inferior.
Nas restantes duas estratégias temos de identificar a melhor parametrização, para poder fazer uma escolha informada.

## Teste 5

Análise dos parâmetros dos métodos de seleção Roleta e Torneio

O método da roleta tem o parâmetro P10(PRESSAO) com o valor por omissão de 150.
Este valor é entre 100 e 200, correspondendo a 1,00 e 2,00 respetivamente.
Este método irá escolher os pais com base no seu valor, cada um ficando com uma dada probabilidade na "roleta".
Valores perto de 1 dão valores quase iguais, e valores perto de 2 os melhores são muito favorecidos.

Vamos testar valores de 100 a 200 em intervalos de 25.

O método torneio seleciona um pai vencedor de um torneio. Faz-se quantos torneios forem necessários,
escolhendo membros da população aleatoriamente para entrarem no torneio.

Tem dois parâmetros:
- P11(TAMANHO_TORNEIO) - valor mínimo 2, podendo ir a valores altos como 100 - valor por omissão 2
- P12(PROB_MELHOR_TORNEIO) - probabilidade do participante com melhor valor, ganhar o torneio - valor por omissão 100%

Torneios grandes favorecem a que os melhores sejam sempre escolhidos, excepto se a probabilidade do melhor ganhar o torneio for baixa.

Vamos variar P11 nos valores baixos, e alguns valores altos: 2,3,4,6,10. Como a população num caso é de 10, aumentar este valor para além da população não faz muito sentido.
Para a probabilidade, vamos deixar de fora o valor 0, caso contrário seria uma escolha completamente aleatória, e variar em intervalos de 25.

Este teste será dividido em dois,um para cada parâmetro.

Teste 5A para o método roleta:

- **Tipo de Teste / Objetivo**: Paramétrico P10
- **Definição**:
	- **ci**: Instâncias: 10:19; Configurações: P6=20 P7=100 P8=0 P9=1 P10=100:200:25
	- **cp**: Instâncias: 10:19; Configurações: P6=10 P7=0 P8=100 P9=1 P10=100:200:25
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=1 P10=100:200:25
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5A -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P3=1:100 x P10=100:200:25
	- **cp**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5A -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=1 P3=1:100 x P10=100:200:25
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5A -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=1 P3=1:10 x P10=100:200:25

Teste 5B para o método torneio:

- **Tipo de Teste / Objetivo**: Paramétrico P11 vs P12
- **Definição**:
	- **ci**: Instâncias: 10:19; Configurações: P6=20 P7=100 P8=0 P9=2 P11=2,3,4,6,10 x P12=25:100:25
	- **cp**: Instâncias: 10:19; Configurações: P6=10 P7=0 P8=100 P9=2 P11=2,3,4,6,10 x P12=25:100:25
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=2,3,4,6,10 x P12=25:100:25
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5B -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
	- **cp**: TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P3=1:10 x P11=2,3,4,6,10 x P12=25:100:25

\htmlonly
<details>
  <summary>Ver script: evolutivos5.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos5
#SBATCH --output=Resultados/evolutivos5.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_5A
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5A -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P3=1:100 x P10=100:200:25
# Teste: damascp_5A
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5A -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=1 P3=1:100 x P10=100:200:25
# Teste: particaocb_5A
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5A -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=1 P3=1:10 x P10=100:200:25
# Teste: damasci_5B
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5B -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
# Teste: damascp_5B
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
# Teste: particaocb_5B
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P3=1:10 x P11=2,3,4,6,10 x P12=25:100:25
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P10=</span>100
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P10=</span>100
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P10=</span>100
 │ ...
 ├─ ⚙  [498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P10=</span>200
 ├─ ⚙  [499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P10=</span>200
 ├─ ⚙  [500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P10=</span>200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:5000   📄 Instâncias: 10   🛠️ Configurações: 500   🖥️ Processos: 48.
 ├─ ⏱ 1' 64ms         📋 2432  📄 11    🛠️ 257   🖥️ 12    ⚖  0 147 21391 970 22360 
 ├─ ⏱ 2' 189ms        📋 3548  📄 12    🛠️ 145   🖥️ 9     ⚖  0 141 18221 850 19070 
 ├─ ⏱ 3' 303ms        📋 4153  📄 19    🛠️ 90    🖥️ 35    ⚖  1 10000 751461 35712 787172 
 ├─ ⏱ 4' 432ms        📋 4551  📄 12    🛠️ 45    🖥️ 46    ⚖  0 669 84603 4015 88617 
 ├─ ⏱ 5' 526ms        📋 4946  📄 13    🛠️ 6     🖥️ 24    ⚖  0 1762 204194 9692 213885 
 ├─ 📑  Ficheiro Resultados/damasci_5A.csv gravado.
 │  ⏱  Tempo real: 5' 18" 143ms 
 │  ⏱  CPU total: 4h 9' 12" 706ms 
 │  ⏱  Espera do gestor: 5' 18" 37ms 
 │  ⏱  Espera trabalhadores: 3' 48" 652ms 
 │  📊  Utilização:
 │  - Total: 96.4%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.5% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 5' 18" 143ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P10=</span>100
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P10=</span>100
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P10=</span>100
 │ ...
 ├─ ⚙  [498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P10=</span>200
 ├─ ⚙  [499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P10=</span>200
 ├─ ⚙  [500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P10=</span>200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:5000   📄 Instâncias: 10   🛠️ Configurações: 500   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/damascp_5A.csv gravado.
 │  ⏱  Tempo real: 24" 923ms 
 │  ⏱  CPU total: 19' 31" 389ms 
 │  ⏱  Espera do gestor: 24" 824ms 
 │  ⏱  Espera trabalhadores: 2' 27" 770ms 
 │  📊  Utilização:
 │  - Total: 85.5%
 │  - Gestor: 0.2%
 │  - Trabalhadores: 87.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 24" 923ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P10=</span>100
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P10=</span>100
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P10=</span>100
 │ ...
 ├─ ⚙  [48] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P10=</span>200
 ├─ ⚙  [49] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P10=</span>200
 ├─ ⚙  [50] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P10=</span>200
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:500   📄 Instâncias: 10   🛠️ Configurações: 50   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/particaocb_5A.csv gravado.
 │  ⏱  Tempo real: 39" 157ms 
 │  ⏱  CPU total: 30' 40" 401ms 
 │  ⏱  Espera do gestor: 39" 146ms 
 │  ⏱  Espera trabalhadores: 4' 15" 19ms 
 │  📊  Utilização:
 │  - Total: 84.3%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 86.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 39" 157ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 │ ...
 ├─ ⚙  [1998] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [1999] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [2000] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:20000   📄 Instâncias: 10   🛠️ Configurações: 2000   🖥️ Processos: 48.
 ├─ ⏱ 1' 13ms         📋 784   📄 18    🛠️ 1922  🖥️ 37    ⚖  0 870 92492 2789 95280 
 ├─ ⏱ 2' 61ms         📋 1846  📄 10    🛠️ 1818  🖥️ 45    ⚖  0 1314 253765 8223 261987 
 ├─ ⏱ 3' 67ms         📋 3747  📄 16    🛠️ 1626  🖥️ 9     ⚖  0 403 45449 1688 47136 
 ├─ ⏱ 4' 132ms        📋 5106  📄 11    🛠️ 1496  🖥️ 32    ⚖  0 5201 857443 26618 884060 
 ├─ ⏱ 5' 170ms        📋 5995  📄 12    🛠️ 1401  🖥️ 20    ⚖  0 840 129003 4007 133009 
 ├─ ⏱ 6' 184ms        📋 7821  📄 16    🛠️ 1220  🖥️ 32    ⚖  0 1112 125096 4637 129732 
 ├─ ⏱ 7' 231ms        📋 9195  📄 19    🛠️ 1088  🖥️ 25    ⚖  2 10000 797933 35284 833216 
 ├─ ⏱ 8' 306ms        📋 9738  📄 19    🛠️ 1034  🖥️ 38    ⚖  1 10000 796720 35251 831970 
 ├─ ⏱ 9' 340ms        📋 10500 📄 10    🛠️ 955   🖥️ 14    ⚖  0 2360 411612 13109 424720 
 ├─ ⏱ 10' 350ms       📋 11852 📄 14    🛠️ 819   🖥️ 43    ⚖  0 1662 217662 7668 225329 
 ├─ ⏱ 11' 523ms       📋 13234 📄 19    🛠️ 688   🖥️ 24    ⚖  1 10000 808693 34356 843048 
 ├─ ⏱ 12' 612ms       📋 13953 📄 10    🛠️ 605   🖥️ 14    ⚖  0 410 64191 2726 66916 
 ├─ ⏱ 13' 668ms       📋 14355 📄 17    🛠️ 570   🖥️ 17    ⚖  1 10000 881815 40299 922113 
 ├─ ⏱ 14' 878ms       📋 14732 📄 11    🛠️ 528   🖥️ 34    ⚖  0 2373 330816 14996 345811 
 ├─ ⏱ 15' 1" 69ms     📋 15256 📄 18    🛠️ 481   🖥️ 26    ⚖  0 4653 469851 15199 485049 
 ├─ ⏱ 16' 1" 88ms     📋 16405 📄 12    🛠️ 360   🖥️ 1     ⚖  0 202 29954 1092 31045 
 ├─ ⏱ 17' 1" 111ms    📋 17389 📄 10    🛠️ 262   🖥️ 47    ⚖  0 757 119457 4946 124402 
 ├─ ⏱ 18' 1" 132ms    📋 18021 📄 10    🛠️ 198   🖥️ 10    ⚖  0 123 18199 805 19003 
 ├─ ⏱ 19' 1" 226ms    📋 18410 📄 13    🛠️ 164   🖥️ 20    ⚖  1 8607 1000010 44552 1044561 
 ├─ ⏱ 20' 1" 391ms    📋 18791 📄 14    🛠️ 126   🖥️ 5     ⚖  1 9235 1000018 44591 1044608 
 ├─ ⏱ 21' 1" 554ms    📋 19148 📄 12    🛠️ 89    🖥️ 30    ⚖  1 7694 1000001 44900 1044900 
 ├─ ⏱ 22' 1" 648ms    📋 19489 📄 12    🛠️ 55    🖥️ 30    ⚖  1 7716 1000006 44925 1044930 
 ├─ ⏱ 23' 1" 779ms    📋 19829 📄 17    🛠️ 22    🖥️ 24    ⚖  2 10000 889921 40213 930133 
 ├─ 📑  Ficheiro Resultados/damasci_5B.csv gravado.
 │  ⏱  Tempo real: 23' 42" 70ms 
 │  ⏱  CPU total: 18h 33' 57" 305ms 
 │  ⏱  Espera do gestor: 23' 41" 649ms 
 │  ⏱  Espera trabalhadores: 3' 37" 426ms 
 │  📊  Utilização:
 │  - Total: 97.6%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.7% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 23' 42" 70ms ) ═══

═╤═ Instâncias ═══ { 📄 10 📄 11 📄 12 📄 13 📄 14 📄 15 📄 16 📄 17 📄 18 📄 19 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 │ ...
 ├─ ⚙  [1998] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [1999] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [2000] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:20000   📄 Instâncias: 10   🛠️ Configurações: 2000   🖥️ Processos: 48.
 ├─ ⏱ 1' 10ms         📋 19939 📄 16    🛠️ 9     🖥️ 46    ⚖  0 610 94439 8566 103004 
 ├─ 📑  Ficheiro Resultados/damascp_5B.csv gravado.
 │  ⏱  Tempo real: 1' 8" 423ms 
 │  ⏱  CPU total: 53' 35" 900ms 
 │  ⏱  Espera do gestor: 1' 8" 38ms 
 │  ⏱  Espera trabalhadores: 4' 41" 217ms 
 │  📊  Utilização:
 │  - Total: 89.3%
 │  - Gestor: 0.2%
 │  - Trabalhadores: 91.2% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 1' 8" 423ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P11=</span>2 <span style="color:gray">P12=</span>25
 │ ...
 ├─ ⚙  [198] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [199] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
 ├─ ⚙  [200] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:2000   📄 Instâncias: 10   🛠️ Configurações: 200   🖥️ Processos: 48.
 ├─ ⏱ 1' 31ms         📋 1059  📄 930   🛠️ 103   🖥️ 38    ⚖  0 6572 76215 3627 79841 
 ├─ ⏱ 2' 354ms        📋 1932  📄 926   🛠️ 19    🖥️ 44    ⚖  2 10001 116012 5521 121532 
 ├─ 📑  Ficheiro Resultados/particaocb_5B.csv gravado.
 │  ⏱  Tempo real: 2' 24" 241ms 
 │  ⏱  CPU total: 1h 52' 59" 336ms 
 │  ⏱  Espera do gestor: 2' 24" 200ms 
 │  ⏱  Espera trabalhadores: 4' 23" 250ms 
 │  📊  Utilização:
 │  - Total: 94.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 96.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 2' 24" 241ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_5

Resultados para roleta:

| P10 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 100 | 35 | 7190 | 6962 | 7419 | 768 | 9357 | 10000 |
| 125 | 79 | 3867 | 3627 | 4106 | 136 | 2120 | 10000 |
| 150 | 99 | 1330 | 1219 | 1442 | 94 | 661 | 3557 |
| 175 | 100 | **1057** | 972 | 1141 | 74 | 540 | 2695 |
| 200 | 99 | 1282 | 1176 | 1389 | 81 | 699 | 3109 |

O melhor valor para P10 na roleta é 175. O intervalo de confiança não intersecta os restantes valores,
o que significa que uma valorização ainda maior dos melhores é preferivel. O percentil de 90% é claramente inferior.

Resultados para torneio:

| P11 vs P12 | 100 | 75 | 50 | 25 | 
|:---:|---:|---:|---:|---:|
| 2 | 2171 | 5102 | 7567 | 8406 | 
| 3 | **1315** | 1679 | 3938 | 7385 | 
| 4 | 1496 | 1360 | 1750 | 4450 | 
| 6 | 2311 | 1637 | 1618 | 1929 | 
| 10 | 3794 | 3209 | 2930 | 2723 | 

A melhor configuração é com P11=3, melhorando claramente relativamente ao torneio de 2.
Para valores de torneio pequenos, P12 é melhor sempre com o valor por omissão a 100%.
Apenas para torneios grandes é que P12 é melhor com valores menores, mas em termos globais
a melhor configuração é com P11=3 e P12=100.

Conjugando a roleta com o torneio, opta-se pela roleta dado que aprensenta valores melhores,
com os seguintes parâmetros: P9=1 P10=175.

### Resultados: damascp_5

Resultados para roleta:

| P10 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 100 | 100 | 379 | 328 | 430 | 7 | 85 | 974 |
| 125 | 100 | 228 | 202 | 254 | 6 | 71 | 658 |
| 150 | 100 | 175 | 154 | 196 | 4 | 48 | 452 |
| 175 | 100 | 138 | 123 | 154 | 3 | 36 | 386 |
| 200 | 100 | **101** | 90 | 112 | 3 | 31 | 274 |

Com a estratégia de mutação a 100%, o melhor valor para P10 na roleta é claramente o 200, dando importância máxima aos melhores.
O intervalo de confiança não intersecta os restantes valores.

Resultados para o torneio:

| P11 vs P12 | 100 | 75 | 50 | 25 | 
|:---:|---:|---:|---:|---:|
| 2 | 114 | 180 | 344 | 705 | 
| 3 | 76 | 118 | 169 | 355 | 
| 4 | 62 | 77 | 110 | 162 | 
| 6 | 48 | 50 | 72 | 96 | 
| 10 | **41** | 45 | 48 | 54 | 

Estes resultados voltam a surpreender ou talvez não, atendendo à estratégia da mutação a 100%.
Um torneio grande com probabilidade do melhor ganhar leva a que quase sempre o melhor seja escolhido.

Entre a roleta e o torneio, continua o torneio nesta nova parametrização a ser claramente melhor.
Assim sendo escolhe-se o torneio com os seguintes parâmetros: P9=2 P11=10 P12=100

### Resultados: particaocb_5

Resultados para roleta:

| P10 | Eficácia | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|---:|
| 100 | 81 | 5045 | 4359 | 5730 | 730 | 4521 | 10001 |
| 125 | 92 | 3195 | 2614 | 3777 | 437 | 2064 | 8099 |
| 150 | 95 | 2741 | 2238 | 3244 | 291 | 2155 | 5882 |
| 175 | 96 | 2519 | 2030 | 3009 | 230 | 1727 | 6060 |
| 200 | 99 | **2354** | 1922 | 2785 | 416 | 1580 | 5303 |

Temos neste caso o melhor valor para P10 também no 200, provavelmente pela mesma razão de ser utilizada a estratégia de mutação a 100%.
No entanto aqui o intervalo de confiança do melhor valor intersecta vários outros, pelo que não há grande certeza.

Resultados para o torneio:

| P11 vs P12 | 100 | 75 | 50 | 25 | 
|:---:|---:|---:|---:|---:|
| 2 | 2005 | 2899 | 4959 | 8776 | 
| 3 | 2177 | 2117 | 2179 | 3467 | 
| 4 | **1862** | 1960 | 2334 | 2514 | 
| 6 | 3177 | 2411 | 2875 | 2942 | 
| 10 | 4825 | 3989 | 3731 | 4018 | 

Temos aqui um novo ganho relativamente à parametrização de base. O torneio de tamanho 4 reduz o tempo de forma visivel,
relativamente ao torneio de tamanho 2. A probabilidade de escolher o melhor mantém-se como melhor opção o 100%.

Assim sendo, entre a roleta e o torneio, é preferivel o torneio, com os parâmetros: P9=2 P11=4 P12=100

## Teste 6

Passamos para a fase da sobrevivência, em que o parâmetro base é P13. Existem 3 valores possíveis:
- 1: Idade (valor por omissão)
- 2: Substitui piores
- 3: round-robin

Este parâmetro é utilizado em conjunção com o P14(PERC_DESCENDENTES), cujo valor por omissão é 100%.
Neste caso os descendentes são iguais à população, pelo que no método da idade são todos substituídos.

Nos restantes dois métodos, qualquer que seja a percentagem, os decendentes são adicionados à população e
no segundo caso são removidos os piores, no terceiro round-robin existe um torneio de cada elemento com Q outros.
Os que perderem mais vezes, são removidos.

O método round-robin tem portanto um parâmetro Q, que é o número de torneios:  P15(Q_ROUND_ROBIN).
Tem o valor por omissão a 3, mas pode ser desde 2 até um valor alto como 100, mas não fará sentido ser superior à população.

Vamos para já deixar este valor por omissão, e fazer um teste com P13 e P14, para apurar se a
estratégia de sobrevivência é muito relevante ou não, e se a percentagem de descendentes é ou não relevante.

Vamos variar P14 de 0 a 100 em passos de 25, tal como temos feito para as restantes percentagens.
Quando P14=0 significa que haverá apenas um só descendente (e não 0) em cada geração.

Vamos ainda alterar o conjunto de teste das 8 damas, atendendo a que os tempos de resolução são demasiado baixos
para a codificação de permutação, com tempos médios abaixo de 0,05 segundos. Escolhemos as instâncias seguintes,
de 20 a 29.

- **Tipo de Teste / Objetivo**: Paramétrico P13 vs P14
- **Definição**:
	- **ci**: Instâncias: 20:29; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1:3 x P14=0:100:25
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=1:3 x P14=0:100:25
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1:3 x P14=0:100:25
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 20:29 -R Resultados/damasci_6 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P3=1:100 x P13=1:3 x P14=0:100:25
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_6 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P3=1:100 x P13=1:3 x P14=0:100:25
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_6 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P3=1:10 x P13=1:3 x P14=0:100:25

\htmlonly
<details>
  <summary>Ver script: evolutivos6.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos6
#SBATCH --output=Resultados/evolutivos6.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_6
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_6 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P3=1:100 x P13=1:3 x P14=0:100:25
# Teste: damascp_6
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_6 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P3=1:100 x P13=1:3 x P14=0:100:25
# Teste: particaocb_6
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_6 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P3=1:10 x P13=1:3 x P14=0:100:25
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1
 ├─ ⚙   ─ <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 │ ...
 ├─ ⚙  [1498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [1499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [1500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:15000   📄 Instâncias: 10   🛠️ Configurações: 1500   🖥️ Processos: 48.
 ├─ ⏱ 1' 361ms        📋 388   📄 23    🛠️ 1467  🖥️ 12    ⚖  1 10000 758450 27578 786027 
 ├─ ⏱ 2' 393ms        📋 739   📄 26    🛠️ 1428  🖥️ 41    ⚖  0 3966 249027 8968 257994 
 ├─ ⏱ 3' 412ms        📋 1081  📄 25    🛠️ 1396  🖥️ 30    ⚖  2 10000 717712 24807 742518 
 ├─ ⏱ 4' 1" 386ms     📋 1379  📄 21    🛠️ 1365  🖥️ 23    ⚖  0 6559 609524 21063 630586 
 ├─ ⏱ 5' 1" 397ms     📋 1670  📄 26    🛠️ 1337  🖥️ 7     ⚖  3 10000 678700 23451 702150 
 ├─ ⏱ 6' 1" 660ms     📋 1963  📄 21    🛠️ 1306  🖥️ 3     ⚖  0 5790 536931 18491 555421 
 ├─ ⏱ 7' 1" 801ms     📋 2410  📄 24    🛠️ 1260  🖥️ 27    ⚖  0 2040 125002 5418 130419 
 ├─ ⏱ 8' 1" 951ms     📋 2894  📄 23    🛠️ 1214  🖥️ 22    ⚖  0 4768 308081 13362 321442 
 ├─ ⏱ 9' 2" 342ms     📋 3267  📄 27    🛠️ 1178  🖥️ 25    ⚖  2 10000 580796 25894 606689 
 ├─ ⏱ 10' 2" 459ms    📋 3620  📄 22    🛠️ 1143  🖥️ 37    ⚖  0 9027 671057 30818 701874 
 ├─ ⏱ 11' 3" 8ms      📋 3974  📄 28    🛠️ 1107  🖥️ 37    ⚖  1 10000 537388 24238 561625 
 ├─ ⏱ 12' 3" 168ms    📋 4275  📄 24    🛠️ 1077  🖥️ 39    ⚖  2 10000 701055 30531 731585 
 ├─ ⏱ 13' 3" 220ms    📋 4566  📄 21    🛠️ 1048  🖥️ 41    ⚖  1 10000 850300 36970 887269 
 ├─ ⏱ 14' 3" 508ms    📋 4857  📄 23    🛠️ 1019  🖥️ 1     ⚖  1 10000 753673 32780 786452 
 ├─ ⏱ 15' 4" 129ms    📋 5152  📄 24    🛠️ 989   🖥️ 39    ⚖  1 10000 523836 30381 554216 
 ├─ ⏱ 16' 4" 152ms    📋 5442  📄 27    🛠️ 960   🖥️ 34    ⚖  2 10000 451288 26202 477489 
 ├─ ⏱ 17' 4" 236ms    📋 5734  📄 23    🛠️ 931   🖥️ 18    ⚖  1 10000 554118 32130 586247 
 ├─ ⏱ 18' 4" 292ms    📋 6031  📄 28    🛠️ 901   🖥️ 24    ⚖  2 10000 418034 24255 442288 
 ├─ ⏱ 19' 4" 395ms    📋 6385  📄 24    🛠️ 867   🖥️ 12    ⚖  1 10000 563962 36171 600132 
 ├─ ⏱ 20' 4" 695ms    📋 6750  📄 20    🛠️ 827   🖥️ 28    ⚖  0 2889 204248 13154 217401 
 ├─ ⏱ 21' 5" 88ms     📋 7092  📄 26    🛠️ 795   🖥️ 22    ⚖  2 10000 535332 32878 568209 
 ├─ ⏱ 22' 5" 196ms    📋 7388  📄 29    🛠️ 765   🖥️ 36    ⚖  2 10000 462535 28464 490998 
 ├─ ⏱ 23' 5" 536ms    📋 7686  📄 23    🛠️ 736   🖥️ 24    ⚖  1 10000 636784 39023 675806 
 ├─ ⏱ 24' 5" 815ms    📋 7976  📄 21    🛠️ 707   🖥️ 13    ⚖  2 10000 702810 43395 746204 
 ├─ ⏱ 25' 5" 961ms    📋 8263  📄 24    🛠️ 678   🖥️ 19    ⚖  2 10000 439570 35782 475351 
 ├─ ⏱ 26' 6" 183ms    📋 8546  📄 20    🛠️ 650   🖥️ 15    ⚖  1 10000 541045 44015 585059 
 ├─ ⏱ 27' 6" 449ms    📋 8829  📄 27    🛠️ 621   🖥️ 27    ⚖  4 10000 382603 31189 413791 
 ├─ ⏱ 28' 6" 691ms    📋 9130  📄 27    🛠️ 592   🖥️ 37    ⚖  2 10000 327034 38210 365243 
 ├─ ⏱ 29' 7" 257ms    📋 9457  📄 24    🛠️ 559   🖥️ 18    ⚖  1 10000 380376 44347 424722 
 ├─ ⏱ 30' 8" 146ms    📋 9781  📄 29    🛠️ 526   🖥️ 31    ⚖  1 10000 300705 35186 335890 
 ├─ ⏱ 31' 8" 840ms    📋 10108 📄 24    🛠️ 494   🖥️ 42    ⚖  2 10000 410322 45176 455497 
 ├─ ⏱ 32' 8" 851ms    📋 10425 📄 26    🛠️ 462   🖥️ 1     ⚖  1 10000 375215 41245 416459 
 ├─ ⏱ 33' 8" 926ms    📋 10741 📄 21    🛠️ 431   🖥️ 24    ⚖  1 10000 473587 51963 525549 
 ├─ ⏱ 34' 8" 971ms    📋 11050 📄 26    🛠️ 399   🖥️ 38    ⚖  6 10000 294457 40131 334587 
 ├─ ⏱ 35' 9" 203ms    📋 11333 📄 23    🛠️ 371   🖥️ 9     ⚖  6 10000 337545 45939 383483 
 ├─ ⏱ 36' 9" 257ms    📋 11616 📄 20    🛠️ 343   🖥️ 2     ⚖  4 10000 390948 53083 444030 
 ├─ ⏱ 37' 9" 273ms    📋 11898 📄 28    🛠️ 314   🖥️ 2     ⚖  7 10000 268833 36677 305509 
 ├─ ⏱ 38' 9" 410ms    📋 12181 📄 25    🛠️ 286   🖥️ 8     ⚖  11 10000 182086 51381 233466 
 ├─ ⏱ 39' 9" 414ms    📋 12465 📄 21    🛠️ 258   🖥️ 6     ⚖  8 10000 214643 60643 275285 
 ├─ ⏱ 40' 9" 524ms    📋 12748 📄 28    🛠️ 229   🖥️ 4     ⚖  13 10000 162993 46010 209002 
 ├─ ⏱ 41' 9" 828ms    📋 13031 📄 25    🛠️ 201   🖥️ 22    ⚖  11 10000 181513 51263 232775 
 ├─ ⏱ 42' 9" 972ms    📋 13315 📄 21    🛠️ 173   🖥️ 33    ⚖  8 10000 224958 62156 287113 
 ├─ ⏱ 43' 10" 16ms    📋 13599 📄 27    🛠️ 144   🖥️ 34    ⚖  13 10000 175322 48423 223744 
 ├─ ⏱ 44' 10" 268ms   📋 13884 📄 22    🛠️ 116   🖥️ 12    ⚖  9 10000 215177 59446 274622 
 ├─ ⏱ 45' 10" 499ms   📋 14167 📄 29    🛠️ 87    🖥️ 3     ⚖  14 10000 151379 44020 195398 
 ├─ ⏱ 46' 11" 378ms   📋 14450 📄 26    🛠️ 59    🖥️ 13    ⚖  11 10000 165760 48148 213907 
 ├─ ⏱ 47' 11" 713ms   📋 14733 📄 23    🛠️ 31    🖥️ 27    ⚖  9 10000 191530 55688 247217 
 ├─ ⏱ 48' 11" 759ms   📋 15000 📄 20    🛠️ 3     🖥️ 36    ⚖  8 10000 218746 63621 282366 
 ├─ 📑  Ficheiro Resultados/damasci_6.csv gravado.
 │  ⏱  Tempo real: 48' 18" 645ms 
 │  ⏱  CPU total: 1d 13h 50' 36" 333ms 
 │  ⏱  Espera do gestor: 48' 18" 322ms 
 │  ⏱  Espera trabalhadores: 4' 1" 486ms 
 │  📊  Utilização:
 │  - Total: 97.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 48' 18" 645ms ) ═══

═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 │ ...
 ├─ ⚙  [1498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [1499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [1500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:15000   📄 Instâncias: 10   🛠️ Configurações: 1500   🖥️ Processos: 48.
 ├─ ⏱ 1' 69ms         📋 1964  📄 20    🛠️ 1306  🖥️ 30    ⚖  0 1138 121665 10126 131790 
 ├─ ⏱ 2' 110ms        📋 3570  📄 21    🛠️ 1143  🖥️ 18    ⚖  0 46 4167 468 4634 
 ├─ ⏱ 3' 167ms        📋 5208  📄 28    🛠️ 1003  🖥️ 27    ⚖  1 10000 700865 78838 779702 
 ├─ ⏱ 4' 225ms        📋 6647  📄 21    🛠️ 836   🖥️ 14    ⚖  0 364 29738 4322 34059 
 ├─ ⏱ 5' 230ms        📋 8131  📄 21    🛠️ 687   🖥️ 13    ⚖  0 113 9156 1450 10605 
 ├─ ⏱ 6' 258ms        📋 9387  📄 24    🛠️ 561   🖥️ 17    ⚖  0 60 3374 882 4255 
 ├─ ⏱ 7' 294ms        📋 10346 📄 29    🛠️ 466   🖥️ 42    ⚖  0 965 46894 12315 59208 
 ├─ ⏱ 8' 344ms        📋 11328 📄 28    🛠️ 371   🖥️ 7     ⚖  0 2829 133433 38318 171750 
 ├─ ⏱ 9' 502ms        📋 12208 📄 22    🛠️ 280   🖥️ 14    ⚖  0 889 45159 16070 61228 
 ├─ ⏱ 10' 595ms       📋 12858 📄 28    🛠️ 223   🖥️ 45    ⚖  0 9918 410019 146065 556083 
 ├─ ⏱ 11' 712ms       📋 13475 📄 23    🛠️ 156   🖥️ 34    ⚖  0 3363 171473 61067 232539 
 ├─ ⏱ 12' 715ms       📋 14115 📄 26    🛠️ 91    🖥️ 31    ⚖  0 2565 110325 42725 153049 
 ├─ ⏱ 13' 745ms       📋 14777 📄 23    🛠️ 25    🖥️ 14    ⚖  0 2934 141344 54794 196137 
 ├─ 📑  Ficheiro Resultados/damascp_6.csv gravado.
 │  ⏱  Tempo real: 13' 29" 366ms 
 │  ⏱  CPU total: 10h 34' 203ms 
 │  ⏱  Espera do gestor: 13' 29" 57ms 
 │  ⏱  Espera trabalhadores: 4' 14" 43ms 
 │  📊  Utilização:
 │  - Total: 97.3%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.3% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 13' 29" 366ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P16=</span>1
 ├─ ⚙   ─ <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>0
 │ ...
 ├─ ⚙  [148] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [149] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
 ├─ ⚙  [150] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P13=</span>3 <span style="color:gray">P14=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:1500   📄 Instâncias: 10   🛠️ Configurações: 150   🖥️ Processos: 48.
 ├─ ⏱ 1' 1" 441ms     📋 400   📄 764   🛠️ 115   🖥️ 6     ⚖  14 10001 125437 7414 132850 
 ├─ ⏱ 2' 1" 449ms     📋 762   📄 870   🛠️ 78    🖥️ 29    ⚖  146 10001 81436 6840 88275 
 ├─ ⏱ 3' 1" 610ms     📋 1118  📄 930   🛠️ 42    🖥️ 8     ⚖  74 10000 45365 6573 51937 
 ├─ ⏱ 4' 1" 796ms     📋 1452  📄 948   🛠️ 9     🖥️ 16    ⚖  10 10001 17474 6384 23857 
 ├─ 📑  Ficheiro Resultados/particaocb_6.csv gravado.
 │  ⏱  Tempo real: 4' 21" 567ms 
 │  ⏱  CPU total: 3h 24' 53" 667ms 
 │  ⏱  Espera do gestor: 4' 21" 535ms 
 │  ⏱  Espera trabalhadores: 3' 49" 744ms 
 │  📊  Utilização:
 │  - Total: 96.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 4' 21" 567ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_6

|  | P13 vs P14 | 0 | 25 | 50 | 75 | 100 |
|:---:|---:|---:|---:|---:|---:|---:|
| Eficácia | 1:Idade | 0 | 0 | 1 | 7 | **72** |
| | 2:Substitui piores | 0 | 24 | 10 | 6 | 7 |
| | 3:round-robin | 0 | 30 | 44 | 38 | 44 |
| Eficiência | 1:Idade | 10000 | 10000 | 9971 | 9696 | **5879** |
| | 2:Substitui piores | 10000 | 8973 | 9592 | 9730 | 9709 |
| | 3:round-robin | 10000 | 8745 | 7875 | 8110 | 7880 |

Podemos ver o registo das 8 damas com codificação inteira da configuração atual, mas no novo conjuunto de instâncias.
A eficiência ficou com um tempo médio nos 5,8 segundos, e eficácia nos 72% de instâncias resolvidas.
Nenhuma das alternativas consideradas melhorou, pelo contrário.

A substituição dos piores tem como melhor valor uma baixa precentagem de descnedentes, e o round-robin é incerto.


### Resultados: damascp_6

| P13 vs P14 | 0 | 25 | 50 | 75 | 100 |
|:---:|---:|---:|---:|---:|---:|
| 1:Idade | 4230 | 2849 | 2059 | 1883 | 1818 |
| 2:Substitui piores | 4507 | 2970 | 1913 | 1695 | 1585 |
| 3:round-robin | 4385 | 2845 | 1980 | 1662 | **1440** |

O método round-robin ficou com resultados melhores com P14=100.
A estratégia de substituir os piores também melhora relativamente à idade.

É portanto necessário um segundo teste para otimizar o parâmetro Q do round-robin.


### Resultados: particaocb_6

| P13 vs P14 | 0 | 25 | 50 | 75 | 100 |
|:---:|---:|---:|---:|---:|---:|
| 1:Idade | 9496 | 6539 | 4059 | 3002 | **1862** |
| 2:Substitui piores | 9163 | 9964 | 9922 | 9895 | 10001 |
| 3:round-robin | 8998 | 9171 | 9736 | 9468 | 9439 |

Neste problema são claramente prejudiciais outras opções que não a parametrização base.


### Teste - damascp_6B

Temos de investigar apenas para as damas com a codificação de permutação o parâmetro P15.
Vamos variar da mesma forma que o tamanho do torneio: 2,3,4,6,10.

- **Tipo de Teste / Objetivo**: Paramétrico P15
- **Definição**:
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2,3,4,6,10
- **Esforço**:
	- **ci**: P3=1:100
- **Execução**:
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_6B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P3=1:100 x P15=2,3,4,6,10


\htmlonly
<details>
  <summary>Ver script: evolutivos6B.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos6B
#SBATCH --output=Resultados/evolutivos6B.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damascp_6B
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_6B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P3=1:100 x P15=2,3,4,6,10
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P15=</span>2
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P15=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P15=</span>2
 │ ...
 ├─ ⚙  [498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P15=</span>10
 ├─ ⚙  [499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P15=</span>10
 ├─ ⚙  [500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P15=</span>10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:5000   📄 Instâncias: 10   🛠️ Configurações: 500   🖥️ Processos: 48.
 ├─ ⏱ 1' 49ms         📋 1904  📄 20    🛠️ 310   🖥️ 40    ⚖  0 224 22644 1890 24533 
 ├─ ⏱ 2' 114ms        📋 3796  📄 22    🛠️ 121   🖥️ 22    ⚖  0 282 26554 2223 28776 
 ├─ 📑  Ficheiro Resultados/damascp_6B.csv gravado.
 │  ⏱  Tempo real: 2' 43" 279ms 
 │  ⏱  CPU total: 2h 7' 54" 131ms 
 │  ⏱  Espera do gestor: 2' 43" 170ms 
 │  ⏱  Espera trabalhadores: 4' 41" 546ms 
 │  📊  Utilização:
 │  - Total: 94.3%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 96.3% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 2' 43" 279ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damascp_6B

| P15 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 2 | **1300** | 1182 | 1419 | 61 | 535 | 3756 |
| 3 | 1441 | 1304 | 1579 | 53 | 521 | 4210 |
| 4 | 1544 | 1396 | 1691 | 57 | 561 | 4350 |
| 6 | 1575 | 1427 | 1724 | 58 | 547 | 4707 |
| 10 | 1552 | 1407 | 1697 | 58 | 640 | 4316 |

O melhor registo é com Q igual a 2, embora o intervalo de confiança intersecte o valor seguinte.
Temos também o percentil de 90% o melhor, embora não por muito.
Assim sendo vamos alterar o valor para P15=2, ficando os restantes dois valores com P13=3 P14=100.

## Teste 7

Vamos agora ver a influência do P6 elitísmo e P17 imigrantes, cujo valor por omissão é 1.
O elitísmo garante que se existirem K elementos da população antiga melhores que na nova população,
esses elementos mantêm-se na nova população. Os imigrantes garantem um número de elementos estrangeiros
na população, que são gerados aleatoriamente.

Vamos ver possibilidades de números pequenos, já que valores demasiado altos bloqueiam a evolução: 0:3

- **Tipo de Teste / Objetivo**: Paramétrico P16 vs P17
- **Definição**:
	- **ci**: Instâncias: 20:29; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=0:3 x P17=0:3
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=0:3 x P17=0:3
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=0:3 x P17=0:3
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 20:29 -R Resultados/damasci_7 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P3=1:100 x P16=0:3 x P17=0:3
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_7 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P3=1:100 x P16=0:3 x P17=0:3
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_7 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P3=1:10 x P16=0:3 x P17=0:3


\htmlonly
<details>
  <summary>Ver script: evolutivos7.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos7
#SBATCH --output=Resultados/evolutivos7.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_7
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_7 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P3=1:100 x P16=0:3 x P17=0:3
# Teste: damascp_7
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_7 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P3=1:100 x P16=0:3 x P17=0:3
# Teste: particaocb_7
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_7 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P3=1:10 x P16=0:3 x P17=0:3
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 │ ...
 ├─ ⚙  [1598] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [1599] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [1600] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:16000   📄 Instâncias: 10   🛠️ Configurações: 1600   🖥️ Processos: 48.
 ├─ ⏱ 1' 19ms         📋 328   📄 28    🛠️ 1571  🖥️ 41    ⚖  2 10000 514420 21535 579024 
 ├─ ⏱ 2' 436ms        📋 617   📄 29    🛠️ 1542  🖥️ 13    ⚖  3 10000 488152 20425 549426 
 ├─ ⏱ 3' 578ms        📋 912   📄 23    🛠️ 1510  🖥️ 3     ⚖  0 2435 164175 6870 184784 
 ├─ ⏱ 4' 1" 34ms      📋 1203  📄 24    🛠️ 1484  🖥️ 23    ⚖  1 10000 644570 26964 698497 
 ├─ ⏱ 5' 1" 39ms      📋 1494  📄 23    🛠️ 1455  🖥️ 17    ⚖  1 10000 682831 28562 739954 
 ├─ ⏱ 6' 1" 91ms      📋 1791  📄 27    🛠️ 1425  🖥️ 21    ⚖  1 10000 543704 22745 589193 
 ├─ ⏱ 7' 1" 282ms     📋 2085  📄 21    🛠️ 1396  🖥️ 34    ⚖  1 10000 773707 32366 806072 
 ├─ ⏱ 8' 1" 694ms     📋 2375  📄 23    🛠️ 1367  🖥️ 41    ⚖  1 10000 677929 28368 706296 
 ├─ ⏱ 9' 1" 951ms     📋 2669  📄 27    🛠️ 1337  🖥️ 15    ⚖  2 10000 544480 22790 567269 
 ├─ ⏱ 10' 2" 485ms    📋 2962  📄 25    🛠️ 1308  🖥️ 18    ⚖  2 10000 604672 25312 629983 
 ├─ ⏱ 11' 2" 681ms    📋 3247  📄 29    🛠️ 1279  🖥️ 43    ⚖  5 10000 488871 20622 488870 
 ├─ ⏱ 12' 2" 890ms    📋 3531  📄 25    🛠️ 1251  🖥️ 15    ⚖  2 10000 612147 25820 612146 
 ├─ ⏱ 13' 2" 972ms    📋 3814  📄 22    🛠️ 1223  🖥️ 31    ⚖  2 10000 730611 30835 730610 
 ├─ ⏱ 14' 3" 78ms     📋 4119  📄 21    🛠️ 1189  🖥️ 13    ⚖  0 2313 169731 7229 191417 
 ├─ ⏱ 15' 3" 194ms    📋 4478  📄 27    🛠️ 1157  🖥️ 14    ⚖  2 10000 530217 22589 597983 
 ├─ ⏱ 16' 3" 574ms    📋 4841  📄 29    🛠️ 1121  🖥️ 33    ⚖  1 10000 469206 19985 529160 
 ├─ ⏱ 17' 3" 733ms    📋 5201  📄 24    🛠️ 1086  🖥️ 38    ⚖  1 10000 623959 26576 677110 
 ├─ ⏱ 18' 3" 877ms    📋 5563  📄 25    🛠️ 1049  🖥️ 31    ⚖  1 10000 590733 25176 641084 
 ├─ ⏱ 19' 4" 150ms    📋 5939  📄 21    🛠️ 1006  🖥️ 31    ⚖  0 452 33931 1445 36820 
 ├─ ⏱ 20' 4" 191ms    📋 6314  📄 23    🛠️ 975   🖥️ 26    ⚖  1 10000 666225 28392 694616 
 ├─ ⏱ 21' 4" 254ms    📋 6675  📄 28    🛠️ 938   🖥️ 7     ⚖  2 10000 503885 21488 525372 
 ├─ ⏱ 22' 4" 295ms    📋 7031  📄 28    🛠️ 902   🖥️ 17    ⚖  1 10000 503209 21462 524670 
 ├─ ⏱ 23' 4" 604ms    📋 7320  📄 26    🛠️ 872   🖥️ 21    ⚖  2 10000 564950 24229 564949 
 ├─ ⏱ 24' 4" 776ms    📋 7610  📄 27    🛠️ 843   🖥️ 37    ⚖  2 10000 526269 22567 526268 
 ├─ ⏱ 25' 5" 289ms    📋 7900  📄 27    🛠️ 814   🖥️ 11    ⚖  2 10000 534552 22922 534551 
 ├─ ⏱ 26' 5" 313ms    📋 8306  📄 22    🛠️ 777   🖥️ 46    ⚖  1 10000 686766 29752 776021 
 ├─ ⏱ 27' 5" 368ms    📋 8792  📄 28    🛠️ 726   🖥️ 22    ⚖  0 5955 289419 12549 327065 
 ├─ ⏱ 28' 5" 408ms    📋 9291  📄 28    🛠️ 675   🖥️ 23    ⚖  0 6406 314820 13645 342109 
 ├─ ⏱ 29' 5" 463ms    📋 9791  📄 24    🛠️ 625   🖥️ 23    ⚖  0 5121 313737 13597 340930 
 ├─ ⏱ 30' 5" 555ms    📋 10265 📄 24    🛠️ 581   🖥️ 30    ⚖  1 10000 611392 26479 637870 
 ├─ ⏱ 31' 5" 583ms    📋 10747 📄 22    🛠️ 526   🖥️ 44    ⚖  0 1153 79328 3437 82764 
 ├─ ⏱ 32' 5" 954ms    📋 11160 📄 22    🛠️ 489   🖥️ 40    ⚖  1 10000 689557 29999 689556 
 ├─ ⏱ 33' 6" 207ms    📋 11485 📄 29    🛠️ 456   🖥️ 5     ⚖  3 10000 469961 20473 469960 
 ├─ ⏱ 34' 6" 506ms    📋 11815 📄 29    🛠️ 423   🖥️ 23    ⚖  2 10000 470784 20505 470783 
 ├─ ⏱ 35' 6" 699ms    📋 12208 📄 26    🛠️ 381   🖥️ 19    ⚖  0 2867 152818 6730 173007 
 ├─ ⏱ 36' 6" 975ms    📋 12735 📄 24    🛠️ 332   🖥️ 42    ⚖  0 8320 489753 21561 554435 
 ├─ ⏱ 37' 7" 90ms     📋 13250 📄 27    🛠️ 282   🖥️ 3     ⚖  0 8755 438277 19317 476910 
 ├─ ⏱ 38' 7" 153ms    📋 13780 📄 25    🛠️ 230   🖥️ 33    ⚖  1 10000 557252 24527 606305 
 ├─ ⏱ 39' 7" 445ms    📋 14310 📄 25    🛠️ 176   🖥️ 9     ⚖  0 8274 467318 20579 487896 
 ├─ ⏱ 40' 7" 459ms    📋 14831 📄 20    🛠️ 122   🖥️ 13    ⚖  0 6295 479068 21084 500151 
 ├─ ⏱ 41' 7" 850ms    📋 15311 📄 21    🛠️ 69    🖥️ 7     ⚖  0 1008 72359 3197 72358 
 ├─ ⏱ 42' 7" 930ms    📋 15730 📄 21    🛠️ 29    🖥️ 26    ⚖  0 3338 241243 10642 241242 
 ├─ 📑  Ficheiro Resultados/damasci_7.csv gravado.
 │  ⏱  Tempo real: 42' 55" 185ms 
 │  ⏱  CPU total: 1d 9h 37' 13" 678ms 
 │  ⏱  Espera do gestor: 42' 54" 843ms 
 │  ⏱  Espera trabalhadores: 4' 5" 66ms 
 │  📊  Utilização:
 │  - Total: 97.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 42' 55" 185ms ) ═══

═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 │ ...
 ├─ ⚙  [1598] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [1599] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [1600] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:16000   📄 Instâncias: 10   🛠️ Configurações: 1600   🖥️ Processos: 48.
 ├─ ⏱ 1' 2ms          📋 2363  📄 24    🛠️ 1367  🖥️ 14    ⚖  0 753 71670 5371 77040 
 ├─ ⏱ 2' 29ms         📋 3514  📄 28    🛠️ 1256  🖥️ 9     ⚖  0 7853 631113 48942 631112 
 ├─ ⏱ 3' 41ms         📋 4670  📄 22    🛠️ 1133  🖥️ 4     ⚖  0 43 4279 333 5277 
 ├─ ⏱ 4' 124ms        📋 7562  📄 21    🛠️ 844   🖥️ 27    ⚖  0 377 39017 3192 39016 
 ├─ ⏱ 5' 157ms        📋 10445 📄 29    🛠️ 555   🖥️ 19    ⚖  0 306 21710 1830 23539 
 ├─ ⏱ 6' 184ms        📋 14011 📄 25    🛠️ 205   🖥️ 11    ⚖  0 1280 102542 9026 120593 
 ├─ ⏱ 7' 566ms        📋 14645 📄 29    🛠️ 144   🖥️ 42    ⚖  1 10000 672767 60855 733621 
 ├─ ⏱ 8' 610ms        📋 15338 📄 28    🛠️ 70    🖥️ 46    ⚖  0 3121 208662 20085 208661 
 ├─ 📑  Ficheiro Resultados/damascp_7.csv gravado.
 │  ⏱  Tempo real: 8' 57" 810ms 
 │  ⏱  CPU total: 7h 1' 17" 92ms 
 │  ⏱  Espera do gestor: 8' 57" 483ms 
 │  ⏱  Espera trabalhadores: 5' 8" 338ms 
 │  📊  Utilização:
 │  - Total: 96.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 8' 57" 810ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P16=</span>0 <span style="color:gray">P17=</span>0
 │ ...
 ├─ ⚙  [158] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [159] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
 ├─ ⚙  [160] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:1600   📄 Instâncias: 10   🛠️ Configurações: 160   🖥️ Processos: 48.
 ├─ ⏱ 1' 24ms         📋 920   📄 926   🛠️ 80    🖥️ 41    ⚖  2 10001 132738 6041 132737 
 ├─ ⏱ 2' 193ms        📋 1600  📄 864   🛠️ 2     🖥️ 7     ⚖  4 10001 108258 5405 108257 
 ├─ 📑  Ficheiro Resultados/particaocb_6.csv gravado.
 │  ⏱  Tempo real: 2' 2" 868ms 
 │  ⏱  CPU total: 1h 36' 14" 794ms 
 │  ⏱  Espera do gestor: 2' 2" 834ms 
 │  ⏱  Espera trabalhadores: 3' 51" 713ms 
 │  📊  Utilização:
 │  - Total: 94.0%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 96.0% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 2' 2" 868ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_7

| P16 vs P17 | 0 | 1 | 2 | 3 |
|:---:|---:|---:|---:|---:|
| 0 | 6647 | 8672 | 9813 | 10000 |
| 1 | **5311** | 5883 | 7732 | 9720 |
| 2 | 5363 | 5730 | 7732 | 9643 |
| 3 | 5478 | 5816 | 7836 | 9572 |

Os imigrantes não aparentam auxiliar, pelo contrário.
Já o elitísmo de 1 ou 2 mostra-se melhor que não utilizar elitismo.
Assim mantemos P16=1 e alteramos P17=0.

### Resultados: damascp_7

| P16 vs P17 | 0 | 1 | 2 | 3 |
|:---:|---:|---:|---:|---:|
| 0 | 3344 | 800 | 2829 | 4534 |
| 1 | 4657 | 1302 | 631 | 1019 |
| 2 | 828 | 444 | 563 | 1140 |
| 3 | 448 | **414** | 652 | 1374 |

Neste caso, atendendo à estratégia de utilização da mutação, os valores atuais aparentam não ser os melhores.
Ter um elitísmo alto, e alguns imigrantes, desde que não demasiado, mostra-se mais vantajoso.
Relativamente à configuração atual reduz em um terço o tempo, o que é um registo considerável.
Vamos portanto alterar P16=3 e mantemos P17=1.


### Resultados: particaocb_7

| P16 vs P17 | 0 | 1 | 2 | 3 |
|:---:|---:|---:|---:|---:|
| 0 | 7055 | 7541 | 7149 | 6072 |
| 1 | 2760 | **1862** | 2142 | 1902 |
| 2 | 2258 | 2586 | 2429 | 2070 |
| 3 | 2812 | 2478 | 2215 | 2109 |

Neste problema a parametrização atual é a melhor.
Podemos observar uma alta sensibilidade à utilização do elitísmo, caso seja 0 a eficiência degrada-se consideravalmente.
A quantidade de imigrantes não tem tanto relevo neste caso.

## Teste 8

Vamos agora estudar o impacto da estratégia da diversidade.
O P18(DIVERSIDADE) tem 3 possibilidades:
- 1: Nenhuma
- 2: Avaliação partilhada
- 3: Limpeza (valor por omissão)

As opções 2 e 3 utilizam também P19(DIST_MINIMA), P24(TIPO_DISTANCIA).

Vamos neste teste estudar o impacto da troca destas estratégias com os valores por omissão para as distâncias,
de modo a identificar a sua relevância.


- **Tipo de Teste / Objetivo**: Paramétrico P18
- **Definição**:
	- **ci**: Instâncias: 20:29; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=1:3
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=1:3
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1:3
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 20:29 -R Resultados/damasci_8 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P3=1:100 x P18=1:3
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_8 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P3=1:100 x P18=1:3
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_8 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P3=1:10 x P18=1:3


\htmlonly
<details>
  <summary>Ver script: evolutivos8.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos8
#SBATCH --output=Resultados/evolutivos8.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_8
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_8 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P3=1:100 x P18=1:3
# Teste: damascp_8
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_8 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P3=1:100 x P18=1:3
# Teste: particaocb_8
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_8 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P3=1:10 x P18=1:3

</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>0 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P18=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P18=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P18=</span>1
 │ ...
 ├─ ⚙  [298] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P18=</span>3
 ├─ ⚙  [299] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P18=</span>3
 ├─ ⚙  [300] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P18=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3000   📄 Instâncias: 10   🛠️ Configurações: 300   🖥️ Processos: 48.
 ├─ ⏱ 1' 259ms        📋 570   📄 20    🛠️ 244   🖥️ 31    ⚖  0 1077 81891 3608 85498 
 ├─ ⏱ 2' 375ms        📋 1059  📄 27    🛠️ 198   🖥️ 8     ⚖  13 10000 433661 21682 455342 
 ├─ ⏱ 3' 509ms        📋 1344  📄 22    🛠️ 170   🖥️ 35    ⚖  8 10000 559101 27954 587054 
 ├─ ⏱ 4' 631ms        📋 1627  📄 29    🛠️ 141   🖥️ 14    ⚖  17 10000 394621 19730 414350 
 ├─ ⏱ 5' 670ms        📋 1911  📄 25    🛠️ 113   🖥️ 5     ⚖  10 10000 478781 23938 502718 
 ├─ ⏱ 6' 1" 153ms     📋 2207  📄 29    🛠️ 83    🖥️ 9     ⚖  13 10000 691881 34593 726473 
 ├─ ⏱ 7' 1" 400ms     📋 2506  📄 22    🛠️ 54    🖥️ 32    ⚖  10 9108 1000001 49999 1049999 
 ├─ ⏱ 8' 1" 587ms     📋 2806  📄 22    🛠️ 24    🖥️ 19    ⚖  9 9136 1000001 49999 1049999 
 ├─ 📑  Ficheiro Resultados/damasci_8.csv gravado.
 │  ⏱  Tempo real: 8' 50" 236ms 
 │  ⏱  CPU total: 6h 55' 21" 85ms 
 │  ⏱  Espera do gestor: 8' 50" 168ms 
 │  ⏱  Espera trabalhadores: 3' 36" 609ms 
 │  📊  Utilização:
 │  - Total: 97.1%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 8' 50" 236ms ) ═══

═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P18=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P18=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P18=</span>1
 │ ...
 ├─ ⚙  [298] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P18=</span>3
 ├─ ⚙  [299] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P18=</span>3
 ├─ ⚙  [300] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P18=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3000   📄 Instâncias: 10   🛠️ Configurações: 300   🖥️ Processos: 48.
 ├─ ⏱ 1' 291ms        📋 1516  📄 29    🛠️ 157   🖥️ 46    ⚖  1 10000 660164 60014 840205 
 ├─ ⏱ 2' 451ms        📋 2073  📄 26    🛠️ 99    🖥️ 27    ⚖  1 10000 987898 89808 1257321 
 ├─ ⏱ 3' 841ms        📋 2466  📄 27    🛠️ 59    🖥️ 6     ⚖  1 10000 952192 86562 1211877 
 ├─ ⏱ 4' 935ms        📋 2863  📄 21    🛠️ 14    🖥️ 35    ⚖  0 1721 211793 19253 269551 
 ├─ 📑  Ficheiro Resultados/damascp_8.csv gravado.
 │  ⏱  Tempo real: 4' 30" 271ms 
 │  ⏱  CPU total: 3h 31' 42" 760ms 
 │  ⏱  Espera do gestor: 4' 30" 204ms 
 │  ⏱  Espera trabalhadores: 4' 3" 39ms 
 │  📊  Utilização:
 │  - Total: 96.0%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 4' 30" 272ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P18=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P18=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P18=</span>1
 │ ...
 ├─ ⚙  [28] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P18=</span>3
 ├─ ⚙  [29] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P18=</span>3
 ├─ ⚙  [30] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P18=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:300   📄 Instâncias: 10   🛠️ Configurações: 30   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/particaocb_8.csv gravado.
 │  ⏱  Tempo real: 15" 308ms 
 │  ⏱  CPU total: 11' 59" 463ms 
 │  ⏱  Espera do gestor: 15" 300ms 
 │  ⏱  Espera trabalhadores: 4' 16" 369ms 
 │  📊  Utilização:
 │  - Total: 63.0%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 64.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 15" 308ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_8

| P18 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1:Nenhuma | 9507 | 9459 | 9554 | 8255 | 10000 | 10000 |
| 2:Avaliação partilhada | 10000 | 10000 | 10000 | 10000 | 10000 | 10000 |
| 3:Limpeza | **5307** | 5103 | 5511 | 1269 | 4750 | 10000 |

A estratégia de diversidade de avaliação partihada, não é compatível com as restantes configurações.
Podemos ver também que a não ulização de nenhuma estratégia de diversidade, é claramente inferior à estratégia de limpeza.

### Resultados: damascp_8

| P18 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1:Nenhuma | 7107 | 6870 | 7344 | 164 | 8869 | 10000 |
| 2:Avaliação partilhada | 4991 | 4733 | 5249 | 274 | 3657 | 10000 |
| 3:Limpeza | **412** | 379 | 445 | 46 | 225 | 1019 |

Podemos ver neste caso que a avaliação partilhada tem algum impacto positivo, embora distante da
estratégia de limpeza que é o valor por omissão. Mesmo o percentil de 90% tem um valor relativamente baixo de 1 segundo.


### Resultados: particaocb_8

| P18 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1:Nenhuma | **273** | 219 | 327 | 30 | 172 | 613 |
| 2:Avaliação partilhada | 2507 | 2036 | 2979 | 281 | 1595 | 5819 |
| 3:Limpeza | 1862 | 1460 | 2263 | 293 | 1354 | 4196 |

Estes resultados mostram o surpreendente registo de não utilizar estratégia de limpeza para este problema,
melhora consideravelmente a eficiência, e com o percentil de 90% a baixo de 1 segundo.
Concluímos que esta estratégia estava a ser prejudicial para este problema.
Assim, alteramos o valor de P18=1. 


## Teste 9

Vamos agora estudar o impacto da distância mínima P19 e tipo de distância P24, apenas para as duas primeiras implementações,
atendendo a que na terceira a não utilização de estratégia de limpeza revelou-se bastante melhor, a qual não utiliza
distâncias.

Para a codificação inteira temos os seguintes tipos de distâncias:
- 1: Hamming (valor por omissão)
- 2: Euclidiana
- 3: Manhattan

Para a codificação permutação temos as seguintes distâncias:
- 1: Hamming (valor por omissão)
- 2: Kendall tau
- 3: Spearman footrule

O parâmetro P19 vamos variar em valores pequenos e alguns grandes, já que depende da medida de distância: 0,1,2,4,8

- **Tipo de Teste / Objetivo**: Paramétrico P19 vs P24
- **Definição**:
	- **ci**: Instâncias: 20:29; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0,1,2,4,8 x P24=1:3
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0,1,2,4,8 x P24=1:3
- **Esforço**:
	- **ci+cp**: P3=1:100
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 20:29 -R Resultados/damasci_9 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_9 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3



\htmlonly
<details>
  <summary>Ver script: evolutivos9.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos9
#SBATCH --output=Resultados/evolutivos9.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_9
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_9 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3
# Teste: damascp_9
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_9 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>0 <span style="color:gray">P18=</span>3 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 │ ...
 ├─ ⚙  [1498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
 ├─ ⚙  [1499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
 ├─ ⚙  [1500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:15000   📄 Instâncias: 10   🛠️ Configurações: 1500   🖥️ Processos: 48.
 ├─ ⏱ 1' 94ms         📋 347   📄 21    🛠️ 1470  🖥️ 42    ⚖  1 10000 705919 30835 736753 
 ├─ ⏱ 2' 395ms        📋 663   📄 28    🛠️ 1438  🖥️ 42    ⚖  1 10000 478842 20977 499818 
 ├─ ⏱ 3' 688ms        📋 988   📄 24    🛠️ 1406  🖥️ 28    ⚖  1 10000 590700 25840 616539 
 ├─ ⏱ 4' 797ms        📋 1416  📄 25    🛠️ 1363  🖥️ 3     ⚖  0 7089 398024 17485 415508 
 ├─ ⏱ 5' 818ms        📋 1863  📄 29    🛠️ 1316  🖥️ 42    ⚖  0 4094 185610 8157 193766 
 ├─ ⏱ 6' 829ms        📋 2332  📄 28    🛠️ 1274  🖥️ 35    ⚖  1 10000 477063 20984 498046 
 ├─ ⏱ 7' 875ms        📋 2843  📄 27    🛠️ 1224  🖥️ 40    ⚖  1 10000 501807 22077 523883 
 ├─ ⏱ 8' 986ms        📋 3336  📄 21    🛠️ 1168  🖥️ 10    ⚖  0 1744 123357 5430 128786 
 ├─ ⏱ 9' 1" 78ms      📋 3852  📄 26    🛠️ 1118  🖥️ 12    ⚖  0 3422 178795 7872 186666 
 ├─ ⏱ 10' 1" 200ms    📋 4367  📄 23    🛠️ 1071  🖥️ 2     ⚖  1 10000 626223 27587 653809 
 ├─ ⏱ 11' 1" 201ms    📋 4895  📄 21    🛠️ 1012  🖥️ 22    ⚖  0 2109 149259 6577 155835 
 ├─ ⏱ 12' 1" 469ms    📋 5414  📄 21    🛠️ 959   🖥️ 39    ⚖  0 1297 91802 4032 95833 
 ├─ ⏱ 13' 1" 638ms    📋 5912  📄 29    🛠️ 916   🖥️ 26    ⚖  1 10000 452073 19907 471979 
 ├─ ⏱ 14' 1" 660ms    📋 6404  📄 22    🛠️ 868   🖥️ 1     ⚖  1 10000 667855 29351 697205 
 ├─ ⏱ 15' 1" 780ms    📋 6921  📄 25    🛠️ 810   🖥️ 47    ⚖  0 3842 211651 9313 220963 
 ├─ ⏱ 16' 2" 79ms     📋 7429  📄 23    🛠️ 759   🖥️ 9     ⚖  0 2915 181956 8017 189972 
 ├─ ⏱ 17' 2" 142ms    📋 7967  📄 26    🛠️ 709   🖥️ 21    ⚖  0 7163 380184 16745 396928 
 ├─ ⏱ 18' 2" 319ms    📋 8474  📄 29    🛠️ 655   🖥️ 43    ⚖  0 4623 208723 9202 217924 
 ├─ ⏱ 19' 2" 398ms    📋 8989  📄 26    🛠️ 608   🖥️ 7     ⚖  0 8472 449335 19782 469116 
 ├─ ⏱ 20' 2" 469ms    📋 9518  📄 29    🛠️ 551   🖥️ 27    ⚖  0 3463 154462 6813 161274 
 ├─ ⏱ 21' 3" 81ms     📋 10038 📄 29    🛠️ 503   🖥️ 9     ⚖  1 10000 452935 19961 472895 
 ├─ ⏱ 22' 4" 106ms    📋 10322 📄 24    🛠️ 472   🖥️ 15    ⚖  8 10000 623554 26034 649587 
 ├─ ⏱ 23' 4" 307ms    📋 10606 📄 20    🛠️ 444   🖥️ 5     ⚖  6 10000 829923 33480 863402 
 ├─ ⏱ 24' 4" 405ms    📋 10889 📄 27    🛠️ 415   🖥️ 3     ⚖  8 10000 517656 21927 539582 
 ├─ ⏱ 25' 5" 214ms    📋 11173 📄 23    🛠️ 387   🖥️ 44    ⚖  5 10000 640993 27799 668791 
 ├─ ⏱ 26' 5" 688ms    📋 11457 📄 29    🛠️ 358   🖥️ 34    ⚖  7 10000 461800 20035 481834 
 ├─ ⏱ 27' 6" 2ms      📋 11744 📄 22    🛠️ 330   🖥️ 14    ⚖  5 10000 672925 29195 702119 
 ├─ ⏱ 28' 6" 103ms    📋 12027 📄 29    🛠️ 301   🖥️ 42    ⚖  5 10000 462287 20075 482361 
 ├─ ⏱ 29' 6" 271ms    📋 12315 📄 21    🛠️ 273   🖥️ 18    ⚖  2 10000 717890 31237 749126 
 ├─ ⏱ 30' 6" 549ms    📋 12599 📄 27    🛠️ 244   🖥️ 41    ⚖  3 10000 510429 22248 532676 
 ├─ ⏱ 31' 6" 633ms    📋 12882 📄 24    🛠️ 216   🖥️ 20    ⚖  2 10000 603159 26263 629421 
 ├─ ⏱ 32' 6" 878ms    📋 13180 📄 29    🛠️ 186   🖥️ 23    ⚖  1 10000 453922 19872 473793 
 ├─ ⏱ 33' 6" 899ms    📋 13474 📄 25    🛠️ 157   🖥️ 5     ⚖  2 10000 568426 24874 593299 
 ├─ ⏱ 34' 7" 124ms    📋 13773 📄 23    🛠️ 127   🖥️ 46    ⚖  1 10000 636605 27837 664441 
 ├─ ⏱ 35' 7" 148ms    📋 14122 📄 25    🛠️ 96    🖥️ 20    ⚖  1 10000 561550 24750 586299 
 ├─ ⏱ 36' 7" 470ms    📋 14656 📄 26    🛠️ 42    🖥️ 18    ⚖  1 10000 535710 23594 559303 
 ├─ 📑  Ficheiro Resultados/damasci_9.csv gravado.
 │  ⏱  Tempo real: 36' 55" 431ms 
 │  ⏱  CPU total: 1d 4h 55' 25" 237ms 
 │  ⏱  Espera do gestor: 36' 55" 97ms 
 │  ⏱  Espera trabalhadores: 4' 45" 183ms 
 │  📊  Utilização:
 │  - Total: 97.6%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.7% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 36' 55" 431ms ) ═══

═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P24=</span>1
 │ ...
 ├─ ⚙  [1498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
 ├─ ⚙  [1499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
 ├─ ⚙  [1500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P19=</span>8 <span style="color:gray">P24=</span>3
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:15000   📄 Instâncias: 10   🛠️ Configurações: 1500   🖥️ Processos: 48.
 ├─ ⏱ 1' 227ms        📋 569   📄 28    🛠️ 1451  🖥️ 35    ⚖  0 9238 594766 45451 731118 
 ├─ ⏱ 2' 254ms        📋 1143  📄 26    🛠️ 1388  🖥️ 45    ⚖  0 2922 198465 15660 245444 
 ├─ ⏱ 3' 314ms        📋 1967  📄 29    🛠️ 1315  🖥️ 2     ⚖  1 10000 593543 46971 734455 
 ├─ ⏱ 4' 320ms        📋 4467  📄 23    🛠️ 1054  🖥️ 29    ⚖  0 169 12617 1034 15718 
 ├─ ⏱ 5' 682ms        📋 5311  📄 29    🛠️ 973   🖥️ 33    ⚖  2 10001 82288 5960 100167 
 ├─ ⏱ 6' 771ms        📋 5625  📄 28    🛠️ 942   🖥️ 9     ⚖  2 10001 88993 6445 108327 
 ├─ ⏱ 7' 1" 109ms     📋 5941  📄 29    🛠️ 910   🖥️ 31    ⚖  1 10002 82920 5995 100904 
 ├─ ⏱ 8' 1" 565ms     📋 6290  📄 29    🛠️ 876   🖥️ 37    ⚖  1 10001 67305 5148 82748 
 ├─ ⏱ 9' 1" 603ms     📋 6640  📄 22    🛠️ 839   🖥️ 21    ⚖  0 6053 84323 6325 103297 
 ├─ ⏱ 10' 1" 701ms    📋 6982  📄 20    🛠️ 806   🖥️ 23    ⚖  0 8210 145155 10808 177578 
 ├─ ⏱ 11' 2" 58ms     📋 7390  📄 22    🛠️ 762   🖥️ 19    ⚖  0 2540 30643 2399 37839 
 ├─ ⏱ 12' 2" 136ms    📋 7799  📄 29    🛠️ 726   🖥️ 34    ⚖  1 10002 60308 4768 74611 
 ├─ ⏱ 13' 2" 267ms    📋 8241  📄 28    🛠️ 683   🖥️ 38    ⚖  1 10000 61423 4951 76275 
 ├─ ⏱ 14' 2" 488ms    📋 8725  📄 25    🛠️ 628   🖥️ 36    ⚖  0 1213 9789 788 12152 
 ├─ ⏱ 15' 2" 517ms    📋 9339  📄 20    🛠️ 567   🖥️ 30    ⚖  0 389 5048 414 6289 
 ├─ ⏱ 16' 2" 643ms    📋 10061 📄 23    🛠️ 497   🖥️ 22    ⚖  0 6665 685923 47068 827126 
 ├─ ⏱ 17' 2" 698ms    📋 10449 📄 24    🛠️ 461   🖥️ 38    ⚖  1 10000 980948 67731 1184140 
 ├─ ⏱ 18' 3" 60ms     📋 10838 📄 20    🛠️ 417   🖥️ 28    ⚖  0 1630 192833 13015 231877 
 ├─ ⏱ 19' 3" 93ms     📋 11363 📄 20    🛠️ 364   🖥️ 38    ⚖  0 826 91503 6851 112055 
 ├─ ⏱ 20' 3" 149ms    📋 12037 📄 28    🛠️ 296   🖥️ 47    ⚖  0 291 22061 1768 27364 
 ├─ 📑  Ficheiro Resultados/damascp_9.csv gravado.
 │  ⏱  Tempo real: 20' 59" 347ms 
 │  ⏱  CPU total: 16h 26' 29" 294ms 
 │  ⏱  Espera do gestor: 20' 59" 19ms 
 │  ⏱  Espera trabalhadores: 1' 52" 998ms 
 │  📊  Utilização:
 │  - Total: 97.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 20' 59" 347ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_9

| P19 vs P24 | 1:Hamming | 2:Euclidiana | 3:Manhattan |
|:---:|---:|---:|---:|
| 0 | **5306** | 5339 | 5343 |
| 1 | 9470 | 5560 | 5562 |
| 2 | 10000 | 5350 | 5678 |
| 4 | 10000 | 5638 | 6421 |
| 8 | 10000 | 5714 | 8855 |

O valor por omissão, com a distância mínima a 0 e utilizar a distância mais básica, a Hamming,
é a que dá melhores resultados.
Os restantes tipos de distâncias são também competitivos, e nesse caso a utilização de uma distância mínima superior a 0
pode ser uma alternativa. Mantemos os valores por omissão.

### Resultados: damascp_9


| P19 vs P24 | 1:Hamming | 2:Kendall tau | 3:Spearman footrule |
|:---:|---:|---:|---:|
| 0 | **413** | 3651 | 513 |
| 1 | 413 | 5799 | 514 |
| 2 | 1624 | 6990 | 1840 |
| 4 | 4361 | 8123 | 3484 |
| 8 | 7335 | 8948 | 5300 |

Na codificação de permutação aparenta não existir grande vantagem em alterar o tipo de distância.
A distância mínima 1 pode ser uma alternativa, mas não existindo vantagem clara, optamos por manter os valores por omissão.

## Teste 10

Neste teste vamos ver se os tipos de operadores utilizados têm impacto no resultado.

Parâmetro P20(TIPO_CRUZAR): (apenas em CI que utiliza cruzamento)
- 0: uniforme
- 1: 1-ponto (valor por omissão)
- 2: 2-pontos
- ...
- 10: 10-pontos

Vamos testar apenas alguns valores, já que se utilizar demasiados pontos acabará por ser igual ao operador uniforme: P20=0,1,2,3,4

Parâmetro P21(TIPO_MUTAR): (apenas em CP e CB que utilizam mutação)
- 0 - aplica um vizinho aleatório (codificação CP e CB)
- 1 a 100 - probabilidade de mutação para cada bit (codificação CB)

Parâmetro P22(TIPO_VIZINHO): (codificação CP, que utiliza a mutação)
- 1: inserir (valor por omissão)
- 2: trocaPar
- 3: inverterSegmento

Parâmetro P22(TIPO_VIZINHO): (codificação CB)
- 1 a 1000 - troca um segmento de N bit (N=1 troca um bit de cada vez)

Parâmetro P23(LIMITE_VIZINHOS):
- 0: não há limite (valor por omissão)
- 1 a 1000: limita a distância entre pares (para existirem menos vizinhos)

Para CP, atendendo a que P21=0 temos P22=1:3 e podemos analisar o impacto do limite dos vizinhos com P23=0,1,2,4,8
Para CB, há dois modos, mutar com determinada probabilidade cada bit, ou aplicar um vizinho que troca um segmento de N bits.
Vamos explorar ambas as possibilidades:
- P21=0 P22=1,2,4,8
- P21=1,2,5,10,20,50


- **Tipo de Teste / Objetivo**: Paramétrico P20/P21/P22/P23
- **Definição**:
	- **ci**: Instâncias: 20:29; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P20=0,1,2,3,4
	- **cp**: Instâncias: 20:29; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=1:3 x P23=0,1,2,4,8
	- **cb**: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=1,2,4,8
	- **cb**B: Instâncias: 948,864,930,922,764,692,806,926,904,870; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=1,2,5,10,20,50
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 20:29 -R Resultados/damasci_10 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P3=1:100 x P20=0,1,2,3,4
	- **cp**: TProcuraMelhorativa 2 20:29 -R Resultados/damascp_10 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P3=1:100 x P22=1:3 x P23=0,1,2,4,8
	- **cb**: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P3=1:10 x P22=1,2,4,8
	- **cb**B: TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P3=1:10 x P21=1,2,5,10,20,50


\htmlonly
<details>
  <summary>Ver script: evolutivos10.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos10
#SBATCH --output=Resultados/evolutivos10.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_10
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_10 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P3=1:100 x P20=0,1,2,3,4
# Teste: damascp_10
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_10 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P3=1:100 x P22=1:3 x P23=0,1,2,4,8
# Teste: particaocb_10
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P3=1:10 x P22=1,2,4,8
# Teste: particaocb_10B
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P3=1:10 x P21=1,2,5,10,20,50
</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>0 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P20=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P20=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P20=</span>0
 │ ...
 ├─ ⚙  [498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P20=</span>4
 ├─ ⚙  [499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P20=</span>4
 ├─ ⚙  [500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P20=</span>4
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:5000   📄 Instâncias: 10   🛠️ Configurações: 500   🖥️ Processos: 48.
 ├─ ⏱ 1' 29ms         📋 1111  📄 23    🛠️ 396   🖥️ 6     ⚖  0 5029 306558 13663 320220 
 ├─ ⏱ 2' 53ms         📋 2055  📄 21    🛠️ 295   🖥️ 2     ⚖  0 236 16393 726 17118 
 ├─ ⏱ 3' 65ms         📋 2832  📄 24    🛠️ 217   🖥️ 47    ⚖  0 601 35029 1551 36579 
 ├─ ⏱ 4' 265ms        📋 3426  📄 27    🛠️ 161   🖥️ 41    ⚖  0 4514 228252 10066 238317 
 ├─ ⏱ 5' 272ms        📋 3957  📄 25    🛠️ 107   🖥️ 33    ⚖  0 4076 227530 10032 237561 
 ├─ ⏱ 6' 406ms        📋 5000  📄 27    🛠️ 0     🖥️ 12    ⚖  0 7739 379261 17041 396301 
 ├─ 📑  Ficheiro Resultados/damasci_10.csv gravado.
 │  ⏱  Tempo real: 6' 725ms 
 │  ⏱  CPU total: 4h 42' 34" 66ms 
 │  ⏱  Espera do gestor: 6' 615ms 
 │  ⏱  Espera trabalhadores: 4' 29" 88ms 
 │  📊  Utilização:
 │  - Total: 96.4%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 98.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 6' 725ms ) ═══

═╤═ Instâncias ═══ { 📄 20 📄 21 📄 22 📄 23 📄 24 📄 25 📄 26 📄 27 📄 28 📄 29 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0
 │ ...
 ├─ ⚙  [1498] ─ <span style="color:gray">P3=</span>98 <span style="color:gray">P22=</span>3 <span style="color:gray">P23=</span>8
 ├─ ⚙  [1499] ─ <span style="color:gray">P3=</span>99 <span style="color:gray">P22=</span>3 <span style="color:gray">P23=</span>8
 ├─ ⚙  [1500] ─ <span style="color:gray">P3=</span>100 <span style="color:gray">P22=</span>3 <span style="color:gray">P23=</span>8
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:15000   📄 Instâncias: 10   🛠️ Configurações: 1500   🖥️ Processos: 48.
 ├─ ⏱ 1' 50ms         📋 3831  📄 20    🛠️ 1117  🖥️ 24    ⚖  0 82 10046 663 12034 
 ├─ ⏱ 2' 111ms        📋 6374  📄 29    🛠️ 871   🖥️ 25    ⚖  1 10000 840079 54097 1002369 
 ├─ ⏱ 3' 232ms        📋 6919  📄 21    🛠️ 808   🖥️ 42    ⚖  0 170 20230 1302 24135 
 ├─ ⏱ 4' 335ms        📋 8095  📄 25    🛠️ 692   🖥️ 32    ⚖  0 1864 164334 12773 202652 
 ├─ ⏱ 5' 573ms        📋 8884  📄 21    🛠️ 613   🖥️ 31    ⚖  0 1184 124386 9645 153320 
 ├─ ⏱ 6' 689ms        📋 9283  📄 21    🛠️ 576   🖥️ 46    ⚖  2 8400 1000008 64044 1192139 
 ├─ ⏱ 7' 1" 127ms     📋 9602  📄 23    🛠️ 544   🖥️ 6     ⚖  2 9270 1000002 65119 1195358 
 ├─ ⏱ 8' 1" 160ms     📋 9922  📄 22    🛠️ 512   🖥️ 39    ⚖  2 8694 1000001 62564 1187692 
 ├─ ⏱ 9' 1" 176ms     📋 10244 📄 21    🛠️ 480   🖥️ 22    ⚖  1 8981 1000007 71328 1213990 
 ├─ ⏱ 10' 1" 305ms    📋 10574 📄 29    🛠️ 447   🖥️ 11    ⚖  3 10000 792555 57248 964298 
 ├─ ⏱ 11' 1" 402ms    📋 10899 📄 24    🛠️ 415   🖥️ 17    ⚖  1 10000 979630 70403 1190838 
 ├─ ⏱ 12' 1" 509ms    📋 11247 📄 22    🛠️ 381   🖥️ 29    ⚖  2 9473 1000006 71977 1215936 
 ├─ ⏱ 13' 1" 559ms    📋 11581 📄 29    🛠️ 347   🖥️ 13    ⚖  3 10000 789271 57177 960801 
 ├─ ⏱ 14' 1" 683ms    📋 11926 📄 24    🛠️ 313   🖥️ 36    ⚖  1 10000 965579 69484 1174030 
 ├─ 📑  Ficheiro Resultados/damascp_10.csv gravado.
 │  ⏱  Tempo real: 14' 57" 912ms 
 │  ⏱  CPU total: 11h 43' 21" 858ms 
 │  ⏱  Espera do gestor: 14' 57" 593ms 
 │  ⏱  Espera trabalhadores: 1' 53" 866ms 
 │  📊  Utilização:
 │  - Total: 97.7%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.7% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 14' 57" 912ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P22=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P22=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P22=</span>1
 │ ...
 ├─ ⚙  [38] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P22=</span>8
 ├─ ⚙  [39] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P22=</span>8
 ├─ ⚙  [40] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P22=</span>8
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:400   📄 Instâncias: 10   🛠️ Configurações: 40   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/particaocb_10.csv gravado.
 │  ⏱  Tempo real: 1" 526ms 
 │  ⏱  CPU total: 1' 11" 717ms 
 │  ⏱  Espera do gestor: 1" 517ms 
 │  ⏱  Espera trabalhadores: 39" 728ms 
 │  📊  Utilização:
 │  - Total: 43.5%
 │  - Gestor: 0.3%
 │  - Trabalhadores: 44.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 1" 526ms ) ═══

═╤═ Instâncias ═══ { 📄 692 📄 764 📄 806 📄 864 📄 870 📄 904 📄 922 📄 926 📄 930 📄 948 } 
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P22=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1 <span style="color:gray">P21=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2 <span style="color:gray">P21=</span>1
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3 <span style="color:gray">P21=</span>1
 │ ...
 ├─ ⚙  [58] ─ <span style="color:gray">P3=</span>8 <span style="color:gray">P21=</span>50
 ├─ ⚙  [59] ─ <span style="color:gray">P3=</span>9 <span style="color:gray">P21=</span>50
 ├─ ⚙  [60] ─ <span style="color:gray">P3=</span>10 <span style="color:gray">P21=</span>50
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:600   📄 Instâncias: 10   🛠️ Configurações: 60   🖥️ Processos: 48.
 ├─ ⏱ 1' 39ms         📋 378   📄 692   🛠️ 25    🖥️ 13    ⚖  0 3965 192989 9189 202177 
 ├─ 📑  Ficheiro Resultados/particaocb_10B.csv gravado.
 │  ⏱  Tempo real: 1' 24" 629ms 
 │  ⏱  CPU total: 1h 6' 17" 582ms 
 │  ⏱  Espera do gestor: 1' 24" 615ms 
 │  ⏱  Espera trabalhadores: 4' 22" 275ms 
 │  📊  Utilização:
 │  - Total: 91.5%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 93.4% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 1' 24" 629ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_10

| P20(TIPO_CRUZAR) | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 0:uniforme | **2224** | 2105 | 2343 | 443 | 1626 | 4791 |
| 1:1-ponto | 5309 | 5104 | 5513 | 1264 | 4778 | 10000 |
| 2:2-pontos | 3617 | 3443 | 3791 | 688 | 2826 | 8168 |
| 3:3-pontos | 2988 | 2832 | 3144 | 581 | 2209 | 6716 |
| 4:4-pontos | 2617 | 2479 | 2756 | 506 | 1912 | 5724 |

Este último teste é identificado uma grande melhoria, o operador de cruzamento uniforome tem clara vantagem
sobre o operador de cruzamento 1-ponto, que era o valor por omissão. Este operador é até a pior opção entre as possíveis.
Aparenta existir vantagem por fazer operadores com muitos pontos, e com este valor muito grande acaba por ser igual
ao operador uniforme.
Vamos portanto alterar P20=0.


### Resultados: damascp_10

| P23 vs P22 | 1:inserir | 2:trocaPar | 3:inverterSegmento |
|:---:|---:|---:|---:|
| 0 | 413 | **19** | 1227 |
| 1 | 8282 | 8704 | 8876 |
| 2 | 3594 | 2042 | 5185 |
| 4 | 529 | 65 | 1836 |
| 8 | 350 | 23 | 1122 |

Pudemos observar neste último teste um grande ganho no operador, mais de uma ordem de grandeza
considerando o limimite de vizinhança 0 (inativo). Ativando o limite de vizinhança, se muito reduzido degrada,
mas a partir de certo ponto melhora.
Vamos assim manter P23=0 e alterar P22=2. Estes resultados baixam tanto o tempo médio de resolução que para continuar
a analisar mais parâmetros, tinhamos de alterar o conjunto das instâncias de teste.

### Resultados: particaocb_10

| P22 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1 | 274 | 220 | 328 | 30 | 173 | 615 |
| 2 | 16 | 15 | 18 | 7 | 15 | 27 |
| 4 | **13** | 12 | 14 | 6 | 12 | 21 |
| 8 | 15 | 13 | 17 | 7 | 14 | 25 |

| P21 | Eficiência (média) | ICinf | ICsup | P10 | Med | P90 |
|:---:|---:|---:|---:|---:|---:|---:|
| 1 | **2198** | 1837 | 2559 | 336 | 1867 | 4469 |
| 2 | 3779 | 3155 | 4403 | 490 | 2816 | 10000 |
| 5 | 6185 | 5496 | 6873 | 1306 | 6507 | 10000 |
| 10 | 8043 | 7460 | 8626 | 3217 | 10000 | 10000 |
| 20 | 8255 | 7657 | 8854 | 2079 | 10000 | 10001 |
| 50 | 8825 | 8329 | 9321 | 3876 | 10000 | 10001 |

Estes resolutados até aparentam ser de problemas distintos ou indicadores distintos.
Mas a diferença é a que a mutação utiliza um tipo vizinho P22 no primeiro caso, em que um segmento de N bits é trocado.
Esta mutação dá clara vantagem, mais de uma ordem de grandeza,
relativamente à alternativa com P21 de alterar a probabilidade de mutação de cada bit.
Mesmo na melhor alternativa, o anterior valor por omissão com P22=1 revela-se pouco eficiente quando comparado com
P22=4, baixando o tempo médio de resolução para 13 miléssimas de segundo.


## Teste 11

Vamos fazer agora um teste final idêntico ao teste 1 mas com a parametrização obtida, de modo a quantificar
o ganho no conjunto completo de instâncias.

- **Tipo de Teste / Objetivo**: Performance (Eficácia / Eficiência vs tamanho)
- **Definição**:
	- **ci**: Instâncias: 4:40; Configurações: P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P20=0
	- **cp**: Instâncias: 4:40; Configurações: P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0
	- **cb**: Instâncias: 2:1000; Configurações: P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=4
- **Esforço**:
	- **ci+cp**: P3=1:100
	- **cb**: P3=1:10
- **Execução**:
	- **ci**: TProcuraMelhorativa 1 4:40 -R Resultados/damasci_11 -M 1 -P P2=2 P3=1:100 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P20=0
	- **cp**: TProcuraMelhorativa 2 4:40 -R Resultados/damascp_11 -M 1 -P P2=2 P3=1:100 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0
	- **cb**: TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_11 -M 1 -P P2=2 P3=1:10 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=4



\htmlonly
<details>
  <summary>Ver script: evolutivos11.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos11
#SBATCH --output=Resultados/evolutivos11.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_11
srun bin/MPI/TProcuraMelhorativa 1 4:40 -R Resultados/damasci_11 -M 1 -P P2=2 P3=1:100 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P20=0
# Teste: damascp_11
srun bin/MPI/TProcuraMelhorativa 2 4:40 -R Resultados/damascp_11 -M 1 -P P2=2 P3=1:100 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0
# Teste: particaocb_11
srun bin/MPI/TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_11 -M 1 -P P2=2 P3=1:10 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=4

</pre>
</details>
<details>
  <summary>Ver execução:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>100 <span style="color:gray">P8=</span>0 <span style="color:gray">P9=</span>1 <span style="color:gray">P10=</span>175 <span style="color:gray">P13=</span>1 <span style="color:gray">P14=</span>100
 ├─ ⚙   ─ <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>0 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>0 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>1 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 │ ...
 ├─ ⚙  [98] ─ <span style="color:gray">P3=</span>98
 ├─ ⚙  [99] ─ <span style="color:gray">P3=</span>99
 ├─ ⚙  [100] ─ <span style="color:gray">P3=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3700   📄 Instâncias: 37   🛠️ Configurações: 100   🖥️ Processos: 48.
 ├─ ⏱ 1' 76ms         📋 1201  📄 27    🛠️ 67    🖥️ 19    ⚖  0 378 18416 830 19245 
 ├─ ⏱ 2' 251ms        📋 2354  📄 18    🛠️ 36    🖥️ 5     ⚖  0 287 24221 1084 25304 
 ├─ ⏱ 3' 417ms        📋 3483  📄 15    🛠️ 6     🖥️ 33    ⚖  0 799 83544 3716 87259 
 ├─ 📑  Ficheiro Resultados/damasci_11.csv gravado.
 │  ⏱  Tempo real: 3' 19" 438ms 
 │  ⏱  CPU total: 2h 36' 13" 595ms 
 │  ⏱  Espera do gestor: 3' 19" 359ms 
 │  ⏱  Espera trabalhadores: 4' 34" 693ms 
 │  📊  Utilização:
 │  - Total: 95.0%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 97.1% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 3' 19" 438ms ) ═══

═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>2 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 │ ...
 ├─ ⚙  [98] ─ <span style="color:gray">P3=</span>98
 ├─ ⚙  [99] ─ <span style="color:gray">P3=</span>99
 ├─ ⚙  [100] ─ <span style="color:gray">P3=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
[cna1349:19422:0:19422] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x30616a46476400)
[cna1349:19432:0:19432] Caught signal 11 (Segmentation fault: invalid permissions for mapped object at address 0x470010)
[cna1349:19398:0:19398] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xfffffffdf0daad30)
[cna1349:19402:0:19402] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x4)
[cna1349:19413:0:19413] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x7c042f9400800)
[cna1349:19434:0:19434] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xfffffffdf0daba60)
==== backtrace (tid:  19432) ====
=================================
[cna1349:19414:0:19414] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x22e3677a6041a0)
==== backtrace (tid:  19422) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19398) ====
 0 0x00000000004253f4 TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 1 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 2 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 3 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 4 0x0000000000401eb0 TProcura::main()  ???:0
 5 0x00000000004022e0 main()  ???:0
 6 0x0000000000020de4 __libc_start_main()  ???:0
 7 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19434) ====
 0 0x00000000004253f4 TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 1 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 2 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 3 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 4 0x0000000000401eb0 TProcura::main()  ???:0
 5 0x00000000004022e0 main()  ???:0
 6 0x0000000000020de4 __libc_start_main()  ???:0
 7 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19437:0:19437] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x400000012)
==== backtrace (tid:  19414) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19394:0:19394] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x30616a46476400)
[cna1349:19418:0:19418] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x1700000011)
[cna1349:19423:0:19423] Caught signal 11 (Segmentation fault: invalid permissions for mapped object at address 0x43b21c)
[cna1349:19403:0:19403] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x8)
[cna1349:19410:0:19410] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x61687420726566)
==== backtrace (tid:  19437) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
[cna1349:19397:0:19397] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x7c042f9400800)
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19419:0:19419] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x1000000c8)
==== backtrace (tid:  19394) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19418) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19423) ====
 0 0x0000000000413978 TVector<int>::operator[]()  ???:0
 1 0x000000000042c888 TCodificacaoPermutacao::Distancia()  ???:0
 2 0x000000000041ec78 TProcuraMelhorativa::AplicarDiversidadeAE()  ???:0
 3 0x0000000000426354 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 4 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 5 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 6 0x0000000000401eb0 TProcura::main()  ???:0
 7 0x00000000004022e0 main()  ???:0
 8 0x0000000000020de4 __libc_start_main()  ???:0
 9 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19403) ====
 0 0x0000000000417798 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19410) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19435:0:19435] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x7c042f9400800)
==== backtrace (tid:  19419) ====
 0 0x000000000041de80 TProcuraMelhorativa::AplicarDiversidadeAE()  ???:0
 1 0x0000000000426354 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 2 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 3 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 4 0x0000000000401eb0 TProcura::main()  ???:0
 5 0x00000000004022e0 main()  ???:0
 6 0x0000000000020de4 __libc_start_main()  ???:0
 7 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19415:0:19415] Caught signal 11 (Segmentation fault: invalid permissions for mapped object at address 0x470010)
[cna1349:19425:0:19425] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x500000003)
[cna1349:19395:0:19395] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xb)
srun: error: cna1349: task 22: Segmentation fault (core dumped)
==== backtrace (tid:  19415) ====
=================================
==== backtrace (tid:  19425) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19395) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19411:0:19411] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xffffffffffffffff)
[cna1349:19416:0:19416] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x30616a46476400)
srun: error: cna1349: tasks 4,6-7,11,23,27,31,34,41,43,46: Segmentation fault (core dumped)
==== backtrace (tid:  19411) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
[cna1349:19405:0:19405] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x8)
[cna1349:19399:0:19399] Caught signal 11 (Segmentation fault: address not mapped to object at address 0x800000008)
==== backtrace (tid:  19416) ====
 0 0x0000000000417794 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
srun: error: cna1349: tasks 3,12,19,32,44: Segmentation fault (core dumped)
==== backtrace (tid:  19405) ====
 0 0x0000000000417798 TProcuraMelhorativa::LibertarVector()  TProcuraMelhorativa.cpp:0
 1 0x00000000004257fc TProcuraMelhorativa::SelecionarSobreviventesAE()  ???:0
 2 0x0000000000426324 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x00000000004022e0 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
srun: error: cna1349: task 28: Segmentation fault (core dumped)
srun: error: cna1349: task 24: Segmentation fault (core dumped)
srun: error: cna1349: tasks 8,20: Segmentation fault (core dumped)
srun: error: cna1349: task 25: Segmentation fault (core dumped)
srun: error: cna1349: task 14: Segmentation fault (core dumped)
slurmstepd: error:  mpi/pmix_v4: _errhandler: cna1349 [0]: pmixp_client_v2.c:212: Error handler invoked: status = -61, source = [slurm.pmix.683947.1:22]
slurmstepd: error: *** STEP 683947.1 ON cna1349 CANCELLED AT 2025-11-15T17:47:54 ***
srun: Job step aborted: Waiting up to 32 seconds for job step to finish.
 ├─ 📋 Tarefas:3700   📄 Instâncias: 37   🛠️ Configurações: 100   🖥️ Processos: 48.srun: error: cna1349: tasks 0-2,5,9-10,13,15-18,21,26,29-30,33,35-40,42,45,47: Killed


═╤═ Instâncias ═══ { 📄 2 📄 3 📄 4 … 📄 998 📄 999 📄 1000 } #999
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>4<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 ├─ ⚙  [4] ─ <span style="color:gray">P3=</span>4
 ├─ ⚙  [5] ─ <span style="color:gray">P3=</span>5
 ├─ ⚙  [6] ─ <span style="color:gray">P3=</span>6
 ├─ ⚙  [7] ─ <span style="color:gray">P3=</span>7
 ├─ ⚙  [8] ─ <span style="color:gray">P3=</span>8
 ├─ ⚙  [9] ─ <span style="color:gray">P3=</span>9
 ├─ ⚙  [10] ─ <span style="color:gray">P3=</span>10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:9990   📄 Instâncias: 999   🛠️ Configurações: 10   🖥️ Processos: 48.
[cna1349:19860:0:19860] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xffffffffff92b4f8)
[cna1349:19858:0:19858] Caught signal 11 (Segmentation fault: address not mapped to object at address 0xffffffffffc76778)
==== backtrace (tid:  19860) ====
 0 0x0000000000428d14 TCodificacaoBinaria::Mutar()  ???:0
 1 0x000000000041a824 TProcuraMelhorativa::ReproduzirAE()  ???:0
 2 0x00000000004262f0 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x0000000000402288 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
==== backtrace (tid:  19858) ====
 0 0x0000000000428d14 TCodificacaoBinaria::Mutar()  ???:0
 1 0x000000000041a824 TProcuraMelhorativa::ReproduzirAE()  ???:0
 2 0x00000000004262f0 TProcuraMelhorativa::AlgoritmoEvolutivo()  ???:0
 3 0x0000000000410940 TProcura::ExecutaTarefa()  ???:0
 4 0x0000000000410dd8 TProcura::TesteEmpiricoTrabalhador()  ???:0
 5 0x0000000000401eb0 TProcura::main()  ???:0
 6 0x0000000000402288 main()  ???:0
 7 0x0000000000020de4 __libc_start_main()  ???:0
 8 0x0000000000402418 _start()  ???:0
=================================
srun: error: cna1349: tasks 1,3: Segmentation fault (core dumped)
slurmstepd: error:  mpi/pmix_v4: _errhandler: cna1349 [0]: pmixp_client_v2.c:212: Error handler invoked: status = -61, source = [slurm.pmix.683947.2:3]
srun: Job step aborted: Waiting up to 32 seconds for job step to finish.
slurmstepd: error: *** STEP 683947.2 ON cna1349 CANCELLED AT 2025-11-15T17:49:03 ***
 ├─ ⏱ 1' 14ms         📋 850   📄 161   🛠️ 9     🖥️ 35    ⚖  5716 3456 1000019 47619 1047637 srun: error: cna1349: tasks 0,2,4-47: Killed

</pre>
</details>

Houve crash devido a dois bugs em damascp_11 e particaocb_11, pelo que submeteu-se nova corrida.
<details>
  <summary>Ver script: evolutivos11B.sh</summary>
<pre>
#!/bin/bash
#SBATCH --job-name=evolutivos11b
#SBATCH --output=Resultados/evolutivos11b.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damascp_11
srun bin/MPI/TProcuraMelhorativa 2 4:40 -R Resultados/damascp_11 -M 1 -P P2=2 P3=1:100 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0
# Teste: particaocb_11
srun bin/MPI/TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_11 -M 1 -P P2=2 P3=1:10 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=4
</pre>
</details>
<details>
  <summary>Ver execução B:</summary>
<pre>
mpic++ -Wall -O3 -DMPI_ATIVO -o bin/MPI/TProcuraMelhorativa ../../TProcura.cpp ../../TRand.cpp ../TProcuraMelhorativa.cpp ../TCodificacaoArvore.cpp ../TCodificacaoBinaria.cpp ../TCodificacaoInteira.cpp ../TCodificacaoReal.cpp ../TCodificacaoPermutacao.cpp ProblemaArtificial.cpp OitoDamas.cpp teste.cpp Particao.cpp


═╤═ Instâncias ═══ { 📄 4 📄 5 📄 6 … 📄 38 📄 39 📄 40 } #37
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>10 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>10 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>3
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P15=</span>2 <span style="color:gray">P16=</span>3 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>3 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>3 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>2 <span style="color:gray">P23=</span>0 <span style="color:gray">P24=</span>1<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 │ ...
 ├─ ⚙  [98] ─ <span style="color:gray">P3=</span>98
 ├─ ⚙  [99] ─ <span style="color:gray">P3=</span>99
 ├─ ⚙  [100] ─ <span style="color:gray">P3=</span>100
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:3700   📄 Instâncias: 37   🛠️ Configurações: 100   🖥️ Processos: 48.
 ├─ 📑  Ficheiro Resultados/damascp_11.csv gravado.
 │  ⏱  Tempo real: 1" 833ms 
 │  ⏱  CPU total: 1' 26" 143ms 
 │  ⏱  Espera do gestor: 1" 758ms 
 │  ⏱  Espera trabalhadores: 3" 386ms 
 │  📊  Utilização:
 │  - Total: 94.0%
 │  - Gestor: 1.6%
 │  - Trabalhadores: 96.0% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 1" 833ms ) ═══

═╤═ Instâncias ═══ { 📄 2 📄 3 📄 4 … 📄 998 📄 999 📄 1000 } #999
 ├─ 🛠️  ─ <span style="color:gray">P1=</span>1 <span style="color:gray">P2=</span>2 <span style="color:gray">P4=</span>10 <span style="color:gray">P5=</span>1000000 <span style="color:gray">P6=</span>20 <span style="color:gray">P7=</span>0 <span style="color:gray">P8=</span>100 <span style="color:gray">P9=</span>2 <span style="color:gray">P11=</span>4 <span style="color:gray">P12=</span>100 <span style="color:gray">P13=</span>1
 ├─ ⚙   ─ <span style="color:gray">P14=</span>100 <span style="color:gray">P16=</span>1 <span style="color:gray">P17=</span>1 <span style="color:gray">P18=</span>1 <span style="color:gray">P19=</span>0 <span style="color:gray">P20=</span>1 <span style="color:gray">P21=</span>0 <span style="color:gray">P22=</span>4<span style="color:gray"> (parâmetros comuns)</span>
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ <span style="color:gray">P3=</span>1
 ├─ ⚙  [2] ─ <span style="color:gray">P3=</span>2
 ├─ ⚙  [3] ─ <span style="color:gray">P3=</span>3
 ├─ ⚙  [4] ─ <span style="color:gray">P3=</span>4
 ├─ ⚙  [5] ─ <span style="color:gray">P3=</span>5
 ├─ ⚙  [6] ─ <span style="color:gray">P3=</span>6
 ├─ ⚙  [7] ─ <span style="color:gray">P3=</span>7
 ├─ ⚙  [8] ─ <span style="color:gray">P3=</span>8
 ├─ ⚙  [9] ─ <span style="color:gray">P3=</span>9
 ├─ ⚙  [10] ─ <span style="color:gray">P3=</span>10
═╧═══════════════════
═╤═ 🧪  Início do Teste (🖥️ 0) ═══
 ├─ 📋 Tarefas:9990   📄 Instâncias: 999   🛠️ Configurações: 10   🖥️ Processos: 48.
 ├─ ⏱ 1' 676ms        📋 846   📄 159   🛠️ 9     🖥️ 29    ⚖  5672 3687 1000019 47619 1047636 
 ├─ ⏱ 2' 4" 123ms     📋 1751  📄 249   🛠️ 8     🖥️ 32    ⚖  13236 4387 1000019 47619 1047636 
 ├─ ⏱ 3' 6" 985ms     📋 2656  📄 347   🛠️ 7     🖥️ 21    ⚖  32022 5169 1000019 47619 1047636 
 ├─ ⏱ 4' 8" 850ms     📋 3561  📄 501   🛠️ 6     🖥️ 29    ⚖  88160 6338 1000019 47619 1047636 
 ├─ ⏱ 5' 9" 826ms     📋 4466  📄 613   🛠️ 5     🖥️ 27    ⚖  137466 7231 1000019 47619 1047636 
 ├─ ⏱ 6' 9" 829ms     📋 5391  📄 693   🛠️ 4     🖥️ 2     ⚖  164094 7956 1000019 47619 1047636 
 ├─ ⏱ 7' 10" 888ms    📋 6308  📄 723   🛠️ 3     🖥️ 23    ⚖  181844 8072 1000019 47619 1047636 
 ├─ ⏱ 8' 17" 88ms     📋 7275  📄 791   🛠️ 2     🖥️ 29    ⚖  224468 8604 1000019 47619 1047636 
 ├─ ⏱ 9' 17" 654ms    📋 8222  📄 829   🛠️ 1     🖥️ 26    ⚖  225412 8929 1000019 47619 1047636 
 ├─ ⏱ 10' 22" 867ms   📋 9179  📄 881   🛠️ 0     🖥️ 36    ⚖  288522 9317 1000019 47619 1047636 
 ├─ 📑  Ficheiro Resultados/particaocb_11.csv gravado.
 │  ⏱  Tempo real: 11' 13" 728ms 
 │  ⏱  CPU total: 8h 47' 45" 232ms 
 │  ⏱  Espera do gestor: 11' 13" 537ms 
 │  ⏱  Espera trabalhadores: 48" 197ms 
 │  📊  Utilização:
 │  - Total: 97.8%
 │  - Gestor: 0.0%
 │  - Trabalhadores: 99.8% 
═╧═ 🏁  Fim do Teste (🖥️ 0  ⏱ 11' 13" 728ms ) ═══
</pre>
</details>
\endhtmlonly

### Resultados: damasci_11

| Instância | Eficácia<br>base | otimizado | Eficiência<br>base | otimizado |
|:---:|---:|---:|---:|---:|
| 4 | 100 | 100 | 0 | 0 |
| 5 | 100 | 100 | 1 | 1 |
| 6 | 100 | 100 | 16 | 14 |
| 7 | 100 | 100 | 15 | 10 |
| 8 | 100 | 100 | 40 | 29 |
| 9 | 100 | 100 | 66 | 45 |
| 10 | 100 | 100 | 213 | 136 |
| 11 | 100 | 100 | 358 | 210 |
| 12 | 100 | 100 | 475 | 292 |
| 13 | 100 | 100 | 779 | 338 |
| 14 | 100 | 100 | 1073 | 340 |
| 15 | 100 | 100 | 1688 | 451 |
| 16 | 99 | 100 | 1980 | 716 |
| 17 | 95 | 100 | 3455 | 736 |
| 18 | 94 | 100 | 4102 | 789 |
| 19 | 83 | 100 | 4985 | 998 |
| 20 | 66 | 100 | 5545 | 1300 |
| 21 | 48 | 100 | 7279 | 1253 |
| 22 | 38 | 99 | 8247 | 1495 |
| 23 | 31 | 100 | 8365 | 1757 |
| 24 | 22 | 100 | 8830 | 1959 |
| 25 | 10 | 100 | 9514 | 2675 |
| 26 | 11 | 98 | 9582 | 2683 |
| 27 | 6 | 99 | 9690 | 2873 |
| 28 | 6 | 96 | 9631 | 2991 |
| 29 | 1 | 99 | 9965 | 3261 |
| 30 | 2 | 90 | 9889 | 4164 |
| 31 | 3 | 95 | 9976 | 4224 |
| 32 | 1 | 89 | 9953 | 4499 |
| 33 | 0 | 90 | 10000 | 4831 |
| 34 | 0 | 77 | 10000 | 5812 |
| 35 | 0 | 74 | 10000 | 6205 |
| 36 | 0 | 79 | 10000 | 5871 |
| 37 | 1 | 80 | 9966 | 6158 |
| 38 | 0 | 72 | 10000 | 6732 |
| 39 | 0 | 53 | 10000 | 7471 |
| 40 | 0 | 55 | 10000 | 8029 |
| Total Geral | 49 | 93 | 5829 | 2469 |

Esta codificação inteira não é a mais aconselhada para as 8 damas.
A codificação permutação é mais natural já que trata de duas restrições na própria codificação.
No entanto podemos ver que a versão otimizada consegue mesmo nas instâncias maiores resolver mais de 50%,
enquanto que a configuração de base só resolve esporadicamente.
Em termos globais utilizando as 40 instâncias, a configuração base tem 49% de eficácia, contra 93% da versão otimizada.
Por outro lado a eficiênica é também mais baixa, 5,8 segundos contra 2,4 segundos da versão otimizada.

### Resultados: damascp_11

| Instância | Eficácia<br>base | otimizado | Eficiência<br>base | otimizado |
|:---:|---:|---:|---:|---:|
| 4 | 100 | 100 | 0 | 0 |
| 5 | 100 | 100 | 0 | 0 |
| 6 | 100 | 100 | 1 | 3 |
| 7 | 100 | 100 | 1 | 0 |
| 8 | 100 | 100 | 2 | 1 |
| 9 | 100 | 100 | 5 | 2 |
| 10 | 100 | 100 | 23 | 3 |
| 11 | 100 | 100 | 48 | 4 |
| 12 | 100 | 100 | 74 | 4 |
| 13 | 100 | 100 | 155 | 5 |
| 14 | 100 | 100 | 353 | 6 |
| 15 | 100 | 100 | 518 | 7 |
| 16 | 100 | 100 | 816 | 8 |
| 17 | 100 | 100 | 2057 | 9 |
| 18 | 97 | 100 | 2924 | 11 |
| 19 | 77 | 100 | 4991 | 12 |
| 20 | 68 | 100 | 6104 | 12 |
| 21 | 35 | 100 | 8262 | 14 |
| 22 | 20 | 100 | 9007 | 16 |
| 23 | 9 | 100 | 9591 | 17 |
| 24 | 7 | 100 | 9694 | 22 |
| 25 | 5 | 100 | 9782 | 19 |
| 26 | 5 | 100 | 9781 | 22 |
| 27 | 2 | 100 | 9852 | 24 |
| 28 | 2 | 100 | 9964 | 27 |
| 29 | 1 | 100 | 9910 | 28 |
| 30 | 1 | 100 | 9910 | 33 |
| 31 | 0 | 100 | 10000 | 37 |
| 32 | 0 | 100 | 10000 | 36 |
| 33 | 0 | 100 | 10000 | 44 |
| 34 | 0 | 100 | 10000 | 48 |
| 35 | 0 | 100 | 10000 | 48 |
| 36 | 0 | 100 | 10000 | 53 |
| 37 | 0 | 100 | 10000 | 49 |
| 38 | 0 | 100 | 10000 | 60 |
| 39 | 0 | 100 | 10000 | 61 |
| 40 | 0 | 100 | 10000 | 66 |
| Total Geral | 47 | 100 | 5779 | 22 |

A versão base com a codificação em permutação tinha um comportamento comparável com a codificação inteira.
Já a versão otimizada tem um resultado que nem se compara. Resolve todas as instâncias em algumas dezenas de milissegundos.

Para continuar a otimizar esta versão teriamos de avançar para instâncias maiores, atendendo aos baixos tempos de resolução.

### Resultados: particaocb_11

| Instância | Eficácia<br>base | otimizado | Eficiência<br>base | otimizado |
|:---:|---:|---:|---:|---:|
| 2 | 40 | 40 | 1265 | 1393 |
| 3 | 0 | 0 | 2200 | 2398 |
| 4 | 30 | 30 | 1687 | 1690 |
| 5 | 0 | 0 | 2721 | 2446 |
| 6 | 40 | 40 | 1794 | 1473 |
| 7 | 0 | 0 | 3239 | 2481 |
| 8 | 50 | 50 | 1726 | 1240 |
| 9 | 0 | 0 | 3624 | 2522 |
| 10 | 100 | 100 | 0 | 1 |
| 11 | 0 | 0 | 3950 | 2534 |
| 12 | 100 | 100 | 1 | 1 |
| 13 | 0 | 0 | 4269 | 2564 |
| 14 | 100 | 100 | 1 | 1 |
| 15 | 0 | 0 | 4535 | 2568 |
| 16 | 100 | 100 | 2 | 0 |
| 17 | 10 | 10 | 4350 | 2365 |
| 18 | 100 | 100 | 3 | 0 |
| 19 | 0 | 0 | 5121 | 2606 |
| 950 | 90 | 100 | 3651 | 10 |
| 951 | 0 | 0 | 10001 | 9903 |
| 952 | 90 | 100 | 5131 | 10 |
| 953 | 0 | 0 | 10001 | 9901 |
| 954 | 80 | 100 | 4655 | 15 |
| 955 | 0 | 0 | 10001 | 9951 |
| 956 | 80 | 100 | 4421 | 16 |
| 957 | 0 | 0 | 10001 | 9960 |
| 958 | 90 | 100 | 3990 | 14 |
| 959 | 0 | 0 | 10002 | 9957 |
| 960 | 100 | 100 | 3444 | 13 |
| 961 | 0 | 0 | 10001 | 9986 |
| 962 | 90 | 100 | 3098 | 12 |
| 963 | 0 | 0 | 10001 | 9993 |
| 964 | 60 | 100 | 6508 | 18 |
| 965 | 0 | 0 | 10002 | 10000 |
| 966 | 100 | 100 | 3765 | 11 |
| 967 | 0 | 0 | 10001 | 10000 |
| 968 | 80 | 100 | 5274 | 13 |
| 969 | 0 | 0 | 10001 | 10000 |
| 970 | 80 | 100 | 5751 | 15 |
| 971 | 0 | 0 | 10001 | 10000 |
| 972 | 80 | 100 | 4069 | 13 |
| 973 | 0 | 0 | 10001 | 10000 |
| 974 | 90 | 100 | 3872 | 14 |
| 975 | 0 | 0 | 10002 | 10000 |
| 976 | 100 | 100 | 2648 | 16 |
| 977 | 0 | 0 | 10001 | 10000 |
| 978 | 80 | 100 | 5548 | 15 |
| 979 | 0 | 0 | 10001 | 10000 |
| 980 | 90 | 100 | 3708 | 12 |
| 981 | 0 | 0 | 10001 | 10000 |
| 982 | 70 | 100 | 6540 | 10 |
| 983 | 0 | 0 | 10002 | 10000 |
| 984 | 100 | 100 | 3347 | 12 |
| 985 | 0 | 0 | 10002 | 10000 |
| 986 | 70 | 100 | 5319 | 12 |
| 987 | 0 | 0 | 10001 | 10000 |
| 988 | 40 | 100 | 7574 | 17 |
| 989 | 0 | 0 | 10002 | 10000 |
| 990 | 90 | 100 | 3824 | 17 |
| 991 | 0 | 0 | 10001 | 10000 |
| 992 | 100 | 100 | 4143 | 16 |
| 993 | 0 | 0 | 10001 | 10000 |
| 994 | 80 | 100 | 4976 | 17 |
| 995 | 0 | 0 | 10001 | 10000 |
| 996 | 70 | 100 | 4391 | 15 |
| 997 | 0 | 0 | 10001 | 10000 |
| 998 | 90 | 100 | 2824 | 12 |
| 999 | 0 | 0 | 10002 | 10000 |
| 1000 | 80 | 100 | 4548 | 14 |
| Total Geral | 48 | 50 | 5802 | 3188 |

Este problema temos a situação das instâncias impossíveis.
Estas instâncias têm por vezes tempos de resolução distintos, dado que o critério de paragem do número de iterações é
nas instâncias mais pequenas atingido antes do tempo limite.
Mesmo assim podemos observar nas últimas instâncias que a eficiência sobe de 48% para 50%,
sendo provavelmente os 50% o maior valor possível dado que há instâncias impossíveis.
Nas instâncias resolvidas os tempos são consideravelmente inferiores, de 2 a 4 segundos por instância para apenas algumas
dezenas de milissegundos para encontrar a solução.
Como nesta tabela os resultados das instâncias possíveis são apresentados em conjunto com as instâncias impossíveis,
a diferença na eficiência aparece diluida, mas mesmo assim melhora de 5,8 segundos para 3,1 segundos.

Para instâncias possíveis a configuração optimiada é muito eficáz e eficiente.

