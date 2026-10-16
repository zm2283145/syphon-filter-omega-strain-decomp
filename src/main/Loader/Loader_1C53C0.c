#pragma cplusplus on
#include "types.h"
#include "tstr_types.h"
#pragma inline_depth(10)
struct PRVec_1C53C0 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049AE50[];
}
#pragma opt_common_subs off
extern "C" void func_001C53C0(PRVec_1C53C0* v, int* first, int* last)
{
    v->count = v->cap = last - first;
    if (v->count > 0x1800000) {
        func_00123BE8(D_00489738->stream, "vector length error\n");
        func_00121B60();
    }
    unsigned int n = v->count;
    if (n) {
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        int* s = first;
        int* d = v->data;
        while (s < last) {
            *d = *s;
            s++;
            d++;
        }
    }
}