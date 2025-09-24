# Variáveis
CC = g++
MPICC = mpic++
CFLAGS = -Wall -g
TARGET = TProcura
TARGET_MPI = TProcuraMPI
SRC = TProcura.cpp TRand.cpp Teste/CTesteTVector.cpp Teste/teste.cpp 
FTeste = Teste/CasosTeste/outputTVector1.txt 

# Regra padrão (executada com `make` sem argumentos)
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação com MPI
mpi: $(SRC)
	$(MPICC) $(CFLAGS) -DMPI_ATIVO -o $(TARGET_MPI) $^

# Regra para testes (executada com `make check`)
check: $(TARGET)
	@echo "Executando testes..."
	@./$(TARGET)  1,3 -R out -P P1=1:12 x P6=1:3 > Teste/CasosTeste/output_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/output_obtido.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' Teste/CasosTeste/outputTVector1.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > Teste/CasosTeste/normalized_esperado.txt
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
