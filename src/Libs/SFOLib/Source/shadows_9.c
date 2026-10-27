/*
 * Libs/SFOLib/Source/shadows: 1 file, 003D5A30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin scriptBase_3D5A30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" { void __destroy_array(void* p, void* dtor, int size, int n); void cShadowMan_tSource_dtor(void); void operator_delete(void* p); }
extern "C" void* cShadowMan_tCaster_dtor(void* self, short deleteFlag)
{
    if (self) {
        __destroy_array((char*)self + 0x10, (void*)cShadowMan_tSource_dtor, 0x30, 6);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_scriptBase_3D5A30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end scriptBase_3D5A30 */
