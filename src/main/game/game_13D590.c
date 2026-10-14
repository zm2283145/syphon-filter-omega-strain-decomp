/*
 * main/game: 4 files, 0013D590-0013D710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013D590 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int func_0013D590(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return PtrVec_Insert(v, data + count, 1, value);
}

Unk0013D5B0* func_0013D5B0(Unk0013D5B0* self) {
    self->unk10 = 3658;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013D590 */

/* merge_units: begin func_0013D5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_allocate.h"

/* Allocate under the allocator guard. */
DEFINE_GUARDED_ALLOCATE(func_0013D5C0)
#pragma pop /* merge_units */
/* merge_units: end func_0013D5C0 */

/* merge_units: begin func_0013D680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(func_0013D680)
#pragma pop /* merge_units */
/* merge_units: end func_0013D680 */

/* merge_units: begin func_0013D710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(func_0013D710)
#pragma pop /* merge_units */
/* merge_units: end func_0013D710 */
