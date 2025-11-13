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

