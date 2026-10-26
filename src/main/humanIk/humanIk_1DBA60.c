/*
 * main/humanIk: range (2 files, 001DBA60-001DBAD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DBA60 */
#pragma push /* merge_units */
/* Implicit member-wise operator= (bytes + lq/sq quad copies). */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct S {
    signed char a;
    signed char b;
    V v10;
    V v20;
    signed char c30;
    V v40;
    V v50;
    signed char c60;
};
extern "C" S* std_pair_cWeaponSlotPair_cIkTarget_LeftRight_ctor_pairR(S* d, const S* s)
{
    *d = *s; return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DBA60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DBA60 */

/* merge_units: begin func_001DBAD0 */
#pragma push /* merge_units */
/* SegPair from two Segs: member-wise copies; pointer-temp placement steers mw38 register coloring. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
#pragma peephole off
#pragma opt_propagation off
SegPair* cDrawAndHolsterWeapon_ActionManager_cIkTarget_LeftRight_ctor_cIkTargetR_cIkTargetR(SegPair* d, const Seg* a, const Seg* b)
{
    const V4* sbq;
    V4* daq;
    V4* dbp;
    V4* dbq;
    const V4* saq;
    d->a.p = a->p;
    daq = &d->a.q;
    dbp = &d->b.p;
    dbq = &d->b.q;
    saq = &a->q;
    *daq = *saq;
    sbq = &b->q;
    d->a.f = a->f;
    *dbp = b->p;
    *dbq = *sbq;
    d->b.f = b->f;
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DBAD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DBAD0 */
