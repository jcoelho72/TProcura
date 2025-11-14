@page melhorativa__deucalion Deucalion - testes melhorativos

Testes da classe TProcuraMelhorativa no cluster Deucalion.

A documentação do cluster Deucalion pode ser encontrada em: https://docs.deucalion.macc.fccn.pt/
A forma como se pode obter acesso ao cluster, bem como a submissão de trabalhos, está descrita nessa documentação.

Vamos fazer testes paramétricos no sentido de identificar para as três implementações, qual a melhor parametrização
no contexto dos algoritmos evolutivos. Pretendemos saber quais os parametros que têm impacto relevante na performance.

Os diversos testes irão ser feitos em paralelo nas três implementações, duas das 8 damas (codificação inteira e permutação),
e uma da partição codificação binária.

Atendendo a que todos os problemas são de procura, ficando o indicador I1 com o número de violações, podemos definir as
seguintes variáveis de análise.

Variáveis:
- Resolvido=(I1=0)
- Eficácia: Percentagem de instãncias resolvidas (=round(AVERAGE(bruto[Resolvido])*100;0))
- Eficiência: Tempo médio utilizado (=round(AVERAGE([I2(Tempo(ms))]);0))

Estas serão as variáveis de performance que iremos monitorizar para identificar a melhor parametrização.
Atendendo a que o tempo de execução está limitado a 10 segundos, o indicador de eficiência contém o da eficácia
mas apenas parcialmente, já que considera que as instâncias não resolvidas têm um custo de 10 segundos,
quando seria necessário mais tempo para as resolver.
O indicador da eficácia não distingue entre duas instâncias resolvidas,
mesmo que uma leve 0,1 segundos e a outra 5 segundos.

Um problema em que se pretenda optimizar, ao contrário destes que são de procura, ou seja, se pretendessemos minimizar I1,
teria de ter indicadores distintos, como distância relativa à solução ótima, ou a um valor mínimo conhecido.

Para averiguar se as diferenças obtidas na eficiência (tempo), são ou não relevantes, vamos calcular também o
intervalo de confiança a 95% para a eficiência:

- ICinf = round(AVERAGE([I2(Tempo(ms))]) - 1.96 * STDEV.S([I2(Tempo(ms))]) / SQRT(COUNTROWS(bruto));0)
- ICsup = round(AVERAGE([I2(Tempo(ms))]) + 1.96 * STDEV.S([I2(Tempo(ms))]) / SQRT(COUNTROWS(bruto));0)


## Teste 1

Vamos fazer um teste de performance inicial com a configuração base, ou seja, todos os parametros no seu
valor de omissão. Pretendemos ter uma avaliação sobre um conjunto alargado de instâncias, em termos de eficácia,
se o algoritmo foi bem sucedido, e eficiência, se foi rápido. Esta será uma referência que iremos repetir no final
com a configuração encontrada, e assim quantificar o ganho da realização dos testes paramétricos.

Como os três problemas utilizam codificações distintas, vamos identificar os problemas por CI (8 damas codificação inteira),
CP (8 damas codificação permutação) e CB (partição codificação binária).

Para as 8 damas com a codificação inteira e permutação, vamos utilizar o conjunto completo de instâncias. Como o algoritmo é aleatório,
vamos executar 100 execuções de modo a ganhar precisão sobre a capacidade da configuração base de resolver uma dada iostâsncia.

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
/TProcura/Construtiva/Teste$ sbatch evolutivos1.sh
</pre>
Podemos ver se o trabalho está em execução com:
<pre>
/TProcura/Construtiva/Teste$ squeue --me
</pre>
Para verificar o output do trabalho, mesmo durante a execução, consultamos o ficheiro Resultados/construtiva.txt vendo o final do ficheiro
<pre>
/TProcura/Teste$ tail -f Resultados/evolutivos1.txt
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

Vamos utilizar estes resultados para fixar o conjunto de teste para conter apenas
instâncias na fase de transição entre complexo e simples, evitando assim instâncias
demasiado simples que não ajudam a identificar a melhor parametrização, nem
instâncias demasiado complexas que gastam o tempo limite e apenas atrasam os resultados.

Vamos utilizar desde a instância 10, embora simples tem 0,2 segundos, até à instância 19,
em que nem sempre a instância é resolvida, e tem tempo médio de quase 5 segundos.

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
para os testes seguintes, de modo a apurar a melhor marametrização.


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
e apenas exporadicamente há uma instância par não resolvida.

A abordagem melhorativa não permite resolver instâncias sem solução, e provavelemnente nas instâncias ímparas, a razão para
não se encontrar a solução é por não existir a solução. Em algumas instâncias é possível confirmar com base
na execução das procuras construtivas, outras não.

Assim vamos utilizar para conjunto de teste apenas instâncias pares, que tenham sido todas resolvidas (com os 10 valores de P3),
com os maiores tempos.

Conjunto de teste: 948,864,930,922,764,692,806,926,904,870 

## Teste 2

Vamos agora iniciar o estudo dos parametros. Adoptamos a ordem com que estão definidos.
Alguns parametros são dependentes do valor de outros, pelo que são analisados em conjunto.

Arrancamos com o parametro P6 população. Este é um parametro determinante nos algoritmos evolutivos.

O valor de omissão é 20, vamos variar em valores baixos e altos.
Vamos começar com o valor 5, embora valores mais baixos
sejam possíveis, mas assim o algoritmo evolutivo assemelha-se a uma procura local e para funcionar
tem de se alterar outros parametros. Iremos estudar esta vertente numa fase posterior.

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

| P6(População) | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 5 | 24 | 5815 | 5649 | 5981 |
| 10 | 65 | 4301 | 4057 | 4545 |
| 15 | 89 | 2674 | 2466 | 2882 |
| 20 | 97 | **1840** | 1690 | 1989 |
| 25 | 96 | 2031 | 1867 | 2195 |
| 30 | 96 | 2272 | 2100 | 2444 |
| 40 | 92 | 2642 | 2450 | 2834 |
| 50 | 88 | 3209 | 2995 | 3422 |
| 75 | 74 | 4336 | 4088 | 4583 |
| 100 | 66 | 4960 | 4699 | 5221 |
| 150 | 56 | 5728 | 5464 | 5992 |
| 200 | 53 | 5973 | 5710 | 6236 |


Podemos observar que a população a 20, o valor de omissão, é nesta codificação o valor com melhores resultados.
O intervalo de confiança a 95% no valor 20 intersecta o de 25, mas é claramente melhor que todos os restanes valores.
O valor 10 ou inferior, e 40 ou superior, aparenta danificar consideravelmente a eficácia e a eficiência.

Mantemos o valor de omissão P6=20.

### Resultados: damascp_2

| P6(População) | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 5 | 91 | 1287 | 1155 | 1420 |
| 10 | 98 | **826** | 722 | 929 |
| 15 | 97 | 1148 | 1011 | 1286 |
| 20 | 98 | 1138 | 1004 | 1272 |
| 25 | 97 | 1389 | 1237 | 1540 |
| 30 | 97 | 1360 | 1216 | 1505 |
| 40 | 96 | 1582 | 1419 | 1744 |
| 50 | 95 | 1752 | 1581 | 1924 |
| 75 | 92 | 2201 | 2007 | 2395 |
| 100 | 88 | 2557 | 2345 | 2769 |
| 150 | 83 | 3051 | 2815 | 3286 |
| 200 | 81 | 3271 | 3028 | 3513 |

Na codificação permutação das 8 damas, ao contrário da codificação inteira, o valor da população mais eficiente é 10.
O intervalo de confiança nem intersecta qualquer um dos restantes valores.
Esta codificação no entanto não é tão sensivel a este parametro como a codificação inteira, mantendo no geral bons valores 
na eficácia e eficiência.

Vamos alterar o valor de omissão para P6=10.

### Resultados: particaocb_2

| P6(População) | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 5 | 73 | 5307 | 4601 | 6014 |
| 10 | 93 | 3510 | 2905 | 4115 |
| 15 | 94 | 3186 | 2648 | 3723 |
| 20 | 100 | 4528 | 3997 | 5059 |
| 25 | 91 | 4528 | 3937 | 5118 |
| 30 | 94 | 3417 | 2831 | 4002 |
| 40 | 86 | 4433 | 3792 | 5075 |
| 50 | 92 | 3960 | 3419 | 4502 |
| 75 | 80 | 5487 | 4866 | 6108 |
| 100 | 75 | 5850 | 5184 | 6517 |
| 150 | 61 | 7522 | 6999 | 8045 |
| 200 | 49 | 7553 | 6959 | 8147 |

O parametro P6(População) tem a eficácia a 100% apenas no valor de omissão 20.
No entanto existem valores com melhor eficiência.
Não se vê no entanto uma tendência clara, apenas uma zona que aparenta ser melhor, entre 10 e 50 elementos,
em que o tempo médio é inferior a 5 segundos. Os intervalos de confiança intersectam-se quase todos.
Assim, considera-se que este parametro não é crítico, e pelo menos na
configuração atual dos restantes parametros não há um claro valor melhor,
pelo que optou-se por manter o valor de omissão: P6=20.

## Teste 3

Vamos agora estudar a probabilidade de cruzamento e mutação, parametros P7 e P8, com os valores de omissão de 100 e 50 respetivamente.
Estes dois parametros são estudados em conjunto, já que se não existir cruzamento torna-se crítica a mutação, e vice-versa.
Existem estratégias que funcionam só com mutação ou só com cruzamento. Os operadores utilizados poderiam ser alvo de estudo,
mas de momento vamos manter os operadores de omissão e estudar apenas a probabilidade de aplicação.

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
Colocar este parametro a 0 reduz a diversidade, mas não elimina, atendendo a que existe um elemento estrangeiro em cada geração
que constantemente introduz diversidade na população.

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
- 1: Roleta (omissão)
- 2: Torneio
- 3: Uniforme

A roleta tem um parametro, o torneio tem dois, e o uniforme não tem paramertros.
Neste teste usamos os parametros internos de omissão para apurar se há diferenças significativas na estratégia de seleção dos pais.
Caso existam, cada método deve ser optimizado separadamente, variando os seus parametros internos, de modo a poder
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

| P9 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 1:Roleta | 99 | **1332** | 1220 | 1443 |
| 2:Torneio | 94 | 2173 | 1999 | 2348 |
| 3:Uniforme | 27 | 7363 | 7154 | 7573 |

Podemos observar que é crítica a estratégia de seleção dos pais. O método uniforme é claramente pior e não tem parametros,
pelo que descartamos. Pelo intervalo de confiança, com os valores de omissão, o método roleta seria o escolhido.
No entanto os métodos Roleta e Torneio têm parametros e precisam de ser explorados para identificar a melhor configuração.


### Resultados: damascp_4

| P9 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 1:Roleta | 100 | 175 | 154 | 196 |
| 2:Torneio | 100 | **115** | 101 | 128 |
| 3:Uniforme | 100 | 342 | 301 | 382 |

Podemos observar também diferenças grandes entre estratégias de seleção de pais.
Descartamos a seleção uniforme, que não tem parametros e tem uma eficiência inferior.
Nas restantes duas estratégias temos de identificar a melhor parametrização, para poder fazer uma escolha informada.

### Resultados: particaocb_4

| P9 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 1:Roleta | 95 | 2742 | 2239 | 3245 |
| 2:Torneio | 100 | **2005** | 1646 | 2365 |
| 3:Uniforme | 89 | 4589 | 3987 | 5192 |

Na partição observamos o mesmo que nas 8 damas em ambas as codificações, que a estratégias de seleção de pais é um passo crítico.
Descartamos a seleção uniforme, que não tem parametros e tem uma eficiência inferior.
Nas restantes duas estratégias temos de identificar a melhor parametrização, para poder fazer uma escolha informada.

## Teste 5

Análise dos parametros dos métodos de seleção Roleta e Torneio

O método da roleta tem o parametro P10(PRESSAO) com o valor de omissão de 150.
Este valor é entre 100 e 200, correspondendo a 1,00 e 2,00 respetivamente.
Este método irá escolher os pais com base no seu valor, cada um ficando com uma dada probabilidade na "roleta".
Valores perto de 1 dão valores quase iguais, e valores perto de 2 os melhores são muito favorecidos.

Vamos testar valores de 100 a 200 em intervalos de 25.

O método torneio seleciona um pai vencedor de um torneio. Faz-se quantos torneios forem necessários,
escolhendo membros da população aleatoriamente para entrarem no torneio.

Tem dois parametros:
- P11(TAMANHO_TORNEIO) - valor mínimo 2, podendo ir a valores altos como 100 - valor de omissão 2
- P12(PROB_MELHOR_TORNEIO) - probabilidade do participante com melhor valor, ganhar o torneio - valor de omissão 100%

Torneios grandes favorecem a que os melhores sejam sempre escolhidos, excepto se a probabilidade do melhor ganhar o torneio for baixa.

Vamos variar P11 nos valores baixos, e alguns valores altos: 2,3,4,6,10. Como a população num caso é de 10, aumentar este valor para além da população não faz muito sentido.
Para a probabilidade, vamos deixar de fora o valor 0, caso contrário seria uma escolha completamente aleatória, e variar em intervalos de 25.

Este teste será dividido em dois,um para cada parametro.

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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m100 [90mP8=[0m0 [90mP9=[0m1 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP10=[0m100
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP10=[0m100
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP10=[0m100
 │ ...
 ├─ ⚙  [498] ─ [90mP3=[0m98 [90mP10=[0m200
 ├─ ⚙  [499] ─ [90mP3=[0m99 [90mP10=[0m200
 ├─ ⚙  [500] ─ [90mP3=[0m100 [90mP10=[0m200
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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m10 [90mP7=[0m0 [90mP8=[0m100 [90mP9=[0m1 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m3 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP10=[0m100
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP10=[0m100
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP10=[0m100
 │ ...
 ├─ ⚙  [498] ─ [90mP3=[0m98 [90mP10=[0m200
 ├─ ⚙  [499] ─ [90mP3=[0m99 [90mP10=[0m200
 ├─ ⚙  [500] ─ [90mP3=[0m100 [90mP10=[0m200
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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m0 [90mP8=[0m100 [90mP9=[0m1 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP10=[0m100
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP10=[0m100
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP10=[0m100
 │ ...
 ├─ ⚙  [48] ─ [90mP3=[0m8 [90mP10=[0m200
 ├─ ⚙  [49] ─ [90mP3=[0m9 [90mP10=[0m200
 ├─ ⚙  [50] ─ [90mP3=[0m10 [90mP10=[0m200
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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m100 [90mP8=[0m0 [90mP9=[0m2 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP11=[0m2 [90mP12=[0m25
 │ ...
 ├─ ⚙  [1998] ─ [90mP3=[0m98 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [1999] ─ [90mP3=[0m99 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [2000] ─ [90mP3=[0m100 [90mP11=[0m10 [90mP12=[0m100
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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m10 [90mP7=[0m0 [90mP8=[0m100 [90mP9=[0m2 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m3 [90mP21=[0m0 [90mP22=[0m1 [90mP23=[0m0 [90mP24=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP11=[0m2 [90mP12=[0m25
 │ ...
 ├─ ⚙  [1998] ─ [90mP3=[0m98 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [1999] ─ [90mP3=[0m99 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [2000] ─ [90mP3=[0m100 [90mP11=[0m10 [90mP12=[0m100
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
 ├─ 🛠️  ─ [90mP1=[0m1 [90mP2=[0m2 [90mP4=[0m10 [90mP5=[0m1000000 [90mP6=[0m20 [90mP7=[0m0 [90mP8=[0m100 [90mP9=[0m2 [90mP13=[0m1 [90mP14=[0m100 [90mP16=[0m1
 ├─ ⚙   ─ [90mP17=[0m1 [90mP18=[0m3 [90mP19=[0m0 [90mP20=[0m1 [90mP21=[0m0 [90mP22=[0m1[90m (parâmetros comuns)[0m
═╪═ Configurações ═══
 ├─ ⚙  [1] ─ [90mP3=[0m1 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [2] ─ [90mP3=[0m2 [90mP11=[0m2 [90mP12=[0m25
 ├─ ⚙  [3] ─ [90mP3=[0m3 [90mP11=[0m2 [90mP12=[0m25
 │ ...
 ├─ ⚙  [198] ─ [90mP3=[0m8 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [199] ─ [90mP3=[0m9 [90mP11=[0m10 [90mP12=[0m100
 ├─ ⚙  [200] ─ [90mP3=[0m10 [90mP11=[0m10 [90mP12=[0m100
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

| P10 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 100 | 35 | 7190 | 6962 | 7419 |
| 125 | 79 | 3867 | 3627 | 4106 |
| 150 | 99 | 1330 | 1219 | 1442 |
| 175 | 100 | **1057** | 972 | 1141 |
| 200 | 99 | 1282 | 1176 | 1389 |

O melhor valor para P10 na roleta é 175. O intervalo de confiança não intersecta os restantes valores,
o que significa que uma valorização ainda maior dos melhores é preferivel.

Resultados para torneio:

| P11 vs P12 | 100 | 75 | 50 | 25 | 
|:---:|---:|---:|---:|---:|
| 2 | 2171 | 5102 | 7567 | 8406 | 
| 3 | **1315** | 1679 | 3938 | 7385 | 
| 4 | 1496 | 1360 | 1750 | 4450 | 
| 6 | 2311 | 1637 | 1618 | 1929 | 
| 10 | 3794 | 3209 | 2930 | 2723 | 

A melhor configuração é com P11=3, melhorando claramente relativamente ao torneio de 2.
Para valores de torneio pequenos, P12 é melhor sempre com o valor de omissão a 100%.
Apenas para torneios grandes é que P12 é melhor com valores menores, mas em termos globais
a melhor configuração é com P11=3 e P12=100.

Conjugando a roleta com o torneio, opta-se pela roleta dado que aprensenta valores melhores,
com os seguintes parametros: P9=1 P10=175.

### Resultados: damascp_5

Resultados para roleta:

| P10 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 100 | 100 | 379 | 328 | 430 |
| 125 | 100 | 228 | 202 | 254 |
| 150 | 100 | 175 | 154 | 196 |
| 175 | 100 | 138 | 123 | 154 |
| 200 | 100 | **101** | 90 | 112 |

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
Assim sendo escolhe-se o torneio com os seguintes parametros: P9=2 P11=10 P12=100

### Resultados: particaocb_5

Resultados para roleta:

| P10 | Eficácia | Eficiência | ICinf | ICsup |
|:---:|---:|---:|---:|---:|
| 100 | 81 | 5045 | 4359 | 5730 |
| 125 | 92 | 3195 | 2614 | 3777 |
| 150 | 95 | 2741 | 2238 | 3244 |
| 175 | 96 | 2519 | 2030 | 3009 |
| 200 | 99 | **2354** | 1922 | 2785 |

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

Assim sendo, entre a roleta e o torneio, é preferivel o torneio, com os parametros: P9=2 P11=4 P12=100

## Teste 6

Passamos para a fase da sobrevivência, em que o parametro base é P13. Existem 3 valores possíveis:
- 1: Idade (valor de omissão)
- 2: Substitui piores
- 3: round-robin

Este parametro é utilizado em conjunção com o P14(PERC_DESCENDENTES), cujo valor de omissão é 100%.
Neste caso os descendentes são iguais à população, pelo que no método da idade são todos substituídos.

Nos restantes dois métodos, qualquer que seja a percentagem, os decendentes são adicionados à população e
no segundo caso são removidos os piores, no terceiro round-robin existe um torneio de cada elemento com Q outros.
Os que perderem mais vezes, são removidos.

O método round-robin tem portanto um parametro Q, que é o número de torneios:  P15(Q_ROUND_ROBIN).
Tem o valor de omissão a 3, mas pode ser desde 2 até um valor alto como 100, mas não fará sentido ser superior à população.

Vamos para já deixar este valor de omissão, e fazer um teste com P13 e P14, para apurar se a
estratégia de sobrevivência é muito relevante ou não, e se a percentagem de descendentes é ou não relevante.

Vamos variar P14 de 0 a 100 em passos de 25, tal como temos feito para as restantes percentagens.
Quando P14=0 significa que haverá apenas um só descendente (e não 0) em cada geração.

Vamos ainda alterar o conjunto de teste das 8 damas, atendendo a que os tempos de resolução são demasiado baixos
para a codificação de permutação, com tempos médios a baixo de 0,05 segundos. Escolhemos as instâncias seguintes,
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


</pre>
</details>
\endhtmlonly

### Resultados: damasci_6


### Resultados: damascp_6


### Resultados: particaocb_6


## Teste 7

P16(ELITISMO) + P17(IMIGRANTES)

## Teste 8

P18(DIVERSIDADE)

## Teste 9

P19(DIST_MINIMA) + P24(TIPO_DISTANCIA)

## Teste 10

P20(TIPO_CRUZAR) + P21(TIPO_MUTAR) +  P23(LIMITE_VIZINHOS)






