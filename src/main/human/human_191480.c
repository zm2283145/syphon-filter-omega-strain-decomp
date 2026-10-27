/*
 * main/human: range (2 files, 00191480-001914A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00191480 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct Orientation { Q a; Q b; } Orientation;

/* Copies two quadwords (orientation rows) from src to dst; returns dst. */
Orientation* cQuatVec_opAssign(Orientation* dst, Orientation* src)
{
    dst->a = src->a;
    dst->b = src->b;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00191480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00191480 */

/* merge_units: begin func_001914A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cSkaNode_CheckType(unsigned char* self, unsigned char value) {
    return value == self[4];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001914A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001914A0 */
