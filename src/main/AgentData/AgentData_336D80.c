/*
 * main/AgentData: range (3 files, 00336D80-00336E40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "AgentData_types.h"

/* merge_units: begin func_00336D80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Small constructors / forwarding helpers.
 */


extern Rel* func_00336DC0(Rel* r);
extern int func_00337140(int a0, int a1, int a2);

int func_00336D80(int a0, int a1, int a2) {
    return func_00337140(a0, a1, a2);
}

/* Clears the three words and sets the flag. */
RelFlag* func_00336D90(RelFlag* self) {
    func_00336DC0(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336D80 */

/* merge_units: begin func_00336DC0 */
#pragma push /* merge_units */
extern int func_001396D0(int, int);
extern Rel* func_00336E40(Rel* r);

Rel* func_00336DC0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int func_00336DE0(int a0, int a1) {
    return func_001396D0(a0, a1);
}

Rel* func_00336DF0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Clears the three words and sets the flag. */
RelFlag* func_00336E10(RelFlag* self) {
    func_00336E40(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336DC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336DC0 */

/* merge_units: begin func_00336E40 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_00336E40(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* func_00336E60(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00336E40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00336E40 */
