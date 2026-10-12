#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E139BD0 { int w[56]; };
struct V139BD0 { unsigned int cap; unsigned int count; E139BD0* data; };
extern "C" {
extern char D_0049ABB0[];
void* func_00139BC0(unsigned int size, void* p);
void func_00139D30(void* dst, const E139BD0* src);
}
extern "C" void func_00139BD0(V139BD0* v, unsigned int n, const E139BD0* val)
{
    if (n) {
        if (n > 0x6DB6D) {
            func_00123BE8(D_00489738->stream, D_0049ABB0);
            func_00121B60();
        }
        E139BD0** pdata = &v->data;
        *pdata = (E139BD0*)TStr_Alloc(n * sizeof(E139BD0), "allocator.hh", 0x5C);
        v->cap = n;
        E139BD0* p = v->data;
        E139BD0* end = p + n;
        for (; p < end; p++) {
            void* o = func_00139BC0(sizeof(E139BD0), p);
            if (o) func_00139D30(o, val);
            v->count++;
        }
    }
}