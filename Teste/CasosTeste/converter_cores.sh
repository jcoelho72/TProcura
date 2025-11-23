#!/bin/bash
rm -f *_cores.txt *_texto.txt
for f in output*.txt; do
  sed -E \
    -e 's/\x1b\[38;2;([0-9]+);([0-9]+);([0-9]+)m/<span style="color:rgb(\1,\2,\3)">/g' \
    -e 's/\x1b\[48;2;([0-9]+);([0-9]+);([0-9]+)m/<span style="background-color:rgb(\1,\2,\3)">/g' \
    -e 's/\x1b\[0m/<\/span>/g' \
    -e 's/\x1b\[90m/<span style="color:gray">/g' \
    "$f" > "${f%.txt}_cores.txt"
  sed -E \
    -e 's/\x1b\[38;2;([0-9]+);([0-9]+);([0-9]+)m//g' \
    -e 's/\x1b\[48;2;([0-9]+);([0-9]+);([0-9]+)m//g' \
    -e 's/\x1b\[0m//g' \
    -e 's/\x1b\[90m//g' \
    "$f" > "${f%.txt}_texto.txt"
done

echo 'Colocar o código copiado entre \htmlonly <pre> e </pre> \endhtmlonly'
