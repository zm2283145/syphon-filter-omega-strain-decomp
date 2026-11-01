/*
 * Libs/SFOLib/Source/gobj: 9 files, 003CCF30-003CD420
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CCF30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void cMemMan_Deallocate(int pool, void* p, char* file, int line); extern char D_004BD228[]; }
class C3CCF30 { public: virtual void Destroy(int flags); };
struct O3CCF30 { char pad[0x58]; C3CCF30* m; };
extern "C" void cGOBJ_DeleteController(O3CCF30* self)
{
    C3CCF30* m = self->m;
    if (m) {
        {
            AllocGuard g;
            m->Destroy(-1);
            cMemMan_Deallocate(0, m, D_004BD228, 0x291);
        }
        self->m = 0;
    }
}
static inline void merge_flush_func_003CCF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCF30 */

/* merge_units: begin func_003CCFF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "node_world_q4.h"
extern "C" MtxQ4 g_IdentityMatrix;
extern "C" MtxQ4 cGOBJ_GetTransform_ForFloorTravel(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CCFF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CCFF0 */

/* merge_units: begin func_003CD090 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
#include "v4_asm_copy.h"
struct N_3CD420 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Update();
    char pad4[0x40 - 4];
    V4 pos;
    unsigned char dirty;
};
struct X_3CD420 { char pad[0x50]; N_3CD420* n; };
#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_GetCameraCollisionReferencePoint(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
static inline void merge_flush_func_003CD090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD090 */

/* merge_units: begin func_003CD110 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetTransform_ForCameraTracking(OwnerQ4* o, int* flag)
{
    *flag = 0;
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD110 */

/* merge_units: begin func_003CD1C0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetTransform_ForTeleporting(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD1C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD1C0 */

/* merge_units: begin func_003CD260 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
static inline V Add(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
static inline V Scale(V v, float s) {
    V c; __int128 t = 0; const V* pv = &v; V* q = &c;
    __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(pv), "f"(s) : "memory");
    return c;
}
static inline V Xf(const V& in, M* m, V o = V()) {
    o = in;
    V* out = &o;
    asm {
        lqc2 vf8, 0x0(out)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(out)
    }
    return *out;
}
static inline V Zero() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
class ObjB {
public:
    virtual void f08(); virtual void f0C(); virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual void f2C(); virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3C(); virtual void f40(); virtual void f44();
    virtual void f48(); virtual void f4C(); virtual void f50(); virtual void f54(); virtual void Update();
};
class Obj : public ObjB {
public:
    char pad4[0xC];
    M m;
    unsigned char b50;
    void Sync() { if (b50) Update(); }
};
class PB {
public:
    virtual void f08(); virtual void f0C(); virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1C(); virtual void f20(); virtual void f24();
    virtual void f28(); virtual void f2C(); virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3C(); virtual void f40(); virtual void f44();
    virtual void f48(); virtual void f4C(); virtual void f50(); virtual void f54(); virtual void f58(); virtual void f5C(); virtual void f60(); virtual void f64();
    virtual void f68(); virtual void f6C(); virtual void f70(); virtual void f74(); virtual void f78(); virtual void f7C(); virtual void f80(); virtual void f84();
    virtual Box* GetBox();
};
class PathObj : public PB {
public:
    char pad4[0x45];
    unsigned char b49;
    char pad4a[6];
    Obj* p50;
    Box* SafeBox() { if (b49 != 14) return GetBox(); return 0; }
};
static inline V XfW(const V& in, M* m) { const V& i2 = in; return Xf(i2, m); }
static inline V Center(Box* b) { return Scale(Add(b->mn, b->mx), 0.5f); }
extern "C" V cGOBJ_GetCenterOfMass(PathObj* self)
{
    if (self->p50) {
        if (self->SafeBox()) {
            Obj* o = self->p50;
            o->Sync();
            M* m = &o->m;
            return XfW(V(Center(self->GetBox())), m);
        }
        Obj* o = self->p50;
        o->Sync();
        return o->m.r[3];
    }
    return Zero();
}
static inline void merge_flush_func_003CD260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD260 */

/* merge_units: begin func_003CD420 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_GetActivationPoint(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD420 */

/* merge_units: begin func_003CD4A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#pragma push
#pragma opt_common_subs off
extern "C" void cGOBJ_v35(V4* out, X_3CD420* x) {
    N_3CD420* n = x->n;
    if (n) {
        if (n->dirty) n->Update();
        V4Copy(out, &n->pos);
        return;
    }
    V4 r;
    V4StoreVF0(&r);
    V4Copy(out, &r);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CD4A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CD4A0 */

/* merge_units: begin func_003CD520 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" MtxQ4 cGOBJ_GetMatrix(OwnerQ4* o)
{
    NODE_WORLD_Q4_BODY(o, g_IdentityMatrix)
}
static inline void merge_flush_func_003CD520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CD520 */
