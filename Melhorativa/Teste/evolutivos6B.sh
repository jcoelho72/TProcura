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

# Teste: damascp_6B
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_6B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P3=1:100 x P15=2,3,4,6,10

