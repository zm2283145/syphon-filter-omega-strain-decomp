#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
struct V3521A0 { unsigned int cap; unsigned int count; VRElem20* data; };
extern "C" {
extern char D_004BABF0[];
void* func_00139BC0(unsigned int size, void* p);
void func_00352320(void* dst, const VRElem20* src);
}
extern "C" void func_003521A0(V3521A0* v, const VRElem20* first, const VRElem20* last)
{
    unsigned int n = last - first;
    if (v->count > 0x4CCCCC) {
        func_00123BE8(D_00489738->stream, D_004BABF0);
        func_00121B60();
    }
    if (n) {
        VRElem20** pdata = &v->data;
        *pdata = (VRElem20*)TStr_Alloc(n * sizeof(VRElem20), "allocator.hh", 0x5C);
        v->cap = n;
        VRElem20* p = v->data;
        for (; first != last; first++, p++) {
            void* o = func_00139BC0(sizeof(VRElem20), p);
            if (o) func_00352320(o, first);
            v->count++;
        }
    }
}