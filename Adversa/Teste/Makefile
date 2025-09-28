# Compiladores
CC     = g++
MPICC  = mpic++

# Flags
CFLAGS_DEBUG   = -Wall -g
CFLAGS_RELEASE = -Wall -O3
CFLAGS_MPI     = -Wall -O3 -DMPI_ATIVO

# Alvos
TARGET       = TProcuraAdversa
SRC          = ../../*.cpp ../../Construtiva/*.cpp ../*.cpp *.cpp
FTeste       = CasosTeste/input.txt CasosTeste/output.txt 

# Pastas de output
BINDIR       = bin
DEBUGDIR     = $(BINDIR)/Debug
RELEASEDIR   = $(BINDIR)/Release
MPIDIR       = $(BINDIR)/MPI

# Regra padrão → compila Release
all: release

# Compilação Debug
debug: $(SRC)
	@mkdir -p $(DEBUGDIR)
	$(CC) $(CFLAGS_DEBUG) -o $(DEBUGDIR)/$(TARGET) $^

# Compilação Release
release: $(SRC)
	@mkdir -p $(RELEASEDIR)
	$(CC) $(CFLAGS_RELEASE) -o $(RELEASEDIR)/$(TARGET) $^

# Compilação MPI
mpi: $(SRC)
	@mkdir -p $(MPIDIR)
	$(MPICC) $(CFLAGS_MPI) -o $(MPIDIR)/$(TARGET) $^

# Testes (usando Release por omissão)
check: release
	@echo "Executando testes..."
	@$(RELEASEDIR)/$(TARGET) < CasosTeste/input.txt > CasosTeste/output_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' CasosTeste/output_obtido.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > CasosTeste/normalized_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' CasosTeste/output.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > CasosTeste/normalized_esperado.txt
	@diff CasosTeste/normalized_obtido.txt CasosTeste/normalized_esperado.txt || (echo "Testes falharam"; exit 1)
	@echo "Todos os testes passaram!"

# Validação completa
distcheck: check
	@echo "Validando distribuição..."
	@tar czf $(TARGET).tar.gz $(SRC) Makefile $(FTeste)
	@echo "Distribuição validada: $(TARGET).tar.gz"

# Limpeza
clean:
	@echo "Limpando ficheiros..."
	@rm -rf $(BINDIR) $(TARGET).tar.gz CasosTeste/output_obtido.txt CasosTeste/normalized_*.txt

