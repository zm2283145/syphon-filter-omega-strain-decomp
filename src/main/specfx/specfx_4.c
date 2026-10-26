/*
 * main/specfx: 2 files, 003EC690-003EC6C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container iterator helpers.
 */

#include "types.h"

Word* cLListIterator_tItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_tItemPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* std_list_tItemPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC690 */

/* merge_units: begin func_003EC6C0 */
#pragma push /* merge_units */
typedef struct { int busy; int pad4; int pad8; unsigned char done; char padD[3]; float time; } OC6C0;
extern void Effect_UpdateSlots(OC6C0* a, OC6C0* b);
void Effect_Update(OC6C0* s, float dt) {
    s->time += dt;
    Effect_UpdateSlots(s, s);
    if (s->busy == 0) s->done = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC6C0 */
