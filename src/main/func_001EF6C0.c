#include "types.h"
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_propagation off
#include "tstr_types.h"

struct V4q {
    float x, y, z, w;
    V4q(const V4q& o) { const V4q* s = &o; V4q* d = this; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct V4r {
    float x, y, z, w;
    V4r(const V4r& o) { V4r* d = this; const V4r* s = &o; __int128 t; asm volatile("lq %0,0(%1)" : "=r"(t) : "r"(s)); asm volatile("sq %0,0(%1)" : : "r"(t), "r"(d) : "memory"); }
} __attribute__((aligned(16)));
struct F2 { float x, y; };
struct E1EF6C0 {
    V4q a;
    V4q b;
    V4q c;
    unsigned char d;
    float e;
    V4r f;
    F2 g;
    int h;
};
struct V1EF6C0 { unsigned int cap; unsigned int count; E1EF6C0* data; };
extern "C" {
extern char D_004A04E0[];
extern char D_004A0548[];
void std_swap_vectordeleterR_vectordeleterR_13(V1EF6C0* a, V1EF6C0* b);
void std_vector_deleter_cCollisionEdge_dtor(V1EF6C0* a, int f);
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline void Construct1EF6C0(E1EF6C0* p, const E1EF6C0* s)
{
    new (p) E1EF6C0(*s);
}
extern "C" void std_vector_imp_cCollisionEdge_reserve(V1EF6C0* v, unsigned int n)
{
    if (v->cap < n) {
        unsigned int mx = 0x100000;
        if (n > mx) {
            Libc_Fprintf(D_00489738->stream, D_004A04E0);
            Libc_Abort();
        }
        V1EF6C0 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E1EF6C0*)TStr_Alloc(n * sizeof(E1EF6C0), D_004A0548, 0x5C);
        { unsigned int* pc = &tmp.cap; *pc = n; }
        E1EF6C0* d = tmp.data;
        E1EF6C0* s = v->data;
        E1EF6C0* e = s + v->count;
        for (; s < e; s++, d++) {
            Construct1EF6C0(d, s);
            tmp.count++;
        }
        std_swap_vectordeleterR_vectordeleterR_13(&tmp, v);
        std_vector_deleter_cCollisionEdge_dtor(&tmp, -1);
    }
}


