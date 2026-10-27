/*
 * SFOGame/Source/decals: 1 file, 0027A570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027A570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* cDecal_ctor: fill a decal record; with a parent object the matrix is stored in the parent's local frame */
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct M {
    V r0, r1, r2, r3;
    M() {}
    // 128-bit lq/sq quadword copy idiom
    M& operator=(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { M* d = this; __int128 qa, qb; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    float* f() { return (float*)this; }
};

// VU0 macro-mode vector op (COP2), not expressible in C
static inline void Apply(V* o, M* m, V* v) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void MMulH(M* rp, M* ap, M* bp) { __asm__ volatile("lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w; vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w; vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w; sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)" : : "r"(rp), "r"(ap), "r"(bp) : "memory"); }
/* xx: dead address of a, kept by retail (an extra addiu before the multiply) */
static inline M MMul(M& a, M& b) { M r; M* rp = &r; void* xx = &a; M* bp = &b; M* ap = &a; MMulH(rp, ap, bp); return r; }
struct Node_7A570 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; M xform; unsigned char dirty;
};
struct Obj_7A570 { char pad[0x50]; Node_7A570* node; };
struct Rec_7A570 { int flags; char pad4[0xC]; M m; float f50; int x54; Obj_7A570* parent; float f5C; };
extern "C" {
M* cMatrix_ctor_cMatrixR(M* d, M* s);
M* cMatrix_InvertRotTrans(M* m);
Rec_7A570* cDecal_ctor(Rec_7A570* r, int flags, M* m, Obj_7A570* parent, float f, float g);
}
static inline M* GetXform(Node_7A570* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline M* InvOf(M* out, Node_7A570* n) { M t; return cMatrix_ctor_cMatrixR(out, cMatrix_InvertRotTrans(cMatrix_ctor_cMatrixR(&t, GetXform(n)))); }
/* pass-through layers: deeper inlines get lower stack slots (t below the product) */
static inline M* InvOf2(M* out, Node_7A570* n) { return InvOf(out, n); }
static inline M* InvOf3(M* out, Node_7A570* n) { return InvOf2(out, n); }
Rec_7A570* cDecal_ctor(Rec_7A570* r, int flags, M* m, Obj_7A570* parent, float f, float g)
{
    r->flags = flags;
    r->f50 = f;
    r->x54 = (int)g;
    r->parent = parent;
    r->f5C = -1.0f;
    if (r->flags & 1) {
        if (r->parent && !r->parent->node) r->parent = 0;
        if (!r->parent) {
            r->m = *m;
        } else {
            Node_7A570* n = r->parent->node;
            M inv;
            InvOf3(&inv, n);
            r->m = MMul(inv, *m);
        }
    }
    return r;
}
static inline void merge_flush_func_0027A570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027A570 */
