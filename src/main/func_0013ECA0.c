#pragma cplusplus on
#include "types.h"
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { void* xx = this; G1(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4];
    M() {}
    M(const M& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
extern "C" {
M* Mtx_Transpose3x3(M* m);
int Mtx_IsTranslationZero(M* m);
V* func_00133EC0(M* m);
void Vec4_Assign(V* d, V* s);
V* Vec3_Negate(V* a);
V* Mtx_TransformByTranspose(V* a, M* b);
void Mtx_SetTranslation(M* m, V* v);
}
extern "C" M Mtx_InvertRigid_13ECA0(const M* s)
{
    M m = *s;
    M* pm = &m;
    V tmp;
    Mtx_Transpose3x3(pm);
    if (!Mtx_IsTranslationZero(pm)) {
        Vec4_Assign(&tmp, func_00133EC0(pm));
        Vec3_Negate(&tmp);
        Mtx_TransformByTranspose(&tmp, pm);
        Mtx_SetTranslation(pm, &tmp);
    }
    return *pm;
}

