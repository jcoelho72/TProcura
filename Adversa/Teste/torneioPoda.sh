#!/bin/bash
#SBATCH --job-name=torneioPoda
#SBATCH --output=Resultados/torneioPoda.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioPoda
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioPoda -M 1 -P P2=2 P4=1 P7=0 P1=2 P12=1 P11=1 P15=300 P16=100 P3=1:2 x P13=0,4,8,16,32
