#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V352910 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004BAC10[];
extern char D_004BACB8[];
extern char D_004BAC78[];
}
static inline void Cp352910(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector assign(first, last): grows the buffer when needed, then copies. */
extern "C" void func_00352910(V352910* v, char* first, char* last)
{
    unsigned int n = last - first;
    if (v->cap < n) {
        if (n > 0x6000000) {
            func_00123BE8(D_00489738->stream, D_004BAC10);
            func_00121B60();
        }
        v->count = 0;
        if (v->data) {
            if (v->data) TStr_Free(v->data, D_004BACB8, 0x64);
            v->data = 0;
            v->cap = 0;
        }
        { char** pdata = &v->data; *pdata = TStr_Alloc(n, D_004BAC78, 0x5C); }
        v->cap = n;
    }
    Cp352910(v->data, first, last);
    v->count = n;
}
