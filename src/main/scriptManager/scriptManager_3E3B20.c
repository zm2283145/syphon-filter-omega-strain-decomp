/*
 * main/scriptManager: 3 files, 003E3B20-003E3C80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E3B20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003E3B20(PtrVec* a, PtrVec* b) {
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
#pragma pop /* merge_units */
/* merge_units: end func_003E3B20 */

/* merge_units: begin func_003E3B60 */
#pragma push /* merge_units */
#include "word_vector_erase.h"

/* Erase a range from a vector of 4-byte elements. */
DEFINE_WORD_VECTOR_ERASE(PtrVector_Erase_3E3B60)
#pragma pop /* merge_units */
/* merge_units: end func_003E3B60 */

/* merge_units: begin func_003E3C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_insert_v8.h"

extern "C" { char D_004BDA80[] = "tree::insert length error\n"; }
DEFINE_TREE_INSERT_V8(func_003E3C80, TIValueII, D_004BDA80, D_004BDBD8, 0x5C, func_0013CD40)
#pragma pop /* merge_units */
/* merge_units: end func_003E3C80 */
