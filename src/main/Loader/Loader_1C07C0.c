/*
 * main/Loader: range (3 files, 001C07C0-001C0840)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "Loader_types.h"

/* merge_units: begin func_001C07C0 */
#pragma push /* merge_units */
Rel* func_001C07F0(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */


#if 0 /* merge_units */
extern PtrVec* func_001C07F0(PtrVec* v);
#endif /* merge_units */
#define func_001C07F0(a0) ((PtrVec *)func_001C07F0((void *)(a0))) /* merge_units */


/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* func_001C07C0(LoaderOwnedVec* self) {
    func_001C07F0(&self->vec);
    self->owns = 1;
    return self;
}
#undef func_001C07F0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C07C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C07C0 */

/* merge_units: begin func_001C07F0 */
#pragma push /* merge_units */
Rel* func_001C0840(Rel* r); /* gsynth: defined below */
#if 0 /* merge_units */
extern PtrVec* func_001C0840(PtrVec* v);
#endif /* merge_units */
#define func_001C0840(a0) ((PtrVec *)func_001C0840((void *)(a0))) /* merge_units */


/* Zero-initialise a three-word vector. */
Rel* func_001C07F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an empty vector that owns its elements. */
LoaderOwnedVec* func_001C0810(LoaderOwnedVec* self) {
    func_001C0840(&self->vec);
    self->owns = 1;
    return self;
}
#undef func_001C0840 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C07F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C07F0 */

/* merge_units: begin func_001C0840 */
#pragma push /* merge_units */
/* Zero-initialise a three-word vector. */
Rel* func_001C0840(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C0840(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C0840 */
