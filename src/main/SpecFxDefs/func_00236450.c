#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
#pragma opt_common_subs off

struct V_6450 { __int128 q; V_6450() {} V_6450(const V_6450& o) { V_6450* pd = this; const V_6450* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } } };
struct M_6450 { V_6450 r[4]; };
struct E_6450 { int pad0; unsigned char b4; char pad5[3]; int i8; char padC[0x10]; };
struct S_6450 { char pad[0x74]; void* actor; E_6450* ents; };

extern "C" {
extern signed char ActorNodeCodeTable[];
void* Actor_GetSkeleton(void* h);
V_6450 Model_GetSkeletonNodePos(void* skel, int node);
}

static inline void Add_6450(V_6450* a, V_6450* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
}
static inline void Unit_6450(M_6450* m) {
    int t;
    asm {
        sqc2 vf0, 0x30(m)
        qmfc2.ni t, vf0
        pcpyud t, t, zero
        sq t, 0x10(m)
        pexcw t, t
        sq t, 0x20(m)
        pcpyud t, t, zero
        sq t, 0(m)
    }
}

extern "C" void FireEffectObj_RecordMatrix(S_6450* s, int i, M_6450* out)
{
    E_6450* e = &s->ents[i];
    unsigned char b = e->b4;
    V_6450 p = Model_GetSkeletonNodePos(Actor_GetSkeleton(s->actor), ActorNodeCodeTable[b]);
    int k = e->i8;
    if (k != 0x15) {
        unsigned char c = k;
        V_6450 q = Model_GetSkeletonNodePos(Actor_GetSkeleton(s->actor), ActorNodeCodeTable[c]);
        Add_6450(&p, &q);
        {
            int tt; V_6450* d; V_6450* src; float h;
            asm { paddub tt, zero, zero } /* retail dead paddub */
            d = &p; src = &p; h = 0.5f;
            asm { .set noreorder; lqc2 vf1, 0x0(src); mfc1 tt, h; qmtc2.ni tt, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(d); .set reorder }
        }
    }
    Unit_6450(out);
    { V_6450* pd = &out->r[3]; V_6450* ps = &p; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
}




