cd ..
make 
cd CasosTeste
../bin/Release/TProcuraConstrutiva < inputAsp1.txt > outputAsp1.txt
../bin/Release/TProcuraConstrutiva < inputAsp2.txt > outputAsp2.txt
../bin/Release/TProcuraConstrutiva < inputPuzzle1.txt > outputPuzzle1.txt
../bin/Release/TProcuraConstrutiva < inputPuzzle2.txt > outputPuzzle2.txt
../bin/Release/TProcuraConstrutiva < inputDamas1.txt > outputDamas1.txt
../bin/Release/TProcuraConstrutiva < inputPart1.txt > outputPart1.txt

./converter_cores.sh
