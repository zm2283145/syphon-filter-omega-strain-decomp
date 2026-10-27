/*
 * SFOGame/Source/humanCollision: 4 files, 001E1040-001E1190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E1040 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cCollisionEdgePtr_dtor)
static inline void merge_flush_func_001E1040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1040 */

/* merge_units: begin func_001E1130 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int std_vector_imp_cEdgeGroup_insert(Vec16Array* v, FlagElem16* pos, int n, int value);

/* push_back(value) on an array of 16-byte elements. */
int cArray_cEdgeGroup_PushBackActual(Vec16Array* v, int value) {
    int count;
    FlagElem16* data;

    count = v->count;
    data = v->data;
    return std_vector_imp_cEdgeGroup_insert(v, data + count, 1, value);
}
static inline void merge_flush_func_001E1130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1130 */

/* merge_units: begin func_001E1150 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj1E;

extern void std_vector_cCollisionEdgePtr_ctor(Obj1E* self);
extern void std_vector_cCollisionEdgePtr_push_back(Obj1E* self, int* value);

/* Initializes the object, sets its flag and assigns the given value; returns self. */
Obj1E* cEdgeGroup_ctor_cCollisionEdgeP(Obj1E* self, int value)
{
    std_vector_cCollisionEdgePtr_ctor(self);
    self->flag = 1;
    std_vector_cCollisionEdgePtr_push_back(self, &value);
    return self;
}
static inline void merge_flush_func_001E1150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1150 */

/* merge_units: begin func_001E1190 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"
DEFINE_BASE_DTOR_CHAIN(cArray_cCollisionEdgePtr_dtor, std_vector_imp_cCollisionEdgePtr_1_dtor)
static inline void merge_flush_func_001E1190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E1190 */
