/*
 * main/gameCamera: range (5 files, 0017EC70-0017EDD0)
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
#include "anim_channel_base_dtor.h"
#pragma pop

/* merge_units: begin func_0017EC70 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(cSplinedMotion_Scalar_dtor_void, D_004DA3E0, D_004DA380)
#pragma pop /* merge_units */
/* merge_units: end func_0017EC70 */

/* merge_units: begin func_0017ECD0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* AnimChannelBase destructor, optionally delete. */
DEFINE_ANIM_CHANNEL_BASE_DTOR(func_0017ECD0)
#pragma pop /* merge_units */
/* merge_units: end func_0017ECD0 */

/* merge_units: begin func_0017ED20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR2(func_0017ED20, D_004DA410, D_004DA3B0)
#pragma pop /* merge_units */
/* merge_units: end func_0017ED20 */

/* merge_units: begin func_0017ED80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
DEFINE_VTABLE_CHAIN_DTOR1(cCollisionSystem_cBox_dtor_void, D_004DA3B0)
#pragma pop /* merge_units */
/* merge_units: end func_0017ED80 */

/* merge_units: begin func_0017EDD0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable chain, optionally delete. */
extern "C" char D_004DA440[];
extern "C" void cSplinedMotion_cQuaternion_UpdateVelocity();
extern "C" void cSplinedMotion_cQuaternion_FixUpResultOfSplineEvaluation();
extern "C" void cSplinedMotion_cQuaternion_UpdateSplinePoints();
extern "C" void func_0017EE30();
extern "C" void cSplinedMotion_cQuaternion_TeleportByDelta();
void * const D_004DA350[12] = { (void*)0x0, (void*)0x0, (void*)func_0017EE30, (void*)cSplinedMotion_cQuaternion_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_cQuaternion_UpdateSplinePoints, (void*)cSplinedMotion_cQuaternion_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_cQuaternion_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
extern "C" VtableChainObject* cSplinedMotion_Vector_dtor(VtableChainObject* self,
                                   short deleteFlag)
{
    if (self) {
        self->vtable = D_004DA440;
        if (self)
            self->vtable = ((char*)D_004DA350);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017EDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017EDD0 */
