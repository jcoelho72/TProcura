cd ..
make 
cd CasosTeste
../bin/Release/TProcuraMelhorativa < input1.txt > output1.txt
../bin/Release/TProcuraMelhorativa < input2.txt > output2.txt
../bin/Release/TProcuraMelhorativa < input3.txt > output3.txt
../bin/Release/TProcuraMelhorativa < input1opt.txt > output1opt.txt
../bin/Release/TProcuraMelhorativa < input2opt.txt > output2opt.txt
../bin/Release/TProcuraMelhorativa < input3opt.txt > output3opt.txt

./converter_cores.sh
