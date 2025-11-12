#!/bin/bash
#SBATCH --job-name=construtiva
#SBATCH --output=Resultados/construtiva.txt
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
srun bin/MPI/TProcuraMelhorativa 1 4:40 -R Resultados/damasci_1 -P P2=2 P3=1:100

# Teste: damascp_1
srun bin/MPI/TProcuraMelhorativa 2 4:40 -R Resultados/damascp_1 -P P2=2 P3=1:100

# Teste: particaocb_1
srun bin/MPI/TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_1 -P P2=2 P3=1:10

