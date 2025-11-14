#!/bin/bash
#SBATCH --job-name=evolutivos7
#SBATCH --output=Resultados/evolutivos7.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_7
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_7 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P3=1:100 x P16=0:5 x P17=0:5
# Teste: damascp_7
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_7 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P3=1:100 x P16=0:5 x P17=0:5
# Teste: particaocb_7
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_6 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P3=1:10 x P16=0:5 x P17=0:5

