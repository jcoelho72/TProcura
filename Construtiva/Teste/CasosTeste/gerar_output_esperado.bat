cmd /c "..\x64\Debug\TProcuraConstrutiva.exe < inputAspirador.txt > output.txt"
powershell -Command "Get-Content output.txt | Set-Content -Encoding utf8 outputAspirador.txt"
del output.txt
