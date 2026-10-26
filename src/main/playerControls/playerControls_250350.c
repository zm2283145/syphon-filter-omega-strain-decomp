/*
 * main/playerControls: range (3 files, 00250350-002503B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "playerControls_types.h"

/* merge_units: begin func_00250350 */
#pragma push /* merge_units */
typedef struct { int unk0; int words[1]; } PrioritySet;

/* Returns 1 if bit n is set in the priority set. */
int PrioritySet_Test(PrioritySet* set, int n)
{
    return ((set->words[n / 32] >> (n & 31)) & 1) != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250350 */

/* merge_units: begin func_00250380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */


float cGameCamera_GetFollowDistance(ControlsUnk934* self) {
    return -self->unk934;
}

Vec2f* cJoyXYVector_ctor_cJoyXYVectorR(Vec2f* dst, Vec2f* src) {
    dst->x = src->x;
    dst->y = src->y;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250380 */

/* merge_units: begin func_002503B0 */
#pragma push /* merge_units */
/* Initializes a float pair from two ints. */
Vec2f* cJoyXYVector_ctor_int_int(Vec2f* v, int x, int y) {
    v->x = (float)x;
    v->y = (float)y;
    return v;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002503B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002503B0 */
