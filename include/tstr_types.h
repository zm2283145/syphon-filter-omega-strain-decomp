#ifndef TSTR_TYPES_H
#define TSTR_TYPES_H

/*
 * 12-byte short/long string used by the string template clones.
 * Short: bit 0 of byte 0 clear, length in bits 1-7, 11 chars in place.
 * Long: bit 0 set, capacity in bits 1-31 of word 0, length at +4, data at +8.
 * The bitfield word is a template so CodeWarrior keeps 32-bit accesses
 * (non-template 1-bit fields are narrowed to byte loads/stores).
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

template <class T> struct TStrBits {
    T isLong : 1;
    T cap : 31;
};

struct TStrLong {
    union {
        unsigned int word;
        TStrBits<unsigned int> b;
    } w;
    unsigned int length;
    char* data;
};

struct TStrShort {
    unsigned char isLong : 1;
    unsigned char len : 7;
    char buf[11];
};

struct TStr {
    union {
        TStrLong l;
        TStrShort s;
    } u;
};

struct TStrErr {
    int pad[3];
    int stream;
};

extern "C" {
extern TStrErr* D_00489738;
void Libc_Fprintf(int stream, const char* msg);
void Libc_Abort(void);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void* memcpy(void* d, const void* s, unsigned int n);
}

static inline unsigned char TStr_ShortLen(const TStr* s)
{
    return s->u.s.len;
}

static inline char* TStr_Alloc(unsigned int n, char* file, int line)
{
    AllocGuard g;
    return (char*)cMemMan_Allocate(0, n, file, line);
}

static inline void TStr_Free(char* p, char* file, int line)
{
    AllocGuard g;
    cMemMan_Deallocate(0, p, file, line);
}

#endif /* TSTR_TYPES_H */