/*
 * main/gobj: range (14 files, 003CDA60-003CE650)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "pp_quad_copy.h"
#include "v4_asm_copy.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_003CDA60 */
#pragma push /* merge_units */
#pragma cplusplus on
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

extern "C" void cGOBJ_SetTransform_ResetPhysics(Obj_3CDA60* o, M44* mtx)
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDA60 */

/* merge_units: begin func_003CDBE0 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CDBE0 { public: VPAD4(p0) VPAD2(p1) VPAD1(p2)  virtual void f(); };
struct O003CDBE0 { char pad[0x50]; C003CDBE0* m; };
extern "C" void cGOBJ_ApplyTranslation(O003CDBE0* self)
{
    C003CDBE0* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDBE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDBE0 */

/* merge_units: begin func_003CDC20 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
#pragma inline_depth(8)
/* GCC-style volatile asm copies (lq/sq, VU0 only): MW does not CSE across them and the
   peephole keeps the dead address local after them (xx), giving retail's duplicate addiu. */
static inline void QR_003CDC20(void* d, const void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct MQ;
static inline void MulRot_3CDC20(MQ* d, MQ* s, MQ* r);
struct MQ {
    __int128 r[4];
    MQ() {}
    void Rot(MQ* r) { MQ* p = this; MulRot_3CDC20(p, p, r); }
    MQ& RotR(MQ* r) { MQ* p = this; MulRot_3CDC20(p, p, r); return *p; }
    void Rot2(MQ* r) { MulRot_3CDC20(this, this, r); }
    MQ& operator=(const MQ& src) { QR_003CDC20(this, &src); return *this; }
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
extern "C" void cGOBJ_ApplyLocalRotation(OwnQ* o, MQ* rot) { NodeQ* n = o->node; if (n) { MQ b; MQ a = World_3CDC20(n); b = a.RotR(rot); void* xx = &b; /* dead on purpose: retail keeps this addiu */ ((XfP*)o->node)->SetMtxP(&b); } }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDC20 */

/* merge_units: begin func_003CDD40 */
#pragma push /* merge_units */
#pragma cplusplus on
class C3CDD40 { public: VPAD4(a) virtual void f18(); };
struct O3CDD40 { char pad[0x50]; C3CDD40* m; };
extern "C" void cGOBJ_ApplyTransform(O3CDD40* self)
{
    C3CDD40* m = self->m;
    if (m)
        m->f18();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDD40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDD40 */

/* merge_units: begin func_003CDD80 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CDD80 { public: VPAD2(p0) VPAD1(p1)  virtual void f(); };
struct O003CDD80 { char pad[0x50]; C003CDD80* m; };
extern "C" void cGOBJ_SetTranslation(O003CDD80* self)
{
    C003CDD80* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDD80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDD80 */

/* merge_units: begin func_003CDDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CDDC0 { public: VPAD2(p0)  virtual void f(); };
struct O003CDDC0 { char pad[0x50]; C003CDDC0* m; };
extern "C" void cGOBJ_SetRotation(O003CDDC0* self)
{
    C003CDDC0* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDDC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDDC0 */

/* merge_units: begin func_003CDE00 */
#pragma push /* merge_units */
#pragma cplusplus on
class C003CDE00 { public: VPAD1(p0)  virtual void f(); };
struct O003CDE00 { char pad[0x50]; C003CDE00* m; };
extern "C" void cGOBJ_SetTransform(O003CDE00* self)
{
    C003CDE00* m = self->m;
    if (m)
        m->f();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDE00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDE00 */

/* merge_units: begin func_003CDE40 */
#pragma push /* merge_units */
#pragma cplusplus on
class Xf_f4 {
public:
    virtual void Destroy(int flags);
};
struct Obj_f4 { char pad[0x48]; unsigned char owns; char pad49[7]; Xf_f4* xf; };
extern "C" {
extern char D_004BD228[];
}
extern "C" void cGOBJ_SetXformPointer(Obj_f4* self, Xf_f4* xf)
{
    Xf_f4* old = self->xf;
    if (old) {
        if (self->owns) {
            {
                AllocGuard g;
                old->Destroy(-1);
                cMemMan_Deallocate(0, old, D_004BD228, 0x174);
            }
            self->owns = 0;
        }
        self->xf = 0;
    }
    self->xf = xf;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDE40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDE40 */

/* merge_units: begin func_003CDF20 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003CDF20 { virtual int v0(...); };
extern "C" {
#if 0 /* merge_units */
extern char D_004BD228;
#endif /* merge_units */
#define D_004BD228 (*(char*)&D_004BD228) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
}
#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_DestroyXform(char * arg0) {
    void **temp_s1;

    temp_s1 = (void **)(F_(arg0, 0x50, int));
    if (temp_s1 != NULL) {
        if (F_(arg0, 0x48, unsigned char) != 0) {
            {
                AllocGuard g;
            ((VC003CDF20 *)(temp_s1))->v0(-1);
            cMemMan_Deallocate(0, temp_s1, &D_004BD228, 0x174);
            }
            F_(arg0, 0x48, unsigned char) = 0U;
        }
        F_(arg0, 0x50, int) = NULL;
    }
}
#pragma pop
#undef D_004BD228 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDF20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDF20 */

/* merge_units: begin func_003CDFF0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { __int128 r[4]; } Mat_3CDFF0;
class Xf_3CDFF0 {
public:
    virtual void dtor(int f);
    virtual void set(Mat_3CDFF0* m);
    virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14();
    virtual int busy();
};
struct Obj_3CDFF0;
class ObjV_3CDFF0 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
    virtual void attach(Mat_3CDFF0* m, int flag);
    char pad4[0x48 - 4]; unsigned char owns; char pad49[7]; Xf_3CDFF0* xf;
};
typedef struct { void* vt; char pad4[0xC]; Mat_3CDFF0 m; unsigned char f50; } Xf2_3CDFF0;
extern "C" {
extern char D_004DF6A0[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
Xf_3CDFF0* cXformNode_ctor_cMatrixR(void* p, Mat_3CDFF0* m);
}
static inline void* Alloc_3CDFF0(unsigned int n, int line) { AllocGuard g; return cMemMan_Allocate(0, n, D_004BD228, line); }

#pragma push
extern "C" void cGOBJ_CreateXform(ObjV_3CDFF0* self, Mat_3CDFF0* m, int flag)
{
    if (!self->xf) {
        if (flag) {
            Xf_3CDFF0* x = (Xf_3CDFF0*)Alloc_3CDFF0(0xC0, 0x151);
            if (x) x = cXformNode_ctor_cMatrixR(x, m);
            self->xf = x;
        } else {
            Xf2_3CDFF0* y = (Xf2_3CDFF0*)Alloc_3CDFF0(0x60, 0x153);
            if (y) {
                Mat_3CDFF0* d; __int128 qa; __int128 qb; char one;
                y->vt = D_004DF6A0;
                d = &y->m;
                asm { .set reorder; lq qa, 0x0(m) }
                one = 1;
                asm { .set reorder; lq qb, 0x10(m) }
                asm { .set reorder; sq qa, 0x0(d) }
                asm { .set reorder; lq qa, 0x20(m) }
                asm { .set reorder; sq qb, 0x10(d) }
                asm { .set reorder; lq qb, 0x30(m) }
                asm { .set reorder; sq qa, 0x20(d) }
                asm { .set reorder; sq qb, 0x30(d) }
                y->f50 = one;
            }
            self->xf = (Xf_3CDFF0*)y;
        }
        self->owns = 1;
        return;
    }
    if (flag && !self->xf->busy()) {
        Xf_3CDFF0* p = self->xf;
        if (p) {
            if (self->owns) {
                { AllocGuard g; p->dtor(-1); cMemMan_Deallocate(0, p, D_004BD228, 0x174); }
                self->owns = 0;
            }
            self->xf = 0;
        }
        self->attach(m, flag);
        return;
    }
    self->xf->set(m);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CDFF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CDFF0 */

/* merge_units: begin func_003CE2A0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cMatrix_Transform(V4* a, V4* b); /* gsynth: defined below */
int cMatrix_opEq(int a0, int a1); /* gsynth: defined below */
#pragma cplusplus on
typedef struct { float m[16]; } BwMtx_f3;
typedef struct { float v[4]; } BwVec_f3;
class BwSrc_f3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC];
    BwMtx_f3 xform;
    unsigned char dirty;
};
typedef struct {
    unsigned char changed; char pad1[0xF];
    BwMtx_f3 xform;
    BwMtx_f3 delta;
    BwVec_f3 vel;
    BwVec_f3 velRate;
} BwDst_f3;
typedef struct { char pad[0x50]; BwSrc_f3* src; BwDst_f3* dst; } BwActor_f3;
extern "C" {
#if 0 /* merge_units */
extern int cMatrix_opEq(BwMtx_f3* a, BwMtx_f3* b);
#endif /* merge_units */
#define cMatrix_opEq(a0, a1) (cMatrix_opEq((int)(a0), (int)(a1))) /* merge_units */

extern void cMatrix_Copy_InvertRotTrans(BwMtx_f3* out, BwMtx_f3* in);
#if 0 /* merge_units */
extern BwMtx_f3* cMatrix_Transform(BwMtx_f3* a, BwMtx_f3* b);
#endif /* merge_units */
#define cMatrix_Transform(a0, a1) ((BwMtx_f3 *)cMatrix_Transform((V4 *)(a0), (V4 *)(a1))) /* merge_units */

extern void cMatrix_opAssign(BwMtx_f3* d, BwMtx_f3* s);
extern BwVec_f3* func_00133EC0(BwMtx_f3* m);
extern void cVector_opSub(BwVec_f3* out, BwVec_f3* a, BwVec_f3* b);
extern BwVec_f3* cVector_WSet0(BwVec_f3* v);
extern void cVector_opAssign(BwVec_f3* d, BwVec_f3* s);
extern void cVector_opMul(BwVec_f3* out, BwVec_f3* in, float s);
void cGOBJ_UpdateMotion(BwActor_f3* self, float dt);
}
void cGOBJ_UpdateMotion(BwActor_f3* self, float dt)
{
    BwMtx_f3 inv;
    BwVec_f3 diff;
    BwVec_f3 rate;
    BwSrc_f3* src;
    BwMtx_f3* sx;
    BwDst_f3* dst;
    if (self->dst == 0) return;
    src = self->src;
    if (src == 0) return;
    if (src->dirty) {
        src->Refresh();
    }
    dst = self->dst;
    sx = &src->xform;
    dst->changed = !cMatrix_opEq(sx, &dst->xform);
    cMatrix_Copy_InvertRotTrans(&inv, &dst->xform);
    cMatrix_opAssign(&dst->delta, cMatrix_Transform(&inv, sx));
    cVector_opSub(&diff, func_00133EC0(sx), func_00133EC0(&dst->xform));
    cVector_opAssign(&dst->vel, cVector_WSet0(&diff));
    cVector_opMul(&rate, &dst->vel, 1.0f / dt);
    cVector_opAssign(&dst->velRate, cVector_WSet0(&rate));
    cMatrix_opAssign(&dst->xform, sx);
}
#undef cMatrix_opEq /* merge_units */
#undef cMatrix_Transform /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE2A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE2A0 */

/* merge_units: begin func_003CE3D0 */
#pragma push /* merge_units */
V4* cMatrix_Transform(V4* a, V4* b) {
    asm {
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        lqc2 vf8, 0x0(a)
        lqc2 vf9, 0x10(a)
        lqc2 vf10, 0x20(a)
        lqc2 vf11, 0x30(a)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE3D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE3D0 */

/* merge_units: begin func_003CE450 */
#pragma push /* merge_units */
int cMatrix_opEq(int a0, int a1) {
    int v0;
    float f0, f1;
    int cond, fcc;

    f1 = *(float*)(char*)a0;
    f0 = *(float*)(char*)a1;
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE468;
    v0 = 0;
L003CE468:;
    cond = v0 == 0;
    if (cond) goto L003CE488;
    f1 = *(float*)((char*)a0 + 4);
    f0 = *(float*)((char*)a1 + 4);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE488;
    v0 = 0;
L003CE488:;
    cond = v0 == 0;
    if (cond) goto L003CE4A8;
    f1 = *(float*)((char*)a0 + 8);
    f0 = *(float*)((char*)a1 + 8);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE4A8;
    v0 = 0;
L003CE4A8:;
    cond = v0 == 0;
    if (cond) goto L003CE4C8;
    f1 = *(float*)((char*)a0 + 12);
    f0 = *(float*)((char*)a1 + 12);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE4C8;
    v0 = 0;
L003CE4C8:;
    cond = v0 == 0;
    if (cond) goto L003CE4E8;
    f1 = *(float*)((char*)a0 + 16);
    f0 = *(float*)((char*)a1 + 16);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE4E8;
    v0 = 0;
L003CE4E8:;
    cond = v0 == 0;
    if (cond) goto L003CE508;
    f1 = *(float*)((char*)a0 + 20);
    f0 = *(float*)((char*)a1 + 20);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE508;
    v0 = 0;
L003CE508:;
    cond = v0 == 0;
    if (cond) goto L003CE528;
    f1 = *(float*)((char*)a0 + 24);
    f0 = *(float*)((char*)a1 + 24);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE528;
    v0 = 0;
L003CE528:;
    cond = v0 == 0;
    if (cond) goto L003CE548;
    f1 = *(float*)((char*)a0 + 28);
    f0 = *(float*)((char*)a1 + 28);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE548;
    v0 = 0;
L003CE548:;
    cond = v0 == 0;
    if (cond) goto L003CE568;
    f1 = *(float*)((char*)a0 + 32);
    f0 = *(float*)((char*)a1 + 32);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE568;
    v0 = 0;
L003CE568:;
    cond = v0 == 0;
    if (cond) goto L003CE588;
    f1 = *(float*)((char*)a0 + 36);
    f0 = *(float*)((char*)a1 + 36);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE588;
    v0 = 0;
L003CE588:;
    cond = v0 == 0;
    if (cond) goto L003CE5A8;
    f1 = *(float*)((char*)a0 + 40);
    f0 = *(float*)((char*)a1 + 40);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE5A8;
    v0 = 0;
L003CE5A8:;
    cond = v0 == 0;
    if (cond) goto L003CE5C8;
    f1 = *(float*)((char*)a0 + 44);
    f0 = *(float*)((char*)a1 + 44);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE5C8;
    v0 = 0;
L003CE5C8:;
    cond = v0 == 0;
    if (cond) goto L003CE5E8;
    f1 = *(float*)((char*)a0 + 48);
    f0 = *(float*)((char*)a1 + 48);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE5E8;
    v0 = 0;
L003CE5E8:;
    cond = v0 == 0;
    if (cond) goto L003CE608;
    f1 = *(float*)((char*)a0 + 52);
    f0 = *(float*)((char*)a1 + 52);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE608;
    v0 = 0;
L003CE608:;
    cond = v0 == 0;
    if (cond) goto L003CE628;
    f1 = *(float*)((char*)a0 + 56);
    f0 = *(float*)((char*)a1 + 56);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE628;
    v0 = 0;
L003CE628:;
    cond = v0 == 0;
    if (cond) goto L003CE648;
    f1 = *(float*)((char*)a0 + 60);
    f0 = *(float*)((char*)a1 + 60);
    fcc = f1 == f0;
    cond = fcc;
    v0 = 0 + 1;
    if (cond) goto L003CE648;
    v0 = 0;
L003CE648:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE450 */

/* merge_units: begin func_003CE650 */
#pragma push /* merge_units */
#pragma cplusplus on
class D2_Logic {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void Update();
};
typedef struct { int a; int b; } D2_WeakRef;
typedef struct { char pad[0x30]; int id; char pad2[0x24]; D2_Logic* logic; } D2_ActorBase;
extern "C" D2_WeakRef* cSafePtr_cGOBJ_ctor_cGOBJP(D2_WeakRef* r, void* obj);
extern "C" void cAssocMultiArray_int_cSafePtr_cGOBJ_Add(void* mgr, int* id, D2_WeakRef* r);
extern "C" void* g_MotionManager;
extern "C" void cGOBJ_NextFrame(D2_ActorBase* a) {
    if (a->logic != 0) {
        a->logic->Update();
    }
    if (a->id >= 0) {
        D2_WeakRef ref;
        int id[1];
        id[0] = a->id;
        cAssocMultiArray_int_cSafePtr_cGOBJ_Add(g_MotionManager, id, cSafePtr_cGOBJ_ctor_cGOBJP(&ref, a));
    }
}
#pragma cplusplus reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE650 */
