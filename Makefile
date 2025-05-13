# Variáveis
CC = g++               # Compilador
CFLAGS = -Wall -g      # Flags de compilação
TARGET = testePConstrutiva      # Executável gerado
SRC = TProcuraConstrutiva.cpp TRand.cpp Teste/ProblemaArtificial.cpp Teste/teste.cpp    # Ficheiros fonte
FTeste = Teste/CasosTeste/input.txt Teste/CasosTeste/output_esperado.txt

# Regra padrão (executada com `make` sem argumentos)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para testes (executada com `make check`)
check: $(TARGET)
	@echo "Executando testes..."
	@./$(TARGET) < Teste/CasosTeste/input.txt > Teste/CasosTeste/output_obtido.txt
	@diff --ignore-matching-lines='^Resultado: [0-9]+ \([0-9]+,[0-9]+s\)$' Teste/CasosTeste/output_obtido.txt Teste/CasosTeste/output_esperado.txt || (echo "Testes falharam"; exit 1)
	@echo "Todos os testes passaram!"

# Regra para validação completa (executada com `make distcheck`)
distcheck: check
	@echo "Validando distribuição..."
	@tar czf $(TARGET).tar.gz $(SRC) Makefile  $(FTeste)
	@echo "Distribuição validada: $(TARGET).tar.gz"

# Limpar ficheiros gerados (executada com `make clean`)
clean:
	@echo "Limpando ficheiros..."
	@rm -f $(TARGET) Teste/CasosTeste/output_obtido.txt $(TARGET).tar.gz
