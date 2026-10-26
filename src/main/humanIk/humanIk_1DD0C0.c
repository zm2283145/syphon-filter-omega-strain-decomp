/*
 * main/humanIk: range (2 files, 001DD0C0-001DD140)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DD0C0 */
#pragma push /* merge_units */
/* Bounded push of a SegPair into a 6-entry list; member-wise copies (pointer-temp placement steers mw38 coloring). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct Seg { V4 p; V4 q; signed char f; } Seg;
typedef struct SegPair { Seg a; Seg b; } SegPair;
typedef struct SegList { unsigned int n; SegPair e[6]; } SegList;
#pragma peephole off
#pragma opt_propagation off
void cArray_FixedCapacity_cIkTarget_LeftRight_6_PushBackActual(SegList* l, const SegPair* s)
{
    if (l->n < 6) {
        SegPair* e;
        V4* dbq;
        const V4* sbq;
        V4* daq;
        const V4* saq;
        V4* dbp;
        const V4* sbp;
        e = &l->e[l->n];
        asm { .set reorder } /* scheduling barrier */
        e->a.p = s->a.p;
        daq = &e->a.q;
        saq = &s->a.q;
        *daq = *saq;
        dbp = &e->b.p;
        sbp = &s->b.p;
        e->a.f = s->a.f;
        dbq = &e->b.q;
        sbq = &s->b.q;
        *dbp = *sbp;
        *dbq = *sbq;
        e->b.f = s->b.f;
        l->n++;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DD0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DD0C0 */

/* merge_units: begin func_001DD140 */
#pragma push /* merge_units */
#pragma peephole off
#pragma opt_propagation off
SegList* cDrawAndHolsterWeapon_ActionManager_cWeaponSlotIkTargetTable_PushBack_WithIndexCheck(SegList* l, int unused, const SegPair* s)
{
    if (l->n < 6) {
        SegPair* e;
        V4* dbq;
        const V4* sbq;
        V4* daq;
        const V4* saq;
        V4* dbp;
        const V4* sbp;
        e = &l->e[l->n];
        asm { .set reorder } /* scheduling barrier */
        e->a.p = s->a.p;
        daq = &e->a.q;
        saq = &s->a.q;
        *daq = *saq;
        dbp = &e->b.p;
        sbp = &s->b.p;
        e->a.f = s->a.f;
        dbq = &e->b.q;
        sbq = &s->b.q;
        *dbp = *sbp;
        *dbq = *sbq;
        e->b.f = s->b.f;
        l->n++;
    }
    return l;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001DD140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001DD140 */
