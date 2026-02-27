#!/bin/bash

# ---------------------------------------------------------
# Script de exemplo para testar TProcuraExecutavel
# Aceita parâmetros arbitrários e produz indicadores
# com prefixos reconhecidos pelo TProcuraExecutavel.
# ---------------------------------------------------------

# Ler argumentos (não interessa o significado real)
PARAM1=0
PARAM2=0

while [[ $# -gt 0 ]]; do
    case "$1" in
        -p1)
            PARAM1="$2"
            shift 2
            ;;
        -p2)
            PARAM2="$2"
            shift 2
            ;;
        *)
            # Último argumento é a instância (ID)
            INSTANCIA="$1"
            shift
            ;;
    esac
done

# Gerar valores aleatórios para os indicadores
# Ind1: inteiro entre 0 e 100
IND1=$(( RANDOM % 101 ))

# Resultado: 0 ou 1
RESULTADO=$(( RANDOM % 2 ))

# Tempo: número real entre 0.0 e 5.0
TEMPO=$(awk -v r=$RANDOM 'BEGIN { printf("%.3f", (r % 5000) / 1000.0) }')

# mostrar parâmetros e instância 
echo "Execução com Param1=$PARAM1 Param2=$PARAM2 Instancia=$INSTANCIA" 

# Output no formato esperado pelo TProcuraExecutavel
echo "Ind1: $IND1"
echo "Resultado: $RESULTADO"
echo "Tempo: $TEMPO"

