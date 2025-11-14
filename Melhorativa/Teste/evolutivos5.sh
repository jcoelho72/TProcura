#!/bin/bash
#SBATCH --job-name=evolutivos5
#SBATCH --output=Resultados/evolutivos5.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_5A
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5A -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=1 P3=1:100 x P10=100:200:25
# Teste: damascp_5A
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5A -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=1 P3=1:100 x P10=100:200:25
# Teste: particaocb_5A
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5A -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=1 P3=1:10 x P10=100:200:25
# Teste: damasci_5B
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_5B -M 1 -P P2=2 P6=20 P7=100 P8=0 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
# Teste: damascp_5B
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_5B -M 1 -P P2=2 P6=10 P7=0 P8=100 P9=2 P3=1:100 x P11=2,3,4,6,10 x P12=25:100:25
# Teste: particaocb_5B
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_5B -M 1 -P P2=2 P6=20 P7=0 P8=100 P9=2 P3=1:10 x P11=2,3,4,6,10 x P12=25:100:25

