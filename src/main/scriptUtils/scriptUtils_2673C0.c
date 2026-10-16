/*
 * main/scriptUtils: 2 files, 002673C0-002674B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002673C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_002673C0)
#pragma pop /* merge_units */
/* merge_units: end func_002673C0 */

/* merge_units: begin func_002674B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int PtrVec_Reserve(int, int);

int func_002674B0(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* func_002674C0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_002674B0 */
