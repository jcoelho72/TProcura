cmd /c "..\..\x64\Debug\TProcuraConstrutiva.exe < input.txt > output.txt"
powershell -Command "Get-Content output.txt | Set-Content -Encoding utf8 output_esperado.txt"
del output.txt