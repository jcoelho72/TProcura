#!/bin/bash
#SBATCH --job-name=construtiva2
#SBATCH --output=Resultados/construtiva2.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI
make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: puzzle8_1
# esforço C --- sem P1=1
srun bin/MPI/TProcuraConstrutiva 2 1:1000 -R Resultados/puzzle8_1C -M 1 -P P2=2 P1=3:7 x P3=1:4

# Teste: particao_1
# esforço C --- P1=3 (corrigido)
srun bin/MPI/TProcuraConstrutiva 4 2:200:20 -R Resultados/particao_1C -M 1 -P P1=3 P2=2 P7=-1 P3=1:100 x P8=1,3

# Teste: particao_3
# esforço C --- repetir já que não terminou
srun bin/MPI/TProcuraConstrutiva 4 2:1000 -R Resultados/particao_3C -M 1 -P P1=3 P2=2 P7=-1 P8=3 P11=1 P3=1:40
