#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies as GCC-style volatile asm; unused xx locals reproduce retail's dead addius (they survive only after an earlier GCC asm) */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Plc;
extern "C" void VecPair_Copy(Plc* d, const Plc* s);
struct Plc { V rot; V pos; Plc() {} Plc(const Plc& o) { VecPair_Copy(this, &o); void* xx = this; } };
extern "C" {
extern signed char D_004E1D80;
extern Plc D_00497F00;
void Quat_SetIdentity(V* q);
void Vec4_SetOrigin(V* v);
void Placement_GetIdentity(Plc* p, V* q, V* v);
void func_003AF2B0(void* self);
}
static inline Plc Ident()
{
    if (!D_004E1D80) {
        V q; V v;
        Quat_SetIdentity(&q);
        Vec4_SetOrigin(&v);
        Placement_GetIdentity(&D_00497F00, &q, &v);
        D_004E1D80 = 1;
    }
    return D_00497F00;
}
struct S { char pad0[0xC]; unsigned char bC; Plc p10; Plc p30; };
extern "C" S* func_003AF2D0(S* s);
S* func_003AF2D0(S* s)
{
    func_003AF2B0(s);
    s->bC = 1;
    s->p10 = Ident();
    s->p30 = Ident();
    return s;
}


