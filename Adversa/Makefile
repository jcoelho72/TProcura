# Variáveis
CC = g++
CFLAGS = -Wall -g
TARGET = TProcuraAdversa
SRC =  TProcuraAdversa.cpp TProcuraConstrutiva/TProcuraConstrutiva.cpp TProcuraConstrutiva/TRand.cpp Teste/JogoDoGalo.cpp Teste/teste.cpp Teste/JogoEmLinha.cpp 
FTeste = Teste/CasosTeste/input.txt Teste/CasosTeste/output.txt 

# Regra padrão (executada com `make` sem argumentos)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para testes (executada com `make check`)
check: $(TARGET)
	@echo "Executando testes..."
	@./$(TARGET) < Teste/CasosTeste/input.txt > Teste/CasosTeste/output_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/output_obtido.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/output.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_esperado.txt
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
