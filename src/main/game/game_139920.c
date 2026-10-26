#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E00139920 { int w[28]; };
struct V00139920 { unsigned int cap; unsigned int count; E00139920* data; };
extern "C" {
extern char D_0049AB90[];
void* Mem_PlacementNew(unsigned int size, void* p);
void cCollisionFace_ctor_cCollisionFaceR(void* dst, const E00139920* src);
void std_swap_vectordeleterR_vectordeleterR(V00139920* a, V00139920* b);
void func_00139DF0(V00139920* a, int f);
}
extern "C" void Vector_Reserve_139920(V00139920* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0xDB6DB) {
            Libc_Fprintf(D_00489738->stream, D_0049AB90);
            Libc_Abort();
        }
        V00139920 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E00139920*)TStr_Alloc(n * sizeof(E00139920), "allocator.hh", 0x5C);
        tmp.cap = n;
        E00139920* d = tmp.data;
        E00139920* s = v->data;
        E00139920* e = s + v->count;
        for (; s < e; s++, d++) {
            void* o = Mem_PlacementNew(sizeof(E00139920), d);
            if (o) cCollisionFace_ctor_cCollisionFaceR(o, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR(&tmp, v);
        func_00139DF0(&tmp, -1);
    }
}