/*
 * main/GuiNetMessages: 6 files, 00346340-00346A90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00346340 */
#pragma push /* merge_units */
#include "types.h"
#include "pod8_vector_erase.h"

/* Erase a range from a vector of 8-byte elements. */
DEFINE_POD8_VECTOR_ERASE(func_00346340)
#pragma pop /* merge_units */
/* merge_units: end func_00346340 */

/* merge_units: begin func_003464A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill8.h"

DEFINE_VECTOR_INSERT_FILL8(func_003464A0, D_004BA0E0, D_0049ECE8, 0x5C, func_001BF9E0, func_001BFBB0)
#pragma pop /* merge_units */
/* merge_units: end func_003464A0 */

/* merge_units: begin func_003468E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003468E0(PtrVec* a, PtrVec* b) {
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

void func_00346920(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003468E0 */

/* merge_units: begin func_00346930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_00346930, func_001BFCB0, func_001BFAD0, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_00346930 */

/* merge_units: begin func_003469B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_003469B0, func_001AEFE0)
#pragma pop /* merge_units */
/* merge_units: end func_003469B0 */

/* merge_units: begin func_00346A90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_00346A90, func_001BFCA0)
#pragma pop /* merge_units */
/* merge_units: end func_00346A90 */
