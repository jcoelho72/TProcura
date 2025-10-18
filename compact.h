// compat.h
#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
#include <locale>

#ifdef _WIN32
#include <windows.h>
#endif

namespace compat {

	inline FILE* fopen(const char* filename, const char* mode) {
#ifdef _MSC_VER
		FILE* f = nullptr;
		fopen_s(&f, filename, mode);
		return f;
#else
		return std::fopen(filename, mode);
#endif
	}

	inline char* strtok(char* str, const char* delim, char** context) {
#ifdef _MSC_VER
		return strtok_s(str, delim, context);
#else
		return strtok_r(str, delim, context);
#endif
	}

	inline void init_io() {
#ifdef _WIN32
		// Windows: locale ".UTF-8" é válido
		std::locale::global(std::locale(".UTF-8"));
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
#else
		// Linux: usar locale vazio "" → herda do ambiente (normalmente já UTF-8)
		std::locale::global(std::locale(""));
#endif
	}

	inline int ContaUTF8(const char* str) {
		// contagem de caracteres (mas icons podem ocupar mais espaço)
		unsigned int count = 0;
		if (!str)
			return 0;
		while (*str) {
			if ((*str & 0xC0) != 0x80) 
				count++;
			str++;
		}
		return count;

		// possibilidade de contar com tamanho dos icons, a explorar no futuro:
		int colunas = 0;
		mbstate_t state{};
		wchar_t wc;
		size_t len;

		while ((len = mbrtowc(&wc, str, MB_CUR_MAX, &state)) > 0) {
#ifdef _WIN32
			// Simplificação: ASCII=1, outros=2
			colunas += (wc < 128 ? 1 : 2);
#else
			int w = wcwidth(wc);
			colunas += (w > 0 ? w : 0);
#endif
			str += len;
		}
		return colunas;
	}


#define ICON_LISTA \
    X(INST,  "📄")    /* instância / dados */ \
    X(EXP,   "🔍")    /* explorar */ \
    X(PARAM, "⚙️")    /* parâmetros */ \
    X(SOL,   "✔")     /* solução */ \
    X(IND,   "⚖")    /* indicadores */ \
    X(EXEC,  "►")     /* execução (início) */ \
    X(FIM,   "🏁")     /* execução (fim) */ \
    X(CONF,  "🛠️")    /* configuração */ \
    X(TESTE, "🧪")    /* teste */ \
    X(TEMPO, "⏱")    /* tempo utilizado */ \
    X(RESULT, "🗎")    /* resultado / ficheiro */ \
    X(PROCESSO, "🖥️")    /* processo / computador */ \
    X(TAREFA, "📋")    /* tarefa */ \
    X(TAXA, "📊")     /* taxa / resultado */ \
    X(SUCESSO, "🎯")    /* objetivo alcançado, sucesso */ \
    X(INSUC, "🚫")    /* insucesso, objetivo não alcançado */ \
    X(MEMORIA, "🗄")    /* estado em memória ou erro de memória (alternativa: 💾) */ \
    X(IMP, "⛔")       /* impossível, sem solução */ \
    X(VALOR, "💰")       /* valor/custo da solução */ \
    X(SEL, "☑")       /* valor ativo / selecionado */ \
    X(NSEL, "☐")       /* valor inativo / não selecionado */ \
    X(TORNEIO, "🏆")       /* torneio */ \
    X(MENU,  "☰")      /* menu */ 

	enum class EIcon {
#define X(nome, string) nome,
		ICON_LISTA
#undef X
	};

	inline const char* Icon(EIcon icon) {
		switch (icon) {
#define X(nome, string) case EIcon::nome: return string;
			ICON_LISTA
#undef X
		}
		return "";
	}

} // namespace compat

// este tipo e função ficam disponíveis sem necessidade de colocar compact::
using compat::EIcon;
using compat::Icon;
