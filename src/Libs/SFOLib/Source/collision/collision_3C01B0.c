/*
 * main/collision: 3 files, 003C01B0-003C0200
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C01B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* table[index] = *value (128-bit copy). */
void func_003C01B0(Q* table, int index, Q* value) {
    Q tmp;

    tmp = *value;
    table[index] = tmp;
}

void func_003C01D0(Counted* self) {
    self->count = self->count - 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003C01B0 */

/* merge_units: begin func_003C01E0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int a; float b; } A1_P1;
int func_003C01E0(A1_P1* p, float x) { return p->b <= x; }
#pragma pop /* merge_units */
/* merge_units: end func_003C01E0 */

/* merge_units: begin func_003C0200 */
#pragma push /* merge_units */
/* Address of element `index` in a vector of 112-byte elements. */
Elem112* func_003C0200(Vec112* v, int index) {
    return &v->data[index];
}
#pragma pop /* merge_units */
/* merge_units: end func_003C0200 */
