#!/bin/bash

while true; do
	# executar mestre
	./bin/Release/TProcuraAdversa 4 -R resultados -S anterior <<< "2"
	if cmp -s resultados.csv anterior.csv; then
		break
	fi
	cp resultados.csv anterior.csv
	# executar adversário (1s por jogada, faz 10s)
	if ! timeout 11s ./bin/Release/TProcuraAdversa 4 -R resultados -S anterior2 -P P1=2 P4=1 P7=2 P12=2 P10=0 P15=300 <<< "2"; then 
		echo "Tempo excedido no adversário" 
		break 
	fi

	cp resultados.csv anterior2.csv
done
