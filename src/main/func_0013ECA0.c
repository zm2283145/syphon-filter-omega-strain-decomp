#pragma cplusplus on
#include "types.h"
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { void* xx = this; G1(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4];
    M() {}
    M(const M& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
extern "C" {
M* cMatrix_InvertRot(M* m);
int cMatrix_IsZeroTranslation(M* m);
V* func_00133EC0(M* m);
void cVector_ctor_cVectorR(V* d, V* s);
V* cVector_NegateXYZ(V* a);
V* cVector_Rotate_cMatrixR(V* a, M* b);
void cMatrix_SetTranslation(M* m, V* v);
}
extern "C" M cMatrix_Copy_InvertRotTrans(const M* s)
{
    M m = *s;
    M* pm = &m;
    V tmp;
    cMatrix_InvertRot(pm);
    if (!cMatrix_IsZeroTranslation(pm)) {
        cVector_ctor_cVectorR(&tmp, func_00133EC0(pm));
        cVector_NegateXYZ(&tmp);
        cVector_Rotate_cMatrixR(&tmp, pm);
        cMatrix_SetTranslation(pm, &tmp);
    }
    return *pm;
}

