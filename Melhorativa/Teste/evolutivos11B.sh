#!/bin/bash
#SBATCH --job-name=evolutivos11b
#SBATCH --output=Resultados/evolutivos11b.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damascp_11
srun bin/MPI/TProcuraMelhorativa 2 4:40 -R Resultados/damascp_11 -M 1 -P P2=2 P3=1:100 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P22=2 P23=0
# Teste: particaocb_11
srun bin/MPI/TProcuraMelhorativa 3 2:1000 -R Resultados/particaocb_11 -M 1 -P P2=2 P3=1:10 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P22=4
