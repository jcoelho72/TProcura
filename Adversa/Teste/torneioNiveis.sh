#!/bin/bash
#SBATCH --job-name=torneioNiveis
#SBATCH --output=Resultados/torneioNiveis.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=04:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: torneioNiveis
srun bin/MPI/TProcuraAdversa 2 1:10 -R Resultados/TorneioNiveis -M 1 -P P2=2 P7=0 P4=4 P1=2 P12=1 P11=1 P15=300 P10=0 -P P4=1 -P P10=-1 -P P10=-4 P15=150 -P P7=2 P10=-1 P15=200 -P P10=-4 P15=150 -P P10=-16 P15=110 P14=10 -P P10=-64 P15=101 P14=4 
