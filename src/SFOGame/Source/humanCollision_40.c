/*
 * SFOGame/Source/humanCollision: 2 files, 001EF370-001EF3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EF370 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_12(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_001EF370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF370 */

/* merge_units: begin func_001EF3B0 */
#pragma push /* merge_units */
extern void cArray_cCollisionEdgePtr_opAssign(void*, int);
typedef struct { int a[4]; } G6E1E;
void std_fill_n_cEdgeGroup_int_fill_n(G6E1E* p, int n, int x)
{
    while (n != 0) {
        cArray_cCollisionEdgePtr_opAssign(p, x);
        n--;
        p++;
    }
}
static inline void merge_flush_func_001EF3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EF3B0 */
