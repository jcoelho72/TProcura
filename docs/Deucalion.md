@page deucalion Deucalion

Página com documentação de utilização do TProcura no cluster Deucalion.


## Sumário

- [Ação 1: Documentação](#deucalion-a1)
- [Ação 2: Estratégia de funcionamento](#deucalion-a2)
- [Ação 3: Reprodução de Execuções](#deucalion-a3)


\anchor deucalion-a1
## Ação 1: Documentação

Documentação do cluster Deucalion pode ser encontrada em: https://docs.deucalion.macc.fccn.pt/

Principais comandos:

module load OpenMPI

- sbatch - submete um trabalho
- squeue - vê a fila de trabalhos
	- squeue --me - apenas os trabalhos do próprio
	- squeue --me --start - vê quando os trabalhos do próprio vão começar
- scancel <jobid> - cancela um trabalho
- sinfo - vê o estado dos nós do cluster
- mpirun - executa um programa paralelo

#!/bin/bash
#SBATCH --job-name=exampleJob
#SBATCH --account=exampleAccount
#SBATCH --partition=examplePartition
#SBATCH --time=02:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=2G

$ sbatch [options] job_script [job_script_arguments ...]


Compilar (no nó de execução):
- salloc -N1 -p dev-arm -A <account> -t 4:00:00 >>> aloca um nó interativo onde se compila na arquitetura ARM
> executar "make mpi"
  (compilação recomendada: mpicc -O2 -ftree-vectorize -march=native -fno-math-errno sample.c )

\anchor deucalion-a2
## Ação 2: Estratégia de funcionamento

- no cluster fazer "git clone" para obter o código
- para adicionar ou editar um ficheiro, fazer localmente e atualizar o repositório
- no clusetr fazer apenas "git pull" para ficar com os ficheiros atualizados



\anchor deucalion-a3
## Ação 1: Reprodução de Execuções

Lista de execuções:
- 
