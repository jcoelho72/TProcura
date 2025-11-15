#!/bin/bash
#SBATCH --job-name=evolutivos10
#SBATCH --output=Resultados/evolutivos10.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_10
srun bin/MPI/TProcuraMelhorativa 1 20:29 -R Resultados/damasci_10 -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P10=175 P13=1 P14=100 P16=1 P17=0 P18=3 P19=0 P24=1 P3=1:100 x P20=0,1,2,3,4
# Teste: damascp_10
srun bin/MPI/TProcuraMelhorativa 2 20:29 -R Resultados/damascp_10 -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P11=10 P12=100 P13=3 P14=100 P15=2 P16=3 P17=1 P18=3 P19=0 P24=1 P21=0 P3=1:100 x P22=1:3 x P23=0,1,2,4,8
# Teste: particaocb_10
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10 -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P21=0 P3=1:10 x P22=1,2,4,8
# Teste: particaocb_10B
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_10B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P11=4 P12=100 P13=1 P14=100 P16=1 P17=1 P18=1 P3=1:10 x P21=1,2,5,10,20,50
