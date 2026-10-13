#pragma cplusplus on
#include "types.h"
#include "pp_quad_copy.h"
#include "v4_asm_copy.h"
typedef PPMtx M44;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_A60;
static inline void UnitMtx_A60(void* m) {
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
static inline void QR(void* d, void* s) {
    __int128 qa, qb;
    asm { .set reorder; lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) }
}
static inline void UM(void* m) { int t; void* p = m; asm { .set noreorder; sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p); .set reorder } }
/* GCC-style volatile asm copy (lq/sq only): MW does not CSE across it and the peephole
   keeps dead address locals around it, giving retail's duplicate addius. */
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline M44* Ident_A60(M44* m) { UnitMtx_A60(m); return m; }
static inline void VZero_A60(void* v) {
    asm { sq zero, 0(v) }
}
static inline V4_A60 Sub_A60(V4_A60* a, V4_A60* b)
{
    V4_A60 r;
    V4_A60* pr = &r;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(pr)
    }
    return r;
}
struct Xf_A60 {
    virtual void v0();
    virtual void SetMtx(M44* m);
    virtual void v1b();
    virtual void SetPos(V4_A60* pos, V4_A60* delta);
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad04[0xC];
    M44 m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
};
struct Mover_A60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Move(V4_A60* d);
};
typedef struct Node_3CDA60 { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; } Node_3CDA60;
struct Obj_3CDA60 { char pad[0x50]; Xf_A60* xf; Node_3CDA60* node; Mover_A60* mover; };

extern "C" void func_003CDA60(Obj_3CDA60* o, M44* mtx)
{
    Xf_A60* xf = o->xf;
    if (xf) {
        V4_A60 save;
        V4_A60 t;
        V4_A60 d;
        if (xf->b50) xf->Update();
        {
            V4_A60* pos = (V4_A60*)&mtx->q[3];
            V4_A60* y = (V4_A60*)&xf->m.q[3];
            V4_A60* q = &d;
            __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(q), "r"(pos), "r"(y) : "memory");
        }
        {
            V4_A60* p;
            V4_A60* s2;
            V4_A60* dd;
            V4_A60* x1;
            V4_A60* x2;
            V4_A60* ss;
            float z;
            dd = &t;
            z = 0.0f;
            p = &t;
            s2 = &save;
            x1 = &t;
            x2 = &save;
            ss = &d;
            *(__int128*)dd = *(__int128*)ss;
            p->w = z;
            *(__int128*)s2 = *(__int128*)p;
        }
        o->xf->SetMtx(mtx);
        if (o->node) {
            Xf_A60* x = o->xf;
            if (x) {
Node_3CDA60* n; if (x->b50) x->Update(); void* s; s = &x->m; n = o->node; n->flag = 0; void* d = &n->m; /* dead on purpose */ GQR(&n->m, s); void* xx = &n->xf; /* dead on purpose */ UM(&n->xf); V4StoreZero(&n->v90);
                V4StoreZero(&n->vA0);
            }
        }
        {
            Mover_A60* mv = o->mover;
            if (mv) mv->Move(&save);
        }
    }
}







