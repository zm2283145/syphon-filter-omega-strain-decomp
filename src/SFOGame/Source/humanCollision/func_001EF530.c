#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"

struct E1EF530 { int w[4]; };
struct V1EF530 { unsigned int cap; unsigned int count; E1EF530* data; };
extern "C" {
extern char D_004A0558[];
void* opNew_uint_voidP(unsigned int size, void* p);
void cEdgeGroup_ctor_cEdgeGroupR(void* dst, const E1EF530* src);
void std_swap_vectordeleterR_vectordeleterR_12(V1EF530* a, V1EF530* b);
void std_vector_deleter_cEdgeGroup_dtor(V1EF530* a, int f);
}
extern "C" void std_vector_imp_cEdgeGroup_reserve(V1EF530* v, unsigned int n)
{
    if (v->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, "vector::reserve length error\n");
            Libc_Abort();
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
            void* o = opNew_uint_voidP(sizeof(E1EF530), d);
            if (o) cEdgeGroup_ctor_cEdgeGroupR(o, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_12(&tmp, v);
        std_vector_deleter_cEdgeGroup_dtor(&tmp, -1);
    }
}