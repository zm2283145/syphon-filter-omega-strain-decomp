#pragma cplusplus on
#pragma opt_propagation off
#include "tstr_types.h"

struct V3_9470 { float x, y, z; };
struct Vec_9470 { unsigned int cap; unsigned int count; V3_9470* data; };

extern "C" {
extern char D_004BD3E0[];
extern char D_004BD408[];
}

extern "C" void func_003D9470(Vec_9470* v, unsigned int n, const V3_9470* val)
{
    if (n) {
        if (n > 0x800000) {
            func_00123BE8(D_00489738->stream, D_004BD3E0);
            func_00121B60();
        }
        V3_9470** pdata = &v->data;
        *pdata = (V3_9470*)TStr_Alloc(n * sizeof(V3_9470), D_004BD408, 0x5C);
        v->cap = n;
        V3_9470* end = v->data + n;
        V3_9470* p = v->data;
        for (; p < end; p++) {
            if (p) {
                float x;
                float y;
                float z;
                x = val->x;
                y = val->y;
                z = val->z;
                p->x = x;
                p->y = y;
                p->z = z;
            }
            v->count++;
        }
    }
}
