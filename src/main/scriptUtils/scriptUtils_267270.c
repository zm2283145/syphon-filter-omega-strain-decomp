/*
 * main/scriptUtils: 2 files, 00267270-00267360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00267270 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_buffer_dtor.h"

extern "C" char D_004A8250[];
extern "C" GuardedBuffer* func_00267270(GuardedBuffer* self, short deleteFlag)
{
    if (self) {
        self->count = 0;
        GUARDED_BUFFER_FREE(self, D_004A8250)
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00267270 */

/* merge_units: begin func_00267360 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

DEFINE_BASE_DTOR_CHAIN(func_00267360, func_002673C0)
#pragma pop /* merge_units */
/* merge_units: end func_00267360 */
