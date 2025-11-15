#!/bin/bash
#SBATCH --job-name=evolutivos9
#SBATCH --output=Resultados/evolutivos9.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_9
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_9 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3
# Teste: damascp_9
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_9 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P3=1:100 x P19=0,1,2,4,8 x P24=1:3
