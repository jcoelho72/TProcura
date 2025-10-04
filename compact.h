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

} // namespace compat
