#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V33B860 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
extern char D_004B98B8[];
}
static inline void Cp33B860(char* d, const char* f, const char* l) { memcpy(d, f, l - f); }
/* Byte vector constructed from the range [first, last). */
extern "C" void func_0033B860(V33B860* v, char* first, char* last)
{
    v->count = v->cap = last - first;
    if (v->count > 0x6000000) {
        Libc_Fprintf(D_00489738->stream, "vector length error\n");
        Libc_Abort();
    }
    if (v->count) {
        { char** pdata = &v->data; *pdata = TStr_Alloc(v->count, D_004B98B8, 0x5C); }
        Cp33B860(v->data, first, last);
    }
}
