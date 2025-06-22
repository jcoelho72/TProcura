# Variáveis
CC = g++
CFLAGS = -Wall -g
TARGET = TProcuraConstrutiva
SRC = TProcura.cpp CListaNo.cpp TProcuraConstrutiva.cpp TRand.cpp Teste/ProblemaArtificial.cpp Teste/teste.cpp Teste/Aspirador.cpp Teste/OitoDamas.cpp Teste/Particao.cpp Teste/Puzzle8.cpp
FTeste = Teste/CasosTeste/inputAspirador.txt Teste/CasosTeste/outputAspirador.txt 

# Regra padrão (executada com `make` sem argumentos)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para testes (executada com `make check`)
check: $(TARGET)
	@echo "Executando testes..."
	@./$(TARGET) < Teste/CasosTeste/inputAspirador.txt > Teste/CasosTeste/output_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/output_obtido.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/outputAspirador.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_esperado.txt
	@diff Teste/CasosTeste/normalized_obtido.txt Teste/CasosTeste/normalized_esperado.txt || (echo "Testes falharam"; exit 1)
	@echo "Todos os testes passaram!"


# Regra para validação completa (executada com `make distcheck`)
distcheck: check
	@echo "Validando distribuição..."
	@tar czf $(TARGET).tar.gz $(SRC) Makefile $(FTeste)
	@echo "Distribuição validada: $(TARGET).tar.gz"

# Limpar ficheiros gerados (executada com `make clean`)
clean:
	@echo "Limpando ficheiros..."
	@rm -f $(TARGET) Teste/CasosTeste/output_obtido.txt $(TARGET).tar.gz
