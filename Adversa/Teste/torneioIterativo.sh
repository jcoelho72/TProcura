#!/bin/bash
#SBATCH --job-name=torneioIterativo
#SBATCH --output=Resultados/torneioIterativo.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioIterativo
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioIterativo -M 1 -P P2=2 P4=1 P7=0 P1=1,2 x P12=0:2 
