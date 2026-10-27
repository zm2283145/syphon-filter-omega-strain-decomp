/*
 * main/humanIk: range (2 files, 001DB7A0-001DB850)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001DB7A0 */
#pragma push /* merge_units */
typedef struct { __int128 a; __int128 b; signed char f; } Seg_B850;
typedef struct { Seg_B850 s0; Seg_B850 s1; } T_B850;
T_B850* cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(T_B850* d, T_B850* s); /* gsynth: defined below */
/* cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Add (humanIk, mw38): map<IkBytePair,SegPair>::insert(make_pair(*k,*v)).second.
   Inlined SegPair copy via volatile lq/sq asm + a dead address local. */
typedef struct { __int128 a; __int128 b; signed char f; } Seg;
typedef struct { Seg s0; Seg s1; } SegPair;
typedef struct { signed char a; signed char b; } IkBytePair;
typedef struct { IkBytePair bp; SegPair sp; } IkPose;
typedef struct { void* node; unsigned char inserted; } InsRes;
void std_make_pair_cWeaponSlotPair_cIkTargetLeftRight(IkPose* d, IkBytePair bp, SegPair* s);
void cDrawAndHolsterWeapon_ActionManager_cWeaponSlotPair_ctor(IkBytePair* d, IkBytePair* s);
#if 0 /* merge_units */
void cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(SegPair* d, SegPair* s);
#endif /* merge_units */
#define cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(a0, a1) ((void)cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR((void *)(a0), (void *)(a1))) /* merge_units */

void std_tree_pair_cWeaponSlotPair_value_compare_insert_one(InsRes* out, void* t, IkPose* k);
static inline void GQ(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%2); sq %0, 0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline __int128 GL(const void* s) { __int128 q; __asm__ volatile("lq %0, 0(%1)" : "=r"(q) : "r"(s) : "memory"); return q; }
static inline void GS(void* d, __int128 q) { __asm__ volatile("sq %0, 0(%1)" : : "r"(q), "r"(d) : "memory"); }
#pragma peephole off
unsigned char cAssocArray_cWeaponSlotPair_cIkTarget_LeftRight_Add(void* m, IkBytePair* k, SegPair* v)
{
    InsRes r;
    IkPose p2;
    IkPose p1;
    SegPair tmp;
    void* d0;
    __int128 q0;
    void* x1;
    d0 = &tmp.s0.a;
    q0 = GL(&v->s0.a);
    x1 = &tmp; /* dead */
    GS(d0, q0);
    GQ(&tmp.s0.b, &v->s0.b);
    tmp.s0.f = v->s0.f;
    GQ(&tmp.s1.a, &v->s1.a);
    GQ(&tmp.s1.b, &v->s1.b);
    tmp.s1.f = v->s1.f;
    std_make_pair_cWeaponSlotPair_cIkTargetLeftRight(&p1, *k, &tmp);
    cDrawAndHolsterWeapon_ActionManager_cWeaponSlotPair_ctor(&p2.bp, &p1.bp);
    cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(&p2.sp, &p1.sp);
    std_tree_pair_cWeaponSlotPair_value_compare_insert_one(&r, m, &p2);
    return r.inserted;
}
#undef cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DB7A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DB7A0 */

/* merge_units: begin func_001DB850 */
#pragma push /* merge_units */
#pragma push
#pragma peephole off
#pragma opt_propagation off

T_B850* cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetLeftRightR(T_B850* d, T_B850* s)
{
    __int128 q0; __int128 t;
    __int128 *s1, *d1, *s2, *d2, *s3, *d3;
    q0 = s->s0.a;
d1 = &d->s0.b;
s1 = &s->s0.b;
d2 = &d->s1.a; s2 = &s->s1.a; d3 = &d->s1.b; s3 = &s->s1.b;
    d->s0.a = q0;
    t = *s1; *d1 = t;
    d->s0.f = s->s0.f;
    t = *s2; *d2 = t;
    t = *s3; *d3 = t;
    d->s1.f = s->s1.f;
    return d;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DB850(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DB850 */
