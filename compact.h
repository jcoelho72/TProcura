// compat.h
#pragma once
#include <cstdio>
#include <cstring>

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

} // namespace compat
