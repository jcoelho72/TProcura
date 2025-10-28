#!/bin/bash
#SBATCH --job-name=tvetor
#SBATCH --output=Resultados/tvetor.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=dev-arm
#SBATCH --time=01:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=2G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }


# Teste 1

# esforço A
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_1m0 -M 0 -P P1=2 P2=3 P3=1
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_1 -M 1 -P P1=2 P2=3 P3=1

# esforço B
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_1Bmo -M 0 -P P1=2 P2=3 P3=1:10
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_1B -M 1 -P P1=2 P2=3 P3=1:10

# esforço C
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_1C -M 1 -P P1=2 P2=2 P3=1:100

# Teste 2

# esforço A
mpirun ./bin/mpi/TProcura 1 -R Resultados/tvetor_2mo -M 0 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10
mpirun ./bin/mpi/TProcura 1 -R Resultados/tvetor_2 -M 1 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10

# esforço B
mpirun ./bin/mpi/TProcura 1:4 -R Resultados/tvetor_2Bmo -M 0 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10
mpirun ./bin/mpi/TProcura 1:4 -R Resultados/tvetor_2B -M 1 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10

# esforço C
mpirun ./bin/mpi/TProcura 1:10 -R Resultados/tvetor_2C -M 1 -P P2=3 P1=1:12 x P6=1:3 x P3=1:10
