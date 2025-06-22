cmd /c "..\..\x64\Debug\TProcuraAdversa.exe < input.txt > output1.txt"
powershell -Command "Get-Content output1.txt | Set-Content -Encoding utf8 output.txt"
del output1.txt