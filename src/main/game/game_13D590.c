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

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back(value). */
int cArray_tServerPtr_PushBackActual(PtrVec* v, int value) {
    int count;
    int* data;

    count = v->count;
    data = v->data;
    return std_vector_pod_int_insert(v, data + count, 1, value);
}

Unk0013D5B0* cDME_tServer_ctor(Unk0013D5B0* self) {
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
DEFINE_GUARDED_ALLOCATE(opNew_uint_int_charP_int)
#pragma pop /* merge_units */
/* merge_units: end func_0013D5C0 */

/* merge_units: begin func_0013D680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_assign.h"

/* Assign one string to another. */
DEFINE_SHORT_STRING_ASSIGN(std_basic_string_char_char_traits_char_assign_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_0013D680 */

/* merge_units: begin func_0013D710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "short_string_replace.h"

/* Replace a range of a string with another string. */
DEFINE_SHORT_STRING_REPLACE(std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_0013D710 */
