/*
 * SFOGame/Source/NIEvent: 1 file, 0023DE10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023DE10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#pragma inline_depth(8)
/* cNIEventBase_ParentXform: world matrix of an event node: billboarded for
 * type-3 nodes, otherwise parent world (recursively, or the parent's
 * billboard) times the local matrix at +0xF0. Types follow
 * cNIEventBase_MakeFacingMat (cNIEventBase_MakeFacingMat.c) and cMatrix_opMul_cMatrixR. */
struct V {
    float x, y, z, w;
    V() {}
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct NiEv {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x60 - 0x2F];
    int type;
    char pad64[0x94 - 0x64];
    NiEv* parent;
    char pad98[0xF0 - 0x98];
    Mtx local;
};
extern "C" {
Mtx cNIEventBase_MakeFacingMat(NiEv* ev);
Mtx cNIEventBase_ParentXform(NiEv* ev);
void cMatrix_opMul_cMatrixR(Mtx* out, Mtx* a, Mtx* b);
void cMatrix_ctor_void(Mtx* m);
void cMatrix_opAssign(Mtx* d, Mtx* s);
void cMatrix_ctor_cMatrixR(Mtx* d, Mtx* s);
int cGOBJ_IsActive(NiEv* ev);
}
static inline bool Not(unsigned char x) { return !x; }
static inline bool Ready(NiEv* t) { bool r = false; bool a = false; if (t->b2D && t->b2C) a = true; if (a && Not(t->b2E)) r = true; return r; }
/* matrix class whose copy constructor is the out-of-line cMatrix_ctor_cMatrixR (retail copies
 * the parent world into MulM's by-value parameter with it) */
struct MP : Mtx { MP() {} MP(const MP& o) { cMatrix_ctor_cMatrixR(this, (Mtx*)&o); } };
static inline Mtx MulM(MP a, const Mtx& b)
{
    const Mtx* pa = &a;
    Mtx t;
    Mtx* p = &t;
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1);"
        "lqc2 $vf8, 0x0(%2); lqc2 $vf9, 0x10(%2); lqc2 $vf10, 0x20(%2); lqc2 $vf11, 0x30(%2);"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w;"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w;"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w;"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w;"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(p), "r"(pa), "r"(&b) : "memory");
    return t;
}

static inline MP ParentWorld(NiEv* p)
{
    MP m;
    cMatrix_ctor_void(&m);
    if (p->type == 3) {
        if (cGOBJ_IsActive(p)) {
            Mtx t = cNIEventBase_MakeFacingMat(p);
            cMatrix_opAssign(&m, &t);
        }
    } else if (p->parent) {
        Mtx t2;
        Mtx w = cNIEventBase_ParentXform(p->parent);
        cMatrix_opMul_cMatrixR(&t2, &w, &p->local);
        cMatrix_opAssign(&m, &t2);
    } else {
        cMatrix_opAssign(&m, &p->local);
    }
    return m;
}

extern "C" Mtx cNIEventBase_ParentXform(NiEv* ev)
{
    Mtx r;
    if (ev->type == 3) {
        if (Ready(ev)) {
            Mtx b = cNIEventBase_MakeFacingMat(ev);
            r = b;
        }
    } else {
        NiEv* p = ev->parent;
        if (p)
            r = MulM(ParentWorld(p), ev->local);
        else
            r = ev->local;
    }
    return r;
}
static inline void merge_flush_func_0023DE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023DE10 */
