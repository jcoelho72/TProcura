cmd /c "..\x64\Release\TProcura.exe 1,3 -R out -P P1=1:12 x P6=1:3 > output.txt"
powershell -Command "Get-Content output.txt | Set-Content -Encoding utf8 outputTVector1.txt"
rem cmd /c "..\..\x64\Release\TProcura.exe 1:10 -R Resultados/outSort -P P1=2 P3=1:10 x P6=1:3 > output.txt"
rem powershell -Command "Get-Content output.txt | Set-Content -Encoding utf8 outputTVector2.txt"
del output.txt
