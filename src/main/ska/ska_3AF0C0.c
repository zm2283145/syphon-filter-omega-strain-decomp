/*
 * main/ska: range (2 files, 003AF0C0-003AF130)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003AF0C0 */
#pragma push /* merge_units */
SkaDirtyFlags* AnimRoot_CopyDirtyFlags(SkaDirtyFlags* dst, SkaDirtyFlags* src); /* gsynth: defined below */Rel* AnimRoot_InitRelations(Rel* r); /* gsynth: defined below */
typedef struct { char b[0x50]; } AnimRegion;
typedef struct { char b[0x10]; } AnimDirty;
typedef struct { char b[0xC]; unsigned char valid; } AnimRelations;
typedef struct {
    AnimRegion a;
    AnimRegion b;
    AnimDirty dirty;
    int unkB0;
    AnimRelations rel;
} AnimRoot;
extern void AnimRoot_CopyRegion(AnimRegion* dst, AnimRegion* src);
#if 0 /* merge_units */
extern void AnimRoot_CopyDirtyFlags(AnimDirty* dst, AnimDirty* src);
#endif /* merge_units */
#define AnimRoot_CopyDirtyFlags(a0, a1) ((void)AnimRoot_CopyDirtyFlags((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void AnimRoot_InitRelations(AnimRelations* rel);
#endif /* merge_units */
#define AnimRoot_InitRelations(a0) ((void)AnimRoot_InitRelations((void *)(a0))) /* merge_units */


/* Copies an animation root: both regions and the dirty flags; resets the relations. */
AnimRoot* AnimRoot_Copy(AnimRoot* dst, AnimRoot* src)
{
    AnimRelations* rel;
    AnimRoot_CopyRegion(&dst->a, &src->a);
    AnimRoot_CopyRegion(&dst->b, &src->b);
    AnimRoot_CopyDirtyFlags(&dst->dirty, &src->dirty);
    rel = &dst->rel;
    dst->unkB0 = 0;
    AnimRoot_InitRelations(rel);
    rel->valid = 1;
    return dst;
}
#undef AnimRoot_CopyDirtyFlags /* merge_units */
#undef AnimRoot_InitRelations /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF0C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF0C0 */

/* merge_units: begin func_003AF130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


Rel* AnimRoot_InitRelations(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

SkaDirtyFlags* AnimRoot_CopyDirtyFlags(SkaDirtyFlags* dst, SkaDirtyFlags* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AF130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AF130 */
