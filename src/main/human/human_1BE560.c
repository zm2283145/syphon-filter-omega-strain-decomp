/*
 * main/human: 4 files, 001BE560-001BE780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BE560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_001BE560(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_001BE560 */

/* merge_units: begin func_001BE5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_001BE5A0, func_001BFA20, D_0049ED38)
#pragma pop /* merge_units */
/* merge_units: end func_001BE5A0 */

/* merge_units: begin func_001BE690 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_001BE690, func_001BFA30, D_0049ED28)
#pragma pop /* merge_units */
/* merge_units: end func_001BE690 */

/* merge_units: begin func_001BE780 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" { char D_0049ED18[] = "allocator.hh"; }
DEFINE_GUARDED_BUFFER_CALL_DTOR(func_001BE780, func_001BFA40, D_0049ED18)
#pragma pop /* merge_units */
/* merge_units: end func_001BE780 */
