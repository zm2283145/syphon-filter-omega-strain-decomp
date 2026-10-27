/*
 * main/gobj: range (2 files, 003CD630-003CD7A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "pp_quad_copy.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_003CD630 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef PPMtx M44;
/* GCC-style volatile asm quad copy: MW treats it as an opaque barrier, so the dead
   address local after it (xx) is neither CSE-merged nor removed by the peephole. */
static inline void QR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UnitMtx_630(void* m) { int t; void* p = m; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
static inline M44* Ident_630(M44* m) { UnitMtx_630(m); return m; }
static inline void VZero_630(void* v) {
    asm { sq zero, 0(v) }
}
typedef struct Node_3CD630 { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; } Node_3CD630;
struct Obj_3CD630 { char pad[0x54]; Node_3CD630* node; };
extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
void cMatrix_ctor_cMatrixR(void*, void*);
void* cMatrix_GetUnit(void);
void* cVector_GetZero(void);
void cVector_ctor_cVectorR(void*, void*);
extern char D_004BD228[];
}

extern "C" void cGOBJ_CreateMovementInfo_cMatrixR(Obj_3CD630* o_, M44* m_)
{
    Node_3CD630* n = o_->node;
    Obj_3CD630* o = o_; M44* m = m_;
    if (n == 0) {
        Node_3CD630* p;
        {
            AllocGuard g;
            p = (Node_3CD630*)cMemMan_Allocate(0, 0xB0, D_004BD228, 0x1F7);
        }
        if (p) {
            p->flag = 0;
            cMatrix_ctor_cMatrixR(&p->m, m);
            cMatrix_ctor_cMatrixR(&p->xf, cMatrix_GetUnit());
            cVector_ctor_cVectorR(&p->v90, cVector_GetZero());
            cVector_ctor_cVectorR(&p->vA0, cVector_GetZero());
        }
        o->node = p;
    } else {
        n->flag = 0;
        M44* d = &n->m;
        QR(d, m);
        void* xx = &n->xf; /* dead on purpose: retail keeps this addiu */
        Ident_630(&n->xf);
        VZero_630(&n->v90);
        VZero_630(&n->vA0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD630 */

/* merge_units: begin func_003CD7A0 */
#pragma push /* merge_units */
#pragma cplusplus on
static inline void Q1(void* d, void* s) { __int128 q; asm { lq q, 0(s); sq q, 0(d) } }
static inline void QR_003CD7A0(void* d, void* s) {
    __int128 qa, qb;
    asm { .set reorder; lq qa, 0x0(s); lq qb, 0x10(s); sq qa, 0x0(d); lq qa, 0x20(s); sq qb, 0x10(d); lq qb, 0x30(s); sq qa, 0x20(d); sq qb, 0x30(d) }
}
static inline void UM(void* m) { int t; void* p = m; asm { .set noreorder; sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p); .set reorder } }
/* GCC-style volatile asm copy (lq/sq only): MW does not CSE across it and the peephole
   keeps dead address locals around it, giving retail's duplicate addius. */
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_7A0;
static inline void UnitMtx_7A0(void* m) {
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
static inline M44* Ident_7A0(M44* m) { UnitMtx_7A0(m); return m; }
static inline void VZero_7A0(void* v) {
    asm { sq zero, 0(v) }
}
static inline V4_7A0 Sub_7A0(V4_7A0* a, V4_7A0* b)
{
    V4_7A0 r;
    V4_7A0* pr = &r;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(pr)
    }
    return r;
}
struct Xf_7A0 {
    virtual void v0(); virtual void v1(); virtual void v1b();
    virtual void SetPos(V4_7A0* pos, V4_7A0* delta);
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad04[0xC];
    M44 m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
};
struct Mover_7A0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Move(V4_7A0* d);
};
typedef struct Node_3CD7A0 { unsigned char flag; char pad[15]; M44 m; M44 xf; __int128 v90; __int128 vA0; } Node_3CD7A0;
struct Obj_3CD7A0 { char pad[0x50]; Xf_7A0* xf; Node_3CD7A0* node; Mover_7A0* mover; };

static inline void Copy_7A0(M44* d, M44* s) { PP_COPY4(d, s) }
extern "C" void cGOBJ_SetTranslation_ResetPhysics(Obj_3CD7A0* o, V4_7A0* pos)
{
    Xf_7A0* xf = o->xf;
    if (xf) {
        V4_7A0 save;
        V4_7A0 t;
        V4_7A0 d;
        V4_7A0* p;
        if (xf->b50) xf->Update();
        {
            V4_7A0* y = (V4_7A0*)&xf->m.q[3];
            V4_7A0* q = &d;
            __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(q), "r"(pos), "r"(y) : "memory");
        }
        {
            V4_7A0* s2;
            V4_7A0* dd = &t;
            float z = 0.0f;
            V4_7A0* x1;
            V4_7A0* x2;
            V4_7A0* ss;
            p = &t;
            s2 = &save;
            x1 = &t;
            x2 = &save;
            ss = &d;
            *(__int128*)dd = *(__int128*)ss;
            p->w = z;
            *(__int128*)s2 = *(__int128*)p;
        }
        o->xf->SetPos(pos, p);
        if (o->node) {
            Xf_7A0* x = o->xf;
            if (x) {
                if (x->b50) x->Update();
                Node_3CD7A0* n; void* s; s = &x->m; n = o->node; n->flag = 0; void* d = &n->m; /* dead on purpose */ GQR(&n->m, s); void* xx = &n->xf; /* dead on purpose */ UM(&n->xf); V4StoreZero(&n->v90); V4StoreZero(&n->vA0);
            }
        }
        {
            Mover_7A0* mv = o->mover;
            if (mv) mv->Move(&save);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD7A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD7A0 */
