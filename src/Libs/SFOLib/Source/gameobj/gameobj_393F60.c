/*
 * main/gameobj: range (2 files, 00393F60-00393FD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"

/* merge_units: begin func_00393F60 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */


extern Rel* std_vector_imp_cBoneScale_ctor(Rel* r);
extern int std_vector_imp_cBone_init(Rel* r, int a1, int a2);

/* Clears the record, then calls std_vector_imp_cBone_init with the incoming a1/a2 unchanged. */
Rel* std_vector_imp_cBone_ctor(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    std_vector_imp_cBone_init(r, a1, a2);
    return r;
}

RelFlag* cArray_cBoneScale_ctor(RelFlag* r) {
    std_vector_imp_cBoneScale_ctor(&r->rel);
    r->flag = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393F60 */

/* merge_units: begin func_00393FD0 */
#pragma push /* merge_units */
Rel* std_vector_imp_cBoneScale_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393FD0 */
