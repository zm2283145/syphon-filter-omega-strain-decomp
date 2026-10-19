#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct V_00174A20 { unsigned int cap; unsigned int count; int* data; };
extern "C" {
extern char D_0049CA60[];
extern char D_0049CAD8[];
}

extern "C" void func_00174A20(V_00174A20* v, unsigned int n, const int* val)
{
    if (n) {
        if (n > 0x1800000) {
            func_00123BE8(D_00489738->stream, D_0049CA60);
            Libc_Abort();
        }
        int** pdata = &v->data;
        *pdata = (int*)TStr_Alloc(n * sizeof(int), D_0049CAD8, 0x5C);
        v->cap = n;
        int* end;
        int* p;
        p = v->data;
        end = p + n;
        while (p < end) {
            if (p)
                *p = *val;
            p++;
            v->count++;
        }
    }
}
