#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
#pragma inline_depth(10)

struct BVec_3F2300 { unsigned int cap; unsigned int count; char* data; };
extern "C" {
char D_004BE100[] = "vector::reserve length error\n";
extern char D_004BE180[];
extern char D_004BE190[];
}
static inline void Free_3F2300(char* p) { if (p) TStr_Free(p, D_004BE190, 0x64); }
extern "C" void func_003F2300(BVec_3F2300* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x6000000) {
            func_00123BE8(D_00489738->stream, D_004BE100);
            func_00121B60();
        }
        char* old = v->data;
        char** pdata = &v->data;
        *pdata = TStr_Alloc(n, D_004BE180, 0x5C);
        if (old) {
            memcpy(v->data, old, *(volatile unsigned int*)&v->count);
            Free_3F2300(old);
        }
        v->cap = n;
    }
}

