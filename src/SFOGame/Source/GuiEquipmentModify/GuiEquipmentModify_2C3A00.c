/*
 * main/GuiEquipmentModify: 3 files, 002C3A00-002C3FA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C3A00 */
#pragma push /* merge_units */
#include "types.h"
#include "pod8_vector_erase.h"

/* Erase a range from a vector of 8-byte elements. */
DEFINE_POD8_VECTOR_ERASE(func_002C3A00)
#pragma pop /* merge_units */
/* merge_units: end func_002C3A00 */

/* merge_units: begin func_002C3B60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill8.h"

DEFINE_VECTOR_INSERT_FILL8(Vector_Insert_2C3B60, D_004AC640, D_0049ECE8, 0x5C, std_swap_vectordeleterR_vectordeleterR_10, std_vector_deleter_cSkaSwitchValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002C3B60 */

/* merge_units: begin func_002C3FA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_002C3FA0(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}

/* Vector clear (count = 0). */
void func_002C3FE0(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C3FA0 */
