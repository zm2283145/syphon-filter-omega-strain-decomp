#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E00139920 { int w[28]; };
struct V00139920 { unsigned int cap; unsigned int count; E00139920* data; };
extern "C" {
extern char D_0049AB90[];
extern char D_0049AE40[];
void* func_00139BC0(unsigned int size, void* p);
void func_00139B00(void* dst, const E00139920* src);
void func_00139AC0(V00139920* a, V00139920* b);
void func_00139DF0(V00139920* a, int f);
}
extern "C" void func_00139920(V00139920* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0xDB6DB) {
            func_00123BE8(D_00489738->stream, D_0049AB90);
            func_00121B60();
        }
        V00139920 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E00139920*)TStr_Alloc(n * sizeof(E00139920), D_0049AE40, 0x5C);
        tmp.cap = n;
        E00139920* d = tmp.data;
        E00139920* s = v->data;
        E00139920* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = func_00139BC0(sizeof(E00139920), d);
            if (o) func_00139B00(o, s);
            tmp.count++;
        }
        func_00139AC0(&tmp, v);
        func_00139DF0(&tmp, -1);
    }
}