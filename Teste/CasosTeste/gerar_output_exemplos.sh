cd ..
make 
cd CasosTeste
../bin/Release/TProcura < input1.txt > output1.txt
../bin/Release/TProcura < input2.txt > output2.txt

./converter_cores.sh
