/*
 * main/AgentData: range (3 files, 00330820-003308A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "AgentData_types.h"

/* merge_units: begin func_00330820 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Objective registration table iterator helpers (24-byte rows).
 */


void* func_00330820(char* self) {
    return self + 8;
}

int func_00330830(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* ++it over ObjectiveRow entries. */
ObjectiveRow** func_00330850(ObjectiveRow** it) {
    *it = *it + 1;
    return it;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330820 */

/* merge_units: begin func_00330870 */
#pragma push /* merge_units */
/* Tests bit `index` in a bit array of ints. */
int AgentData_TestObjectiveBit(int* bits, int index) {
    return ((bits[index / 32] >> (index & 0x1F)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00330870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00330870 */

/* merge_units: begin func_003308A0 */
#pragma push /* merge_units */
ObjectiveRow* func_003308A0(ObjectiveRow** it) {
    return *it;
}

/* out = end() of the registration row vector. */
void func_003308B0(ObjectiveRow** out, ObjectiveRowVec* v) {
    *out = v->data + v->count;
}

void func_003308D0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003308A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003308A0 */
