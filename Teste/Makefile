# Compiladores
CC     = g++
MPICC  = mpic++

# Flags
CFLAGS_DEBUG   = -Wall -g
CFLAGS_RELEASE = -Wall -O3
CFLAGS_MPI     = -Wall -O3 -DMPI_ATIVO

# Alvos
TARGET       = TProcura
TARGET_EXE   = exTProcuraExecutavel

# Fontes do TProcura (programa principal de testes)
SRC_MAIN     = ../*.cpp teste.cpp CTesteTVector.cpp

# Fontes do executável externo de demonstração
SRC_EXE      = ../*.cpp exTProcuraExecutavel.cpp

# Pastas de output
BINDIR       = bin
DEBUGDIR     = $(BINDIR)/Debug
RELEASEDIR   = $(BINDIR)/Release
MPIDIR       = $(BINDIR)/MPI

# Regra padrão → compila Release do TProcura
all: release

# ---------------------------------------------------------
# Compilação do programa principal TProcura
# ---------------------------------------------------------

debug: $(SRC_MAIN)
	@mkdir -p $(DEBUGDIR)
	$(CC) $(CFLAGS_DEBUG) -o $(DEBUGDIR)/$(TARGET) $^

release: $(SRC_MAIN)
	@mkdir -p $(RELEASEDIR)
	$(CC) $(CFLAGS_RELEASE) -o $(RELEASEDIR)/$(TARGET) $^

mpi: $(SRC_MAIN)
	@mkdir -p $(MPIDIR)
	$(MPICC) $(CFLAGS_MPI) -o $(MPIDIR)/$(TARGET) $^

# ---------------------------------------------------------
# Compilação do executável externo de demonstração
# ---------------------------------------------------------

exe: $(SRC_EXE)
	@mkdir -p $(RELEASEDIR)
	$(CC) $(CFLAGS_RELEASE) -o $(RELEASEDIR)/$(TARGET_EXE) $^

# ---------------------------------------------------------
# Testes (usando Release por omissão)
# ---------------------------------------------------------

FTeste       = CasosTeste/outputTVector1.txt

check: release
	@echo "Executando testes..."
	@$(RELEASEDIR)/$(TARGET) 1,3 -R out -P P1=1:12 x P6=1:3 > CasosTeste/output_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' CasosTeste/output_obtido.txt | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > CasosTeste/normalized_obtido.txt
	@sed 's/[0-9]\+[,.][0-9]\+s//g' $(FTeste) | tr -d '\r' | sed -e '$a\' | sed '1s/^\xEF\xBB\xBF//' > CasosTeste/normalized_esperado.txt
	@diff CasosTeste/normalized_obtido.txt CasosTeste/normalized_esperado.txt || (echo "Testes falharam"; exit 1)
	@echo "Todos os testes passaram!"

# ---------------------------------------------------------
# Limpeza
# ---------------------------------------------------------

clean:
	@echo "Limpando ficheiros..."
	@rm -rf $(BINDIR) $(TARGET).tar.gz CasosTeste/output_obtido.txt CasosTeste/normalized_*.txt

