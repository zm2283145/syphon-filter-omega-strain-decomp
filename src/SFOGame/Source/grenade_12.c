/*
 * SFOGame/Source/grenade: 2 files, 0025DAA0-0025DB90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025DAA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_0025DAA0)
static inline void merge_flush_func_0025DAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025DAA0 */

/* merge_units: begin func_0025DB90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int std_vector_pod_int_reserve(int, int);
extern int std_vector_imp_cVector_reserve(int, int);

int PtrVec_Reserve_Thunk_25DB90(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* func_0025DBA0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int std_vector_cVector_reserve(int a0, int a1) {
    return std_vector_imp_cVector_reserve(a0, a1);
}
static inline void merge_flush_func_0025DB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025DB90 */
