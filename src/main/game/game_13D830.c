/*
 * main/game: 3 files, 0013D830-0013D870
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013D830 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0013D830(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D830 */

/* merge_units: begin func_0013D840 */
#pragma push /* merge_units */
typedef struct { int value; } Handle;
typedef struct { int unk0; int unk4; int value; } HSrc;

/* Writes a handle holding the source's field at +8 to *out. */
void func_0013D840(Handle* out, HSrc* s)
{
    Handle h;
    Handle tmp;
    tmp.value = s->value;
    h = tmp;
    out->value = h.value;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D840 */

/* merge_units: begin func_0013D870 */
#pragma push /* merge_units */
#include "loose00_types.h"

/* Iterator from a node pointer (passed through the stack). */
Iter* func_0013D870(Iter* out, int* node) {
    int* volatile tmp = node; /* stored to the stack and reloaded */

    out->p = tmp;
    return out;
}

void func_0013D890(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D870 */
