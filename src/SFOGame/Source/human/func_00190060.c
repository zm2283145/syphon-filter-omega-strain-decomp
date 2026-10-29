#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
static inline void Cp_U(void* d, const void* s) { __int128 t; asm { lq t, 0(s); sq t, 0(d) } }
struct V_U {
    float x, y, z, w;
    V_U() {}
    V_U(const V_U& o) { __int128 t; __asm__ volatile("lq %0, 0(%1)" : "=r"(t) : "r"(&o)); asm { sq t, 0(this) } }
    V_U& SetI() { V_U* p = this; asm { sqc2 vf0, 0(p) } return *this; }
} __attribute__((aligned(16)));
struct QV_U {
    V_U rot;
    V_U trans;
};
extern "C" {
extern signed char D_004E1D80;
extern QV_U D_00497F00;
}
static inline V_U QIdent_U(void) { return V_U().SetI(); }
static inline V_U V0001_U(void) { V_U r; V_U* pr = &r; asm { sqc2 vf0, 0(pr) } return *pr; }
static inline void QVInit_U(QV_U* p, const V_U& q, const V_U& t) { Cp_U(&p->rot, &q); Cp_U(&p->trans, &t); }
#pragma opt_common_subs off
extern "C" QV_U cQuatVec_GetUnit(void)
{
    if (!D_004E1D80) {
        QVInit_U(&D_00497F00, QIdent_U(), V0001_U());
        D_004E1D80 = 1;
    }
    return D_00497F00;
}

