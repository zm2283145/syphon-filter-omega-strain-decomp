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


extern Rel* func_00393FD0(Rel* r);
extern int func_00395EB0(Rel* r, int a1, int a2);

/* Clears the record, then calls func_00395EB0 with the incoming a1/a2 unchanged. */
Rel* func_00393F60(Rel* r, int a1, int a2) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    func_00395EB0(r, a1, a2);
    return r;
}

RelFlag* func_00393FA0(RelFlag* r) {
    func_00393FD0(&r->rel);
    r->flag = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393F60 */

/* merge_units: begin func_00393FD0 */
#pragma push /* merge_units */
Rel* func_00393FD0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393FD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393FD0 */
