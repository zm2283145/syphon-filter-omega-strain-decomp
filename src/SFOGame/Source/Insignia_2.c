/*
 * SFOGame/Source/Insignia: 3 files, 00267230-00267270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00267230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void std_swap_vectordeleterR_vectordeleterR_24(PtrVec* a, PtrVec* b) {
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
static inline void merge_flush_func_00267230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267230 */

/* merge_units: begin func_00267270 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" char D_004A8250[];
extern "C" GuardedBuffer* std_vector_deleter_TaserPoint_dtor(GuardedBuffer* self, short deleteFlag)
{
    if (self) {
        self->count = 0;
        GUARDED_BUFFER_FREE(self, D_004A8250)
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_00267270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267270 */

/* merge_units: begin func_00267360 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(cArray_cAirTaserPtr_dtor, std_vector_imp_cAirTaserPtr_1_dtor)
static inline void merge_flush_func_00267360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00267360 */
