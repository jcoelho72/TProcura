#!/bin/bash
#SBATCH --job-name=evolutivos2
#SBATCH --output=Resultados/evolutivos2.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=10:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }

# Teste: damasci_2
srun bin/MPI/TProcuraMelhorativa 1 10:19 -R Resultados/damasci_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200

# Teste: damascp_2
srun bin/MPI/TProcuraMelhorativa 2 10:19 -R Resultados/damascp_2 -M 1 -P P2=2 P3=1:100 x P6=5,10,15,20,25,30,40,50,75,100,150,200

# Teste: particaocb_2
srun bin/MPI/TProcuraMelhorativa 3 948,864,930,922,764,692,806,926,904,870 -R Resultados/particaocb_2 -M 1 -P P2=2 P3=1:10 x P6=5,10,15,20,25,30,40,50,75,100,150,200

