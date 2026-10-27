/*
 * main/gameCamera: range (3 files, 0017EE30-0017EEE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable_chain_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop

/* merge_units: begin func_0017EE30 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(func_0017EE30, D_004DA350)
#pragma pop /* merge_units */
/* merge_units: end func_0017EE30 */

/* merge_units: begin func_0017EE80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_004DAD70[];
extern "C" void cCollisionRoutine_cBox_dtor_void_2();
void * const D_004DA330[8] = { (void*)0x0, (void*)0x0, (void*)cCollisionRoutine_cBox_dtor_void_2, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0, (void*)0x0 };
extern "C" VtableChainObject* cSplinedMotion_QuaternionLERP_1_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = D_004DAD70;
        if (self)
            self->vtable = ((char*)D_004DA330);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017EE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017EE80 */

/* merge_units: begin func_0017EEE0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cCollisionSystem_cBox_dtor_void_2)
#pragma pop /* merge_units */
/* merge_units: end func_0017EEE0 */
