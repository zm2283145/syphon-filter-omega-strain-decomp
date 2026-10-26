/*
 * main/human: 2 files, 001BF240-001BF280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BF240 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_9(PtrVec* a, PtrVec* b) {
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
/* merge_units: end func_001BF240 */

/* merge_units: begin func_001BF280 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; } G4_E3C;
extern void cSplinedMotion_Scalar0To1_opAssign(G4_E3C* d, void* v);
void std_fill_n_cSkaSliderValue_int_fill_n(G4_E3C* p, unsigned int n, void* v)
{
    for (; n != 0; n--, p++) {
        cSplinedMotion_Scalar0To1_opAssign(p, v);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_001BF280 */
