cd ..
make 
cd CasosTeste
../bin/Release/TProcuraAdversa < inputGalo1.txt > outputGalo1.txt
../bin/Release/TProcuraAdversa < inputGalo2.txt > outputGalo2.txt
../bin/Release/TProcuraAdversa < inputGalo3.txt > outputGalo3.txt
../bin/Release/TProcuraAdversa < inputGalo4.txt > outputGalo4.txt
../bin/Release/TProcuraAdversa < inputGalo5.txt > outputGalo5.txt
../bin/Release/TProcuraAdversa < inputGalo6.txt > outputGalo6.txt
../bin/Release/TProcuraAdversa < inputGalo7.txt > outputGalo7.txt

../bin/Release/TProcuraAdversa < inputLinha1.txt > outputLinha1.txt
../bin/Release/TProcuraAdversa < inputLinha2.txt > outputLinha2.txt
../bin/Release/TProcuraAdversa < inputLinha3.txt > outputLinha3.txt

./converter_cores.sh
