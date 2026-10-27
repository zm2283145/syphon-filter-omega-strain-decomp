/*
 * SFOGame/Source/Loader: 3 files, 001C2F20-001C3050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C2F20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Loader.cc
 */

#include "types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* v.push_back(value): insert one copy at end(). */
int std_vector_cTerrainPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Zero-initialise a three-word vector. */
Rel* std_vector_cTerrainPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_001C2F20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C2F20 */

/* merge_units: begin func_001C2F60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_cTerrainPtr_1_dtor)
static inline void merge_flush_func_001C2F60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C2F60 */

/* merge_units: begin func_001C3050 */
#pragma push /* merge_units */
extern int cLoader_LoadNILights(int a0, int a1);
extern int cLoader_LoadNIObjs(int a0, int a1, int a2);

/* Initialise NI event lights, then NI event objects. */
int cLoader_LoadNIEvents(int a0, int a1, int a2) {
    cLoader_LoadNILights(a0, a1);
    return cLoader_LoadNIObjs(a0, a1, a2);
}
static inline void merge_flush_func_001C3050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C3050 */
