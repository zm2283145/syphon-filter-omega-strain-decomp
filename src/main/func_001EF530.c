#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E1EF530 { int w[4]; };
struct V1EF530 { unsigned int cap; unsigned int count; E1EF530* data; };
extern "C" {
extern char D_004A0558[];
void* func_00139BC0(unsigned int size, void* p);
void func_001EF4F0(void* dst, const E1EF530* src);
void func_001EF370(V1EF530* a, V1EF530* b);
void HumanColBufA_Dtor(V1EF530* a, int f);
}
extern "C" void HumanColBufA_Reserve(V1EF530* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x600000) {
            func_00123BE8(D_00489738->stream, "vector::reserve length error\n");
            func_00121B60();
        }
        V1EF530 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E1EF530*)TStr_Alloc(n * sizeof(E1EF530), D_004A0558, 0x5C);
        tmp.cap = n;
        E1EF530* d = tmp.data;
        E1EF530* s = v->data;
        E1EF530* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = func_00139BC0(sizeof(E1EF530), d);
            if (o) func_001EF4F0(o, s);
            tmp.count++;
        }
        func_001EF370(&tmp, v);
        HumanColBufA_Dtor(&tmp, -1);
    }
}