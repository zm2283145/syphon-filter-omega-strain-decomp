/*
 * main/human: range (2 files, 001AEF20-001AEF70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_001AEF20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(cSkaSwitchValue_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001AEF20 */

/* merge_units: begin func_001AEF70 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Anim channel destructor, optionally delete (DEFINE_ANIM_CHANNEL_DTOR_DEEP of
 * anim_channel_dtor.h written out, so the unit can define the class vtable). */
extern "C" {
void cSplinedMotion_Scalar0To1_dtor();
void cSplinedMotion_Scalar0To1_TeleportByDelta();
void cSplinedMotion_Scalar0To1_InitPos();
void cSplinedMotion_Scalar0To1_ZeroVel();
void cSplinedMotion_Scalar0To1_UpdateSplinePoints();
void cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation();
void cSplinedMotion_Scalar0To1_UpdateVelocity();
extern char D_004DA380[];
#if 0 /* merge_units */
void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

void* const D_004DA840[12] = { 0, 0, (void*)cSplinedMotion_Scalar0To1_dtor, (void*)cSplinedMotion_Scalar0To1_TeleportByDelta, (void*)cSplinedMotion_Scalar0To1_InitPos,
    (void*)cSplinedMotion_Scalar0To1_ZeroVel, (void*)cSplinedMotion_Scalar0To1_UpdateSplinePoints, (void*)cSplinedMotion_Scalar0To1_FixUpResultOfSplineEvaluation,
    (void*)cSplinedMotion_Scalar0To1_UpdateVelocity, 0, 0, 0 };
}

struct AnimChannelObj {
    void* vtable;
};

extern "C" AnimChannelObj* cSkaSliderValue_dtor(AnimChannelObj* self, short deleteFlag)
{
    if (self) {
        if (self) {
            self->vtable = (void*)D_004DA840;
            if (self)
                self->vtable = D_004DA380;
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001AEF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001AEF70 */
