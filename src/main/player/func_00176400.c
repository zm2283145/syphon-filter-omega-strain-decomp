#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { V r[4]; };
struct Src {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; Mtx xform; unsigned char dirty;
};
struct Owner_76400 { char pad[0x50]; Src* src; };
struct P_76400 { char pad[0x30]; char* p30; char pad34[0x1A0 - 0x34]; Owner_76400* x1A0; };
extern "C" void Weapon_MuzzleFrame(Mtx* out, void* p, unsigned char f);
static inline Mtx* GetXform(Src* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline void GQ(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void MulV(V* o, Mtx* m, V* v) {
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(o)
    }
}
/* cPlayer_v17: muzzle/eye frame (else branch is cNPC_v17, npc_14F380.c) */
extern "C" int cPlayer_v17(P_76400* self, Mtx* out, int flag, int eye)
{
    char* p = self->p30;
    if (eye) {
        V u;
        GQ(out, GetXform(self->x1A0->src));
        u.x = 0.0f; u.y = 1.0f; u.z = 0.0f; u.w = 1.0f;
        MulV(&u, out, &u);
        VC(&out->r[3], &u);
    } else {
        Mtx tmp;
        __int128 qa; __int128 qb; Mtx* s;
        unsigned short f;
        if (flag) f = 1; else f = 0;
        { char* q = p + 0x60; Weapon_MuzzleFrame(&tmp, q, f); }
        s = &tmp;
        asm {
            .set noreorder
            lq qa, 0x0(s)
            lq qb, 0x10(s)
            sq qa, 0x0(out)
            lq qa, 0x20(s)
            sq qb, 0x10(out)
            lq qb, 0x30(s)
            sq qa, 0x20(out)
            sq qb, 0x30(out)
            .set reorder
        }
    }
    return 1;
}
