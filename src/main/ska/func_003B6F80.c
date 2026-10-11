#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
struct V3B6F80 { unsigned int cap; unsigned int count; VRElem20* data; };
extern "C" {
extern char D_004BCE20[];
extern char D_004A3F20[];
void* func_00139BC0(unsigned int size, void* p);
void func_0020C020(void* dst, const VRElem20* src);
}
extern "C" void func_003B6F80(V3B6F80* v, const VRElem20* first, const VRElem20* last)
{
    unsigned int n = last - first;
    if (v->count > 0x4CCCCC) {
        func_00123BE8(D_00489738->stream, D_004BCE20);
        func_00121B60();
    }
    if (n) {
        VRElem20** pdata = &v->data;
        *pdata = (VRElem20*)TStr_Alloc(n * sizeof(VRElem20), D_004A3F20, 0x5C);
        v->cap = n;
        VRElem20* p = v->data;
        for (; first != last; first++, p++) {
            void* o = func_00139BC0(sizeof(VRElem20), p);
            if (o) func_0020C020(o, first);
            v->count++;
        }
    }
}