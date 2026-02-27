#include "../TProcura.h"

// exemplo de utilização de TProcuraExecutavel
// para correr um executável externo, com parâmetros e indicadores específicos, e extrair os indicadores do output do programa, para registar num ficheiro CSV de resultados
// vamos utilizar o exTProcuraExecutavel.sh
int main(int argc, char* argv[]) {
	TProcuraExecutavel proc;
	// adicionar parâmetros específicos, para configurar a execução do programa
	proc.solver = "./exTProcuraExecutavel.sh";
	proc.inst = { "Instâncias", 1, 1, 10, "IDs das instâncias a serem testadas" }; // definição de instâncias existentes

	proc.par += { "param1", 0, 0, 10, "explicação do que acontece com este parametro entre 0 e 10" };
	proc.par += { "param2", 0, 0, 10, "explicação do que acontece com este parametro entre 0 e 10" };
	proc.parPrefixo += { "-p1 ", "-p2 " }; // prefixo a dar nos argumentos do programa, para cada parâmetro

	// adicionar indicadores específicos, para extrair do output do programa
	proc.ind += { "indicador1", "explicação do indicador1", IND_PROCURA };
	proc.indPrefixo += { "Ind1: " }; // prefixo existente no output do programa, para cada indicador, de modo a extrair o valor do indicador
	proc.indPrefixo[IND_RESULTADO] = "Resultado: "; // prefixo para extrair o resultado
	proc.indPrefixo[IND_TEMPO] = "Tempo: "; // prefixo para extrair o tempo

	proc.main(argc, argv, "exTProcuraExecutavel");
}
