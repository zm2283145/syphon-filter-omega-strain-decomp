#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V3527F0 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004BABF0[];
extern char D_004BAC78[];
}
static inline void Cp3527F0(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector constructed from the range [first, last). */
extern "C" void func_003527F0(V3527F0* v, char* first, char* last)
{
    v->count = v->cap = last - first;
    if (v->count > 0x6000000) {
        func_00123BE8(D_00489738->stream, D_004BABF0);
        func_00121B60();
    }
    if (v->count) {
        { char** pdata = &v->data; *pdata = TStr_Alloc(v->count, D_004BAC78, 0x5C); }
        Cp3527F0(v->data, first, last);
    }
}
