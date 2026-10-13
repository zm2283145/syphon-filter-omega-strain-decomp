#pragma opt_common_subs off
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* GCC-style volatile asm copies (lq/sq, VU0 only): MW does not CSE across them and the
   peephole keeps the dead address local after them (xx), giving retail's duplicate addiu. */
static inline void QR(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct MQ;
static inline void MulRot_3CDC20(MQ* d, MQ* s, MQ* r);
struct MQ {
    __int128 r[4];
    MQ() {}
    void Rot(MQ* r) { MQ* p = this; MulRot_3CDC20(p, p, r); }
    MQ& RotR(MQ* r) { MQ* p = this; MulRot_3CDC20(p, p, r); return *p; }
    void Rot2(MQ* r) { MulRot_3CDC20(this, this, r); }
    MQ& operator=(const MQ& src) { QR(this, &src); return *this; }
    MQ(const MQ& src) { const MQ* s = &src; MQ* d = this; __int128 qa; __int128 qb; asm { .set reorder; lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) } }
};
struct NodeQ { void* vt; int pad[3]; MQ world; unsigned char dirty; };
struct NodeQV { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); };
typedef struct { char pad[0x50]; NodeQ* node; } OwnQ;
struct XfQ { virtual void v0(); virtual void SetMtx(MQ m); };
struct XfP { virtual void v0(); virtual void SetMtxP(MQ* m); };
static inline void MulRot_3CDC20(MQ* d, MQ* s, MQ* r)
{
    __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf9, 0x10(%2); lqc2 vf10, 0x20(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddz.xyzw vf12, vf6, vf8z; vmulax.xyzw ACC, vf4, vf9x; vmadday.xyzw ACC, vf5, vf9y; vmaddz.xyzw vf13, vf6, vf9z; vmulax.xyzw ACC, vf4, vf10x; vmadday.xyzw ACC, vf5, vf10y; vmaddz.xyzw vf14, vf6, vf10z; vmove.xyzw vf15, vf7; sqc2 vf12, 0x0(%0); sqc2 vf13, 0x10(%0); sqc2 vf14, 0x20(%0); sqc2 vf15, 0x30(%0)" : : "r"(d), "r"(s), "r"(r) : "memory");
}
static inline MQ World_3CDC20(NodeQ* n) { if (n->dirty) ((NodeQV*)n)->v20(); return n->world; }
extern "C" void func_003CDC20(OwnQ* o, MQ* rot) { NodeQ* n = o->node; if (n) { MQ b; MQ a = World_3CDC20(n); b = a.RotR(rot); void* xx = &b; /* dead on purpose: retail keeps this addiu */ ((XfP*)o->node)->SetMtxP(&b); } }

