#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)

/* Recomputes a root's cached world pose (w at 0x30) from its local placement
 * (p at 0x80) and the parent's world placement when the dirty flag is set. */

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    /* The unused xx keeps retail's dead source-address addiu. */
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };

extern "C" {
void* Root_GetParent(void*);
void* Root_GetWorldPlacement(void*);
void Transform_SetOrientation(Plc*, void*);
void Placement_Invert(Plc*);
void func_00132840(V*);
void func_00132810(V*, V*, V*);
void func_00132800(V*, V*);
void Root_GetWorldPose(struct S* s);
void Root_RefreshWorldCache(void*);
char* Root_Identity(void*);
}

struct S {
    char pad00[0x30];
    Plc w;              /* 0x30 */
    char pad50[0x30];
    Plc p;              /* 0x80 */
    char padA0[2];
    unsigned char ba2;  /* 0xA2 */
    char padA3[0xD];
    void* ib0;          /* 0xB0 */
};

static inline void QRot(V* v, V* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V* s, V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

static inline Plc* WorldPlc(void* r)
{
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return (Plc*)Root_Identity(r);
    }
    return (Plc*)(Root_Identity(r) + 0x50);
}

void Root_GetWorldPose(S* s)
{
    if (s->ba2) {
        Plc* pi = WorldPlc(s->ib0);
        {
            Plc* o = &s->p;
            Plc* d = &s->w;
            Q16(&d->rot, &o->rot);
            Q16(&d->pos, &o->pos);
        }
        Plc* p = &s->w;
        V r;
        V q;
        func_00132840(&q);
        func_00132810(&q, &pi->rot, &p->rot);
        func_00132800(&r, &q);
        p->rot = r;
        QRot(&p->pos, &pi->rot);
        VAdd3(&pi->pos, &p->pos);
        s->ba2 = 0;
    }
}


