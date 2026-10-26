/*
 * main/gameobj: range (3 files, 003939B0-00393A20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_003939B0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


/* Address of the value stored at +8 of the current node. */
char* cLListIterator_cSkaTransPlaybackPtr_opMul(Iter16* it) {
    return it->p + 8;
}

void cLList_cSkaTransPlaybackPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003939B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003939B0 */

/* merge_units: begin func_003939D0 */
#pragma push /* merge_units */
Rel* std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { int v; int z; Sub sub; } S;
#if 0 /* merge_units */
extern void std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Sub*);
#endif /* merge_units */
#define std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(a0) ((void)std_vector_cTreeNode_cSkaSystemPtrPtr_ctor((void *)(a0))) /* merge_units */

/* Constructor: copies a value, clears a field, inits the sub-object and sets its flag. */
S* cTreeNode_cSkaSystemPtr_ctor(S* s, int* v) { Sub* sub = &s->sub; s->v = *v; s->z = 0; std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(sub); sub->flag = 1; return s; }
#undef std_vector_cTreeNode_cSkaSystemPtrPtr_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003939D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003939D0 */

/* merge_units: begin func_00393A20 */
#pragma push /* merge_units */
Rel* std_vector_cTreeNode_cSkaSystemPtrPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393A20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393A20 */
