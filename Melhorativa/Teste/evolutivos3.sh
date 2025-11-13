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

