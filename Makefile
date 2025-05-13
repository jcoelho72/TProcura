# Variáveis
CC = g++               # Compilador
CFLAGS = -Wall -g      # Flags de compilação
TARGET = testePConstrutiva      # Executável gerado
SRC = TProcuraConstrutiva.cpp TRand.cpp Teste/ProblemaArtificial.cpp Teste/teste.cpp    # Ficheiros fonte

# Regra padrão (executada com `make` sem argumentos)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para testes (executada com `make check`)
check: $(TARGET)
	@echo "Executando testes..."
	@./$(TARGET) < Teste/CasosTeste/input.txt > Teste/CasosTeste/output_obtido.txt
	@diff tests/output_obtido.txt tests/output_esperado.txt || (echo "Testes falharam"; exit 1)
	@echo "Todos os testes passaram!"

# Regra para validação completa (executada com `make distcheck`)
distcheck: check
	@echo "Validando distribuição..."
	@tar czf $(TARGET).tar.gz $(SRC) Makefile
	@echo "Distribuição validada: $(TARGET).tar.gz"

# Limpar ficheiros gerados (executada com `make clean`)
clean:
	@echo "Limpando ficheiros..."
	@rm -f $(TARGET) tests/output_obtido.txt $(TARGET).tar.gz
