/*
 * main/GuiAgentInfo: 6 files, 00367010-00367760
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00367010 */
#pragma push /* merge_units */
#include "types.h"
#include "pod8_vector_erase.h"

/* Erase a range from a vector of 8-byte elements. */
DEFINE_POD8_VECTOR_ERASE(func_00367010)
#pragma pop /* merge_units */
/* merge_units: end func_00367010 */

/* merge_units: begin func_00367170 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_insert_fill8.h"

DEFINE_VECTOR_INSERT_FILL8(func_00367170, D_004BBAA0, D_0049ECE8, 0x5C, func_001BF9E0, func_001BFBB0)
#pragma pop /* merge_units */
/* merge_units: end func_00367170 */

/* merge_units: begin func_003675B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_003675B0(PtrVec* a, PtrVec* b) {
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

void func_003675F0(char* self) {
    *(int*)(self + 4) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003675B0 */

/* merge_units: begin func_00367600 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_release_dtor.h"

/* Destroy a vector through its allocator, optionally delete. */
DEFINE_VECTOR_RELEASE_DTOR(func_00367600, func_001BFCB0, func_001BFAD0, D_0049ECD8)
#pragma pop /* merge_units */
/* merge_units: end func_00367600 */

/* merge_units: begin func_00367680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_destroy_release.h"

/* Destroy and free an allocation under the allocator guard. */
DEFINE_GUARDED_DESTROY_RELEASE(func_00367680, func_001AEFE0)
#pragma pop /* merge_units */
/* merge_units: end func_00367680 */

/* merge_units: begin func_00367760 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR(func_00367760, func_001BFCA0)
#pragma pop /* merge_units */
/* merge_units: end func_00367760 */
