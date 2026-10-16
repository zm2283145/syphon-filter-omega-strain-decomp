#pragma cplusplus on
#include "types.h"
#include "tstr_types.h"
#pragma inline_depth(10)
struct PRVec_1C50F0 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049AE50[];
extern char D_0049AF00[];
extern char D_0049F300[];
}
static inline void PRVec_1C50F0_Free(int* p)
{
    if (p)
        TStr_Free((char*)p, D_0049AF00, 0x64);
}
#pragma opt_common_subs off
extern "C" void func_001C50F0(PRVec_1C50F0* v, int* first, int* last)
{
    unsigned int n = last - first;
    if (v->cap < n) {
        if (n > 0x1800000) {
            func_00123BE8(D_00489738->stream, D_0049F300);
            func_00121B60();
        }
        v->count = 0;
        int* old = v->data;
        if (old) {
            PRVec_1C50F0_Free(old);
            v->data = 0;
            v->cap = 0;
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        v->cap = n;
    }
    int* d = v->data;
    int* s = first;
    while (s < last) {
        *d = *s;
        s++;
        d++;
    }
    v->count = n;
}

