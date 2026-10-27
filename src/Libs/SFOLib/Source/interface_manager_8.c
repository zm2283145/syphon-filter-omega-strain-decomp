/*
 * Libs/SFOLib/Source/interface_manager: 2 files, 00413E10-00413E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00413E10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "types.h"

/* Zero-initialise a three-word record. */
Rel* func_00413E10(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00413E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413E10 */

/* merge_units: begin interface_manager_413E30 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" { void cInterfaceManager_Reset(void* self); void cInterfaceManager_Entry_dtor(void); void __destroy_array(void* p, void* dtor, int size, int n); void operator_delete(void* p); }
extern "C" void* cInterfaceManager_dtor(void* self, short deleteFlag)
{
    if (self) {
        cInterfaceManager_Reset(self);
        __destroy_array(self, (void*)cInterfaceManager_Entry_dtor, 0x18, 0x14);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
static inline void merge_flush_interface_manager_413E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end interface_manager_413E30 */
