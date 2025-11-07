#!/bin/bash
#SBATCH --job-name=construtiva
#SBATCH --output=Resultados/construtiva.txt
#SBATCH --account=f202507959cpcaa0a
#SBATCH --partition=normal-arm
#SBATCH --time=02:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=48
#SBATCH --cpus-per-task=1
#SBATCH --mem=24G

ml OpenMPI

make mpi || { echo "Compilação falhou"; exit 1; }


# Teste: puzzle8_1

# esforço A
srun bin/MPI/TProcuraConstrutiva 2 1:1000:100 -R Resultados/puzzle8_1 -M 1 -P P2=3 P1=1,3:7 x P3=1:4
 
# esforço B
srun bin/MPI/TProcuraConstrutiva 2 1:1000:10 -R Resultados/puzzle8_1B -M 1 -P P2=3 P1=1,3:7 x P3=1:4

# esforço C
srun bin/MPI/TProcuraConstrutiva 2 1:1000 -R Resultados/puzzle8_1C -M 1 -P P2=2 P1=1,3:7 x P3=1:4

# Teste: 8damas_1

# esforço A
srun bin/MPI/TProcuraConstrutiva 3 4:40 -R Resultados/8damas_1 -M 1 -P P1=3 P2=4 P7=-1 P8=1,3

# Teste: 8damas_2

# esforço A
srun bin/MPI/TProcuraConstrutiva 3 4:40 -R Resultados/8damas_2 -M 1 -P P1=3 P2=3 P7=-1 P8=1 P11=0,1 x P3=1:4

# Teste: 8damas_3

# esforço A
srun bin/MPI/TProcuraConstrutiva 3 4:40 -R Resultados/8damas_3 -M 1 -P P1=3 P2=3 P7=-1 P8=1 P11=1 P3=1:10

# esforço B
srun bin/MPI/TProcuraConstrutiva 3 4:40 -R Resultados/8damas_3B -M 1 -P P1=3 P2=3 P7=-1 P8=1 P11=1 P3=1:100

# esforço C
srun bin/MPI/TProcuraConstrutiva 3 4:40 -R Resultados/8damas_3C -M 1 -P P1=3 P2=2 P7=-1 P8=1 P11=1 P3=1:1000

# Teste: particao_1

# esforço A
srun bin/MPI/TProcuraConstrutiva 4 2:200:20 -R Resultados/particao_1 -M 1 -P P1=3 P2=4 P7=-1 P3=1 P8=1,3

# esforço B
srun bin/MPI/TProcuraConstrutiva 4 2:200:20 -R Resultados/particao_1B -M 1 -P P1=3 P2=3 P7=-1 P3=1:10 x P8=1,3

# esforço C
srun bin/MPI/TProcuraConstrutiva 4 2:200:20 -R Resultados/particao_1C -M 1 -P P1=2 P2=2 P7=-1 P3=1:100 x P8=1,3

# Teste: particao_2

# esforço A
srun bin/MPI/TProcuraConstrutiva 4 2:100:10 -R Resultados/particao_2 -M 1 -P P1=3 P2=3 P7=-1 P8=3 P3=1:4 x P11=0,1

# esforço B
srun bin/MPI/TProcuraConstrutiva 4 2:100:10 -R Resultados/particao_2B -M 1 -P P1=3 P2=3 P7=-1 P8=3 P3=1:40 x P11=0,1

# esforço C
srun bin/MPI/TProcuraConstrutiva 4 2:100:10 -R Resultados/particao_2C -M 1 -P P1=3 P2=2 P7=-1 P8=3 P3=1:400 x P11=0,1

# Teste: particao_3

# esforço A
srun bin/MPI/TProcuraConstrutiva 4 2:1000:100 -R Resultados/particao_3 -M 1 -P P1=3 P2=3 P7=-1 P8=3 P11=1 P3=1:4

# esforço B
srun bin/MPI/TProcuraConstrutiva 4 2:1000:10 -R Resultados/particao_3B -M 1 -P P1=3 P2=3 P7=-1 P8=3 P11=1 P3=1:40

# esforço C
srun bin/MPI/TProcuraConstrutiva 4 2:1000 -R Resultados/particao_3C -M 1 -P P1=3 P2=2 P7=-1 P8=3 P11=1 P3=1:40
