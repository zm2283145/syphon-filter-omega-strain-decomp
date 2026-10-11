#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E003B8230 { int w[96]; };
struct V003B8230 { unsigned int cap; unsigned int count; E003B8230* data; };
extern "C" {
extern char D_004BCE80[];
extern char D_004BCFB8[];
void* func_00139BC0(unsigned int size, void* p);
void func_003B6B20(void* dst, const E003B8230* src);
void func_003B8100(V003B8230* a, V003B8230* b);
void func_003961E0(V003B8230* a, int f);
}
extern "C" void func_003B8230(V003B8230* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x40000) {
            func_00123BE8(D_00489738->stream, D_004BCE80);
            func_00121B60();
        }
        V003B8230 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E003B8230*)TStr_Alloc(n * sizeof(E003B8230), D_004BCFB8, 0x5C);
        tmp.cap = n;
        E003B8230* d = tmp.data;
        E003B8230* s = v->data;
        E003B8230* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = func_00139BC0(sizeof(E003B8230), d);
            if (o) func_003B6B20(o, s);
            tmp.count++;
        }
        func_003B8100(&tmp, v);
        func_003961E0(&tmp, -1);
    }
}