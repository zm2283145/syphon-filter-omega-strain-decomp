#pragma cplusplus on
#include "ptrvec_reserve.h"
extern "C" { extern char D_0049CA60[]; extern char D_0049AE50[]; }

extern "C" void func_001748F0(PRVec* v, unsigned int n, const int* val)
{
    if (n) {
        if (n > 0x1800000) {
            func_00123BE8(D_00489738->stream, D_0049CA60);
            func_00121B60();
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * 4, D_0049AE50, 0x5C);
        v->count = n;
        v->cap = n;
        int* d = v->data;
        while (n) {
            *d = *val;
            n--;
            d++;
        }
    }
}
