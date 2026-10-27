/*
 * SFOGame/Source/hotbox: 1 file, 001719C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001719C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cHotbox_Intersects: point-in-box test of the hotbox, in the attached node's frame when there is one */
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { V r[4]; };
struct Node_HC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; Mtx xform; unsigned char dirty;
};
struct Hotbox_HC { char pad[0x50]; Node_HC* node; char pad54[0x70 - 0x54]; V lo; V hi; };
extern "C" {
void cMatrix_Copy_InvertRotTrans(Mtx* out, Mtx* in);
V* cVector_Transform_cMatrixR(V* v, Mtx* m);
unsigned char cHotbox_Intersects(Hotbox_HC* h, V* p);
}
static inline Mtx* GetXform(Node_HC* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void VC0(void* d, const void* s) { __int128 q; asm volatile { lq q, 0(s); sq q, 0(d) } }
static inline int InBox(V* p, Hotbox_HC* b) {
    V* lo = &b->lo;
    V* hi = &b->hi;
    int r;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(lo)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
unsigned char cHotbox_Intersects(Hotbox_HC* h, V* p)
{
    Node_HC* n = h->node;
    if (n) {
        V pt;
        V t;
        Mtx inv;
        VC0(&t, p);
        { V* q = &t; V* d = &pt; q->w = 1.0f; VC(d, q); }
        cMatrix_Copy_InvertRotTrans(&inv, GetXform(n));
        return InBox(cVector_Transform_cMatrixR(&pt, &inv), h);
    }
    return InBox(p, h);
}
static inline void merge_flush_func_001719C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001719C0 */
