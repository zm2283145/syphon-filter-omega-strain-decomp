/*
 * SFOGame/Source/humanIk: 3 files, 001DB8A0-001DB940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DB8A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "humanIk_types.h"

IkBytePair* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotPair_ctor(IkBytePair* dst, IkBytePair* src) {
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
static inline void merge_flush_func_001DB8A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DB8A0 */

/* merge_units: begin func_001DB8C0 */
#pragma push /* merge_units */
/* std_make_pair_cWeaponSlotPair_cIkTargetLeftRight (humanIk, mw38): IkPose ctor - byte pair + SegPair copy.
   Volatile lq/sq asm copies + dead address locals reproduce retail's duplicate addius. */
typedef struct { __int128 a; __int128 b; signed char f; } Seg;
typedef struct { Seg s0; Seg s1; } SegPair;
typedef struct { signed char a; signed char b; } IkBytePair_001DB8C0;
typedef struct { IkBytePair_001DB8C0 bp; SegPair sp; } IkPose;
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s) : "memory"); return q; }
static inline void GS(void* d, __int128 q) { __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(d) : "memory"); }
#pragma peephole off
void std_make_pair_cWeaponSlotPair_cIkTargetLeftRight(IkPose* d, IkBytePair_001DB8C0 bp, SegPair* s)
{
    void* d0;
    __int128 q0;
    void *x1, *x2, *x3, *x4, *x5;
    d0 = &d->sp.s0.a;
    d->bp.a = bp.a;
    d->bp.b = bp.b;
    q0 = GL(&s->s0.a);
    x1 = &d->sp; /* dead */
    x2 = &d->sp.s0; /* dead */
    x3 = &d->sp.s1; /* dead */
    x4 = &d->sp.s1; /* dead */
    x5 = &d->sp; /* dead */
    GS(d0, q0);
    GQ(&d->sp.s0.b, &s->s0.b);
    d->sp.s0.f = s->s0.f;
    GQ(&d->sp.s1.a, &s->s1.a);
    GQ(&d->sp.s1.b, &s->s1.b);
    d->sp.s1.f = s->s1.f;
}
static inline void merge_flush_func_001DB8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DB8C0 */

/* merge_units: begin func_001DB940 */
#pragma push /* merge_units */
extern void std_tree_pair_cWeaponSlotPair_value_compare_find(IkIter* out, int a1, int a2);

/* Iterator equality. */
int cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Iterator_opEq(IkIter* a, IkIter* b) {
    return (unsigned int)(a->node ^ b->node) < 1u;
}

void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Forwards to std_tree_pair_cWeaponSlotPair_value_compare_find through a temporary iterator. */
void cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Find(IkIter* out, int a1, int a2) {
    IkIter tmp;

    std_tree_pair_cWeaponSlotPair_value_compare_find(&tmp, a1, a2);
    out->node = tmp.node;
}
static inline void merge_flush_func_001DB940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DB940 */
